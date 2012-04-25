/*
Para compilar no windows:
	g++ main.cpp ia.cpp tabuleiroTetralath.cpp casaTabuleiroTetralath.cpp -o main
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <process.h>
#include "ia.h"
using namespace std;

/*
* Jogo tetralath com IA.
*/


/**************************************************
* Declarações de comandos da interface do jogo.
*
*/

#define MOVIMENTO_CIMA 'w' //Movimenta para o vizinho A, se existir.
#define MOVIMENTO_CIMA_CAPS 'W'
#define MOVIMENTO_BAIXO 's' //Movimenta para o vizinho F, se existir.
#define MOVIMENTO_BAIXO_CAPS 'S'
#define MOVIMENTO_ESQUERDA 'a' //Movimenta para o vizinho C, se existir.
#define MOVIMENTO_ESQUERDA_CAPS 'A'
#define MOVIMENTO_DIREITA 'd' //Movimenta para o vizinho D, se existir.
#define MOVIMENTO_DIREITA_CAPS 'D'
#define COMANDO_FECHAR 'q' //Termina a aplicação.
#define COMANDO_FECHAR_CAPS 'Q'
#define COMANDO_JOGAR 'j' //Faz uma jogada na posição em que estiver, se possível.
#define COMANDO_JOGAR_CAPS 'J'
#define COMANDO_JOGAR_ALTERNATIVO ' '
#define COMANDO_DESFAZER_JOGADA 'z' //Desfaz a última jogada.
#define COMANDO_DESFAZER_JOGADA_CAPS 'Z' 
#define COMANDO_SEM_ACAO 'o' //Usado para inicialização. Não deve ter ação atribuída.


/**************************************************
* Declarações de métodos definidos após main.
*
*/

char esperarComandoUsuario(void);
void avisarAoFimDeCincoSegundos(bool *variavel_aviso_param);
void imprimirCoresWindows(void);
void imprimirTelaTabuleiro(int casaAtual_param, int pecasDaVez_param, tabuleiroTetralath *tabuleiro_param);
void imprimirTelaResultado(int cor_pecas_ganhadoras_param, int casaAtual_param, tabuleiroTetralath *tabuleiro_param);
int getIndiceCasaMovimento(int movimento_param, int casa_partida_param);
bool fazerJogadaUsuario(tabuleiroTetralath *tabuleiro_param, int casaAtual_param, int pecasDaVez_param, bool *ehVezDoUsuario_param,
						tabuleiroTetralath* tabuleirosPassados_param[], int *numeroJogadasFeitas_param);


/**************************************************
* Variáveis globais.
*
*/

int pecasDaVez = casaTabuleiroTetralath::PECAS_BRANCAS;

/**************************************************
* Função principal.
*
*/
int main(){
	int casaCursor = 0;
	int numeroJogadasFeitas = 0;

	char comandoUsuario = COMANDO_SEM_ACAO;
	char movimentoUsuario = COMANDO_SEM_ACAO;

	bool condicaoParadaMinimax = false;
	bool jogoAcabou = false;
	bool ehVezDoUsuario = true;

	ia jogadorArtificial = *(new ia());

	tabuleiroTetralath tabuleiro = *(new tabuleiroTetralath());
	tabuleiroTetralath* tabuleirosPassados[tabuleiroTetralath::NUMERO_CASAS+1];

	Sleep(500); //Para que não saia jogando logo no início.

	while(comandoUsuario != COMANDO_FECHAR){
		Sleep(50); //Movimento não muito rápido, permitindo melhor controle.
		if(!jogoAcabou){
			imprimirTelaTabuleiro(casaCursor, pecasDaVez, &tabuleiro);
			comandoUsuario = esperarComandoUsuario();
		}

		if(comandoUsuario != COMANDO_DESFAZER_JOGADA){
			if(comandoUsuario == COMANDO_JOGAR and !jogoAcabou and ehVezDoUsuario){
				jogoAcabou = fazerJogadaUsuario(&tabuleiro, casaCursor, pecasDaVez, &ehVezDoUsuario, tabuleirosPassados, &numeroJogadasFeitas);
				ehVezDoUsuario = true; // DEBUG
			} else if((comandoUsuario == MOVIMENTO_CIMA or comandoUsuario == MOVIMENTO_BAIXO or comandoUsuario == MOVIMENTO_ESQUERDA or comandoUsuario == MOVIMENTO_DIREITA)
					and !jogoAcabou and ehVezDoUsuario){
				movimentoUsuario = comandoUsuario;
				casaCursor = getIndiceCasaMovimento(movimentoUsuario, casaCursor);
			}
	
			if(!jogoAcabou and !ehVezDoUsuario){
				imprimirTelaTabuleiro(casaCursor, pecasDaVez, &tabuleiro);
				condicaoParadaMinimax = false;
				avisarAoFimDeCincoSegundos(&condicaoParadaMinimax);
				tabuleirosPassados[numeroJogadasFeitas] = new tabuleiroTetralath(tabuleiro);
				//Atenção! A jogada é feita dentro de comecar_minimax.
				//tabuleiro = jogadorArtificial.comecar_minimax(tabuleiro, &condicaoParadaMinimax, ia::JOGADA_MAX, casaTabuleiroTetralath::PECAS_PRETAS);
				numeroJogadasFeitas++;
				ehVezDoUsuario = true;
			}
		} else {
			if(0 < numeroJogadasFeitas){
				tabuleiro = *(tabuleirosPassados[numeroJogadasFeitas - 1]);
				numeroJogadasFeitas--;
				(pecasDaVez == casaTabuleiroTetralath::PECAS_BRANCAS) ? 
					pecasDaVez = casaTabuleiroTetralath::PECAS_PRETAS : pecasDaVez = casaTabuleiroTetralath::PECAS_BRANCAS;
			}
		}
	}

	system("cls");
	system("color 0f");

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
	_beginthreadex(0, 0, &esperar, (void *) variavel_aviso_param, 0, 0);
	/*
	pid_t pid;
	pid_t pid_filho = 0;
	pid = fork();
	if(pid == pid_filho){
		Sleep(5000);
		*variavel_aviso_param = true;
		exit(0);
	}
	*/
}
/*
* Passou no teste se os tempos estiverem certos e (x) 1<=x<=6 não repetir.
* Não pode repetir, pois apenas o pai pode sair de avisarAoFimDeCincoSegundos.
* Os filhos devem ser terminados, de modo que não seja possível voltarem à main!
*/
/*void testesAvisarAoFimDeCincoSegundos(){
	bool avisoUm = FALSE;
	bool avisoDois = FALSE;
	bool avisoTres = FALSE;
	
	avisarAoFimDeCincoSegundos(&avisoUm);
	printf("(1) avisoUm contém %d\n", avisoUm);
	avisarAoFimDeCincoSegundos(&avisoDois);
	printf("(2) avisoDois contém %d\n", avisoDois);
	avisarAoFimDeCincoSegundos(&avisoTres);
	printf("(3) avisoTres contém %d\n", avisoTres);
	system("pause");
	printf("(4) avisoUm contém %d\n", avisoUm);
	printf("(5) avisoDois contém %d\n", avisoDois);
	printf("(6) avisoTres contém %d\n", avisoTres);
	system("pause");
}*/

/*
* Espera por comando do usuário e o retorna, quando for feito.
* @return O comando digitado pelo usuário. Não retorna comandos com CAPS, prefere sempre sua versão em lower case.
*/
char esperarComandoUsuario(void){
	char comandoUsuario = COMANDO_SEM_ACAO;

	while(comandoUsuario == COMANDO_SEM_ACAO){
		if(GetAsyncKeyState(VK_LEFT) or GetAsyncKeyState(MOVIMENTO_ESQUERDA) or GetAsyncKeyState(MOVIMENTO_ESQUERDA_CAPS)){
			comandoUsuario = MOVIMENTO_ESQUERDA;
		} else if(GetAsyncKeyState(VK_UP) or GetAsyncKeyState(MOVIMENTO_CIMA) or GetAsyncKeyState(MOVIMENTO_CIMA_CAPS)){
			comandoUsuario = MOVIMENTO_CIMA;
		} else if(GetAsyncKeyState(VK_RIGHT) or GetAsyncKeyState(MOVIMENTO_DIREITA) or GetAsyncKeyState(MOVIMENTO_DIREITA_CAPS)){
			comandoUsuario = MOVIMENTO_DIREITA;
		} else if(GetAsyncKeyState(VK_DOWN) or GetAsyncKeyState(MOVIMENTO_BAIXO) or GetAsyncKeyState(MOVIMENTO_BAIXO_CAPS)){
			comandoUsuario = MOVIMENTO_BAIXO;
		} else if(GetAsyncKeyState(COMANDO_JOGAR) or GetAsyncKeyState(COMANDO_JOGAR_CAPS) or GetAsyncKeyState(COMANDO_JOGAR_ALTERNATIVO)){
			comandoUsuario = COMANDO_JOGAR;
		} else if(GetAsyncKeyState(COMANDO_FECHAR) or GetAsyncKeyState(COMANDO_FECHAR_CAPS)){
			comandoUsuario = COMANDO_FECHAR;
		} else if(GetAsyncKeyState(COMANDO_DESFAZER_JOGADA) or GetAsyncKeyState(COMANDO_DESFAZER_JOGADA_CAPS)){
			comandoUsuario = COMANDO_DESFAZER_JOGADA;
		}
	}

	return comandoUsuario;
}

/*
* Realiza uma jogada. Mostra a tela do resultado, se o jogo acabar.
* @param tabuleiro_param O tabuleiro no qual a jogada é feita.
* @param casaAtual_param A casa do tabuleiro na qual a jogada é feita.
* @param pecasDaVez_param A cor das peças que farão a jogada. Esta cor é trocada caso a jogada tenha sucesso.
* @param ehVezDoUsuario_param Não é feita verificação desta variável. Ela apenas é setada como false, caso o usuário consiga jogar.
* @param tabuleirosPassados_param Array com os tabuleiros que já foram usados, para poder desfazer jogadas.
* @param numeroJogadasFeitas_param Quantas jogadas estão no array tabuleirosPassados_param.
* @return bool indicando se o jogo acabou.
*/
bool fazerJogadaUsuario(tabuleiroTetralath *tabuleiro_param, int casaAtual_param, int pecasDaVez_param, bool *ehVezDoUsuario_param,
						tabuleiroTetralath* tabuleirosPassados_param[], int *numeroJogadasFeitas_param){
	bool conseguiuJogar;
	bool jogoAcabou = false;

	int CASA_INEXISTENTE = -1;

	tabuleirosPassados_param[*numeroJogadasFeitas_param] = new tabuleiroTetralath(tabuleiro_param);

	conseguiuJogar = tabuleiro_param->jogar(casaAtual_param, pecasDaVez_param);
	if(conseguiuJogar){
		*numeroJogadasFeitas_param = *numeroJogadasFeitas_param + 1;
		*ehVezDoUsuario_param = false;
		(pecasDaVez_param == casaTabuleiroTetralath::PECAS_BRANCAS) ? 
			pecasDaVez = casaTabuleiroTetralath::PECAS_PRETAS : pecasDaVez = casaTabuleiroTetralath::PECAS_BRANCAS;
		if(tabuleiro_param->pecasDaMesmaCorGanharam(tabuleiro_param->recuperarNomeCasaUltimaJogada())){
			jogoAcabou = true;
			imprimirTelaResultado(tabuleiro_param->recuperarCorPecasUltimaJogada(), CASA_INEXISTENTE, tabuleiro_param);
		} else if(tabuleiro_param->pecasDaMesmaCorPerderam(tabuleiro_param->recuperarNomeCasaUltimaJogada())){
			jogoAcabou = true;
			tabuleiro_param->recuperarCorPecasUltimaJogada() == casaTabuleiroTetralath::PECAS_BRANCAS?
				imprimirTelaResultado(casaTabuleiroTetralath::PECAS_PRETAS, CASA_INEXISTENTE, tabuleiro_param) : imprimirTelaResultado(casaTabuleiroTetralath::PECAS_BRANCAS, CASA_INEXISTENTE, tabuleiro_param);
		} else if(tabuleiro_param->houveEmpate()){
			imprimirTelaResultado(casaTabuleiroTetralath::PECAS_PRETAS+casaTabuleiroTetralath::PECAS_BRANCAS+5, CASA_INEXISTENTE, tabuleiro_param);

		}
	}

	return jogoAcabou;
}

/*
* Dado um movimento e um índice de casa, decide para qual índice de casa o cursor do tabuleiro deve ser movido.
* @param movimento_param Caractere que decide o índice.
* @param casa_partida_param Casa da qual deseja-se obter o vizinho.
* @return Índice a ser passado para imprimir. Se não houver vizinho para o movimento, retorna a casa passada como argumento.
*/
int getIndiceCasaMovimento(int movimento_param, int casa_partida_param){
	int casa_destino = casa_partida_param;
	if(movimento_param == MOVIMENTO_CIMA or movimento_param == MOVIMENTO_CIMA_CAPS){ //Movimenta para o vizinho A, se existir.
		if(casa_partida_param == 0 or casa_partida_param == 1 or casa_partida_param == 2 or casa_partida_param == 3 or casa_partida_param == 4 or
		   casa_partida_param == 5 or casa_partida_param == 11 or casa_partida_param == 18 or casa_partida_param == 26){
			casa_destino = casa_partida_param;
		} else if(casa_partida_param <= 10){
			casa_destino = casa_partida_param - 6;
		} else if(casa_partida_param <= 17){
			casa_destino = casa_partida_param - 7;
		} else if(casa_partida_param <= 25){
			casa_destino = casa_partida_param - 8;
		} else if(casa_partida_param <= 34){
			casa_destino = casa_partida_param - 9;
		} else if(casa_partida_param <= 42){
			casa_destino = casa_partida_param - 9;
		} else if(casa_partida_param <= 49){
			casa_destino = casa_partida_param - 8;
		} else if(casa_partida_param <= 55){
			casa_destino = casa_partida_param - 7;
		} else if(casa_partida_param <= 60){
			casa_destino = casa_partida_param - 6;
		}
	} else if(movimento_param == MOVIMENTO_BAIXO or movimento_param == MOVIMENTO_BAIXO_CAPS){ //Movimenta para o vizinho F, se existir.
		if(casa_partida_param == 56 or casa_partida_param == 57 or casa_partida_param == 58 or casa_partida_param == 59 or casa_partida_param == 60 or
		   casa_partida_param == 34 or casa_partida_param == 42 or casa_partida_param == 49 or casa_partida_param == 55){
			casa_destino = casa_partida_param;
		} else if(casa_partida_param <= 4){
			casa_destino = casa_partida_param + 6;
		} else if(casa_partida_param <= 10){
			casa_destino = casa_partida_param + 7;
		} else if(casa_partida_param <= 17){
			casa_destino = casa_partida_param + 8;
		} else if(casa_partida_param <= 25){
			casa_destino = casa_partida_param + 9;
		} else if(casa_partida_param <= 34){
			casa_destino = casa_partida_param + 9;
		} else if(casa_partida_param <= 42){
			casa_destino = casa_partida_param + 8;
		} else if(casa_partida_param <= 49){
			casa_destino = casa_partida_param + 7;
		} else if(casa_partida_param <= 55){
			casa_destino = casa_partida_param + 6;
		}
	} else if(movimento_param == MOVIMENTO_ESQUERDA or movimento_param == MOVIMENTO_ESQUERDA_CAPS){ //Movimenta para o vizinho C, se existir.
		if(casa_partida_param == 0 or casa_partida_param == 5 or casa_partida_param == 11 or casa_partida_param == 18 or casa_partida_param == 26 or
		   casa_partida_param == 35 or casa_partida_param == 43 or casa_partida_param == 50 or casa_partida_param == 56){
			casa_destino = casa_partida_param;
		} else {
			casa_destino = casa_partida_param - 1;
		}
	} else if(movimento_param == MOVIMENTO_DIREITA or movimento_param == MOVIMENTO_DIREITA_CAPS){ //Movimenta para o vizinho D, se existir.
		if(casa_partida_param == 4 or casa_partida_param == 10 or casa_partida_param == 17 or casa_partida_param == 25 or casa_partida_param == 34 or
		   casa_partida_param == 42 or casa_partida_param == 49 or casa_partida_param == 55 or casa_partida_param == 60){
			casa_destino = casa_partida_param;
		} else {
			casa_destino = casa_partida_param + 1;
		}
	} else {
		casa_destino = casa_partida_param;
	}
	return casa_destino;
}

/*
* Imprime um comando com letras brancas em colchetes.
* É auxiliar da função imprimirTelaTabuleiro.
* @param comando_param Comando a imprimir.
*/
void imprimirComando(string comando_param){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
	printf("[");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << comando_param;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
	printf("]");
}
/*
* Imprime a tela do jogo.
* @param casaAtual_param A casa em que está o cursor.
* @param pecasDaVez_param A cor das peças que estão jogando.
* @param tabuleiro_param O tabuleiro que será impresso.
*/
void imprimirTelaTabuleiro(int casaAtual_param, int pecasDaVez_param, tabuleiroTetralath *tabuleiro_param){
	//printf(COR_BRANCA_LINUX);	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_INTENSITY);
	system("cls");
	printf("\t\t\t\t TEXTLATH\n\n");
	printf("\t\t\t O tetralath em modo texto!\n");

	if(pecasDaVez_param == casaTabuleiroTetralath::PECAS_BRANCAS){
		printf("\n\n\t\t\tEh a vez das pecas BRANCAS");
	} else {
		printf("\n\n\t\t\tEh a vez das pecas PRETAS");
	}

	printf("\n\n\n\n");
	tabuleiro_param->imprimir(casaAtual_param);
	printf("\n\n\n\n");

	//printf(COR_AZUL_FRACA_LINUX);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
	imprimirComando("W");
	printf("ou ");
	imprimirComando("SETA CIMA");
	printf(" MOVER PARA CASA NA DIAGONAL ESQUERDA SUPERIOR (CIMA)\n");

	imprimirComando("S");
	printf("ou ");
	imprimirComando("SETA BAIXO");
	printf(" MOVER PARA CASA NA DIAGONAL DIREITA INFEROR (BAIXO)\n");

	imprimirComando("A");
	printf("ou ");
	imprimirComando("SETA ESQUERDA");
	printf(" MOVER PARA CASA A ESQUERDA\n");
	
	imprimirComando("D");
	printf("ou ");
	imprimirComando("SETA DIREITA");
	printf(" MOVER PARA CASA A DIREITA\n");

	imprimirComando("J");
	printf("ou ");
	imprimirComando("BARRA ESPACO");
	printf(" JOGAR\n");

	imprimirComando("Z");
	printf(" DESFAZER ULTIMA JOGADA\n");

	imprimirComando("Q");
	printf(" SAIR\n");


	//printf(COR_BRANCA_LINUX);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
}

/*
* Imprime a tela do resultado de um jogo.
* @param cor_pecas_ganhadoras_param A cor das peças que ganharam o jogo. Qualquer valor diferente de PECAS_PRETAS e PECAS_BRANCAS é empate.
* @param casaAtual_param A casa em que está o cursor.
* @param tabuleiro_param O tabuleiro que será impresso.
*/
void imprimirTelaResultado(int cor_pecas_ganhadoras_param, int casaAtual_param, tabuleiroTetralath *tabuleiro_param){
	system("cls");
	//printf(COR_BRANCA_LINUX);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("\t\t\t\t TEXTLATH\n\n");
	printf("\t\t\t O tetralath em modo texto!\n");

	printf("\n\n\t\t\t\tFim do jogo!");

	printf("\n\n\n\n");
	tabuleiro_param->imprimir(casaAtual_param);
	printf("\n\n\n\n");

	//printf(COR_BRANCA_LINUX);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_INTENSITY);
	if(cor_pecas_ganhadoras_param == casaTabuleiroTetralath::PECAS_BRANCAS){
		printf("\t\t\tAs pecas BRANCAS ganharam!");
	} else if(cor_pecas_ganhadoras_param == casaTabuleiroTetralath::PECAS_PRETAS){
		printf("\t\t\tAs pecas PRETAS ganharam!");
	} else {
		printf("\t\t\t   Houve empate!");
	}
	printf("\n\n\n\n");

	//printf(COR_AZUL_FRACA_LINUX);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
	printf("[Q] SAIR\n");
	//printf(COR_BRANCA_LINUX);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
}


/*
* Imprime todas as cores possíveis no prompt no windows (Só funciona no windows!!!!!!).
*/
void imprimirCoresWindows(void){
	system("cls");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	printf("FOREGROUND_RED\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
	printf("FOREGROUND_BLUE\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	printf("FOREGROUND_GREEN\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
	printf("FOREGROUND_RED | FOREGROUND_BLUE\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
	printf("FOREGROUND_RED | FOREGROUND_GREEN\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN);
	printf("FOREGROUND_BLUE | FOREGROUND_GREEN\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	printf("FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("FOREGROUND_RED | FOREGROUND_INTENSITY\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf("FOREGROUND_BLUE | FOREGROUND_INTENSITY\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("FOREGROUND_GREEN | FOREGROUND_INTENSITY\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf("FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
	printf("BACKGROUND_RED\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
	printf("BACKGROUND_BLUE\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
	printf("BACKGROUND_GREEN\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_BLUE);
	printf("BACKGROUND_RED | BACKGROUND_BLUE\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN);
	printf("BACKGROUND_RED | BACKGROUND_GREEN\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN);
	printf("BACKGROUND_BLUE | BACKGROUND_GREEN\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
	printf("BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_INTENSITY);
	printf("BACKGROUND_RED | BACKGROUND_INTENSITY\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	printf("BACKGROUND_BLUE | BACKGROUND_INTENSITY\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	printf("BACKGROUND_GREEN | BACKGROUND_INTENSITY\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
	printf("BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	printf("BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	printf("BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	printf("BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
