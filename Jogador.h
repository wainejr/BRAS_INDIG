#pragma once
#include "Personagem.h"
class Jogador :
	public Personagem
{
private:
	static int num_jogs;
	int chances;

public:
	Jogador();
	~Jogador();
	void atacar();
	void moverDir();
	void moverEsq();
	void pular();
	void setChances(const int aChances);
	const int getChances();
	// para cordas
	void subir();
	void draw(const int aPosFaseX, const int aPosFaseY);

	// para não tomar dano seguidamente
	void builderJogador(const int ax, const int ay, const int aLimX, const int aLimy, const bool aAtivo, const int aVida, Arma* const pArma, const int aChances);
	void atualizar();
	
	void initTimerInv();
	void destroyTimerInv();
	void createTimers();
};

