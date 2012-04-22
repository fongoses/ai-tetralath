#include <iostream>
#include "tabuleiroTetralath.h"

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
	static const int CONTINUAR = 1;
	static const int PARAR = 0;
	
	/*
	* Indicam tipos de movimentos de avaliação dos valores dos filhos.
	*/
	static const int JOGADA_MAX = 1;
	static const int JOGADA_MIN = 0;
	
	//métodos
	/*
	* Gerencia o uso do minimax até que a condição de parada seja satisfeita.
	* São feitas avaliações em grafos de profundidades crescentes.
	* @param estado_inicial_param Estado à partir do qual o grafo será expandido.
	* @param deve_parar_param Ponteiro para variável que indica se o minimax deve terminar sua execução e retornar o resultado parcial.
	*		 Esta variável é constantemente checada para verificar se é necessário parar. Seus possíveis valores são CONTINUAR e PARAR,
	*		 definidos nesta classe. Caso o valor não seja nenhum destes, o default assumido é continuar.
	* @param tipo_jogada_param O tipo de jogada (JOGADA_MAX ou JOGADA_MIN) que deve ser aplicado aos valores dos filhos de estado_inicial_param.
	* @return O melhor estado encontrado para o qual estado_inicial_param pode ir.
	*/
	static tabuleiroTetralath comecar_minimax(tabuleiroTetralath estado_inicial_param, int *deve_parar_param, int tipo_jogada_param, int cor_pecas_avaliacao_param);
	
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
	static tabuleiroTetralath comecar_minimax_poda_alfa_beta(tabuleiroTetralath estado_inicial_param, int *deve_parar_param, int tipo_jogada_param, int cor_pecas_avaliacao_param);
	
	
	private:
	//dados
	/*
	* Na expansão do grafo do minimax, é o valor atribuído ao nível do estado_inicial passado à função comecar_(nome do algortimo).
	*/
	static const int NIVEL_INICIAL = 0;

	//métodos

	/*
	* Executa o algoritmo minimax. O caminhamento utilizado é progressivo em profundidade.
	* @param estado_inicial_param Estado à partir do qual o grafo será expandido.
	* @param resultado_parcial_param Ponteiro para variável em que será colocado o resultado parcial. Este resultado só tem utilidade
	*								 caso corresponda a um objeto diretamente ligado ao objeto que deu início à primeira chamada desta função.
	* @param deve_parar_param Ponteiro para variável que indica se o minimax deve terminar sua execução e retornar o resultado parcial.
	*		 Esta variável é constantemente checada para verificar se é necessário parar. Seus possíveis valores são CONTINUAR e PARAR,
	*		 definidos nesta classe. Caso o valor não seja nenhum destes, o default assumido é continuar.
	* @param tipo_jogada_param O tipo de jogada (JOGADA_MAX ou JOGADA_MIN) que deve ser aplicado aos valores dos filhos de estado_inicial_param.
	* @param nivel_maximo_param Especifica quantos niveis (em profundidade) o grafo pode ser expandido.
	* @param nivel_atual_param Define a distância (no grafo expandido) entre estado_inicial_param e o estado que iniciou esta função.
	*						   Logicamente, na primeira chamada à função, deve conter 0.
	* @return O melhor estado para o qual estado_inicial_param pode ir.
	*/
	static tabuleiroTetralath minimax(tabuleiroTetralath estado_inicial_param,
									  tabuleiroTetralath* resultado_parcial_param,
									  int *deve_parar_param,
									  int tipo_jogada_param,
									  int nivel_maximo_param,
									  int nivel_atual_param);

	/*
	* Executa o algoritmo minimax com poda alfa beta. O caminhamento utilizado é progressivo em profundidade.
	* @param estado_inicial_param Estado à partir do qual o grafo será expandido.
	* @param resultado_parcial_param Ponteiro para variável em que será colocado o resultado parcial. Este resultado só tem utilidade
	*								 caso corresponda a um objeto diretamente ligado ao objeto que deu início à primeira chamada desta função.
	* @param deve_parar_param Ponteiro para variável que indica se o minimax deve terminar sua execução e retornar o resultado parcial.
	*		 Esta variável é constantemente checada para verificar se é necessário parar. Seus possíveis valores são CONTINUAR e PARAR,
	*		 definidos nesta classe. Caso o valor não seja nenhum destes, o default assumido é continuar.
	* @param tipo_jogada_param O tipo de jogada (JOGADA_MAX ou JOGADA_MIN) que deve ser aplicado aos valores dos filhos de estado_inicial_param.
	* @param nivel_maximo_param Especifica quantos niveis (em profundidade) o grafo pode ser expandido.
	* @param nivel_atual_param Define a distância (no grafo expandido) entre estado_inicial_param e o estado que iniciou esta função.
	*						   Logicamente, na primeira chamada à função, deve conter 0.
	* @return O melhor estado para o qual estado_inicial_param pode ir.
	*/
	static tabuleiroTetralath minimax_poda_alfa_beta(tabuleiroTetralath estado_inicial_param,
													 tabuleiroTetralath* resultado_parcial_param,
													 int *deve_parar_param,
													 int nivel_maximo_param,
													 int nivel_atual_param);

	/*
	* Tenta encontrar em um array um valor (obtido com avaliação dos elementos) condizente com o objetivo parâmetro.
	* @param array_param Um array em que cada elemento é um float.
	* @param tamanho_array_param A quantidade de itens no array (contando à partir do elemento de índice 1).
	* @param objetivo_param Determina se deve-se procurar pelo elemento que tenha o maior valor (JOGADA_MAX) ou
	*						por aquele que tenha o menor valor (JOGADA_MIN).
	* @return O objeto que mais se pareça com o objetivo.
	*/
	static int procurarMelhor(tabuleiroTetralath array_param[], int tamanho_array_param, int objetivo_param);

};