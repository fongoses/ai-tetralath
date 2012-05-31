#include "jogadorHumano.h"



/*
* Cria um novo jogador humano.
* @param _interfaceComunicacaoUsuario A interface pela qual será possível comunicar-se com o usuário.
* @param _corPecas Cor das peças deste jogador.
*/
jogadorHumano::jogadorHumano(interface_gui *_interfaceComunicacaoUsuario, int _corPecas){
	setTipoJogador(jogadorTetralath::TIPO_HUMANO);
	setCorPecas(_corPecas);
	interfaceComunicacaoUsuario = _interfaceComunicacaoUsuario;
}
	
/*
* @param _tabuleiro O tabuleiro em que é feita a jogada.
* @return O índice da casa em que o jogador resolveu fazer sua jogada. Esta função é implementada somente nas herdeiras.
*/
int jogadorHumano::getIndiceCasaJogada(tabuleiroTetralath *_tabuleiro){
	int casaCursor = 0;
	int casaEscolhida = 0;
	
	char comandoUsuario = COMANDO_SEM_ACAO;
	char movimentoUsuario = COMANDO_SEM_ACAO;
	
	bool escolheuJogada = false;
	
	while(comandoUsuario != COMANDO_FECHAR and !escolheuJogada){
		Sleep(50); //Movimento não muito rápido, permitindo melhor controle.

		comandoUsuario = interfaceComunicacaoUsuario->esperarComandoUsuario();

		if(comandoUsuario == COMANDO_JOGAR){
			escolheuJogada = true;
			casaEscolhida = casaCursor;
		} else if((comandoUsuario == MOVIMENTO_CIMA or comandoUsuario == MOVIMENTO_BAIXO or comandoUsuario == MOVIMENTO_ESQUERDA or comandoUsuario == MOVIMENTO_DIREITA)){
			movimentoUsuario = comandoUsuario;
			casaCursor = _tabuleiro->getIndiceCasaMovimento(movimentoUsuario, casaCursor);
			interfaceComunicacaoUsuario->imprimirTelaTabuleiro(casaCursor, _tabuleiro);
		} else if(comandoUsuario == COMANDO_DESFAZER_JOGADA){
			_tabuleiro->desfazerUltimaJogada(); //Desfaz jogada do usuário...
			_tabuleiro->desfazerUltimaJogada(); //... e da IA.
			interfaceComunicacaoUsuario->imprimirTelaTabuleiro(casaCursor, _tabuleiro);
		}
	}
	
	return casaEscolhida;
}

