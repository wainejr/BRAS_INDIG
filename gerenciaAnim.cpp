#include "gerenciaAnim.h"
#include "Entidade.h"
#include "allegro5\allegro_primitives.h"

bool gerenciaAnim::carregouRaoni = false;


bool gerenciaAnim::carregouTeca = false;


bool gerenciaAnim::carregouMosq = false;


bool gerenciaAnim::carregouEsp = false;


bool gerenciaAnim::carregouCav = false;


bool gerenciaAnim::carregouChefaoCap = false;


bool gerenciaAnim::carregouProj = false;


bool gerenciaAnim::carregouPlat = false;
Animacao* gerenciaAnim::plataforma = nullptr;


bool gerenciaAnim::carregouCorda = false;
Animacao* gerenciaAnim::corda_esc = nullptr;
Animacao* gerenciaAnim::corda_nEsc = nullptr;

bool gerenciaAnim::carregouArmadilha = false;
Animacao* gerenciaAnim::armd_desativada = nullptr;
Animacao* gerenciaAnim::armd_ativada = nullptr;

bool gerenciaAnim::carregouEspinho = false;
Animacao* gerenciaAnim::espinho = nullptr;

bool gerenciaAnim::carregouRede = false;


gerenciaAnim::gerenciaAnim()
{
	plataforma = nullptr;
}


gerenciaAnim::~gerenciaAnim()
{
	/*
	if(plataforma)
		delete (plataforma);
	
	if(corda_esc)
		delete(corda_esc);
	if(corda_nEsc)
		delete(corda_nEsc);

	if(armd_desativada)
		delete(armd_desativada);
	if(armd_desativada)
		delete(armd_ativada);
	*/
}

ListaAnimacao* const gerenciaAnim::listaAnimEnt(const int aID)
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
	case CAVALEIRO:
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
		return nullptr;
		break;
	}
}

ListaAnimacao* const gerenciaAnim::listaAnimRaoni()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	Animacao* pAnim;
	if (!carregouRaoni)
		carregaAnimRaoni();

	// ADICIONA AS ANIMAÇÕES A LISTA

	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimTeca()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	Animacao* pAnim;
	if (!carregouTeca)
		carregaAnimTeca();

	// ADICIONA AS ANIMAÇÕES A LISTA

	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimMosq()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	Animacao* pAnim;
	if (!carregouMosq)
		carregaAnimMosq();

	// ADICIONA AS ANIMAÇÕES A LISTA

	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimEsp()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	Animacao* pAnim;
	if (!carregouEspinho)
		carregaAnimEspinho();
	
	pAnim = espinho->copiaAnimacao();
	pListaAnim->addAnimacao(espinho);
	// ADICIONA AS ANIMAÇÕES A LISTA

	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimCav()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	Animacao* pAnim;
	if (!carregouCav)
		carregaAnimCav();

	// ADICIONA AS ANIMAÇÕES A LISTA

	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimChefaoCap()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	Animacao* pAnim;
	if (!carregouChefaoCap)
		carregaAnimChefaoCap();

	// ADICIONA AS ANIMAÇÕES A LISTA

	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimProj()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	Animacao* pAnim;
	if (!carregouProj)
		carregaAnimProj();

	// ADICIONA AS ANIMAÇÕES A LISTA

	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimPlat()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	Animacao* pAnim;
	if (!carregouPlat)
		carregaAnimPlat();

	// ADICIONA AS ANIMAÇÕES A LISTA

	pAnim = plataforma->copiaAnimacao();
	pListaAnim->addAnimacao(pAnim);
	
	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimCorda()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	Animacao* pAnim;
	if (!carregouCorda)
		carregaAnimCorda();

	pAnim = corda_esc->copiaAnimacao();
	pListaAnim->addAnimacao(pAnim);

	pAnim = corda_nEsc->copiaAnimacao();
	pListaAnim->addAnimacao(pAnim);

	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimArmadilha()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	Animacao* pAnim;
	if (!carregouArmadilha)
		carregaAnimArmadilha();
	
	pAnim = armd_desativada->copiaAnimacao();
	pListaAnim->addAnimacao(pAnim);

	pAnim = armd_ativada->copiaAnimacao();
	pListaAnim->addAnimacao(pAnim);

	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimEspinho()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	Animacao* pAnim;
	if (!carregouEspinho)
		carregaAnimEspinho();

	// ADICIONA AS ANIMAÇÕES A LISTA
	pAnim = espinho->copiaAnimacao();
	pListaAnim->addAnimacao(pAnim);

	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimRede()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	Animacao* pAnim;
	if (!carregouRede)
		carregaAnimRede();

	// ADICIONA AS ANIMAÇÕES A LISTA

	return pListaAnim;
}

void gerenciaAnim::carregaAnimRaoni()
{
	//	CARREGA OS BITMAPS E DEFINE AS ANIMAÇOES, SEUS IDS E LARGURA E TD
}


void gerenciaAnim::carregaAnimTeca()
{
	//	CARREGA OS BITMAPS E DEFINE AS ANIMAÇOES, SEUS IDS E LARGURA E TD
}


void gerenciaAnim::carregaAnimMosq()
{
	//	CARREGA OS BITMAPS E DEFINE AS ANIMAÇOES, SEUS IDS E LARGURA E TD
}


void gerenciaAnim::carregaAnimEsp()
{
	//	CARREGA OS BITMAPS E DEFINE AS ANIMAÇOES, SEUS IDS E LARGURA E TD
}


void gerenciaAnim::carregaAnimCav()
{
	//	CARREGA OS BITMAPS E DEFINE AS ANIMAÇOES, SEUS IDS E LARGURA E TD
}


void gerenciaAnim::carregaAnimChefaoCap()
{
	//	CARREGA OS BITMAPS E DEFINE AS ANIMAÇOES, SEUS IDS E LARGURA E TD
}


void gerenciaAnim::carregaAnimProj()
{
	//	CARREGA OS BITMAPS E DEFINE AS ANIMAÇOES, SEUS IDS E LARGURA E TD
}


void gerenciaAnim::carregaAnimPlat()
{
	plataforma = new Animacao;
	ALLEGRO_BITMAP* image;

	image = al_load_bitmap("sprite_teste.png");
	plataforma->setSprite(image, 0, 256, 256, 6, 0.1);
	carregouPlat = true;
}


void gerenciaAnim::carregaAnimCorda()
{
	ALLEGRO_BITMAP* img_corda_esc;
	ALLEGRO_BITMAP* img_corda_nEsc;
	
	corda_esc = new Animacao;
	corda_nEsc = new Animacao;

	img_corda_esc = al_load_bitmap("sprites/plats/corda_esc.png");
	img_corda_nEsc = al_load_bitmap("sprites/plats/corda_nEsc.png");

	corda_esc->setSprite(img_corda_esc, 0, al_get_bitmap_width(img_corda_esc), al_get_bitmap_height(img_corda_esc));
	corda_nEsc->setSprite(img_corda_nEsc, 1, al_get_bitmap_width(img_corda_nEsc), al_get_bitmap_height(img_corda_nEsc));
	
	carregouCorda = true;
}


void gerenciaAnim::carregaAnimArmadilha()
{
	ALLEGRO_BITMAP* img_armd_ativada;
	ALLEGRO_BITMAP* img_armd_desativada;
	armd_ativada = new Animacao;
	armd_desativada = new Animacao;
	
	img_armd_ativada = al_load_bitmap("sprites/obstaculos/armadilha_ativada.png");
	img_armd_desativada = al_load_bitmap("sprites/obstaculos/armadilha_desativada.png");

	armd_desativada->setSprite(img_armd_desativada, 0, al_get_bitmap_width(img_armd_desativada), al_get_bitmap_height(img_armd_desativada));
	armd_ativada->setSprite(img_armd_ativada, 1, al_get_bitmap_width(img_armd_ativada), al_get_bitmap_height(img_armd_ativada));

	carregouArmadilha = true;
}


void gerenciaAnim::carregaAnimEspinho()
{
	ALLEGRO_BITMAP* img_espinho;
	espinho = new Animacao;
	
	img_espinho = al_load_bitmap("sprites/obstaculos/espinho.png");
	espinho->setSprite(img_espinho, 0, al_get_bitmap_width(img_espinho), al_get_bitmap_height(img_espinho));

	carregouEspinho = true;
}


void gerenciaAnim::carregaAnimRede()
{
	//	CARREGA OS BITMAPS E DEFINE AS ANIMAÇOES, SEUS IDS E LARGURA E TD
}