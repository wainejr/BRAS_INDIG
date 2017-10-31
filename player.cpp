#include "player.h"



player::player()
{
	ID = 1;
	x = 20;
	y = 150;
	velX = 10;
	velY = 9;
	tamX = 10;
	tamY = 30;
	vidas = 3;
	pontos = 0;
}


player::~player()
{
}

void player::draw()
{
	al_draw_filled_rectangle(x-tamX, y-tamY, x + tamX, y + tamY, al_map_rgb(140, 150, 9));
}

void player::moverCima(){
	if (y >= 480)
		velY = -10;
}
void player::moverBaixo(){
	/*
	y +=vel;
	if (y > 480-tamY)
		y = 480-tamY;
	*/
}
void player::moverEsq(){
	x -= velX;
	if (x < (tamX+2))
		x = tamX + 2;
}
void player::moverDir(){
	x += velX;
	if (x > 400)
		x = 400;
}