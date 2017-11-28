#include "gerenciaAnim.h"
#include "Entidade.h"
#include "allegro5\allegro_primitives.h"


bool gerenciaAnim::carregouRaoni = false;
Animacao* gerenciaAnim::raoni_anda = nullptr;
Animacao* gerenciaAnim::raoni_parado = nullptr;
Animacao* gerenciaAnim::raoni_atacando = nullptr;
Animacao* gerenciaAnim::raoni_subindo = nullptr;
Animacao* gerenciaAnim::raoni_corda = nullptr;

bool gerenciaAnim::carregouTeca = false;
Animacao* gerenciaAnim::teca_anda = nullptr;
Animacao* gerenciaAnim::teca_parada = nullptr;
Animacao* gerenciaAnim::teca_atacando = nullptr;
Animacao* gerenciaAnim::teca_subindo = nullptr;
Animacao* gerenciaAnim::teca_corda = nullptr;

bool gerenciaAnim::carregouMosq = false;


bool gerenciaAnim::carregouEsp = false;


bool gerenciaAnim::carregouCav = false;


bool gerenciaAnim::carregouChefaoCap = false;


bool gerenciaAnim::carregouProj = false;
Animacao* gerenciaAnim::tiro = nullptr;
Animacao* gerenciaAnim::flecha = nullptr;


bool gerenciaAnim::carregouPlat = false;
Animacao* gerenciaAnim::plataforma_grama = nullptr;
Animacao* gerenciaAnim::plataforma_chao = nullptr;
Animacao* gerenciaAnim::plataforma_cima = nullptr;


bool gerenciaAnim::carregouCorda = false;
Animacao* gerenciaAnim::corda_esc = nullptr;
Animacao* gerenciaAnim::corda_nEsc = nullptr;

bool gerenciaAnim::carregouArmadilha = false;
Animacao* gerenciaAnim::armd_desativada = nullptr;
Animacao* gerenciaAnim::armd_ativada = nullptr;

bool gerenciaAnim::carregouEspinho = false;
Animacao* gerenciaAnim::espinho = nullptr;


bool gerenciaAnim::carregouRede = false;
Animacao* gerenciaAnim::rede_caindo = nullptr;
Animacao* gerenciaAnim::rede_parada = nullptr;

gerenciaAnim::gerenciaAnim()
{
	
}


gerenciaAnim::~gerenciaAnim()
{
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
		return listaAnimEspinho();
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
	if (!carregouRaoni)
		carregaAnimRaoni();

	pListaAnim->addAnimacao(raoni_anda->copiaAnimacao());
	pListaAnim->addAnimacao(raoni_parado->copiaAnimacao());
	pListaAnim->addAnimacao(raoni_subindo->copiaAnimacao());
	pListaAnim->addAnimacao(raoni_atacando->copiaAnimacao());
	pListaAnim->addAnimacao(raoni_corda->copiaAnimacao());

	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimTeca()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	if (!carregouTeca)
		carregaAnimTeca();

	pListaAnim->addAnimacao(teca_anda->copiaAnimacao());
	pListaAnim->addAnimacao(teca_parada->copiaAnimacao());
	pListaAnim->addAnimacao(teca_subindo->copiaAnimacao());
	pListaAnim->addAnimacao(teca_atacando->copiaAnimacao());
	pListaAnim->addAnimacao(teca_corda->copiaAnimacao());

	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimMosq()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	if (!carregouMosq)
		carregaAnimMosq();

	// ADICIONA AS ANIMAÇÕES A LISTA

	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimEsp()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	if (!carregouEspinho)
		carregaAnimEspinho();
	
	
	// ADICIONA AS ANIMAÇÕES A LISTA

	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimCav()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	if (!carregouCav)
		carregaAnimCav();

	// ADICIONA AS ANIMAÇÕES A LISTA

	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimChefaoCap()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	if (!carregouChefaoCap)
		carregaAnimChefaoCap();

	// ADICIONA AS ANIMAÇÕES A LISTA

	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimProj()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	if (!carregouProj)
		carregaAnimProj();

	pListaAnim->addAnimacao(tiro->copiaAnimacao());
	pListaAnim->addAnimacao(flecha->copiaAnimacao());
	// ADICIONA AS ANIMAÇÕES A LISTA

	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimPlat()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	if (!carregouPlat)
		carregaAnimPlat();

	// ADICIONA AS ANIMAÇÕES A LISTA

	pListaAnim->addAnimacao(plataforma_chao->copiaAnimacao());
	pListaAnim->addAnimacao(plataforma_grama->copiaAnimacao());
	pListaAnim->addAnimacao(plataforma_cima->copiaAnimacao());

	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimCorda()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	if (!carregouCorda)
		carregaAnimCorda();

	pListaAnim->addAnimacao(corda_esc->copiaAnimacao());
	pListaAnim->addAnimacao(corda_nEsc->copiaAnimacao());

	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimArmadilha()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	if (!carregouArmadilha)
		carregaAnimArmadilha();
	
	pListaAnim->addAnimacao(armd_desativada->copiaAnimacao());
	pListaAnim->addAnimacao(armd_ativada->copiaAnimacao());

	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimEspinho()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	if (!carregouEspinho)
		carregaAnimEspinho();

	// ADICIONA AS ANIMAÇÕES A LISTA
	pListaAnim->addAnimacao(espinho->copiaAnimacao());

	return pListaAnim;
}


ListaAnimacao* const gerenciaAnim::listaAnimRede()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	if (!carregouRede)
		carregaAnimRede();

	// ADICIONA AS ANIMAÇÕES A LISTA
	pListaAnim->addAnimacao(rede_caindo->copiaAnimacao());
	pListaAnim->addAnimacao(rede_parada->copiaAnimacao());
	return pListaAnim;
}

void gerenciaAnim::carregaAnimRaoni()
{
	raoni_anda = new Animacao;
	raoni_parado = new Animacao;
	raoni_atacando = new Animacao;
	raoni_subindo = new Animacao;
	raoni_corda = new Animacao;

	ALLEGRO_BITMAP* image_anda;
	ALLEGRO_BITMAP* image_parado;
	ALLEGRO_BITMAP* image_ataque;
	ALLEGRO_BITMAP* image_subindo;
	ALLEGRO_BITMAP* image_corda;

	image_anda = al_load_bitmap("sprites/jogs/raoni_anda.png");
	image_parado = al_load_bitmap("sprites/jogs/raoni_parado.png");
	image_ataque = al_load_bitmap("sprites/jogs/raoni_atacando.png");
	image_subindo = al_load_bitmap("sprites/jogs/raoni_subindo.png");
	image_corda = al_load_bitmap("sprites/jogs/raoni_corda.png");

	raoni_anda->setSprite(image_anda, 0, 28, al_get_bitmap_height(image_anda), 8, 1.0 / 15);
	raoni_parado->setSprite(image_parado, 1, 28, al_get_bitmap_height(image_parado));
	raoni_atacando->setSprite(image_ataque, 2, 33, al_get_bitmap_height(image_ataque), 6, 1.0 / 30);
	raoni_subindo->setSprite(image_subindo, 3, 30, al_get_bitmap_height(image_subindo), 4, 1.0 / 10);
	raoni_corda->setSprite(image_corda, 4, 30, al_get_bitmap_height(image_corda));

	carregouRaoni = true;
}


void gerenciaAnim::carregaAnimTeca()
{
	teca_anda = new Animacao;
	teca_parada = new Animacao;
	teca_atacando = new Animacao;
	teca_subindo = new Animacao;
	teca_corda = new Animacao;

	ALLEGRO_BITMAP* image_anda;
	ALLEGRO_BITMAP* image_parada;
	ALLEGRO_BITMAP* image_ataque;
	ALLEGRO_BITMAP* image_subindo;
	ALLEGRO_BITMAP* image_corda;

	image_anda = al_load_bitmap("sprites/jogs/teca_anda.png");
	image_parada = al_load_bitmap("sprites/jogs/teca_parada.png");
	image_ataque = al_load_bitmap("sprites/jogs/teca_atacando.png");
	image_subindo = al_load_bitmap("sprites/jogs/teca_subindo.png");
	image_corda = al_load_bitmap("sprites/jogs/teca_corda.png");

	teca_anda->setSprite(image_anda, 0, 25, al_get_bitmap_height(image_anda), 8, 1.0 / 15);
	teca_parada->setSprite(image_parada, 1, 25, al_get_bitmap_height(image_parada));
	teca_atacando->setSprite(image_ataque, 2, 27, al_get_bitmap_height(image_ataque), 5, 1.0 / 30);
	teca_subindo->setSprite(image_subindo, 3, 30, al_get_bitmap_height(image_subindo), 4, 1.0 / 10);
	teca_corda->setSprite(image_corda, 4, 30, al_get_bitmap_height(image_corda));
}


void gerenciaAnim::carregaAnimMosq()
{
	raoni_anda = new Animacao;
	raoni_parado = new Animacao;
	raoni_atacando = new Animacao;
	raoni_subindo = new Animacao;
	raoni_corda = new Animacao;

	ALLEGRO_BITMAP* image_anda;
	ALLEGRO_BITMAP* image_parado;
	ALLEGRO_BITMAP* image_ataque;
	ALLEGRO_BITMAP* image_subindo;
	ALLEGRO_BITMAP* image_corda;

	image_anda = al_load_bitmap("sprites/jogs/raoni_anda.png");
	image_parado = al_load_bitmap("sprites/jogs/raoni_parado.png");
	image_ataque = al_load_bitmap("sprites/jogs/raoni_atacando.png");
	image_subindo = al_load_bitmap("sprites/jogs/raoni_subindo.png");
	image_corda = al_load_bitmap("sprites/jogs/raoni_corda.png");

	raoni_anda->setSprite(image_anda, 0, 28, al_get_bitmap_height(image_anda), 8, 1.0 / 15);
	raoni_parado->setSprite(image_parado, 1, 28, al_get_bitmap_height(image_parado));
	raoni_atacando->setSprite(image_ataque, 2, 33, al_get_bitmap_height(image_ataque), 6, 1.0 / 30);
	raoni_subindo->setSprite(image_subindo, 3, 30, al_get_bitmap_height(image_subindo), 4, 1.0 / 10);
	raoni_corda->setSprite(image_corda, 4, 30, al_get_bitmap_height(image_corda));
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
	tiro = new Animacao;
	flecha = new Animacao;

	ALLEGRO_BITMAP* image_tiro;
	ALLEGRO_BITMAP* image_flecha;

	image_tiro = al_load_bitmap("sprites/proj/projetil_tiro.png");
	image_flecha = al_load_bitmap("sprites/proj/projetil_flecha.png");
	
	tiro->setSprite(image_tiro, 0, al_get_bitmap_width(image_tiro), al_get_bitmap_height(image_tiro));
	flecha->setSprite(image_flecha, 1, al_get_bitmap_width(image_flecha), al_get_bitmap_height(image_flecha));

	carregouProj = true;
}


void gerenciaAnim::carregaAnimPlat()
{
	plataforma_chao = new Animacao;
	plataforma_grama = new Animacao;
	plataforma_cima = new Animacao;
	ALLEGRO_BITMAP* image_terra;
	ALLEGRO_BITMAP* image_grama;
	ALLEGRO_BITMAP* image_cima;

	image_terra = al_load_bitmap("sprites/plats/plat_terra.png");
	image_grama = al_load_bitmap("sprites/plats/plat_grama.png");
	image_cima = al_load_bitmap("sprites/plats/plat_cima.png");

	plataforma_chao->setSprite(image_terra, 1, al_get_bitmap_width(image_terra), al_get_bitmap_height(image_terra), 1);
	plataforma_grama->setSprite(image_grama, 0, al_get_bitmap_width(image_grama), al_get_bitmap_height(image_grama), 1);
	plataforma_cima->setSprite(image_cima, 2, al_get_bitmap_width(image_cima), al_get_bitmap_height(image_cima), 1);

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
	rede_caindo = new Animacao;
	rede_parada = new Animacao;

	ALLEGRO_BITMAP* image_caindo;
	ALLEGRO_BITMAP* image_parada;

	image_caindo = al_load_bitmap("sprites/obstaculos/rede_caindo.png");
	image_parada = al_load_bitmap("sprites/obstaculos/rede_parada.png");

	rede_caindo->setSprite(image_caindo, 1, al_get_bitmap_width(image_caindo), al_get_bitmap_height(image_caindo));
	rede_parada->setSprite(image_parada, 0, al_get_bitmap_width(image_parada), al_get_bitmap_height(image_parada));
	carregouRede = true;
}