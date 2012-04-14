#include "tabuleiroTetralath.h"
#include "casaTabuleiroTetralath.h"

#define VIZINHO_INEXISTENTE = NULL;

/*
* Classe que implementa um tabuleiro do jogo Tetralath.
*/
/*
* Construtor da classe.
* Inicializa todas as casas com seus vizinhos.
* @param corPecasJogador_param casaTabuleiroTetralath.PECAS_BRANCAS ou casaTabuleiroTetralath.PECAS_PRETAS. É a cor do jogador, a AI.
*/
tabuleiroTetralath::tabuleiroTetralath(int corPecasJogador_param){
	int indiceCasa = 0;

	//Inicialização do vetor de casas.
	for(indiceCasa=0; indiceCasa<NUMERO_CASAS; indiceCasa++){
		tabuleiro[indiceCasa] = *(new casaTabuleiroTetralath());
	}

	//Criação do tabuleiro. Para informações sobre vizinhanças, verificar figuras anexas ao projeto.
	 tabuleiro[0].criarVizinhanca(VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,&tabuleiro[1]      ,&tabuleiro[5]      ,&tabuleiro[6]);
	 tabuleiro[1].criarVizinhanca(VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,&tabuleiro[0]      ,&tabuleiro[2]      ,&tabuleiro[6]      ,&tabuleiro[7]);
	 tabuleiro[2].criarVizinhanca(VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,&tabuleiro[1]      ,&tabuleiro[3]      ,&tabuleiro[7]      ,&tabuleiro[8]);
	 tabuleiro[3].criarVizinhanca(VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,&tabuleiro[2]      ,&tabuleiro[4]      ,&tabuleiro[8]      ,&tabuleiro[9]);
	 tabuleiro[4].criarVizinhanca(VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,&tabuleiro[3]      ,VIZINHO_INEXISTENTE,&tabuleiro[9]      ,&tabuleiro[10]);
	 tabuleiro[5].criarVizinhanca(VIZINHO_INEXISTENTE,&tabuleiro[0]      ,VIZINHO_INEXISTENTE,&tabuleiro[6]      ,&tabuleiro[11]     ,&tabuleiro[12]);
	 tabuleiro[6].criarVizinhanca(&tabuleiro[0]      ,&tabuleiro[1]      ,&tabuleiro[5]      ,&tabuleiro[7]      ,&tabuleiro[12]     ,&tabuleiro[13]);
	 tabuleiro[7].criarVizinhanca(&tabuleiro[1]      ,&tabuleiro[2]      ,&tabuleiro[6]      ,&tabuleiro[8]      ,&tabuleiro[13]     ,&tabuleiro[14]);
	 tabuleiro[8].criarVizinhanca(&tabuleiro[2]      ,&tabuleiro[3]      ,&tabuleiro[7]      ,&tabuleiro[9]      ,&tabuleiro[14]     ,&tabuleiro[15]);
	 tabuleiro[9].criarVizinhanca(&tabuleiro[3]      ,&tabuleiro[4]      ,&tabuleiro[8]      ,&tabuleiro[10]     ,&tabuleiro[15]     ,&tabuleiro[16]);
	tabuleiro[10].criarVizinhanca(&tabuleiro[4]      ,VIZINHO_INEXISTENTE,&tabuleiro[9]      ,VIZINHO_INEXISTENTE,&tabuleiro[16]     ,&tabuleiro[17]);
	tabuleiro[11].criarVizinhanca(VIZINHO_INEXISTENTE,&tabuleiro[5]      ,VIZINHO_INEXISTENTE,&tabuleiro[12]     ,&tabuleiro[18]     ,&tabuleiro[19]);
	tabuleiro[12].criarVizinhanca(&tabuleiro[5]      ,&tabuleiro[6]      ,&tabuleiro[11]     ,&tabuleiro[13]     ,&tabuleiro[19]     ,&tabuleiro[20]);
	tabuleiro[13].criarVizinhanca(&tabuleiro[6]      ,&tabuleiro[7]      ,&tabuleiro[12]     ,&tabuleiro[14]     ,&tabuleiro[20]     ,&tabuleiro[21]);
	tabuleiro[14].criarVizinhanca(&tabuleiro[7]      ,&tabuleiro[8]      ,&tabuleiro[13]     ,&tabuleiro[15]     ,&tabuleiro[21]     ,&tabuleiro[22]);
	tabuleiro[15].criarVizinhanca(&tabuleiro[8]      ,&tabuleiro[9]      ,&tabuleiro[14]     ,&tabuleiro[16]     ,&tabuleiro[22]     ,&tabuleiro[23]);
	tabuleiro[16].criarVizinhanca(&tabuleiro[9]      ,&tabuleiro[10]     ,&tabuleiro[15]     ,&tabuleiro[17]     ,&tabuleiro[23]     ,&tabuleiro[24]);
	tabuleiro[17].criarVizinhanca(&tabuleiro[10]     ,VIZINHO_INEXISTENTE,&tabuleiro[16]     ,VIZINHO_INEXISTENTE,&tabuleiro[24]     ,&tabuleiro[25]);
	tabuleiro[18].criarVizinhanca(VIZINHO_INEXISTENTE,&tabuleiro[11]     ,VIZINHO_INEXISTENTE,&tabuleiro[19]     ,&tabuleiro[26]     ,&tabuleiro[27]);
	tabuleiro[19].criarVizinhanca(&tabuleiro[11]     ,&tabuleiro[12]     ,&tabuleiro[18]     ,&tabuleiro[20]     ,&tabuleiro[27]     ,&tabuleiro[28]);
	tabuleiro[20].criarVizinhanca(&tabuleiro[12]     ,&tabuleiro[13]     ,&tabuleiro[19]     ,&tabuleiro[21]     ,&tabuleiro[28]     ,&tabuleiro[29]);
	tabuleiro[21].criarVizinhanca(&tabuleiro[13]     ,&tabuleiro[14]     ,&tabuleiro[20]     ,&tabuleiro[22]     ,&tabuleiro[29]     ,&tabuleiro[30]);
	tabuleiro[22].criarVizinhanca(&tabuleiro[14]     ,&tabuleiro[15]     ,&tabuleiro[21]     ,&tabuleiro[23]     ,&tabuleiro[30]     ,&tabuleiro[31]);
	tabuleiro[23].criarVizinhanca(&tabuleiro[15]     ,&tabuleiro[16]     ,&tabuleiro[22]     ,&tabuleiro[24]     ,&tabuleiro[31]     ,&tabuleiro[32]);
	tabuleiro[24].criarVizinhanca(&tabuleiro[16]     ,&tabuleiro[17]     ,&tabuleiro[23]     ,&tabuleiro[25]     ,&tabuleiro[32]     ,&tabuleiro[33]);
	tabuleiro[25].criarVizinhanca(&tabuleiro[17]     ,VIZINHO_INEXISTENTE,&tabuleiro[24]     ,VIZINHO_INEXISTENTE,&tabuleiro[33]     ,&tabuleiro[34]);
	tabuleiro[26].criarVizinhanca(VIZINHO_INEXISTENTE,&tabuleiro[18]     ,VIZINHO_INEXISTENTE,&tabuleiro[27]     ,VIZINHO_INEXISTENTE,&tabuleiro[35]);
	tabuleiro[27].criarVizinhanca(&tabuleiro[18]     ,&tabuleiro[19]     ,&tabuleiro[26]     ,&tabuleiro[28]     ,&tabuleiro[35]     ,&tabuleiro[36]);
	tabuleiro[28].criarVizinhanca(&tabuleiro[19]     ,&tabuleiro[20]     ,&tabuleiro[27]     ,&tabuleiro[29]     ,&tabuleiro[36]     ,&tabuleiro[37]);
	tabuleiro[29].criarVizinhanca(&tabuleiro[20]     ,&tabuleiro[21]     ,&tabuleiro[28]     ,&tabuleiro[30]     ,&tabuleiro[37]     ,&tabuleiro[38]);
	tabuleiro[30].criarVizinhanca(&tabuleiro[21]     ,&tabuleiro[22]     ,&tabuleiro[29]     ,&tabuleiro[31]     ,&tabuleiro[38]     ,&tabuleiro[39]);
	tabuleiro[31].criarVizinhanca(&tabuleiro[22]     ,&tabuleiro[23]     ,&tabuleiro[30]     ,&tabuleiro[32]     ,&tabuleiro[39]     ,&tabuleiro[40]);
	tabuleiro[32].criarVizinhanca(&tabuleiro[23]     ,&tabuleiro[24]     ,&tabuleiro[31]     ,&tabuleiro[33]     ,&tabuleiro[40]     ,&tabuleiro[41]);
	tabuleiro[33].criarVizinhanca(&tabuleiro[24]     ,&tabuleiro[25]     ,&tabuleiro[32]     ,&tabuleiro[34]     ,&tabuleiro[41]     ,&tabuleiro[42]);
	tabuleiro[34].criarVizinhanca(&tabuleiro[25],VIZINHO_INEXISTENTE     ,&tabuleiro[33]     ,VIZINHO_INEXISTENTE,&tabuleiro[42]     ,VIZINHO_INEXISTENTE);
	tabuleiro[35].criarVizinhanca(&tabuleiro[26]     ,&tabuleiro[27]     ,VIZINHO_INEXISTENTE,&tabuleiro[36]     ,VIZINHO_INEXISTENTE,&tabuleiro[43]);
	tabuleiro[36].criarVizinhanca(&tabuleiro[27]     ,&tabuleiro[28]     ,&tabuleiro[35]     ,&tabuleiro[37]     ,&tabuleiro[43]     ,&tabuleiro[44]);
	tabuleiro[37].criarVizinhanca(&tabuleiro[28]     ,&tabuleiro[29]     ,&tabuleiro[36]     ,&tabuleiro[38]     ,&tabuleiro[44]     ,&tabuleiro[45]);
	tabuleiro[38].criarVizinhanca(&tabuleiro[29]     ,&tabuleiro[30]     ,&tabuleiro[37]     ,&tabuleiro[39]     ,&tabuleiro[45]     ,&tabuleiro[46]);
	tabuleiro[39].criarVizinhanca(&tabuleiro[30]     ,&tabuleiro[31]     ,&tabuleiro[38]     ,&tabuleiro[40]     ,&tabuleiro[46]     ,&tabuleiro[47]);
	tabuleiro[40].criarVizinhanca(&tabuleiro[31]     ,&tabuleiro[32]     ,&tabuleiro[39]     ,&tabuleiro[41]     ,&tabuleiro[47]     ,&tabuleiro[48]);
	tabuleiro[41].criarVizinhanca(&tabuleiro[32]     ,&tabuleiro[33]     ,&tabuleiro[40]     ,&tabuleiro[42]     ,&tabuleiro[48]     ,&tabuleiro[49]);
	tabuleiro[42].criarVizinhanca(&tabuleiro[33]     ,&tabuleiro[34]     ,&tabuleiro[41]     ,VIZINHO_INEXISTENTE,&tabuleiro[49]     ,VIZINHO_INEXISTENTE);
	tabuleiro[43].criarVizinhanca(&tabuleiro[35]     ,&tabuleiro[36]     ,VIZINHO_INEXISTENTE,&tabuleiro[44]     ,VIZINHO_INEXISTENTE,&tabuleiro[50]);
	tabuleiro[44].criarVizinhanca(&tabuleiro[36]     ,&tabuleiro[37]     ,&tabuleiro[43]     ,&tabuleiro[45]     ,&tabuleiro[50]     ,&tabuleiro[51]);
	tabuleiro[45].criarVizinhanca(&tabuleiro[37]     ,&tabuleiro[38]     ,&tabuleiro[44]     ,&tabuleiro[46]     ,&tabuleiro[51]     ,&tabuleiro[52]);
	tabuleiro[46].criarVizinhanca(&tabuleiro[38]     ,&tabuleiro[39]     ,&tabuleiro[45]     ,&tabuleiro[47]     ,&tabuleiro[52]     ,&tabuleiro[53]);
	tabuleiro[47].criarVizinhanca(&tabuleiro[39]     ,&tabuleiro[40]     ,&tabuleiro[46]     ,&tabuleiro[48]     ,&tabuleiro[53]     ,&tabuleiro[54]);
	tabuleiro[48].criarVizinhanca(&tabuleiro[40]     ,&tabuleiro[41]     ,&tabuleiro[47]     ,&tabuleiro[49]     ,&tabuleiro[54]     ,&tabuleiro[55]);
	tabuleiro[49].criarVizinhanca(&tabuleiro[41]     ,&tabuleiro[42]     ,&tabuleiro[48]     ,VIZINHO_INEXISTENTE,&tabuleiro[55]     ,VIZINHO_INEXISTENTE);
	tabuleiro[50].criarVizinhanca(&tabuleiro[43]     ,&tabuleiro[44]     ,VIZINHO_INEXISTENTE,&tabuleiro[51]     ,VIZINHO_INEXISTENTE,&tabuleiro[56]);
	tabuleiro[51].criarVizinhanca(&tabuleiro[44]     ,&tabuleiro[45]     ,&tabuleiro[50]     ,&tabuleiro[52]     ,&tabuleiro[56]     ,&tabuleiro[57]);
	tabuleiro[52].criarVizinhanca(&tabuleiro[45]     ,&tabuleiro[46]     ,&tabuleiro[51]     ,&tabuleiro[53]     ,&tabuleiro[57]     ,&tabuleiro[58]);
	tabuleiro[53].criarVizinhanca(&tabuleiro[46]     ,&tabuleiro[47]     ,&tabuleiro[52]     ,&tabuleiro[54]     ,&tabuleiro[58]     ,&tabuleiro[59]);
	tabuleiro[54].criarVizinhanca(&tabuleiro[47]     ,&tabuleiro[48]     ,&tabuleiro[53]     ,&tabuleiro[55]     ,&tabuleiro[59]     ,&tabuleiro[60]);
	tabuleiro[55].criarVizinhanca(&tabuleiro[48]     ,&tabuleiro[49]     ,&tabuleiro[54]     ,VIZINHO_INEXISTENTE,&tabuleiro[60]     ,VIZINHO_INEXISTENTE);
	tabuleiro[56].criarVizinhanca(&tabuleiro[50]     ,&tabuleiro[51]     ,VIZINHO_INEXISTENTE,&tabuleiro[57]     ,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE);
	tabuleiro[57].criarVizinhanca(&tabuleiro[51]     ,&tabuleiro[52]     ,&tabuleiro[56]     ,&tabuleiro[58]     ,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE);
	tabuleiro[58].criarVizinhanca(&tabuleiro[52]     ,&tabuleiro[53]     ,&tabuleiro[57]     ,&tabuleiro[59]     ,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE);
	tabuleiro[59].criarVizinhanca(&tabuleiro[53]     ,&tabuleiro[54]     ,&tabuleiro[58]     ,&tabuleiro[60]     ,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE);
	tabuleiro[60].criarVizinhanca(&tabuleiro[54]     ,&tabuleiro[55]     ,&tabuleiro[59]     ,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE);
}
/*
* Determina se a casa de nome passado como parâmetro está ocupada por alguma peça.
* @param nomeCasa_param O nome da casa a ser verificada. Nomes de casas são constantes definidas no início deste arquivo.
* @return Booleano indicando se a casa está ocupada por alguma peça.
*/
bool tabuleiroTetralath::casaOcupada(int nomeCasa_param){
	return tabuleiro[nomeCasa_param].estahOcupada();
}

/*
* Determina se a casa de nome passado como parâmetro está ocupada por alguma peça da cor branca.
* @param nomeCasa_param O nome da casa a ser verificada. Nomes de casas são constantes definidas no início deste arquivo.
* @return Booleano indicando se a casa está ocupada por alguma peça branca.
*	Atenção: Se a casa não estiver ocupada ou se estiver ocupada por peça preta, retornará false.
*/
bool tabuleiroTetralath::casaOcupadaPorPecaBranca(int nomeCasa_param){
	return tabuleiro[nomeCasa_param].estahOcupadaPorPecaBranca();
}

/*
* Realiza uma jogada das peças passadas como parâmetro.
* @param nomeCasa_param Casa a jogar.
* @param corPecas_param Cor das peças que realizarão a jogada.
* @return Booleano indicando se foi possível realizar a jogada.
*/
bool tabuleiroTetralath::jogar(int nomeCasa_param, int corPecas_param){
	return tabuleiro[nomeCasa_param].ocuparCom(corPecas_param);
}

/*
* Indica se as brancas ganharam, isto acontece em dois casos:
*	(1) Se elas formaram uma linha de 4 peças consecutivas.
*	(2) Se as pretas formaram uma linha de 3 peças consecutivas.
* @param nomeCasaReferencia_param Um nome de casa a ser tomada como central, para referência. Tipicamente, esta será a última jogada feita.
*	Este parâmetro existe por motivos de desempenho.
* @return Booleano indicando se as brancas ganharam.
* 	Atenção: false como retorno indica apenas que as brancas não ganharam, nada diz sobre empates ou perdedores.
*/
bool tabuleiroTetralath::brancasGanharam(int nomeCasaReferencia_param){
	bool brancasVenceram = false;
	bool pretasPerderam = false;
	casaTabuleiroTetralath casaReferencia = tabuleiro[nomeCasaReferencia_param];
	//Variáveis à seguir são bitstreams que representam com 1 a presença de uma peça branca e 0 o contrário.
	unsigned short linhaHorizontalBrancas = 0x0000;
	unsigned short linhaDiagonalDecrescenteBrancas = 0x0000;
	unsigned short linhaDiagonalCrescenteBrancas = 0x0000;
	unsigned short linhaHorizontalPretas = 0x0000;
	unsigned short linhaDiagonalDecrescentePretas = 0x0000;
	unsigned short linhaDiagonalCrescentePretas = 0x0000;

	/*
	* Verificar se as brancas formaram uma linha com quatro peças consecutivas.
	* Monta-se 3 bitstream com 1s onde há peças brancas e 0s onde não há.
	* Cada bitstream corresponde a uma linha e devem ser considerados somente seus 7 bits mais significativos.
	*/
	//Montagem da linha horizontal
	if(casaReferencia.getVizinhoC() != VIZINHO_INEXISTENTE){
		if(casaReferencia.getVizinhoC()->getVizinhoC() != VIZINHO_INEXISTENTE){
			if(casaReferencia.getVizinhoC()->getVizinhoC()->getVizinhoC() != VIZINHO_INEXISTENTE
			   and casaReferencia.getVizinhoC()->getVizinhoC()->getVizinhoC()->estahOcupadaPorPecaBranca()){
				linhaHorizontalBrancas = linhaHorizontalBrancas | 0x8000;
			}
			if(casaReferencia.getVizinhoC()->getVizinhoC()->estahOcupadaPorPecaBranca()){
				linhaHorizontalBrancas = linhaHorizontalBrancas | 0x4000;
			}
		if(casaReferencia.getVizinhoC()->estahOcupadaPorPecaBranca()){
			linhaHorizontalBrancas = linhaHorizontalBrancas | 0x2000;
		}
	}
	if(casaReferencia.estahOcupadaPorPecaBranca()){
		linhaHorizontalBrancas = linhaHorizontalBrancas | 0x1000;
	}
	if(casaReferencia.getVizinhoD() != VIZINHO_INEXISTENTE){
		if(casaReferencia.getVizinhoD()->getVizinhoD() != VIZINHO_INEXISTENTE){
			if(casaReferencia.getVizinhoD()->getVizinhoD()->getVizinhoD() != VIZINHO_INEXISTENTE
			   and casaReferencia.getVizinhoD()->getVizinhoD()->getVizinhoD()->estahOcupadaPorPecaBranca()){
				linhaHorizontalBrancas = linhaHorizontalBrancas | 0x0800;
			}
			if(casaReferencia.getVizinhoD()->getVizinhoD()->estahOcupadaPorPecaBranca()){
				linhaHorizontalBrancas = linhaHorizontalBrancas | 0x0400;
			}
		if(casaReferencia.getVizinhoD()->estahOcupadaPorPecaBranca()){
			linhaHorizontalBrancas = linhaHorizontalBrancas | 0x0200;
		}
	}

	//Montagem da linha diagonal decrescente
	if(casaReferencia.getVizinhoA() != VIZINHO_INEXISTENTE){
		if(casaReferencia.getVizinhoA()->getVizinhoA() != VIZINHO_INEXISTENTE){
			if(casaReferencia.getVizinhoA()->getVizinhoA()->getVizinhoA() != VIZINHO_INEXISTENTE
			   and casaReferencia.getVizinhoA()->getVizinhoA()->getVizinhoA()->estahOcupadaPorPecaBranca()){
				linhaDiagonalDecrescenteBrancas = linhaDiagonalDecrescenteBrancas | 0x8000;
			}
			if(casaReferencia.getVizinhoA()->getVizinhoA()->estahOcupadaPorPecaBranca()){
				linhaDiagonalDecrescenteBrancas = linhaDiagonalDecrescenteBrancas | 0x4000;
			}
		if(casaReferencia.getVizinhoA()->estahOcupadaPorPecaBranca()){
			linhaDiagonalDecrescenteBrancas = linhaDiagonalDecrescenteBrancas | 0x2000;
		}
	}
	if(casaReferencia.estahOcupadaPorPecaBranca()){
		linhaDiagonalDecrescenteBrancas = linhaDiagonalDecrescenteBrancas | 0x1000;
	}
	if(casaReferencia.getVizinhoF() != VIZINHO_INEXISTENTE){
		if(casaReferencia.getVizinhoF()->getVizinhoF() != VIZINHO_INEXISTENTE){
			if(casaReferencia.getVizinhoF()->getVizinhoF()->getVizinhoF() != VIZINHO_INEXISTENTE
			   and casaReferencia.getVizinhoF()->getVizinhoF()->getVizinhoF()->estahOcupadaPorPecaBranca()){
				linhaDiagonalDecrescenteBrancas = linhaDiagonalDecrescenteBrancas | 0x0800;
			}
			if(casaReferencia.getVizinhoF()->getVizinhoF()->estahOcupadaPorPecaBranca()){
				linhaDiagonalDecrescenteBrancas = linhaDiagonalDecrescenteBrancas | 0x0400;
			}
		if(casaReferencia.getVizinhoF()->estahOcupadaPorPecaBranca()){
			linhaDiagonalDecrescenteBrancas = linhaDiagonalDecrescenteBrancas | 0x0200;
		}
	}

	//Montagem da linha diagonal crescente
	if(casaReferencia.getVizinhoE() != VIZINHO_INEXISTENTE){
		if(casaReferencia.getVizinhoE()->getVizinhoE() != VIZINHO_INEXISTENTE){
			if(casaReferencia.getVizinhoE()->getVizinhoE()->getVizinhoE() != VIZINHO_INEXISTENTE
			   and casaReferencia.getVizinhoE()->getVizinhoE()->getVizinhoE()->estahOcupadaPorPecaBranca()){
				linhaDiagonalCrescenteBrancas = linhaDiagonalCrescenteBrancas | 0x8000;
			}
			if(casaReferencia.getVizinhoE()->getVizinhoE()->estahOcupadaPorPecaBranca()){
				linhaDiagonalCrescenteBrancas = linhaDiagonalCrescenteBrancas | 0x4000;
			}
		if(casaReferencia.getVizinhoE()->estahOcupadaPorPecaBranca()){
			linhaDiagonalCrescenteBrancas = linhaDiagonalCrescenteBrancas | 0x2000;
		}
	}
	if(casaReferencia.estahOcupadaPorPecaBranca()){
		linhaDiagonalCrescenteBrancas = linhaDiagonalCrescenteBrancas | 0x1000;
	}
	if(casaReferencia.getVizinhoB() != VIZINHO_INEXISTENTE){
		if(casaReferencia.getVizinhoB()->getVizinhoB() != VIZINHO_INEXISTENTE){
			if(casaReferencia.getVizinhoB()->getVizinhoB()->getVizinhoB() != VIZINHO_INEXISTENTE
			   and casaReferencia.getVizinhoB()->getVizinhoB()->getVizinhoB()->estahOcupadaPorPecaBranca()){
				linhaDiagonalCrescenteBrancas = linhaDiagonalCrescenteBrancas | 0x0800;
			}
			if(casaReferencia.getVizinhoB()->getVizinhoB()->estahOcupadaPorPecaBranca()){
				linhaDiagonalCrescenteBrancas = linhaDiagonalCrescenteBrancas | 0x0400;
			}
		if(casaReferencia.getVizinhoB()->estahOcupadaPorPecaBranca()){
			linhaDiagonalCrescenteBrancas = linhaDiagonalCrescenteBrancas | 0x0200;
		}
	}

	//Teste das linhas
	brancasVenceram = linhaHorizontalBrancas & 0xF000
			  or linhaHorizontalBrancas & 0x7800
			  or linhaHorizontalBrancas & 0x3C00
			  or linhaHorizontalBrancas & 0x1E00
			  or linhaDiagonalDecrescenteBrancas & 0xF000
			  or linhaDiagonalDecrescenteBrancas & 0x7800
			  or linhaDiagonalDecrescenteBrancas & 0x3C00
			  or linhaDiagonalDecrescenteBrancas & 0x1E00
			  or linhaDiagonalCrescenteBrancas & 0xF000
			  or linhaDiagonalCrescenteBrancas & 0x7800
			  or linhaDiagonalCrescenteBrancas & 0x3C00
			  or linhaDiagonalCrescenteBrancas & 0x1E00;

	/*
	* Verificar se as pretas formaram uma linha com três peças consecutivas.
	* Monta-se 3 bitstream com 1s onde há peças pretas e 0s onde não há.
	* Cada bitstream corresponde a uma linha e devem ser considerados somente seus 5 bits mais significativos.
	*/
	//Montagem da linha horizontal
	if(casaReferencia.getVizinhoC() != VIZINHO_INEXISTENTE){
		if(casaReferencia.getVizinhoC()->getVizinhoC() != VIZINHO_INEXISTENTE){
			if(casaReferencia.getVizinhoC()->getVizinhoC()->estahOcupadaPorPecaPreta()){
				linhaHorizontalPretas = linhaHorizontalPretas | 0x4000;
			}
		if(casaReferencia.getVizinhoC()->estahOcupadaPorPecaPreta()){
			linhaHorizontalPretas = linhaHorizontalPretas | 0x2000;
		}
	}
	if(casaReferencia.estahOcupadaPorPecaBranca()){
		linhaHorizontalPretas = linhaHorizontalPretas | 0x1000;
	}
	if(casaReferencia.getVizinhoD() != VIZINHO_INEXISTENTE){
		if(casaReferencia.getVizinhoD()->getVizinhoD() != VIZINHO_INEXISTENTE){
			if(casaReferencia.getVizinhoD()->getVizinhoD()->estahOcupadaPorPecaPreta()){
				linhaHorizontalPretas = linhaHorizontalPretas | 0x0400;
			}
		if(casaReferencia.getVizinhoD()->estahOcupadaPorPecaPreta()){
			linhaHorizontalPretas = linhaHorizontalPretas | 0x0200;
		}
	}

	//Montagem da linha diagonal decrescente
	if(casaReferencia.getVizinhoA() != VIZINHO_INEXISTENTE){
		if(casaReferencia.getVizinhoA()->getVizinhoA() != VIZINHO_INEXISTENTE){
			if(casaReferencia.getVizinhoA()->getVizinhoA()->estahOcupadaPorPecaPreta()){
				linhaDiagonalDecrescentePretas = linhaDiagonalDecrescentePretas | 0x4000;
			}
		if(casaReferencia.getVizinhoA()->estahOcupadaPorPecaPreta()){
			linhaDiagonalDecrescentePretas = linhaDiagonalDecrescentePretas | 0x2000;
		}
	}
	if(casaReferencia.estahOcupadaPorPecaBranca()){
		linhaDiagonalDecrescentePretas = linhaDiagonalDecrescentePretas | 0x1000;
	}
	if(casaReferencia.getVizinhoF() != VIZINHO_INEXISTENTE){
		if(casaReferencia.getVizinhoF()->getVizinhoF() != VIZINHO_INEXISTENTE){
			if(casaReferencia.getVizinhoF()->getVizinhoF()->estahOcupadaPorPecaPreta()){
				linhaDiagonalDecrescentePretas = linhaDiagonalDecrescentePretas | 0x0400;
			}
		if(casaReferencia.getVizinhoF()->estahOcupadaPorPecaPreta()){
			linhaDiagonalDecrescentePretas = linhaDiagonalDecrescentePretas | 0x0200;
		}
	}

	//Montagem da linha diagonal crescente
	if(casaReferencia.getVizinhoE() != VIZINHO_INEXISTENTE){
		if(casaReferencia.getVizinhoE()->getVizinhoE() != VIZINHO_INEXISTENTE){
			if(casaReferencia.getVizinhoE()->getVizinhoE()->estahOcupadaPorPecaPreta()){
				linhaDiagonalCrescentePretas = linhaDiagonalCrescentePretas | 0x4000;
			}
		if(casaReferencia.getVizinhoE()->estahOcupadaPorPecaPreta()){
			linhaDiagonalCrescentePretas = linhaDiagonalCrescentePretas | 0x2000;
		}
	}
	if(casaReferencia.estahOcupadaPorPecaBranca()){
		linhaDiagonalCrescentePretas = linhaDiagonalCrescentePretas | 0x1000;
	}
	if(casaReferencia.getVizinhoB() != VIZINHO_INEXISTENTE){
		if(casaReferencia.getVizinhoB()->getVizinhoB() != VIZINHO_INEXISTENTE){
			if(casaReferencia.getVizinhoB()->getVizinhoB()->estahOcupadaPorPecaPreta()){
				linhaDiagonalCrescentePretas = linhaDiagonalCrescentePretas | 0x0400;
			}
		if(casaReferencia.getVizinhoB()->estahOcupadaPorPecaPreta()){
			linhaDiagonalCrescentePretas = linhaDiagonalCrescentePretas | 0x0200;
		}
	}

	//Teste das linhas
	pretasPerderam = linhaHorizontalPretas & 0xE000
			 or linhaHorizontalPretas & 0x7000
			 or linhaHorizontalPretas & 0x3800
			 or linhaDiagonalDecrescentePretas & 0xE000
			 or linhaDiagonalDecrescentePretas & 0x7000
			 or linhaDiagonalDecrescentePretas & 0x3800
			 or linhaDiagonalCrescentePretas & 0xE000
			 or linhaDiagonalCrescentePretas & 0x7000
			 or linhaDiagonalCrescentePretas & 0x3800;

	return brancasVenceram or pretasPerderam;
}
/*
* Indica se as brancas perderam, isto acontece em dois casos:
*	(1) Brancas formaram uma linha de 3 peças consecutivas.
*	(2) Pretas formaram uma linha de 4 peças consecutivas.
* @param nomeCasaReferencia_param Um nome de casa a ser tomada como central, para referência. Tipicamente, esta será a última jogada feita.
*	Este parâmetro existe por motivos de desempenho.
* @return Booleano indicando se o jogador perdeu.
* 	Atenção: false como retorno indica apenas que as brancas não perderam, nada diz sobre ganhadores ou empates.
*/
bool tabuleiroTetralath::brancasPerderam(int nomeCasaReferencia_param){


}

/*
* Indica se o tabuleiro está em estado de empate.
* @return Booleano indicando se houve empate.
* 	Atenção: false como retorno indica apenas que não houve empate, nada diz sobre ganhadores ou perdedores.
*/
bool tabuleiroTetralath::houveEmpate(void){
	int indiceCasa=0;
	bool encontrouCasaDesocupada = false;
	while(!encontrouCasaDesocupada and indiceCasa<NUMERO_CASAS){
		encontrouCasaDesocupada = !tabuleiro[indiceCasa].estahOcupada();
		indiceCasa++;
	}
	return !encontrouCasaDesocupada;
}



};
