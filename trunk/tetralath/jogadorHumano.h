#ifndef JOGADOR_TETRALATH
#define JOGADOR_TETRALATH

#include "jogadorTetralath.h"
 
#endif

#ifndef INTERFACE_GUI
#define INTERFACE_GUI

#include "interface_gui.h"
 
#endif

/*
* Define um jogador controlado por humano.
*/
class jogadorHumano : public jogadorTetralath{
	public:
	/*
	* Cria um novo jogador humano.
	* @param _interfaceComunicacaoUsuario A interface pela qual será possível comunicar-se com o usuário.
	* @param _corPecas Cor das peças deste jogador.
	*/
	jogadorHumano(interface_gui _interfaceComunicacaoUsuario, int _corPecas);

	/*
	* Nesta classe, esta função aguardará entrada do usuário e retornará a casa escolhida por ele, quando ele escolher uma casa válida.
	* Atente para o fato de que o usuário pode terminar a aplicação aqui, através da interface.
	* @param _tabuleiro O tabuleiro em que é feita a jogada.
	* @return O índice da casa em que o jogador resolveu fazer sua jogada. Esta função é implementada somente nas herdeiras.
	*/
	int getIndiceCasaJogada(tabuleiroTetralath _tabuleiro);

	private:
	/*
	* A interface pela qual será possível comunicar-se com o usuário.
	*/
	interface_gui interfaceComunicacaoUsuario;
};