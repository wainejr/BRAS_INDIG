#pragma once
#include "EntConcreteClasses.h"
#include "Lista.h"
#include "definesMacros.h"

class Mapa
{
private:
	//	LISTA DE ENTIDADES QUE ESTARÃO PRESENTES NO MAPA
	Lista <Jogador*> jogadores;
	Lista <Plataforma*> plataformas;
	Lista <Mosqueteiro*> mosqueteiros;
	Lista <Espadachim*> espadachins;
	Lista <EspadachimCavaleiro*> cavaleiros;
	Lista <Projetil*> projeteis;
	Lista <Corda*> cordas;
	Lista <Armadilha*> armadilhas;
	Lista <Espinho*> espinhos;
	Lista <Rede*> redes;

	//	PROPRIEDADES DE POSIÇÃO DO MAPA
	int limX;
	int limY;
	int posRelX;
	int posRelY;
	
	void atualizaPosMapa();
	const int getLimX();
	void setLimX(const int aLimX);
	const int getLimY();
	void setLimY(const int aLimY);

	//	CHAMA O ATUALIZAR DAS ENTIDADES
	void atualizaObjs();

	//	ATUALIZA QUAIS ENTIDADES ESTÃO ATIVAS
	void atualizaAtivos();

	//	ATUALIZA QUAIS OS ALVOS DOS INIMIGOS
	void atualizaAlvos();
	void alvoInimigo(Inimigo* const pIni);

	//	GERENCIA COLISÕES E DANO ENTRE PERSONAGENS
	void gerenciaColisoes();

	void gerenciaColisaoAtaques();
	void gerenciaColisaoPlatObstProj();

	const bool colisaoChao(Personagem* const pEnt);
	const bool colisaoInimigo(Jogador* const pJog);
	const bool colisaoPlat(Entidade* const pEnt);		//	gere a colisão
	const bool colisaoEntPlat(Entidade* const pEnt);	//	apenas vê se a colisão ocorreu

	void colisaoProjeteis(Personagem* const pPers);
	void colisaoEspinhos(Personagem* const pPers);
	void colisaoArmadilhas(Jogador* const pJog);
	void colisaoLinhaRede(Jogador* const pJog);
	void colisaoRede(Jogador* const pJog);

	const bool colisaoPersChao(Personagem* const pPers, Plataforma* const pPlataforma);
	const bool colisaoEntEnt(Entidade* const pEnt1, Entidade* const pEnt2);
	void gereColisao(Entidade* const pMovel, Entidade* const pParado);

	//	GERENCIA OS ATAQUES DOS INIMGOS
	void ataqueInimigos();

	void desenhaProjeteis();
	void desenhaCordas();
	void desenhaPlataformas();
	void desenhaEspinhos();
	void desenhaArmadilhas();
	void desenhaRedes();
	void desenhaInimigos();
	void desenhaJogadores();

public:
	Mapa();
	~Mapa();

	//	ATUALIZA TODO O MAPA
	void atualizaMapa();

	//	DESENHA AS ENTIDADES DO MAPA
	void desenhaObjs();

	//	GERENCIA PERMISSÕES DO PERSONAGEM
	const bool personagemPodeAtacar(Personagem* const pPers);
	const bool jogadorPodeSubir(Jogador* const  pJog);
	const bool personagemPodePular(Personagem* const pPers);
	const bool jogadorEstaNumaCorda(Jogador* const pJog);
	const bool persPodeDescerPlat(Personagem* const pPers);
	void perDescePlat(Personagem* const pPers);			//	desce o personagem da plataforma caso possível

	//	RETIRA TODOS AS ENTIDADES DO MAPA
	void retiraTodosObjs();

	void addPlayer(Jogador* const pPlayer);
	void addPlataforma(Plataforma* const pPlataforma);
	void addCorda(Corda* const pCorda);
	void addMosqueteiro(Mosqueteiro* const pMosq);
	void addEspadachim(Espadachim* const pEsp);
	void addCavaleiro(EspadachimCavaleiro* const pCav);
	void addProjetil(Projetil* const pProj);
	void addArmadilha(Armadilha* const pArmd);
	void addEspinho(Espinho* const pEspinho);
	void addRede(Rede* const pRede);

	void criarTimers();
	void initTimers();
	void stopTimers();
	void resumeTimers();
};

