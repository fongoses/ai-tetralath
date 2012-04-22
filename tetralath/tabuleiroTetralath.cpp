#include "tabuleiroTetralath.h"

/*
* Atenção! Só funcionarão no linux!
*/
#define COR_VERDE \033[22;32m
#define COR_VERMELHA \033[22;31m
#define COR_PRETA \033[22;30m
#define COR_BRANCA \033[01;37m
#define COR_CINZA \033[22;37m

/*
* Classe que implementa um tabuleiro do jogo Tetralath.
*/

/*************************************************************************************
* ATENÇÃO: À partir daqui, todos métodos são públicos
*************************************************************************************/

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
	casaUltimaJogada = nomeCasa_param;
	corUltimaJogada = corPecas_param;
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
* @return O nome da casa na qual foi feita a última jogada.
*/
int tabuleiroTetralath::recuperarNomeCasaUltimaJogada(void){
	return casaUltimaJogada;
}

/*
* @return Ponteiro cópia do objeto em que for invocada. A cópia possui exatamente o mesmo conteúdo,
* 		  mas é armazenada em outra posição de memória.
*/
tabuleiroTetralath* clonar(void){
	tabuleiroTetralath tabuleiroClone = new tabuleiroTetralath();
	tabuleiroClone.copiarDe(this);
	return tabuleiroClone;
}

/*
* Torna o objeto no qual é invocado uma cópia do objeto que é passado como parâmetro. As cópias ocupam posições diferentes de memória.
* @param modelo_param Tabuleiro que será copiado.
*/
void copiarDe(tabuleiroTetralath modelo_param){
	for(int nomeCasa=INDICE_PRIMEIRA_CASA; nomeCasa<NUMERO_CASAS; nomeCasa++){
		if(modelo_param.casaOcupada(nomeCasa)){
			if(modelo_param.casaOcupadaPorPecaBranca(nomeCasa)){
				jogar(nomeCasa, casaTabuleiroTetralath::PECAS_BRANCAS);
			} else {
				jogar(nomeCasa, casaTabuleiroTetralath::PECAS_PRETAS);
			}
		}
	}
	casaUltimaJogada = modelo_param.recuperarNomeCasaUltimaJogada();
	corUltimaJogada = modelo_param.recuperarCorPecasUltimaJogada();
}

/*
* Avalia a utilidade deste tabuleiro para as peças de parâmetro, isto é, o quão favorável o tabuleiro está.
* @param pecas_avaliacao_param A cor das peças que será usada para avaliar o tabuleiro (PECAS_BRANCAS ou PECAS_PRETAS).
* @return Um valor float entre -1 e 1. A interpretação é de -1 (PERDA) para perda, 0 (EMPATE) para 
* 		  empate e 1 (VITORIA) para vitória. Número decimais são permitidos.
*/
float avaliarParaPecasDaCor(int pecas_avaliacao_param){
	return VITORIA;
}

/*
* Procura, em uma ordenação interna dos estados, algum que esteja na posição fornecida.
* @param posicao_param A posição, na ordenação encapsulada desta classe, do estado.
* @return Ponteiro para outro estado (atingível à partir do estado dado) ou NAO_HA_ESTADO_ATINGIVEL (definido nesta classe).
* Exemplo: Se de um estado 3 outros forem atingíveis, a chamada a esta função com 1 retorna o primeiro, 2 retorna o
* segundo e 3 retorna o terceiro. Qualquer número maior retorna NAO_HA_ESTADO_ATINGIVEL. Para números menores que 1,
* deve retornar NAO_HA_ESTADO_ATINGIVEL também.
*/
tabuleiroTetralath* procurarEstadoAtingivelNaPosicao(int posicao_param){
	int numeroMovimentosLegais = calcularNumeroMovimentosLegais();
	int estadosQueAindaDevemSerIgnorados = posicao_param - 1;
	int corJogar = (corUltimaJogada == casaTabuleiroTetralath::PECAS_BRANCAS? casaTabuleiroTetralath::PECAS_PRETAS : casaTabuleiroTetralath::PECAS_BRANCAS);
	int nomeCasaJogar;
	int nomeCasa;

	if(posicao_param < 1 or numeroMovimentosLegais < posicao_param){
		return NAO_HA_ESTADO_ATINGIVEL;
	}

	tabuleiroTetralath* estadoAtingivelNaPosicao;
	*estadoAtingivelNaPosicao = new tabuleiroTetralath();
	estadoAtingivelNaPosicao.copiarDe(this);

	nomeCasa = INDICE_PRIMEIRA_CASA;
	while(0 < estadosQueAindaDevemSerIgnorados){
		if(casaOcupada(nomeCasa)){
			estadosQueAindaDevemSerIgnorados--;
		}
		nomeCasa++;
	}

	while(casaOcupada(nomeCasa)){
		nomeCasa++;
	}

	nomeCasaJogar = nomeCasa;
	estadoAtingivelNaPosicao.jogar(nomeCasaJogar, corJogar);
	return estadoAtingivelNaPosicao;
}

/*
* @return O nome da casa na qual foi feita a última jogada.
*/
int recuperarNomeCasaUltimaJogada(void){
	return casaUltimaJogada;
}

/*
* @return A cor (PECAS_PRETAS ou PECAS_BRANCAS) das peças que jogaram na última jogada.
*/
int recuperarCorPecasUltimaJogada(void){
	return corUltimaJogada;
}

/*
* @return O número de tabuleiros diferentes que podem ser criados inserindo uma peça neste.
*		  Considera-se apenas movimentos legais.
* ANTENCAO: Retornará 0 caso o jogo tenha acabado, mesmo que hajam casas livres. No entanto, 
* ela só conseguirá percebe-lo caso o fim do jogo tenha acontecido na última jogada feita.
*/
int calcularNumeroMovimentosLegais(void){
	int numeroMovimentosLegais = 0;
	
	if(pecasDaMesmaCorGanharam(casaTabuleiroTetralath::PECAS_BRANCAS)
	   or pecasDaMesmaCorGanharam(casaTabuleiroTetralath::PECAS_BRANCAS)){
		numeroMovimentosLegais = 0;
	} else {
		for(int nomeCasa=INDICE_PRIMEIRA_CASA; nomeCasa<NUMERO_CASAS; nomeCasa++){
			if(!casaOcupada(nomeCasa)){
				numeroMovimentosLegais++;
			}
		}
	}
	
	return numeroMovimentosLegais;
}

/*
* Imprime este tabuleiro na tela, considerando interface do terminal.
* Colocará B em posições ocupadas por peças brancas, P em posições ocupadas por peças pretas
* e N em posição não ocupadas. Exemplos de tabuleiros impressos assim estão abaixo:
+-----------------------+------------------------+------------------------+------------------------+
|X 1 2 3 4 5 6 7 8 9  X | X 1 2 3 4 5 6 7 8 9  X | X 1 2 3 4 5 6 7 8 9  X | X 1 2 3 4 5 6 7 8 9  X |
|1     N N N N N      1 | 1     N N N N N      1 | 1     N N N N N      1 | 1     B B P B B      1 |
|2    N N N N N N     2 | 2    N N N N N N     2 | 2    N N N N N N     2 | 2    B P B B P B     2 |
|3   N N N N N N N    3 | 3   N N B N N N N    3 | 3   N N N N B N N    3 | 3   P B B P N N N    3 |
|4  N N N N N N N N   4 | 4  N N N B P N N N   4 | 4  N N N P P B P N   4 | 4  N N N N N N N N   4 |
|5 N N N N N N N N N  5 | 5 N N N P B P N N N  5 | 5 N N N N N N B N N  5 | 5 N N N N N N N N N  5 |
|6  N N N N N N N N   6 | 6  N N N N B N N N   6 | 6  N N N N N N N N   6 | 6  N N N N N N N N   6 |
|7   N N N N N N N    7 | 7   N N N N N N N    7 | 7   N N N N N N N    7 | 7   N N N N N N N    7 |
|8    N N N N N N     8 | 8    N N N N N N     8 | 8    N N N N N N     8 | 8    N N N N N N     8 |
|9     N N N N N      9 | 9     N N N N N      9 | 9     N N N N N      9 | 9     N N N N N      9 |
|X 1 2 3 4 5 6 7 8 9  X | X 1 2 3 4 5 6 7 8 9  X | X 1 2 3 4 5 6 7 8 9  X | X 1 2 3 4 5 6 7 8 9  X |
+-----------------------+------------------------+------------------------+------------------------+
* Adicionalmente, toda letra P possui a cor preta, B possui a cor branca e N possui a cor cinza.
* A casa em que foi feita a última jogada ficará piscando.
* @param casa_selecionada_param Permite pintar uma casa com uma cor. As casas são identificadas por seus índices (entre INDICE_PRIMEIRA_CASA e INDICE_ULTIMA_CASA).
*		 A cor será verde se a casa puder ser ocupada e vermelha se não puder. Esta cor têm preferência sobre todas as outras.
* ATENCAO: As duas funções auxiliares estão definidas logo abaixo desta.
*/
void imprimir(int casa_selecionada_param){
	printf("\n");
	printf("+-----------------------+\n");
	printf("|X 1 2 3 4 5 6 7 8 9  X |\n");
	
	//linha 1
	printf("|1     ");
	imprimirDeCasaAtehCasa(INDICE_PRIMEIRA_CASA, 4, casa_selecionada_param);
	printf("     1 |\n");
	
	//linha 2
	printf("|2    ");
	imprimirDeCasaAtehCasa(5, 10, casa_selecionada_param);
	printf("    2 |\n");
	
	//linha 3
	printf("|3   ");
	imprimirDeCasaAtehCasa(11, 17, casa_selecionada_param);
	printf("   3 |\n");
	
	//linha 4
	printf("|4  ");
	imprimirDeCasaAtehCasa(18, 25, casa_selecionada_param);
	printf("  4 |\n");
	
	//linha 5
	printf("|5 ");
	imprimirDeCasaAtehCasa(26, 34, casa_selecionada_param);
	printf(" 5 |\n");
	
	//linha 6
	printf("|6  ");
	imprimirDeCasaAtehCasa(35, 42, casa_selecionada_param);
	printf("  6 |\n");
	
	//linha 7
	printf("|7   ");
	imprimirDeCasaAtehCasa(43, 49, casa_selecionada_param);
	printf("   7 |\n");
	
	//linha 8
	printf("|8    ");
	imprimirDeCasaAtehCasa(50, 55, casa_selecionada_param);
	printf("    8 |\n");
	
	//linha 9
	printf("|9     ");
	imprimirDeCasaAtehCasa(56, 60, casa_selecionada_param);
	printf("     9 |\n");
	
	printf("|X 1 2 3 4 5 6 7 8 9  X |\n");
	printf("+-----------------------+\n");
	printf("\n");
}

/*
* Função auxiliar de imprimir.
* Imprime um único caractere (uma única casa do tabuleiro).
* É capaz de decidir que cor a casa deve ter, com base nos seguintes critérios:
* Colocará B em posições ocupadas por peças brancas, P em posições ocupadas por peças pretas
* e N em posição não ocupadas.
* Adicionalmente, toda letra P possui a cor preta, B possui a cor branca e N possui a cor cinza.
* A casa em que foi feita a última jogada ficará piscando.
* @param indice_casa_pintar_param O índice (entre INDICE_PRIMEIRA_CASA e INDICE_ULTIMA_CASA) da casa que será pintada.
* @param casa_selecionada_param Permite pintar uma casa com uma cor. As casas são identificadas por seus índices (entre INDICE_PRIMEIRA_CASA e INDICE_ULTIMA_CASA).
*		 A cor será verde se a casa puder ser ocupada e vermelha se não puder. Esta cor têm preferência sobre todas as outras.
*/
void imprimirCasa(int indice_casa_pintar_param, int casa_selecionada_param){
	if(indice_casa_pintar_param == casa_selecionada_param){ //Pintar P, B ou N com vermelho ou verde e piscando ou não.
		if(casaOcupada(indice_casa_pintar_param)){ //Pintar P ou B com vermelho e piscando ou não.
			if(casaOcupadaPorPecaBranca(indice_casa_pintar_param)){ //Pintar B com vermelho e piscando ou não.
				if(recuperarNomeCasaUltimaJogada() == indice_casa_pintar_param){ //Pintar B com vermelho e piscando.
					printf(COR_VERMELHA+"B");																		
				} else { //Pintar B com vermelho e não piscando.
					printf(COR_VERMELHA+"B");																						
				}
			} else { //Pintar P com vermelho e piscando ou não.
				if(recuperarNomeCasaUltimaJogada() == indice_casa_pintar_param){ //Pintar P com vermelho e piscando.
					printf(COR_VERMELHA+"P");																						
				} else { //Pintar P com vermelho e não piscando.
					printf(COR_VERMELHA+"P");																						
				}
			}
		} else { //Pintar N com verde.
			printf(COR_VERDE+"N");																								
		}
	} else { //Pintar P, B ou N com cor branca, preta ou cinza piscando ou não.
		if(casaOcupadaPorPecaBranca(indice_casa_pintar_param)){ //Pintar B com cor branca piscando ou não.
			if(recuperarNomeCasaUltimaJogada() == indice_casa_pintar_param){ //Pintar B com cor branca piscando.
				printf(COR_BRANCA+"B");																							
			} else { //Pintar B com cor branca não piscando.
				printf(COR_BRANCA+"B");																							
			}
		} else if(casaOcupada(indice_casa_pintar_param)){ //Pintar P com cor preta piscando ou não.
			if(recuperarNomeCasaUltimaJogada() == indice_casa_pintar_param){ //Pintar P com cor preta piscando.
				printf(COR_PRETA+"P");																							
			} else { //Pintar P com cor preta não piscando.
				printf(COR_PRETA+"P");																							
			}
		} else { //Pintar N com cor cinza não piscando.
			printf(COR_CINZA+"N");																								
		}
	}
}

/*
* Imprime casas separadas por espaços. A primeira impressão é de casa. A última, de espaço.
* As casas variam entre os índices dados.
* @param casa_inicial_param Nome da primeira casa a ser impressa.
* @param casa_final_param Nome da última casa a ser impressa.
* @param casa_selecionada_param Permite pintar uma casa com uma cor. As casas são identificadas por seus índices (entre INDICE_PRIMEIRA_CASA e INDICE_ULTIMA_CASA).
*		 A cor será verde se a casa puder ser ocupada e vermelha se não puder. Esta cor têm preferência sobre todas as outras.
*/
void imprimirDeCasaAtehCasa(int casa_inicial_param, int casa_final_param, int casa_selecionada_param){
	for(int nomeCasa=casa_inicial_param; nomeCasa<=casa_final_param; nomeCasa++){
		imprimirCasa(nomeCasa, casa_selecionada_param);
		printf(" ");
	}
}

/*
* Auxilia a função de impressão, 
*/

/*************************************************************************************
* ATENÇÃO: À partir daqui, todos métodos são privados
*************************************************************************************/

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













