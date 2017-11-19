#include "ChefaoCapitao.h"



ChefaoCapitao::ChefaoCapitao()
{
	ID = CHEFAO_CAP;
	fisica = true;

	vida = 0;
	arma = nullptr;
	dir = true;
	podeAtacar = false;
	atacando = false;
	invuneravel = false;
	timer_ataque = nullptr;
	timer_atacando = nullptr;
	timer_invuneravel = nullptr;

	listaAnim = nullptr;
}


ChefaoCapitao::~ChefaoCapitao()
{
	delete(listaAnim);

	delete (arma);
	al_destroy_timer(timer_ataque);
	al_destroy_timer(timer_atacando);
	al_destroy_timer(timer_invuneravel);

	alvo = nullptr;
}


void ChefaoCapitao::builderChefaoCapitao()
{
}


void ChefaoCapitao::mover()
{
}


void ChefaoCapitao::atacar()
{
}


void ChefaoCapitao::atualizar()
{
	//a fazer
}


void ChefaoCapitao::addCapanga1(Inimigo* pInimigo)
{
	capangas1.addObj(pInimigo);
}


void ChefaoCapitao::addCapangas2(Inimigo* pInimigo)
{
	capangas2.addObj(pInimigo);
}


void ChefaoCapitao::mandaCapangas1()
{
}


void ChefaoCapitao::mandaCapangas2()
{
}

void ChefaoCapitao::createTimers()
{

}


