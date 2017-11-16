#include "Animacao.h"

Animacao::Animacao()
{
	sprite = nullptr;
	ID = -1;
	currFrame = 0;
	largFrame = 0;
	altFrame = 0;
	numFrames = 0;
}


Animacao::~Animacao()
{	
	if(sprite != nullptr)
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
	
	//al_draw_bitmap(sprite, aPosX, aPosY- al_get_bitmap_height(sprite), 0); //	MUDAR E ACERTAR ISSO
	al_draw_bitmap_region(sprite, largFrame*currFrame, 0, largFrame, altFrame, aPosX, aPosY - altFrame, 0);

	//al_draw_filled_rectangle(aPosX, aPosY, aPosX + largFrame, aPosY + largFrame, al_map_rgb(255, 255, 255));
	if (al_get_timer_count(periodo) >= 1)
	{
		al_set_timer_count(periodo, 0);
		currFrame++;
	}
}


const int Animacao::getID()
{
	return ID;
}


Animacao* const Animacao::copiaAnimacao()
{
	Animacao* pAnim = new Animacao;
	pAnim->setSprite(sprite, ID, largFrame, altFrame, numFrames, al_get_timer_speed(periodo));
	return pAnim;
}


void Animacao::resetaAnim()
{
	currFrame = 0;
}
