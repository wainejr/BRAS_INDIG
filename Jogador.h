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
	Jogador(const int aChances, const int aID, const int aVida = VIDA_MAX_JOG, const float aVelX = 0,
		const float aVelY = 0, const float aVelMaxX = VEL_MAX_X_JOG,
		const float aVelMaxY = VEL_SUBIDA, const bool aFisica = true,
		const float aPosX = 0, const float aPosY = 0, const int aLimX = LIM_X_JOG,
		const int aLimY = LIM_Y_JOG, const bool aAtivo = 0);
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

	void buildJogador(const int ax, const int ay, const bool aAtivo, const int aID = -1, const int aChances = -1);
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

	Jogador& operator--()
	{
		chances--;
		return *this;
	}
	
	Jogador& operator--(int)
	{
		return--(*this);
	}
	
};

