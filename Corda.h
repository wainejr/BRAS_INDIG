#pragma once
#include "Plataforma.h"
class Corda :
	public Plataforma
{
public:
	Corda();
	~Corda();
	void setEscalavel(const bool aEscalav);
	const bool getEscalavel();
private:
	bool escalavel;
public:
	void draw();
	void builderCorda();
};

