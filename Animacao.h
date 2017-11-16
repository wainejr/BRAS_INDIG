#pragma once
#include "allegro5\allegro.h"
#include "allegro5\allegro_image.h"

class Animacao
{
private:
	ALLEGRO_BITMAP* sprite;
	ALLEGRO_TIMER* periodo;
	int ID;
	int currFrame;
	int largFrame;  
	int altFrame;
	int numFrames;
public:
	Animacao();
	~Animacao();

	void setSprite(ALLEGRO_BITMAP* const pSprite, const int aID, const int aLargFrame,
		const int aAltFrame, const int aNumFrames, const float aPeriodo);
	void draw(const int aPosX, const int aPosY);
	const int getID();
	Animacao* const copiaAnimacao();
	void resetaAnim();
};

