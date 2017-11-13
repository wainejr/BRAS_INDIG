#include "ListaFases.h"



ListaFases::ListaFases()
{
	raoni = new Jogador;
	teca = new Jogador;

	raoni->builderJogador(0, 0, false, RAONI);
	teca->builderJogador(0, 0, false, TECA);
}


ListaFases::~ListaFases()
{
}


void ListaFases::carregaFaseN(const int aN)
{
	//	carrega a fase predeterminada
	switch (aN)
	{
	case 1:
		fase1.setCampanha(false);
		fase1.initFase();
		break;
	case 2:
		fase2.setCampanha(false);
		fase2.initFase();
		break;
	case 3:
		faseFinal.setCampanha(false);
		faseFinal.initFase();
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


	// créditos
}


//	MUDAR O STRING PARA ALGUM ID OU COISA ASSIM
void ListaFases::defineJog(const int aID, const int aNum)
{
	if (fase1.getNumJogs() == 1)
	{
		if (aNum == 1)
		{
			if (aID == TECA)
			{
				fase1.setJog1(teca);
				
			}
			else if (aID == RAONI)
			{
				fase1.setJog1(teca);
			}
		}
	}
	else if (fase1.getNumJogs() == 2)
	{
		if (aNum == 1)
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
		else if (aNum == 2)
		{
			if (aID == TECA)
			{
				fase1.setJog2(teca);
			}
			else if (aID == RAONI)
			{
				fase1.setJog2(teca);
			}
		}
	}
}