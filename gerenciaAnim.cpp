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


bool gerenciaAnim::carregouArmadilha = false;


bool gerenciaAnim::carregouEspinho = false;


bool gerenciaAnim::carregouRede = false;


gerenciaAnim::gerenciaAnim()
{
	plataforma = nullptr;
}


gerenciaAnim::~gerenciaAnim()
{
	delete (plataforma);
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

	// ADICIONA AS ANIMAÇÕES A LISTA

	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimArmadilha()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	Animacao* pAnim;
	if (!carregouArmadilha)
		carregaAnimArmadilha();

	// ADICIONA AS ANIMAÇÕES A LISTA

	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimEspinho()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	Animacao* pAnim;
	if (!carregouEspinho)
		carregaAnimEspinho();

	// ADICIONA AS ANIMAÇÕES A LISTA

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
	//image = al_create_bitmap(20, 20);
	//al_set_target_bitmap(image);
	//al_draw_filled_circle(10, 10, 10, al_map_rgb(255, 0, 0));

	plataforma->setSprite(image, 0, 256, 256, 6, 0.1);

}


void gerenciaAnim::carregaAnimCorda()
{
	//	CARREGA OS BITMAPS E DEFINE AS ANIMAÇOES, SEUS IDS E LARGURA E TD
}


void gerenciaAnim::carregaAnimArmadilha()
{
	//	CARREGA OS BITMAPS E DEFINE AS ANIMAÇOES, SEUS IDS E LARGURA E TD
}


void gerenciaAnim::carregaAnimEspinho()
{
	//	CARREGA OS BITMAPS E DEFINE AS ANIMAÇOES, SEUS IDS E LARGURA E TD
}


void gerenciaAnim::carregaAnimRede()
{
	//	CARREGA OS BITMAPS E DEFINE AS ANIMAÇOES, SEUS IDS E LARGURA E TD
}