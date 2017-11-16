#pragma once
#include "ListaAnimacao.h"

class gerenciaAnim
{
private:
	//	TODAS ANIMAÇÕES DO JOGO 
	//	DEIXAR TODAS ANIMAÇÕES ESTÁTICAS
	
	//	ANIMACOES RAONI
	static bool carregouRaoni;

	//	ANIMACOES TECA
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
	static bool carregouProj;

	//	ANIMACOES PLATAFORMA
	static Animacao* plataforma;
	static bool carregouPlat;

	//	ANIMACOES CORDA
	static bool carregouCorda;

	//	ANIMACOES ARMADILHA
	static bool carregouArmadilha;

	//	ANIMACOES ESPINHO
	static bool carregouEspinho;

	//	ANIMACOES REDE
	static bool carregouRede;

public:
	gerenciaAnim();
	~gerenciaAnim();
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

	ListaAnimacao* const listaAnimEnt(const int aID);
};

