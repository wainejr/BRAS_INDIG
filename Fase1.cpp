#include "Fase1.h"



Fase1::Fase1()
{
}


Fase1::~Fase1()
{
}


void Fase1::initFase()
{
	//INICIALIZAÇÕES DE OBJETOS
	///mudar depois os objetos para ponteiros e inicializar apenas pela construtora pelo "new"
	///initObjs();

	inimigo1.setFisica(true);
	inimigo1.setAtivo(true);
	inimigo1.setLimX(10);
	inimigo1.setLimY(20);
	inimigo1.setX(LARG - 100);
	inimigo1.setY(50);
	inimigo1.setArma(&armaInimigo);
	inimigo1.setVida(100);
	inimigo1.setAlvo(&player1);

	inimigoMosq1.builderMosqueteiro(300, 90, 10, 20, true, 20, &armaMosq1);
	inimigoMosq1.setAlvo(&player1);
	inimigoMosq1.setFisica(true);

	armaMosq1.builderMosquete(0, 0, 1, 1, false, true, 10, &inimigoMosq1);

	chao.setFisica(false);
	chao.setAtivo(true);
	chao.setLimX(LARG);
	chao.setLimY(10);
	chao.setX(0);
	chao.setY(ALT);

	plat1.builderPlataforma(200, ALT - 70, 100, 10, true);

	player1.setX(20);
	player1.setY(50);

	addInimigo(&inimigo1);
	addMosqueteiro(&inimigoMosq1);
	addPlataforma(&chao);
	addPlataforma(&plat1);
	addPlayer(&player1);

	// -------------   INICIALIZAÇÕES	--------------
	///initAllegroObjs();
	if (!al_init())
		return;
	al_init_primitives_addon();
	al_install_keyboard();
	al_install_mouse();
	al_init_ttf_addon();

	arial18 = al_load_ttf_font("arial.ttf", 18, 0);
	display = al_create_display(LARG, ALT);
	queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);

	//----------	ADD FONTES À FILA DE EVENTOS		-------------
	///setQueue();
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_display_event_source(display));

	execFase();
}


void Fase1::execFase()
{
	//VARIAVEIS PRIMITIVAS
	bool done = false;
	bool redraw = false;
	//
	enum KEYS { UP, DOWN, LEFT, RIGHT, SPACE, W, S, A, D };
	bool keys[9] = { false, false, false, false, false, false, false, false, false };



	// ----------- LOOP PRINCIPAL ---------------------
	///initLoopFase();
	al_start_timer(timer);
	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(queue, &ev);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = false;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
			{
				if (keys[LEFT])
					player1.moverEsq();
				if (keys[RIGHT])
					player1.moverDir();
				if (keys[UP] && personagemPodePular(static_cast<Personagem*>(&player1)))
					player1.pular();
				if (keys[SPACE])
					player1.atacar();
				if (!keys[LEFT] && !keys[RIGHT])
					player1.parar();
				atualizaFase();
			}
		}

		if (redraw && al_is_event_queue_empty(queue))
		{
			desenhaObjs();
			redraw = false;
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}
	//

	///destroyAllegroObjs();
	al_destroy_display(display);
	al_destroy_event_queue(queue);
	return;
}
