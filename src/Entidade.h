 #pragma once

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_image.h>
#include "ProtoEntidade.h"
#include "gerenciaAnim.h"
#include "defineCarac.h"

//	O TAMANHO DOS INIMGOS/JOGADORES E A VELOCIDADE DAS BALAS DEVEM SER
//	DIMENSIONADOS PARA QUE OS PROJETEIS NAO PASSEM DELES

class Entidade :
	public ProtoEntidade
{
protected:

	//	A velocidade em y positiva corresponde ao personagem subir
	//	na tela, negativa, descer.

	float velX;
	float velY;
	float velMaxX;
	float velMaxY;
	int ID;
	bool fisica;
	gerenciaAnim gerListaAnim;
	
	ListaAnimacao* listaAnim;

public:
	Entidade();
	Entidade(const int aVelX, const int aVelY, const int aVelMaxX,
		const int aVelMaxY, const int aID, const bool aFisica,
		const float aPosX = 0, const float aPosY = 0, const int aLimX = 0,
		const int aLimY = 0, const bool aAtivo = 0);
	virtual ~Entidade();
	void setFisica(const bool aFisica);
	const bool getFisica();
	const float getVelMaxX();
	void setVelMaxX(const float aVelMaxX);
	const float getVelMaxY();
	void setVelMaxY(const float aVelMaxY);

	const int getID();
	void setVelX(const float aVelX);
	const int getVelX();
	void setVelY(const float aVelY);
	const int getVelY();
	virtual void atualizar() = 0;
	void setID(const int aID);
	void resumeTimerAnim();
	void stopTimerAnim();
};

