#pragma once
#include "Menu.h"
class MenuPrincipal :
	public Menu
{
private:
	Botao botao_sair;
	Botao botao_controles; //	A FAZER E IMPLEMENTAR UM NOVO ESTADO NO JOGO
	Botao botao_novoJogo;
	Botao botao_campanha;
	Botao botao_fase1;
	Botao botao_fase2;
	Botao botao_fase3;
	Botao botao_tecaRaoni;
	Botao botao_raoniTeca;
	Botao botao_teca;
	Botao botao_raoni;
	Botao botao_voltar;
public:
	MenuPrincipal();
	~MenuPrincipal();
};

