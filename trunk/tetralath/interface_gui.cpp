#include "interface_gui.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

/*************************************************************
* À partir daqui, todos os métodos são PÚBLICOS
**************************************************************/
/*
* Construtor da classe.
*/
interface_gui::interface_gui(){
}

/*
* Espera por comando do usuário e o retorna, quando for feito.
* @return O comando digitado pelo usuário. Não retorna comandos com CAPS, prefere sempre sua versão em lower case.
* Obs.: Código encontrado em http://www.cplusplus.com/forum/windows/6632/
*		A forma usada anteriormente (GetAsyncKeyState) causava erros.
*/
char interface_gui::esperarComandoUsuario(void){
	DWORD        mode;          						/* Preserved console mode */
    INPUT_RECORD event;         						/* Input event */
    HANDLE hstdin = GetStdHandle( STD_INPUT_HANDLE );	/* Get the console input handle */
    char comandoUsuario = COMANDO_SEM_ACAO;

	GetConsoleMode( hstdin, &mode ); 					/* Preserve the original console mode */
    SetConsoleMode( hstdin, 0 ); 						/* Set to no line-buffering, no echo, no special-key-processing */

	while(comandoUsuario == COMANDO_SEM_ACAO){
		if (WaitForSingleObject( hstdin, 0 ) == WAIT_OBJECT_0){
			DWORD count;  /* ignored */
				
            ReadConsoleInput( hstdin, &event, 1, &count );  /* Get the input event */
		
			if ((event.EventType == KEY_EVENT) &&  event.Event.KeyEvent.bKeyDown){
                switch (event.Event.KeyEvent.wVirtualKeyCode){
                    case VK_RETURN: comandoUsuario = COMANDO_ESCOLHER;
                        break;
                    case VK_TAB: comandoUsuario = COMANDO_PERCORRER_ALTERNATIVAS;
						break;
					case VK_LEFT:
					case MOVIMENTO_ESQUERDA:
					case MOVIMENTO_ESQUERDA_CAPS: comandoUsuario = MOVIMENTO_ESQUERDA;
						break;
					case VK_UP:
					case MOVIMENTO_CIMA:
					case MOVIMENTO_CIMA_CAPS: comandoUsuario = MOVIMENTO_CIMA;
						break;
					case VK_RIGHT:
					case MOVIMENTO_DIREITA:
					case MOVIMENTO_DIREITA_CAPS: comandoUsuario = MOVIMENTO_DIREITA;
						break;
					case VK_DOWN:
					case MOVIMENTO_BAIXO:
					case MOVIMENTO_BAIXO_CAPS: comandoUsuario = MOVIMENTO_BAIXO;
						break;
					case COMANDO_JOGAR:
					case COMANDO_JOGAR_CAPS:
					case COMANDO_JOGAR_ALTERNATIVO: comandoUsuario = COMANDO_JOGAR;
						break;
					case COMANDO_FECHAR:
					case COMANDO_FECHAR_CAPS: comandoUsuario = COMANDO_FECHAR;
						break;
					case COMANDO_DESFAZER_JOGADA:
					case COMANDO_DESFAZER_JOGADA_CAPS: comandoUsuario = COMANDO_DESFAZER_JOGADA;
						break;
                }
			}
        }
	}

	return comandoUsuario;
}

/*
* Imprime a tela inicial, que permite escolha da cor das peças do usuário.
* @param opcao_realcar A opção COMANDO_ESCOLHER_BRANCAS ou COMANDO_ESCOLHER_PRETAS que deve ficar realçada.
*/
void interface_gui::imprimirTelaInicio(char opcao_realcar){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_INTENSITY);
	system("cls");
	printf("\t\t\t BEM-VINDO AO TEXTLATH\n\n");
	printf("\t\t\t O tetralath em modo texto!\n");

	printf("\n\n");
	printf("\t\t Escolha a cor que deseja usar.");
	printf("\n\n");
	if(opcao_realcar == COMANDO_ESCOLHER_BRANCAS){
		printf("\t\t\t");imprimirComando("BRANCAS");printf("\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		printf("\t\t\t[PRETAS]\n");
	} else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		printf("\t\t\t[BRANCAS]\n");
		printf("\t\t\t");imprimirComando("PRETAS");printf("\n");
	}
	printf("\n\n\n\n");

	//printf(COR_AZUL_FRACA_LINUX);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
	imprimirComando("TAB");
	printf(" PERCORRER ALTERNATIVAS\n");
	imprimirComando("ENTER");
	printf(" ESCOLHER\n");
	imprimirComando("Q");
	printf(" SAIR\n");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
}

/*
* Imprime a tela do jogo.
* @param casaAtual_param A casa em que está o cursor.
* @param pecasDaVez_param A cor das peças que estão jogando.
* @param tabuleiro_param O tabuleiro que será impresso.
*/
void interface_gui::imprimirTelaTabuleiro(int casaAtual_param, int pecasDaVez_param, tabuleiroTetralath *tabuleiro_param){
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
	printf(" ou ");
	imprimirComando("SETA CIMA");
	printf(" MOVER PARA CASA NA DIAGONAL ESQUERDA SUPERIOR (CIMA)\n");

	imprimirComando("S");
	printf(" ou ");
	imprimirComando("SETA BAIXO");
	printf(" MOVER PARA CASA NA DIAGONAL DIREITA INFEROR (BAIXO)\n");

	imprimirComando("A");
	printf(" ou ");
	imprimirComando("SETA ESQUERDA");
	printf(" MOVER PARA CASA A ESQUERDA\n");
	
	imprimirComando("D");
	printf(" ou ");
	imprimirComando("SETA DIREITA");
	printf(" MOVER PARA CASA A DIREITA\n");

	imprimirComando("J");
	printf(" ou ");
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
void interface_gui::imprimirTelaResultado(int cor_pecas_ganhadoras_param, int casaAtual_param, tabuleiroTetralath *tabuleiro_param){
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
void interface_gui::imprimirCoresWindows(void){
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

/*************************************************************
* À partir daqui, todos os métodos são PRIVADOS
**************************************************************/

/*
* Imprime um comando com letras brancas em colchetes.
* @param comando_param Comando a imprimir.
*/
void interface_gui::imprimirComando(string comando_param){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
	printf("[");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << comando_param;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
	printf("]");
}