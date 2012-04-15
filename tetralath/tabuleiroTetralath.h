#include <iostream>
#include <stdlib.h>
#include "casaTabuleiroTetralath.h"

/*
* Classe que implementa um tabuleiro do jogo Tetralath.
*/
class tabuleiroTetralath{
	public:
		//dados
		static const int NUMERO_CASAS = 61;
		
		//métodos
		/*
		* Construtor da classe.
		* Inicializa todas as casas com seus vizinhos.
		*/
		tabuleiroTetralath();
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
		* Indica se as peças da cor da peça parâmetro ganharam, isto acontece em um caso:
		*	(1) Se elas formaram uma linha de 4 peças consecutivas.
		* @param nomeCasaReferencia_param Um nome de casa a ser tomada como central, para referência. Tipicamente, esta será a última jogada feita.
		*	Este parâmetro existe por motivos de desempenho.
		* @return Booleano indicando se as peças da cor da peça parâmetro ganharam.
		* 	Atenção: false como retorno indica apenas que as peças parâmetro não ganharam, nada diz sobre empates ou perdedores.
		*/
		bool pecasDaMesmaCorGanharam(int nomeCasaReferencia_param);
		/*
		* Indica se as peças da cor da peça parâmetro perderam, isto acontece em um caso:
		*	(1) Estas peças formaram uma linha de 3 peças consecutivas.
		* @param nomeCasaReferencia_param Um nome de casa a ser tomada como central, para referência. Tipicamente, esta será a última jogada feita.
		*	Este parâmetro existe por motivos de desempenho.
		* @return Booleano indicando se as peças da cor da peça parâmetro perderam.
		* 	Atenção: false como retorno indica apenas que as peças parâmetro não perderam, nada diz sobre ganhadores ou empates.
		*/
		bool pecasDaMesmaCorPerderam(int nomeCasaReferencia_param);
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
		casaTabuleiroTetralath **tabuleiro;
		
		//métodos
		/*
		* Procura por uma seqüência de um número de casas ocupadas por peças da mesma cor.
		* A cor testada é a mesma da peça da casa considerada central.
		* Esta função verificará as três linhas possíveis ao redor da casa central:
		*	(1) Horizontal
		*	(2) Diagonal Decrescente
		*	(3) Diagonal Crescente
		* Somente serão verificadas casas nestas linhas e a uma distância de adjacência de (tamanhoSequencia_param - 1) casas.
		* Desta forma, para a linha horizontal e tamanhoSequencia_param = 4, teríamos:
		*	casa_não_testada,casa_testada,casa_testada,casa_testada,casa_central,casa_testada,casa_testada,casa_testada,casa_não_testada
		* @param nomeCasa_param Um índice (em tabuleiro) da casa que fica no centro da linha testada.
		* @param tamanhoSequencia_param O tamanho que a seqüência de casas da mesma cor precisa ter para ser considerada válida.
		* @return Booleano indicando se há alguma seqüência (com o número especificado) de casas adjacentes com peças da mesma cor.
		*/
		bool haSequenciaCasasMesmaCor(int nomeCasa_param, int tamanhoSequencia_param);







};
