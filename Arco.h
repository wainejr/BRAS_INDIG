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
	void atacar();
	void builderArco(const int ax, const int ay, const int aLimX, const int aLimY, const bool aFisica, const bool aAtivo, const int aDano, Personagem* const pDonoArma);
};

