/*
Para compilar no windows:
	g++ main.cpp tabuleiroTetralath.cpp casaTabuleiroTetralath.cpp -o main
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "tabuleiroTetralath.h"
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
#define COMANDO_SEM_ACAO 'o' //Usado para inicialização. Não deve ter ação atribuída.


/**************************************************
* Declarações de métodos definidos após main.
*
*/

void imprimirCoresWindows(void);
void imprimirTelaTabuleiro(int casaAtual_param, int pecasDaVez_param, tabuleiroTetralath *tabuleiro_param);
void imprimirTelaResultado(int cor_pecas_ganhadoras_param, int casaAtual_param, tabuleiroTetralath *tabuleiro_param);
int getIndiceCasaMovimento(int movimento_param, int casa_partida_param);
bool fazerJogada(tabuleiroTetralath *tabuleiro_param, int casaAtual_param, int pecasDaVez_param);

/**************************************************
* Função principal.
*
*/
int pecasDaVez = casaTabuleiroTetralath::PECAS_BRANCAS;
int main(){
	int casaAtual = 0;

	char comandoUsuario = COMANDO_SEM_ACAO;
	char movimentoUsuario = COMANDO_SEM_ACAO;

	bool jogoAcabou = false;

	tabuleiroTetralath tabuleiro = *(new tabuleiroTetralath());

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_INTENSITY);

	while(comandoUsuario != COMANDO_FECHAR and comandoUsuario != COMANDO_FECHAR_CAPS){
		if(!jogoAcabou){
			imprimirTelaTabuleiro(casaAtual, pecasDaVez, &tabuleiro);
		}

		comandoUsuario = getc(stdin);
		if(comandoUsuario == COMANDO_JOGAR or comandoUsuario == COMANDO_JOGAR_CAPS){
			jogoAcabou = fazerJogada(&tabuleiro, casaAtual, pecasDaVez);
		} else if(comandoUsuario == MOVIMENTO_CIMA or comandoUsuario == MOVIMENTO_BAIXO or comandoUsuario == MOVIMENTO_ESQUERDA or comandoUsuario == MOVIMENTO_DIREITA
				  or comandoUsuario == MOVIMENTO_CIMA_CAPS or comandoUsuario == MOVIMENTO_BAIXO_CAPS or comandoUsuario == MOVIMENTO_ESQUERDA_CAPS 
				  or comandoUsuario == MOVIMENTO_DIREITA_CAPS){
			movimentoUsuario = comandoUsuario;
			casaAtual = getIndiceCasaMovimento(movimentoUsuario, casaAtual);
		}
	}

	system("cls");
	system("color 0f");

	return 0;
}

/*
* Realiza uma jogada. Mostra a tela do resultado, se o jogo acabar.
* @param tabuleiro_param O tabuleiro no qual a jogada é feita.
* @param casaAtual_param A casa do tabuleiro na qual a jogada é feita.
* @param pecasDaVez_param A cor das peças que farão a jogada. Esta cor é trocada caso a jogada tenha sucesso.
* @return bool indicando se o jogo acabou.
*/
bool fazerJogada(tabuleiroTetralath *tabuleiro_param, int casaAtual_param, int pecasDaVez_param){
	bool conseguiuJogar;
	bool jogoAcabou = false;

	int CASA_INEXISTENTE = -1;

	conseguiuJogar = tabuleiro_param->jogar(casaAtual_param, pecasDaVez_param);
	if(conseguiuJogar){
		(pecasDaVez_param == casaTabuleiroTetralath::PECAS_BRANCAS) ? 
			pecasDaVez = casaTabuleiroTetralath::PECAS_PRETAS : pecasDaVez = casaTabuleiroTetralath::PECAS_BRANCAS;
		if(tabuleiro_param->pecasDaMesmaCorGanharam(tabuleiro_param->recuperarNomeCasaUltimaJogada())){
			jogoAcabou = true;
			imprimirTelaResultado(tabuleiro_param->recuperarCorPecasUltimaJogada(), CASA_INEXISTENTE, tabuleiro_param);
		} else if(tabuleiro_param->pecasDaMesmaCorPerderam(tabuleiro_param->recuperarNomeCasaUltimaJogada())){
			jogoAcabou = true;
			tabuleiro_param->recuperarCorPecasUltimaJogada() == casaTabuleiroTetralath::PECAS_BRANCAS?
				imprimirTelaResultado(casaTabuleiroTetralath::PECAS_PRETAS, CASA_INEXISTENTE, tabuleiro_param) : imprimirTelaResultado(casaTabuleiroTetralath::PECAS_BRANCAS, CASA_INEXISTENTE, tabuleiro_param);
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
* Imprime a tela do jogo.
* @param casaAtual_param A casa em que está o cursor.
* @param pecasDaVez_param A cor das peças que estão jogando.
* @param tabuleiro_param O tabuleiro que será impresso.
*/
void imprimirTelaTabuleiro(int casaAtual_param, int pecasDaVez_param, tabuleiroTetralath *tabuleiro_param){
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

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
	printf("[W] DIAGONAL ESQUERDA SUPERIOR (CIMA) [S] DIAGONAL DIREITA INFEROR (BAIXO)\n");
	printf("[A] ESQUERDA [D] DIREITA\n");
	printf("[J] JOGAR\n");
	printf("[Q] SAIR\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
}

/*
* Imprime a tela do resultado de um jogo.
* @param cor_pecas_ganhadoras_param A cor das peças que ganharam o jogo.
* @param casaAtual_param A casa em que está o cursor.
* @param tabuleiro_param O tabuleiro que será impresso.
*/
void imprimirTelaResultado(int cor_pecas_ganhadoras_param, int casaAtual_param, tabuleiroTetralath *tabuleiro_param){
	system("cls");
	printf("\t\t\t\t TEXTLATH\n\n");
	printf("\t\t\t O tetralath em modo texto!\n");

	printf("\n\n\t\t\t\tFim do jogo!");

	printf("\n\n\n\n");
	tabuleiro_param->imprimir(casaAtual_param);
	printf("\n\n\n\n");

	if(cor_pecas_ganhadoras_param == casaTabuleiroTetralath::PECAS_BRANCAS){
		printf("\t\t\tAs pecas BRANCAS ganharam!");
	} else {
		printf("\t\t\tAs pecas PRETAS ganharam!");
	}
	printf("\n\n\n\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
	printf("[Q] SAIR\n");
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