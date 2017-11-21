#include "ListaFases.h"



ListaFases::ListaFases()
{
	
}


ListaFases::~ListaFases()
{
	
}


void ListaFases::carregaFaseN(const int aN)
{
	//	carrega a fase predeterminada
	for (it = fases.begin(); it != fases.end(); it++)
	{
		if ((*it)->getNumFase() == aN)
		{
			(*it)->setCampanha(false);
			(*it)->initFase();
			break;
		}
	}
}


bool ListaFases::defineNumJogadores(const int aNumJogs)
{
	if (aNumJogs == 2 || aNumJogs == 1)
	{
		for (it = fases.begin(); it != fases.end(); it++)
		{
			(*it)->setNumJogs(aNumJogs);
		}
		return true;
	}
	else
		return false;
}


void ListaFases::campanha()
{
	for(unsigned int i = 1; i <= fases.size(); i++)
	{ 
		carregaFaseN(i);
		//	condição para ter passado de fase...
		//	se passou, mostra pontos, cutscene ou coisa assim e então inicia outra fase
	}

	//	condição para ter passado de fase...
	//	se passou, mostra pontos, cutscene ou coisa assim e então inicia outra fase
	
	// créditos
}


void ListaFases::defineJog(Jogador* const pJog, const int aNum)
{
	if (pJog != nullptr)
	{
		for (it = fases.begin(); it != fases.end(); it++)
		{
			if ((*it)->getNumJogs() >= 1 && aNum >= 1)
			{
				(*it)->setJog1(pJog);
			}
			if ((*it)->getNumJogs() == 2 && aNum == 2)
			{
				(*it)->setJog2(pJog);
			}
		}
	}
}


void ListaFases::setDisplays(ALLEGRO_DISPLAY* const pDisplay)
{
	for (it = fases.begin(); it != fases.end(); it++)
	{
		(*it)->setDisplay(pDisplay);
	}
}


void ListaFases::addFase(Fase* const pFase)
{
	fases.push_back(pFase);
}


void ListaFases::anulaJogs()
{
	Fase::anulaJogs();
}
