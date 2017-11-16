#include "Jogo.h"

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
	bool done = false;
	bool redraw = true;
	ALLEGRO_EVENT ev;
	initAllegroObjs();
	al_start_timer(timer);
	
	while (!done)
	{
		al_wait_for_event(queue, &ev);
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			int x = ev.mouse.x;
			int y = ev.mouse.y;
			if (estadoJogo == MENU)
			{
				if (mouseEstaNoBotao(&botao_novoJogo, x, y))
					botao_novoJogo.botaoSelec(true);
				else
					botao_novoJogo.botaoSelec(false);
				if (mouseEstaNoBotao(&botao_sair, x, y))
					botao_sair.botaoSelec(true);
				else
					botao_sair.botaoSelec(false);
			}
		}
		else if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
			// atualiza tudo se tiver que atualizar
		}
		
		if (redraw && al_is_event_queue_empty(queue))
		{
			draw();
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}


	//listaFases.defineNumJogadores(2);
	//listaFases.defineJog(RAONI, 1);
	//listaFases.defineJog(TECA, 2);
	//listaFases.carregaFaseN(1);
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
	}
}


void Jogo::draw()
{
	if (estadoJogo == MENU)
	{
		botao_novoJogo.draw();
		botao_sair.draw();
	}
	else if (estado_jogo == ESCOLHA_NOVO_JOGO)
	{

	}
}

void Jogo::carregaBotoes()
{
	ALLEGRO_BITMAP* image_novoJogo;
	image_novoJogo = al_create_bitmap(LARG_BOTAO, ALT_BOTAO);
	al_set_target_bitmap(image_novoJogo);
	al_draw_rounded_rectangle(0, 0, LARG_BOTAO, ALT_BOTAO, 5, 5, al_map_rgb(255, 0, 0), 2);
	al_draw_text(arial18, al_map_rgb(255, 0, 0), 60, 5, ALLEGRO_ALIGN_CENTER, "Novo Jogo");
	botao_novoJogo.setSprite(image_novoJogo, LARG_BOTAO, ALT_BOTAO);
	botao_novoJogo.setX(500);
	botao_novoJogo.setY(50);

	ALLEGRO_BITMAP* image_sair;
	image_sair = al_create_bitmap(LARG_BOTAO, ALT_BOTAO);
	al_set_target_bitmap(image_sair);
	al_draw_rounded_rectangle(0, 0, LARG_BOTAO, ALT_BOTAO, 5, 5, al_map_rgb(255, 0, 0), 2);
	al_draw_text(arial18, al_map_rgb(255, 0, 0), 60, 5, ALLEGRO_ALIGN_CENTER, "Sair");
	botao_sair.setSprite(image_sair, LARG_BOTAO, ALT_BOTAO);
	botao_sair.setX(500);
	botao_sair.setY(200);
	


	al_set_target_bitmap(al_get_backbuffer(display));
}


bool Jogo::mouseEstaNoBotao(Botao* const pBotao, const int mouseX, const int mouseY)
{
	if (mouseX <= (pBotao->getX() + pBotao->getLarg()) && mouseX >= pBotao->getX()
		&& mouseY >= pBotao->getY() && mouseY <= pBotao->getY()+pBotao->getAlt())
		return true;
	return false;
}
