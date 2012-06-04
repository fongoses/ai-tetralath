

#include "menu.h"

#ifndef TABULEIRO_TETRALATH
#define TABULEIRO_TETRALATH

#include "tabuleiroTetralath.h"
 
#endif

/*
* Concentra todas funções da interface, isto é, a parte visual do jogo.
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
#define COMANDO_ESCOLHER_BRANCAS 'b' //No início, escolhe as peças brancas para o usuário.
#define COMANDO_ESCOLHER_PRETAS 'p' //No início, escolhe as peças pretas para o usuário.
#define COMANDO_ESCOLHER '$'//Faz um escolha em um menu.
#define COMANDO_PERCORRER_ALTERNATIVAS '*'//Percorre alternativas em um menu.
#define COMANDO_DEBUG_AVALIAR 'm'

class interface_gui{
	public:
	/*
	* Construtor da classe.
	*/
	interface_gui();
	/*
	* Espera por comando do usuário e o retorna, quando for feito.
	* @return O comando digitado pelo usuário. Não retorna comandos com CAPS, prefere sempre sua versão em lower case.
	*/
	char esperarComandoUsuario(void);
	/*
	* Imprime uma tela que permite escolha entre várias opções.
	* @param _opcoes Array de opções que o usuário possui.
	* @param _opcaoEscolhida O índice, no array, da opção escolhida. Se exceder os limites do array, será realçada a última.
	*/
	void imprimirTelaEscolha(vector<string> _opcoes, int _opcaoEscolhida);
	/*
	* Imprime uma tela de escolha em que cada opção é um submenu que pode ser acessado com [ENTER].
	* Recebe um objeto menu e nele define as opções selecionadas.
	* @param _menu Vector de vectors. Cada vector é um submenu de opções, que são strings.
	* Exemplo:
	*	imprimirTelaMenus(vector(vector("brancas","pretas"), 
								 vector("maquina", "humano"))) 
			= vector("brancas", "maquina")
	*/
	void imprimirTelaMenus(menu *_menu);
	/*
	* Imprime a tela do jogo.
	* @param casaAtual_param A casa em que está o cursor.
	* @param tabuleiro_param O tabuleiro que será impresso.
	*/
	void imprimirTelaTabuleiro(int casaAtual_param, tabuleiroTetralath *tabuleiro_param);
	/*
	* Imprime a tela do resultado de um jogo.
	* @param cor_pecas_ganhadoras_param A cor das peças que ganharam o jogo. Qualquer valor diferente de PECAS_PRETAS e PECAS_BRANCAS é empate.
	* @param casaAtual_param A casa em que está o cursor.
	* @param tabuleiro_param O tabuleiro que será impresso.
	*/
	void imprimirTelaResultado(int cor_pecas_ganhadoras_param, int casaAtual_param, tabuleiroTetralath *tabuleiro_param);
	/*
	* Imprime a tela que informa ao usuário para aguardar a jogada da inteligência artificial.
	*/
	void imprimirTelaAguardarJogada();
	/*
	* Imprime todas as cores possíveis no prompt no windows (Só funciona no windows!!!!!!).
	*/
	void imprimirCoresWindows(void);

	private:

	/*
	* Imprime um comando com letras brancas em colchetes.
	* @param comando_param Comando a imprimir.
	*/
	void imprimirComando(string comando_param);
	/*
	* Imprime um texto centralizado na tela.
	* @param texto_param Texto a ser impresso.
	*/
	void imprimirTextoCentralizado(string texto_param);
};