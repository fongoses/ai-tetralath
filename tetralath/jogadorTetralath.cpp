#include "jogadorTetralath.h"

/*
* @param _cor A cor das peças deste jogador. As cores são definidas em casaTabuleiroTetralath.
*/
void jogadorTetralath::setCorPecas(int _cor){
	corPecas = _cor;
}

/*
* A cor das peças deste jogador. As cores são definidas em casaTabuleiroTetralath.
*/
int jogadorTetralath::getCorPecas(){
	return corPecas;
}

/*
* @param _tipo O tipo do jogador, se humano ou máquina. Tipos são definidos neste arquivo.
*/
void jogadorTetralath::setTipoJogador(int _tipo){
	tipoJogador = _tipo;
}

/*
* @return O tipo do jogador, se humano ou máquina. Tipos são definidos neste arquivo.
*/
int jogadorTetralath::getTipoJogador(){
	return tipoJogador;
}