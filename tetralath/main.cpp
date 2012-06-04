
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

	menu menuInicioJogo;

	vector<string> opcoesCores;
	vector<string> opcoesJogadores;
	vector<string> nomesColunas;

	opcoesCores.push_back("BRANCAS");
	opcoesCores.push_back("PRETAS");
	opcoesJogadores.push_back("HUMANO");
	opcoesJogadores.push_back("MAQUINA");

	menuInicioJogo.criarNovaOpcao(opcoesJogadores);
	menuInicioJogo.criarNovaOpcao(opcoesJogadores);
	menuInicioJogo.criarNovaLinha();
	menuInicioJogo.criarNovaOpcao(opcoesCores);
	menuInicioJogo.criarNovaOpcao(opcoesCores);

	nomesColunas.push_back("Jogador 1");
	nomesColunas.push_back("Jogador 2");
	menuInicioJogo.nomearColunas(nomesColunas);

	gui.imprimirTelaMenus(&menuInicioJogo);

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
	
	system("color 0f");

	return 0;
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
	gui.imprimirTelaEscolha(opcoes, opcaoRealcarInterface);
	
	do{
		Sleep(50); //Movimento não muito rápido, permitindo melhor controle.
		comandoUsuario = gui.esperarComandoUsuario();
		if(comandoUsuario == COMANDO_PERCORRER_ALTERNATIVAS){
			opcaoRealcarInterface++;
			if(2 < opcaoRealcarInterface){
				opcaoRealcarInterface = 0;
			}
		}
		gui.imprimirTelaEscolha(opcoes, opcaoRealcarInterface);
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

