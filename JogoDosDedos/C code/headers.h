#ifndef Headers
#define Headers

/* Lista Generalizada usando ponteiro para void como forma de apontar para dados */
typedef struct Lista{
    struct Lista* prox;
    void* info;
}Lista;

/* Fila Implementada usando ponteiros para Lista, junto com seus demais metodos Apresentados abaixo*/
typedef struct Fila{
    Lista* Head;
    Lista* Tail;
    int tamanho;
}Fila;

typedef struct Jogo{
    int bracos;
    int* mao;
    int dedos;
}Player;

typedef struct Estado{
    int local;                              //Localização do Estado no arquivo de estatistica
    int possibs;                            //Quantidade de possibilidade de ações já classificadas
    double winrate;
    int* maos;                              //Vetor contedo as informações da mão nesse estado
    Fila* localDestino;
    
    int quantidade;
}Estado;
/* Adicionar no struct de Estados "Vezesjájogadas" (ou algo assim)
E atualizar as funções de ler e escrever dados para suportar essa 
nova informação*/
/* Mudar Função de Atualizar estátistica para incrementar as vezes já jogadas
de um estado */
/* Diferenciar direito um estado de vitoria de um de derrota da fila "agora" 
na hora de atualizar as estatisticas*/
/* Criar o calculo para o winrate*/
/*************Finalizada parte de armazenar dados***************/
/* Funções Do arquivo rules */
Player* CriaJogador(int bracos, int dedos);
int VerificaSePerdeu(Player* p);
int JogadaValidaAtaque(Player* p1, Player* p2, int maoAtaque, int maoDestino);
int FazerJogadaAtaque(Player* p1, Player* p2, int maoAtaque, int maoDestino);
int JogadaValidaSeparar(Player* p, int mao, int validar);
int FazerJogadaSeparar(Player* p, int mao);
void PrintaJogo(Player* p1, Player* p2);
void SimPvPGame();
/* */

/* Funções do arquivo do bot */
void PrintFilaEstados(Fila* f);                           
void AtualizaFila(Player* Ataque, Player* Defesa, Fila* f);
Fila* LeDadosEstatisca();
void EscreveDados(Fila* Att);
void AtualizaEstatisticas(Fila* Lido, Fila* Agora, int Ganhador);
void SimPvRandGame();
Estado* ProcuraNosDados(Fila* Lido, Estado* Atual);
void SimPvBOTGame();
void SimBOTvBOTGame();
void SimRandvRandGame();
/* Funções de Manipulação de Filas */

Fila* CriaFilaVazia();                                                             //Cria uma fila e retorna ponteiro para ela
void FreeFila(Fila* f);                                                            //Libera os dados da fila e de seus elemento
void InserirNaFila(Fila* f, void* elemento);                                       //Insere elemento no Final da Fila
void* TiraElementoDaFila(Fila* f);                                                 //Tira elemento qualquer da fila, retornando o ponteiro para ele
int FVazia(Fila* f);                                                               //Retorna 1 caso a Fila esteja vazia e 0 caso contrario
void* AcessaElemento(Fila* f, int n);
void TiraEspecificDaFila(Fila* f, void* inf);
int ProcuraRef(Fila* f, void* inf);
/* Fim das funções de Fila */
//void SimGamePvRand();
#endif