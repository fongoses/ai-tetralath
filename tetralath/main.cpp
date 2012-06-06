
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

	jogadorTetralath *jogadorUm; 
	jogadorTetralath *jogadorDois;
	jogoTetralath jogo = *(new jogoTetralath(*(new tabuleiroTetralath(true)), jogadorUm, jogadorDois));

	menu menuInicioJogo;

	vector<string> opcoesJogadores;
	vector<string> nomesColunas;

	opcoesJogadores.push_back("HUMANO");
	opcoesJogadores.push_back("MAQUINA");

	menuInicioJogo.criarNovaOpcao(opcoesJogadores);
	menuInicioJogo.criarNovaOpcao(opcoesJogadores);

	nomesColunas.push_back("Jogador 1");
	nomesColunas.push_back("Jogador 2");
	menuInicioJogo.nomearColunas(nomesColunas);

	usuarioDesejaTerminar = false;
	do{
		gui.imprimirTelaMenus(&menuInicioJogo);

		if(!gui.usuarioQuerFecharPrograma()){
			vector<vector<string> > opcoesEscolhidas = menuInicioJogo.getAlternativasSelecionadas();
			bool escolheu_opcoesValidas = false;

			jogadorUm = (opcoesEscolhidas.at(0).at(0) == "HUMANO"? 
							(jogadorTetralath*) (new jogadorHumano(&gui, casaTabuleiroTetralath::PECAS_BRANCAS)) : 
							(jogadorTetralath*) (new jogadorMaquina(*(new ia(ia::MINIMAX)), casaTabuleiroTetralath::PECAS_BRANCAS)));

			jogadorDois = (opcoesEscolhidas.at(0).at(1) == "HUMANO"? 
								(jogadorTetralath*) (new jogadorHumano(&gui, casaTabuleiroTetralath::PECAS_PRETAS)) : 
								(jogadorTetralath*) (new jogadorMaquina(*(new ia(ia::MINIMAX)), casaTabuleiroTetralath::PECAS_PRETAS)));

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
