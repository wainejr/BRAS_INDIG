#include "ListaObstaculos.h"



ListaObstaculos::ListaObstaculos()
{
}


ListaObstaculos::~ListaObstaculos()
{
}


void ListaObstaculos::addObst(Obstaculo* const pObst)
{
	if (pObst != nullptr)
		obstaculos.addObj(pObst);
}


void ListaObstaculos::retirarObst(Obstaculo* const pObst)
{
	if (pObst != nullptr)
		obstaculos.retirarObj(pObst);
}


const int ListaObstaculos::numObst()
{
	return obstaculos.numObjs();
}


Obstaculo* const ListaObstaculos::obstPosi(const int i)
{
	return obstaculos.objI(i);
}
