#include "jogadorMaquina.h"



/*
* Cria um novo jogador máquina, passando como argumento o algoritmo que utiliza para suas jogadas.
* @param _iaEscolhida Inteligência artificial deste jogador.
* @param _corPecas Cor das peças deste jogador.
*/
jogadorMaquina::jogadorMaquina(ia _iaEscolhida, int _corPecas){
	iaEscolhida = _iaEscolhida;
	setCorPecas(_corPecas);
	setTipoJogador(jogadorTetralath::TIPO_MAQUINA);
}

/*
* @param _tabuleiro O tabuleiro em que é feita a jogada.
* @return O índice da casa em que o jogador resolveu fazer sua jogada. Esta função é implementada somente nas herdeiras.
*/
int jogadorMaquina::getIndiceCasaJogada(tabuleiroTetralath _tabuleiro){
	return 0;
}

