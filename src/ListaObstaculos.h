#pragma once
#include "Lista.h"
#include "Obstaculo.h"
class ListaObstaculos
{
private:
	Lista<Obstaculo*> obstaculos;

public:
	ListaObstaculos();
	~ListaObstaculos();
	void addObst(Obstaculo* const pObst);
	void retirarObst(Obstaculo* const pObst);
	const int numObst();
	Obstaculo* const obstPosi(const int i);
};

