#pragma once
class ProtoEntidade
{
protected:
	//	float foi optado na posi��o para ser poss�vel adicionar
	//	fra��es com rela��o a movimenta��o, tanto em X quanto em Y
	//					---------------
	//	Para entidades, posi��o x e y correspondem a posi��o do canto esquerdo
	//	inferior do objeto. A posi��o x+limX e y-limY correspondem
	//	ao canto direito superior do objeto

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

