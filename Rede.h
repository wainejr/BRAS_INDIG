#pragma once
#include "Obstaculo.h"
#include "Corda.h"
class Rede :
	public Obstaculo
{
public:
	Rede();
	~Rede();
private:
	Corda* linha;
public:
	Corda* const getCorda();
	void setCorda(Corda* const pCorda);
	void builderCorda();
};

