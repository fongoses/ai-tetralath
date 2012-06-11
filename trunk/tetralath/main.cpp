
#include "jogoTetralath.h"
#include "jogadorMaquina.h"
#include "jogadorHumano.h"
#include "menu.h"
#include "casaTabuleiroTetralath.h"
#include "abertura.h"
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

	vector<string> opcoesAberturas; vector<string> legendasAberturas;
	vector<string> opcoesJogadores; vector<string> legendasJogadores;
	vector<string> opcoesAlgoritmos; vector<string> legendasAlgoritmos;
	vector<string> opcoesAvaliacao; vector<string> legendasAvaliacao;
	vector<string> nomesColunas;

	opcoesJogadores.push_back("HUMANO"); legendasJogadores.push_back("Voce faz as jogadas.");
	opcoesJogadores.push_back("MAQUINA"); legendasJogadores.push_back("Jogadas feitas pela IA.");

	opcoesAlgoritmos.push_back("MINIMAX"); legendasAlgoritmos.push_back("Algoritmo minimax simples, sem nenhum tipo de corte, exceto por nodo folha. Este eh o menos eficiente.");
	opcoesAlgoritmos.push_back("PODA ALFA BETA"); legendasAlgoritmos.push_back("Algoritmo minimax com poda alfa beta. Torna-se mais eficiente que o minimax em poucas jogadas.");

	opcoesAvaliacao.push_back("AVALIACAO INGENUA"); legendasAvaliacao.push_back("Pior funcao de avaliacao. Possui complexidade O(n^2) e retorna valores discretos (-1, 0 ou +1).");
	opcoesAvaliacao.push_back("AVALIACAO MINUCIOSA"); legendasAvaliacao.push_back("Funcao de avaliacao de alta complexidade, mas capaz de retornar valores continuos no intervalo [-1,+1].");
	opcoesAvaliacao.push_back("AVALIACAO PREGUICOSA"); legendasAvaliacao.push_back("Otimizacao da avaliacao ingenua. Com complexidade O(n), eh a mais rahpida e retorna valores discretos (-1, 0 ou +1).");

	opcoesAberturas.push_back("SEM ABERTURA"); legendasAberturas.push_back("A IA nao tentarah usar jogadas prontas.");
	opcoesAberturas.push_back("ABERTURA DUPLA"); legendasAberturas.push_back("A IA tentarah utilizar a abertura mais simples e menos eficaz.");
	opcoesAberturas.push_back("ABERTURA TRIANGULO AGRESSIVO"); legendasAberturas.push_back("A IA utilizarah a melhor abertura e mais agressiva, que faz um triangulo e obriga o inimigo a se defender ateh que perca. Necessita de 3 jogadas para iniciar o ataque.");
	opcoesAberturas.push_back("ABERTURA DUPLA FILEIRA AGRESSIVA"); legendasAberturas.push_back("A IA utilizarah uma abertura que faz uma dupla fileira, obrigando o inimigo a se defender ateh que perca. Existem muitas formas de fugir dos ataques desta abertura, portanto ela nao eh a melhor.");

	menuInicioJogo.criarNovaOpcao(opcoesJogadores, legendasJogadores);
	menuInicioJogo.criarNovaOpcao(opcoesJogadores, legendasJogadores);
	menuInicioJogo.criarNovaLinha();
	menuInicioJogo.criarNovaOpcao(opcoesAlgoritmos, legendasAlgoritmos);
	menuInicioJogo.criarNovaOpcao(opcoesAlgoritmos, legendasAlgoritmos);
	menuInicioJogo.criarNovaLinha();
	menuInicioJogo.criarNovaOpcao(opcoesAvaliacao, legendasAvaliacao);
	menuInicioJogo.criarNovaOpcao(opcoesAvaliacao, legendasAvaliacao);
	menuInicioJogo.criarNovaLinha();
	menuInicioJogo.criarNovaOpcao(opcoesAberturas, legendasAberturas);
	menuInicioJogo.criarNovaOpcao(opcoesAberturas, legendasAberturas);

	menuInicioJogo.restringirExibicaoOpcao(1, 0, 1, 0, 0);
	menuInicioJogo.restringirExibicaoOpcao(1, 1, 1, 0, 1);
	menuInicioJogo.restringirExibicaoOpcao(2, 0, 1, 0, 0);
	menuInicioJogo.restringirExibicaoOpcao(2, 1, 1, 0, 1);
	menuInicioJogo.restringirExibicaoOpcao(3, 0, 1, 0, 0);
	menuInicioJogo.restringirExibicaoOpcao(3, 1, 1, 0, 1);

	nomesColunas.push_back("Jogador 1");
	nomesColunas.push_back("Jogador 2");
	menuInicioJogo.nomearColunas(nomesColunas);

	int avaliacao;
	int algoritmo;
	int aberturaUtilizada;
	usuarioDesejaTerminar = false;
	do{
		gui.imprimirTelaMenus(&menuInicioJogo);
		vector<vector<string> > opcoesEscolhidas = menuInicioJogo.getAlternativasSelecionadas();

		algoritmo = (opcoesEscolhidas.at(1).at(0)=="MINIMAX"? ia::MINIMAX : ia::MINIMAX_PODA);
		if(opcoesEscolhidas.at(2).at(0)=="AVALIACAO INGENUA"){
			avaliacao = ia::AVALIACAO_SIMPLES;
		} else if(opcoesEscolhidas.at(2).at(0)=="AVALIACAO MINUCIOSA"){
			avaliacao = ia::AVALIACAO_MINUCIOSA;
		} else if(opcoesEscolhidas.at(2).at(0)=="AVALIACAO PREGUICOSA"){
			avaliacao = ia::AVALIACAO_PREGUICOSA;
		}
		if(opcoesEscolhidas.at(3).at(0) == "SEM ABERTURA"){
			aberturaUtilizada = abertura::SEM_ABERTURA;
		} else if(opcoesEscolhidas.at(3).at(0) == "ABERTURA DUPLA"){
			aberturaUtilizada = abertura::ABERTURA_DUPLA;
		} else if(opcoesEscolhidas.at(3).at(0) == "ABERTURA TRIANGULO AGRESSIVO"){
			aberturaUtilizada = abertura::ABERTURA_TRIANGULO_AGRESSIVO;
		} else if(opcoesEscolhidas.at(3).at(0) == "ABERTURA DUPLA FILEIRA AGRESSIVA"){
			aberturaUtilizada = abertura::ABERTURA_DUPLA_FILEIRA_AGRESSIVA;
		}
		iaMaquinaUm = (aberturaUtilizada == abertura::SEM_ABERTURA? 
					new ia(algoritmo, avaliacao) : 
					new ia(algoritmo, avaliacao, new abertura(aberturaUtilizada)));
		algoritmo = (opcoesEscolhidas.at(1).at(1)=="MINIMAX"? ia::MINIMAX : ia::MINIMAX_PODA);
		if(opcoesEscolhidas.at(2).at(1)=="AVALIACAO INGENUA"){
			avaliacao = ia::AVALIACAO_SIMPLES;
		} else if(opcoesEscolhidas.at(2).at(1)=="AVALIACAO MINUCIOSA"){
			avaliacao = ia::AVALIACAO_MINUCIOSA;
		} else if(opcoesEscolhidas.at(2).at(1)=="AVALIACAO PREGUICOSA"){
			avaliacao = ia::AVALIACAO_PREGUICOSA;
		}
		if(opcoesEscolhidas.at(3).at(1) == "SEM ABERTURA"){
			aberturaUtilizada = abertura::SEM_ABERTURA;
		} else if(opcoesEscolhidas.at(3).at(1) == "ABERTURA DUPLA"){
			aberturaUtilizada = abertura::ABERTURA_DUPLA;
		} else if(opcoesEscolhidas.at(3).at(1) == "ABERTURA TRIANGULO AGRESSIVO"){
			aberturaUtilizada = abertura::ABERTURA_TRIANGULO_AGRESSIVO;
		} else if(opcoesEscolhidas.at(3).at(1) == "ABERTURA DUPLA FILEIRA AGRESSIVA"){
			aberturaUtilizada = abertura::ABERTURA_DUPLA_FILEIRA_AGRESSIVA;
		}
		iaMaquinaDois = (aberturaUtilizada == abertura::SEM_ABERTURA? 
					new ia(algoritmo, avaliacao) : 
					new ia(algoritmo, avaliacao, new abertura(aberturaUtilizada)));

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
