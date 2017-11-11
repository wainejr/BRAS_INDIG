#include "Fase1.h"
#include <iostream>

using namespace std;

Fase1::Fase1()
{
	numEntidades();
	alocaEntidades();
}


Fase1::~Fase1()
{
	deletaEntidades();
}


void Fase1::initFase()
{
	initAllegroObjs();
	initObjs();
	//buildEntidades();
	//addEntidades();
	execFase();
}


void Fase1::execFase()
{
	//VARIAVEIS PRIMITIVAS
	bool done = false;
	bool redraw = false;
	bool resetar = false;
	int x = 0;
	int y = 0;

	enum KEYS { UP, DOWN, LEFT, RIGHT, SPACE, W, S, A, D, CTRL};
	bool keys[10] = { false, false, false, false, false, false, false, false, false, false };

	//	VARIAVEIS ALLEGRO DO LOOP
	ALLEGRO_EVENT ev;

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
				if(!keys[SPACE])	//evitar segurar o botão para atacar continuamente
					keys[SPACE] = true;
				break;
			case ALLEGRO_KEY_W:
				keys[W] = true;
				break;
			case ALLEGRO_KEY_S:
				keys[S] = true;
				break;
			case ALLEGRO_KEY_D:
				keys[D] = true;
				break;
			case ALLEGRO_KEY_A:
				keys[A] = true;
				break;
			case ALLEGRO_KEY_RCTRL:
				if(!keys[CTRL])		//evitar segurar o botão para atacar continuamente
					keys[CTRL] = true;
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
			case ALLEGRO_KEY_W:
				keys[W] = false;
				break;
			case ALLEGRO_KEY_S:
				keys[S] = false;
				break;
			case ALLEGRO_KEY_D:
				keys[D] = false;
				break;
			case ALLEGRO_KEY_A:
				keys[A] = false;
				break;
			case ALLEGRO_KEY_RCTRL:
				keys[CTRL] = false;
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
					if (jogadorPodeSubir(&player1))
						player1.subir();
					else if (personagemPodePular(static_cast<Personagem*>(&player1)))
						player1.pular();
				}
				if (keys[CTRL] && personagemPodeAtacar(static_cast<Personagem*>(&player1)))
				{
					if (player1.getArma()->getID() == ARCO)
						projeteis.addObj(player1.atirar());
					else if (player1.getArma()->getID() == ESPADA)
						player1.atacar();
					keys[CTRL] = false; //evitar ataques contínuos
				}
				if (!keys[LEFT] && !keys[RIGHT])
					player1.parar();
				if (keys[DOWN])
				{
					if (jogadorEstaNumaCorda(&player1) && !personagemPodePular(static_cast<Personagem*>(&player1)))
						player1.descer();
					else if (persPodeDescerPlat(static_cast<Personagem*>(&player1)))
						perDescePlat(static_cast<Personagem*>(&player1));
				}
				if (keys[A])
					player2.moverEsq();
				if (keys[D])
					player2.moverDir();
				if (keys[W])
				{
					if (jogadorPodeSubir(&player2))
						player2.subir();
					else if (personagemPodePular(static_cast<Personagem*>(&player2)))
						player2.pular();
				}
				if (keys[SPACE] && personagemPodeAtacar(static_cast<Personagem*>(&player2)))
				{
					if (player2.getArma()->getID() == ARCO)
						projeteis.addObj(player1.atirar());
					else if (player2.getArma()->getID() == ESPADA)
						player2.atacar();
					keys[SPACE] = false; //evitar ataques contínuos
				}
				if (!keys[A] && !keys[D])
					player2.parar();
				if (keys[S])
				{
					if (jogadorEstaNumaCorda(&player2) && !personagemPodePular(static_cast<Personagem*>(&player2)))
						player2.descer();
					else if (persPodeDescerPlat(static_cast<Personagem*>(&player2)))
						perDescePlat(static_cast<Personagem*>(&player2));
				}
				if (player2.getVida() <= 0)
				{
					player2.setChances(player2.getChances() - 1);
					player2.setVida(VIDA_MAX_JOG);
					if (player2.getVida() > 0)
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

	corda1.builderCorda(100, ALT - 10, 5, 50, true, true);
	corda1.setColisaoBaixo(false);

	inimigoMosq1.builderMosqueteiro(300, 90, 10, 20, true, 20, &armaMosq1);
	inimigoMosq1.setAlvo(&player1);
	inimigoMosq1.setFisica(true);

	cav1.builderEspadachimCav(400, ALT - 50, 40, 20, true, 40, &lanc1);
	cav1.setAlvo(&player1);

	chao.setFisica(false);
	chao.setAtivo(true);
	chao.setColisaoBaixo(true);
	chao.setLimX(LARG * 5);
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
	
	rede1.builderRede(100, ALT - 200, 30, 3, true, 50);
	rede1cord.builderCorda(50, ALT - 15, 5, 5, true, false);
	rede1.setCorda(&rede1cord);

	player1.setX(20);
	player1.setY(50);

	armd1.builderArmadilha(300, ALT - 10, 5, 2, true, 20);
	
	espinho1.builderEspinho(570, ALT - 10, 50, 5, true, 10);

	//addEspadachim(&inimigo1);
	addMosqueteiro(&inimigoMosq1);
	addCavaleiro(&cav1);
	addPlataforma(&chao);
	addPlataforma(&plat1);
	addPlataforma(&plat2);
	addPlataforma(&plat3);
	addPlataforma(&plat4);
	addPlayer(&player1);
	addPlayer(&player2);
	addEspinho(&espinho1);
	addArmadilha(&armd1);
	
	addCorda(&corda1);
	addRede(&rede1);
}


void Fase1::initAllegroObjs()
{
	// -------------   INICIALIZAÇÕES	--------------
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

	//	----------	ADD FONTES À FILA DE EVENTOS   -------------
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_display_event_source(display));
}


void Fase1::restart()
{
	resetAllObjs();
	initObjs();
	//buildEntidades();
	//addEntidades();
	//adicionar código aqui pra clicar pra reiniciar e tals
}

//FUNÇÃO PARA TESTES RETIRAR DEPOIS
void Fase1::imprimeVida()
{
	al_draw_textf(arial18, al_map_rgb(255, 255, 255), 10, 20, ALLEGRO_ALIGN_LEFT,
		"VIDA:      Player: %i  Esp: %i  Cav: %i  Mosq: %i",
		player1.getVida(), inimigo1.getVida(), cav1.getVida(), inimigoMosq1.getVida());
}


void Fase1::alocaEntidades()
{
	/// LER UM ARQUIVO TXT E ALOCAR AS ENTIDADES NO NÚMERO CORRETO
	int i;

	mosqs = new Mosqueteiro*[num_mosq];
	mosquetes = new Mosquete*[num_mosq];
	for (i = 0; i < num_mosq; i++)
	{
		mosqs[i] = new Mosqueteiro;
		mosquetes[i] = new Mosquete;
	}

	esps = new Espadachim*[num_esps];
	espadas = new Espada*[num_esps];
	for (i = 0; i < num_esps; i++)
	{
		esps[i] = new Espadachim;
		espadas[i] = new Espada;
	}

	cavs = new EspadachimCavaleiro*[num_cavs];
	lancas = new Lanca*[num_cavs];
	for (i = 0; i < num_cavs; i++)
	{
		cavs[i] = new EspadachimCavaleiro;
		lancas[i] = new Lanca;
	}

	plats = new Plataforma*[num_plats];
	for (i = 0; i < num_plats; i++)
	{
		plats[i] = new Plataforma;
	}

	cords = new Corda*[num_cordas];
	for (i = 0; i < num_cordas; i++)
	{
		cords[i] = new Corda;
	}

	armds = new Armadilha*[num_armds];
	for (i = 0; i < num_armds; i++)
	{
		armds[i] = new Armadilha;
	}

	espins = new Espinho*[num_espinhos];
	for (i = 0; i < num_espinhos; i++)
	{
		espins[i] = new Espinho;
	}

	reds = new Rede*[num_redes];
	for (i = 0; i < num_redes; i++)
	{
		reds[i] = new Rede;
	}
}


void Fase1::deletaEntidades()
{
	int i;
	for (i = 0; i < num_mosq; i++)
	{
		delete (mosqs[i]);
		delete (mosquetes[i]);
	}
	delete(mosqs);
	delete(mosquetes);
	
	for (i = 0; i < num_esps; i++)
	{
		delete (esps[i]);
		delete (espadas[i]);
	}
	delete(esps);
	delete(espadas);

	for (i = 0; i < num_cavs; i++)
	{
		delete (cavs[i]);
		delete (lancas[i]);
	}
	delete(cavs);
	delete(lancas);

	for (i = 0; i < num_plats; i++)
	{
		delete (plats[i]);
	}
	delete(plats);

	for (i = 0; i < num_cordas; i++)
	{
		delete (cords[i]);
	}
	delete(cords);

	for (i = 0; i < num_armds; i++)
	{
		delete (armds[i]);
	}
	delete(armds);

	for (i = 0; i < num_espinhos; i++)
	{
		delete (espins[i]);
	}
	delete(espins);

	for (i = 0; i < num_redes; i++)
	{
		delete (reds[i]);
	}
	delete(reds);
}


void Fase1::buildEntidades()
{
	///	SETAR A POSIÇÃO DOS JOGADORES EM X E Y TAMBÉM
}


void Fase1::numEntidades()
{
	//	 LER DO TXT O NÚMERO DE ENTIDADES E TALS
	num_armds = 0;
	num_cavs = 0;
	num_cordas = 0;
	num_espinhos = 0;
	num_esps = 0;
	num_mosq = 0;
	num_plats = 0;
	num_redes = 0;
}


void Fase1::addEntidades()
{
	int i;
	for (i = 0; i < num_mosq; i++)
	{
		addMosqueteiro(mosqs[i]);
	}

	for (i = 0; i < num_esps; i++)
	{
		addEspadachim(esps[i]);
	}

	for (i = 0; i < num_cavs; i++)
	{
		addCavaleiro(cavs[i]);
	}

	for (i = 0; i < num_plats; i++)
	{
		addPlataforma(plats[i]);
	}

	for (i = 0; i < num_cordas; i++)
	{
		addCorda(cords[i]);
	}

	for (i = 0; i < num_armds; i++)
	{
		addArmadilha(armds[i]);
	}

	for (i = 0; i < num_espinhos; i++)
	{
		addEspinho(espins[i]);
	}

	for (i = 0; i < num_redes; i++)
	{
		addRede(reds[i]);
	}
}
