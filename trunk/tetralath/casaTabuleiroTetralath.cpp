#include "casaTabuleiroTetralath.h"
using namespace std;

/*
* Classe que implementa uma casa do tabuleiro do jogo Tetralath.
* Para fins de comunicação, dá-se nomes aos vizinhos de uma casa da seguinte forma:
*       A   B
*     C   X   D
*       E   F
* A casa X é a casa representada pelo objeto.
* A e F formam uma reta, assim como C e D e B e E.
* Notar que o construtor não exige que sejam informadas as peças vizinhas, de modo que isto deve ser feito por função própria após a construção.
*/

/*
* Construtor da classe.
*/
casaTabuleiroTetralath::casaTabuleiroTetralath(void){
	ocupada = false;
	conteudo = PECAS_BRANCAS;
	A = NULL;
	B = NULL;
	C = NULL;
	D = NULL;
	E = NULL;
	F = NULL;
}

/*
* Determina se esta casa está ocupada.
* @return Booleano indicando se a casa está ocupada por alguma peça.
*/
bool casaTabuleiroTetralath::estahOcupada(void){ return ocupada; }

/*
* Determina se esta casa está ocupada por peça da cor branca.
* @return Booleano indicando se a casa está ocupada por alguma peça branca.
*	Atenção: Se a casa não estiver ocupada ou se estiver ocupada por peça preta, retornará false.
*/
bool casaTabuleiroTetralath::estahOcupadaPorPecaBranca(void){
	if(ocupada and conteudo == PECAS_BRANCAS){
		return true;
	} else {
		return false;
	}
}

/*
* Determina se esta casa está ocupada por peça da cor preta. Duplicou-se a função por motivo de desempenho.
* @return Booleano indicando se a casa está ocupada por alguma peça preta.
*	Atenção: Se a casa não estiver ocupada ou se estiver ocupada por peça branca, retornará false.
*/
bool casaTabuleiroTetralath::estahOcupadaPorPecaPreta(void){
	if(ocupada and conteudo == PECAS_PRETAS){
		return true;
	} else {
		return false;
	}
}

/*
* Ocupa esta casa com uma peça da cor passada.
* @param corPeca_param A cor da peça que ocupará a casa. Deve ser PECAS_BRANCAS ou PECAS_PRETAS.
* @return Booleano indicando se foi possível ocupar a casa (se ela estiver ocupada, não será possível).
*/
bool casaTabuleiroTetralath::ocuparCom(int corPeca_param){
	if(!estahOcupada() and (corPeca_param == PECAS_BRANCAS
				or corPeca_param == PECAS_PRETAS)){
		ocupada = true;
		conteudo = corPeca_param;
		return true;
	} else {
		return false;
	}
}

/*
* As funções à seguir possuem comportamento semelhante.
* Cada uma retorna um ponteiro para uma casaTabuleiroTetralath que é vizinha desta casa.
* Caso a casa não tenha vizinho na posição que a função verifica, retornará NULL.
* @return Se há vizinho, retorna ponteiro para ele.
	  Se não há vizinho, retorna NULL.
*/
casaTabuleiroTetralath* casaTabuleiroTetralath::getVizinhoA(void){ return A; }
casaTabuleiroTetralath* casaTabuleiroTetralath::getVizinhoB(void){ return B; }
casaTabuleiroTetralath* casaTabuleiroTetralath::getVizinhoC(void){ return C; }
casaTabuleiroTetralath* casaTabuleiroTetralath::getVizinhoD(void){ return D; }
casaTabuleiroTetralath* casaTabuleiroTetralath::getVizinhoE(void){ return E; }
casaTabuleiroTetralath* casaTabuleiroTetralath::getVizinhoF(void){ return F; }

/*
* A função à seguir cria a vizinhança desta casa, populando-a por outras casas.
* Caso esta casa já possua vizinhos, esta função não terá efeito.
* Não é possível, assim, editar vizinhos e todos vizinhos devem ser criados de uma só vez.
* Vizinhos passados como NULL serão tratados como inexistentes (é possível utilizar a constante definida no início).
* @param casaVizinhaX_param O objeto da casa de nome X, que é vizinha desta.
* @return Booleano indicando se foi possível criar a vizinhança.
*/
bool casaTabuleiroTetralath::criarVizinhanca(casaTabuleiroTetralath* casaVizinhaA_param,
					     casaTabuleiroTetralath* casaVizinhaB_param,
					     casaTabuleiroTetralath* casaVizinhaC_param,
					     casaTabuleiroTetralath* casaVizinhaD_param,
					     casaTabuleiroTetralath* casaVizinhaE_param,
					     casaTabuleiroTetralath* casaVizinhaF_param){
	bool vizinhancaAindaNaoCriada = (A == NULL and B == NULL and C == NULL and D == NULL and E == NULL and F == NULL);
	if(vizinhancaAindaNaoCriada){
		A = casaVizinhaA_param;
		B = casaVizinhaB_param;
		C = casaVizinhaC_param;
		D = casaVizinhaD_param;
		E = casaVizinhaE_param;
		F = casaVizinhaF_param;
		return true;
	} else {
		return false;
	}
}

/*
* Procura por uma casa que, em linha reta (horizontal, diagonal decrescente ou diagonal crescente) está a uma distância dada desta.
* @param distancia_param A distância desta casa em que está a casa procurada.
* 			Distâncias negativas são interpretadas como casas à esquerda ou acima da casa de referência.
*			Distâncias positivas são interpretadas como casas à direita ou abaixo da casa de referência.
* @param linha_param A linha (LINHA_HORIZONTAL, LINHA_DIAGONAL_CRESCENTE ou LINHA_DIAGONAL_DECRESCENTE) em que se deseja efetuar a busca.
* @return A casa com distância distancia_param da casa cujo nome é passado como parâmetro. Se não houver, retorna VIZINHO_INEXISTENTE.
*/
casaTabuleiroTetralath* casaTabuleiroTetralath::getCasaDistanciaDesta(int distancia_param, int linha_param){
	casaTabuleiroTetralath* vizinhoEncontrado = this;

	if(distancia_param == 0){ //Condição de parada da recursão.
		vizinhoEncontrado = this;
	} else{
		if(distancia_param < 0){ //Vizinho está à esquerda ou acima da casa de referência
			switch(linha_param){
				case LINHA_HORIZONTAL: vizinhoEncontrado = getVizinhoC();
					break;
				case LINHA_DIAGONAL_CRESCENTE: vizinhoEncontrado = getVizinhoE();
					break;
				case LINHA_DIAGONAL_DECRESCENTE: vizinhoEncontrado = getVizinhoA();
					break;
				default: vizinhoEncontrado = VIZINHO_INEXISTENTE;
			}
		} else { //Vizinho está à direita ou abaixo da casa de referência
			switch(linha_param){
				case LINHA_HORIZONTAL: vizinhoEncontrado = getVizinhoD();
					break;
				case LINHA_DIAGONAL_CRESCENTE: vizinhoEncontrado = getVizinhoB();
					break;
				case LINHA_DIAGONAL_DECRESCENTE: vizinhoEncontrado = getVizinhoF();
					break;
				default: vizinhoEncontrado = VIZINHO_INEXISTENTE;
			}
		}

		if(vizinhoEncontrado != VIZINHO_INEXISTENTE){
			int sinalDistancia = fabs(distancia_param)/distancia_param;
			vizinhoEncontrado = vizinhoEncontrado->getCasaDistanciaDesta((fabs(distancia_param)-1)*sinalDistancia,linha_param);
		}
	}

	return vizinhoEncontrado;
}



