#include "ia.h"

/*************************************************************************************
* ATENÇÃO: À partir daqui, todos métodos são públicos
*************************************************************************************/
/*
* Construtor. Não faz nada.
* Só existe porque deixar os métodos estáticos estava dando erros demais.
*/
ia::ia(){}


/*
* Gerencia o uso do minimax até que a condição de parada seja satisfeita.
* São feitas avaliações em grafos de profundidades crescentes.
* @param estado_inicial_param Estado à partir do qual o grafo será expandido.
* @param deve_parar_param Ponteiro para variável que indica se o minimax deve terminar sua execução e retornar o resultado parcial.
*		 Esta variável é constantemente checada para verificar se é necessário parar. Seus possíveis valores são CONTINUAR e PARAR,
*		 definidos nesta classe. Caso o valor não seja nenhum destes, o default assumido é CONTINUAR.
* @param tipo_jogada_param O tipo de jogada (JOGADA_MAX ou JOGADA_MIN) que deve ser aplicado aos valores dos filhos de estado_inicial_param.
* @param cor_pecas_avaliacao_param Cor das peças para a qual as avaliações devem ser feitas.
* @return O nome da casa em que deve ser feita a jogada.
*/
int ia::comecar_minimax(tabuleiroTetralath estado_inicial_param, bool *deve_parar_param, int tipo_jogada_param, int cor_pecas_avaliacao_param){
	int MAXIMO_ITERACOES = estado_inicial_param.numeroDeCasasLivres();
	int nivelMaximoSendoAvaliado = 1;
	int casaMelhorJogada = 0;

	tabuleiro = *(new tabuleiroTetralath(&estado_inicial_param, true));

	while(*deve_parar_param != PARAR and nivelMaximoSendoAvaliado <= MAXIMO_ITERACOES){
		minimax(deve_parar_param, tipo_jogada_param, nivelMaximoSendoAvaliado, NIVEL_INICIAL, cor_pecas_avaliacao_param);
		if(!(*deve_parar_param)){
			casaMelhorJogada = resultado_minimax;
			nivelMaximoSendoAvaliado++;
		}
	}
	return casaMelhorJogada;
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
 tabuleiroTetralath ia::comecar_minimax_poda_alfa_beta(tabuleiroTetralath estado_inicial_param, bool *deve_parar_param, int tipo_jogada_param, int cor_pecas_avaliacao_param){
	return *(new tabuleiroTetralath(false));
}



/*************************************************************************************
* ATENÇÃO: À partir daqui, todos métodos são privados
*************************************************************************************/

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
float ia::minimax(bool *deve_parar_param, int tipo_jogada_param, int nivel_maximo_param, int nivel_atual_param, int cor_pecas_avaliacao_param){
	int jogadaAtual;
	int valorJogada;
	int tipoJogadaFilho = (tipo_jogada_param == (int) JOGADA_MIN? (int) JOGADA_MAX : (int) JOGADA_MIN);
	int casaMelhorJogada;

	bool valor_deveSerMaximizado = (tipo_jogada_param == JOGADA_MAX);
	bool estado_ehFolha = (tabuleiro.calcularNumeroMovimentosLegais() == 0);
	bool estado_jahAtingiuNivelMaximo = (nivel_atual_param == nivel_maximo_param);

	float valorMelhorJogada;

	if(estado_ehFolha or estado_jahAtingiuNivelMaximo){
		valorMelhorJogada = tabuleiro.avaliarParaPecasDaCor(cor_pecas_avaliacao_param);
	} else {
		if(nivel_atual_param == NIVEL_INICIAL){ //Necessário saber qual a casa de melhor jogada.
			casaMelhorJogada = 0;
			jogadaAtual=0;
			if(valor_deveSerMaximizado){
				valorMelhorJogada = tabuleiroTetralath::PERDA;
				while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS){
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorMelhorJogada <= valorJogada){
							casaMelhorJogada = jogadaAtual;
							valorMelhorJogada = valorJogada;
						}
					}
					jogadaAtual++;
				}
			} else {
				valorMelhorJogada = tabuleiroTetralath::VITORIA;
				while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS){
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorJogada <= valorMelhorJogada){
							casaMelhorJogada = jogadaAtual;
							valorMelhorJogada = valorJogada;
						}
					}
					jogadaAtual++;
				}
			}
			resultado_minimax = casaMelhorJogada;
		} else { //Não é necessário saber a casa de melhor jogada, só seu valor.
			jogadaAtual=0;
			if(valor_deveSerMaximizado){
				valorMelhorJogada = tabuleiroTetralath::PERDA;
				while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS){
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorMelhorJogada <= valorJogada){
							valorMelhorJogada = valorJogada;
						}
					}
					jogadaAtual++;
				}
			} else {
				valorMelhorJogada = tabuleiroTetralath::VITORIA;
				while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS){
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorJogada <= valorMelhorJogada){
							valorMelhorJogada = valorJogada;
						}
					}
					jogadaAtual++;
				}
			}
		}
	}

	return valorMelhorJogada;
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
													 bool *deve_parar_param,
													 int tipo_jogada_param,
													 int nivel_maximo_param,
													 int nivel_atual_param, int cor_pecas_avaliacao_param)
{


}
