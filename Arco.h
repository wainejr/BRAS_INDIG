#pragma once
#include "ArmaDeAlcance.h"
class Arco :
	public ArmaDeAlcance
{
private:
	float forca;
public:
	Arco();
	~Arco();
	void setForca(const float aForca);
	const float getForca();
	void atacar();
};
