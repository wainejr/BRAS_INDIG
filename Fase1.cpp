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
	fase_completa = false;
	int x = 0;
	int y = 0;

	enum KEYS { UP, DOWN, LEFT, RIGHT, SPACE, W, S, A, D, CTRL};
	bool keys[10] = { false, false, false, false, false, false, false, false, false, false};

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
						//if (jog1->getChances() <= 0)
							//num_jogs--;
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
							if (mapaFase.jogadorPodeSubir(jog1))
								jog1->subir();
							else if (mapaFase.personagemPodePular(static_cast<Personagem*>(jog1)))
								jog1->pular();
						}
						if (keys[CTRL] && mapaFase.personagemPodeAtacar(static_cast<Personagem*>(jog1)))
						{
							if (jog1->getArma()->getID() == ARCO)
								mapaFase.addProjetil(jog1->atirar());
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
							if (mapaFase.jogadorEstaNumaCorda(jog1) && !mapaFase.personagemPodePular(static_cast<Personagem*>(jog1)))
								jog1->descer();
							else if (mapaFase.persPodeDescerPlat(static_cast<Personagem*>(jog1)))
								mapaFase.perDescePlat(static_cast<Personagem*>(jog1));
						}
					}
				}
				if (num_jogs == 2 && jog2->getAtivo())
				{
					if (jog2->getVida() <= 0)
					{
						jog2->setChances(jog2->getChances() - 1);
						//if (jog2->getChances() <= 0)
							//num_jogs--;
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
							if (mapaFase.jogadorPodeSubir(jog2))
								jog2->subir();
							else if (mapaFase.personagemPodePular(static_cast<Personagem*>(jog2)))
								jog2->pular();
						}
						if (keys[SPACE] && mapaFase.personagemPodeAtacar(static_cast<Personagem*>(jog2)))
						{
							if (jog2->getArma()->getID() == ARCO)
								mapaFase.addProjetil(jog2->atirar());
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
							if (mapaFase.jogadorEstaNumaCorda(jog2) && !mapaFase.personagemPodePular(static_cast<Personagem*>(jog2)))
								jog2->descer();
							else if (mapaFase.persPodeDescerPlat(static_cast<Personagem*>(jog2)))
								mapaFase.perDescePlat(static_cast<Personagem*>(jog2));
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
					mapaFase.atualizaMapa();
			}
		}

		if (redraw && al_is_event_queue_empty(queue) && !resetar && !done)
		{
			mapaFase.desenhaObjs();
			//FUNÇAO DE TESTE
			imprimeVida();
			redraw = false;
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}
	al_stop_timer(timer);
}


//FUNÇÃO PARA TESTES RETIRAR DEPOIS
void Fase1::imprimeVida()
{
	al_draw_textf(arial18, al_map_rgb(255, 255, 255), 10, 20, ALLEGRO_ALIGN_LEFT,
		"VIDA: %i", jog1->getVida());
}


void Fase1::buildEntidades()
{
	///	SETAR A POSIÇÃO DOS JOGADORES EM X E Y TAMBÉM
	if (num_jogs >= 1)
	{
		jog1->builderJogador(25, ALT - 50, true);
	}
	if (num_jogs == 2)
	{
		jog2->builderJogador(50, ALT - 50, true);
	}

	plats[0]->builderPlataforma(0, ALT, LARG * 4, 10, true, true);
	plats[1]->builderPlataforma(50, ALT - 70, 100, 10, true, false);
	plats[2]->builderPlataforma(300, ALT-70, 50, 10, true, false);
	plats[3]->builderPlataforma(350, ALT-120, 75, 10, true, false);
	
	cords[0]->builderCorda(430, ALT - 10, 10, 130, true, true);

	armds[0]->builderArmadilha(100, ALT - 10, true);

	//espins[0]->builderEspinho(500, ALT - 10, 50, 5, true);

	reds[0]->builderRede(800, ALT - 200, 700, ALT-15, true);

	cavs[0]->builderEspadachimCav(1200, ALT-20, true, jog1);

	esps[0]->builderEspadachim(700, ALT-20, true, jog1);

	mosqs[0]->builderMosqueteiro(500, ALT-20, true, jog1);
}


void Fase1::numEntidades()
{
	num_plats = 4;
	num_cordas = 1;

	num_armds = 1;
	num_espinhos = 0;
	num_redes = 1;

	num_cavs = 1;
	num_esps = 1;
	num_mosq = 1;
}