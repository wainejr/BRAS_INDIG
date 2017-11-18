#pragma once
#include "Fase.h"
class FaseFinal :
	public Fase
{
public:
	FaseFinal();
	~FaseFinal();
	void restart();
	void initFase();

	void numEntidades() {}
	void buildEntidades() {}
};

