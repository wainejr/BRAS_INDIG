#pragma once
#include "Personagem.h"
class Jogador :
	public Personagem
{
private:
	static int num_jogs;
	bool invuneravel;
	int chances;
	const int getChances();

public:
	Jogador();
	~Jogador();
	void atacar();
	void moverDir();
	void moverEsq();
	void pular();
	void setChances(const int aChances);
	// para cordas
	void subir();
	void draw();

	// para não tomar dano seguidamente
	const bool getInvuneravel();
	void setInvuneravel(const bool aInv);
	void builderJogador();
	void atualizar();
	
};

