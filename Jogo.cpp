#include "Jogo.h"

bool Jogo::done = false;

Jogo::Jogo()
{
	carregouAllegro = false;
	display = nullptr;
	timer = nullptr;
	queue = nullptr;
	arial18 = nullptr;
	estadoJogo = MENU;
	exec();
}


Jogo::~Jogo()
{
	destroyAllegroObjs();
}


void Jogo::exec()
{
	bool redraw = true;
	bool pula = false;
	bool estadoJogoMudou = true;
	int x = 0;
	int y = 0;
	enum KEYS { MOUSE_ESQ, ESC };
	bool keys[2] = { false, false };
	ALLEGRO_EVENT ev;
	initAllegroObjs();
	addBotoes();
	listaFases.setDisplays(display);
	al_start_timer(timer);

	while (!done)
	{
		al_wait_for_event(queue, &ev);
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE || keys[ESC])
		{
			done = true;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				keys[ESC] = true;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				keys[ESC] = false;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (ev.mouse.button & 1)
				keys[MOUSE_ESQ] = true;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			if (ev.mouse.button & 1)
				keys[MOUSE_ESQ] = false;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			x = ev.mouse.x;
			y = ev.mouse.y;
		}

		else if (ev.type == ALLEGRO_EVENT_TIMER && !done)
		{
			redraw = true;
			// ATUALIZA OS BOTÕES ATIVOS
			if (estadoJogoMudou)
			{
				gerBotoes.desativaBotoes();
				switch (estadoJogo)
				{
				case MENU:
					botao_novoJogo.setAtivo(true);
					botao_sair.setAtivo(true);
					break;
				case ESCOLHA_PLAYER:
					botao_raoni.setAtivo(true);
					botao_teca.setAtivo(true);
					botao_raoniTeca.setAtivo(true);
					botao_tecaRaoni.setAtivo(true);
					botao_voltar.setAtivo(true);
					break;
				case ESCOLHA_FASE:
					botao_campanha.setAtivo(true);
					botao_fase1.setAtivo(true);
					botao_fase2.setAtivo(true);
					botao_fase3.setAtivo(true);
					botao_voltar.setAtivo(true);
					break;
				default:
					break;
				}
			}
			gerBotoes.checaSelec(x, y);
			
			//	ATUALIZA O ESTADO DO JOGO
			estadoJogoMudou = false;
			if (keys[MOUSE_ESQ])
			{
				keys[MOUSE_ESQ] = false; //	evitar segurar botão consistir numa escolha
				switch (estadoJogo)
				{
				case MENU:
					if (botao_novoJogo.getSelec())
					{
						estadoJogo = ESCOLHA_PLAYER;
						estadoJogoMudou = true;
					}
					else if (botao_sair.getSelec())
						done = true;
					break;

				case ESCOLHA_FASE:
					if (botao_voltar.getSelec())
					{
						estadoJogo = ESCOLHA_PLAYER;
						Fase::anulaJogs();
						estadoJogoMudou = true;
					}
					else if (botao_campanha.getSelec())
					{
						listaFases.campanha();
						estadoJogo = MENU;
						estadoJogoMudou = true;
					}
					else if (botao_fase1.getSelec())
					{
						listaFases.carregaFaseN(1);
						estadoJogo = MENU;
						estadoJogoMudou = true;
					}
					else if (botao_fase2.getSelec())
					{
						listaFases.carregaFaseN(2);
						estadoJogo = MENU;
						estadoJogoMudou = true;
					}
					else if (botao_fase3.getSelec())
					{
						listaFases.carregaFaseN(3);
						estadoJogo = MENU;
						estadoJogoMudou = true;
					}
					break;

				case ESCOLHA_PLAYER:

					if (botao_voltar.getSelec())
					{
						estadoJogo = MENU;
						estadoJogoMudou = true;
					}
					else if (botao_raoni.getSelec())
					{
						listaFases.defineNumJogadores(1);
						listaFases.defineJog(RAONI, 1);
						estadoJogo = ESCOLHA_FASE;
						estadoJogoMudou = true;
					}
					else if (botao_teca.getSelec())
					{
						listaFases.defineNumJogadores(1);
						listaFases.defineJog(TECA, 1);
						estadoJogo = ESCOLHA_FASE;
						estadoJogoMudou = true;
					}
					else if (botao_tecaRaoni.getSelec())
					{
						listaFases.defineNumJogadores(2);
						listaFases.defineJog(TECA, 1);
						listaFases.defineJog(RAONI, 2);
						estadoJogo = ESCOLHA_FASE;
						estadoJogoMudou = true;
					}
					else if (botao_raoniTeca.getSelec())
					{
						listaFases.defineNumJogadores(2);
						listaFases.defineJog(RAONI, 1);
						listaFases.defineJog(TECA, 2);
						estadoJogo = ESCOLHA_FASE;
						estadoJogoMudou = true;
					}
					break;

				default:
					break;
				}
			}
		}

		if (redraw && !done && al_is_event_queue_empty(queue))
		{
			draw();
			gerBotoes.desenhaBotoes();
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}
}


void Jogo::initAllegroObjs()
{
	if (!carregouAllegro)
	{
		// -------------   INICIALIZAÇÕES	--------------
		if (!al_init())
			return;
		al_init_primitives_addon();
		al_install_keyboard();
		al_install_mouse();
		al_init_ttf_addon();
		al_init_image_addon();

		arial18 = al_load_ttf_font("arial.ttf", 18, 0);
		display = al_create_display(LARG, ALT);
		queue = al_create_event_queue();
		timer = al_create_timer(1.0 / FPS);

		carregaBotoes();

		//	----------	ADD FONTES À FILA DE EVENTOS   -------------
		al_register_event_source(queue, al_get_keyboard_event_source());
		al_register_event_source(queue, al_get_mouse_event_source());
		al_register_event_source(queue, al_get_timer_event_source(timer));
		al_register_event_source(queue, al_get_display_event_source(display));
		carregouAllegro = true;
	}
}


void Jogo::destroyAllegroObjs()
{
	if (carregouAllegro)
	{
		al_destroy_display(display);
		al_destroy_timer(timer);
		al_destroy_font(arial18);
	}
}


void Jogo::draw()
{
	// DESENHA FUNDO, DESCRIÇÃO E TALS
}

void Jogo::carregaBotoes()
{
	//	TESTE COM PRIMITIVAS
	ALLEGRO_BITMAP* image_novoJogo;
	image_novoJogo = al_create_bitmap(LARG_BOTAO, ALT_BOTAO);
	al_set_target_bitmap(image_novoJogo);
	al_draw_rounded_rectangle(0, 0, LARG_BOTAO, ALT_BOTAO, 5, 5, al_map_rgb(255, 0, 0), 2);
	al_draw_text(arial18, al_map_rgb(255, 0, 0), LARG_BOTAO / 2, ALT_BOTAO / 2 - al_get_font_line_height(arial18) / 2, ALLEGRO_ALIGN_CENTER, "Novo Jogo");
	botao_novoJogo.setSprite(image_novoJogo, LARG_BOTAO, ALT_BOTAO);
	botao_novoJogo.setX(500);
	botao_novoJogo.setY(50);

	ALLEGRO_BITMAP* image_sair;
	image_sair = al_create_bitmap(LARG_BOTAO, ALT_BOTAO);
	al_set_target_bitmap(image_sair);
	al_draw_rounded_rectangle(0, 0, LARG_BOTAO, ALT_BOTAO, 5, 5, al_map_rgb(255, 0, 0), 2);
	al_draw_text(arial18, al_map_rgb(255, 0, 0), LARG_BOTAO / 2, ALT_BOTAO / 2 - al_get_font_line_height(arial18) / 2, ALLEGRO_ALIGN_CENTER, "Sair");
	botao_sair.setSprite(image_sair, LARG_BOTAO, ALT_BOTAO);
	botao_sair.setX(500);
	botao_sair.setY(100);

	ALLEGRO_BITMAP* image_campanha;
	image_campanha = al_create_bitmap(LARG_BOTAO, ALT_BOTAO);
	al_set_target_bitmap(image_campanha);
	al_draw_rounded_rectangle(0, 0, LARG_BOTAO, ALT_BOTAO, 5, 5, al_map_rgb(255, 0, 0), 2);
	al_draw_text(arial18, al_map_rgb(255, 0, 0), LARG_BOTAO / 2, ALT_BOTAO / 2 - al_get_font_line_height(arial18) / 2, ALLEGRO_ALIGN_CENTER, "Campanha");
	botao_campanha.setSprite(image_campanha, LARG_BOTAO, ALT_BOTAO);
	botao_campanha.setX(500);
	botao_campanha.setY(50);

	ALLEGRO_BITMAP* image_fase1;
	image_fase1 = al_create_bitmap(LARG_BOTAO, ALT_BOTAO);
	al_set_target_bitmap(image_fase1);
	al_draw_rounded_rectangle(0, 0, LARG_BOTAO, ALT_BOTAO, 5, 5, al_map_rgb(255, 0, 0), 2);
	al_draw_text(arial18, al_map_rgb(255, 0, 0), LARG_BOTAO / 2, ALT_BOTAO / 2 - al_get_font_line_height(arial18) / 2, ALLEGRO_ALIGN_CENTER, "Fase 1");
	botao_fase1.setSprite(image_fase1, LARG_BOTAO, ALT_BOTAO);
	botao_fase1.setX(500);
	botao_fase1.setY(100);

	ALLEGRO_BITMAP* image_fase2;
	image_fase2 = al_create_bitmap(LARG_BOTAO, ALT_BOTAO);
	al_set_target_bitmap(image_fase2);
	al_draw_rounded_rectangle(0, 0, LARG_BOTAO, ALT_BOTAO, 5, 5, al_map_rgb(255, 0, 0), 2);
	al_draw_text(arial18, al_map_rgb(255, 0, 0), LARG_BOTAO / 2, ALT_BOTAO / 2 - al_get_font_line_height(arial18) / 2, ALLEGRO_ALIGN_CENTER, "Fase 2");
	botao_fase2.setSprite(image_fase2, LARG_BOTAO, ALT_BOTAO);
	botao_fase2.setX(500);
	botao_fase2.setY(150);

	ALLEGRO_BITMAP* image_fase3;
	image_fase3 = al_create_bitmap(LARG_BOTAO, ALT_BOTAO);
	al_set_target_bitmap(image_fase3);
	al_draw_rounded_rectangle(0, 0, LARG_BOTAO, ALT_BOTAO, 5, 5, al_map_rgb(255, 0, 0), 2);
	al_draw_text(arial18, al_map_rgb(255, 0, 0), LARG_BOTAO / 2, ALT_BOTAO / 2 - al_get_font_line_height(arial18) / 2, ALLEGRO_ALIGN_CENTER, "Fase 3");
	botao_fase3.setSprite(image_fase3, LARG_BOTAO, ALT_BOTAO);
	botao_fase3.setX(500);
	botao_fase3.setY(200);

	ALLEGRO_BITMAP* image_teca;
	image_teca = al_create_bitmap(LARG_BOTAO, ALT_BOTAO);
	al_set_target_bitmap(image_teca);
	al_draw_rounded_rectangle(0, 0, LARG_BOTAO, ALT_BOTAO, 5, 5, al_map_rgb(255, 0, 0), 2);
	al_draw_text(arial18, al_map_rgb(255, 0, 0), LARG_BOTAO / 2, ALT_BOTAO / 2 - al_get_font_line_height(arial18) / 2, ALLEGRO_ALIGN_CENTER, "Teca");
	botao_teca.setSprite(image_teca, LARG_BOTAO, ALT_BOTAO);
	botao_teca.setX(500);
	botao_teca.setY(50);

	ALLEGRO_BITMAP* image_raoni;
	image_raoni = al_create_bitmap(LARG_BOTAO, ALT_BOTAO);
	al_set_target_bitmap(image_raoni);
	al_draw_rounded_rectangle(0, 0, LARG_BOTAO, ALT_BOTAO, 5, 5, al_map_rgb(255, 0, 0), 2);
	al_draw_text(arial18, al_map_rgb(255, 0, 0), LARG_BOTAO / 2, ALT_BOTAO / 2 - al_get_font_line_height(arial18) / 2, ALLEGRO_ALIGN_CENTER, "Raoni");
	botao_raoni.setSprite(image_raoni, LARG_BOTAO, ALT_BOTAO);
	botao_raoni.setX(500);
	botao_raoni.setY(100);

	ALLEGRO_BITMAP* image_tecaRaoni;
	image_tecaRaoni = al_create_bitmap(LARG_BOTAO, ALT_BOTAO);
	al_set_target_bitmap(image_tecaRaoni);
	al_draw_rounded_rectangle(0, 0, LARG_BOTAO, ALT_BOTAO, 5, 5, al_map_rgb(255, 0, 0), 2);
	al_draw_text(arial18, al_map_rgb(255, 0, 0), LARG_BOTAO / 2, ALT_BOTAO / 2 - al_get_font_line_height(arial18) / 2, ALLEGRO_ALIGN_CENTER, "Teca - Raoni");
	botao_tecaRaoni.setSprite(image_tecaRaoni, LARG_BOTAO, ALT_BOTAO);
	botao_tecaRaoni.setX(500);
	botao_tecaRaoni.setY(150);

	ALLEGRO_BITMAP* image_raoniTeca;
	image_raoniTeca = al_create_bitmap(LARG_BOTAO, ALT_BOTAO);
	al_set_target_bitmap(image_raoniTeca);
	al_draw_rounded_rectangle(0, 0, LARG_BOTAO, ALT_BOTAO, 5, 5, al_map_rgb(255, 0, 0), 2);
	al_draw_text(arial18, al_map_rgb(255, 0, 0), LARG_BOTAO / 2, ALT_BOTAO / 2 - al_get_font_line_height(arial18) / 2, ALLEGRO_ALIGN_CENTER, "Raoni - Teca");
	botao_raoniTeca.setSprite(image_raoniTeca, LARG_BOTAO, ALT_BOTAO);
	botao_raoniTeca.setX(500);
	botao_raoniTeca.setY(200);

	ALLEGRO_BITMAP* image_voltar;
	image_voltar = al_create_bitmap(LARG_BOTAO, ALT_BOTAO);
	al_set_target_bitmap(image_voltar);
	al_draw_rounded_rectangle(0, 0, LARG_BOTAO, ALT_BOTAO, 5, 5, al_map_rgb(255, 0, 0), 2);
	al_draw_text(arial18, al_map_rgb(255, 0, 0), LARG_BOTAO / 2, ALT_BOTAO / 2 - al_get_font_line_height(arial18) / 2, ALLEGRO_ALIGN_CENTER, "Voltar");
	botao_voltar.setSprite(image_voltar, LARG_BOTAO, ALT_BOTAO);
	botao_voltar.setX(500);
	botao_voltar.setY(400);

	al_set_target_bitmap(al_get_backbuffer(display));
}


void Jogo::setDone(const bool aDone)
{
	done = aDone;
}


void Jogo::resetaBotoesExceto(Botao* const pBotao)
{
	if (pBotao != &botao_sair)
		botao_sair.botaoSelec(false);
	if (pBotao != &botao_novoJogo)
		botao_novoJogo.botaoSelec(false);
	if (pBotao != &botao_campanha)
		botao_campanha.botaoSelec(false);
	if (pBotao != &botao_fase1)
		botao_fase1.botaoSelec(false);
	if (pBotao != &botao_fase2)
		botao_fase2.botaoSelec(false);
	if (pBotao != &botao_fase3)
		botao_fase3.botaoSelec(false);
	if (pBotao != &botao_tecaRaoni)
		botao_tecaRaoni.botaoSelec(false);
	if (pBotao != &botao_raoniTeca)
		botao_raoniTeca.botaoSelec(false);
	if (pBotao != &botao_teca)
		botao_teca.botaoSelec(false);
	if (pBotao != &botao_raoni)
		botao_raoni.botaoSelec(false);
	if (pBotao != &botao_voltar)
		botao_voltar.botaoSelec(false);
}


void Jogo::addBotoes()
{
	gerBotoes.addBotao(&botao_novoJogo);
	gerBotoes.addBotao(&botao_sair);
	gerBotoes.addBotao(&botao_campanha);
	gerBotoes.addBotao(&botao_fase1);
	gerBotoes.addBotao(&botao_fase2);
	gerBotoes.addBotao(&botao_fase3);
	gerBotoes.addBotao(&botao_tecaRaoni);
	gerBotoes.addBotao(&botao_raoniTeca);
	gerBotoes.addBotao(&botao_teca);
	gerBotoes.addBotao(&botao_raoni);
	gerBotoes.addBotao(&botao_voltar);
}
