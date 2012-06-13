class casaTabuleiroTetralath;

#define COR_PRETA_LINUX "\033[22;30"
#define COR_VERMELHA_LINUX "\033[22;31"
#define COR_VERDE_LINUX "\033[22;32"
#define COR_MARROM_LINUX "\033[22;33"
#define COR_AZUL_LINUX "\033[22;34"
#define COR_MAGENTA_LINUX "\033[22;35"
#define COR_CIANO_LINUX "\033[22;36"
#define COR_CINZA_LINUX "\033[22;37"
#define COR_CINZA_FORTE_LINUX "\033[01;30"
#define COR_VERMELHA_FRACA_LINUX "\033[01;31"
#define COR_VERDE_FRACA_LINUX "\033[01;32"
#define COR_AMARELA_LINUX "\033[01;33"
#define COR_AZUL_FRACA_LINUX "\033[01;34"
#define COR_MAGENTA_FRACA_LINUX "\033[01;35"
#define COR_CIANO_FRACA_LINUX "\033[01;36"
#define COR_BRANCA_LINUX "\033[01;37"

/*
* Classe que implementa um tabuleiro do jogo Tetralath.
*/
class tabuleiroTetralath{
	public:
		//dados
		/*
		* O número total de casas do tabuleiro.
		*/
		static const int NUMERO_CASAS = 61;
		
		/*
		* Indicam valores extremos e neutro de aplicações da função de avaliação.
		*/
		static const float PERDA = -1.0;
		static const float EMPATE = 0.0;
		static const float VITORIA = 1.0;
		static const float AVALIACAO_INDEFINIDA = -5; //Uma avaliação que ainda não tem valor.
		
		/*
		* Indica que não há estado atingível. É necessário no minimax.
		*/
		static const int NAO_HA_ESTADO_ATINGIVEL = 0;

		//métodos
		/*
		* Construtor da classe.
		* Inicializa todas as casas com seus vizinhos.
		*/
		tabuleiroTetralath(void);
		/*
		* Construtor da classe.
		* Inicializa todas as casas com seus vizinhos.
		* @param manter_registro_jogadas_param Indica se deve ser mantido registro de jogadas neste tabuleiro, para uso em desfazerUltimaJogada.
		*		 Atentar para o alto custo de memória desta opção! Com poucos tabuleiros assim, é possível estourar o limite bem rápido!
		*/
		tabuleiroTetralath(bool manter_registro_jogadas_param);
		/*
		* Construtor de cópia. A cópia é profunda, isto é, não ocupa a mesma posição de memória que o modelo.
		* Inicializa todas as casas com seus vizinhos. Copia o conteúdo de um tabuleiro para este.
		* @param modelo_param O modelo a ser copiado.
		* @param manter_registro_jogadas_param Indica se deve ser mantido registro de jogadas neste tabuleiro, para uso em desfazerUltimaJogada.
		*		 Atentar para o alto custo de memória desta opção! Com poucos tabuleiros assim, é possível estourar o limite bem rápido!
		*/
		tabuleiroTetralath(tabuleiroTetralath *modelo_param, bool manter_registro_jogadas_param);
		/*
		* Determina se a casa de nome passado como parâmetro está ocupada por alguma peça.
		* @param nomeCasa_param O nome da casa a ser verificada. Nomes de casas são constantes definidas no início deste arquivo.
		* @return Booleano indicando se a casa está ocupada por alguma peça.
		*/
		bool casaOcupada(int nomeCasa_param);
		/*
		* Determina se a casa de nome passado como parâmetro está ocupada por alguma peça da cor branca.
		* @param nomeCasa_param O nome da casa a ser verificada. Nomes de casas são constantes definidas no início deste arquivo.
		* @return Booleano indicando se a casa está ocupada por alguma peça branca.
		*	Atenção: Se a casa não estiver ocupada ou se estiver ocupada por peça preta, retornará false.
		*/
		bool casaOcupadaPorPecaBranca(int nomeCasa_param);
		/*
		* Realiza uma jogada das peças passadas como parâmetro.
		* @param nomeCasa_param Casa a jogar.
		* @return Booleano indicando se foi possível realizar a jogada.
		*/
		bool jogar(int nomeCasa_param);
		/*
		* Indica se as peças da cor da peça parâmetro ganharam, isto acontece em um caso:
		*	(1) Se elas formaram uma linha de 4 peças consecutivas.
		* @param nomeCasaReferencia_param Um nome de casa a ser tomada como central, para referência. Tipicamente, esta será a última jogada feita.
		*	Este parâmetro existe por motivos de desempenho.
		* @return Booleano indicando se as peças da cor da peça parâmetro ganharam.
		* 	Atenção: false como retorno indica apenas que as peças parâmetro não ganharam, nada diz sobre empates ou perdedores.
		*/
		bool pecasDaMesmaCorGanharam(int nomeCasaReferencia_param);
		/*
		* Indica se as peças da cor da peça parâmetro perderam, isto acontece em um caso:
		*	(1) Estas peças formaram uma linha de 3 peças consecutivas.
		* @param nomeCasaReferencia_param Um nome de casa a ser tomada como central, para referência. Tipicamente, esta será a última jogada feita.
		*	Este parâmetro existe por motivos de desempenho.
		* @return Booleano indicando se as peças da cor da peça parâmetro perderam.
		* 	Atenção: false como retorno indica apenas que as peças parâmetro não perderam, nada diz sobre ganhadores ou empates.
		*/
		bool pecasDaMesmaCorPerderam(int nomeCasaReferencia_param);
		/*
		* Indica se o tabuleiro está em estado de empate.
		* @return Booleano indicando se houve empate.
		* 	Atenção: false como retorno indica apenas que não houve empate, nada diz sobre ganhadores ou perdedores.
		*/
		bool houveEmpate(void);
		/*
		* Torna o objeto no qual é invocado uma cópia do objeto que é passado como parâmetro. As cópias ocupam posições diferentes de memória.
		* @param modelo_param Tabuleiro que será copiado.
		*/
		void copiarDe(tabuleiroTetralath *modelo_param);
		/*
		* Avalia a utilidade deste tabuleiro para as peças de parâmetro, isto é, o quão favorável o tabuleiro está.
		* @param pecas_avaliacao_param A cor das peças que será usada para avaliar o tabuleiro (PECAS_BRANCAS ou PECAS_PRETAS).
		* @return Um valor float entre -1 e 1. A interpretação é de -1 (PERDA) para perda, 0 (EMPATE) para 
		* 		  empate e 1 (VITORIA) para vitória. Número decimais são permitidos.
		* Esta avaliação é preguiçosa e só testará a vizinhança da penúltima jogada feita.
		*/
		float avaliarPreguicosamenteParaPecasDaCor(int pecas_avaliacao_param);
		/*
		* Avalia a utilidade deste tabuleiro para as peças de parâmetro, isto é, o quão favorável o tabuleiro está.
		* @param pecas_avaliacao_param A cor das peças que será usada para avaliar o tabuleiro (PECAS_BRANCAS ou PECAS_PRETAS).
		* @return Um valor float entre -1 e 1. A interpretação é de -1 (PERDA) para perda, 0 (EMPATE) para 
		* 		  empate e 1 (VITORIA) para vitória. Número decimais NÃO SÃO permitidos.
		*/
		float avaliarParaPecasDaCor(int pecas_avaliacao_param);
		/*
		* Avalia a utilidade deste tabuleiro para as peças de parâmetro, isto é, o quão favorável o tabuleiro está.
		* Esta avaliação é mais custosa e minuciosa.
		* @param pecas_avaliacao_param A cor das peças que será usada para avaliar o tabuleiro (PECAS_BRANCAS ou PECAS_PRETAS).
		* @return Um valor float entre -1 e 1. A interpretação é de -1 (PERDA) para perda, 0 (EMPATE) para 
		* 		  empate e 1 (VITORIA) para vitória. Número decimais SÃO permitidos.
		*/
		float avaliarMinuciosamenteParaPecasDaCor(int pecas_avaliacao_param);
		/*
		* Procura, em uma ordenação interna dos estados, algum que esteja na posição fornecida.
		* @param posicao_param A posição, na ordenação encapsulada desta classe, do estado.
		* @return Ponteiro para outro estado (atingível à partir do estado dado) ou NAO_HA_ESTADO_ATINGIVEL (definido nesta classe).
		* Exemplo: Se de um estado 3 outros forem atingíveis, a chamada a esta função com 1 retorna o primeiro, 2 retorna o
		* segundo e 3 retorna o terceiro. Qualquer número maior retorna NAO_HA_ESTADO_ATINGIVEL. Para números menores que 1,
		* deve retornar NAO_HA_ESTADO_ATINGIVEL também.
		*/
		tabuleiroTetralath* procurarEstadoAtingivelNaPosicao(int posicao_param);
		/*
		* @return O nome da casa na qual foi feita a última jogada.
		*/
		int recuperarNomeCasaUltimaJogada(void);
		/*
		* @return A cor (PECAS_PRETAS ou PECAS_BRANCAS) das peças que jogaram na última jogada.
		*/
		int recuperarCorPecasUltimaJogada(void);
		/*
		* @return O número de tabuleiros diferentes que podem ser criados inserindo uma peça neste.
		*		  Considera-se apenas movimentos legais.
		*/
		int calcularNumeroMovimentosLegais(void);
		/*
		* @return O número de casas que estão livres.
		*/
		int numeroDeCasasLivres(void);
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
		void imprimirCasa(int indice_casa_pintar_param, int casa_selecionada_param);
		/*
		* Imprime casas separadas por espaços. A primeira impressão é de casa. A última, de espaço.
		* As casas variam entre os índices dados.
		* @param casa_inicial_param Nome da primeira casa a ser impressa.
		* @param casa_final_param Nome da última casa a ser impressa.
		* @param casa_selecionada_param Permite pintar uma casa com uma cor. As casas são identificadas por seus índices (entre INDICE_PRIMEIRA_CASA e INDICE_ULTIMA_CASA).
		*		 A cor será verde se a casa puder ser ocupada e vermelha se não puder. Esta cor têm preferência sobre todas as outras.
		*/
		void imprimirDeCasaAtehCasa(int casa_inicial_param, int casa_final_param, int casa_selecionada_param);
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
		*/
		void imprimir(int casa_selecionada_param);
		/*
		* Dado um movimento e um índice de casa, decide para qual índice de casa o cursor do tabuleiro deve ser movido.
		* @param movimento_param Caractere que decide o índice.
		* @param casa_partida_param Casa da qual deseja-se obter o vizinho.
		* @return Índice a ser passado para imprimir. Se não houver vizinho para o movimento, retorna a casa passada como argumento.
		*/
		int getIndiceCasaMovimento(int movimento_param, int casa_partida_param);
		/*
		* Desfaz a última jogada feita com jogar.
		*/
		void desfazerUltimaJogada(void);
		
	private:
		//dados
		/*
		* Array construído no momento da criação com os dados de todas as casas deste tabuleiro.
		*/
		casaTabuleiroTetralath *tabuleiro;
		
		/*
		* Nome da casa (entre INDICE_PRIMEIRA_CASA e INDICE_ULTIMA_CASA) na qual foi feita a última jogada.
		*/
		int casaUltimaJogada;
		
		/*
		* A cor (PECAS_PRETAS ou PECAS_BRANCAS) das peças que jogaram na última jogada.
		*/
		int corUltimaJogada;
		
		/*
		* Array com casas de jogadas passadas, usado para desfazer jogadas passadas.
		*/
		int *casasJogadas;
		
		/*
		* Array com cores de jogadas passadas, usado para desfazer jogadas passadas.
		*/
		int *coresJogadas;
		
		/*
		* Número de jogadas já feitas. Usado para desfazer jogadas passadas.
		*/
		int numeroJogadasFeitas;
		
		/*
		* Índices de casas no array que representa o tabuleiro.
		*/
		static const int INDICE_PRIMEIRA_CASA = 0;
		static const int INDICE_ULTIMA_CASA = 60;
		
		/*
		* Indica se deve manter registro das jogadas feitas, para uso em desfazerUltimaJogada.
		*/
		bool manterRegistroJogadas;
		
		//métodos
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
		*/
		bool haSequenciaCasasMesmaCor(int nomeCasa_param, int tamanhoSequencia_param);

		/*
		* Procura, da forma mais otimizada possível e imaginável, pelo padrão dado no tabuleiro.
		* Este padrão refere-se a casas em seqüência, tanto horizontal como diagonal. 
		* Ele deve ser uma mistura de peças das duas cores com casas vazias.
		* Assim, se um deles tiver o padrão 0...1000, os outros devem, pelo menos, preencher os últimos três 0s com 1s.
		* O padrão deve ser legível em um dos sentidos (esquerda->direita ou direita->esquerda).
		* @param _padraoBrancas Um bitstream correspondente ao padrão de peças sequenciais brancas procuradas.
		* @param _padraoPretas Um bitstream correspondente ao padrão de peças sequenciais pretas procuradas.
		* @param _padraoVazias Um bitstream correspondente ao padrão de peças sequenciais vazias procuradas.
		* O and dos três padrões dirá a largura do padrão procurado. Assim:
		* 	_padraoBrancas = 0...0100 AND
		* 	_padraoPretas = 0...1000 AND  
		* 	_padraoVazias = 0...0011 = 0...1111
		*		Procurará pelo padrão de tamanho 4 PRETA BRANCA VAZIA VAZIA. As casas ao redor deste padrão podem ter qualquer conteúdo.
		* @return A quantidade de vezes que o padrão foi observado.
		*/ 
		int contarOcorrenciasPadrao(unsigned short _padraoBrancas, unsigned short _padraoPretas, unsigned short _padraoVazias);

		/*
		* Cria as vizinhanças e inicializa os dados.
		*/
		void inicializarDados(void);
		

		/*
		* Inverte a cor das peças passadas. Se forem brancas, serão pretas. Se forem pretas, serão brancas.
		* @param pecas_param Cor das peças a ser invertida.
		* @return A cor das peças, após invertida.
		*/
		int inverterCorPecas(int pecas_param);



};
