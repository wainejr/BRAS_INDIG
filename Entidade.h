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

#define ACEL_X_PERS 0.4
#define ACEL_REDE 0.6
#define ACEL_X_CAV 0.12
#define VEL_MAX_X_PERS 3
#define VEL_MAX_X_JOG 5
#define VEL_MAX_X_CAV 5
#define VEL_MAX_PROJ 7
#define VEL_MAX_REDE 3
#define VEL_SUBIDA 1
#define VEL_X_KB 4.5
#define VEL_Y_KB 1.6


//	Período de tempo entre ataques de cada Personagem 
//	(contando o tempo que o pers fica em estado ataque)
#define PER_ATAQ_MOSQ 2.5
#define PER_ATAQ_ESP 2.0
#define PER_ATAQ_JOG 0.5

//Tempo que o jogador "fica" atacando, ou seja, que a arma fica esticada
#define TEMP_ATAQ_JOG 0.2
#define TEMP_ATAQ_ESP 0.3
#define TEMP_ATAQ_MOSQ 0.1

#define TEMP_INVUN_JOG 2.0
#define TEMP_INVUN_MOSQ 0.5
#define TEMP_INVUN_ESP 0.5
#define TEMP_INVUN_CAV 1.0
#define TEMP_ACION_ARMD 1.5

#define TEMP_IMOVEL 1.5

#define VIDA_MAX_JOG 100
#define DIFF_PIXELS_PARAR_X 10
#define DIFF_PIXELS_SEGUIR_Y 40
#define DIFF_PIXELS_CAV_PARAR 60

#define DANO_MOSQUETE 15
#define DANO_ESPADA_ESP 20
#define DANO_ESPADA_JOG	25
#define DANO_LANCA 30
#define DANO_ARCO 20

#define LIM_X_JOG 10
#define LIM_Y_JOG 20
#define LIM_X_ESP 10
#define LIM_Y_ESP 20
#define LIM_X_MOSQ 10
#define LIM_Y_MOSQ 20
#define LIM_X_CAV 50
#define LIM_Y_CAV 25

#define LIM_X_ESPADA_ESP 15
#define LIM_Y_ESPADA_ESP 5
#define LIM_X_ESPADA_JOG 20
#define LIM_Y_ESPADA_JOG 5

#define LIM_X_PROJ_MOSQ 4
#define LIM_Y_PROJ_MOSQ 4
#define LIM_X_PROJ_ARCO 16
#define LIM_Y_PROJ_ARCO 4


using namespace std;

enum IDS{JOGADOR1, JOGADOR2, MOSQUETEIRO, ESPADACHIM, ESP_CAVALEIRO, CHEFAO_CAP, 
	ESPADA, LANCA, MOSQUETE, ARCO, PROJETIL_INI, PROJETIL_JOG, PLATAFORMA, CORDA, 
	ARMADILHA, ESPINHO, REDE, CORDA_REDE};
enum PERS{RAONI, TECA};

class Entidade
{
protected:
	//	float foi optado na posição para ser possível adicionar
	//	frações com relação a movimentação, tanto em X quanto em Y
	//					---------------
	//	A posição x e y correspondem a posição do canto esquerdo
	//	inferior do objeto. A posição x+limX e y+limY correspondem
	//	ao canto direito superior do objeto
	//					---------------
	//	A velocidade em y positiva corresponde ao personagem subir
	//	na tela, negativa, descer.

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

