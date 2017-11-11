#pragma once
#include "Personagem.h"
class Jogador :
	public Personagem
{
private:
	static int num_jogs;
	int chances;
	bool subindo;
	bool subiu; // gerenciamento interno apenas
	bool imovel; // gerenciamento interno apenas
	int pers;
	ALLEGRO_TIMER*	timer_imovel;

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
	void builderJogador(const int ax, const int ay, const int aLimX, const int aLimy, 
		const bool aAtivo, const int aVida, Arma* const pArma, const int aChances);
	void atualizar();
	
	void createTimers();
	const bool getSubindo();
	void setSubindo(const bool aSubindo);
	void descer();
	void atualizaParado();
	void tomaDano(const int aDano, const int KB);
	void destruirTimer();
	void initTimer();
	const bool persPodeAtacar();
	Projetil* const atirar();
	const int getPers();
	void setPers(const int aPers);
	Arma* const constroiArma();
};

