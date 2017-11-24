#include "Jogo.h"

bool Jogo::done = false;

Jogo::Jogo()
{
	carregouAllegro = false;
	display = nullptr;
	timer = nullptr;
	queue = nullptr;
	arial18 = nullptr;
	fundo = nullptr;
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

	initAllegroObjs();
	ALLEGRO_EVENT ev;

	listaFases.addFaseIni(&fase1);
	listaFases.addFaseIni(&fase2);
	listaFases.addFaseIni(&faseFinal);
	listaFases.setDisplays(display);
	listaFases.setGerPont(&gerPont);
	gerPont.setDisplay(display);
	gerPont.setFonte(arial18);

	addBotoes();
	
	buildJogadores();
	
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
				gerBotoes.resetaSelecBotoes();
				switch (estadoJogo)
				{
				case MENU:
					botao_novoJogo.setAtivo(true);
					botao_sair.setAtivo(true);
					botao_pontuacao.setAtivo(true);
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
				case PONTUACAO:
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
					else if (botao_pontuacao.getSelec())
					{
						estadoJogo = PONTUACAO;
						estadoJogoMudou = true;
					}
					else if (botao_sair.getSelec())
						done = true;
					break;
				case PONTUACAO:
					if (botao_voltar.getSelec())
					{
						estadoJogo = MENU;
						estadoJogoMudou = true;
					}
					break;
				
				case ESCOLHA_FASE:
					if (botao_voltar.getSelec())
					{
						estadoJogo = ESCOLHA_PLAYER;
						listaFases.anulaJogs();
						estadoJogoMudou = true;
					}
					else if (botao_campanha.getSelec())
					{
						gerBotoes.resetaSelecBotoes();
						al_stop_timer(timer);
						listaFases.campanha();
						listaFases.anulaJogs();
						al_resume_timer(timer);
						al_flush_event_queue(queue);
						estadoJogo = MENU;
						estadoJogoMudou = true;
					}
					else if (botao_fase1.getSelec())
					{
						gerBotoes.resetaSelecBotoes();
						al_stop_timer(timer);
						listaFases.carregaFaseN(1);
						listaFases.anulaJogs();
						resetaJogs();
						al_resume_timer(timer);
						al_flush_event_queue(queue);
						estadoJogo = MENU;
						estadoJogoMudou = true;
					}
					else if (botao_fase2.getSelec())
					{
						gerBotoes.resetaSelecBotoes();
						al_stop_timer(timer);
						listaFases.carregaFaseN(2);
						listaFases.anulaJogs();
						resetaJogs();
						al_resume_timer(timer);
						al_flush_event_queue(queue);
						estadoJogo = MENU;
						estadoJogoMudou = true;
					}
					else if (botao_fase3.getSelec())
					{
						gerBotoes.resetaSelecBotoes();
						al_stop_timer(timer);
						listaFases.carregaFaseN(3);
						listaFases.anulaJogs();
						resetaJogs();
						al_resume_timer(timer);
						al_flush_event_queue(queue);
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
						listaFases.defineJog(&raoni, 1);
						estadoJogo = ESCOLHA_FASE;
						estadoJogoMudou = true;
					}
					else if (botao_teca.getSelec())
					{
						listaFases.defineNumJogadores(1);
						listaFases.defineJog(&teca, 1);
						estadoJogo = ESCOLHA_FASE;
						estadoJogoMudou = true;
					}
					else if (botao_tecaRaoni.getSelec())
					{
						listaFases.defineNumJogadores(2);
						listaFases.defineJog(&teca, 1);
						listaFases.defineJog(&raoni, 2);
						estadoJogo = ESCOLHA_FASE;
						estadoJogoMudou = true;
					}
					else if (botao_raoniTeca.getSelec())
					{
						listaFases.defineNumJogadores(2);
						listaFases.defineJog(&raoni, 1);
						listaFases.defineJog(&teca, 2);
						estadoJogo = ESCOLHA_FASE;
						estadoJogoMudou = true;
					}
					break;
				default:
					break;
				}
			}
		}

		if (redraw && !done)
		{
			draw();
			gerBotoes.desenhaBotoes();
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
			redraw = false;
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
		fundo = al_load_bitmap("sprites/backgrounds/fundoMenu.png");
		tipo_brasilIndig = al_load_bitmap("sprites/tipos/tipo_brasilIndig.png");
		tipo_1jogador = al_load_bitmap("sprites/tipos/tipo_1jogador.png");
		tipo_2jogadores = al_load_bitmap("sprites/tipos/tipo_2jogadores.png");
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
		al_destroy_event_queue(queue);
		al_destroy_bitmap(fundo);
	}
}


void Jogo::draw()
{
	al_draw_bitmap(fundo, 0, 0, 0);
	if (estadoJogo == MENU)
	{
		al_draw_bitmap(tipo_brasilIndig, LARG / 2 - al_get_bitmap_width(tipo_brasilIndig) / 2,
			75 - al_get_bitmap_height(tipo_brasilIndig) / 2, 0);
	}
	else if (estadoJogo == ESCOLHA_PLAYER)
	{
		al_draw_bitmap(tipo_1jogador, LARG / 4 - al_get_bitmap_width(tipo_1jogador) / 2,
			100 - al_get_bitmap_height(tipo_1jogador) / 2, 0);
		al_draw_bitmap(tipo_2jogadores, 3*LARG / 4 - al_get_bitmap_width(tipo_2jogadores) / 2,
			100 - al_get_bitmap_height(tipo_2jogadores) / 2, 0);
	}
	else if (estadoJogo == PONTUACAO)
	{
		gerPont.desenhaPont(0, 100, 50);
		gerPont.desenhaPont(1, 250, 50);
		gerPont.desenhaPont(2, 400, 50);
	}
}


void Jogo::carregaBotoes()
{
	//	TESTE COM PRIMITIVAS
	ALLEGRO_BITMAP* image_novoJogo;
	ALLEGRO_BITMAP* imageSelec_novoJogo;
	image_novoJogo = al_load_bitmap("sprites/botoes/botao_novoJogo.png");
	imageSelec_novoJogo = al_load_bitmap("sprites/botoes/botao_novoJogoSelec.png");
	botao_novoJogo.setSprite(image_novoJogo, imageSelec_novoJogo, LARG_BOTAO, ALT_BOTAO);
	botao_novoJogo.setX(LARG / 2 - al_get_bitmap_width(image_novoJogo) / 2);
	botao_novoJogo.setY(200 - al_get_bitmap_height(image_novoJogo) / 2);

	ALLEGRO_BITMAP* image_pontuacao;
	ALLEGRO_BITMAP* imageSelec_pontuacao;
	image_pontuacao = al_load_bitmap("sprites/botoes/botao_pontuacao.png");
	imageSelec_pontuacao = al_load_bitmap("sprites/botoes/botao_pontuacaoSelec.png");
	botao_pontuacao.setSprite(image_pontuacao, imageSelec_pontuacao, LARG_BOTAO, ALT_BOTAO);
	botao_pontuacao.setX(LARG / 2 - al_get_bitmap_width(image_pontuacao) / 2);
	botao_pontuacao.setY(250 - al_get_bitmap_height(image_pontuacao) / 2);

	ALLEGRO_BITMAP* image_sair;
	ALLEGRO_BITMAP* imageSelec_sair;
	image_sair = al_load_bitmap("sprites/botoes/botao_sair.png");
	imageSelec_sair = al_load_bitmap("sprites/botoes/botao_sairSelec.png");
	botao_sair.setSprite(image_sair, imageSelec_sair, LARG_BOTAO, ALT_BOTAO);
	botao_sair.setX(LARG / 2 - al_get_bitmap_width(image_sair) / 2);
	botao_sair.setY(300 - al_get_bitmap_height(image_sair) / 2);

	ALLEGRO_BITMAP* image_campanha;
	ALLEGRO_BITMAP* imageSelec_campanha;
	image_campanha = al_load_bitmap("sprites/botoes/botao_campanha.png");
	imageSelec_campanha = al_load_bitmap("sprites/botoes/botao_campanhaSelec.png");
	botao_campanha.setSprite(image_campanha, imageSelec_campanha, LARG_BOTAO, ALT_BOTAO);
	botao_campanha.setX(LARG / 2 - al_get_bitmap_width(image_campanha)/2);
	botao_campanha.setY(100 - al_get_bitmap_height(image_campanha)/2);

	ALLEGRO_BITMAP* image_fase1;
	ALLEGRO_BITMAP* imageSelec_fase1;
	image_fase1 = al_load_bitmap("sprites/botoes/botao_fase1.png");
	imageSelec_fase1 = al_load_bitmap("sprites/botoes/botao_fase1Selec.png");
	botao_fase1.setSprite(image_fase1, imageSelec_fase1, LARG_BOTAO, ALT_BOTAO);
	botao_fase1.setX(LARG / 2 - al_get_bitmap_width(image_fase1) / 2);
	botao_fase1.setY(150 - al_get_bitmap_height(image_fase1) / 2);

	ALLEGRO_BITMAP* image_fase2;
	ALLEGRO_BITMAP* imageSelec_fase2;
	image_fase2 = al_load_bitmap("sprites/botoes/botao_fase2.png");
	imageSelec_fase2 = al_load_bitmap("sprites/botoes/botao_fase2Selec.png");
	botao_fase2.setSprite(image_fase2, imageSelec_fase2, LARG_BOTAO, ALT_BOTAO);
	botao_fase2.setX(LARG / 2 - al_get_bitmap_width(image_fase2) / 2);
	botao_fase2.setY(200 - al_get_bitmap_height(image_fase2) / 2);

	ALLEGRO_BITMAP* image_faseFinal;
	ALLEGRO_BITMAP* imageSelec_faseFinal;
	image_faseFinal = al_load_bitmap("sprites/botoes/botao_faseFinal.png");
	imageSelec_faseFinal = al_load_bitmap("sprites/botoes/botao_faseFinalSelec.png");
	botao_fase3.setSprite(image_faseFinal, imageSelec_faseFinal, LARG_BOTAO, ALT_BOTAO);
	botao_fase3.setX(LARG / 2 - al_get_bitmap_width(image_faseFinal) / 2);
	botao_fase3.setY(250 - al_get_bitmap_height(image_faseFinal) / 2);

	ALLEGRO_BITMAP* image_teca;
	ALLEGRO_BITMAP* imageSelec_teca;
	image_teca = al_load_bitmap("sprites/botoes/botao_teca.png");
	imageSelec_teca = al_load_bitmap("sprites/botoes/botao_tecaSelec.png");
	botao_teca.setSprite(image_teca, imageSelec_teca, LARG_BOTAO, ALT_BOTAO);
	botao_teca.setX(LARG / 4 - al_get_bitmap_width(image_teca) / 2);
	botao_teca.setY(150 - al_get_bitmap_height(image_teca) / 2);

	ALLEGRO_BITMAP* image_raoni;
	ALLEGRO_BITMAP* imageSelec_raoni;
	image_raoni = al_load_bitmap("sprites/botoes/botao_raoni.png");
	imageSelec_raoni = al_load_bitmap("sprites/botoes/botao_raoniSelec.png");
	botao_raoni.setSprite(image_raoni, imageSelec_raoni, LARG_BOTAO, ALT_BOTAO);
	botao_raoni.setX(LARG / 4 - al_get_bitmap_width(image_raoni) / 2);
	botao_raoni.setY(200 - al_get_bitmap_height(image_raoni) / 2);

	ALLEGRO_BITMAP* image_tecaRaoni;
	ALLEGRO_BITMAP* imageSelec_tecaRaoni;
	image_tecaRaoni = al_load_bitmap("sprites/botoes/botao_tecaRaoni.png");
	imageSelec_tecaRaoni = al_load_bitmap("sprites/botoes/botao_tecaRaoniSelec.png");
	botao_tecaRaoni.setSprite(image_tecaRaoni, imageSelec_tecaRaoni, LARG_BOTAO, ALT_BOTAO);
	botao_tecaRaoni.setX(3*LARG/4 - al_get_bitmap_width(image_tecaRaoni) / 2);
	botao_tecaRaoni.setY(150 - al_get_bitmap_height(image_tecaRaoni) / 2);

	ALLEGRO_BITMAP* image_raoniTeca;
	ALLEGRO_BITMAP* imageSelec_raoniTeca;
	image_raoniTeca = al_load_bitmap("sprites/botoes/botao_raoniTeca.png");
	imageSelec_raoniTeca = al_load_bitmap("sprites/botoes/botao_raoniTecaSelec.png");
	botao_raoniTeca.setSprite(image_raoniTeca, imageSelec_raoniTeca, LARG_BOTAO, ALT_BOTAO);
	botao_raoniTeca.setX(3 * LARG / 4 - al_get_bitmap_width(image_raoniTeca) / 2);
	botao_raoniTeca.setY(200 - al_get_bitmap_height(image_raoniTeca) / 2);

	ALLEGRO_BITMAP* image_voltar;
	ALLEGRO_BITMAP* imageSelec_voltar;
	//	MUDAR DEPOIS
	image_voltar = al_load_bitmap("sprites/botoes/botao_voltar.png");
	imageSelec_voltar = al_load_bitmap("sprites/botoes/botao_voltarSelec.png");
	botao_voltar.setSprite(image_voltar, imageSelec_voltar, LARG_BOTAO, ALT_BOTAO);
	botao_voltar.setX(550 - al_get_bitmap_width(image_voltar) / 2);
	botao_voltar.setY(450 - al_get_bitmap_height(image_voltar) / 2);

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
	gerBotoes.addBotao(&botao_pontuacao);
}


void Jogo::buildJogadores()
{
	raoni.buildJogador(0, 0, false, RAONI, 3);
	teca.buildJogador(0, 0, false, TECA, 3);
}


void Jogo::resetaJogs()
{
	teca.buildJogador(0, 0, false, TECA, 3);
	raoni.buildJogador(0, 0, false, RAONI, 3);
}


void Jogo::salvaPontuacao(const float aPont, const int aN)
{
	al_draw_bitmap(fundo, 0, 0, 0);

}