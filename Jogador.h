#pragma once
#include "Personagem.h"
class Jogador :
	public Personagem
{
private:
	int chances;
	bool subindo;
	bool subiu;		//	gerenciamento interno apenas
	bool imovel;	//	gerenciamento interno apenas
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

	void builderJogador(const int ax, const int ay, const bool aAtivo, const int aID = -1, const int aChances = -1);
	void atualizar();
	
	void createTimers();
	const bool getSubindo();
	void setSubindo(const bool aSubindo);
	void descer();
	void atualizaParado();
	void tomaDano(const int aDano, const int KB);
	void destruirTimer();
	void initTimer();
	Projetil* const atirar();
	void reset(const int ax, const int ay, const bool aAtivo);
	void resetChances();
	void atualizaAtaque();
	void resetaTimers();
	void stopTimers();
	void resumeTimers();
};

