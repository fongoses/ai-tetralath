#include "ia.h"

/*************************************************************************************
* ATENÇÃO: À partir daqui, todos métodos são públicos
*************************************************************************************/
	/*
	* Construtor. Não faz nada.
	* Só existe porque deixar os métodos estáticos estava dando erros demais.
	*/
	ia::ia(){
		
	}


/*
* Gerencia o uso do minimax até que a condição de parada seja satisfeita.
* São feitas avaliações em grafos de profundidades crescentes.
* @param estado_inicial_param Estado à partir do qual o grafo será expandido.
* @param deve_parar_param Ponteiro para variável que indica se o minimax deve terminar sua execução e retornar o resultado parcial.
*		 Esta variável é constantemente checada para verificar se é necessário parar. Seus possíveis valores são CONTINUAR e PARAR,
*		 definidos nesta classe. Caso o valor não seja nenhum destes, o default assumido é CONTINUAR.
* @param tipo_jogada_param O tipo de jogada (JOGADA_MAX ou JOGADA_MIN) que deve ser aplicado aos valores dos filhos de estado_inicial_param.
* @param cor_pecas_avaliacao_param Cor das peças para a qual as avaliações devem ser feitas.
* @return O melhor estado encontrado para o qual estado_inicial_param pode ir.
*/
tabuleiroTetralath ia::comecar_minimax(tabuleiroTetralath estado_inicial_param, int *deve_parar_param, int tipo_jogada_param, int cor_pecas_avaliacao_param){
	int MAXIMO_ITERACOES = tabuleiroTetralath::NUMERO_CASAS;
	int nivelMaximoSendoAvaliado = 1;
	int indiceMelhorJogadaEncontrada;
	float valoresJogadasEncontradas[MAXIMO_ITERACOES];

	tabuleiroTetralath* resultado_parcial[MAXIMO_ITERACOES];

	for(int i=0; i<MAXIMO_ITERACOES; i++){
		resultado_parcial[i] = new tabuleiroTetralath();
	}

	while(*deve_parar_param != PARAR){
		valoresJogadasEncontradas[nivelMaximoSendoAvaliado] = minimax(estado_inicial_param, resultado_parcial[nivelMaximoSendoAvaliado],
																	  deve_parar_param, tipo_jogada_param, nivelMaximoSendoAvaliado,
																	  NIVEL_INICIAL, cor_pecas_avaliacao_param);
		nivelMaximoSendoAvaliado++;
	}

	indiceMelhorJogadaEncontrada = procurarMelhor(valoresJogadasEncontradas, nivelMaximoSendoAvaliado, tipo_jogada_param);
	return *(resultado_parcial[indiceMelhorJogadaEncontrada]->clonar());
}

/*
* Gerencia o uso do minimax com poda alfa beta até que a condição de parada seja satisfeita.
* São feitas avaliações em grafos de profundidades crescentes.
* @param estado_inicial_param Estado à partir do qual o grafo será expandido.
* @param deve_parar_param Ponteiro para variável que indica se o minimax deve terminar sua execução e retornar o resultado parcial.
*		 Esta variável é constantemente checada para verificar se é necessário parar. Seus possíveis valores são CONTINUAR e PARAR,
*		 definidos nesta classe. Caso o valor não seja nenhum destes, o default assumido é CONTINUAR.
* @param tipo_jogada_param O tipo de jogada (JOGADA_MAX ou JOGADA_MIN) que deve ser aplicado aos valores dos filhos de estado_inicial_param.
* @param cor_pecas_avaliacao_param Cor das peças para a qual as avaliações devem ser feitas.
* @return O melhor estado encontrado para o qual estado_inicial_param pode ir.
*/
 tabuleiroTetralath ia::comecar_minimax_poda_alfa_beta(tabuleiroTetralath estado_inicial_param, int *deve_parar_param, int tipo_jogada_param, int cor_pecas_avaliacao_param){
	int MAXIMO_ITERACOES = tabuleiroTetralath::NUMERO_CASAS;
	int nivelMaximoSendoAvaliado = 1;
	int indiceMelhorJogadaEncontrada;
	float valoresJogadasEncontradas[MAXIMO_ITERACOES];

	tabuleiroTetralath* resultado_parcial[MAXIMO_ITERACOES];

	for(int i=0; i<MAXIMO_ITERACOES; i++){
		resultado_parcial[i] = new tabuleiroTetralath();
	}

	while(*deve_parar_param != PARAR){
		valoresJogadasEncontradas[nivelMaximoSendoAvaliado] = minimax_poda_alfa_beta(estado_inicial_param, resultado_parcial[nivelMaximoSendoAvaliado],
																					 deve_parar_param, tipo_jogada_param, nivelMaximoSendoAvaliado,
																					 NIVEL_INICIAL, cor_pecas_avaliacao_param);
		nivelMaximoSendoAvaliado++;
	}

	indiceMelhorJogadaEncontrada = procurarMelhor(valoresJogadasEncontradas, nivelMaximoSendoAvaliado, tipo_jogada_param);
	return *(resultado_parcial[indiceMelhorJogadaEncontrada]->clonar());
}



/*************************************************************************************
* ATENÇÃO: À partir daqui, todos métodos são privados
*************************************************************************************/

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
* @param cor_pecas_avaliacao_param Cor das peças para a qual as avaliações devem ser feitas.
* @return O melhor valor de avaliação encontrado em toda a subárvore do nodo estado_inicial_param.
*/
float ia::minimax(tabuleiroTetralath estado_inicial_param,
									  tabuleiroTetralath* resultado_parcial_param,
									  int *deve_parar_param,
									  int tipo_jogada_param,
									  int nivel_maximo_param,
									  int nivel_atual_param, int cor_pecas_avaliacao_param)
{
	int filhoAtual;
	int valorUtilidadeEstado;
	int tipoJogadaFilho = (tipo_jogada_param == (int) JOGADA_MIN? (int) JOGADA_MAX : (int) JOGADA_MIN);
	int numeroDeFilhos = estado_inicial_param.calcularNumeroMovimentosLegais();
	int indiceMelhorValorEncontradoNaSubarvore;

	bool estado_ehFolha = (numeroDeFilhos == 0);
	bool estado_jahAtingiuNivelMaximo = (nivel_atual_param == nivel_maximo_param);

	tabuleiroTetralath *estadoFilho;
	tabuleiroTetralath *melhorEstadoEncontrado;
	tabuleiroTetralath resultadosParciaisFilhos[numeroDeFilhos+1]; //O primeiro indice válido será 1.

	float melhorValorEncontradoNaSubarvore;
	float valoresEncontradosNaSubarvore[numeroDeFilhos];

	if(estado_ehFolha or estado_jahAtingiuNivelMaximo){
		resultado_parcial_param->copiarDe(&estado_inicial_param);
		melhorValorEncontradoNaSubarvore = estado_inicial_param.avaliarParaPecasDaCor(cor_pecas_avaliacao_param);
	} else {
		for(int i=0; i<numeroDeFilhos; i++){
			resultadosParciaisFilhos[i] = *(new tabuleiroTetralath());
		}
		filhoAtual = 1;
		estadoFilho = estado_inicial_param.procurarEstadoAtingivelNaPosicao(filhoAtual);
		while(estadoFilho != tabuleiroTetralath::NAO_HA_ESTADO_ATINGIVEL and *deve_parar_param != PARAR){
			valoresEncontradosNaSubarvore[filhoAtual] = minimax(*estadoFilho, &(resultadosParciaisFilhos[filhoAtual]),
																deve_parar_param, tipoJogadaFilho, nivel_maximo_param,
																nivel_atual_param+1, cor_pecas_avaliacao_param);
			filhoAtual++;
			estadoFilho = estado_inicial_param.procurarEstadoAtingivelNaPosicao(filhoAtual);
		}
		//Usa-se filhoAtual-1 ao invés de numeroDeFilhos, pois numeroDeFilhos causaria invasão de memória se deve_parar_param tivesse sido acionado.
		indiceMelhorValorEncontradoNaSubarvore = procurarMelhor(valoresEncontradosNaSubarvore, filhoAtual-1, tipo_jogada_param);
		melhorEstadoEncontrado = &(resultadosParciaisFilhos[indiceMelhorValorEncontradoNaSubarvore]);
		resultado_parcial_param->copiarDe(melhorEstadoEncontrado);
		melhorValorEncontradoNaSubarvore = melhorEstadoEncontrado->avaliarParaPecasDaCor(cor_pecas_avaliacao_param);
	}

	return melhorValorEncontradoNaSubarvore;
}

/*
* Executa o algoritmo minimax com poda alfa beta. O caminhamento utilizado é progressivo em profundidade.
* @param estado_inicial_param Estado à partir do qual o grafo será expandido.
* @param resultado_parcial_param Ponteiro para variável em que será colocado o resultado parcial. Este resultado só tem utilidade
*								 caso corresponda a um objeto diretamente ligado ao objeto que deu início à primeira chamada desta função.* @param deve_parar_param Ponteiro para variável que indica se o minimax deve terminar sua execução e retornar o resultado parcial.
*		 Esta variável é constantemente checada para verificar se é necessário parar. Seus possíveis valores são CONTINUAR e PARAR,
*		 definidos nesta classe. Caso o valor não seja nenhum destes, o default assumido é continuar.
* @param tipo_jogada_param O tipo de jogada (JOGADA_MAX ou JOGADA_MIN) que deve ser aplicado aos valores dos filhos de estado_inicial_param.
* @param nivel_maximo_param Especifica quantos niveis (em profundidade) o grafo pode ser expandido.
* @param nivel_atual_param Define a distância (no grafo expandido) entre estado_inicial_param e o estado que iniciou esta função.
*						   Logicamente, na primeira chamada à função, deve conter 0.
* @param cor_pecas_avaliacao_param Cor das peças para a qual as avaliações devem ser feitas.
* @return O melhor valor de avaliação encontrado em toda a subárvore do nodo estado_inicial_param.
*/
float ia::minimax_poda_alfa_beta(tabuleiroTetralath estado_inicial_param,
													 tabuleiroTetralath* resultado_parcial_param,
													 int *deve_parar_param,
													 int tipo_jogada_param,
													 int nivel_maximo_param,
													 int nivel_atual_param, int cor_pecas_avaliacao_param)
{


}

/*
* Tenta encontrar em um array um valor (obtido com avaliação dos elementos) condizente com o objetivo parâmetro.
* @param array_param Um array em que cada elemento é um float.
* @param tamanho_array_param A quantidade de itens no array (contando à partir do elemento de índice 1).
* @param objetivo_param Determina se deve-se procurar pelo elemento que tenha o maior valor (JOGADA_MAX) ou
*						por aquele que tenha o menor valor (JOGADA_MIN).
* @return O índice do array que possui o melhor valor.
*/
 int ia::procurarMelhor(float array_param[], int tamanho_array_param, int objetivo_param){
	int indiceMelhorResultadoParcial;
	float valorResultadoParcial;
	float valorMelhorResultadoParcial = tabuleiroTetralath::PERDA;
	for(int i=0; i<tamanho_array_param; i++){
		valorResultadoParcial = array_param[i];
		if(valorMelhorResultadoParcial <= valorResultadoParcial){
			indiceMelhorResultadoParcial = i;
		}
	}
	return indiceMelhorResultadoParcial;
}