#include "Fase.h"
#include "Jogo.h"


Fase::Fase()
{
	carregouBotoes = false;
}


Fase::~Fase()
{
	
}

bool Fase::campanha = false;


int Fase::num_jogs = 0;


Jogador* Fase::jog1 = nullptr;
Jogador* Fase::jog2 = nullptr;


void Fase::execFase()
{
	//VARIAVEIS PRIMITIVAS
	bool done = false;
	bool redraw = false;
	bool resetar = false;
	fase_completa = false;
	bool pausado = false;
	int x = 0;
	int y = 0;

	enum KEYS { UP, DOWN, LEFT, RIGHT, CTRL, W, S, A, D, SPACE, P, MOUSE_ESQ };
	bool keys[12] = { false, false, false, false, false, false, false, false, false, false, false, false };

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
			Jogo::setDone(true);
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
				keys[CTRL] = true;
				break;
			case ALLEGRO_KEY_P:
				keys[P] = !keys[P];
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
		else if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
			{
				if (keys[P] && !pausado)
				{
					pausado = true;
					mapaFase.stopTimers();
				}
				//	LOOP JOGO
				if (!pausado)
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
					if (!resetar && !done)
						mapaFase.atualizaMapa();
				}
				else
				{
					gerBotoesFase.checaSelec(x, y);
					if (botao_continuar.getSelec() && keys[MOUSE_ESQ] || !keys[P])
					{
						pausado = false;
						mapaFase.resumeTimers();
						keys[P] = false;
					}
					else if (botao_menu.getSelec() && keys[MOUSE_ESQ])
					{
						done = true;
					}
				}
			}
		}

		if (redraw && al_is_event_queue_empty(queue) && !resetar && !done)
		{
			if (!pausado)
				mapaFase.desenhaObjs();
			else
				gerBotoesFase.desenhaBotoes();
			redraw = false;
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}
	al_flush_event_queue(queue);
	mapaFase.retiraTodosObjs();
	//	RESETA OS JOGADORES PARA NÃO HAVER CONFLITO NO PRÓXIMA JOGADA
	anulaJogs();
	al_stop_timer(timer);
}


void Fase::initTimers()
{
	mapaFase.initTimers();
	al_start_timer(timer);
}


void Fase::criarTimers()
{
	mapaFase.criarTimers();
}


void Fase::setCampanha(const bool aCamp)
{
	campanha = aCamp;
}


const int Fase::getNumJogs()
{
	return num_jogs;
}


void Fase::setNumJogs(const int aNumJogs)
{
	num_jogs = aNumJogs;
}


Jogador* const Fase::getJog1()
{
	return jog1;
}


Jogador* const Fase::getJog2()
{
	return jog2;
}


void Fase::setJog1(Jogador* const pJog1)
{
	if (pJog1 != nullptr && pJog1 != jog2)
		jog1 = pJog1;
}


void Fase::setJog2(Jogador* const pJog2)
{
	if (pJog2 != nullptr && pJog2 != jog1)
		jog2 = pJog2;
}


void Fase::setFaseCompleta(const bool aCompleta)
{
	fase_completa = aCompleta;
}


const bool Fase::getFaseCompleta()
{
	return fase_completa;
}


void Fase::restart()
{
	mapaFase.retiraTodosObjs();
	buildEntidades();
	addEntidades();
	//adicionar código aqui pra clicar pra reiniciar e tals
}


void Fase::alocaEntidades()
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

//	TA DANDO LEAK DE MEMÓRIA NO DESTRUIR A SPRITE DA ANIMAÇAO
void Fase::deletaEntidades()
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


void Fase::addEntidades()
{
	int i;

	if (num_jogs >= 1)
	{
		mapaFase.addPlayer(jog1);
	}
	if (num_jogs == 2)
	{
		mapaFase.addPlayer(jog2);
	}

	for (i = 0; i < num_esps; i++)
	{
		mapaFase.addMosqueteiro(mosqs[i]);
	}

	for (i = 0; i < num_esps; i++)
	{
		mapaFase.addEspadachim(esps[i]);
	}

	for (i = 0; i < num_cavs; i++)
	{
		mapaFase.addCavaleiro(cavs[i]);
	}

	for (i = 0; i < num_plats; i++)
	{
		mapaFase.addPlataforma(plats[i]);
	}

	for (i = 0; i < num_cordas; i++)
	{
		mapaFase.addCorda(cords[i]);
	}

	for (i = 0; i < num_armds; i++)
	{
		mapaFase.addArmadilha(armds[i]);
	}

	for (i = 0; i < num_espinhos; i++)
	{
		mapaFase.addEspinho(espins[i]);
	}

	for (i = 0; i < num_redes; i++)
	{
		mapaFase.addRede(reds[i]);
	}
}


void Fase::initAllegroObjs()
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


void Fase::destroyAllegroObjs()
{
	if (carregouAllegro)
	{
		al_destroy_display(display);
		al_destroy_timer(timer);
	}
}

void Fase::anulaJogs()
{
	jog1 = nullptr;
	jog2 = nullptr;
}


void Fase::carregaBotoes()
{
	if (!carregouBotoes)
	{
		initBotoes();
		botao_continuar.setAtivo(true);
		botao_menu.setAtivo(true);
		gerBotoesFase.addBotao(&botao_continuar);
		gerBotoesFase.addBotao(&botao_menu);
		carregouBotoes = true;
	}
}

void Fase::initBotoes()
{
	ALLEGRO_FONT* arial;
	arial = al_load_ttf_font("arial.ttf", 18, 0);
	ALLEGRO_BITMAP* image_continuar;
	image_continuar = al_create_bitmap(LARG_BOTAO, ALT_BOTAO);
	al_set_target_bitmap(image_continuar);
	al_draw_rounded_rectangle(0, 0, LARG_BOTAO, ALT_BOTAO, 5, 5, al_map_rgb(255, 0, 0), 2);
	al_draw_text(arial, al_map_rgb(255, 0, 0), LARG_BOTAO / 2, ALT_BOTAO / 2 - al_get_font_line_height(arial) / 2, ALLEGRO_ALIGN_CENTER, "Continuar");
	botao_continuar.setSprite(image_continuar, LARG_BOTAO, ALT_BOTAO);
	botao_continuar.setX(LARG / 2 - LARG_BOTAO / 2);
	botao_continuar.setY(ALT / 2 - ALT_BOTAO/2-10);

	ALLEGRO_BITMAP* image_menu;
	image_menu = al_create_bitmap(LARG_BOTAO, ALT_BOTAO);
	al_set_target_bitmap(image_menu);
	al_draw_rounded_rectangle(0, 0, LARG_BOTAO, ALT_BOTAO, 5, 5, al_map_rgb(255, 0, 0), 2);
	al_draw_text(arial, al_map_rgb(255, 0, 0), LARG_BOTAO / 2, ALT_BOTAO / 2 - al_get_font_line_height(arial) / 2, ALLEGRO_ALIGN_CENTER, "Voltar ao Menu");
	botao_menu.setSprite(image_menu, LARG_BOTAO, ALT_BOTAO);
	botao_menu.setX(LARG/2-LARG_BOTAO/2);
	botao_menu.setY(ALT / 2 + ALT_BOTAO / 2 + 10);

	al_destroy_font(arial);
}




void Fase::setDisplay(ALLEGRO_DISPLAY* const pDisplay)
{
	display = pDisplay;
}
