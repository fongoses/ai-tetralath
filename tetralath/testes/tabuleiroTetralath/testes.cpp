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
	empate.jogar(0,  casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(2,  casaTabuleiroTetralath::PECAS_BRANCAS);
	empate.jogar(1,  casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(6,  casaTabuleiroTetralath::PECAS_BRANCAS);
	empate.jogar(3,  casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(9,  casaTabuleiroTetralath::PECAS_BRANCAS);
	empate.jogar(4,  casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(11, casaTabuleiroTetralath::PECAS_BRANCAS);
	empate.jogar(5,  casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(14, casaTabuleiroTetralath::PECAS_BRANCAS);
	empate.jogar(7,  casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(17, casaTabuleiroTetralath::PECAS_BRANCAS);
	empate.jogar(8,  casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(20, casaTabuleiroTetralath::PECAS_BRANCAS);
	empate.jogar(10, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(23, casaTabuleiroTetralath::PECAS_BRANCAS);
	empate.jogar(12, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(27, casaTabuleiroTetralath::PECAS_BRANCAS);
	empate.jogar(13, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(30, casaTabuleiroTetralath::PECAS_BRANCAS);
	empate.jogar(15, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(33, casaTabuleiroTetralath::PECAS_BRANCAS);
	empate.jogar(16, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(37, casaTabuleiroTetralath::PECAS_BRANCAS);
	empate.jogar(18, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(40, casaTabuleiroTetralath::PECAS_BRANCAS);
	empate.jogar(19, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(43, casaTabuleiroTetralath::PECAS_BRANCAS);
	empate.jogar(21, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(46, casaTabuleiroTetralath::PECAS_BRANCAS);
	empate.jogar(22, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(49, casaTabuleiroTetralath::PECAS_BRANCAS);
	empate.jogar(24, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(51, casaTabuleiroTetralath::PECAS_BRANCAS);
	empate.jogar(25, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(54, casaTabuleiroTetralath::PECAS_BRANCAS);
	empate.jogar(26, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(58, casaTabuleiroTetralath::PECAS_BRANCAS);
	empate.jogar(28, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(29, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(31, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(32, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(34, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(35, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(36, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(38, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(39, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(41, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(42, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(44, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(45, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(47, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(48, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(50, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(52, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(53, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(55, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(56, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(57, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(59, casaTabuleiroTetralath::PECAS_PRETAS);
	empate.jogar(60, casaTabuleiroTetralath::PECAS_PRETAS);
	if(empate.avaliarParaPecasDaCor(casaTabuleiroTetralath::PECAS_PRETAS) == tabuleiroTetralath::EMPATE
	   and empate.avaliarParaPecasDaCor(casaTabuleiroTetralath::PECAS_BRANCAS) == tabuleiroTetralath::EMPATE){
		cout << "\tavaliarParaPecasDaCor está OK (1 de 5).\n";
	} else {
		cout << "\tavaliarParaPecasDaCor está NOT_OK (1 de 5).\n";
	}
	
	
	brancasGanharam.jogar(28, casaTabuleiroTetralath::PECAS_BRANCAS);
	brancasGanharam.jogar(13, casaTabuleiroTetralath::PECAS_PRETAS);
	brancasGanharam.jogar(30, casaTabuleiroTetralath::PECAS_BRANCAS);
	brancasGanharam.jogar(20, casaTabuleiroTetralath::PECAS_PRETAS);
	brancasGanharam.jogar(29, casaTabuleiroTetralath::PECAS_BRANCAS);
	brancasGanharam.jogar(36, casaTabuleiroTetralath::PECAS_PRETAS);
	brancasGanharam.jogar(31, casaTabuleiroTetralath::PECAS_BRANCAS);
	if(brancasGanharam.avaliarParaPecasDaCor(casaTabuleiroTetralath::PECAS_PRETAS) == tabuleiroTetralath::PERDA
	   and brancasGanharam.avaliarParaPecasDaCor(casaTabuleiroTetralath::PECAS_BRANCAS) == tabuleiroTetralath::VITORIA){
		cout << "\tavaliarParaPecasDaCor está OK (2 de 5).\n";
	} else {
		cout << "\tavaliarParaPecasDaCor está NOT_OK (2 de 5).\n";
	}
	
	
	brancasPerderam.jogar(30, casaTabuleiroTetralath::PECAS_BRANCAS);
	brancasPerderam.jogar(1, casaTabuleiroTetralath::PECAS_PRETAS);
	brancasPerderam.jogar(31, casaTabuleiroTetralath::PECAS_BRANCAS);
	brancasPerderam.jogar(2, casaTabuleiroTetralath::PECAS_PRETAS);
	brancasPerderam.jogar(32, casaTabuleiroTetralath::PECAS_BRANCAS);
	if(brancasPerderam.avaliarParaPecasDaCor(casaTabuleiroTetralath::PECAS_PRETAS) == tabuleiroTetralath::VITORIA
	   and brancasPerderam.avaliarParaPecasDaCor(casaTabuleiroTetralath::PECAS_BRANCAS) == tabuleiroTetralath::PERDA){
		cout << "\tavaliarParaPecasDaCor está OK (3 de 5).\n";
	} else {
		cout << "\tavaliarParaPecasDaCor está NOT_OK (3 de 5).\n";
	}
	
	pretasGanharam.jogar(23, casaTabuleiroTetralath::PECAS_BRANCAS);
	pretasGanharam.jogar(30, casaTabuleiroTetralath::PECAS_PRETAS);
	pretasGanharam.jogar(21, casaTabuleiroTetralath::PECAS_BRANCAS);
	pretasGanharam.jogar(22, casaTabuleiroTetralath::PECAS_PRETAS);
	pretasGanharam.jogar(31, casaTabuleiroTetralath::PECAS_BRANCAS);
	pretasGanharam.jogar(38, casaTabuleiroTetralath::PECAS_PRETAS);
	pretasGanharam.jogar(29, casaTabuleiroTetralath::PECAS_BRANCAS);
	pretasGanharam.jogar(15, casaTabuleiroTetralath::PECAS_PRETAS);
	if(pretasGanharam.avaliarParaPecasDaCor(casaTabuleiroTetralath::PECAS_PRETAS) == tabuleiroTetralath::VITORIA
	   and pretasGanharam.avaliarParaPecasDaCor(casaTabuleiroTetralath::PECAS_BRANCAS) == tabuleiroTetralath::PERDA){
		cout << "\tavaliarParaPecasDaCor está OK (4 de 5).\n";
	} else {
		cout << "\tavaliarParaPecasDaCor está NOT_OK (4 de 5).\n";
	}
	
	pretasPerderam.jogar(1, casaTabuleiroTetralath::PECAS_BRANCAS);
	pretasPerderam.jogar(13, casaTabuleiroTetralath::PECAS_PRETAS);
	pretasPerderam.jogar(7, casaTabuleiroTetralath::PECAS_BRANCAS);
	pretasPerderam.jogar(0, casaTabuleiroTetralath::PECAS_PRETAS);
	pretasPerderam.jogar(12, casaTabuleiroTetralath::PECAS_BRANCAS);
	pretasPerderam.jogar(6, casaTabuleiroTetralath::PECAS_PRETAS);
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

	tabuleiro5.jogar(1, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiro5.jogar(30, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiro5.jogar(19, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiro5.jogar(54, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiro5.jogar(33, casaTabuleiroTetralath::PECAS_BRANCAS);
	if(tabuleiro5.calcularNumeroMovimentosLegais() == tabuleiroTetralath::NUMERO_CASAS - 5){
		cout << "\tcalcularNumeroMovimentosLegais está OK (2 de 8).\n";
	} else {
		cout << "\tcalcularNumeroMovimentosLegais está NOT_OK (2 de 8).\n";
	}
	
	tabuleiro30.jogar(0, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiro30.jogar(5, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiro30.jogar(11, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiro30.jogar(18, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiro30.jogar(26, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiro30.jogar(7, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiro30.jogar(2, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiro30.jogar(20, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiro30.jogar(13, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiro30.jogar(36, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiro30.jogar(28, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiro30.jogar(9, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiro30.jogar(43, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiro30.jogar(22, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiro30.jogar(4, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiro30.jogar(38, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiro30.jogar(15, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiro30.jogar(51, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiro30.jogar(30, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiro30.jogar(24, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiro30.jogar(45, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiro30.jogar(40, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiro30.jogar(56, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiro30.jogar(53, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiro30.jogar(17, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiro30.jogar(42, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiro30.jogar(32, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiro30.jogar(55, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiro30.jogar(47, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiro30.jogar(1, casaTabuleiroTetralath::PECAS_PRETAS);
	if(tabuleiro30.calcularNumeroMovimentosLegais() == tabuleiroTetralath::NUMERO_CASAS - 30){
		cout << "\tcalcularNumeroMovimentosLegais está OK (3 de 8).\n";
	} else {
		cout << "\tcalcularNumeroMovimentosLegais está NOT_OK (3 de 8).\n";
	}
	
	//Exemplo de empate retirado da definicao do trabalho. Sim, possui muito mais brancas do que pretas.
	tabuleiroCheio.jogar(0, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(2, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroCheio.jogar(1, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(6, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroCheio.jogar(3, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(9, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroCheio.jogar(4, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(11, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroCheio.jogar(5, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(14, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroCheio.jogar(7, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(17, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroCheio.jogar(8, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(20, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroCheio.jogar(10, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(23, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroCheio.jogar(12, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(27, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroCheio.jogar(13, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(30, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroCheio.jogar(15, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(33, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroCheio.jogar(16, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(37, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroCheio.jogar(18, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(40, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroCheio.jogar(19, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(43, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroCheio.jogar(21, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(46, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroCheio.jogar(22, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(49, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroCheio.jogar(24, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(51, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroCheio.jogar(25, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(54, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroCheio.jogar(26, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(58, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroCheio.jogar(28, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(29, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(31, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(32, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(34, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(35, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(36, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(38, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(39, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(41, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(42, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(44, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(45, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(47, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(48, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(50, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(52, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(53, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(55, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(56, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(57, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(59, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroCheio.jogar(60, casaTabuleiroTetralath::PECAS_BRANCAS);
	if(tabuleiroCheio.calcularNumeroMovimentosLegais() == 0){
		cout << "\tcalcularNumeroMovimentosLegais está OK (4 de 8).\n";
	} else {
		cout << "\tcalcularNumeroMovimentosLegais está NOT_OK (4 de 8).\n";
	}
	
	tabuleiroBrancasGanharam.jogar(14, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroBrancasGanharam.jogar(12, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroBrancasGanharam.jogar(29, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroBrancasGanharam.jogar(47, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroBrancasGanharam.jogar(21, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroBrancasGanharam.jogar(24, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroBrancasGanharam.jogar(37, casaTabuleiroTetralath::PECAS_BRANCAS);
	if(tabuleiroBrancasGanharam.calcularNumeroMovimentosLegais() == 0){
		cout << "\tcalcularNumeroMovimentosLegais está OK (5 de 8).\n";
	} else {
		cout << "\tcalcularNumeroMovimentosLegais está NOT_OK (5 de 8).\n";
	}
	
	tabuleiroBrancasPerderam.jogar(13, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroBrancasPerderam.jogar(31, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroBrancasPerderam.jogar(14, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroBrancasPerderam.jogar(47, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroBrancasPerderam.jogar(15, casaTabuleiroTetralath::PECAS_BRANCAS);
	if(tabuleiroBrancasPerderam.calcularNumeroMovimentosLegais() == 0){
		cout << "\tcalcularNumeroMovimentosLegais está OK (6 de 8).\n";
	} else {
		cout << "\tcalcularNumeroMovimentosLegais está NOT_OK (6 de 8).\n";
	}
	
	tabuleiroPretasGanharam.jogar(1, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroPretasGanharam.jogar(40, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroPretasGanharam.jogar(7, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroPretasGanharam.jogar(22, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroPretasGanharam.jogar(55, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroPretasGanharam.jogar(31, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroPretasGanharam.jogar(27, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroPretasGanharam.jogar(14, casaTabuleiroTetralath::PECAS_PRETAS);
	if(tabuleiroPretasGanharam.calcularNumeroMovimentosLegais() == 0){
		cout << "\tcalcularNumeroMovimentosLegais está OK (7 de 8).\n";
	} else {
		cout << "\tcalcularNumeroMovimentosLegais está NOT_OK (7 de 8).\n";
	}
	
	tabuleiroPretasPerderam.jogar(2, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroPretasPerderam.jogar(40, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroPretasPerderam.jogar(12, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroPretasPerderam.jogar(22, casaTabuleiroTetralath::PECAS_PRETAS);
	tabuleiroPretasPerderam.jogar(51, casaTabuleiroTetralath::PECAS_BRANCAS);
	tabuleiroPretasPerderam.jogar(31, casaTabuleiroTetralath::PECAS_PRETAS);
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