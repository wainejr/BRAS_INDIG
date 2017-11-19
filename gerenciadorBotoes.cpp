#include "gerenciadorBotoes.h"



gerenciadorBotoes::gerenciadorBotoes()
{
}


gerenciadorBotoes::~gerenciadorBotoes()
{
}


void gerenciadorBotoes::addBotao(Botao* const pBotao)
{
	if (pBotao != nullptr)
		listaBotoes.addObj(pBotao);
}


void gerenciadorBotoes::retiraBotao(Botao* const pBotao)
{
	if (pBotao != nullptr)
	{
		listaBotoes.retirarObj(pBotao);
	}
}


void gerenciadorBotoes::checaSelec(const int mouseX, const int mouseY)
{
	Botao* pBotao;
	for (int i = 0; i < listaBotoes.numObjs(); i++)
	{
		pBotao = listaBotoes.objI(i);
		if (pBotao->getAtivo() && mouseEstaNoBotao(pBotao, mouseX, mouseY))
		{
			pBotao->botaoSelec(true);
		}
		else
			pBotao->botaoSelec(false);
	}
}


void gerenciadorBotoes::desenhaBotoes()
{
	Botao* pBotao;
	for (int i = 0; i < listaBotoes.numObjs(); i++)
	{
		pBotao = listaBotoes.objI(i);
		if (pBotao->getAtivo())
			pBotao->draw();
	}
}


const bool gerenciadorBotoes::mouseEstaNoBotao(Botao* const pBotao, const int mouseX, const int mouseY)
{
	if (mouseX <= (pBotao->getX() + pBotao->getLarg()) && mouseX >= pBotao->getX()
		&& mouseY >= pBotao->getY() && mouseY <= pBotao->getY() + pBotao->getAlt())
		return true;
	return false;
}


void gerenciadorBotoes::desativaBotoes()
{
	Botao* pBotao;
	for (int i = 0; i < listaBotoes.numObjs(); i++)
	{
		pBotao = listaBotoes.objI(i);
		pBotao->setAtivo(false);
	}
}


void gerenciadorBotoes::resetaSelecBotoes()
{
	Botao* pBotao;
	for (int i = 0; i < listaBotoes.numObjs(); i++)
	{
		pBotao = listaBotoes.objI(i);
		pBotao->botaoSelec(false);
	}
}
