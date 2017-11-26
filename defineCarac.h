#pragma once


#define RAONI 1
#define TECA 2
#define MOSQUETEIRO 3
#define ESPADACHIM 4
#define CAVALEIRO 5
#define ESPADA 6
#define LANCA 7
#define MOSQUETE 8
#define ARCO 9
#define PROJETIL_MOSQ 10
#define PROJETIL_ARCO 11
#define PLATAFORMA 12
#define CORDA 13
#define ARMADILHA 14
#define ESPINHO 15
#define REDE 16


#define ACEL_X_INI 0.6
#define ACEL_X_JOG 0.4
#define ACEL_REDE 0.6
#define ACEL_X_CAV 0.08

#define VEL_PULO 5
#define VEL_MAX_X_PERS 2
#define VEL_MAX_X_JOG 5
#define VEL_MAX_X_CAV 5
#define VEL_MAX_PROJ 7
#define VEL_MAX_REDE 3
#define VEL_SUBIDA 2
#define VEL_X_KB 4.5
#define VEL_Y_KB 1.6

//	Período de tempo entre ataques de cada Personagem 
//	(contando o tempo que o pers fica em estado ataque)
#define PER_ATAQ_MOSQ 1.5
#define PER_ATAQ_ESP 1.0
#define PER_ATAQ_JOG 0.5

//Tempo que o jogador "fica" atacando, ou seja, que a arma fica esticada
#define TEMP_ATAQ_JOG 0.2
#define TEMP_ATAQ_ESP 0.3
#define TEMP_ATAQ_MOSQ 0.1

#define TEMP_INVUN_JOG 2.0
#define TEMP_INVUN_MOSQ 0.5
#define TEMP_INVUN_ESP 0.5
#define TEMP_INVUN_CAV 1.0
#define TEMP_ACION_ARMD 1.5

#define TEMP_IMOVEL 1.5

#define VIDA_MAX_JOG 100
#define VIDA_MAX_ESP 50
#define VIDA_MAX_MOSQ 25
#define VIDA_MAX_CAV 40

#define DIFF_PIXELS_PARAR_X 10
#define DIFF_PIXELS_SEGUIR_Y 40
#define DIFF_PIXELS_CAV_PARAR 60

#define DANO_MOSQUETE 10
#define DANO_ESPADA_ESP 15
#define DANO_ESPADA_JOG	25
#define DANO_LANCA 30
#define DANO_ARCO 15

#define DANO_ARMD 25
#define DANO_ESPINHO 15
#define DANO_REDE 50

#define LIM_X_JOG 24
#define LIM_Y_JOG 48
#define LIM_X_ESP 24
#define LIM_Y_ESP 48
#define LIM_X_MOSQ 24
#define LIM_Y_MOSQ 48
#define LIM_X_CAV 64
#define LIM_Y_CAV 48

#define LIM_X_ESPADA_ESP 18
#define LIM_Y_ESPADA_ESP 5
#define LIM_X_ESPADA_JOG 32
#define LIM_Y_ESPADA_JOG 5

#define LIM_X_PROJ_MOSQ 4
#define LIM_Y_PROJ_MOSQ 4
#define LIM_X_PROJ_ARCO 24
#define LIM_Y_PROJ_ARCO 4

#define LIM_X_ARMD 14
#define LIM_Y_ARMD 5
#define LIM_X_REDE 30
#define LIM_Y_REDE 5
#define LIM_X_LINHA_REDE 5
#define LIM_Y_LINHA_REDE 5

#define DIFFCENT_ARMD 5
#define DIFFCENT_CORDA 10