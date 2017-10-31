#pragma once
#include <allegro5\allegro5.h>
#include <allegro5/allegro_primitives.h>
class player
{
public:
	player();
	~player();

	int ID;
	int x;
	int y;
	float velX;
	float velY;
	int tamX;
	int tamY;
	int vidas;
	int pontos;
	void draw();

	void moverCima();
	void moverBaixo();
	void moverEsq();
	void moverDir();
};

struct bullet
{
	int ID;
	int x;
	int y;
	bool live;
	int vel;
};

struct morte
{
	int ID;
	int x;
	int y;
	int vel;
	int tamX;
	int tamY;
	bool live;
	
};

