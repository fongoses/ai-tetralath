
#include "jogoTetralath.h"
#include "jogadorMaquina.h"
#include "jogadorHumano.h"
#include "menu.h"
#include "casaTabuleiroTetralath.h"
#include <stdlib.h>

using namespace std;

/*
* Jogo tetralath com IA.
*/

/**************************************************
* Declarações de métodos definidos após main.
*
*/


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
	/*int c;
	for(c=0; c<300; c++){
		printf("%d=%c\n",c,c);
	}
	system("pause");*/

	gui = (*new interface_gui());
	gui.redimensionar(interface_gui::LINHAS, interface_gui::COLUNAS);

	bool usuarioDesejaTerminar;
	vector<string> menuSair;
	menuSair.push_back("JOGAR NOVAMENTE");
	menuSair.push_back("SAIR DO TEXTLATH");

	ia *iaMaquinaUm;
	ia *iaMaquinaDois;
	jogadorTetralath *jogadorUm; 
	jogadorTetralath *jogadorDois;
	jogoTetralath jogo = *(new jogoTetralath(*(new tabuleiroTetralath(true)), jogadorUm, jogadorDois));

	menu menuInicioJogo;

	vector<string> opcoesJogadores;
	vector<string> opcoesAlgoritmos;
	vector<string> opcoesAvaliacao;
	vector<string> nomesColunas;

	opcoesJogadores.push_back("HUMANO");
	opcoesJogadores.push_back("MAQUINA");

	opcoesAlgoritmos.push_back("MINIMAX");
	opcoesAlgoritmos.push_back("PODA ALFA BETA");

	opcoesAvaliacao.push_back("AVALIACAO SIMPLES");
	opcoesAvaliacao.push_back("AVALIACAO MINUCIOSA");

	menuInicioJogo.criarNovaOpcao(opcoesJogadores);
	menuInicioJogo.criarNovaOpcao(opcoesJogadores);
	menuInicioJogo.criarNovaLinha();
	menuInicioJogo.criarNovaOpcao(opcoesAlgoritmos);
	menuInicioJogo.criarNovaOpcao(opcoesAlgoritmos);
	menuInicioJogo.criarNovaLinha();
	menuInicioJogo.criarNovaOpcao(opcoesAvaliacao);
	menuInicioJogo.criarNovaOpcao(opcoesAvaliacao);

	menuInicioJogo.restringirExibicaoOpcao(1, 0, 1, 0, 0);
	menuInicioJogo.restringirExibicaoOpcao(1, 1, 1, 0, 1);
	menuInicioJogo.restringirExibicaoOpcao(2, 0, 1, 0, 0);
	menuInicioJogo.restringirExibicaoOpcao(2, 1, 1, 0, 1);

	nomesColunas.push_back("Jogador 1");
	nomesColunas.push_back("Jogador 2");
	menuInicioJogo.nomearColunas(nomesColunas);

	int avaliacao;
	int algoritmo;
	usuarioDesejaTerminar = false;
	do{
		gui.imprimirTelaMenus(&menuInicioJogo);
		vector<vector<string> > opcoesEscolhidas = menuInicioJogo.getAlternativasSelecionadas();

		algoritmo = (opcoesEscolhidas.at(1).at(0)=="MINIMAX"? ia::MINIMAX : ia::MINIMAX_PODA);
		avaliacao = (opcoesEscolhidas.at(2).at(0)=="AVALIACAO SIMPLES"? ia::AVALIACAO_SIMPLES : ia::AVALIACAO_MINUCIOSA);
		iaMaquinaUm = new ia(algoritmo, avaliacao);
		algoritmo = (opcoesEscolhidas.at(1).at(1)=="MINIMAX"? ia::MINIMAX : ia::MINIMAX_PODA);
		avaliacao = (opcoesEscolhidas.at(2).at(1)=="AVALIACAO SIMPLES"? ia::AVALIACAO_SIMPLES : ia::AVALIACAO_MINUCIOSA);
		iaMaquinaDois = new ia(algoritmo, avaliacao);

		if(!gui.usuarioQuerFecharPrograma()){
			bool escolheu_opcoesValidas = false;

			jogadorUm = (opcoesEscolhidas.at(0).at(0) == "HUMANO"? 
							(jogadorTetralath*) (new jogadorHumano(&gui, casaTabuleiroTetralath::PECAS_BRANCAS)) : 
							(jogadorTetralath*) (new jogadorMaquina(*iaMaquinaUm, casaTabuleiroTetralath::PECAS_BRANCAS)));

			jogadorDois = (opcoesEscolhidas.at(0).at(1) == "HUMANO"? 
								(jogadorTetralath*) (new jogadorHumano(&gui, casaTabuleiroTetralath::PECAS_PRETAS)) : 
								(jogadorTetralath*) (new jogadorMaquina(*iaMaquinaDois, casaTabuleiroTetralath::PECAS_PRETAS)));

			jogo = *(new jogoTetralath(*(new tabuleiroTetralath(true)), jogadorUm, jogadorDois));
			jogo.iniciarJogo(&gui);

			if(!gui.usuarioQuerFecharPrograma()){
				usuarioDesejaTerminar = (gui.imprimirTelaEscolha(menuSair)==1 ? true : false);
			}
		}
	}while(!gui.usuarioQuerFecharPrograma() && !usuarioDesejaTerminar);

	system("cls");
	system("color 0f");

	return 0;
}
