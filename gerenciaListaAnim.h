#pragma once
#include "ListaAnimacao.h"
#include "gerenciaAnim.h"

class gerenciaListaAnim
{
private:
	gerenciaAnim gerAnim;

	static ListaAnimacao* raoni;
	static bool carregouRaoni;

	static ListaAnimacao* teca;
	static bool carregouTeca;
	
	static ListaAnimacao* mosqueteiro;
	static bool carregouMosq;
	
	static ListaAnimacao* espadachim;
	static bool carregouEsp;
	
	static ListaAnimacao* cavaleiro;
	static bool carregouCav;
	
	static ListaAnimacao* chefaoCap;
	static bool carregouChefaoCap;
	
	static ListaAnimacao* projetil;
	static bool carregouProj;
	
	static ListaAnimacao* plataforma;
	static bool carregouPlat;
	
	static ListaAnimacao* corda;
	static bool carregouCorda;
	
	static ListaAnimacao* armadilha;
	static bool carregouArmadilha;
	
	static ListaAnimacao* espinho;
	static bool carregouEspinho;
	
	static ListaAnimacao* rede;
	static bool carregouRede;

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

	void carregaListaAnimRaoni();
	void carregaListaAnimTeca();
	void carregaListaAnimMosq();
	void carregaListaAnimEsp();
	void carregaListaAnimCav();
	void carregaListaAnimChefaoCap();
	void carregaListaAnimProj();
	void carregaListaAnimPlat();
	void carregaListaAnimCorda();
	void carregaListaAnimArmadilha();
	void carregaListaAnimEspinho();
	void carregaListaAnimRede();


	/*
		RAONI, TECA, MOSQUETEIRO, ESPADACHIM, ESP_CAVALEIRO, CHEFAO_CAP, 
	ESPADA, LANCA, MOSQUETE, ARCO, PROJETIL_MOSQ, PROJETIL_ARCO, PLATAFORMA, CORDA, 
	ARMADILHA, ESPINHO, REDE, CORDA_REDE
	*/
public:
	gerenciaListaAnim();
	~gerenciaListaAnim();
	ListaAnimacao* const listaAnimEnt(const int aID);
};

