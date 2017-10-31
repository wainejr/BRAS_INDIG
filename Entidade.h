#pragma once
#include <string>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
using namespace std;

enum IDS{/*a fazer, com ordem e afins*/};

class Entidade
{
protected:
	int posX;
	int posY;
	int limX;
	int limY;
	float velX;
	float velY;
	string nome;
	bool fisica;
	bool ativo;

private:
	int ID;
	//sprite
public:
	Entidade();
	virtual ~Entidade();
	void setX(const int px);
	const int getX();
	void setY(const int py);
	const int getY();
	void setLimX(const int aLimX);
	const int getLimX();
	void setLimY(const int aLimY);
	const int getLimY();
	void setAtivo(const bool aAtivo);
	const bool getAtivo();
	void setFisica(const bool aFisica);
	const bool getFisica();

	const int getID();
	virtual void draw() = 0;
};

