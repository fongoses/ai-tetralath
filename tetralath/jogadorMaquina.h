#ifndef JOGADOR_TETRALATH
#define JOGADOR_TETRALATH

#include "jogadorTetralath.h"
 
#endif

/*
* Define um jogador controlado pela máquina, via inteligência artificial.
*/
class jogadorMaquina : public jogadorTetralath{
	public:
	/*
	* Cria um novo jogador máquina, passando como argumento o algoritmo que utiliza para suas jogadas.
	* @param _iaEscolhida Inteligência artificial deste jogador.
	* @param _corPecas Cor das peças deste jogador.
	*/
	jogadorMaquina(ia _iaEscolhida, int _corPecas);

	/*
	* Nesta classe, esta função chamará o algoritmo da ia para decidir qual jogada deve ser feita.
	* @param _tabuleiro O tabuleiro em que é feita a jogada.
	* @return O índice da casa em que o jogador resolveu fazer sua jogada. Esta função é implementada somente nas herdeiras.
	*/
	int getIndiceCasaJogada(tabuleiroTetralath _tabuleiro);

	private:
	/*
	* Inteligência artificial deste jogador.
	*/
	ia iaEscolhida;
};