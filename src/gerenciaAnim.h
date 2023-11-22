#pragma once
#include "ListaAnimacao.h"

class gerenciaAnim
{
private:
	//	TODAS ANIMAÇÕES DO JOGO
	
	//	ANIMACOES RAONI
	static Animacao* raoni_anda;
	static Animacao* raoni_parado;
	static Animacao* raoni_atacando;
	static Animacao* raoni_subindo;
	static Animacao* raoni_corda;
	static bool carregouRaoni;

	//	ANIMACOES TECA
	static Animacao* teca_anda;
	static Animacao* teca_parada;
	static Animacao* teca_atacando;
	static Animacao* teca_subindo;
	static Animacao* teca_corda;
	static bool carregouTeca;

	//	ANIMACOES MOSQUETEIRO
	static bool carregouMosq;

	//	ANIMACOES ESPADACHIM
	static bool carregouEsp;

	//	ANIMACOES CAVALEIRO
	static bool carregouCav;

	//	ANIMACOES CHEFAO CAPITAO
	static bool carregouChefaoCap;

	//	ANIMACOES PROJETIL
	static Animacao* flecha;
	static Animacao* tiro;
	static bool carregouProj;

	//	ANIMACOES PLATAFORMA
	static Animacao* plataforma_grama;
	static Animacao* plataforma_chao;
	static Animacao* plataforma_cima;
	static bool carregouPlat;

	//	ANIMACOES CORDA
	static Animacao* corda_esc;
	static Animacao* corda_nEsc;
	static bool carregouCorda;

	//	ANIMACOES ARMADILHA
	static Animacao* armd_desativada;
	static Animacao* armd_ativada;
	static bool carregouArmadilha;

	//	ANIMACOES ESPINHO
	static Animacao* espinho;
	static bool carregouEspinho;

	//	ANIMACOES REDE
	static Animacao* rede_caindo;
	static Animacao* rede_parada;
	static bool carregouRede;

	void carregaAnimRaoni();
	void carregaAnimTeca();
	void carregaAnimMosq();
	void carregaAnimEsp();
	void carregaAnimCav();
	void carregaAnimChefaoCap();
	void carregaAnimProj();
	void carregaAnimPlat();
	void carregaAnimCorda();
	void carregaAnimArmadilha();
	void carregaAnimEspinho();
	void carregaAnimRede();

	ListaAnimacao* const listaAnimRaoni();
	ListaAnimacao* const listaAnimTeca();
	ListaAnimacao* const listaAnimMosq();
	ListaAnimacao* const listaAnimEsp();
	ListaAnimacao* const listaAnimCav();
	ListaAnimacao* const listaAnimChefaoCap();
	ListaAnimacao* const listaAnimProj();
	ListaAnimacao* const listaAnimPlat();
	ListaAnimacao* const listaAnimCorda();
	ListaAnimacao* const listaAnimArmadilha();
	ListaAnimacao* const listaAnimEspinho();
	ListaAnimacao* const listaAnimRede();

public:
	gerenciaAnim();
	~gerenciaAnim();
	
	ListaAnimacao* const listaAnimEnt(const int aID);
};

