#include <windows.h>
#include <process.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef IA
#define IA

#include "ia.h"

#endif

#ifndef TABULEIRO_TETRALATH
#define TABULEIRO_TETRALATH

#include "tabuleiroTetralath.h"
 
#endif

/*
* Define um jogador de tetralath, seja ele artificial ou humano.
* Esta classe é abstrata, define a interface para seus dois tipos possíveis.
*/
class jogadorTetralath{
	public:
	/*
	* Define o tipo do jogador, máquina ou humano.
	*/
	static const int TIPO_HUMANO = 1;
	static const int TIPO_MAQUINA = 2;
	
	/*
	* @param _cor A cor das peças deste jogador. As cores são definidas em casaTabuleiroTetralath.
	*/
	void setCorPecas(int _cor);
	
	/*
	* A cor das peças deste jogador. As cores são definidas em casaTabuleiroTetralath.
	*/
	int getCorPecas();

	/*
	* @param _tipo O tipo do jogador, se humano ou máquina. Tipos são definidos neste arquivo.
	*/
	void setTipoJogador(int _tipo);
	
	/*
	* @return O tipo do jogador, se humano ou máquina. Tipos são definidos neste arquivo.
	*/
	int getTipoJogador();

	/*
	* @param _tabuleiro O tabuleiro em que é feita a jogada.
	* @return O índice da casa em que o jogador resolveu fazer sua jogada. Esta função é implementada somente nas herdeiras.
	*/
	virtual int getIndiceCasaJogada(tabuleiroTetralath *_tabuleiro) = 0;

	private:
	/*
	* Define a cor das peças deste jogador. As cores são definidas em casaTabuleiroTetralath.
	*/
	int corPecas;

	/*
	* O tipo do jogador, se humano ou máquina. Tipos são definidos neste arquivo.
	*/
	int tipoJogador;
};