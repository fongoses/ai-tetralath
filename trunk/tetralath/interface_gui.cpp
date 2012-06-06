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
	DWORD mode;											/* Preserved console mode */
	INPUT_RECORD events[128];							/* Input event */
	HANDLE hstdin = GetStdHandle( STD_INPUT_HANDLE );	/* Get the console input handle */
	char comandoUsuario = COMANDO_SEM_ACAO;
	int indice_evento_aceitavel;
	int i=0;
	bool haEventoAceitavel = false;

	GetConsoleMode( hstdin, &mode ); 					/* Preserve the original console mode */
	SetConsoleMode( hstdin, 0 ); 						/* Set to no line-buffering, no echo, no special-key-processing */

	while(comandoUsuario == COMANDO_SEM_ACAO){
		
		if (WaitForSingleObject( hstdin, 0 ) == WAIT_OBJECT_0){
			DWORD count;  /* ignored */

			ReadConsoleInput( hstdin, events, 128, &count );  /* Get the input event */
			
			haEventoAceitavel = false;
			
			if(0 < count){
				for(i=0; i<=count; i++){
					if(events[i].EventType == KEY_EVENT &&  !events[i].Event.KeyEvent.bKeyDown){
						indice_evento_aceitavel = i;
						haEventoAceitavel = true;
					}
				}
			}
			
			if (haEventoAceitavel){
				switch (events[indice_evento_aceitavel].Event.KeyEvent.wVirtualKeyCode){
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
					case COMANDO_DEBUG_AVALIAR: comandoUsuario = COMANDO_DEBUG_AVALIAR;
						break;
				}
			}
		}
	}
	return comandoUsuario;
}

/*
* Imprime uma tela que permite escolha entre várias opções.
* @param _opcoes Array de opções que o usuário possui.
* @param _opcaoEscolhida O índice, no array, da opção escolhida. Se exceder os limites do array, será realçada a última.
*/
void interface_gui::imprimirTelaEscolha(vector<string> _opcoes, int _opcaoEscolhida){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_INTENSITY);
	system("cls");
	imprimirTextoCentralizado("BEM-VINDO AO TEXTLATH");
	printf("\n\n");
	imprimirTextoCentralizado("O tetralath em modo texto!");
	printf("\n");

	printf("\n\n");
	imprimirTextoCentralizado("Escolha uma opcao.");
	printf("\n\n");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
	for (vector<string>::iterator iteradorOpcoes = _opcoes.begin(); iteradorOpcoes!=_opcoes.end(); ++iteradorOpcoes) {
		if(iteradorOpcoes - _opcoes.begin() == _opcaoEscolhida){
			printf("\t\t\t\t");imprimirComando(*iteradorOpcoes);printf("\n");
		} else {
			printf("\t\t\t\t[");printf("%s",iteradorOpcoes->c_str());printf("]\n");
		}
	}
	printf("\n\n\n\n");

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
* Imprime uma tela de escolha em que cada opção é um submenu que pode ser acessado com [ENTER].
* Recebe um objeto menu e nele define as opções selecionadas.
* @param _menu Vector de vectors de vectors de strings. Cada vector dentro de um vector é um submenu de opções, as quais são strings.
*			   Cada vector dentro de um vector é exibido em uma mesma linha. O vector seguinte é exibido em linha seguinte.
*			   A primeira opção de um submenu é a escolhida por default e pode ser mudada utilizando [ENTER] + direcional.
*			   Para selecionar a opção escolhida, utiliza-se novo [ENTER].
* Exemplo:
*	imprimirTelaMenus(vector(
*						vector(vector("maquina","humano"), vector("maquina", "humano")),
*						vector(vector("brancas","pretas"), vector("brancas", "pretas"))) 
*		= vector("brancas", "maquina")
*	e é exibido como:
*	[maquina] [maquina]
*	[brancas] [brancas]
*/
void interface_gui::imprimirTelaMenus(menu *_menu){
	char comandoUsuario;
	char* comando = new char[1];
	string comandoString;


	do{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_INTENSITY);
		system("cls");
		imprimirTextoCentralizado("BEM-VINDO AO TEXTLATH");
		printf("\n\n");
		imprimirTextoCentralizado("O tetralath em modo texto!");
		printf("\n");

		printf("\n\n");
		imprimirTextoCentralizado("Escolha uma opcao.");
		printf("\n\n");

		_menu->imprimir();

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		comando[0]=30;comando[1]='\0';comandoString = *(new string(comando));
		imprimirComando(comandoString);
		printf(" ou ");
		comando[0]=31;comando[1]='\0';comandoString = *(new string(comando));
		imprimirComando(comandoString);
		printf(" ESCOLHER ALTERNATIVA\n");
		imprimirComando("ENTER");
		printf(" FINALIZAR SELECAO\n");
		imprimirComando("TAB");
		printf(" ou ");
		comando[0]=16;comando[1]='\0';comandoString = *(new string(comando));
		imprimirComando(comandoString);
		printf(" ou ");
		comando[0]=17;comando[1]='\0';comandoString = *(new string(comando));
		imprimirComando(comandoString);
		printf(" NAVEGAR ENTRE OPCOES\n");
		imprimirComando("Q");
		printf(" SAIR\n");
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);

		Sleep(50); //Movimento não muito rápido, permitindo melhor controle.
		comandoUsuario = esperarComandoUsuario();

		switch(comandoUsuario){
			case COMANDO_PERCORRER_ALTERNATIVAS: 
			case MOVIMENTO_DIREITA: _menu->selecionarOpcaoSeguinte();
				break;
			case MOVIMENTO_ESQUERDA: _menu->selecionarOpcaoAnterior(); 
				break;
			case MOVIMENTO_CIMA: _menu->selecionarAlternativaSeguinte();
				break;
			case MOVIMENTO_BAIXO: _menu->selecionarAlternativaAnterior();
				break;
		}
	}while(comandoUsuario != COMANDO_FECHAR and comandoUsuario != COMANDO_ESCOLHER);
}

/*
* Imprime a tela do jogo.
* @param casaAtual_param A casa em que está o cursor.
* @param tabuleiro_param O tabuleiro que será impresso.
*/
void interface_gui::imprimirTelaTabuleiro(int casaAtual_param, tabuleiroTetralath *tabuleiro_param){
	char* comando = new char[1];
	string comandoString;

	//printf(COR_BRANCA_LINUX);	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_INTENSITY);
	system("cls");
	imprimirTextoCentralizado("TEXTLATH");
	printf("\n\n");
	imprimirTextoCentralizado("O tetralath em modo texto!");
	printf("\n");

	if(tabuleiro_param->recuperarCorPecasUltimaJogada() == casaTabuleiroTetralath::PECAS_PRETAS){
		printf("\n\n");
		imprimirTextoCentralizado("Eh a vez das pecas BRANCAS");
	} else {
		printf("\n\n");
		imprimirTextoCentralizado("Eh a vez das pecas PRETAS");
	}

	printf("\n\n\n\n");
	tabuleiro_param->imprimir(casaAtual_param);
	printf("\n\n\n\n");

	//printf(COR_AZUL_FRACA_LINUX);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
	imprimirComando("W");
	printf(" ou ");
	comando[0]=30;comando[1]='\0';comandoString = *(new string(comando));
	imprimirComando(comandoString);
	printf(" MOVER PARA CASA NA DIAGONAL ESQUERDA SUPERIOR (CIMA)\n");

	imprimirComando("S");
	printf(" ou ");
	comando[0]=31;comando[1]='\0';comandoString = *(new string(comando));
	imprimirComando(comandoString);
	printf(" MOVER PARA CASA NA DIAGONAL DIREITA INFEROR (BAIXO)\n");

	imprimirComando("A");
	printf(" ou ");
	comando[0]=17;comando[1]='\0';comandoString = *(new string(comando));
	imprimirComando(comandoString);
	printf(" MOVER PARA CASA A ESQUERDA\n");
	
	imprimirComando("D");
	printf(" ou ");
	comando[0]=16;comando[1]='\0';comandoString = *(new string(comando));
	imprimirComando(comandoString);
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
	imprimirTextoCentralizado("TEXTLATH");
	printf("\n\n");
	imprimirTextoCentralizado("O tetralath em modo texto!");
	printf("\n\n\n");

	imprimirTextoCentralizado("Fim do jogo!");

	printf("\n\n\n\n");
	tabuleiro_param->imprimir(casaAtual_param);
	printf("\n\n\n\n");

	//printf(COR_BRANCA_LINUX);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_INTENSITY);
	if(cor_pecas_ganhadoras_param == casaTabuleiroTetralath::PECAS_BRANCAS){
		imprimirTextoCentralizado("As pecas BRANCAS ganharam!");
	} else if(cor_pecas_ganhadoras_param == casaTabuleiroTetralath::PECAS_PRETAS){
		imprimirTextoCentralizado("As pecas PRETAS ganharam!");
	} else {
		imprimirTextoCentralizado("Houve empate!");
	}
	printf("\n\n\n\n");

	//printf(COR_AZUL_FRACA_LINUX);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
	printf("[Q] SAIR\n");
	//printf(COR_BRANCA_LINUX);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
	system("pause>>nul");
}

/*
* Imprime a tela que informa ao usuário para aguardar a jogada da inteligência artificial.
*/
void interface_gui::imprimirTelaAguardarJogada(){
	system("cls");
	//printf(COR_BRANCA_LINUX);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_INTENSITY);
	imprimirTextoCentralizado("TEXTLATH");
	printf("\n\n");
	imprimirTextoCentralizado("O tetralath em modo texto!");
	printf("\n\n\n");
	imprimirTextoCentralizado("Favor aguardar enquanto a IA estah rodando...\n\n\n");
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

/*
* Imprime um texto centralizado na tela.
* @param texto_param Texto a ser impresso.
*/
void interface_gui::imprimirTextoCentralizado(string texto_param){
	int CARACTERES_LINHA_CONSOLE = 80;
	int numeroEspacos;
	int i;
	if(texto_param.length() <= CARACTERES_LINHA_CONSOLE){
		numeroEspacos = floor((CARACTERES_LINHA_CONSOLE - texto_param.length())/2);
		for(i=0; i<numeroEspacos; i++){
			printf(" ");
		}
		printf(texto_param.data());
	} else {
		printf(texto_param.data());
	}
}