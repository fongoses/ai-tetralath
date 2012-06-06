#include <iostream>
#include <string>

#ifndef TABULEIRO_TETRALATH
#define TABULEIRO_TETRALATH

#include "tabuleiroTetralath.h"
 
#endif

/*
* Classe para inteligência artificial.
* Encapsula o algoritmo e permite acesso a resultado parcial em qualquer momento após início da computação.
* A classe não possui construtor. Ela serve somente para encapsulamento dos algoritmos, "limpando" o código principal
* e permitindo reuso.
* ATENÇÃO: Como não há construtor, todos dados e métodos devem ser estáticos.
*/
class ia{
	public:
	//dados
	/*
	* Usadas para definir se o minimax deve continuar ou ser interrompido.
	*/
	static const bool CONTINUAR = false;
	static const bool PARAR = true;
	
	/*
	* Indicam tipos de movimentos de avaliação dos valores dos filhos.
	*/
	static const int JOGADA_MAX = 1;
	static const int JOGADA_MIN = 0;
	
	/*
	* Indicam os algoritmos que esta classe oferece.
	*/
	static const int MINIMAX = 0;
	static const int MINIMAX_PODA = 1;
	
	/*
	* Indicam as funcões de avaliação disponíveis.
	*/
	static const int AVALIACAO_SIMPLES = 0;
	static const int AVALIACAO_MINUCIOSA = 1;
	
	//métodos
	/*
	* Construtor base... Faz nada!
	*/
	ia(void);
	
	/*
	* Construtor. 
	* @param _algoritmo O algoritmo que deve ser utilizado por esta ia. Definido nesta classe.
	* @param _avaliacao A função de avaliação que esta ia utilizará. Definido nesta classe.
	*/
	ia(int _algoritmo, int _avaliacao);

	/*
	* Construtor de cópia.
	* @param _ia ia a ser copiada.
	*/
	ia(ia *_ia);
	
	/*
	* Gerencia o uso do algoritmo escolhido até que a condição de parada seja satisfeita.
	* São feitas avaliações em grafos de profundidades crescentes.
	* @param estado_inicial_param Estado à partir do qual o grafo será expandido.
	* @param deve_parar_param Ponteiro para variável que indica se o minimax deve terminar sua execução e retornar o resultado parcial.
	*		 Esta variável é constantemente checada para verificar se é necessário parar. Seus possíveis valores são CONTINUAR e PARAR,
	*		 definidos nesta classe. Caso o valor não seja nenhum destes, o default assumido é continuar.
	* @param tipo_jogada_param O tipo de jogada (JOGADA_MAX ou JOGADA_MIN) que deve ser aplicado aos valores dos filhos de estado_inicial_param.
	* @return O nome da casa em que deve ser feita a jogada.
	*/
	int comecar_avaliacao(tabuleiroTetralath estado_inicial_param, bool *deve_parar_param, int tipo_jogada_param, int cor_pecas_avaliacao_param);
	
	/*
	* @return Char* indicando a estratégia utilizada.
	*/
	std::string toString();

	private:
	/*
	* Algoritmo utilizado.
	*/
	int algoritmo;
	
	/*
	* Função de avaliação utilizada.
	*/
	int avaliacao;
	
	//dados
	/*
	* Na expansão do grafo do minimax, é o valor atribuído ao nível do estado_inicial passado à função comecar_(nome do algortimo).
	*/
	static const int NIVEL_INICIAL = 0;

	/*
	* Tabuleiro utilizado nos algoritmos. É sempre inicializado nas funções comecar_x.
	*/
	tabuleiroTetralath tabuleiro;
	
	/*
	* Contem o nome da casa em que deve ser feita a jogada, apos execucao do minimax.
	*/
	int resultado_minimax;

	//métodos
	/*
	* Gerencia o uso do minimax até que a condição de parada seja satisfeita.
	* São feitas avaliações em grafos de profundidades crescentes.
	* @param estado_inicial_param Estado à partir do qual o grafo será expandido.
	* @param deve_parar_param Ponteiro para variável que indica se o minimax deve terminar sua execução e retornar o resultado parcial.
	*		 Esta variável é constantemente checada para verificar se é necessário parar. Seus possíveis valores são CONTINUAR e PARAR,
	*		 definidos nesta classe. Caso o valor não seja nenhum destes, o default assumido é continuar.
	* @param tipo_jogada_param O tipo de jogada (JOGADA_MAX ou JOGADA_MIN) que deve ser aplicado aos valores dos filhos de estado_inicial_param.
	* @return O nome da casa em que deve ser feita a jogada.
	*/
	int comecar_minimax(tabuleiroTetralath estado_inicial_param, bool *deve_parar_param, int tipo_jogada_param, int cor_pecas_avaliacao_param);
	
	/*
	* Gerencia o uso do minimax com poda alfa beta até que a condição de parada seja satisfeita.
	* São feitas avaliações em grafos de profundidades crescentes.
	* @param estado_inicial_param Estado à partir do qual o grafo será expandido.
	* @param deve_parar_param Ponteiro para variável que indica se o minimax deve terminar sua execução e retornar o resultado parcial.
	*		 Esta variável é constantemente checada para verificar se é necessário parar. Seus possíveis valores são CONTINUAR e PARAR,
	*		 definidos nesta classe. Caso o valor não seja nenhum destes, o default assumido é continuar.
	* @param tipo_jogada_param O tipo de jogada (JOGADA_MAX ou JOGADA_MIN) que deve ser aplicado aos valores dos filhos de estado_inicial_param.
	* @return O melhor estado encontrado para o qual estado_inicial_param pode ir.
	*/
	int comecar_minimax_poda_alfa_beta(tabuleiroTetralath estado_inicial_param, bool *deve_parar_param, int tipo_jogada_param, int cor_pecas_avaliacao_param);

	/*
	* Executa o algoritmo minimax. O caminhamento utilizado é progressivo em profundidade.
	* Utiliza a variável de instância tabuleiro para dar início ao algoritmo. Todas jogadas são simuladas neste tabuleiro.
	* O resultado é colocado em resultado_minimax.
	* @param deve_parar_param Ponteiro para variável que indica se o minimax deve terminar sua execução e retornar o resultado parcial.
	*		 Esta variável é constantemente checada para verificar se é necessário parar. Seus possíveis valores são CONTINUAR e PARAR,
	*		 definidos nesta classe. Caso o valor não seja nenhum destes, o default assumido é continuar.
	* @param tipo_jogada_param O tipo de jogada (JOGADA_MAX ou JOGADA_MIN) que deve ser aplicado aos valores dos filhos de estado_inicial_param.
	* @param nivel_maximo_param Especifica quantos niveis (em profundidade) o grafo pode ser expandido.
	* @param nivel_atual_param Define a distância (no grafo expandido) entre estado_inicial_param e o estado que iniciou esta função.
	*						   Logicamente, na primeira chamada à função, deve conter 0.
	* @param cor_pecas_avaliacao_param Cor das peças para a qual as avaliações devem ser feitas.
	* @return O melhor valor de avaliação encontrado em toda a subárvore do nodo estado_inicial_param.
	*/
	float minimax(bool *deve_parar_param, int tipo_jogada_param, int nivel_maximo_param, int nivel_atual_param, int cor_pecas_avaliacao_param);
	//minimax com função de avaliação minuciosa
	float minimax_minucioso(bool *deve_parar_param, int tipo_jogada_param, int nivel_maximo_param, int nivel_atual_param, int cor_pecas_avaliacao_param);

	/*
	* Executa o algoritmo minimax com poda alfa beta. O caminhamento utilizado é progressivo em profundidade.
	* Utiliza a variável de instância tabuleiro para dar início ao algoritmo. Todas jogadas são simuladas neste tabuleiro.
	* O resultado é colocado em resultado_minimax.
	* @param deve_parar_param Ponteiro para variável que indica se o minimax deve terminar sua execução e retornar o resultado parcial.
	*		 Esta variável é constantemente checada para verificar se é necessário parar. Seus possíveis valores são CONTINUAR e PARAR,
	*		 definidos nesta classe. Caso o valor não seja nenhum destes, o default assumido é continuar.
	* @param tipo_jogada_param O tipo de jogada (JOGADA_MAX ou JOGADA_MIN) que deve ser aplicado aos valores dos filhos de estado_inicial_param.
	* @param nivel_maximo_param Especifica quantos niveis (em profundidade) o grafo pode ser expandido.
	* @param nivel_atual_param Define a distância (no grafo expandido) entre estado_inicial_param e o estado que iniciou esta função.
	*						   Logicamente, na primeira chamada à função, deve conter 0.
	* @param cor_pecas_avaliacao_param Cor das peças para a qual as avaliações devem ser feitas.
	* @return O melhor valor de avaliação encontrado em toda a subárvore do nodo estado_inicial_param.
	*/
	float minimax_poda_alfa_beta(bool *deve_parar_param, int tipo_jogada_param, int nivel_maximo_param, int nivel_atual_param, int cor_pecas_avaliacao_param);
	//minimax com função de avaliação minuciosa
	float minimax_poda_alfa_beta_minucioso(bool *deve_parar_param, int tipo_jogada_param, int nivel_maximo_param, int nivel_atual_param, int cor_pecas_avaliacao_param);

};