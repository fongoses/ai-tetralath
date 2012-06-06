#ifndef STRING_E_VECTOR
#define STRING_E_VECTOR
	#include <string>
	#include <vector>
#endif

class menu;
class tabuleiroTetralath;

using namespace std;

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
	* Indicam as dimensões da linha de comando.
	*/
	static const int LINHAS = 40;
	static const int COLUNAS = 150;

	/*
	* Construtor da classe.
	*/
	interface_gui();
	/*
	* Imprime um texto centralizado na tela.
	* @param texto_param Texto a ser impresso.
	*/
	static void imprimirTextoCentralizado(string texto_param);
	/*
	* Imprime tantos espaços quanto for especificado.
	* @param _quantidadeEspacos Quantidade de espaços que será impressa na tela.
	*/
	static void imprimirEspacos(int _quantidadeEspacos);
	/*
	* Espera por comando do usuário e o retorna, quando for feito.
	* @param _possivelTerminar Booleano que liga/desliga a atribuição da flag que sinaliza a entrada de um COMANDO_FECHAR.
	* @return O comando digitado pelo usuário. Não retorna comandos com CAPS, prefere sempre sua versão em lower case.
	*/
	char esperarComandoUsuario(bool _possivelTerminar);
	/*
	* Imprime uma tela que permite escolha entre várias opções.
	* @param _opcoes Array de opções que o usuário possui.
	* @param _opcaoEscolhida O índice, no array, da opção escolhida. Se exceder os limites do array, será realçada a última.
	*/
	void imprimirTelaEscolhaEstatica(vector<string> _opcoes, int _opcaoEscolhida);
	/*
	* Controla a impressão da tela de escolha com base em entrada do usuário.
	* @param _opcoes Opções excludentes dentre as quais o usuário pode escolher.
	* @return Opção que foi escolhida.
	*/
	int imprimirTelaEscolha(vector<string> _opcoes);
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
	/*
	* @return Booleano que indica se o usuário informou à esta gui que deseja terminar o programa.
	*/
	bool usuarioQuerFecharPrograma();
	/*
	* Redimensiona esta gui para as dimensões dadas.
	* @param _numeroLinhas O número de linhas que a gui terá.
	* @param _numeroColunas O número de colunas que a gui terá.
	*/
	void redimensionar(int _numeroLinhas, int _numeroColunas);
	/*
	* Gera string cujo único caractere tem o código ASCII passado.
	* @param _codigoASCII Código ASCII do caractere que se quer na string.
	* @return String cujo único caractere tem o código ASCII passado.
	*/
	static string getStringCaractereASCII(int _codigoASCII);

	private:
	/*
	* Booleano que indica se o usuário informou à esta gui que deseja terminar o programa.
	*/
	bool deveTerminar;

	/*
	* Imprime um comando com letras brancas em colchetes.
	* @param comando_param Comando a imprimir.
	*/
	void imprimirComando(string comando_param);
};