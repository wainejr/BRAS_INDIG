#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>

class Animacao
{
private:
	ALLEGRO_BITMAP* sprite;
	//	O TIMER SÓ É CRIADO POR AQUELES QUE EFETIVAMENTE 
	//	ITERAM DENTRE AS SPRITES, CASO APENAS DOS PERSONAGENS
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
		const int aAltFrame, const int aNumFrames = 1, const float aPeriodo = 0);
	void draw(const int aPosX, const int aPosY);
	const int getID();
	Animacao* const copiaAnimacao();
	void resetaAnim();
	void stopTimer();
	void resumeTimer();
};

