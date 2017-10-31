#include "Jogo.h"



Jogo::Jogo()
{
	//INICIALIZAÇÕES DE OBJETOS
	///mudar depois os objetos para ponteiros e inicializar apenas pela construtora pelo "new"
	///initObjs();
	
	player.setFisica(true);
	player.setAtivo(true);
	player.setLimX(10);
	player.setLimY(20);
	player.setX(100);
	player.setY(100);
	player.setArma(&armaPlayer);
	player.setChances(3);
	player.setVida(100);
	
	inimigo1.setFisica(true);
	inimigo1.setAtivo(true);
	inimigo1.setLimX(10);
	inimigo1.setLimY(20);
	inimigo1.setX(LARG-100);
	inimigo1.setY(50);
	inimigo1.setArma(&armaInimigo);
	inimigo1.setVida(100);

	chao.setFisica(false);
	chao.setAtivo(true);
	chao.setLimX(LARG);
	chao.setLimY(10);
	chao.setX(0);
	chao.setY(ALT);

	fasePrototipo.addInimigo(&inimigo1);
	fasePrototipo.addPlayer(&player);
	fasePrototipo.addPlataforma(&chao);
	//
	
	
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

	exec();
}


Jogo::~Jogo()
{
	///destroyObjs();
	///destroyAllegroObjs();
}


void Jogo::exec()
{
	

	//VARIAVEIS PRIMITIVAS
	bool done = false;
	bool redraw = false;
	int estado_jogo = FASE;
	//

	

	// ----------- LOOP PRINCIPAL ---------------------
	///initLoopJogo();
	al_start_timer(timer);
	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(queue, &ev);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}
		else if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
			switch (estado_jogo)
			{
			case FASE:
				///execFase();
				fasePrototipo.atualizaFase();
				break;
			case MENUPRINCIPAL:
				///execMenuPrincipal();
				break;
			case MENUPAUSE:
				///mudar para dentro da fase
				break;
			}
		}


		if (redraw && al_is_event_queue_empty(queue))
		{
			switch (estado_jogo)
			{
			case FASE:
				
				fasePrototipo.desenhaFase();
				break;
			case MENUPRINCIPAL:
				break;
			case MENUPAUSE:
				break;
			}
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
