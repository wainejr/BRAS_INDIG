#pragma once
#include <string>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
using namespace std;

enum IDS{JOGADOR1, JOGADOR2, MOSQUETEIRO, ESPADACHIM, ESP_CAVALEIRO, CHEFAO_CAP, 
	ESPADA, LANCA, MOSQUETE, ARCO, PROJETIL, PLATAFORMA, CORDA, ARMADILHA, ESPINHO, 
	REDE, CORDA_REDE};

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
	string nome;
	bool fisica;
	bool ativo;
	float velMaxX;
	float velMaxY;
private:
	int ID;
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
	virtual void draw() = 0;
	virtual void atualizar();
};

