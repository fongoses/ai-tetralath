#include <iostream>
#include <math.h>
using namespace std;

#define VIZINHO_INEXISTENTE NULL
#define LINHA_HORIZONTAL 1
#define LINHA_DIAGONAL_DECRESCENTE 2
#define LINHA_DIAGONAL_CRESCENTE 3

/*
* Classe que implementa uma casa do tabuleiro do jogo Tetralath.
* Para fins de comunicação, dá-se nomes aos vizinhos de uma casa da seguinte forma:
*       A   B
*     C   X   D
*       E   F
* A casa X é a casa representada pelo objeto.
* A e F formam uma reta, assim como C e D e B e E.
* Notar que o construtor não exige que sejam informadas as peças vizinhas, de modo que isto deve ser feito por função própria após a construção.
*/
class casaTabuleiroTetralath{
	public:
		//dados
		/*
		* Valor de cada vizinha que não existe (casas das bordas).
		*/
		//static const casaTabuleiroTetralath VIZINHO_INEXISTENTE = NULL;
		/*
		* Ids de cores de peças.
		* Na estrutura de dados e em funções que peçam cores de peças como parâmetros devem constar estes valores.
		*/
		static const int PECAS_BRANCAS = 1;
		static const int PECAS_PRETAS = 2;

		//métodos
		/*
		* Construtor da classe.
		*/
		casaTabuleiroTetralath(void);
		/*
		* Determina se esta casa está ocupada.
		* @return Booleano indicando se a casa está ocupada por alguma peça.
		*/
		bool estahOcupada(void);
		/*
		* Determina se esta casa está ocupada por peça da cor branca.
		* @return Booleano indicando se a casa está ocupada por alguma peça branca.
		*	Atenção: Se a casa não estiver ocupada ou se estiver ocupada por peça preta, retornará false.
		*/
		bool estahOcupadaPorPecaBranca(void);
		/*
		* Determina se esta casa está ocupada por peça da cor preta. Duplicou-se a função por motivo de desempenho.
		* @return Booleano indicando se a casa está ocupada por alguma peça preta.
		*	Atenção: Se a casa não estiver ocupada ou se estiver ocupada por peça branca, retornará false.
		*/
		bool estahOcupadaPorPecaPreta(void);
		/*
		* Ocupa esta casa com uma peça da cor passada.
		* @param corPeca_param A cor da peça que ocupará a casa. Deve ser tabuleiroTetralath.PECAS_BRANCAS ou tabuleiroTetralath.PECAS_PRETAS.
		* @return Booleano indicando se foi possível ocupar a casa (se ela estiver ocupada, não será possível).
		*/
		bool ocuparCom(int corPeca_param);
		/*
		* As funções à seguir possuem comportamento semelhante.
		* Cada uma retorna um ponteiro para uma casaTabuleiroTetralath que é vizinha desta casa.
		* Caso a casa não tenha vizinho na posição que a função verifica, retornará NULL.
		* @return Se há vizinho, retorna ponteiro para ele.
			  Se não há vizinho, retorna NULL.
		*/
		casaTabuleiroTetralath* getVizinhoA(void);
		casaTabuleiroTetralath* getVizinhoB(void);
		casaTabuleiroTetralath* getVizinhoC(void);
		casaTabuleiroTetralath* getVizinhoD(void);
		casaTabuleiroTetralath* getVizinhoE(void);
		casaTabuleiroTetralath* getVizinhoF(void);
		/*
		* A função à seguir cria a vizinhança desta casa, populando-a por outras casas.
		* Caso esta casa já possua vizinhos, esta função não terá efeito.
		* Não é possível, assim, editar vizinhos e todos vizinhos devem ser criados de uma só vez.
		* Vizinhos passados como NULL serão tratados como inexistentes (é possível utilizar a constante definida no início).
		* @param casaVizinhaX_param O objeto da casa de nome X, que é vizinha desta.
		* @return Booleano indicando se foi possível criar a vizinhança.
		*/
		bool criarVizinhanca(casaTabuleiroTetralath* casaVizinhaA,
				     casaTabuleiroTetralath* casaVizinhaB,
				     casaTabuleiroTetralath* casaVizinhaC,
				     casaTabuleiroTetralath* casaVizinhaD,
				     casaTabuleiroTetralath* casaVizinhaE,
				     casaTabuleiroTetralath* casaVizinhaF);

		/*
		* Procura por uma casa que, em linha reta (horizontal, diagonal decrescente ou diagonal crescente) está a uma distância dada desta.
		* @param distancia_param A distância desta casa em que está a casa procurada.
		* 			Distâncias negativas são interpretadas como casas à esquerda ou acima da casa de referência.
		*			Distâncias positivas são interpretadas como casas à direita ou abaixo da casa de referência.
		* @param linha_param A linha (LINHA_HORIZONTAL, LINHA_DIAGONAL_CRESCENTE ou LINHA_DIAGONAL_DECRESCENTE) em que se deseja efetuar a busca.
		* @return A casa com distância distancia_param da casa cujo nome é passado como parâmetro. Se não houver, retorna VIZINHO_INEXISTENTE.
		*/
		casaTabuleiroTetralath* getCasaDistanciaDesta(int distancia_param, int linha_param);

	private:
		//dados
		/*
		* À qualquer momento, indica se esta casa está ocupada por alguma peça.
		*/
		bool ocupada;
		/*
		* Caso a casa esteja ocupada por alguma peça, conterá o tipo da peça (conforme definido em "tabuleiroTetralath.h").
		*/
		int conteudo;
		/*
		* Casas vizinhas, conforme explicado no início deste arquivo.
		*/
		casaTabuleiroTetralath *A,
				       *B,
				       *C,
				       *D,
				       *E,
				       *F;

		//métodos
		






};
