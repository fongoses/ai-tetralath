#include <stdio.h>
#include "../../tabuleiroTetralath.h"
using namespace std;


/*
* Este arquivo testa as funções de casaTabuleiroTetralath.
*/



int main(){
	cout << "Este é o teste da classe tabuleiroTetralath.\n";

	/*
	* Teste do construtor.
	*/
	cout << "Construtor.\n";
	tabuleiroTetralath tabuleiro = *(new tabuleiroTetralath());
	if(tabuleiro.casaOcupada(45) == false){
		cout << "\tConstrutor está OK (1 de 2).\n";
	} else {
		cout << "\tConstrutor está NOT_OK (1 de 2).\n";
	}
	if(tabuleiro.casaOcupadaPorPecaBranca(27) == false){
		cout << "\tConstrutor está OK (2 de 2).\n";
	} else {
		cout << "\tConstrutor está NOT_OK (2 de 2).\n";
	}
	
	/*
	* Teste das funções jogar e brancasGanharam.
	*/
	cout << "jogar e pecasDaMesmaCorGanharam.\n";
	tabuleiroTetralath tabuleiro2 = *(new tabuleiroTetralath());

	if(tabuleiro2.jogar(20, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro2.jogar(29, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro2.jogar(38, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro2.jogar(46, casaTabuleiroTetralath::PECAS_PRETAS)
	   and not tabuleiro2.pecasDaMesmaCorPerderam(29)){
		cout << "\tpecasDaMesmaCorPerderam está OK (1 de 5).\n";
	} else {
		cout << "\tpecasDaMesmaCorPerderam está NOT_OK (1 de 5).\n";
	}
	if(tabuleiro2.jogar(19, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.jogar(20, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.jogar(21, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.jogar(22, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.pecasDaMesmaCorGanharam(21)){
		cout << "\tpecasDaMesmaCorGanharam está OK (2 de 5).\n";
	} else {
		cout << "\tpecasDaMesmaCorGanharam está NOT_OK (2 de 5).\n";
	}
	if(tabuleiro2.jogar(29, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.jogar(21, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.jogar(14, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.jogar(8, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.pecasDaMesmaCorGanharam(8)){
		cout << "\tpecasDaMesmaCorGanharam está OK (3 de 5).\n";
	} else {
		cout << "\tpecasDaMesmaCorGanharam está NOT_OK (3 de 5).\n";
	}
	if(tabuleiro2.jogar(13, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.jogar(21, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.jogar(30, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.jogar(39, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.pecasDaMesmaCorGanharam(39)){
		cout << "\tpecasDaMesmaCorGanharam está OK (4 de 5).\n";
	} else {
		cout << "\tpecasDaMesmaCorGanharam está NOT_OK (4 de 5).\n";
	}
	if(tabuleiro2.jogar(44, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro2.jogar(51, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro2.jogar(57, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro2.pecasDaMesmaCorGanharam(57)){
		cout << "\tpecasDaMesmaCorGanharam está OK (5 de 5).\n";
	} else {
		cout << "\tpecasDaMesmaCorGanharam está NOT_OK (5 de 5).\n";
	}

	/*
	* Teste das funções jogar e brancasPerderam.
	*/
	cout << "jogar e pecasDaMesmaCorPerderam.\n";
	tabuleiroTetralath tabuleiro3 = *(new tabuleiroTetralath());

	if(tabuleiro3.jogar(46, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro3.jogar(47, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro3.jogar(48, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro3.pecasDaMesmaCorPerderam(48)){
		cout << "\tpecasDaMesmaCorPerderam está OK (1 de 4).\n";
	} else {
		cout << "\tpecasDaMesmaCorPerderam está NOT_OK (1 de 4).\n";
	}
	if(tabuleiro3.jogar(0, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro3.jogar(6, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro3.jogar(13, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro3.pecasDaMesmaCorPerderam(6)){
		cout << "\tpecasDaMesmaCorPerderam está OK (2 de 4).\n";
	} else {
		cout << "\tpecasDaMesmaCorPerderam está NOT_OK (2 de 4).\n";
	}
	if(tabuleiro3.jogar(10, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro3.jogar(16, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro3.jogar(23, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro3.pecasDaMesmaCorPerderam(10)){
		cout << "\tpecasDaMesmaCorPerderam está OK (3 de 4).\n";
	} else {
		cout << "\tpecasDaMesmaCorPerderam está NOT_OK (3 de 4).\n";
	}
	if(tabuleiro3.jogar(58, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro3.jogar(59, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro3.jogar(60, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro3.pecasDaMesmaCorPerderam(60)){
		cout << "\tpecasDaMesmaCorPerderam está OK (4 de 4).\n";
	} else {
		cout << "\tpecasDaMesmaCorPerderam está NOT_OK (4 de 4).\n";
	}

	/*
	* Teste da função jogar e brancasPerderam.
	*/

	/*
	* Testes de desempenho.
	*/
	cout << "DESEMPENHO.\n";
	





	return 0;
}
