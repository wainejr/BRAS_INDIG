#pragma once

#include <string>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

//	O TAMANHO DOS INIMGOS/JOGADORES E A VELOCIDADE DAS BALAS DEVEM SER
//	DIMENSIONADOS PARA QUE OS PROJETEIS NAO PASSEM DELES

//	MUDAR OS BUILDERS AO FINAL DO PROJETO PARA MAIOR FACILIDADE DE DESENVOLVIMENTO

#define VEL_PULO 5

#define ACEL_X_PERS 0.5

#define ACEL_X_CAV 0.2
#define VEL_MAX_X_PERS 3
#define VEL_MAX_X_JOG 5
#define VEL_MAX_X_CAV 7
#define VEL_MAX_PROJ 7
#define VEL_SUBIDA 3

//Período de tempo entre ataques de cada Personagem
#define PER_ATAQ_MOSQ 1.2
#define PER_ATAQ_ESP 0.8
#define PER_ATAQ_JOG 0.5


//FAZER UM TIMER PARA QUANTO TEMPO O PERSONAGEM FICA NO ESTADO ATAQUE

#define TEMP_INVUN 2
#define VIDA_MAX_JOG 100
#define DIFF_PIXELS_PARAR_X 10
#define DIFF_PIXELS_SEGUIR_Y 40
#define DIFF_PIXELS_CAV_PARAR 60

using namespace std;

enum IDS{JOGADOR1, JOGADOR2, MOSQUETEIRO, ESPADACHIM, ESP_CAVALEIRO, CHEFAO_CAP, 
	ESPADA, LANCA, MOSQUETE, ARCO, PROJETIL_INI, PROJETIL_JOG, PLATAFORMA, CORDA, 
	ARMADILHA, ESPINHO, REDE, CORDA_REDE};

class Entidade
{
protected:
	//	float foi optado na posição para ser possível adicionar
	//	frações com relação a movimentação, tanto em X quanto em Y
	//					---------------
	//	A posição x e y correspondem a posição do canto esquerdo
	//	inferior do objeto. A posição x+limX e y+limY correspondem
	//	ao canto direito superior do objeto

	float posX;
	float posY;
	int limX;
	int limY;
	float velX;
	float velY;
	bool fisica;
	bool ativo;
	float velMaxX;
	float velMaxY;
	int ID;
private:
	//sprite
public:
	Entidade();
	virtual ~Entidade();
	void setX(const float px);
	const float getX();
	void setY(const float py);
	const float getY();
	void setLimX(const int aLimX);
	const int getLimX();
	void setLimY(const int aLimY);
	const int getLimY();
	void setAtivo(const bool aAtivo);
	const bool getAtivo();
	void setFisica(const bool aFisica);
	const bool getFisica();
	const float getVelMaxX();
	void setVelMaxX(const float aVelMaxX);
	const float getVelMaxY();
	void setVelMaxY(const float aVelMaxY);

	const int getID();
	virtual void draw(const int aPosFaseX, const int aPosFaseY) = 0;
	void setVelX(const float aVelX);
	const int getVelX();
	void setVelY(const float aVelY);
	const int getVelY();
	virtual void atualizar() = 0;
	void setID(const int aID);
};

