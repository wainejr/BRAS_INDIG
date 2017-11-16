#include "gerenciaListaAnim.h"
#include "Entidade.h" //	para saber o ID

//	VER SE VAI USAR O NEW DE COMEÇO JÁ OU SÓ QUANDO FOR CHAMADO PRA CARREGAR

bool gerenciaListaAnim::carregouRaoni = false;
ListaAnimacao* gerenciaListaAnim::raoni = NULL;


bool gerenciaListaAnim::carregouTeca = false;
ListaAnimacao* gerenciaListaAnim::teca = NULL;


bool gerenciaListaAnim::carregouMosq = false;
ListaAnimacao* gerenciaListaAnim::mosqueteiro = NULL;


bool gerenciaListaAnim::carregouEsp = false;
ListaAnimacao* gerenciaListaAnim::espadachim = NULL;


bool gerenciaListaAnim::carregouCav = false;
ListaAnimacao* gerenciaListaAnim::cavaleiro = NULL;


bool gerenciaListaAnim::carregouChefaoCap = false;
ListaAnimacao* gerenciaListaAnim::chefaoCap = NULL;


bool gerenciaListaAnim::carregouProj = false;
ListaAnimacao* gerenciaListaAnim::projetil = NULL;


bool gerenciaListaAnim::carregouPlat = false;
ListaAnimacao* gerenciaListaAnim::plataforma = NULL;


bool gerenciaListaAnim::carregouCorda = false;
ListaAnimacao* gerenciaListaAnim::corda = NULL;


bool gerenciaListaAnim::carregouArmadilha = false;
ListaAnimacao* gerenciaListaAnim::armadilha = NULL;

bool gerenciaListaAnim::carregouEspinho = false;
ListaAnimacao* gerenciaListaAnim::espinho = NULL;


bool gerenciaListaAnim::carregouRede = false;
ListaAnimacao* gerenciaListaAnim::rede = NULL;

gerenciaListaAnim::gerenciaListaAnim()
{
}


gerenciaListaAnim::~gerenciaListaAnim()
{
}


ListaAnimacao* const gerenciaListaAnim::listaAnimEnt(const int aID)
{
	switch (aID)
	{
	case RAONI:
		return listaAnimRaoni();
		break;
	case TECA:
		return listaAnimTeca();
		break;
	case MOSQUETEIRO:
		return listaAnimMosq();
		break;
	case ESPADACHIM:
		return listaAnimEsp();
		break;
	case ESP_CAVALEIRO:
		return listaAnimCav();
		break;
	case CHEFAO_CAP:
		return listaAnimChefaoCap();
		break;
	case PROJETIL_MOSQ:
		return listaAnimProj();
		break;
	case PROJETIL_ARCO:
		return listaAnimProj();
		break;
	case PLATAFORMA:
		return listaAnimPlat();
		break;
	case CORDA:
		return listaAnimCorda();
		break;
	case ARMADILHA:
		return listaAnimArmadilha();
		break;
	case ESPINHO:
		return listaAnimEsp();
		break;
	case REDE:
		return listaAnimRede();
		break;
	default:
		return NULL;
		break;
	}
}


ListaAnimacao* const gerenciaListaAnim::listaAnimRaoni()
{
	if (!carregouRaoni)
		carregaListaAnimRaoni();
	ListaAnimacao* pListaAnim;
	pListaAnim = raoni->copiaListaAnim();
	return pListaAnim;
}


ListaAnimacao* const gerenciaListaAnim::listaAnimTeca()
{
	if (!carregouTeca)
		carregaListaAnimTeca();
	ListaAnimacao* pListaAnim;
	pListaAnim = teca->copiaListaAnim();
	return pListaAnim;
}


ListaAnimacao* const gerenciaListaAnim::listaAnimMosq()
{
	if (!carregouRaoni)
		carregaListaAnimMosq();
	ListaAnimacao* pListaAnim;
	pListaAnim = mosqueteiro->copiaListaAnim();
	return pListaAnim;
}


ListaAnimacao* const gerenciaListaAnim::listaAnimEsp()
{
	if (!carregouEsp)
		carregaListaAnimEsp();
	ListaAnimacao* pListaAnim;
	pListaAnim = espadachim->copiaListaAnim();
	return pListaAnim;
}


ListaAnimacao* const gerenciaListaAnim::listaAnimCav()
{
	if (!carregouCav)
		carregaListaAnimCav();
	ListaAnimacao* pListaAnim;
	pListaAnim = cavaleiro->copiaListaAnim();
	return pListaAnim;
}


ListaAnimacao* const gerenciaListaAnim::listaAnimChefaoCap()
{
	if (!carregouChefaoCap)
		carregaListaAnimChefaoCap();
	ListaAnimacao* pListaAnim;
	pListaAnim = chefaoCap->copiaListaAnim();
	return pListaAnim;
}


ListaAnimacao* const gerenciaListaAnim::listaAnimProj()
{
	if (!carregouProj)
		carregaListaAnimProj();
	ListaAnimacao* pListaAnim;
	pListaAnim = projetil->copiaListaAnim();
	return pListaAnim;
}


ListaAnimacao* const gerenciaListaAnim::listaAnimPlat()
{
	if (!carregouPlat)
		carregaListaAnimPlat();
	ListaAnimacao* pListaAnim;
	pListaAnim = plataforma->copiaListaAnim();
	return pListaAnim;
}


ListaAnimacao* const gerenciaListaAnim::listaAnimCorda()
{
	if (!carregouCorda)
		carregaListaAnimCorda();
	ListaAnimacao* pListaAnim;
	pListaAnim = corda->copiaListaAnim();
	return pListaAnim;
}


ListaAnimacao* const gerenciaListaAnim::listaAnimArmadilha()
{
	if (!carregouArmadilha)
		carregaListaAnimArmadilha();
	ListaAnimacao* pListaAnim;
	pListaAnim = armadilha->copiaListaAnim();
	return pListaAnim;
}


ListaAnimacao* const gerenciaListaAnim::listaAnimEspinho() 
{
	if (!carregouEspinho)
		carregaListaAnimEspinho();
	ListaAnimacao* pListaAnim;
	pListaAnim = espinho->copiaListaAnim();
	return pListaAnim;
}


ListaAnimacao* const gerenciaListaAnim::listaAnimRede()
{
	if (!carregouRede)
		carregaListaAnimRede();
	ListaAnimacao* pListaAnim;
	pListaAnim = rede->copiaListaAnim();
	return pListaAnim;
}


void gerenciaListaAnim::carregaListaAnimRaoni()
{
	raoni = new ListaAnimacao;
	gerAnim.addAnimRaoni(raoni);
	carregouRaoni = true;
}


void gerenciaListaAnim::carregaListaAnimTeca()
{
	teca = new ListaAnimacao;
	gerAnim.addAnimTeca(teca);
	carregouTeca = true;
}


void gerenciaListaAnim::carregaListaAnimMosq()
{
	mosqueteiro= new ListaAnimacao;
	gerAnim.addAnimMosq(mosqueteiro);
	carregouMosq = true;
}


void gerenciaListaAnim::carregaListaAnimEsp()
{
	espadachim = new ListaAnimacao;
	gerAnim.addAnimEsp(espadachim);
	carregouEsp = true;
}


void gerenciaListaAnim::carregaListaAnimCav()
{
	cavaleiro = new ListaAnimacao;
	gerAnim.addAnimCav(cavaleiro);
	carregouCav = true;
}


void gerenciaListaAnim::carregaListaAnimChefaoCap()
{
	chefaoCap = new ListaAnimacao;
	gerAnim.addAnimChefaoCap(chefaoCap);
	carregouChefaoCap = true;
}


void gerenciaListaAnim::carregaListaAnimProj()
{
	projetil = new ListaAnimacao;
	gerAnim.addAnimProj(projetil);
	carregouProj = true;
}


void gerenciaListaAnim::carregaListaAnimPlat()
{
	plataforma = new ListaAnimacao;
	gerAnim.addAnimPlat(plataforma);
	carregouPlat = true;
}


void gerenciaListaAnim::carregaListaAnimCorda()
{
	corda = new ListaAnimacao;
	gerAnim.addAnimCorda(corda);
	carregouCorda = true;
}


void gerenciaListaAnim::carregaListaAnimArmadilha()
{
	armadilha = new ListaAnimacao;
	gerAnim.addAnimArmadilha(armadilha);
	carregouArmadilha = true;
}


void gerenciaListaAnim::carregaListaAnimEspinho()
{
	espinho = new ListaAnimacao;
	gerAnim.addAnimEspinho(espinho);
	carregouEspinho = true;
}


void gerenciaListaAnim::carregaListaAnimRede()
{
	rede = new ListaAnimacao;
	gerAnim.addAnimRede(rede);
	carregouRede = true;
}