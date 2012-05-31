/*
Para compilar no windows:
	g++ main.cpp ia.cpp tabuleiroTetralath.cpp casaTabuleiroTetralath.cpp -o main
*/

#include <windows.h>
#include <process.h>
#include "jogoTetralath.h"
#include "jogadorMaquina.h"
#include "jogadorHumano.h"
using namespace std;

/*
* Jogo tetralath com IA.
*/

/**************************************************
* Declarações de métodos definidos após main.
*
*/

int escolhaCorPecasUsuario(void);
int escolhaTipoJogoUsuario(void);

void avisarAoFimDeCincoSegundos(bool *variavel_aviso_param);

bool fazerJogadaUsuario(tabuleiroTetralath *tabuleiro_param, int casaAtual_param, bool *ehVezDoUsuario_param);


/**************************************************
* Variáveis globais.
*
*/

interface_gui gui;

/**************************************************
* Função principal.
*
*/
int main(){
	gui = (*new interface_gui());
	
	jogadorTetralath *jogadorUm; 
	jogadorTetralath *jogadorDois;
	
	int corPecasUsuario;
	int tipoJogoUsuario = escolhaTipoJogoUsuario();
	
	switch(tipoJogoUsuario){
		case jogoTetralath::JOGO_HUMANO_VS_PC:
				corPecasUsuario = escolhaCorPecasUsuario();
				if(corPecasUsuario == casaTabuleiroTetralath::PECAS_BRANCAS){
					jogadorUm = new jogadorHumano(&gui, casaTabuleiroTetralath::PECAS_BRANCAS);
					jogadorDois = new jogadorMaquina(*(new ia(ia::MINIMAX)), casaTabuleiroTetralath::PECAS_PRETAS);
				} else {
					jogadorUm = new jogadorMaquina(*(new ia(ia::MINIMAX)), casaTabuleiroTetralath::PECAS_BRANCAS);
					jogadorDois = new jogadorHumano(&gui, casaTabuleiroTetralath::PECAS_PRETAS);
				}
			break;
		case jogoTetralath::JOGO_HUMANO_VS_HUMANO:
				jogadorUm = new jogadorHumano(&gui, casaTabuleiroTetralath::PECAS_BRANCAS);
				jogadorDois = new jogadorHumano(&gui, casaTabuleiroTetralath::PECAS_PRETAS);
			break;
		case jogoTetralath::JOGO_PC_VS_PC:
				jogadorUm = new jogadorMaquina(*(new ia(ia::MINIMAX)), casaTabuleiroTetralath::PECAS_BRANCAS);
				jogadorDois = new jogadorMaquina(*(new ia(ia::MINIMAX)), casaTabuleiroTetralath::PECAS_PRETAS);
			break;
	}
	
	jogoTetralath jogo = *(new jogoTetralath(*(new tabuleiroTetralath(true)), jogadorUm, jogadorDois));
	jogo.iniciarJogo(&gui);
	
	
	/*int casaCursor = 0;
	int casaJogadaIA;

	char comandoUsuario = COMANDO_SEM_ACAO;
	char movimentoUsuario = COMANDO_SEM_ACAO;

	bool usuarioEhBrancas = false;
	bool condicaoParadaMinimax = false;
	bool jogoAcabou = false;
	bool ehVezDoUsuario = true;

	ia jogadorArtificial = *(new ia());

	gui = (*new interface_gui());

	tabuleiroTetralath tabuleiro = *(new tabuleiroTetralath(true));

	Sleep(500); //Para que não saia jogando logo no início.

	if(escolhaCorPecasUsuario() == casaTabuleiroTetralath::PECAS_BRANCAS){
		ehVezDoUsuario = true;
		usuarioEhBrancas = true;
		gui.imprimirTelaTabuleiro(casaCursor, &tabuleiro);
	} else {
		usuarioEhBrancas = false;
		ehVezDoUsuario = false;
	}
*/
	/*
	* Início do jogo.
	*/
	/*while(comandoUsuario != COMANDO_FECHAR){
		Sleep(50); //Movimento não muito rápido, permitindo melhor controle.

		if(ehVezDoUsuario){
			comandoUsuario = gui.esperarComandoUsuario();
		}

		if(comandoUsuario == COMANDO_JOGAR and !jogoAcabou and ehVezDoUsuario){
			jogoAcabou = fazerJogadaUsuario(&tabuleiro, casaCursor, &ehVezDoUsuario);
		} else if((comandoUsuario == MOVIMENTO_CIMA or comandoUsuario == MOVIMENTO_BAIXO or comandoUsuario == MOVIMENTO_ESQUERDA or comandoUsuario == MOVIMENTO_DIREITA)
					and !jogoAcabou and ehVezDoUsuario){
			movimentoUsuario = comandoUsuario;
			casaCursor = tabuleiro.getIndiceCasaMovimento(movimentoUsuario, casaCursor);
		} else if(comandoUsuario == COMANDO_DESFAZER_JOGADA){
			tabuleiro.desfazerUltimaJogada(); //Desfaz jogada do usuário...
			tabuleiro.desfazerUltimaJogada(); //... e da IA.
		}

		if(!jogoAcabou){
			gui.imprimirTelaTabuleiro(casaCursor, &tabuleiro);
		}

		if(!jogoAcabou and !ehVezDoUsuario){
			avisarAoFimDeCincoSegundos(&condicaoParadaMinimax);
			gui.imprimirTelaAguardarJogada();
			if(usuarioEhBrancas){
				casaJogadaIA = jogadorArtificial.comecar_minimax(tabuleiro, &condicaoParadaMinimax, ia::JOGADA_MAX, casaTabuleiroTetralath::PECAS_PRETAS);
			} else {
				casaJogadaIA = jogadorArtificial.comecar_minimax(tabuleiro, &condicaoParadaMinimax, ia::JOGADA_MAX, casaTabuleiroTetralath::PECAS_BRANCAS);
			}
			tabuleiro.jogar(casaJogadaIA);
			ehVezDoUsuario = true;
			jogoAcabou = conferirFimDoJogo(&tabuleiro);
		}

		if(!jogoAcabou){
			gui.imprimirTelaTabuleiro(casaCursor, &tabuleiro);
		}
	}

	system("cls");
	system("color 0f");
*/
	return 0;
}


/*
* A função executa em tempo muito menor ao pedido para o aviso.
* Ela cria uma espera de 5 segundos e, ao final da espera, coloca TRUE em variavel_aviso_param.
* @param variavel_aviso_param Ponteiro cujo conteúdo será TRUE após tempo_segundos_param.
*/
unsigned int __stdcall esperar(void *variavel_aviso_param){
	Sleep(5000);
	bool *enderecoVariavelAviso = (bool*) variavel_aviso_param;
	*enderecoVariavelAviso = TRUE;
	return 0;
}
void avisarAoFimDeCincoSegundos(bool *variavel_aviso_param){
	*variavel_aviso_param = false;
	_beginthreadex(0, 0, &esperar, (void *) variavel_aviso_param, 0, 0);
}

/*
* Realiza uma jogada. Mostra a tela do resultado, se o jogo acabar.
* @param tabuleiro_param O tabuleiro no qual a jogada é feita.
* @param casaAtual_param A casa do tabuleiro na qual a jogada é feita.
* @param ehVezDoUsuario_param Não é feita verificação desta variável. Ela apenas é setada como false, caso o usuário consiga jogar.
* @param tabuleirosPassados_param Array com os tabuleiros que já foram usados, para poder desfazer jogadas.
* @param numeroJogadasFeitas_param Quantas jogadas estão no array tabuleirosPassados_param.
* @return bool indicando se o jogo acabou.
*/
bool fazerJogadaUsuario(tabuleiroTetralath *tabuleiro_param, int casaAtual_param, bool *ehVezDoUsuario_param){
	bool conseguiuJogar;
	bool jogoAcabou = false;

	int CASA_INEXISTENTE = -1;

	conseguiuJogar = tabuleiro_param->jogar(casaAtual_param);
	if(conseguiuJogar){
		*ehVezDoUsuario_param = false;
		//jogoAcabou = conferirFimDoJogo(tabuleiro_param);
	}

	return jogoAcabou;
}

/*
* Gerencia a escolha da cor de peças que o usuário deseja.
* @return Booleano indicando se o usuário deve começar (se escolheu as brancas).
*/
int escolhaCorPecasUsuario(void){
	vector<string> opcoes;
	int opcaoRealcarInterface = 0;
	char comandoUsuario;
	bool usuarioEscolheuBrancas = true;
	
	opcoes.push_back("BRANCAS");
	opcoes.push_back("PRETAS");
	interface_gui gui = *(new interface_gui());
	gui.imprimirTelaEscolha(opcoes, opcaoRealcarInterface);
	do{
		Sleep(50); //Movimento não muito rápido, permitindo melhor controle.
		comandoUsuario = gui.esperarComandoUsuario();
		if(comandoUsuario == COMANDO_PERCORRER_ALTERNATIVAS){
			if(!usuarioEscolheuBrancas){
				opcaoRealcarInterface = 0;
				usuarioEscolheuBrancas = true;
			} else {
				opcaoRealcarInterface = 1;
				usuarioEscolheuBrancas = false;
			}
		}
		gui.imprimirTelaEscolha(opcoes, opcaoRealcarInterface);
	} while(comandoUsuario != COMANDO_FECHAR and comandoUsuario != COMANDO_ESCOLHER);
	return usuarioEscolheuBrancas;
}

/*
* Gerencia a escolha do tipo de jogo que o usuário deseja.
* Os tipos de jogos são definidos em jogoTetralath.h.
* @return Inteiro indicando o tipo de jogo que o usuário quer.
*/
int escolhaTipoJogoUsuario(void){
	vector<string> opcoes;
	int opcaoRealcarInterface = 0;
	int opcaoEscolhida;
	char comandoUsuario;
	
	opcoes.push_back("HUMANO vs MAQUINA");
	opcoes.push_back("HUMANO vs HUMANO");
	opcoes.push_back("MAQUINA vs MAQUINA");
	interface_gui gui = *(new interface_gui());
	gui.imprimirTelaEscolha(opcoes, opcaoRealcarInterface);
	
	printf("1");
	do{
		Sleep(50); //Movimento não muito rápido, permitindo melhor controle.
		printf("2");
		comandoUsuario = gui.esperarComandoUsuario();
		printf("3");
		if(comandoUsuario == COMANDO_PERCORRER_ALTERNATIVAS){
			opcaoRealcarInterface++;
			if(2 < opcaoRealcarInterface){
				opcaoRealcarInterface = 0;
			}
		}
		gui.imprimirTelaEscolha(opcoes, opcaoRealcarInterface);
		printf("\n");
	} while(comandoUsuario != COMANDO_FECHAR and comandoUsuario != COMANDO_ESCOLHER);
	switch(opcaoRealcarInterface){
		case 0: opcaoEscolhida = jogoTetralath::JOGO_HUMANO_VS_PC;
			break;
		case 1: opcaoEscolhida = jogoTetralath::JOGO_HUMANO_VS_HUMANO;
			break;
		case 2: opcaoEscolhida = jogoTetralath::JOGO_PC_VS_PC;
			break;
	}
	return opcaoEscolhida;
}

