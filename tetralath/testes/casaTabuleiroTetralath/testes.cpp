#include <stdio.h>
#include "../../casaTabuleiroTetralath.h"
using namespace std;


/*
* Este arquivo testa as funções de casaTabuleiroTetralath.
*/



int main(){
	cout << "Este é o teste da classe casaTabuleiroTetralath.\n";

	/*
	* Teste do construtor.
	*/
	cout << "Construtor.\n";
	casaTabuleiroTetralath casa = *(new casaTabuleiroTetralath());
	if(casa.estahOcupada() == false){
		cout << "\tConstrutor está OK (1 de 3).\n";
	} else {
		cout << "\tConstrutor está NOT_OK (1 de 3).\n";
	}
	if(casa.estahOcupadaPorPecaBranca() == false){
		cout << "\tConstrutor está OK (2 de 3).\n";
	} else {
		cout << "\tConstrutor está NOT_OK (2 de 3).\n";
	}
	if(casa.getVizinhoA() == NULL
	   and casa.getVizinhoB() == NULL
	   and casa.getVizinhoC() == NULL
	   and casa.getVizinhoD() == NULL
	   and casa.getVizinhoE() == NULL
	   and casa.getVizinhoF() == NULL){
		cout << "\tConstrutor está OK (3 de 3).\n";
	} else {
		cout << "\tConstrutor está NOT_OK (3 de 3).\n";
	}

	/*
	* Teste da função ocuparCom.
	*/
	cout << "ocuparCom.\n";
	casaTabuleiroTetralath casaBranca = *(new casaTabuleiroTetralath());
	casaTabuleiroTetralath casaPreta = *(new casaTabuleiroTetralath());
	if(casaBranca.ocuparCom(casaTabuleiroTetralath::PECAS_BRANCAS)
	   and casaPreta.ocuparCom(casaTabuleiroTetralath::PECAS_PRETAS)){
		cout << "\tocuparCom está OK (1 de 4).\n";
	} else {
		cout << "\tocuparCom está NOT_OK (1 de 4).\n";
	}
	if(casaBranca.estahOcupada() == true
	   and casaPreta.estahOcupada() == true){
		cout << "\tocuparCom está OK (2 de 4).\n";
	} else {
		cout << "\tocuparCom está NOT_OK (2 de 4).\n";
	}
	if(casaBranca.estahOcupadaPorPecaBranca() == true
	   and casaPreta.estahOcupadaPorPecaBranca() == false){
		cout << "\tocuparCom está OK (3 de 4).\n";
	} else {
		cout << "\tocuparCom está NOT_OK (3 de 4).\n";
	}
	if(casaBranca.estahOcupadaPorPecaPreta() == false
	   and casaPreta.estahOcupadaPorPecaPreta() == true){
		cout << "\tocuparCom está OK (4 de 4).\n";
	} else {
		cout << "\tocuparCom está NOT_OK (4 de 4).\n";
	}

	/*
	* Teste da função criarVizinhança.
	*/
	cout << "criarVizinhança.\n";
	casaTabuleiroTetralath* X = (new casaTabuleiroTetralath());
	casaTabuleiroTetralath* A = (new casaTabuleiroTetralath());
	casaTabuleiroTetralath* B = (new casaTabuleiroTetralath());
	casaTabuleiroTetralath* C = (new casaTabuleiroTetralath());
	casaTabuleiroTetralath* D = (new casaTabuleiroTetralath());
	casaTabuleiroTetralath* E = (new casaTabuleiroTetralath());
	casaTabuleiroTetralath* F = (new casaTabuleiroTetralath());
	if(X->criarVizinhanca(A,B,C,D,E,F)){
		cout << "\tcriarVizinhança está OK (1 de 2).\n";
	} else {
		cout << "\tcriarVizinhança está NOT_OK (1 de 2).\n";
	}
	if(X->getVizinhoA() == A
	   and X->getVizinhoB() == B
	   and X->getVizinhoC() == C
	   and X->getVizinhoD() == D
	   and X->getVizinhoE() == E
	   and X->getVizinhoF() == F){
		cout << "\tcriarVizinhança está OK (2 de 2).\n";
	} else {
		cout << "\tcriarVizinhança está NOT_OK (2 de 2).\n";
	}

	/*
	* Teste da função getCasaDistanciaDesta.
	*/
	cout << "getCasaDistanciaDesta.\n";
	casaTabuleiroTetralath* X1 = (new casaTabuleiroTetralath());
	casaTabuleiroTetralath* horizontalMenos1 = (new casaTabuleiroTetralath());
	X1->criarVizinhanca(VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,horizontalMenos1,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE);
	if(X1->getCasaDistanciaDesta(-1, LINHA_HORIZONTAL) == horizontalMenos1){
		cout << "\tgetCasaDistanciaDesta está OK (1 de 3)\n";
	} else {
		cout << "\tgetCasaDistanciaDesta está NOT_OK (1 de 3).\n";
	}

	casaTabuleiroTetralath* X2 = (new casaTabuleiroTetralath());
	casaTabuleiroTetralath* horizontalMais1 = (new casaTabuleiroTetralath());
	casaTabuleiroTetralath* horizontalMais2 = (new casaTabuleiroTetralath());
	X2->criarVizinhanca(VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,horizontalMais1,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE);
	horizontalMais1->criarVizinhanca(VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,horizontalMais2,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE);
	if(X2->getCasaDistanciaDesta(1, LINHA_HORIZONTAL) == horizontalMais1
	   and X2->getCasaDistanciaDesta(2, LINHA_HORIZONTAL) == horizontalMais2
	   and horizontalMais1->getCasaDistanciaDesta(1, LINHA_HORIZONTAL) == horizontalMais2){
		cout << "\tgetCasaDistanciaDesta está OK (2 de 3).\n";
	} else {
		cout << "\tgetCasaDistanciaDesta está NOT_OK (2 de 3).\n";
	}

	casaTabuleiroTetralath* X3 = (new casaTabuleiroTetralath());
	casaTabuleiroTetralath* diagonalCrescenteMenos1 = (new casaTabuleiroTetralath());
	casaTabuleiroTetralath* diagonalCrescenteMenos2 = (new casaTabuleiroTetralath());
	casaTabuleiroTetralath* diagonalCrescenteMenos3 = (new casaTabuleiroTetralath());
	X3->criarVizinhanca(VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,diagonalCrescenteMenos1,VIZINHO_INEXISTENTE);
	diagonalCrescenteMenos1->criarVizinhanca(VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,diagonalCrescenteMenos2,VIZINHO_INEXISTENTE);
	diagonalCrescenteMenos2->criarVizinhanca(VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,VIZINHO_INEXISTENTE,diagonalCrescenteMenos3,VIZINHO_INEXISTENTE);
	if(X3->getCasaDistanciaDesta(-1, LINHA_DIAGONAL_CRESCENTE) == diagonalCrescenteMenos1
	   and X3->getCasaDistanciaDesta(-2, LINHA_DIAGONAL_CRESCENTE) == diagonalCrescenteMenos2
	   and X3->getCasaDistanciaDesta(-3, LINHA_DIAGONAL_CRESCENTE) == diagonalCrescenteMenos3
	   and diagonalCrescenteMenos1->getCasaDistanciaDesta(-1, LINHA_DIAGONAL_CRESCENTE) == diagonalCrescenteMenos2
	   and diagonalCrescenteMenos1->getCasaDistanciaDesta(-2, LINHA_DIAGONAL_CRESCENTE) == diagonalCrescenteMenos3
	   and diagonalCrescenteMenos2->getCasaDistanciaDesta(-1, LINHA_DIAGONAL_CRESCENTE) == diagonalCrescenteMenos3){
		cout << "\tgetCasaDistanciaDesta está OK (3 de 3).\n";
	} else {
		cout << "\tgetCasaDistanciaDesta está NOT_OK (3 de 3).\n";
	}

	/*
	* Testes de desempenho.
	*/
	cout << "DESEMPENHO.\n";
	





	return 0;
}
