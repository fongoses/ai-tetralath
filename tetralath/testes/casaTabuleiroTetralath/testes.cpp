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
		cout << "\tocuparCom está OK (1 de 3).\n";
	} else {
		cout << "\tocuparCom está NOT_OK (1 de 3).\n";
	}
	if(casaBranca.estahOcupada() == true
	   and casaPreta.estahOcupada() == true){
		cout << "\tConstrutor está OK (2 de 3).\n";
	} else {
		cout << "\tConstrutor está NOT_OK (2 de 3).\n";
	}
	if(casaBranca.estahOcupadaPorPecaBranca() == true
	   and casaPreta.estahOcupadaPorPecaBranca() == false){
		cout << "\tConstrutor está OK (3 de 3).\n";
	} else {
		cout << "\tConstrutor está NOT_OK (3 de 3).\n";
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
	* Testes de desempenho.
	*/
	cout << "DESEMPENHO.\n";
	





	return 0;
}
