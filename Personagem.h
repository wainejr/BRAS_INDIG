#pragma once
#include "Entidade.h"
#include "Arma.h"

class Personagem :
	public Entidade
{
protected:
	int vida;
	Arma* arma;
	//	verdadeiro para personagem virado para direita,
	//	falso para personagem virado para esquerda
	bool dir;
	bool podeAtacar;
	bool atacando;
	bool invuneravel;
	ALLEGRO_TIMER*  timer_ataque;
	ALLEGRO_TIMER*  timer_atacando;
	ALLEGRO_TIMER*  timer_invuneravel;
public:
	Personagem();
	~Personagem();
	const int getVida();
	void setVida(const int aVida);
	Arma* const getArma();
	void parar();
	virtual void atacar();
	virtual void atualizar() = 0;
	void atualizaArma();
	virtual void draw(const int aPosFaseX, const int aPosFaseY) = 0;
	void tomaDano(const int aDano);

	void setArma(Arma* const pArma);
	void setDir(bool const aDir);
	const bool getDir();
	void cair(const float acAt);
	void setAtacando(const bool aAt);
	const bool getAtacando();
	void initTimer();
	void destruirTimer();
	virtual const bool persPodeAtacar();
	virtual void createTimers() = 0;
	void setInvuneravel(const bool aInv);
	const bool getInvuneravel();
	void atualizaInvuneravel();
	void atualizaAtacando();
	void atualizaAtaque();
};

