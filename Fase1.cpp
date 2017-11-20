#include "Fase1.h"

using namespace std;

Fase1::Fase1()
{
	numEntidades();
	alocaEntidades();
}


Fase1::~Fase1()
{
	deletaEntidades();
	anulaJogs();
	if (carregouAllegro)
	{
		al_destroy_timer(timer);
		al_destroy_font(arial18);
		al_destroy_event_queue(queue);
	}
}


void Fase1::initFase()
{
	initAllegroObjs();
	if (!carregouBotoes) {
		carregaBotoes();
	}
	buildEntidades();
	addEntidades();
	execFase();
}


void Fase1::buildEntidades()
{
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
	//armds[1]->builderArmadilha(150, ALT - 10, true);

	espins[0]->builderEspinho(500, ALT - 10, 50, 5, true);

	reds[0]->builderRede(800, ALT - 200, 700, ALT-15, true);

	//cavs[0]->builderEspadachimCav(1200, ALT-20, true, jog1);

	//esps[0]->builderEspadachim(700, ALT-20, true, jog1);

	//mosqs[0]->builderMosqueteiro(500, ALT-20, true, jog1);
}


void Fase1::numEntidades()
{
	num_plats = 4;
	num_cordas = 1;

	num_armds = 1;
	num_espinhos = 1;
	num_redes = 1;

	num_cavs = 0;
	num_esps = 0;
	num_mosq = 0;
}