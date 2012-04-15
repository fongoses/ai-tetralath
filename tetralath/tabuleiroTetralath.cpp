#include "tabuleiroTetralath.h"

/*
* Classe que implementa um tabuleiro do jogo Tetralath.
*/
/*
* Construtor da classe.
* Inicializa todas as casas com seus vizinhos.
*/
tabuleiroTetralath::tabuleiroTetralath(){
	int indiceCasa = 0;
	tabuleiro = new casaTabuleiroTetralath*[NUMERO_CASAS];
	for(indiceCasa=0; indiceCasa<NUMERO_CASAS; indiceCasa++){
		tabuleiro[indiceCasa] = new casaTabuleiroTetralath();
	}

	//Criação do tabuleiro. Para informações sobre vizinhanças, verificar figuras anexas ao projeto.
	 tabuleiro[0]->criarVizinhanca(VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,tabuleiro[1]       ,tabuleiro[5]       ,tabuleiro[6]);
	 tabuleiro[1]->criarVizinhanca(VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,tabuleiro[0]       ,tabuleiro[2]       ,tabuleiro[6]       ,tabuleiro[7]);
	 tabuleiro[2]->criarVizinhanca(VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,tabuleiro[1]       ,tabuleiro[3]       ,tabuleiro[7]       ,tabuleiro[8]);
	 tabuleiro[3]->criarVizinhanca(VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,tabuleiro[2]       ,tabuleiro[4]       ,tabuleiro[8]       ,tabuleiro[9]);
	 tabuleiro[4]->criarVizinhanca(VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,tabuleiro[3]       ,VIZINHO_INEXISTENTE,tabuleiro[9]       ,tabuleiro[10]);
	 tabuleiro[5]->criarVizinhanca(VIZINHO_INEXISTENTE,tabuleiro[0]       ,VIZINHO_INEXISTENTE,tabuleiro[6]       ,tabuleiro[11]      ,tabuleiro[12]);
	 tabuleiro[6]->criarVizinhanca(tabuleiro[0]       ,tabuleiro[1]       ,tabuleiro[5]       ,tabuleiro[7]       ,tabuleiro[12]      ,tabuleiro[13]);
	 tabuleiro[7]->criarVizinhanca(tabuleiro[1]       ,tabuleiro[2]       ,tabuleiro[6]       ,tabuleiro[8]       ,tabuleiro[13]      ,tabuleiro[14]);
	 tabuleiro[8]->criarVizinhanca(tabuleiro[2]       ,tabuleiro[3]       ,tabuleiro[7]       ,tabuleiro[9]       ,tabuleiro[14]      ,tabuleiro[15]);
	 tabuleiro[9]->criarVizinhanca(tabuleiro[3]       ,tabuleiro[4]       ,tabuleiro[8]       ,tabuleiro[10]      ,tabuleiro[15]      ,tabuleiro[16]);
	tabuleiro[10]->criarVizinhanca(tabuleiro[4]       ,VIZINHO_INEXISTENTE,tabuleiro[9]       ,VIZINHO_INEXISTENTE,tabuleiro[16]      ,tabuleiro[17]);
	tabuleiro[11]->criarVizinhanca(VIZINHO_INEXISTENTE,tabuleiro[5]       ,VIZINHO_INEXISTENTE,tabuleiro[12]      ,tabuleiro[18]      ,tabuleiro[19]);
	tabuleiro[12]->criarVizinhanca(tabuleiro[5]       ,tabuleiro[6]       ,tabuleiro[11]      ,tabuleiro[13]      ,tabuleiro[19]      ,tabuleiro[20]);
	tabuleiro[13]->criarVizinhanca(tabuleiro[6]       ,tabuleiro[7]       ,tabuleiro[12]      ,tabuleiro[14]      ,tabuleiro[20]      ,tabuleiro[21]);
	tabuleiro[14]->criarVizinhanca(tabuleiro[7]       ,tabuleiro[8]       ,tabuleiro[13]      ,tabuleiro[15]      ,tabuleiro[21]      ,tabuleiro[22]);
	tabuleiro[15]->criarVizinhanca(tabuleiro[8]       ,tabuleiro[9]       ,tabuleiro[14]      ,tabuleiro[16]      ,tabuleiro[22]      ,tabuleiro[23]);
	tabuleiro[16]->criarVizinhanca(tabuleiro[9]       ,tabuleiro[10]      ,tabuleiro[15]      ,tabuleiro[17]      ,tabuleiro[23]      ,tabuleiro[24]);
	tabuleiro[17]->criarVizinhanca(tabuleiro[10]      ,VIZINHO_INEXISTENTE,tabuleiro[16]      ,VIZINHO_INEXISTENTE,tabuleiro[24]      ,tabuleiro[25]);
	tabuleiro[18]->criarVizinhanca(VIZINHO_INEXISTENTE,tabuleiro[11]      ,VIZINHO_INEXISTENTE,tabuleiro[19]      ,tabuleiro[26]      ,tabuleiro[27]);
	tabuleiro[19]->criarVizinhanca(tabuleiro[11]      ,tabuleiro[12]      ,tabuleiro[18]      ,tabuleiro[20]      ,tabuleiro[27]      ,tabuleiro[28]);
	tabuleiro[20]->criarVizinhanca(tabuleiro[12]      ,tabuleiro[13]      ,tabuleiro[19]      ,tabuleiro[21]      ,tabuleiro[28]      ,tabuleiro[29]);
	tabuleiro[21]->criarVizinhanca(tabuleiro[13]      ,tabuleiro[14]      ,tabuleiro[20]      ,tabuleiro[22]      ,tabuleiro[29]      ,tabuleiro[30]);
	tabuleiro[22]->criarVizinhanca(tabuleiro[14]      ,tabuleiro[15]      ,tabuleiro[21]      ,tabuleiro[23]      ,tabuleiro[30]      ,tabuleiro[31]);
	tabuleiro[23]->criarVizinhanca(tabuleiro[15]      ,tabuleiro[16]      ,tabuleiro[22]      ,tabuleiro[24]      ,tabuleiro[31]      ,tabuleiro[32]);
	tabuleiro[24]->criarVizinhanca(tabuleiro[16]      ,tabuleiro[17]      ,tabuleiro[23]      ,tabuleiro[25]      ,tabuleiro[32]      ,tabuleiro[33]);
	tabuleiro[25]->criarVizinhanca(tabuleiro[17]      ,VIZINHO_INEXISTENTE,tabuleiro[24]      ,VIZINHO_INEXISTENTE,tabuleiro[33]      ,tabuleiro[34]);
	tabuleiro[26]->criarVizinhanca(VIZINHO_INEXISTENTE,tabuleiro[18]      ,VIZINHO_INEXISTENTE,tabuleiro[27]      ,VIZINHO_INEXISTENTE,tabuleiro[35]);
	tabuleiro[27]->criarVizinhanca(tabuleiro[18]      ,tabuleiro[19]      ,tabuleiro[26]      ,tabuleiro[28]      ,tabuleiro[35]      ,tabuleiro[36]);
	tabuleiro[28]->criarVizinhanca(tabuleiro[19]      ,tabuleiro[20]      ,tabuleiro[27]      ,tabuleiro[29]      ,tabuleiro[36]      ,tabuleiro[37]);
	tabuleiro[29]->criarVizinhanca(tabuleiro[20]      ,tabuleiro[21]      ,tabuleiro[28]      ,tabuleiro[30]      ,tabuleiro[37]      ,tabuleiro[38]);
	tabuleiro[30]->criarVizinhanca(tabuleiro[21]      ,tabuleiro[22]      ,tabuleiro[29]      ,tabuleiro[31]      ,tabuleiro[38]      ,tabuleiro[39]);
	tabuleiro[31]->criarVizinhanca(tabuleiro[22]      ,tabuleiro[23]      ,tabuleiro[30]      ,tabuleiro[32]      ,tabuleiro[39]      ,tabuleiro[40]);
	tabuleiro[32]->criarVizinhanca(tabuleiro[23]      ,tabuleiro[24]      ,tabuleiro[31]      ,tabuleiro[33]      ,tabuleiro[40]      ,tabuleiro[41]);
	tabuleiro[33]->criarVizinhanca(tabuleiro[24]      ,tabuleiro[25]      ,tabuleiro[32]      ,tabuleiro[34]      ,tabuleiro[41]      ,tabuleiro[42]);
	tabuleiro[34]->criarVizinhanca(tabuleiro[25]      ,VIZINHO_INEXISTENTE,tabuleiro[33]      ,VIZINHO_INEXISTENTE,tabuleiro[42]      ,VIZINHO_INEXISTENTE);
	tabuleiro[35]->criarVizinhanca(tabuleiro[26]      ,tabuleiro[27]      ,VIZINHO_INEXISTENTE,tabuleiro[36]      ,VIZINHO_INEXISTENTE,tabuleiro[43]);
	tabuleiro[36]->criarVizinhanca(tabuleiro[27]      ,tabuleiro[28]      ,tabuleiro[35]      ,tabuleiro[37]      ,tabuleiro[43]      ,tabuleiro[44]);
	tabuleiro[37]->criarVizinhanca(tabuleiro[28]      ,tabuleiro[29]      ,tabuleiro[36]      ,tabuleiro[38]      ,tabuleiro[44]      ,tabuleiro[45]);
	tabuleiro[38]->criarVizinhanca(tabuleiro[29]      ,tabuleiro[30]      ,tabuleiro[37]      ,tabuleiro[39]      ,tabuleiro[45]      ,tabuleiro[46]);
	tabuleiro[39]->criarVizinhanca(tabuleiro[30]      ,tabuleiro[31]      ,tabuleiro[38]      ,tabuleiro[40]      ,tabuleiro[46]      ,tabuleiro[47]);
	tabuleiro[40]->criarVizinhanca(tabuleiro[31]      ,tabuleiro[32]      ,tabuleiro[39]      ,tabuleiro[41]      ,tabuleiro[47]      ,tabuleiro[48]);
	tabuleiro[41]->criarVizinhanca(tabuleiro[32]      ,tabuleiro[33]      ,tabuleiro[40]      ,tabuleiro[42]      ,tabuleiro[48]      ,tabuleiro[49]);
	tabuleiro[42]->criarVizinhanca(tabuleiro[33]      ,tabuleiro[34]      ,tabuleiro[41]      ,VIZINHO_INEXISTENTE,tabuleiro[49]      ,VIZINHO_INEXISTENTE);
	tabuleiro[43]->criarVizinhanca(tabuleiro[35]      ,tabuleiro[36]      ,VIZINHO_INEXISTENTE,tabuleiro[44]      ,VIZINHO_INEXISTENTE,tabuleiro[50]);
	tabuleiro[44]->criarVizinhanca(tabuleiro[36]      ,tabuleiro[37]      ,tabuleiro[43]      ,tabuleiro[45]      ,tabuleiro[50]      ,tabuleiro[51]);
	tabuleiro[45]->criarVizinhanca(tabuleiro[37]      ,tabuleiro[38]      ,tabuleiro[44]      ,tabuleiro[46]      ,tabuleiro[51]      ,tabuleiro[52]);
	tabuleiro[46]->criarVizinhanca(tabuleiro[38]      ,tabuleiro[39]      ,tabuleiro[45]      ,tabuleiro[47]      ,tabuleiro[52]      ,tabuleiro[53]);
	tabuleiro[47]->criarVizinhanca(tabuleiro[39]      ,tabuleiro[40]      ,tabuleiro[46]      ,tabuleiro[48]      ,tabuleiro[53]      ,tabuleiro[54]);
	tabuleiro[48]->criarVizinhanca(tabuleiro[40]      ,tabuleiro[41]      ,tabuleiro[47]      ,tabuleiro[49]      ,tabuleiro[54]      ,tabuleiro[55]);
	tabuleiro[49]->criarVizinhanca(tabuleiro[41]      ,tabuleiro[42]      ,tabuleiro[48]      ,VIZINHO_INEXISTENTE,tabuleiro[55]      ,VIZINHO_INEXISTENTE);
	tabuleiro[50]->criarVizinhanca(tabuleiro[43]      ,tabuleiro[44]      ,VIZINHO_INEXISTENTE,tabuleiro[51]      ,VIZINHO_INEXISTENTE,tabuleiro[56]);
	tabuleiro[51]->criarVizinhanca(tabuleiro[44]      ,tabuleiro[45]      ,tabuleiro[50]      ,tabuleiro[52]      ,tabuleiro[56]      ,tabuleiro[57]);
	tabuleiro[52]->criarVizinhanca(tabuleiro[45]      ,tabuleiro[46]      ,tabuleiro[51]      ,tabuleiro[53]      ,tabuleiro[57]      ,tabuleiro[58]);
	tabuleiro[53]->criarVizinhanca(tabuleiro[46]      ,tabuleiro[47]      ,tabuleiro[52]      ,tabuleiro[54]      ,tabuleiro[58]      ,tabuleiro[59]);
	tabuleiro[54]->criarVizinhanca(tabuleiro[47]      ,tabuleiro[48]      ,tabuleiro[53]      ,tabuleiro[55]      ,tabuleiro[59]      ,tabuleiro[60]);
	tabuleiro[55]->criarVizinhanca(tabuleiro[48]      ,tabuleiro[49]      ,tabuleiro[54]      ,VIZINHO_INEXISTENTE,tabuleiro[60]      ,VIZINHO_INEXISTENTE);
	tabuleiro[56]->criarVizinhanca(tabuleiro[50]      ,tabuleiro[51]      ,VIZINHO_INEXISTENTE,tabuleiro[57]      ,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE);
	tabuleiro[57]->criarVizinhanca(tabuleiro[51]      ,tabuleiro[52]      ,tabuleiro[56]      ,tabuleiro[58]      ,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE);
	tabuleiro[58]->criarVizinhanca(tabuleiro[52]      ,tabuleiro[53]      ,tabuleiro[57]      ,tabuleiro[59]      ,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE);
	tabuleiro[59]->criarVizinhanca(tabuleiro[53]      ,tabuleiro[54]      ,tabuleiro[58]      ,tabuleiro[60]      ,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE);
	tabuleiro[60]->criarVizinhanca(tabuleiro[54]      ,tabuleiro[55]      ,tabuleiro[59]      ,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE);
}
/*
* Determina se a casa de nome passado como parâmetro está ocupada por alguma peça.
* @param nomeCasa_param O nome da casa a ser verificada. Nomes de casas são constantes definidas no início deste arquivo.
* @return Booleano indicando se a casa está ocupada por alguma peça.
*/
bool tabuleiroTetralath::casaOcupada(int nomeCasa_param){
	return tabuleiro[nomeCasa_param]->estahOcupada();
}

/*
* Determina se a casa de nome passado como parâmetro está ocupada por alguma peça da cor branca.
* @param nomeCasa_param O nome da casa a ser verificada. Nomes de casas são constantes definidas no início deste arquivo.
* @return Booleano indicando se a casa está ocupada por alguma peça branca.
*	Atenção: Se a casa não estiver ocupada ou se estiver ocupada por peça preta, retornará false.
*/
bool tabuleiroTetralath::casaOcupadaPorPecaBranca(int nomeCasa_param){
	return tabuleiro[nomeCasa_param]->estahOcupadaPorPecaBranca();
}

/*
* Realiza uma jogada das peças passadas como parâmetro.
* @param nomeCasa_param Casa a jogar.
* @param corPecas_param Cor das peças que realizarão a jogada.
* @return Booleano indicando se foi possível realizar a jogada.
*/
bool tabuleiroTetralath::jogar(int nomeCasa_param, int corPecas_param){
	return tabuleiro[nomeCasa_param]->ocuparCom(corPecas_param);
}

/*
* Indica se as peças da cor da peça parâmetro ganharam, isto acontece em um caso:
*	(1) Se elas formaram uma linha de 4 peças consecutivas.
* @param nomeCasaReferencia_param Um nome de casa a ser tomada como central, para referência. Tipicamente, esta será a última jogada feita.
*	Este parâmetro existe por motivos de desempenho.
* @return Booleano indicando se as peças da cor da peça parâmetro ganharam.
* 	Atenção: false como retorno indica apenas que as peças parâmetro não ganharam, nada diz sobre empates ou perdedores.
*/
bool tabuleiroTetralath::pecasDaMesmaCorGanharam(int nomeCasaReferencia_param){
	return haSequenciaCasasMesmaCor(nomeCasaReferencia_param, 4);
}
/*
* Indica se as peças da cor da peça parâmetro perderam, isto acontece em um caso:
*	(1) Estas peças formaram uma linha de 3 peças consecutivas.
* @param nomeCasaReferencia_param Um nome de casa a ser tomada como central, para referência. Tipicamente, esta será a última jogada feita.
*	Este parâmetro existe por motivos de desempenho.
* @return Booleano indicando se as peças da cor da peça parâmetro perderam.
* 	Atenção: false como retorno indica apenas que as peças parâmetro não perderam, nada diz sobre ganhadores ou empates.
*/
bool tabuleiroTetralath::pecasDaMesmaCorPerderam(int nomeCasaReferencia_param){
	return (haSequenciaCasasMesmaCor(nomeCasaReferencia_param, 3) and not haSequenciaCasasMesmaCor(nomeCasaReferencia_param, 4));
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
		encontrouCasaDesocupada = !tabuleiro[indiceCasa]->estahOcupada();
		indiceCasa++;
	}
	return !encontrouCasaDesocupada;
}

/*
* Procura por uma seqüência de um número de casas ocupadas por peças da mesma cor.
* A cor testada é a mesma da peça da casa considerada central.
* Esta função verificará as três linhas possíveis ao redor da casa central:
*	(1) Horizontal
*	(2) Diagonal Decrescente
*	(3) Diagonal Crescente
* Somente serão verificadas casas nestas linhas e a uma distância de adjacência de (tamanhoSequencia_param - 1) casas.
* Desta forma, para a linha horizontal e tamanhoSequencia_param = 4, teríamos:
*	casa_não_testada,casa_testada,casa_testada,casa_testada,casa_central,casa_testada,casa_testada,casa_testada,casa_não_testada
* @param nomeCasa_param Um índice (em tabuleiro) da casa que fica no centro da linha testada.
* @param tamanhoSequencia_param O tamanho que a seqüência de casas da mesma cor precisa ter para ser considerada válida.
* @return Booleano indicando se há alguma seqüência (com o número especificado) de casas adjacentes com peças da mesma cor.
* Atenção: Esta função aceita apenas tamanhos de seqüência 3 e 4. Retornará sempre false caso outro número seja passado.
*/
bool tabuleiroTetralath::haSequenciaCasasMesmaCor(int nomeCasa_param, int tamanhoSequencia_param){
	bool existeSequenciaCasasMesmaCor = false;
	casaTabuleiroTetralath *casaAux;
	casaTabuleiroTetralath casaReferencia = *tabuleiro[nomeCasa_param];
	//Variáveis à seguir são bitstreams que representam com 1 a presença de uma peça da mesma cor da peça de parâmetro e 0 caso contrário.
	unsigned short linhaHorizontal = 0x0000;
	unsigned short linhaDiagonalDecrescente = 0x0000;
	unsigned short linhaDiagonalCrescente = 0x0000;

	if(tamanhoSequencia_param == 3 and casaReferencia.estahOcupadaPorPecaBranca()){
		/***************************************
		* Montagem da linha horizontal
		*/
		casaAux = casaReferencia.getCasaDistanciaDesta(-2, LINHA_HORIZONTAL);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaHorizontal = linhaHorizontal | 0x8000;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(-1, LINHA_HORIZONTAL);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaHorizontal = linhaHorizontal | 0x4000;
		}
		
		linhaHorizontal = linhaHorizontal | 0x2000;
		
		casaAux = casaReferencia.getCasaDistanciaDesta(1, LINHA_HORIZONTAL);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaHorizontal = linhaHorizontal | 0x1000;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(2, LINHA_HORIZONTAL);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaHorizontal = linhaHorizontal | 0x0800;
		}

		/***************************************
		* Montagem da linha diagonal decrescente
		*/
		casaAux = casaReferencia.getCasaDistanciaDesta(-2, LINHA_DIAGONAL_DECRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x8000;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(-1, LINHA_DIAGONAL_DECRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x4000;
		}
		
		linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x2000;
		
		casaAux = casaReferencia.getCasaDistanciaDesta(1, LINHA_DIAGONAL_DECRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x1000;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(2, LINHA_DIAGONAL_DECRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x0800;
		}

		/***************************************
		* Montagem da linha diagonal crescente
		*/
		casaAux = casaReferencia.getCasaDistanciaDesta(-2, LINHA_DIAGONAL_CRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaDiagonalCrescente = linhaDiagonalCrescente | 0x8000;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(-1, LINHA_DIAGONAL_CRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaDiagonalCrescente = linhaDiagonalCrescente | 0x4000;
		}
		
		linhaDiagonalCrescente = linhaDiagonalCrescente | 0x2000;
		
		casaAux = casaReferencia.getCasaDistanciaDesta(1, LINHA_DIAGONAL_CRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaDiagonalCrescente = linhaDiagonalCrescente | 0x1000;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(2, LINHA_DIAGONAL_CRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaDiagonalCrescente = linhaDiagonalCrescente | 0x0800;
		}
	} else if(tamanhoSequencia_param == 3 and casaReferencia.estahOcupadaPorPecaPreta()){
		/***************************************
		* Montagem da linha horizontal
		*/
		casaAux = casaReferencia.getCasaDistanciaDesta(-2, LINHA_HORIZONTAL);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaHorizontal = linhaHorizontal | 0x8000;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(-1, LINHA_HORIZONTAL);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaHorizontal = linhaHorizontal | 0x4000;
		}
		
		linhaHorizontal = linhaHorizontal | 0x2000;
		
		casaAux = casaReferencia.getCasaDistanciaDesta(1, LINHA_HORIZONTAL);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaHorizontal = linhaHorizontal | 0x1000;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(2, LINHA_HORIZONTAL);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaHorizontal = linhaHorizontal | 0x0800;
		}

		/***************************************
		* Montagem da linha diagonal decrescente
		*/
		casaAux = casaReferencia.getCasaDistanciaDesta(-2, LINHA_DIAGONAL_DECRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x8000;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(-1, LINHA_DIAGONAL_DECRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x4000;
		}
		
		linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x2000;
		
		casaAux = casaReferencia.getCasaDistanciaDesta(1, LINHA_DIAGONAL_DECRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x1000;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(2, LINHA_DIAGONAL_DECRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x0800;
		}

		/***************************************
		* Montagem da linha diagonal crescente
		*/
		casaAux = casaReferencia.getCasaDistanciaDesta(-2, LINHA_DIAGONAL_CRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaDiagonalCrescente = linhaDiagonalCrescente | 0x8000;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(-1, LINHA_DIAGONAL_CRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaDiagonalCrescente = linhaDiagonalCrescente | 0x4000;
		}
		
		linhaDiagonalCrescente = linhaDiagonalCrescente | 0x2000;
		
		casaAux = casaReferencia.getCasaDistanciaDesta(1, LINHA_DIAGONAL_CRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaDiagonalCrescente = linhaDiagonalCrescente | 0x1000;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(2, LINHA_DIAGONAL_CRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaDiagonalCrescente = linhaDiagonalCrescente | 0x0800;
		}
	} else if(tamanhoSequencia_param == 4 and casaReferencia.estahOcupadaPorPecaBranca()){
		/***************************************
		* Montagem da linha horizontal
		*/
		casaAux = casaReferencia.getCasaDistanciaDesta(-3, LINHA_HORIZONTAL);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaHorizontal = linhaHorizontal | 0x8000;
		}

		casaAux = casaReferencia.getCasaDistanciaDesta(-2, LINHA_HORIZONTAL);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaHorizontal = linhaHorizontal | 0x4000;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(-1, LINHA_HORIZONTAL);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaHorizontal = linhaHorizontal | 0x2000;
		}
		
		linhaHorizontal = linhaHorizontal | 0x1000;
		
		casaAux = casaReferencia.getCasaDistanciaDesta(1, LINHA_HORIZONTAL);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaHorizontal = linhaHorizontal | 0x0800;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(2, LINHA_HORIZONTAL);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaHorizontal = linhaHorizontal | 0x0400;
		}

		casaAux = casaReferencia.getCasaDistanciaDesta(3, LINHA_HORIZONTAL);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaHorizontal = linhaHorizontal | 0x0200;
		}

		/***************************************
		* Montagem da linha diagonal decrescente
		*/
		casaAux = casaReferencia.getCasaDistanciaDesta(-3, LINHA_DIAGONAL_DECRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x8000;
		}

		casaAux = casaReferencia.getCasaDistanciaDesta(-2, LINHA_DIAGONAL_DECRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x4000;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(-1, LINHA_DIAGONAL_DECRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x2000;
		}
		
		linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x1000;
		
		casaAux = casaReferencia.getCasaDistanciaDesta(1, LINHA_DIAGONAL_DECRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x0800;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(2, LINHA_DIAGONAL_DECRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x0400;
		}

		casaAux = casaReferencia.getCasaDistanciaDesta(3, LINHA_DIAGONAL_DECRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x0200;
		}

		/***************************************
		* Montagem da linha diagonal crescente
		*/
		casaAux = casaReferencia.getCasaDistanciaDesta(-3, LINHA_DIAGONAL_CRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaDiagonalCrescente = linhaDiagonalCrescente | 0x8000;
		}

		casaAux = casaReferencia.getCasaDistanciaDesta(-2, LINHA_DIAGONAL_CRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaDiagonalCrescente = linhaDiagonalCrescente | 0x4000;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(-1, LINHA_DIAGONAL_CRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaDiagonalCrescente = linhaDiagonalCrescente | 0x2000;
		}
		
		linhaDiagonalCrescente = linhaDiagonalCrescente | 0x1000;
		
		casaAux = casaReferencia.getCasaDistanciaDesta(1, LINHA_DIAGONAL_CRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaDiagonalCrescente = linhaDiagonalCrescente | 0x0800;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(2, LINHA_DIAGONAL_CRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaDiagonalCrescente = linhaDiagonalCrescente | 0x0400;
		}

		casaAux = casaReferencia.getCasaDistanciaDesta(3, LINHA_DIAGONAL_CRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaBranca()){
			linhaDiagonalCrescente = linhaDiagonalCrescente | 0x0200;
		}
	} else if(tamanhoSequencia_param == 4 and casaReferencia.estahOcupadaPorPecaPreta()){
		/***************************************
		* Montagem da linha horizontal
		*/
		casaAux = casaReferencia.getCasaDistanciaDesta(-3, LINHA_HORIZONTAL);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaHorizontal = linhaHorizontal | 0x8000;
		}

		casaAux = casaReferencia.getCasaDistanciaDesta(-2, LINHA_HORIZONTAL);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaHorizontal = linhaHorizontal | 0x4000;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(-1, LINHA_HORIZONTAL);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaHorizontal = linhaHorizontal | 0x2000;
		}
		
		linhaHorizontal = linhaHorizontal | 0x1000;
		
		casaAux = casaReferencia.getCasaDistanciaDesta(1, LINHA_HORIZONTAL);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaHorizontal = linhaHorizontal | 0x0800;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(2, LINHA_HORIZONTAL);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaHorizontal = linhaHorizontal | 0x0400;
		}

		casaAux = casaReferencia.getCasaDistanciaDesta(3, LINHA_HORIZONTAL);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaHorizontal = linhaHorizontal | 0x0200;
		}

		/***************************************
		* Montagem da linha diagonal decrescente
		*/
		casaAux = casaReferencia.getCasaDistanciaDesta(-3, LINHA_DIAGONAL_DECRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x8000;
		}

		casaAux = casaReferencia.getCasaDistanciaDesta(-2, LINHA_DIAGONAL_DECRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x4000;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(-1, LINHA_DIAGONAL_DECRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x2000;
		}
		
		linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x1000;
		
		casaAux = casaReferencia.getCasaDistanciaDesta(1, LINHA_DIAGONAL_DECRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x0800;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(2, LINHA_DIAGONAL_DECRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x0400;
		}

		casaAux = casaReferencia.getCasaDistanciaDesta(3, LINHA_DIAGONAL_DECRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaDiagonalDecrescente = linhaDiagonalDecrescente | 0x0200;
		}

		/***************************************
		* Montagem da linha diagonal crescente
		*/
		casaAux = casaReferencia.getCasaDistanciaDesta(-3, LINHA_DIAGONAL_CRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaDiagonalCrescente = linhaDiagonalCrescente | 0x8000;
		}

		casaAux = casaReferencia.getCasaDistanciaDesta(-2, LINHA_DIAGONAL_CRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaDiagonalCrescente = linhaDiagonalCrescente | 0x4000;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(-1, LINHA_DIAGONAL_CRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaDiagonalCrescente = linhaDiagonalCrescente | 0x2000;
		}
		
		linhaDiagonalCrescente = linhaDiagonalCrescente | 0x1000;
		
		casaAux = casaReferencia.getCasaDistanciaDesta(1, LINHA_DIAGONAL_CRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaDiagonalCrescente = linhaDiagonalCrescente | 0x0800;
		}
		
		casaAux = casaReferencia.getCasaDistanciaDesta(2, LINHA_DIAGONAL_CRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaDiagonalCrescente = linhaDiagonalCrescente | 0x0400;
		}

		casaAux = casaReferencia.getCasaDistanciaDesta(3, LINHA_DIAGONAL_CRESCENTE);
		if(casaAux != VIZINHO_INEXISTENTE and casaAux->estahOcupadaPorPecaPreta()){
			linhaDiagonalCrescente = linhaDiagonalCrescente | 0x0200;
		}
	}

	if(tamanhoSequencia_param == 3){
		existeSequenciaCasasMesmaCor = ((linhaHorizontal & 0xE000) == 0xE000)
					       or ((linhaHorizontal & 0x7000) == 0x7000)
					       or ((linhaHorizontal & 0x3800) == 0x3800)
					       or ((linhaDiagonalDecrescente & 0xE000) == 0xE000)
					       or ((linhaDiagonalDecrescente & 0x7000) == 0x7000)
					       or ((linhaDiagonalDecrescente & 0x3800) == 0x3800)
					       or ((linhaDiagonalCrescente & 0xE000) == 0xE000)
					       or ((linhaDiagonalCrescente & 0x7000) == 0x7000)
					       or ((linhaDiagonalCrescente & 0x3800) == 0x3800);
	} else if(tamanhoSequencia_param == 4){
		existeSequenciaCasasMesmaCor = ((linhaHorizontal & 0xF000) == 0xF000)
					       or ((linhaHorizontal & 0x7800) == 0x7800)
					       or ((linhaHorizontal & 0x3C00) == 0x3C00)
					       or ((linhaHorizontal & 0x1E00) == 0x1E00)
					       or ((linhaDiagonalDecrescente & 0xF000) == 0xF000)
					       or ((linhaDiagonalDecrescente & 0x7800) == 0x7800)
					       or ((linhaDiagonalDecrescente & 0x3C00) == 0x3C00)
					       or ((linhaDiagonalDecrescente & 0x1E00) == 0x1E00)
					       or ((linhaDiagonalCrescente & 0xF000) == 0xF000)
					       or ((linhaDiagonalCrescente & 0x7800) == 0x7800)
					       or ((linhaDiagonalCrescente & 0x3C00) == 0x3C00)
					       or ((linhaDiagonalCrescente & 0x1E00) == 0x1E00);
	}

	return existeSequenciaCasasMesmaCor;
}












