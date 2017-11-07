#include "Fase1.h"



Fase1::Fase1()
{

}


Fase1::~Fase1()
{
	
}


void Fase1::initFase()
{
	initAllegroObjs();
	initObjs();
	execFase();
}


void Fase1::execFase()
{
	//VARIAVEIS PRIMITIVAS
	bool done = false;
	bool redraw = false;
	bool resetar = false;
	//

	enum KEYS { UP, DOWN, LEFT, RIGHT, SPACE, W, S, A, D };
	bool keys[9] = { false, false, false, false, false, false, false, false, false };

	// ----------- LOOP PRINCIPAL ---------------------
	
	criarTimers();
	initTimers();
	while (!done)
	{
		if (resetar)
		{
			restart();
			resetar = false;
		}
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
				if(!keys[SPACE]) //evitar segurar o botão para atacar continuamente
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
				if (keys[UP])
				{
					if(personagemPodePular(static_cast<Personagem*>(&player1)))
						player1.pular();
					else if (jogadorPodeSubir(&player1))
						player1.subir();
				}
				if (keys[SPACE] && player1.getArma()->getID() == ESPADA && personagemPodeAtacar(static_cast<Personagem*>(&player1)))
				{
					player1.atacar();
					keys[SPACE] = false; //evitar ataques contínuos
				}
				if (!keys[LEFT] && !keys[RIGHT])
					player1.parar();
				if (player1.getVida() <= 0)
				{
					player1.setChances(player1.getChances() - 1);
					player1.setVida(VIDA_MAX_JOG);
					if (player1.getChances() > 0)
					{
						restart();
						resetar = true;
					}
					else 
						done = true;
				}
				atualizaFase();
			}
		}

		if (redraw && al_is_event_queue_empty(queue) && !resetar && !done)
		{
			desenhaObjs();
			//FUNÇAO DE TESTE
			imprimeVida();
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


void Fase1::initObjs()
{
	inimigo1.setFisica(true);
	inimigo1.setAtivo(true);
	inimigo1.setLimX(10);
	inimigo1.setLimY(20);
	inimigo1.setX(LARG - 100);
	inimigo1.setY(50);
	inimigo1.setArma(&armaInimigo);
	inimigo1.setVida(100);
	inimigo1.setAlvo(&player1);
	armaInimigo.builderEspada(0, 0, 10, 5, false, true, 10, &inimigo1);

	corda1.builderCorda(30, ALT - 10, 5, 50, true, true);
	corda1.setColisaoBaixo(false);

	inimigoMosq1.builderMosqueteiro(300, 90, 10, 20, true, 20, &armaMosq1);
	inimigoMosq1.setAlvo(&player1);
	inimigoMosq1.setFisica(true);

	armaMosq1.builderMosquete(0, 0, 1, 1, false, true, 10, &inimigoMosq1);

	cav1.builderEspadachimCav(400, ALT - 50, 40, 20, true, 40, &lanc1);
	cav1.setAlvo(&player1);
	lanc1.builderLanca(0, 0, 10, 10, false, true, 20, &cav1);

	chao.setFisica(false);
	chao.setAtivo(true);
	chao.setLimX(LARG * 2);
	chao.setLimY(10);
	chao.setX(0);
	chao.setY(ALT);

	plat1.builderPlataforma(200, ALT - 70, 100, 10, true);
	plat2.builderPlataforma(500, ALT - 70, 100, 10, true);
	plat3.builderPlataforma(700, ALT - 70, 10, 10, true);
	plat4.builderPlataforma(650, ALT - 10, 10, 80, true);
	plat2.setColisaoBaixo(true);
	plat3.setColisaoBaixo(true);
	plat4.setColisaoBaixo(true);
	
	player1.setX(20);
	player1.setY(50);
	
	//addEspadachim(&inimigo1);
	//addMosqueteiro(&inimigoMosq1);
	//addCavaleiro(&cav1);
	addPlataforma(&chao);
	//addPlataforma(&plat1);
	//addPlataforma(&plat2);
	//addPlataforma(&plat3);
	//addPlataforma(&plat4);
	addPlayer(&player1);
	
	addCorda(&corda1);
}


void Fase1::initAllegroObjs()
{
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
}


void Fase1::initInimigos()
{
}


void Fase1::initPlataformas()
{
}


void Fase1::restart()
{
	resetAllObjs();
	initObjs();
	//adicionar código aqui pra clicar pra reiniciar e tals
}

//FUNÇÃO PARA TESTES RETIRAR DEPOIS
void Fase1::imprimeVida()
{
	al_draw_textf(arial18, al_map_rgb(255, 255, 255), 10, 20, ALLEGRO_ALIGN_LEFT,
		"VIDA:      Player: %i  Esp: %i  Cav: %i  Mosq: %i",
		player1.getVida(), inimigo1.getVida(), cav1.getVida(), inimigoMosq1.getVida());
}