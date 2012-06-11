/*
* Define um menu, que pode ter submenos e ser dividido em linhas.
* Opções de um menu são sempre strings e podem estar selecionadas ou não.
*/

#ifndef STRING_E_VECTOR
#define STRING_E_VECTOR
	#include <string>
	#include <vector>
#endif

#include <map>

using namespace std;

struct restricaoLinha{
	int linhaRestrita;
	int colunaRestrita;
	int alternativa;
	int linhaOpcao;
	int colunaOpcao;
};

class menu{
	public:

	/*
	* Cria um novo menu, sem opções ainda.
	*/
	menu();

	/*
	* Cria uma nova opção no menu, com as alternativas de argumento.
	* @param _alternativas Vector de strings em que cada elemento é uma alternativa da nova opção.
	*						A nova opção é sempre inserida na linha corrente.
	* @param _legendas Vector de strings em que cada elemento é uma legenda que aparece quando a correspondente alternativa
	*				   em _alternativas estiver selecionada.
	*/
	void criarNovaOpcao(vector<string> _alternativas, vector<string> _legendas);

	/*
	* Cria uma nova linha. Depois desta chamada e até a próxima chamada todas novas opções são inseridas nesta linha.
	*/
	void criarNovaLinha();

	/*
	* Seleciona a opção seguinte à selecionada, na ordem em que foram inseridas no menu.
	* A seleção é circular.
	* A opção selecionada é aquela em cujas alternativas pode-se navegar.
	*/
	void selecionarOpcaoSeguinte();

	/*
	* Seleciona a opção anterior à selecionada, na ordem em que foram inseridas no menu.
	* A seleção é circular.
	* A opção selecionada é aquela em cujas alternativas pode-se navegar.
	*/
	void selecionarOpcaoAnterior();

	/*
	* Seleciona a alternativa seguinte à selecionada, na opção que estiver selecionada.
	* A seleção é circular.
	*/
	void selecionarAlternativaSeguinte();

	/*
	* Seleciona a alternativa anterior à selecionada, na opção que estiver selecionada.
	* A seleção é circular.
	*/
	void selecionarAlternativaAnterior();

	/*
	* @return Um vector de vectors de strings. Cada vector de vectors representa uma linha do menu e cada string que ele contém
	*		  É uma opção selecionada.
	*/
	vector<vector<string> > getAlternativasSelecionadas();

	/*
	* Imprime este menu na tela, evidenciando a opção escolhida e suas alternativas.
	*/
	void imprimir();

	/*
	* Imprime a legenda da alternativa selecionada da opção selecionada.
	*/
	void imprimirLegendaAlternativaSelecionada();

	/*
	* Dá nomes às colunas do menu.
	* @param _nomesColunas Vetor de strings em que cada string é o nome de uma coluna.
	*/
	void nomearColunas(vector<string> _nomesColunas);

	/*
	* Restringe a opção de (_linhaRestrita, _colunaRestrita) para aparecer/ser editável somente quando
	* a alternativa _alternativa de (_linhaOpcao, _colunaOpcao) estiver selecionada.
	* @param _linhaRestrita Índice em linhas do vetor que contém a opção que será restringida.
	* @param _colunaRestritra Índice em elemento de linhas do vetor que contém a opção que será restringida.
	* @param _alternativa Índice em elemento de elemento de linhas da alternativa a cuja seleção está atrelada a 
	*					  exibição da opção restringida.
	* @param _linhaOpcao Índice em linhas do vetor que contém a opção que contém _alternativa.
	* @param _colunaOpcao Índice em elemento de linhas do vetor que contém a opção que contém _alternativa.
	*/
	void restringirExibicaoOpcao(int _linhaRestrita, int _colunaRestrita, int _alternativa, int _linhaOpcao, int _colunaOpcao);

	private:
	/*
	* Vetor de linhas do menu. Cada linha é um vetor de vetores de strings.
	* Cada vetor de uma linha corresponde a uma opção e suas strings são as alternativas da opção.
	*/
	vector<vector<vector<string> > > linhas;

	/*
	* Indica a linha da opção que está selecionada.
	*/
	int linhaOpcaoSelecionada;

	/*
	* Indica a posição da opção selecionada (no vector da linha à qual pertence).
	*/
	int colunaOpcaoSelecionada;

	/*
	* Vetor de alternativas selecionadas do menu. Cada linha é um vetor de ints.
	* Cada int corresponde à alternativa que está selecionada.
	* É um mapeamento de linhas.
	*/
	vector<vector<int> > alternativasSelecionadas;

	/*
	* @return O número de alternativas da opção selecionada.
	*/
	int getNumeroAlternativasOpcaoSelecionada();

	/*
	* @return O índice da alternativa selecionada na opção selecionada.
	*/
	int getIndiceAlternativaSelecionada();

	/*
	* Nomes exibidos sobre as colunas, caso haja.
	*/
	vector<string> nomesColunas;

	/*
	* Relaciona nomes de alternativas com suas legendas.
	*/
	map<string,string> legendas;

	/*
	* Vetor que mapeia as restrições feitas com restringirExibicaoOpcao.
	*/
	vector<restricaoLinha> restricoesExibicaoOpcoes;

	/*
	* Modifica a alternativa selecionada da opção selecionada.
	* @param _alternativa A alternativa que será selecionada.
	* ATENÇÃO: a função não é robusta! Verifique os limites!!
	*/
	void setIndiceAlternativaSelecionadaOpcaoSelecionada(int _alternativa);

	/*
	* @param _linha A linha em que a opção vai ser procurada.
	* @param _coluna A coluna em que a opção vai ser procurada.
	* @return A alternativa que foi selecionada da opção na linha e coluna fornecidas.
	* ATENÇÃO: a função não é robusta! Verifique os limites!!
	*/
	string getNomeAlternativaSelecionadaOpcaoEm(int _linha, int _coluna);

	/*
	* @param _linha Índice do elemento que contém o elemento que contém a opção em linhas.
	* @param _coluna Índice do elemento que contém a posição no elemento que o contém de linhas.
	* @return Booleano indicando se a opção em _linha e _coluna deve aparecer.
	*/
	bool opcaoDeveAparecer(int _linha, int _coluna);
};