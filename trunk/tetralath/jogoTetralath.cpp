#include <iostream>

#include "jogoTetralath.h"

using namespace std;

/*************************************************************************************
* ATENÇÃO: À partir daqui, todos métodos são públicos
*************************************************************************************/

/*
* Cria um novo jogo, com base no seu tipo, e o retorna.
* @param _tipoJogo Define o tipo de jogo, se entre dois humanos, humano e pc ou pc contra pc.
* @param _tabuleiroJogo Tabuleiro em que acontece o jogo.
* @param _jogadorUm O jogador que fará a primeira jogada.
* @param _jogadorDois O jogador que fará a segunda jogada.
*/
jogoTetralath::jogoTetralath(tabuleiroTetralath _tabuleiroJogo, jogadorTetralath *_jogadorUm, jogadorTetralath *_jogadorDois){
	tabuleiroJogo = _tabuleiroJogo;
	jogadorUm = _jogadorUm;
	jogadorDois = _jogadorDois;
}

/*
* Inicia o jogo. Esta função só retornará quando o jogo estiver terminado.
* @param _interfaceUsuario A interface_gui usada para comunicação com o usuário.
* @return O jogador que ganhou o jogo.
*/
jogadorTetralath* jogoTetralath::iniciarJogo(interface_gui *_interfaceUsuario){
	jogadorTetralath *jogadorAtual = jogadorUm;
	bool eh_vezDoJogadorUm = true;
	int casaJogada;
	int resultadoAtehAgora = jogoTetralath::NAO_TERMINOU;
	
	_interfaceUsuario->imprimirTelaTabuleiro(0, &tabuleiroJogo);
	
	while(resultadoAtehAgora == jogoTetralath::NAO_TERMINOU){
		if(eh_vezDoJogadorUm){
			jogadorAtual = jogadorUm;
		} else {
			jogadorAtual = jogadorDois;
		}
		casaJogada = jogadorAtual->getIndiceCasaJogada(&tabuleiroJogo);
		tabuleiroJogo.jogar(casaJogada);
		_interfaceUsuario->imprimirTelaTabuleiro(0, &tabuleiroJogo);
		resultadoAtehAgora = conferirFimDoJogo();
	}
	
	if(resultadoAtehAgora == EMPATE){
		_interfaceUsuario->imprimirTelaResultado(500, casaJogada, &tabuleiroJogo);
	} else if(resultadoAtehAgora == JOGADOR_UM_GANHOU){
		_interfaceUsuario->imprimirTelaResultado(jogadorUm->getCorPecas(), casaJogada, &tabuleiroJogo);
	} else if(resultadoAtehAgora == JOGADOR_DOIS_GANHOU){
		_interfaceUsuario->imprimirTelaResultado(jogadorDois->getCorPecas(), casaJogada, &tabuleiroJogo);
	}
	
	return jogadorAtual;
}

/*
* Deve ser chamada ao fim de uma jogada.
* Irá conferir se o jogo acabou e dirá de quem é a vitória.
* @return EMPATE, se houve empate. 
*		  JOGADOR_UM_GANHOU, se o jogador um ganhou o jogo.
*		  JOGADOR_DOIS_GANHOU, se o jogador dois ganhou o jogo.
*		  NAO_TERMINOU, se o jogo ainda não terminou.
*/
int jogoTetralath::conferirFimDoJogo(){
	int resultadoJogo = jogoTetralath::NAO_TERMINOU;
	int CASA_INEXISTENTE = -1;
	bool jogoAcabou = false;
	tabuleiroJogo.pecasDaMesmaCorGanharam(tabuleiroJogo.recuperarNomeCasaUltimaJogada());
	bool brancasGanharam = (tabuleiroJogo.pecasDaMesmaCorGanharam(tabuleiroJogo.recuperarNomeCasaUltimaJogada())
						   and tabuleiroJogo.casaOcupadaPorPecaBranca(tabuleiroJogo.recuperarNomeCasaUltimaJogada()))
						   or (tabuleiroJogo.pecasDaMesmaCorPerderam(tabuleiroJogo.recuperarNomeCasaUltimaJogada()) 
						   and !tabuleiroJogo.casaOcupadaPorPecaBranca(tabuleiroJogo.recuperarNomeCasaUltimaJogada()));
	bool pretasGanharam = (tabuleiroJogo.pecasDaMesmaCorGanharam(tabuleiroJogo.recuperarNomeCasaUltimaJogada()) 
						   and !tabuleiroJogo.casaOcupadaPorPecaBranca(tabuleiroJogo.recuperarNomeCasaUltimaJogada()))
						   or (tabuleiroJogo.pecasDaMesmaCorPerderam(tabuleiroJogo.recuperarNomeCasaUltimaJogada()) 
						   and tabuleiroJogo.casaOcupadaPorPecaBranca(tabuleiroJogo.recuperarNomeCasaUltimaJogada()));
	if(brancasGanharam){
		if(jogadorUm->getCorPecas() == casaTabuleiroTetralath::PECAS_BRANCAS){
			resultadoJogo = jogoTetralath::JOGADOR_UM_GANHOU;
		} else {
			resultadoJogo = jogoTetralath::JOGADOR_DOIS_GANHOU;
		}
	} else if(pretasGanharam){
		if(jogadorUm->getCorPecas() == casaTabuleiroTetralath::PECAS_PRETAS){
			resultadoJogo = jogoTetralath::JOGADOR_UM_GANHOU;
		} else {
			resultadoJogo = jogoTetralath::JOGADOR_DOIS_GANHOU;
		}
	} else if(tabuleiroJogo.houveEmpate()){
		resultadoJogo = jogoTetralath::EMPATE;
	} else {
		resultadoJogo = jogoTetralath::NAO_TERMINOU;
	}
	return resultadoJogo;
}

/*************************************************************************************
* ATENÇÃO: À partir daqui, todos métodos são privados
*************************************************************************************/
