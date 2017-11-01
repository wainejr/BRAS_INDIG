#include "Arco.h"



Arco::Arco()
{
	forca = 0.0f;
}


Arco::~Arco()
{
}


void Arco::atacar()
{
}


void Arco::setForca(const float aForca)
{
	forca = aForca;
}


const float Arco::getForca()
{
	return forca;
}


