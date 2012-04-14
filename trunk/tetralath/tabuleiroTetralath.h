#include <iostream>
#include "casaTabuleiroTetralath.h"

/*
* Classe que implementa um tabuleiro do jogo Tetralath.
*/
class tabuleiroTetralath{
	public:
		//dados

		
		//métodos
		/*
		* Construtor da classe.
		* Inicializa todas as casas com seus vizinhos.
		* @param corPecasJogador_param casaTabuleiroTetralath.PECAS_BRANCAS ou casaTabuleiroTetralath.PECAS_PRETAS. É a cor do jogador, a AI.
		*/
		tabuleiroTetralath(int corPecasJogador_param);
		/*
		* Determina se a casa de nome passado como parâmetro está ocupada por alguma peça.
		* @param nomeCasa_param O nome da casa a ser verificada. Nomes de casas são constantes definidas no início deste arquivo.
		* @return Booleano indicando se a casa está ocupada por alguma peça.
		*/
		bool casaOcupada(int nomeCasa_param);
		/*
		* Determina se a casa de nome passado como parâmetro está ocupada por alguma peça da cor branca.
		* @param nomeCasa_param O nome da casa a ser verificada. Nomes de casas são constantes definidas no início deste arquivo.
		* @return Booleano indicando se a casa está ocupada por alguma peça branca.
		*	Atenção: Se a casa não estiver ocupada ou se estiver ocupada por peça preta, retornará false.
		*/
		bool casaOcupadaPorPecaBranca(int nomeCasa_param);
		/*
		* Realiza uma jogada das peças passadas como parâmetro.
		* @param nomeCasa_param Casa a jogar.
		* @param corPecas_param Cor das peças que realizarão a jogada.
		* @return Booleano indicando se foi possível realizar a jogada.
		*/
		bool jogar(int nomeCasa_param, int corPecas_param);
		/*
		* Indica se o tabuleiro está em tal estado que o jogador atual ganhou.
		* @return Booleano indicando se o jogador ganhou.
		* 	Atenção: false como retorno indica apenas que este jogador não ganhou, nada diz sobre empates ou perdedores.
		*/
		bool ganhou(void);
		/*
		* Indica se o tabuleiro está em tal estado que o jogador atual perdeu.
		* @return Booleano indicando se o jogador perdeu.
		* 	Atenção: false como retorno indica apenas que este jogador não perdeu, nada diz sobre ganhadores ou empates.
		*/
		bool perdeu(void);
		/*
		* Indica se o tabuleiro está em estado de empate.
		* @return Booleano indicando se houve empate.
		* 	Atenção: false como retorno indica apenas que não houve empate, nada diz sobre ganhadores ou perdedores.
		*/
		bool houveEmpate(void);

	private:
		//dados
		/*
		* Array construído no momento da criação com os dados de todas as casas deste tabuleiro.
		*/
		casaTabuleiroTetralath[] tabuleiro;
		
		//métodos
	








};
