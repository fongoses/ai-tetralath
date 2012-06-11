#include "ia.h"
#include "interface_gui.h"
#include "abertura.h"
#include "casaTabuleiroTetralath.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>


/*************************************************************************************
* ATENÇÃO: À partir daqui, todos métodos são públicos
*************************************************************************************/
/*
* Construtor base... Faz nada!
*/
ia::ia(void){}

/*
* Construtor. 
* @param _algoritmo O algoritmo que deve ser utilizado por esta ia. Definido nesta classe.
* @param _avaliacao A função de avaliação que esta ia utilizará. Definido nesta classe.
*/
ia::ia(int _algoritmo, int _avaliacao){
	algoritmo = _algoritmo;
	avaliacao = _avaliacao;
	utilizaAbertura = false;
}

/*
* Construtor. 
* @param _algoritmo O algoritmo que deve ser utilizado por esta ia. Definido nesta classe.
* @param _avaliacao A função de avaliação que esta ia utilizará. Definido nesta classe.
* @param _abertura A abertura que esta ia utilizará.
*/
ia::ia(int _algoritmo, int _avaliacao, abertura *_abertura){
	algoritmo = _algoritmo;
	avaliacao = _avaliacao;
	utilizaAbertura = true;
	aberturaUtilizada = _abertura;
}

/*
* Construtor de cópia.
* @param _ia ia a ser copiada.
*/
ia::ia(ia *_ia){
	algoritmo = _ia->algoritmo;
	avaliacao = _ia->avaliacao;
	aberturaUtilizada = _ia->aberturaUtilizada;
}

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
int ia::comecar_avaliacao(tabuleiroTetralath estado_inicial_param, bool *deve_parar_param, int tipo_jogada_param, int cor_pecas_avaliacao_param){
	int casaResultado = 0;
	bool utilizouAbertura = false;

	if(utilizaAbertura and aberturaUtilizada->aplicavelAoTabuleiro(&estado_inicial_param)){
		utilizouAbertura = true;
		casaResultado = aberturaUtilizada->getNomeProximaJogada();
		tabuleiro = *(new tabuleiroTetralath(&estado_inicial_param, true));
		tabuleiro.jogar(casaResultado);
		bool variavelComFalse = false;
		int corPecasAvaliacao = (cor_pecas_avaliacao_param == casaTabuleiroTetralath::PECAS_BRANCAS?
					casaTabuleiroTetralath::PECAS_PRETAS : casaTabuleiroTetralath::PECAS_BRANCAS);
		
		float avaliacaoJogada = minimax_poda_alfa_beta_preguicoso(&variavelComFalse, tipo_jogada_param, 3, NIVEL_INICIAL, corPecasAvaliacao);
		
		if(tabuleiroTetralath::EMPATE < avaliacaoJogada){
			utilizouAbertura = false;
			printf("Abertura falhou, pois inimigo pode ganhar em breve.\n");
		} else {
			tabuleiro = *(new tabuleiroTetralath(&estado_inicial_param, true));
			avaliacaoJogada = minimax_poda_alfa_beta_preguicoso(&variavelComFalse, tipo_jogada_param, 3, NIVEL_INICIAL, cor_pecas_avaliacao_param);
			if(avaliacaoJogada == tabuleiroTetralath::PERDA){
				utilizouAbertura = false;
				printf("Abertura falhou, pois daria vitória ao inimigo.\n");
			} else {
				aberturaUtilizada->jogar();
				interface_gui::imprimirTextoCentralizado(toString());
				printf("Utilizou movimento de abertura.\n");
			}
		}
	} else {
		utilizouAbertura = false;
		if(utilizaAbertura){
			printf("Abertura falhou, pois nao eh aplicavel.\n");
		}
	}

	if(!utilizouAbertura){
		switch(algoritmo){
			case ia::MINIMAX: 
					casaResultado = comecar_minimax(estado_inicial_param, deve_parar_param, tipo_jogada_param, cor_pecas_avaliacao_param);
				break;
			case ia::MINIMAX_PODA: 
					casaResultado = comecar_minimax_poda_alfa_beta(estado_inicial_param, deve_parar_param, 
												tipo_jogada_param, cor_pecas_avaliacao_param);
				break;
		}
	}

	return casaResultado;
}

/*
* @return Char* indicando a estratégia utilizada.
*/
std::string ia::toString(){
	std::string stringIA;
	switch(algoritmo){
		case ia::MINIMAX: stringIA = "MINIMAX";
			break;
		case ia::MINIMAX_PODA: stringIA = "PODA ALFA BETA";
			break;
	}
	switch(avaliacao){
		case ia::AVALIACAO_SIMPLES: stringIA += " com AVALIACAO INGENUA";
			break;
		case ia::AVALIACAO_MINUCIOSA: stringIA += " com AVALIACAO MINUCIOSA";
			break;
		case ia::AVALIACAO_PREGUICOSA: stringIA += " com AVALIACAO PREGUICOSA";
			break;
	}
	if(utilizaAbertura){
		stringIA += " com ABERTURA";
	} else {
		stringIA += " sem ABERTURA";
	}
	stringIA+="\n";
	return stringIA;
}


/*************************************************************************************
* ATENÇÃO: À partir daqui, todos métodos são privados
*************************************************************************************/

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
	float resultado_melhor_aplicacao_minimax = tabuleiroTetralath::PERDA;
	float resultado_aplicacao_minimax = tabuleiroTetralath::PERDA;
	unsigned milissegundosInicioIteracao;

	tabuleiro = *(new tabuleiroTetralath(&estado_inicial_param, true));

	interface_gui::imprimirTextoCentralizado(toString());
	printf("Niveis que jah avaliou: ");
	while(*deve_parar_param != PARAR and nivelMaximoSendoAvaliado <= MAXIMO_ITERACOES 
			and resultado_melhor_aplicacao_minimax != tabuleiroTetralath::VITORIA){
		milissegundosInicioIteracao = clock();

		switch(avaliacao){
			case ia::AVALIACAO_SIMPLES:
					resultado_aplicacao_minimax = minimax(deve_parar_param, tipo_jogada_param, nivelMaximoSendoAvaliado, NIVEL_INICIAL, cor_pecas_avaliacao_param);
				break;
			case ia::AVALIACAO_MINUCIOSA:
					resultado_aplicacao_minimax = minimax_minucioso(deve_parar_param, tipo_jogada_param, nivelMaximoSendoAvaliado, NIVEL_INICIAL, cor_pecas_avaliacao_param);
				break;
			case ia::AVALIACAO_PREGUICOSA:
					resultado_aplicacao_minimax = minimax_preguicoso(deve_parar_param, tipo_jogada_param, nivelMaximoSendoAvaliado, NIVEL_INICIAL, cor_pecas_avaliacao_param);
				break;
		}
		if(!(*deve_parar_param)){
			printf("\n\t\t\t\t%d em %ldms com valor %.1f para casa %d,",nivelMaximoSendoAvaliado, 
				clock()-milissegundosInicioIteracao, 
				resultado_aplicacao_minimax,
				resultado_minimax);
		}
		if(!(*deve_parar_param) && resultado_melhor_aplicacao_minimax <= resultado_aplicacao_minimax){
			resultado_melhor_aplicacao_minimax = resultado_aplicacao_minimax;
			casaMelhorJogada = resultado_minimax;
		}
		nivelMaximoSendoAvaliado++;
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
 int ia::comecar_minimax_poda_alfa_beta(tabuleiroTetralath estado_inicial_param, bool *deve_parar_param, int tipo_jogada_param, int cor_pecas_avaliacao_param){
	int MAXIMO_ITERACOES = estado_inicial_param.numeroDeCasasLivres();
	int nivelMaximoSendoAvaliado = 1;
	int casaMelhorJogada = 0;
	float resultado_melhor_aplicacao_minimax = tabuleiroTetralath::PERDA;
	float resultado_aplicacao_minimax = tabuleiroTetralath::PERDA;
	unsigned milissegundosInicioIteracao;

	tabuleiro = *(new tabuleiroTetralath(&estado_inicial_param, true));

	interface_gui::imprimirTextoCentralizado(toString());
	printf("Niveis que jah avaliou: ");
	while(*deve_parar_param != PARAR and nivelMaximoSendoAvaliado <= MAXIMO_ITERACOES
			and resultado_melhor_aplicacao_minimax != tabuleiroTetralath::VITORIA){
		milissegundosInicioIteracao = clock();
		switch(avaliacao){
			case ia::AVALIACAO_SIMPLES: 
					resultado_aplicacao_minimax = minimax_poda_alfa_beta(deve_parar_param, tipo_jogada_param, nivelMaximoSendoAvaliado, NIVEL_INICIAL, cor_pecas_avaliacao_param);
				break;
			case ia::AVALIACAO_MINUCIOSA: 
					resultado_aplicacao_minimax = minimax_poda_alfa_beta_minucioso(deve_parar_param, tipo_jogada_param, nivelMaximoSendoAvaliado, NIVEL_INICIAL, cor_pecas_avaliacao_param);
				break;
			case ia::AVALIACAO_PREGUICOSA:
					resultado_aplicacao_minimax = minimax_poda_alfa_beta_preguicoso(deve_parar_param, tipo_jogada_param, nivelMaximoSendoAvaliado, NIVEL_INICIAL, cor_pecas_avaliacao_param);
				break;
		}
		if(!(*deve_parar_param)){
			printf("\n\t\t\t\t%d em %ldms com valor %.1f para casa %d,",nivelMaximoSendoAvaliado, 
				clock()-milissegundosInicioIteracao, 
				resultado_aplicacao_minimax,
				resultado_minimax);
		}
		if(!(*deve_parar_param) && resultado_melhor_aplicacao_minimax <= resultado_aplicacao_minimax){
			resultado_melhor_aplicacao_minimax = resultado_aplicacao_minimax;
			casaMelhorJogada = resultado_minimax;
		}
		nivelMaximoSendoAvaliado++;
	}
	return casaMelhorJogada;
}

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

	float valorMelhorJogada = tabuleiro.avaliarParaPecasDaCor(cor_pecas_avaliacao_param);

	bool valor_deveSerMaximizado = (tipo_jogada_param == JOGADA_MAX);
	bool estado_ehFolha = (valorMelhorJogada == tabuleiroTetralath::VITORIA || valorMelhorJogada == tabuleiroTetralath::PERDA);
	bool estado_jahAtingiuNivelMaximo = (nivel_atual_param == nivel_maximo_param);

	if(!estado_ehFolha and !estado_jahAtingiuNivelMaximo) {
		if(nivel_atual_param == NIVEL_INICIAL){ //Necessário saber qual a casa de melhor jogada.
			casaMelhorJogada = 0;
			jogadaAtual=0;
			if(valor_deveSerMaximizado){
				valorMelhorJogada = tabuleiroTetralath::PERDA-1;
				do{
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorMelhorJogada < valorJogada){
							casaMelhorJogada = jogadaAtual;
							valorMelhorJogada = valorJogada;
						}
					}
					jogadaAtual++;
				}while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS);
			} else {
				valorMelhorJogada = tabuleiroTetralath::VITORIA+1;
				do{
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorJogada < valorMelhorJogada){
							casaMelhorJogada = jogadaAtual;
							valorMelhorJogada = valorJogada;
						}
					}
					jogadaAtual++;
				}while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS);
			}
			resultado_minimax = casaMelhorJogada;
		} else { //Não é necessário saber a casa de melhor jogada, só seu valor.
			jogadaAtual=0;
			if(valor_deveSerMaximizado){
				valorMelhorJogada = tabuleiroTetralath::PERDA-1;
				do{
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorMelhorJogada < valorJogada){
							valorMelhorJogada = valorJogada;
						}
					}
					jogadaAtual++;
				}while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS);
			} else {
				valorMelhorJogada = tabuleiroTetralath::VITORIA+1;
				do{
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorJogada < valorMelhorJogada){
							valorMelhorJogada = valorJogada;
						}
					}
					jogadaAtual++;
				}while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS);
			}
		}
	}

	return valorMelhorJogada;
}
float ia::minimax_preguicoso(bool *deve_parar_param, int tipo_jogada_param, int nivel_maximo_param, int nivel_atual_param, int cor_pecas_avaliacao_param){
	int jogadaAtual;
	int valorJogada;
	int tipoJogadaFilho = (tipo_jogada_param == (int) JOGADA_MIN? (int) JOGADA_MAX : (int) JOGADA_MIN);
	int casaMelhorJogada;

	float valorMelhorJogada = tabuleiro.avaliarPreguicosamenteParaPecasDaCor(cor_pecas_avaliacao_param);

	bool valor_deveSerMaximizado = (tipo_jogada_param == JOGADA_MAX);
	bool estado_ehFolha = (valorMelhorJogada == tabuleiroTetralath::VITORIA || valorMelhorJogada == tabuleiroTetralath::PERDA);
	bool estado_jahAtingiuNivelMaximo = (nivel_atual_param == nivel_maximo_param);

	if(!estado_ehFolha and !estado_jahAtingiuNivelMaximo) {
		if(nivel_atual_param == NIVEL_INICIAL){ //Necessário saber qual a casa de melhor jogada.
			casaMelhorJogada = 0;
			jogadaAtual=0;
			if(valor_deveSerMaximizado){
				valorMelhorJogada = tabuleiroTetralath::PERDA-1;
				do{
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax_preguicoso(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorMelhorJogada < valorJogada){
							casaMelhorJogada = jogadaAtual;
							valorMelhorJogada = valorJogada;
						}
					}
					jogadaAtual++;
				}while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS);
			} else {
				valorMelhorJogada = tabuleiroTetralath::VITORIA+1;
				do{
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax_preguicoso(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorJogada < valorMelhorJogada){
							casaMelhorJogada = jogadaAtual;
							valorMelhorJogada = valorJogada;
						}
					}
					jogadaAtual++;
				}while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS);
			}
			resultado_minimax = casaMelhorJogada;
		} else { //Não é necessário saber a casa de melhor jogada, só seu valor.
			jogadaAtual=0;
			if(valor_deveSerMaximizado){
				valorMelhorJogada = tabuleiroTetralath::PERDA-1;
				do{
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax_preguicoso(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorMelhorJogada < valorJogada){
							valorMelhorJogada = valorJogada;
						}
					}
					jogadaAtual++;
				}while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS);
			} else {
				valorMelhorJogada = tabuleiroTetralath::VITORIA+1;
				do{
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax_preguicoso(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorJogada < valorMelhorJogada){
							valorMelhorJogada = valorJogada;
						}
					}
					jogadaAtual++;
				}while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS);
			}
		}
	}

	return valorMelhorJogada;
}
float ia::minimax_minucioso(bool *deve_parar_param, int tipo_jogada_param, int nivel_maximo_param, int nivel_atual_param, int cor_pecas_avaliacao_param){
	int jogadaAtual;
	int valorJogada;
	int tipoJogadaFilho = (tipo_jogada_param == (int) JOGADA_MIN? (int) JOGADA_MAX : (int) JOGADA_MIN);
	int casaMelhorJogada;

	float valorMelhorJogada = tabuleiro.avaliarParaPecasDaCor(cor_pecas_avaliacao_param);

	bool valor_deveSerMaximizado = (tipo_jogada_param == JOGADA_MAX);
	bool estado_ehFolha = (valorMelhorJogada == tabuleiroTetralath::VITORIA || valorMelhorJogada == tabuleiroTetralath::PERDA);
	bool estado_jahAtingiuNivelMaximo = (nivel_atual_param == nivel_maximo_param);

	if(!estado_ehFolha and !estado_jahAtingiuNivelMaximo) {
		if(nivel_atual_param == NIVEL_INICIAL){ //Necessário saber qual a casa de melhor jogada.
			casaMelhorJogada = 0;
			jogadaAtual=0;
			if(valor_deveSerMaximizado){
				valorMelhorJogada = tabuleiroTetralath::PERDA-1;
				do{
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax_minucioso(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorMelhorJogada < valorJogada){
							casaMelhorJogada = jogadaAtual;
							valorMelhorJogada = valorJogada;
						}
					}
					jogadaAtual++;
				}while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS);
			} else {
				valorMelhorJogada = tabuleiroTetralath::VITORIA+1;
				do{
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax_minucioso(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorJogada < valorMelhorJogada){
							casaMelhorJogada = jogadaAtual;
							valorMelhorJogada = valorJogada;
						}
					}
					jogadaAtual++;
				}while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS);
			}
			resultado_minimax = casaMelhorJogada;
		} else { //Não é necessário saber a casa de melhor jogada, só seu valor.
			jogadaAtual=0;
			if(valor_deveSerMaximizado){
				valorMelhorJogada = tabuleiroTetralath::PERDA-1;
				do{
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax_minucioso(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorMelhorJogada < valorJogada){
							valorMelhorJogada = valorJogada;
						}
					}
					jogadaAtual++;
				}while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS);
			} else {
				valorMelhorJogada = tabuleiroTetralath::VITORIA+1;
				do{
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax_minucioso(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorJogada < valorMelhorJogada){
							valorMelhorJogada = valorJogada;
						}
					}
					jogadaAtual++;
				}while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS);
			}
		}
	}

	return valorMelhorJogada;
}

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
float ia::minimax_poda_alfa_beta(bool *deve_parar_param, int tipo_jogada_param, int nivel_maximo_param, int nivel_atual_param, int cor_pecas_avaliacao_param){
	int jogadaAtual;
	int valorJogada;
	int tipoJogadaFilho = (tipo_jogada_param == (int) JOGADA_MIN? (int) JOGADA_MAX : (int) JOGADA_MIN);
	int casaMelhorJogada;

	float valorMelhorJogada = tabuleiro.avaliarParaPecasDaCor(cor_pecas_avaliacao_param);

	bool valor_deveSerMaximizado = (tipo_jogada_param == JOGADA_MAX);
	bool estado_ehFolha = (valorMelhorJogada == tabuleiroTetralath::VITORIA || valorMelhorJogada == tabuleiroTetralath::PERDA);
	bool estado_jahAtingiuNivelMaximo = (nivel_atual_param == nivel_maximo_param);
	bool realizarPoda = false;

	if(!estado_ehFolha and !estado_jahAtingiuNivelMaximo) {
		if(nivel_atual_param == NIVEL_INICIAL){ //Necessário saber qual a casa de melhor jogada.
			casaMelhorJogada = 0;
			jogadaAtual=0;
			if(valor_deveSerMaximizado){
				valorMelhorJogada = tabuleiroTetralath::PERDA-1;
				
				while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS and !realizarPoda){
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax_poda_alfa_beta(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorMelhorJogada < valorJogada){
							casaMelhorJogada = jogadaAtual;
							valorMelhorJogada = valorJogada;
							realizarPoda = (valorMelhorJogada == tabuleiroTetralath::VITORIA);
						}
					}
					jogadaAtual++;
				}
			} else {
				valorMelhorJogada = tabuleiroTetralath::VITORIA+1;
				while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS and !realizarPoda){
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax_poda_alfa_beta(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorJogada < valorMelhorJogada){
							casaMelhorJogada = jogadaAtual;
							valorMelhorJogada = valorJogada;
							realizarPoda = (valorMelhorJogada == tabuleiroTetralath::PERDA);
						}
					}
					jogadaAtual++;
				}
			}
			resultado_minimax = casaMelhorJogada;
		} else { //Não é necessário saber a casa de melhor jogada, só seu valor.
			jogadaAtual=0;
			if(valor_deveSerMaximizado){
				valorMelhorJogada = tabuleiroTetralath::PERDA-1;
				while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS and !realizarPoda){
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax_poda_alfa_beta(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorMelhorJogada < valorJogada){
							valorMelhorJogada = valorJogada;
							realizarPoda = (valorMelhorJogada == tabuleiroTetralath::VITORIA);
						}
					}
					jogadaAtual++;
				}
			} else {
				valorMelhorJogada = tabuleiroTetralath::VITORIA+1;
				while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS and !realizarPoda){
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax_poda_alfa_beta(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorJogada < valorMelhorJogada){
							valorMelhorJogada = valorJogada;
							realizarPoda = (valorMelhorJogada == tabuleiroTetralath::PERDA);
						}
					}
					jogadaAtual++;
				}
			}
		}
	}

	return valorMelhorJogada;
}
float ia::minimax_poda_alfa_beta_minucioso(bool *deve_parar_param, int tipo_jogada_param, int nivel_maximo_param, int nivel_atual_param, int cor_pecas_avaliacao_param){
	int jogadaAtual;
	int valorJogada;
	int tipoJogadaFilho = (tipo_jogada_param == (int) JOGADA_MIN? (int) JOGADA_MAX : (int) JOGADA_MIN);
	int casaMelhorJogada;

	float valorMelhorJogada = tabuleiro.avaliarMinuciosamenteParaPecasDaCor(cor_pecas_avaliacao_param);

	bool valor_deveSerMaximizado = (tipo_jogada_param == JOGADA_MAX);
	bool estado_ehFolha = (valorMelhorJogada == tabuleiroTetralath::VITORIA || valorMelhorJogada == tabuleiroTetralath::PERDA);
	bool estado_jahAtingiuNivelMaximo = (nivel_atual_param == nivel_maximo_param);
	bool realizarPoda = false;

	if(!estado_ehFolha and !estado_jahAtingiuNivelMaximo) {
		if(nivel_atual_param == NIVEL_INICIAL){ //Necessário saber qual a casa de melhor jogada.
			casaMelhorJogada = 0;
			jogadaAtual=0;
			if(valor_deveSerMaximizado){
				valorMelhorJogada = tabuleiroTetralath::PERDA-1;
				
				while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS and !realizarPoda){
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax_poda_alfa_beta_minucioso(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorMelhorJogada < valorJogada){
							casaMelhorJogada = jogadaAtual;
							valorMelhorJogada = valorJogada;
							realizarPoda = (valorMelhorJogada == tabuleiroTetralath::VITORIA);
						}
					}
					jogadaAtual++;
				}
			} else {
				valorMelhorJogada = tabuleiroTetralath::VITORIA+1;
				while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS and !realizarPoda){
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax_poda_alfa_beta_minucioso(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorJogada < valorMelhorJogada){
							casaMelhorJogada = jogadaAtual;
							valorMelhorJogada = valorJogada;
							realizarPoda = (valorMelhorJogada == tabuleiroTetralath::PERDA);
						}
					}
					jogadaAtual++;
				}
			}
			resultado_minimax = casaMelhorJogada;
		} else { //Não é necessário saber a casa de melhor jogada, só seu valor.
			jogadaAtual=0;
			if(valor_deveSerMaximizado){
				valorMelhorJogada = tabuleiroTetralath::PERDA-1;
				while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS and !realizarPoda){
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax_poda_alfa_beta_minucioso(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorMelhorJogada < valorJogada){
							valorMelhorJogada = valorJogada;
							realizarPoda = (valorMelhorJogada == tabuleiroTetralath::VITORIA);
						}
					}
					jogadaAtual++;
				}
			} else {
				valorMelhorJogada = tabuleiroTetralath::VITORIA+1;
				while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS and !realizarPoda){
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax_poda_alfa_beta_minucioso(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorJogada < valorMelhorJogada){
							valorMelhorJogada = valorJogada;
							realizarPoda = (valorMelhorJogada == tabuleiroTetralath::PERDA);
						}
					}
					jogadaAtual++;
				}
			}
		}
	}

	return valorMelhorJogada;
}
float ia::minimax_poda_alfa_beta_preguicoso(bool *deve_parar_param, int tipo_jogada_param, int nivel_maximo_param, int nivel_atual_param, int cor_pecas_avaliacao_param){
	int jogadaAtual;
	int valorJogada;
	int tipoJogadaFilho = (tipo_jogada_param == (int) JOGADA_MIN? (int) JOGADA_MAX : (int) JOGADA_MIN);
	int casaMelhorJogada;

	float valorMelhorJogada = tabuleiro.avaliarPreguicosamenteParaPecasDaCor(cor_pecas_avaliacao_param);

	bool valor_deveSerMaximizado = (tipo_jogada_param == JOGADA_MAX);
	bool estado_ehFolha = (valorMelhorJogada == tabuleiroTetralath::VITORIA || valorMelhorJogada == tabuleiroTetralath::PERDA);
	bool estado_jahAtingiuNivelMaximo = (nivel_atual_param == nivel_maximo_param);
	bool realizarPoda = false;

	if(!estado_ehFolha and !estado_jahAtingiuNivelMaximo) {
		if(nivel_atual_param == NIVEL_INICIAL){ //Necessário saber qual a casa de melhor jogada.
			casaMelhorJogada = 0;
			jogadaAtual=0;
			if(valor_deveSerMaximizado){
				valorMelhorJogada = tabuleiroTetralath::PERDA-1;
				
				while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS and !realizarPoda){
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax_poda_alfa_beta_preguicoso(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorMelhorJogada < valorJogada){
							casaMelhorJogada = jogadaAtual;
							valorMelhorJogada = valorJogada;
							realizarPoda = (valorMelhorJogada == tabuleiroTetralath::VITORIA);
						}
					}
					jogadaAtual++;
				}
			} else {
				valorMelhorJogada = tabuleiroTetralath::VITORIA+1;
				while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS and !realizarPoda){
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax_poda_alfa_beta_preguicoso(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorJogada < valorMelhorJogada){
							casaMelhorJogada = jogadaAtual;
							valorMelhorJogada = valorJogada;
							realizarPoda = (valorMelhorJogada == tabuleiroTetralath::PERDA);
						}
					}
					jogadaAtual++;
				}
			}
			resultado_minimax = casaMelhorJogada;
		} else { //Não é necessário saber a casa de melhor jogada, só seu valor.
			jogadaAtual=0;
			if(valor_deveSerMaximizado){
				valorMelhorJogada = tabuleiroTetralath::PERDA-1;
				while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS and !realizarPoda){
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax_poda_alfa_beta_preguicoso(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorMelhorJogada < valorJogada){
							valorMelhorJogada = valorJogada;
							realizarPoda = (valorMelhorJogada == tabuleiroTetralath::VITORIA);
						}
					}
					jogadaAtual++;
				}
			} else {
				valorMelhorJogada = tabuleiroTetralath::VITORIA+1;
				while(!(*deve_parar_param) and jogadaAtual < tabuleiroTetralath::NUMERO_CASAS and !realizarPoda){
					if(tabuleiro.jogar(jogadaAtual)){
						valorJogada = minimax_poda_alfa_beta_preguicoso(deve_parar_param, tipoJogadaFilho, nivel_maximo_param, nivel_atual_param+1, cor_pecas_avaliacao_param);
						tabuleiro.desfazerUltimaJogada();
						if(valorJogada < valorMelhorJogada){
							valorMelhorJogada = valorJogada;
							realizarPoda = (valorMelhorJogada == tabuleiroTetralath::PERDA);
						}
					}
					jogadaAtual++;
				}
			}
		}
	}

	return valorMelhorJogada;
}