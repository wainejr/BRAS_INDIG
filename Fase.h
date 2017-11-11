#pragma once
#include "definesMacros.h"
#include "EntConcreteClasses.h"
#include "Lista.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>


/// FAZER UMA FUNÇÃO QUE TIRA E RETIRA OS ELEMENTOS DAS LISTAS, PARA NÃO FICAR COMPARANDO COM TODOS
///	UMA ESPÉCIE DE "TODASPLATAFORMAS", "TODOSMOSQUETEIROS" E AFINS

class Fase
{	
protected:
	//	VARIAVEIS ALLEGRO
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_EVENT_QUEUE* queue = NULL;
	ALLEGRO_FONT* arial18 = NULL;

	///	JOGADOR TESTE
	Jogador player1;
	Jogador player2;
	Arco armaPlayer1;
	Espada armaPlayer2;

	Jogador* jog1;
	Jogador* jog2;
	static int num_jogs;
	
	static bool campanha;

	//	LISTA DE ENTIDADES QUE ESTARÃO PRESENTES NA FASE
	//	(com exceção da fase final que não terá obstáculos)
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
	
	//	PROPRIEDADES DE POSIÇÃO DA FASE
	int limX;
	int limY;
	int posRelX;
	int posRelY;

	//	GERENCIADORES DA INICIALIZAÇÃO E REINICIALIZAÇÃO DA FASE
	void initTimers();
	void criarTimers();
	virtual void restart() = 0;
	void resetAllObjs();
	
	//	EXECUÇÃO DA FASE
	virtual void execFase() = 0;

	//	ATUALIZA TODA A FASE
	void atualizaFase();

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

	void perDescePlat(Personagem* const pPers);			//	desce o personagem da plataforma caso possível
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

	//	GERENCIA PERMISSÕES DO PERSONAGEM
	const bool personagemPodeAtacar(Personagem* const pPers);
	const bool jogadorPodeSubir(Jogador* const  pJog);
	const bool personagemPodePular(Personagem* const pPers);
	const bool jogadorEstaNumaCorda(Jogador* const pJog);
	const bool persPodeDescerPlat(Personagem* const pPers);

	//	DESENHA AS ENTIDADES DA FASE
	void desenhaObjs();

	void desenhaProjeteis();
	void desenhaCordas();
	void desenhaPlataformas();
	void desenhaEspinhos();
	void desenhaArmadilhas();
	void desenhaRedes();
	void desenhaInimigos();
	void desenhaJogadores();
	
	//	ATUALIZA A POSIÇÃO DA FASE COM RELAÇÃO AO JOGADOR
	void atualizaPosFase();
	const int getLimX();
	void setLimX(const int aLimX);
	const int getLimY();
	void setLimY(const int aLimY);

	
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

public:
	Fase();
	~Fase();

	virtual void initFase() = 0;
	void umJogador();
	void doisJogadores();
	void setCampanha(const bool aCamp);
	const int getNumJogs();
	void setNumJogs(const int aNumJogs);
	
};
