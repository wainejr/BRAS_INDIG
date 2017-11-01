#pragma once
#include "fase.h"
#include "definesMacros.h"

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
	Fase fasePrototipo;
	Jogador player;
	Mosqueteiro inimigo1;
	Plataforma chao;
	Espada armaPlayer;
	Espada armaInimigo;

	void exec();
public:
	Jogo();
	~Jogo();
	
};

