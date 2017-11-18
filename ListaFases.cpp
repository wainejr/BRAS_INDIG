#include "ListaFases.h"



ListaFases::ListaFases()
{
	raoni = new Jogador;
	teca = new Jogador;

	raoni->builderJogador(0, 0, true, RAONI, 3);
	teca->builderJogador(0, 0, true, TECA, 3);
}


ListaFases::~ListaFases()
{
	delete (raoni);
	delete (teca);
}


void ListaFases::carregaFaseN(const int aN)
{
	//	carrega a fase predeterminada
	switch (aN)
	{
	case 1:
		fase1.setCampanha(false);
		fase1.initFase();
		resetaJogs();
		break;
	case 2:
		fase2.setCampanha(false);
		fase2.initFase();
		resetaJogs();
		break;
	case 3:
		faseFinal.setCampanha(false);
		faseFinal.initFase();
		resetaJogs();
		break;
	default:
		break;
	}
}


bool ListaFases::defineNumJogadores(const int aNumJogs)
{
	if (aNumJogs == 2 || aNumJogs == 1)
	{
		fase1.setNumJogs(aNumJogs);
		return true;
	}
	else
		return false;
}


void ListaFases::campanha()
{
	fase1.setCampanha(true);
	// cutscene e tals

	fase1.initFase();
	//	condição para ter passado de fase...
	//	se passou, mostra pontos, cutscene ou coisa assim e então inicia outra fase
	
	fase2.initFase();
	//	condição para ter passado de fase...
	//	se passou, mostra pontos, cutscene ou coisa assim e então inicia outra fase

	faseFinal.initFase();
	//	condição para ter passado de fase...
	//	se passou, mostra pontos, cutscene ou coisa assim e então inicia outra fase

	resetaJogs();
	// créditos
}


void ListaFases::defineJog(const int aID, const int aNum)
{
	if (fase1.getNumJogs() >= 1 && aNum == 1)
	{
		if (aID == TECA)
		{
			fase1.setJog1(teca);	
		}
		else if (aID == RAONI)
		{
			fase1.setJog1(raoni);
		}
		
	}
	if (fase1.getNumJogs() == 2 && aNum == 2)
	{
		if (aID == TECA)
		{
			fase1.setJog2(teca);
		}
		else if (aID == RAONI)
		{
			fase1.setJog2(raoni);
		}
	}
}

void ListaFases::resetaJogs()
{
	teca->builderJogador(0, 0, false, TECA, 3);
	raoni->builderJogador(0, 0, false, RAONI, 3);
}


void ListaFases::setDisplays(ALLEGRO_DISPLAY* const pDisplay)
{
	fase1.setDisplay(pDisplay);
	fase2.setDisplay(pDisplay);
	faseFinal.setDisplay(pDisplay);
}
