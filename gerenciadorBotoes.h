#pragma once
#include "Botao.h"
#include "Lista.h"
class gerenciadorBotoes
{
private:
	Lista<Botao*> listaBotoes;

public:
	gerenciadorBotoes();
	~gerenciadorBotoes();
	void addBotao(Botao* const pBotao);
	void retiraBotao(Botao* const pBotao);
	void checaSelec(const int mouseX, const int mouseY);
	void desenhaBotoes();
	const bool mouseEstaNoBotao(Botao* const pBotao, const int mouseX, const int mouseY);
	void desativaBotoes();
};

