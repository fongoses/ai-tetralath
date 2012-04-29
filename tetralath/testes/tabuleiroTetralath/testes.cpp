#include <stdio.h>
#include "../../tabuleiroTetralath.h"
using namespace std;


/*
* Este arquivo testa as funções de casaTabuleiroTetralath.
*/



int main(){
	cout << "Este é o teste da classe tabuleiroTetralath.\n";

	testesConstrutor();
	testesJogarEBrancasGanharam();
	testesJogarEBrancasPerderam();
	testesCalcularNumeroMovimentosLegais();
	
	testesAvaliarParaPecasDaCor();

	/*
	* Testes de desempenho.
	*/
	cout << "DESEMPENHO.\n";
	
	return 0;
}

/*
* Teste de procurarEstadoAtingivelNaPosicao.
*/
void procurarEstadoAtingivelNaPosicao(void){
	cout << "Teste de procurarEstadoAtingivelNaPosicao\n";
	
	
	
}

/*
* Teste de avaliarParaPecasDaCor.
*/
void testesAvaliarParaPecasDaCor(void){
	cout << "Testes de avaliarParaPecasDaCor\n";
	tabuleiroTetralath brancasGanharam = *(new tabuleiroTetralath());
	tabuleiroTetralath brancasPerderam = *(new tabuleiroTetralath());
	tabuleiroTetralath empate = *(new tabuleiroTetralath());
	tabuleiroTetralath pretasGanharam = *(new tabuleiroTetralath());
	tabuleiroTetralath pretasPerderam = *(new tabuleiroTetralath());
	
	//Exemplo de empate retirado da definicao do trabalho. Sim, possui muito mais pretas do que brancas.
	empate.jogar(0);
	empate.jogar(2);
	empate.jogar(1);
	empate.jogar(6);
	empate.jogar(3);
	empate.jogar(9);
	empate.jogar(4);
	empate.jogar(11);
	empate.jogar(5);
	empate.jogar(14);
	empate.jogar(7);
	empate.jogar(17);
	empate.jogar(8);
	empate.jogar(20);
	empate.jogar(10);
	empate.jogar(23);
	empate.jogar(12);
	empate.jogar(27);
	empate.jogar(13);
	empate.jogar(30);
	empate.jogar(15);
	empate.jogar(33);
	empate.jogar(16);
	empate.jogar(37);
	empate.jogar(18);
	empate.jogar(40);
	empate.jogar(19);
	empate.jogar(43);
	empate.jogar(21);
	empate.jogar(46);
	empate.jogar(22);
	empate.jogar(49);
	empate.jogar(24);
	empate.jogar(51);
	empate.jogar(25);
	empate.jogar(54);
	empate.jogar(26);
	empate.jogar(58);
	empate.jogar(28);
	empate.jogar(29);
	empate.jogar(31);
	empate.jogar(32);
	empate.jogar(34);
	empate.jogar(35);
	empate.jogar(36);
	empate.jogar(38);
	empate.jogar(39);
	empate.jogar(41);
	empate.jogar(42);
	empate.jogar(44);
	empate.jogar(45);
	empate.jogar(47);
	empate.jogar(48);
	empate.jogar(50);
	empate.jogar(52);
	empate.jogar(53);
	empate.jogar(55);
	empate.jogar(56);
	empate.jogar(57);
	empate.jogar(59);
	empate.jogar(60);
	if(empate.avaliarParaPecasDaCor(casaTabuleiroTetralath::PECAS_PRETAS) == tabuleiroTetralath::EMPATE
	   and empate.avaliarParaPecasDaCor(casaTabuleiroTetralath::PECAS_BRANCAS) == tabuleiroTetralath::EMPATE){
		cout << "\tavaliarParaPecasDaCor está OK (1 de 5).\n";
	} else {
		cout << "\tavaliarParaPecasDaCor está NOT_OK (1 de 5).\n";
	}
	
	
	brancasGanharam.jogar(28);
	brancasGanharam.jogar(13);
	brancasGanharam.jogar(30);
	brancasGanharam.jogar(20);
	brancasGanharam.jogar(29);
	brancasGanharam.jogar(36);
	brancasGanharam.jogar(31);
	if(brancasGanharam.avaliarParaPecasDaCor(casaTabuleiroTetralath::PECAS_PRETAS) == tabuleiroTetralath::PERDA
	   and brancasGanharam.avaliarParaPecasDaCor(casaTabuleiroTetralath::PECAS_BRANCAS) == tabuleiroTetralath::VITORIA){
		cout << "\tavaliarParaPecasDaCor está OK (2 de 5).\n";
	} else {
		cout << "\tavaliarParaPecasDaCor está NOT_OK (2 de 5).\n";
	}
	
	
	brancasPerderam.jogar(30);
	brancasPerderam.jogar(1);
	brancasPerderam.jogar(31);
	brancasPerderam.jogar(2);
	brancasPerderam.jogar(32);
	if(brancasPerderam.avaliarParaPecasDaCor(casaTabuleiroTetralath::PECAS_PRETAS) == tabuleiroTetralath::VITORIA
	   and brancasPerderam.avaliarParaPecasDaCor(casaTabuleiroTetralath::PECAS_BRANCAS) == tabuleiroTetralath::PERDA){
		cout << "\tavaliarParaPecasDaCor está OK (3 de 5).\n";
	} else {
		cout << "\tavaliarParaPecasDaCor está NOT_OK (3 de 5).\n";
	}
	
	pretasGanharam.jogar(23);
	pretasGanharam.jogar(30);
	pretasGanharam.jogar(21);
	pretasGanharam.jogar(22);
	pretasGanharam.jogar(31);
	pretasGanharam.jogar(38);
	pretasGanharam.jogar(29);
	pretasGanharam.jogar(15);
	if(pretasGanharam.avaliarParaPecasDaCor(casaTabuleiroTetralath::PECAS_PRETAS) == tabuleiroTetralath::VITORIA
	   and pretasGanharam.avaliarParaPecasDaCor(casaTabuleiroTetralath::PECAS_BRANCAS) == tabuleiroTetralath::PERDA){
		cout << "\tavaliarParaPecasDaCor está OK (4 de 5).\n";
	} else {
		cout << "\tavaliarParaPecasDaCor está NOT_OK (4 de 5).\n";
	}
	
	pretasPerderam.jogar(1);
	pretasPerderam.jogar(13);
	pretasPerderam.jogar(7);
	pretasPerderam.jogar(0);
	pretasPerderam.jogar(12);
	pretasPerderam.jogar(6);
	if(pretasPerderam.avaliarParaPecasDaCor(casaTabuleiroTetralath::PECAS_PRETAS) == tabuleiroTetralath::PERDA
	   and pretasPerderam.avaliarParaPecasDaCor(casaTabuleiroTetralath::PECAS_BRANCAS) == tabuleiroTetralath::VITORIA){
		cout << "\tavaliarParaPecasDaCor está OK (5 de 5).\n";
	} else {
		cout << "\tavaliarParaPecasDaCor está NOT_OK (5 de 5).\n";
	}
}

/*
* Teste de clonar e copiarDe.
*/
void testesClonarECopiarDe(void){
	cout << "Teste de clonar e copiarDe\n";
	
	
	
	
}

/*
* Teste de calcularNumeroMovimentosLegais.
*/
void testesCalcularNumeroMovimentosLegais(void){
	cout << "Testes calcularNumeroMovimentosLegais\n";

	tabuleiroTetralath tabuleiroVazio = *(new tabuleiroTetralath());
	tabuleiroTetralath tabuleiro5 = *(new tabuleiroTetralath());
	tabuleiroTetralath tabuleiro30 = *(new tabuleiroTetralath());
	tabuleiroTetralath tabuleiroCheio = *(new tabuleiroTetralath());
	tabuleiroTetralath tabuleiroBrancasGanharam = *(new tabuleiroTetralath());
	tabuleiroTetralath tabuleiroBrancasPerderam = *(new tabuleiroTetralath());
	tabuleiroTetralath tabuleiroPretasGanharam = *(new tabuleiroTetralath());
	tabuleiroTetralath tabuleiroPretasPerderam = *(new tabuleiroTetralath());

	if(tabuleiroVazio.calcularNumeroMovimentosLegais() == tabuleiroTetralath::NUMERO_CASAS){
		cout << "\tcalcularNumeroMovimentosLegais está OK (1 de 8).\n";
	} else {
		cout << "\tcalcularNumeroMovimentosLegais está NOT_OK (1 de 8).\n";
	}

	tabuleiro5.jogar(1);
	tabuleiro5.jogar(30);
	tabuleiro5.jogar(19);
	tabuleiro5.jogar(54);
	tabuleiro5.jogar(33);
	if(tabuleiro5.calcularNumeroMovimentosLegais() == tabuleiroTetralath::NUMERO_CASAS - 5){
		cout << "\tcalcularNumeroMovimentosLegais está OK (2 de 8).\n";
	} else {
		cout << "\tcalcularNumeroMovimentosLegais está NOT_OK (2 de 8).\n";
	}
	
	tabuleiro30.jogar(0);
	tabuleiro30.jogar(5);
	tabuleiro30.jogar(11);
	tabuleiro30.jogar(18);
	tabuleiro30.jogar(26);
	tabuleiro30.jogar(7);
	tabuleiro30.jogar(2);
	tabuleiro30.jogar(20);
	tabuleiro30.jogar(13);
	tabuleiro30.jogar(36);
	tabuleiro30.jogar(28);
	tabuleiro30.jogar(9,);
	tabuleiro30.jogar(43);
	tabuleiro30.jogar(22);
	tabuleiro30.jogar(4);
	tabuleiro30.jogar(38);
	tabuleiro30.jogar(15);
	tabuleiro30.jogar(51);
	tabuleiro30.jogar(30);
	tabuleiro30.jogar(24);
	tabuleiro30.jogar(45);
	tabuleiro30.jogar(40);
	tabuleiro30.jogar(56);
	tabuleiro30.jogar(53);
	tabuleiro30.jogar(17);
	tabuleiro30.jogar(42);
	tabuleiro30.jogar(32);
	tabuleiro30.jogar(55);
	tabuleiro30.jogar(47);
	tabuleiro30.jogar(1);
	if(tabuleiro30.calcularNumeroMovimentosLegais() == tabuleiroTetralath::NUMERO_CASAS - 30){
		cout << "\tcalcularNumeroMovimentosLegais está OK (3 de 8).\n";
	} else {
		cout << "\tcalcularNumeroMovimentosLegais está NOT_OK (3 de 8).\n";
	}
	
	//Exemplo de empate retirado da definicao do trabalho. Sim, possui muito mais brancas do que pretas.
	tabuleiroCheio.jogar(0);
	tabuleiroCheio.jogar(2);
	tabuleiroCheio.jogar(1);
	tabuleiroCheio.jogar(6);
	tabuleiroCheio.jogar(3);
	tabuleiroCheio.jogar(9);
	tabuleiroCheio.jogar(4);
	tabuleiroCheio.jogar(11);
	tabuleiroCheio.jogar(5);
	tabuleiroCheio.jogar(14);
	tabuleiroCheio.jogar(7);
	tabuleiroCheio.jogar(17);
	tabuleiroCheio.jogar(8);
	tabuleiroCheio.jogar(20);
	tabuleiroCheio.jogar(10);
	tabuleiroCheio.jogar(23);
	tabuleiroCheio.jogar(12);
	tabuleiroCheio.jogar(27);
	tabuleiroCheio.jogar(13);
	tabuleiroCheio.jogar(30);
	tabuleiroCheio.jogar(15);
	tabuleiroCheio.jogar(33);
	tabuleiroCheio.jogar(16);
	tabuleiroCheio.jogar(37);
	tabuleiroCheio.jogar(18);
	tabuleiroCheio.jogar(40);
	tabuleiroCheio.jogar(19);
	tabuleiroCheio.jogar(43);
	tabuleiroCheio.jogar(21);
	tabuleiroCheio.jogar(46);
	tabuleiroCheio.jogar(22);
	tabuleiroCheio.jogar(49);
	tabuleiroCheio.jogar(24);
	tabuleiroCheio.jogar(51);
	tabuleiroCheio.jogar(25);
	tabuleiroCheio.jogar(54);
	tabuleiroCheio.jogar(26);
	tabuleiroCheio.jogar(58);
	tabuleiroCheio.jogar(28);
	tabuleiroCheio.jogar(29);
	tabuleiroCheio.jogar(31);
	tabuleiroCheio.jogar(32);
	tabuleiroCheio.jogar(34);
	tabuleiroCheio.jogar(35);
	tabuleiroCheio.jogar(36);
	tabuleiroCheio.jogar(38);
	tabuleiroCheio.jogar(39);
	tabuleiroCheio.jogar(41);
	tabuleiroCheio.jogar(42);
	tabuleiroCheio.jogar(44);
	tabuleiroCheio.jogar(45);
	tabuleiroCheio.jogar(47);
	tabuleiroCheio.jogar(48);
	tabuleiroCheio.jogar(50);
	tabuleiroCheio.jogar(52);
	tabuleiroCheio.jogar(53);
	tabuleiroCheio.jogar(55);
	tabuleiroCheio.jogar(56);
	tabuleiroCheio.jogar(57);
	tabuleiroCheio.jogar(59);
	tabuleiroCheio.jogar(60);
	if(tabuleiroCheio.calcularNumeroMovimentosLegais() == 0){
		cout << "\tcalcularNumeroMovimentosLegais está OK (4 de 8).\n";
	} else {
		cout << "\tcalcularNumeroMovimentosLegais está NOT_OK (4 de 8).\n";
	}
	
	tabuleiroBrancasGanharam.jogar(14);
	tabuleiroBrancasGanharam.jogar(12);
	tabuleiroBrancasGanharam.jogar(29);
	tabuleiroBrancasGanharam.jogar(47);
	tabuleiroBrancasGanharam.jogar(21);
	tabuleiroBrancasGanharam.jogar(24);
	tabuleiroBrancasGanharam.jogar(37);
	if(tabuleiroBrancasGanharam.calcularNumeroMovimentosLegais() == 0){
		cout << "\tcalcularNumeroMovimentosLegais está OK (5 de 8).\n";
	} else {
		cout << "\tcalcularNumeroMovimentosLegais está NOT_OK (5 de 8).\n";
	}
	
	tabuleiroBrancasPerderam.jogar(13);
	tabuleiroBrancasPerderam.jogar(31);
	tabuleiroBrancasPerderam.jogar(14);
	tabuleiroBrancasPerderam.jogar(47);
	tabuleiroBrancasPerderam.jogar(15);
	if(tabuleiroBrancasPerderam.calcularNumeroMovimentosLegais() == 0){
		cout << "\tcalcularNumeroMovimentosLegais está OK (6 de 8).\n";
	} else {
		cout << "\tcalcularNumeroMovimentosLegais está NOT_OK (6 de 8).\n";
	}
	
	tabuleiroPretasGanharam.jogar(1);
	tabuleiroPretasGanharam.jogar(40);
	tabuleiroPretasGanharam.jogar(7);
	tabuleiroPretasGanharam.jogar(22);
	tabuleiroPretasGanharam.jogar(55);
	tabuleiroPretasGanharam.jogar(31);
	tabuleiroPretasGanharam.jogar(27);
	tabuleiroPretasGanharam.jogar(14);
	if(tabuleiroPretasGanharam.calcularNumeroMovimentosLegais() == 0){
		cout << "\tcalcularNumeroMovimentosLegais está OK (7 de 8).\n";
	} else {
		cout << "\tcalcularNumeroMovimentosLegais está NOT_OK (7 de 8).\n";
	}
	
	tabuleiroPretasPerderam.jogar(2);
	tabuleiroPretasPerderam.jogar(40);
	tabuleiroPretasPerderam.jogar(12);
	tabuleiroPretasPerderam.jogar(22);
	tabuleiroPretasPerderam.jogar(51);
	tabuleiroPretasPerderam.jogar(31);
	if(tabuleiroPretasPerderam.calcularNumeroMovimentosLegais() == 0){
		cout << "\tcalcularNumeroMovimentosLegais está OK (8 de 8).\n";
	} else {
		cout << "\tcalcularNumeroMovimentosLegais está NOT_OK (8 de 8).\n";
	}
}

/*
* Teste do construtor.
*/
void testesConstrutor(void){
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
}


/*
* Teste das funções jogar e brancasGanharam.
*/
void testesJogarEBrancasGanharam(void){
	cout << "jogar e pecasDaMesmaCorGanharam.\n";
	tabuleiroTetralath tabuleiro2;

	tabuleiro2 = *(new tabuleiroTetralath());
	if(tabuleiro2.jogar(20, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro2.jogar(29, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro2.pecasDaMesmaCorGanharam(29)){
		cout << "\tpecasDaMesmaCorGanharam está NOT_OK (1 de 5).\n";
	} else {
		cout << "\tpecasDaMesmaCorGanharam está OK (1 de 5).\n";
	}

	tabuleiro2 = *(new tabuleiroTetralath());
	if(tabuleiro2.jogar(19, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.jogar(20, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.jogar(21, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.jogar(22, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.pecasDaMesmaCorGanharam(21)){
		cout << "\tpecasDaMesmaCorGanharam está OK (2 de 5).\n";
	} else {
		cout << "\tpecasDaMesmaCorGanharam está NOT_OK (2 de 5).\n";
	}

	tabuleiro2 = *(new tabuleiroTetralath());
	if(tabuleiro2.jogar(29, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.jogar(21, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.jogar(14, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.jogar(8, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.pecasDaMesmaCorGanharam(8)){
		cout << "\tpecasDaMesmaCorGanharam está OK (3 de 5).\n";
	} else {
		cout << "\tpecasDaMesmaCorGanharam está NOT_OK (3 de 5).\n";
	}

	tabuleiro2 = *(new tabuleiroTetralath());
	if(tabuleiro2.jogar(13, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.jogar(21, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.jogar(30, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.jogar(39, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro2.pecasDaMesmaCorGanharam(39)){
		cout << "\tpecasDaMesmaCorGanharam está OK (4 de 5).\n";
	} else {
		cout << "\tpecasDaMesmaCorGanharam está NOT_OK (4 de 5).\n";
	}

	tabuleiro2 = *(new tabuleiroTetralath());
	if(tabuleiro2.jogar(44, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro2.jogar(51, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro2.jogar(57, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro2.pecasDaMesmaCorGanharam(57)){
		cout << "\tpecasDaMesmaCorGanharam está NOT_OK (5 de 5).\n";
	} else {
		cout << "\tpecasDaMesmaCorGanharam está OK (5 de 5).\n";
	}
}

/*
* Teste das funções jogar e brancasPerderam.
*/
void testesJogarEBrancasPerderam(void){
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

	tabuleiro3 = *(new tabuleiroTetralath());
	if(tabuleiro3.jogar(0, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro3.jogar(6, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro3.jogar(13, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro3.pecasDaMesmaCorPerderam(6)){
		cout << "\tpecasDaMesmaCorPerderam está OK (2 de 4).\n";
	} else {
		cout << "\tpecasDaMesmaCorPerderam está NOT_OK (2 de 4).\n";
	}

	tabuleiro3 = *(new tabuleiroTetralath());
	if(tabuleiro3.jogar(10, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro3.jogar(16, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro3.jogar(23, casaTabuleiroTetralath::PECAS_PRETAS)
	   and tabuleiro3.pecasDaMesmaCorPerderam(10)){
		cout << "\tpecasDaMesmaCorPerderam está OK (3 de 4).\n";
	} else {
		cout << "\tpecasDaMesmaCorPerderam está NOT_OK (3 de 4).\n";
	}

	tabuleiro3 = *(new tabuleiroTetralath());
	if(tabuleiro3.jogar(58, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro3.jogar(59, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro3.jogar(60, casaTabuleiroTetralath::PECAS_BRANCAS)
	   and tabuleiro3.pecasDaMesmaCorPerderam(60)){
		cout << "\tpecasDaMesmaCorPerderam está OK (4 de 4).\n";
	} else {
		cout << "\tpecasDaMesmaCorPerderam está NOT_OK (4 de 4).\n";
	}
}