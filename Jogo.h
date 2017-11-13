#pragma once
#include "ListaFases.h"

enum ESTADOS{FASE, MENUPRINCIPAL, MENUPAUSE};

class Jogo
{
private:
	//VARIAVEIS ALLEGRO
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_EVENT_QUEUE* queue = NULL;
	ALLEGRO_FONT* arial18 = NULL;
	
	//OBJETOS
	Fase1 fasePrototipo;
	Jogador player;
	

	void exec();
public:
	Jogo();
	~Jogo();
	
};

