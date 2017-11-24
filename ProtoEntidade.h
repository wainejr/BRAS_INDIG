#pragma once
class ProtoEntidade
{
protected:
	float posX;
	float posY;
	int limX;
	int limY;
	bool ativo;

public:
	ProtoEntidade();
	ProtoEntidade(const float aPosX, const float aPosY, const int aLimX, const int aLimY, const bool aAtivo);
	virtual ~ProtoEntidade();
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
	virtual void draw(const int aPosFaseX, const int aPosFaseY) = 0;
};

