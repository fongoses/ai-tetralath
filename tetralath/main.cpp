#include <stdio.h>
#include <stdlib.h>
#include "ia.h"
using namespace std;


/*
* Jogo tetralath com IA.
*/


#define MOVIMENTO_CIMA 'w' //Movimenta para o vizinho A, se existir.
#define MOVIMENTO_BAIXO 's' //Movimenta para o vizinho F, se existir.
#define MOVIMENTO_ESQUERDA 'a' //Movimenta para o vizinho C, se existir.
#define MOVIMENTO_DIREITA 'd' //Movimenta para o vizinho D, se existir.
#define COMANDO_FECHAR 'q' //Termina a aplicação.
#define COMANDO_JOGAR 'j' //Faz uma jogada na posição em que estiver, se possível.
#define COMANDO_SEM_ACAO 'o' //Usado para inicialização. Não deve ter ação atribuída.


int getIndiceCasaMovimento(int movimento_param, int casa_partida_param);

int main(){
	int pecasDaVez = casaTabuleiroTetralath::PECAS_BRANCAS;
	int casaAtual = 0;

	char comandoUsuario = COMANDO_SEM_ACAO;
	char movimentoUsuario = COMANDO_SEM_ACAO;

	bool conseguiuJogar;
	bool jogoAcabou = false;

	tabuleiroTetralath tabuleiro = *(new tabuleiroTetralath());


	while(comandoUsuario != COMANDO_FECHAR){
		if(!jogoAcabou){
			system("cls");
			tabuleiro.imprimir(casaAtual);
		}

		comandoUsuario = getc(stdin);
		if(comandoUsuario == COMANDO_JOGAR){
			conseguiuJogar = tabuleiro.jogar(casaAtual, pecasDaVez);
			if(conseguiuJogar){
				(pecasDaVez == casaTabuleiroTetralath::PECAS_BRANCAS) ? 
					pecasDaVez = casaTabuleiroTetralath::PECAS_PRETAS : pecasDaVez = casaTabuleiroTetralath::PECAS_BRANCAS;
				if(tabuleiro.pecasDaMesmaCorGanharam(tabuleiro.recuperarNomeCasaUltimaJogada())){
					jogoAcabou = true;
					system("cls");
					tabuleiro.recuperarCorPecasUltimaJogada() == casaTabuleiroTetralath::PECAS_BRANCAS?
						printf("\n\n\n\n\n\t\t As peças BRANCAS ganharam!!!") : printf("\n\n\n\n\n\t\t As peças PRETAS ganharam!!!");
				} else if(tabuleiro.pecasDaMesmaCorPerderam(tabuleiro.recuperarNomeCasaUltimaJogada())){
					jogoAcabou = true;
					system("cls");
					tabuleiro.recuperarCorPecasUltimaJogada() == casaTabuleiroTetralath::PECAS_BRANCAS?
						printf("\n\n\n\n\n\t\t As peças BRANCAS ganharam!!!") : printf("\n\n\n\n\n\t\t As peças PRETAS ganharam!!!");
				}
			}
		} else if(comandoUsuario == MOVIMENTO_CIMA or comandoUsuario == MOVIMENTO_BAIXO or comandoUsuario == MOVIMENTO_ESQUERDA or comandoUsuario == MOVIMENTO_DIREITA){
			movimentoUsuario = comandoUsuario;
			casaAtual = getIndiceCasaMovimento(movimentoUsuario, casaAtual);
		}
	}

	system("cls");

	return 0;
}

/*
* Dado um movimento e um índice de casa, decide para qual índice de casa o cursor do tabuleiro deve ser movido.
* @param movimento_param Caractere que decide o índice.
* @param casa_partida_param Casa da qual deseja-se obter o vizinho.
* @return Índice a ser passado para imprimir. Se não houver vizinho para o movimento, retorna a casa passada como argumento.
*/
int getIndiceCasaMovimento(int movimento_param, int casa_partida_param){
	int casa_destino = casa_partida_param;
	if(movimento_param == MOVIMENTO_CIMA){ //Movimenta para o vizinho A, se existir.
		if(casa_partida_param == 0 or casa_partida_param == 1 or casa_partida_param == 2 or casa_partida_param == 3 or casa_partida_param == 4 or
		   casa_partida_param == 5 or casa_partida_param == 11 or casa_partida_param == 18 or casa_partida_param == 26){
			casa_destino = casa_partida_param;
		} else if(casa_partida_param <= 10){
			casa_destino = casa_partida_param - 6;
		} else if(casa_partida_param <= 17){
			casa_destino = casa_partida_param - 7;
		} else if(casa_partida_param <= 25){
			casa_destino = casa_partida_param - 8;
		} else if(casa_partida_param <= 34){
			casa_destino = casa_partida_param - 9;
		} else if(casa_partida_param <= 42){
			casa_destino = casa_partida_param - 9;
		} else if(casa_partida_param <= 49){
			casa_destino = casa_partida_param - 8;
		} else if(casa_partida_param <= 55){
			casa_destino = casa_partida_param - 7;
		} else if(casa_partida_param <= 60){
			casa_destino = casa_partida_param - 6;
		}
	} else if(movimento_param == MOVIMENTO_BAIXO){ //Movimenta para o vizinho F, se existir.
		if(casa_partida_param == 56 or casa_partida_param == 57 or casa_partida_param == 58 or casa_partida_param == 59 or casa_partida_param == 60 or
		   casa_partida_param == 34 or casa_partida_param == 42 or casa_partida_param == 49 or casa_partida_param == 55){
			casa_destino = casa_partida_param;
		} else if(casa_partida_param <= 4){
			casa_destino = casa_partida_param + 6;
		} else if(casa_partida_param <= 10){
			casa_destino = casa_partida_param + 7;
		} else if(casa_partida_param <= 17){
			casa_destino = casa_partida_param + 8;
		} else if(casa_partida_param <= 25){
			casa_destino = casa_partida_param + 9;
		} else if(casa_partida_param <= 34){
			casa_destino = casa_partida_param + 9;
		} else if(casa_partida_param <= 42){
			casa_destino = casa_partida_param + 8;
		} else if(casa_partida_param <= 49){
			casa_destino = casa_partida_param + 7;
		} else if(casa_partida_param <= 55){
			casa_destino = casa_partida_param + 6;
		}
	} else if(movimento_param == MOVIMENTO_ESQUERDA){ //Movimenta para o vizinho C, se existir.
		if(casa_partida_param == 0 or casa_partida_param == 5 or casa_partida_param == 11 or casa_partida_param == 18 or casa_partida_param == 26 or
		   casa_partida_param == 35 or casa_partida_param == 43 or casa_partida_param == 50 or casa_partida_param == 56){
			casa_destino = casa_partida_param;
		} else {
			casa_destino = casa_partida_param - 1;
		}
	} else if(movimento_param == MOVIMENTO_DIREITA){ //Movimenta para o vizinho D, se existir.
		if(casa_partida_param == 4 or casa_partida_param == 10 or casa_partida_param == 17 or casa_partida_param == 25 or casa_partida_param == 34 or
		   casa_partida_param == 42 or casa_partida_param == 49 or casa_partida_param == 55 or casa_partida_param == 60){
			casa_destino = casa_partida_param;
		} else {
			casa_destino = casa_partida_param + 1;
		}
	} else {
		casa_destino = casa_partida_param;
	}
	return casa_destino;
}


