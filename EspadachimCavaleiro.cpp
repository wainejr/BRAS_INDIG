#include "EspadachimCavaleiro.h"



EspadachimCavaleiro::EspadachimCavaleiro()
{
	ID = ESP_CAVALEIRO;
	fisica = true;
}


EspadachimCavaleiro::~EspadachimCavaleiro()
{
}


void EspadachimCavaleiro::builderEspadachimCav(const int ax, const int ay, const int aLimX, const int aLimy, const bool aAtivo, const int aVida, Arma* const pArma)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimy;
	ativo = aAtivo;
	vida = aVida;
	this->setArma(constroiArma());
}

//	o cavaleiro passa do alvo, só começando a parar um tempo depois
void EspadachimCavaleiro::mover()
{
	//	o cavaleiro tem que estar no máximo há DIFF_PIXELS_SEGUIR_Y de distância
	//	do alvo para começar a segui-lo
	if ((posY-limY-alvo->getY()) <= DIFF_PIXELS_SEGUIR_Y || (posY - (alvo->getY()-alvo->getLimY())) <= -DIFF_PIXELS_SEGUIR_Y)
	{
		//	se o cavaleiro estiver parado, vai na direção do alvo
		if(velX == 0)
		{ 
			if (alvo->getX() >= posX)
				velX += ACEL_X_CAV;
			else
				velX -= ACEL_X_CAV;
		}
		else 
		{
			//	se o cavaleiro estiver a menos de DIFF_PIXELS_CAV_PARAR a esquerda do alvo e
			//	estiver com velocidade em x negativa, ele continua acelerando para esquerda
			if ((alvo->getX() - posX - limX) < DIFF_PIXELS_CAV_PARAR && velX < 0 && velX > -VEL_MAX_X_CAV)
				velX -= (float)ACEL_X_CAV;
			else if (velX < -VEL_MAX_X_CAV)
				velX = -VEL_MAX_X_CAV;
			//	se o cavaleiro estiver a menos de DIFF_PIXELS_CAV_PARAR a direita do alvo e
			//	estiver com velocidade em x positiva, ele continua acelerando para direita
			else if ((posX - alvo->getLimX() - alvo->getX()) < DIFF_PIXELS_CAV_PARAR && velX > 0 && velX < VEL_MAX_X_CAV)
				velX += (float)ACEL_X_CAV;
			else if (velX > VEL_MAX_X_CAV)
				velX = VEL_MAX_X_CAV;
			//	se o cavaleiro já passou do limite de distância do alvo, começa a parar
			else
				parar();
		}
	}
	else
		parar();
}


void EspadachimCavaleiro::atacar()
{

}


void EspadachimCavaleiro::atualizar()
{
	mover();
	posX += velX;
	posY -= velY;
	if (alvo->getX() > posX)
		dir = true;
	else
		dir = false;
	atualizaInvuneravel();
	atualizaAtacando();
	atualizaArma();
}



const bool EspadachimCavaleiro::getCavalo()
{
	return cavalo;
}


void EspadachimCavaleiro::setCavalo(const bool aCavalo)
{
	cavalo = aCavalo;
}


void EspadachimCavaleiro::draw(const int aPosFaseX, const int aPosFaseY)
{
	if(!invuneravel)
		al_draw_filled_rectangle(posX - aPosFaseX, posY - aPosFaseY, posX + limX - aPosFaseX, posY - limY - aPosFaseY, al_map_rgb(155, 100, 55));
	else
		al_draw_rectangle(posX - aPosFaseX, posY - aPosFaseY, posX + limX - aPosFaseX, posY - limY - aPosFaseY, al_map_rgb(155, 100, 55), 2);
}


void EspadachimCavaleiro::createTimers()
{
	timer_ataque = al_create_timer(PER_ATAQ_ESP);
	timer_atacando = al_create_timer(1.0); // não será utilizado
	timer_invuneravel = al_create_timer(TEMP_INVUN_CAV);
}