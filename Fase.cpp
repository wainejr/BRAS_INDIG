#include "Fase.h"

Fase::Fase()
{

}


Fase::~Fase()
{
	
}

bool Fase::campanha = false;


int Fase::num_jogs = 0;


Jogador* Fase::jog1 = nullptr;
Jogador* Fase::jog2 = nullptr;


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

//	TA DANDO LEAK DE MEMÓRIA, CHAMAR A DESTRUTORA DEBAIXO ANTES DE DAR DELETE
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
		//plats[i]->~Plataforma();
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


void Fase::destroyAllegroObjs()
{
	if (carregouAllegro)
	{
		al_destroy_display(display);
		al_destroy_timer(timer);
	}
}