#include "Fase1.h"

using namespace std;

Fase1::Fase1():Fase()
{
	numEntidades();
	alocaEntidades();
}


Fase1::~Fase1()
{
	
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
	int perc; 
	srand(time(NULL));

	if (num_jogs >= 1)
	{
		jog1->buildJogador(40, ALT - 50, true);
		//jog1->setChances(1);
	}
	if (num_jogs == 2)
	{
		jog2->buildJogador(80, ALT - 50, true);
	}

	//	chão
	plats[0]->buildPlataforma(0, ALT, LARG * 7, 30, true, true);
	mapaFase.setLimX(LARG * 7); //	o limite da fase é definido por até onde o mapa vai
	//	plat 1
	plats[1]->buildPlataforma(LARG+100, ALT - 95, 150, 10, true, false);
	//	plat 2
	plats[2]->buildPlataforma(LARG*2, ALT-95, 50, 10, true, false);
	//	plat 3
	plats[3]->buildPlataforma(LARG*3-150, ALT-95, 150, 10, true, false);
	//	monte
	plats[4]->buildPlataforma(LARG*3+150, ALT, LARG+150, 210, true, true);
	//	plat 4
	plats[5]->buildPlataforma(LARG*5+50, ALT - 95, 50, 10, true, false);

	//	corda esq
	cords[0]->buildCorda(LARG*3+135, ALT - 30, 10, 230, true, true);
	//	corda dir
	cords[1]->buildCorda(LARG*4+305, ALT - 30, 10, 230, true, true);
	
	//	armd 1 op 80%
	armds[0]->buildArmadilha(LARG+100, ALT - 30, true);
	perc = rand()%101;
	if (perc > 80)
		armds[0]->setAtivo(false);
	//	armd 2
	armds[1]->buildArmadilha(LARG*3-80, ALT - 30, true);
	//	armd 3 op 30%
	armds[2]->buildArmadilha(LARG*5+68, ALT - 105, true);
	perc = rand() % 101;
	if (perc > 30)
		armds[2]->setAtivo(false);

	//	espinho 1
	espins[0]->buildEspinho(LARG*2-95, ALT - 30, 250, 5, true);
	//	espinho 2
	espins[1]->buildEspinho(LARG*5-45, ALT - 30, 250, 5, true);

	//	rede 1 op 70%
	reds[0]->buildRede(LARG * 4 + 100, ALT - 410, LARG * 4-100, ALT - 210, true);
	perc = rand() % 101;
	if (perc > 70)
		reds[0]->setAtivo(false);
	//	rede 2
	reds[1]->buildRede(LARG*6-10, ALT - 240, LARG*6-100, ALT-30, true);

	//	esp 1
	esps[0]->buildEspadachim(LARG+250, ALT - 30, true, jog1);
	//	esp 2 op 50%
	esps[1]->buildEspadachim(LARG*4-150, ALT - 210, true, jog1);
	perc = rand() % 101;
	if (perc > 50)
		esps[1]->setAtivo(false);
	//	esp 3
	esps[2]->buildEspadachim(LARG*4 + 400, ALT - 30, true, jog1);
	//	esp 4 op 60%
	esps[3]->buildEspadachim(LARG*6+200, ALT - 30, true, jog1);
	perc = rand() % 101;
	if (perc > 60)
		esps[3]->setAtivo(false);
	
	//	mosq 1
	mosqs[0]->buildMosqueteiro(LARG*3-40, ALT-105, true, jog1);
	//	mosq 2 op 40%
	mosqs[1]->buildMosqueteiro(LARG*3, ALT - 30, true, jog1);
	perc = rand() % 101;
	if (perc > 40)
		mosqs[1]->setAtivo(false);
	//	mosq 3
	mosqs[2]->buildMosqueteiro(LARG*4+250, ALT - 210, true, jog1);
	//	mosq 4
	mosqs[3]->buildMosqueteiro(LARG*6+270, ALT - 30, true, jog1);
}


void Fase1::numEntidades()
{
	num_plats = 6;
	num_cordas = 2;

	num_armds = 3;
	num_espinhos = 2;
	num_redes = 2;

	num_cavs = 0;
	num_esps = 4;
	num_mosq = 4;
}


void Fase1::carregaFundoMapa()
{
	if (!carregouFundoMapa)
	{
		ALLEGRO_BITMAP* fundo;
		fundo = al_load_bitmap("sprites/backgrounds/fundoFase.png");
		mapaFase.setFundo(fundo);
		carregouFundoMapa = true;
	}
}
