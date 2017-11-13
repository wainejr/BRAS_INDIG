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
	buildEntidades();
	addEntidades();
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
	bool keys[10] = { false, false, false, false, false, false, false, false, false, false};

	//	VARIAVEIS AUXILIARES
	Jogador* jog1;
	Jogador* jog2;

	if (num_jogs >= 1)
		jog1 = jogadores.objI(0);
	if (num_jogs == 2)
		jog2 = jogadores.objI(1);

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
				if (num_jogs >= 1 && jog1->getAtivo())
				{
					if (jog1->getVida() <= 0)
					{
						jog1->setChances(jog1->getChances() - 1);
						jog1->setVida(VIDA_MAX_JOG);
						jog1->setAtivo(false);
						jogadores.retirarObj(jog1);
						if (jog1->getChances() <= 0)
							num_jogs--;
					}
					else 
					{
						if (keys[LEFT])
						{
							jog1->moverEsq();
						}
						if (keys[RIGHT])
						{
							jog1->moverDir();
						}
						if (keys[UP])
						{
							if (jogadorPodeSubir(jog1))
								jog1->subir();
							else if (personagemPodePular(static_cast<Personagem*>(jog1)))
								jog1->pular();
						}
						if (keys[CTRL] && personagemPodeAtacar(static_cast<Personagem*>(jog1)))
						{
							if (jog1->getArma()->getID() == ARCO)
								projeteis.addObj(jog1->atirar());
							else if (jog1->getArma()->getID() == ESPADA)
								jog1->atacar();
							keys[CTRL] = false; //evitar ataques contínuos
						}
						if (!keys[LEFT] && !keys[RIGHT])
						{
							jog1->parar();
						}
						if (keys[DOWN])
						{
							if (jogadorEstaNumaCorda(jog1) && !personagemPodePular(static_cast<Personagem*>(jog1)))
								jog1->descer();
							else if (persPodeDescerPlat(static_cast<Personagem*>(jog1)))
								perDescePlat(static_cast<Personagem*>(jog1));
						}
					}
				}
				if (num_jogs == 2 && jog2->getAtivo())
				{
					if (jog2->getVida() <= 0)
					{
						jog2->setChances(jog2->getChances() - 1);
						jog2->setVida(VIDA_MAX_JOG);
						jog2->setAtivo(false);
						jogadores.retirarObj(jog2);
						if (jog2->getChances() <= 0)
							num_jogs--;
					}
					else {
						if (keys[A])
						{
							jog2->moverEsq();
						}
						if (keys[D])
						{
							jog2->moverDir();
						}
						if (keys[W])
						{
							if (jogadorPodeSubir(jog2))
								jog2->subir();
							else if (personagemPodePular(static_cast<Personagem*>(jog2)))
								jog2->pular();
						}
						if (keys[SPACE] && personagemPodeAtacar(static_cast<Personagem*>(jog2)))
						{
							if (jog2->getArma()->getID() == ARCO)
								projeteis.addObj(jog2->atirar());
							else if (jog2->getArma()->getID() == ESPADA)
								jog2->atacar();
							keys[SPACE] = false; //evitar ataques contínuos
						}
						if (!keys[A] && !keys[D])
						{
							jog2->parar();
						}
						if (keys[S])
						{
							if (jogadorEstaNumaCorda(jog2) && !personagemPodePular(static_cast<Personagem*>(jog2)))
								jog2->descer();
							else if (persPodeDescerPlat(static_cast<Personagem*>(jog2)))
								perDescePlat(static_cast<Personagem*>(jog2));
						}
					}
				}
				
				if (jog1->getChances() <= 0 && jog2->getChances() <= 0)
				{
					done = true;
					redraw = false;
					resetar = false;
				}
				else 
				{
					if (num_jogs == 1 && !jog1->getAtivo())
					{
						resetar = true;
					}
					else if (num_jogs == 2 && !jog1->getAtivo() && !jog2->getAtivo())
					{
						resetar = true;
					}
				}
				if(!resetar && !done)
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

	al_stop_timer(timer);
	return;
}


void Fase1::initAllegroObjs()
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

		arial18 = al_load_ttf_font("arial.ttf", 18, 0);
		display = al_create_display(LARG, ALT);
		queue = al_create_event_queue();
		timer = al_create_timer(1.0 / FPS);

		//	----------	ADD FONTES À FILA DE EVENTOS   -------------
		al_register_event_source(queue, al_get_keyboard_event_source());
		al_register_event_source(queue, al_get_mouse_event_source());
		al_register_event_source(queue, al_get_timer_event_source(timer));
		al_register_event_source(queue, al_get_display_event_source(display));
		carregouAllegro = true;
	}
}


void Fase1::restart()
{
	resetAllObjs();
	buildEntidades();
	addEntidades();
	//adicionar código aqui pra clicar pra reiniciar e tals
}

//FUNÇÃO PARA TESTES RETIRAR DEPOIS
void Fase1::imprimeVida()
{
	al_draw_textf(arial18, al_map_rgb(255, 255, 255), 10, 20, ALLEGRO_ALIGN_LEFT,
		"VIDA: %i", jog1->getVida());
}


void Fase1::alocaEntidades()
{
	int i;

	mosqs = new Mosqueteiro*[num_mosq];
	for (i = 0; i < num_mosq; i++)
	{
		mosqs[i] = new Mosqueteiro;
	}

	esps = new Espadachim*[num_esps];
	for (i = 0; i < num_esps; i++)
	{
		esps[i] = new Espadachim;
	}

	cavs = new EspadachimCavaleiro*[num_cavs];
	for (i = 0; i < num_cavs; i++)
	{
		cavs[i] = new EspadachimCavaleiro;
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
	}
	delete(mosqs);
	
	for (i = 0; i < num_esps; i++)
	{
		delete (esps[i]);
	}
	delete(esps);

	for (i = 0; i < num_cavs; i++)
	{
		delete (cavs[i]);
	}
	delete(cavs);

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
	if (num_jogs >= 1)
	{
		jog1->setY(ALT - 50);
		jog1->setX(10);
		jog1->setAtivo(true);
	}
	if (num_jogs == 2)
	{
		jog2->setY(ALT - 50);
		jog2->setX(40);
		jog2->setAtivo(true);
	}

	plats[0]->builderPlataforma(0, ALT, LARG * 4, 10, true, true);
	plats[1]->builderPlataforma(50, ALT - 70, 100, 10, true, false);
	plats[2]->builderPlataforma(300, ALT-70, 50, 10, true, false);
	plats[3]->builderPlataforma(350, ALT-120, 75, 10, true, false);
	
	cords[0]->builderCorda(430, ALT - 10, 10, 130, true, true);

	armds[0]->builderArmadilha(100, ALT - 10, true);

	espins[0]->builderEspinho(500, ALT - 10, 50, 5, true);

	reds[0]->builderRede(800, ALT - 200, 700, ALT-15, true);
	reds[0]->getCorda()->builderCorda(800, ALT - 15, 5, 5, true, false);

	cavs[0]->builderEspadachimCav(1200, ALT-20, true, jog1);

	esps[0]->builderEspadachim(700, ALT-20, true, jog1);

	mosqs[0]->builderMosqueteiro(500, ALT-20, true, jog1);
}


void Fase1::numEntidades()
{
	num_plats = 4;
	num_cordas = 1;
	
	num_armds = 1;
	num_espinhos = 1;
	num_redes = 1;

	num_cavs = 1;
	num_esps = 1;
	num_mosq = 1;	
}


void Fase1::addEntidades()
{
	int i;
	
	if (num_jogs >= 1)
	{
		addPlayer(jog1);
	}
	if (num_jogs == 2)
	{
		addPlayer(jog2);
	}

	for (i = 0; i < num_esps; i++)
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
