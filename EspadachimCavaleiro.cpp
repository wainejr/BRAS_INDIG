#include "EspadachimCavaleiro.h"



EspadachimCavaleiro::EspadachimCavaleiro()
{
	posX = 0;
	posY = 0;
	limX = LIM_X_CAV;
	limY = LIM_Y_CAV;
	velX = 0;
	velY = 0;
	fisica = true;
	ativo = false;
	velMaxX = VEL_MAX_X_CAV;
	velMaxY = VEL_PULO;
	ID = ESP_CAVALEIRO;

	vida = VIDA_MAX_CAV;
	arma = nullptr;
	dir = true;
	podeAtacar = false;
	atacando = false;
	invuneravel = false;
	timer_ataque = nullptr;
	timer_atacando = nullptr;
	timer_invuneravel = nullptr;
	criouTimers = false;

	alvo = nullptr;
}


EspadachimCavaleiro::~EspadachimCavaleiro()
{
	delete(listaAnim);

	delete (arma);
	al_destroy_timer(timer_ataque);
	al_destroy_timer(timer_atacando);
	al_destroy_timer(timer_invuneravel);

	alvo = nullptr;
}


void EspadachimCavaleiro::builderEspadachimCav(const int ax, const int ay, const bool aAtivo, Jogador* const pAlvo)
{
	posX = ax;
	posY = ay;
	velX = 0;
	velY = 0;
	ativo = aAtivo;

	vida = VIDA_MAX_MOSQ;
	podeAtacar = false;
	atacando = false;
	invuneravel = false;
	if (arma == nullptr)
	{
		Arma* pArma = constroiArma();
		if (pArma != nullptr)
			arma = pArma;
	}
	if (!criouTimers)
	{
		createTimers();
	}

	if (pAlvo != nullptr)
	{
		alvo = pAlvo;
	}
}

//	o cavaleiro passa do alvo, só começando a parar um tempo depois
void EspadachimCavaleiro::mover()
{
	//	o cavaleiro tem que estar no máximo há DIFF_PIXELS_SEGUIR_Y de distância
	//	do alvo para começar a segui-lo
	if (alvo != nullptr)
	{
		if ((posY - limY - alvo->getY()) <= DIFF_PIXELS_SEGUIR_Y || (posY - (alvo->getY() - alvo->getLimY())) <= -DIFF_PIXELS_SEGUIR_Y)
		{
			//	se o cavaleiro estiver parado, vai na direção do alvo
			if (velX == 0)
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
	else
		parar();
}


void EspadachimCavaleiro::atualizar()
{
	mover();
	posX += velX;
	posY -= velY;
	if (alvo != nullptr)
	{
		if (alvo->getX() > posX)
			dir = true;
		else
			dir = false;
	}
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
	timer_atacando = al_create_timer(1.0); // não será utilizado, o ataque é do cavaleiro é pelo contato
	timer_invuneravel = al_create_timer(TEMP_INVUN_CAV);
	criouTimers = true;
}


void EspadachimCavaleiro::atualizaAtaque() 
{
	podeAtacar = true;
}