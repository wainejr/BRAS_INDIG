#pragma once
#include "Inimigo.h"
class Mosqueteiro :
	public Inimigo
{
public:
	Mosqueteiro();
	~Mosqueteiro();
	void mover();
	void atacar();
	void atualizar();
	void draw();
	void builderMosqueteiro();
};

