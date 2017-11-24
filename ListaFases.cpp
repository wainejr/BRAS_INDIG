#include "ListaFases.h"


ListaFases::ListaFases()
{
	topo = nullptr;
	gerPont = nullptr;
}


ListaFases::~ListaFases()
{
	if (topo != nullptr)
	{
		FaseAnin* pAux1 = topo;
		FaseAnin* pAux2;
		if (pAux1->isThereProx())
		{
			pAux2 = pAux1->getProx();
			delete(pAux1);
			pAux1 = pAux2;
		}
		delete(pAux1);
	}
}


ListaFases::FaseAnin::FaseAnin()
{
	proxFase = nullptr;
	curr = nullptr;
	antFase = nullptr;
}


ListaFases::FaseAnin::~FaseAnin()
{
	proxFase = nullptr;
	curr = nullptr;
	antFase = nullptr;
}


void ListaFases::FaseAnin::setProx(FaseAnin* const pAninFase)
{
	if (pAninFase != nullptr)
		proxFase = pAninFase;
}


void ListaFases::FaseAnin::setAnt(FaseAnin* const pAninFase)
{
	if (pAninFase != nullptr)
		antFase = pAninFase;
}


void ListaFases::FaseAnin::setCurr(Fase* const pFase)
{
	if (pFase != nullptr)
		curr = pFase;
}


ListaFases::FaseAnin* const ListaFases::FaseAnin::getProx()
{
	return proxFase;
}


ListaFases::FaseAnin* const ListaFases::FaseAnin::getAnt()
{
	return antFase;
}


Fase* const ListaFases::FaseAnin::getFase()
{
	return curr;
}

const bool ListaFases::FaseAnin::isThereProx()
{
	if (proxFase != nullptr)
		return true;
	return false;
}

void ListaFases::carregaFaseN(const int aN)
{
	//	carrega a fase predeterminada
	FaseAnin* pAux = topo;
	int i = 1;
	while (i < aN)
	{
		i++;
		if (!pAux->isThereProx())
			return;
		pAux = pAux->getProx();
	}
	Fase* pFase = pAux->getFase();
	pFase->setCampanha(false);
	pFase->initFase();
	if (pFase->getFaseCompleta())
	{
		float pont = pFase->getPontuacao();
		gerPont->salvarPont(pont, aN);
	}
}


bool ListaFases::defineNumJogadores(const int aNumJogs)
{
	if (aNumJogs == 1 || aNumJogs == 2 && topo != nullptr)
	{
		Fase* pFase = topo->getFase();
		// o numero de jogadores da fase é estático, logo só precisa ser acionado para uma fase a função
		pFase->setNumJogs(aNumJogs);
		return true;
	}
	return false;
}


void ListaFases::campanha()
{
	if (topo)
	{
		bool continuar = true;
		FaseAnin* pAux = topo;
		float pont = 0;
		while (continuar)
		{
			Fase* pFase;
			pFase = pAux->getFase();
			pFase->setCampanha(true);
			pFase->initFase();
			pont += pFase->getPontuacao();
			if (!pFase->getFaseCompleta())
			{
				continuar = false;
			}
			else if (!pAux->isThereProx())
			{
				continuar = false;
				gerPont->salvarPont(pont, 0);
			}
			else
				pAux = pAux->getProx();
		}
		//	anula os jogadores das fases visto que a campanha acabou
		topo->getFase()->anulaJogs();
	}
}


void ListaFases::defineJog(Jogador* const pJog, const int aNum)
{
	if (pJog != nullptr && topo != nullptr)
	{
		Fase* pFase = topo->getFase();
		// o jogador da fase é estático, logo só precisa ser acionado para uma fase a função
		if (pFase->getNumJogs() >= 1 && aNum == 1)
		{
			pFase->setJog1(pJog);
		}
		else if (pFase->getNumJogs() == 2 && aNum == 2)
		{
			pFase->setJog2(pJog);
		}
	}
}


void ListaFases::setDisplays(ALLEGRO_DISPLAY* const pDisplay)
{
	if (topo != nullptr && pDisplay != nullptr)
	{
		FaseAnin* pAux = topo;
		pAux->getFase()->setDisplay(pDisplay);
		while(pAux->isThereProx())
		{
			pAux = pAux->getProx();
			pAux->getFase()->setDisplay(pDisplay);
		} 
	}
}

//	adiciona uma fase ao final da lista de fases
void ListaFases::addFaseIni(Fase* const pFase)
{
	if (pFase != nullptr)
	{
		FaseAnin* pAninFase = new FaseAnin;
		pAninFase->setCurr(pFase);
		if (topo == nullptr)
		{
			topo = pAninFase;
			ultimo = pAninFase;
		}
		else
		{
			ultimo->setProx(pAninFase);
			pAninFase->setAnt(ultimo);
			ultimo = pAninFase;
		}
	}
}


void ListaFases::anulaJogs()
{
	Fase::anulaJogs();
}

void ListaFases::setGerPont(gerenciaPontuacoes* const pGer)
{
	if(pGer != nullptr)
		gerPont = pGer;
}
