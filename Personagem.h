#pragma once
#include "Entidade.h"
#include "Arco.h"
#include "Mosquete.h"
#include "Lanca.h"
#include "Espada.h"

class Personagem :
	public Entidade
{
protected:
	int vida;
	Arma* arma;
	
	bool dir;
	bool podeAtacar;
	bool atacando;
	bool invuneravel;
	
	ALLEGRO_TIMER*  timer_ataque;
	ALLEGRO_TIMER*  timer_atacando;
	ALLEGRO_TIMER*  timer_invuneravel;
	bool criouTimers;
public:
	Personagem();
	Personagem(const int aVida, const float aVelX, const float aVelY, const float aVelMaxX,
		const float aVelMaxY, const int aID, const bool aFisica = true,
		const float aPosX = 0, const float aPosY = 0, const int aLimX = 0,
		const int aLimY = 0, const bool aAtivo = false);
	~Personagem();
	const int getVida();
	void setVida(const int aVida);
	Arma* const getArma();
	void parar();
	virtual void atacar() {}
	virtual void atualizar() = 0;
	void atualizaArma();
	virtual void draw(const int aPosFaseX, const int aPosFaseY) = 0;
	virtual void tomaDano(const int aDano, const int KB);

	void setArma(Arma* const pArma);
	void setDir(bool const aDir);
	const bool getDir();
	void cair(const float acAt);
	void setAtacando(const bool aAt);
	const bool getAtacando();
	virtual void initTimer();
	virtual void destruirTimer();
	const bool persPodeAtacar();
	virtual void createTimers() = 0;
	void setInvuneravel(const bool aInv);
	const bool getInvuneravel();
	void atualizaInvuneravel();
	void atualizaAtacando();
	virtual void atualizaAtaque();
	virtual Arma* const constroiArma();
	virtual void resetaTimers();
	virtual void stopTimers();
	virtual void resumeTimers();

	bool operator!()
	{
		if (vida <= 0)
			return true;
		return false;
	}
};

