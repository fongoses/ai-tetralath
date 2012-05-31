#include <iostream>

#ifndef INTERFACE_GUI
#define INTERFACE_GUI

#include "interface_gui.h"
 
#endif

#ifndef JOGADOR_TETRALATH
#define JOGADOR_TETRALATH

#include "jogadorTetralath.h"
 
#endif

using namespace std;

/*
* Representação de um jogo de tetralath.
*/
class jogoTetralath{
	public:
	/*
	* Define os tipos de jogos.
	*/
	static const int JOGO_HUMANO_VS_PC = 0;
	static const int JOGO_HUMANO_VS_HUMANO = 1;
	static const int JOGO_PC_VS_PC = 2;
		
	/*
	* Cria um novo jogo, com base no seu tipo, e o retorna.
	* @param _tipoJogo Define o tipo de jogo, se entre dois humanos, humano e pc ou pc contra pc.
	* @param _jogadorUm O jogador que fará a primeira jogada.
	* @param _jogadorDois O jogador que fará a segunda jogada.
	*/
	jogoTetralath(jogadorTetralath *_jogadorUm, jogadorTetralath *_jogadorDois);

	/*
	* Inicia o jogo. Esta função só retornará quando o jogo estiver terminado.
	* @param _interfaceUsuario A interface_gui usada para comunicação com o usuário.
	* @return O jogador que ganhou o jogo.
	*/
	jogadorTetralath* iniciarJogo(interface_gui _interfaceUsuario);
		
	private:
	/*
	* O jogador que fará a primeira jogada.
	*/
	jogadorTetralath* jogadorUm;
	
	/*
	* O jogador que fará a segunda jogada.
	*/
	jogadorTetralath* jogadorDois;

	/*
	* A interface_gui usada para comunicação com o usuário.
	*/
	interface_gui interfaceUsuario;
};