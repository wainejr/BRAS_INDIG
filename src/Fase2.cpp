#include "Fase2.h"

Fase2::Fase2():Fase()
{
	numEntidades();
	alocaEntidades();
}


Fase2::~Fase2()
{
}


void Fase2::carregaFundoMapa()
{
	if (!carregouFundoMapa)
	{
		ALLEGRO_BITMAP* fundo;
		fundo = al_load_bitmap("sprites/backgrounds/fundoFase.png");
		mapaFase.setFundo(fundo);
		carregouFundoMapa = true;
	}
}


void Fase2::numEntidades()
{
	num_plats = 4;
	num_cordas = 2;

	num_armds = 5;
	num_espinhos = 1;
	num_redes = 2;

	num_cavs = 2;
	num_esps = 4;
	num_mosq = 4;

}

void Fase2::buildEntidades()
{
	int perc;
	srand(time(NULL));

	if (num_jogs >= 1)
	{
		jog1->buildJogador(40, ALT - 50, true);
	}
	if (num_jogs == 2)
	{
		jog2->buildJogador(80, ALT - 50, true);
	}
								
	//	ch�o
	plats[0]->buildPlataforma(0, ALT, LARG * 7, 30, true, true);
	mapaFase.setLimX(LARG * 7); //	o limite da fase � definido por at� onde o mapa vai
	//	plat 1
	plats[1]->buildPlataforma(350, ALT - 95, 150, 10, true, false);
	//	plat 2
	plats[2]->buildPlataforma(LARG*2+50, ALT-95, 50, 10, true, false);
	//	monte
	plats[3]->buildPlataforma(LARG*3-100, ALT, LARG+150, 210, true, true);

	//	corda esq
	cords[0]->buildCorda(LARG * 3 - 115, ALT - 30, 10, 210, true, true);
	//	corda dir
	cords[1]->buildCorda(LARG * 4 + 55, ALT - 30, 10, 210, true, true);

	
	//	armd 1 
	armds[0]->buildArmadilha(420, ALT - 105, true);
	//	armd 2 op
	armds[1]->buildArmadilha(LARG + 400, ALT - 30, true);
	perc = rand() % 101;
	if (perc > 60)
		armds[1]->setAtivo(false);
	//	armd 3 op
	armds[2]->buildArmadilha(LARG*2 + 70, ALT - 105, true);
	perc = rand() % 101;
	if (perc > 50)
		armds[2]->setAtivo(false);
	//	armd 4 
	armds[3]->buildArmadilha(LARG * 3.5 + 70, ALT - 210, true);
	//	armd 5 op
	armds[4]->buildArmadilha(LARG * 6, ALT - 30, true);
	perc = rand() % 101;
	if (perc > 70)
		armds[4]->setAtivo(false);

	//rede 1 op
	reds[0]->buildRede(LARG + 90, ALT - 240, LARG-120, ALT - 30, true);
	perc = rand() % 101;
	if (perc > 30)
		reds[0]->setAtivo(false);
	//	rede 2
	reds[1]->buildRede(LARG * 5 + 390, ALT - 240, LARG * 5 + 160, ALT - 30, true);
	
	
	//	espinho 1
	espins[0]->buildEspinho(LARG * 2 - 100, ALT - 30, 350, 5, true);
	
	
	//	esp 1 op
	esps[0]->buildEspadachim(LARG*2 - 250, ALT - 30, true, jog1);
	perc = rand() % 101;
	if (perc > 20)
		esps[0]->setAtivo(false);
	//	esp 2 
	esps[1]->buildEspadachim(LARG * 3 + 150, ALT - 210, true, jog1);
	//	esp 3
	esps[2]->buildEspadachim(LARG * 4 + 400, ALT - 30, true, jog1);
	//	esp 4 op 
	esps[3]->buildEspadachim(LARG * 6 + 200, ALT - 30, true, jog1);
	perc = rand() % 101;
	if (perc > 70)
		esps[3]->setAtivo(false);
	

	//	mosq 1
	mosqs[0]->buildMosqueteiro(LARG * 2 - 200, ALT - 30, true, jog1);
	//	mosq 2 op
	mosqs[1]->buildMosqueteiro(LARG * 4, ALT - 210, true, jog1);
	perc = rand() % 101;
	if (perc > 40)
		mosqs[1]->setAtivo(false);
	//	mosq 3 op
	mosqs[2]->buildMosqueteiro(LARG * 4 + 450, ALT - 30, true, jog1);
	perc = rand() % 101;
	if (perc > 60)
		mosqs[2]->setAtivo(false);
	//	mosq 4
	mosqs[3]->buildMosqueteiro(LARG * 6 + 250, ALT - 30, true, jog1);

	// cav 1
	cavs[0]->buildCav(LARG - 100, ALT - 30, true, jog1);
	// cav 2 op
	cavs[1]->buildCav(LARG*4-100, ALT - 210, true, jog1);
	perc = rand() % 101;
	if (perc > 30)
		cavs[1]->setAtivo(false);
}
