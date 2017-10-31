#pragma once
#include "ArmaDeAlcance.h"
class Arco :
	public ArmaDeAlcance
{
public:
	Arco();
	~Arco();
private:
	float forca;
public:
	void setForca(const float aForca);
	const float getForca();
};

