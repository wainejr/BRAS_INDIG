#include "Animacao.h"

Animacao::Animacao()
{
	sprite = nullptr;
	periodo = nullptr;
	ID = -1;
	currFrame = 0;
	largFrame = 0;
	altFrame = 0;
	numFrames = 0;
}


Animacao::~Animacao()
{	
	al_destroy_timer(periodo);
	al_destroy_bitmap(sprite);
}


void Animacao::setSprite(ALLEGRO_BITMAP* const pSprite, const int aID, const int aLargFrame, 
	const int aAltFrame, const int aNumFrames, const float aPeriodo)
{
	if(pSprite != nullptr)
		sprite = pSprite;
	ID = aID;
	largFrame = aLargFrame;
	altFrame = aAltFrame;
	numFrames = aNumFrames;
	if (aPeriodo > 0)
	{
		periodo = al_create_timer(aPeriodo);
		al_start_timer(periodo);
	}
}


void Animacao::draw(const int aPosX, const int aPosY)
{
	if (currFrame >= numFrames)
	{
		currFrame = 0;
	}
	
	al_draw_bitmap_region(sprite, largFrame*currFrame, 0, largFrame, altFrame, aPosX-al_get_bitmap_width(sprite)/2, aPosY - altFrame, 0);

	if (periodo != nullptr) 
	{
		if (al_get_timer_count(periodo) >= 1)
		{
			al_set_timer_count(periodo, 0);
			currFrame++;
		}
	}
}


const int Animacao::getID()
{
	return ID;
}


Animacao* const Animacao::copiaAnimacao()
{
	Animacao* pAnim = new Animacao;
	if (periodo != nullptr)
		pAnim->setSprite(sprite, ID, largFrame, altFrame, numFrames, al_get_timer_speed(periodo));
	else
		pAnim->setSprite(sprite, ID, largFrame, altFrame, numFrames);
	return pAnim;
}


void Animacao::resetaAnim()
{
	currFrame = 0;
}


void Animacao::stopTimer()
{
	if (periodo != nullptr)
		al_stop_timer(periodo);
}


void Animacao::resumeTimer()
{
	if (periodo != nullptr)
		al_resume_timer(periodo);
}
