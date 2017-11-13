#pragma once
#include "Arma.h"
class Arco :
	public Arma
{
private:
	float forca;
public:
	Arco();
	~Arco();
	void setForca(const float aForca);
	const float getForca();
	void builderArco(const int ax, const int ay, const bool aAtivo, Personagem* const pDonoArma);
	void draw(const int aPosFaseX, const int aPosFaseY);
};

