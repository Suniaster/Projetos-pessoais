#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#include <time.h>
#include <unistd.h>


/* Precisa de Fila de Estados Como entrada */
void ProcessaFilaFinal(Fila* f){
    Estado* Analisando;
    int swap;
    for(int i=0;i<f->tamanho-1;i++){
        Analisando = AcessaElemento(f,i);
        Analisando->local=i;
        Analisando->winrate=1;
        Analisando->possibs=1;
        Analisando->quantidade=1;
        // if(Analisando->maos[0]>Analisando->maos[1]){
        //     swap=Analisando->maos[0];
        //     Analisando->maos[0]=Analisando->maos[1];
        //     Analisando->maos[1]=swap;
        // }
        // if(Analisando->maos[2]>Analisando->maos[3]){
        //     swap=Analisando->maos[2];
        //     Analisando->maos[2]=Analisando->maos[3];
        //     Analisando->maos[3]=swap;
        // }
    }
    Analisando = AcessaElemento(f,f->tamanho-1);
    Analisando->local=f->tamanho-1;
    Analisando->winrate=1;
    Analisando->possibs=0;
    Analisando->quantidade=1;
    // if(Analisando->maos[0]>Analisando->maos[1]){
    //         swap=Analisando->maos[0];
    //         Analisando->maos[0]=Analisando->maos[1];
    //         Analisando->maos[1]=swap;
    // }
    // if(Analisando->maos[2]>Analisando->maos[3]){
    //     swap=Analisando->maos[2];
    //     Analisando->maos[2]=Analisando->maos[3];
    //     Analisando->maos[3]=swap;
    // }
}
/* Atualiza os dados das ultimas jogadas da partida que está ocorrendo */
void AtualizaFila(Player* Ataque, Player* Defesa, Fila* f){
    Estado* Est;                               //Variavel Para retorno
    Estado* auxFree;                           //Variavel auxiliar para liberação de dados extras
    Est = (Estado*)malloc(sizeof(Estado));     //Alocando Variavel para inserir na fila
    Est->maos = (int*)malloc(4*sizeof(int));  //Alocando espaço para salvar o estado atual do jogo
    Est->possibs=1;                            //A não ser a ultima jogada, todas que estão sendo salvas tem pelo menos uma possibilidade de onde ir
    Est->localDestino = CriaFilaVazia();       //Cria fila para armazenar Locais da fila onde está salvo o destino
    for(int i=0;i<2;i++){                      //Quantidade fixa de braços analizados como 2
        Est->maos[i]=Ataque->mao[i];
        Est->maos[i+2]=Defesa->mao[i];
    }
    if(f->tamanho>5){                          //Caso a quantiade de jogadas passe de 5, tira a ultima jogada feita
        auxFree=TiraElementoDaFila(f);
        free(auxFree->maos);
        FreeFila(auxFree->localDestino);
        free(auxFree);
    }
    InserirNaFila(f,Est);                      //Insere elemento na fila
}

/* Função Para ler Dados e retornar uma fila de Estados com tudo já lido */
Fila* LeDadosEstatisca(){
    int Quantidade;
    Estado* Lendo;
    FILE* Entrada;
    Fila* f;
    f=CriaFilaVazia();
    int* Dest;
    Entrada = fopen("estatisticas.txt","r");
    fscanf(Entrada,"%d ",&Quantidade);
    for(int i = 0;i<Quantidade;i++){

        Lendo = (Estado*)malloc(sizeof(Estado));                    //Aloca espaço para a struct
        Lendo->maos = (int*)malloc(4*sizeof(int));                  //Aloca espaço para o estado que essa struct representa
        Lendo->local=i;                                             //Armazena local onde está tal estado de acordo com o contador
        for(int j=0; j < 4;j++){                                                    
            fscanf(Entrada,"%d ",&Lendo->maos[j]);
        }
        fscanf(Entrada,"%d ",&Lendo->quantidade);
        fscanf(Entrada,"%lf %d ", &Lendo->winrate,&Lendo->possibs); 

        Lendo->localDestino=CriaFilaVazia();                        //Cria Fila para armazenar Locais de Destino possiveis

        for(int j = 0; j< Lendo->possibs;j++){                       
            Dest=(int*)malloc(sizeof(int));                         //Aloca Espaço para um numero novo ser adicionado na lista de locais de destino
            fscanf(Entrada,"%d ",Dest);
            InserirNaFila(Lendo->localDestino,Dest);
        }
        InserirNaFila(f,Lendo);                                     //Insere estado lido na fila
    }
    fclose(Entrada);
    return f;
} 

/* Função que recebe Fila de Estados para salvar seus dados */
void EscreveDados(Fila* Att){
    FILE* saida;
    saida=fopen("estatisticas.txt","w");

    fprintf(saida,"%d\n", Att->tamanho);             //Primeira Linha sempre será a quantidade de dados já salva

    Estado* Salvando;                                //Auxiliar para Salvar dados
    int j;                                           //Contador auxiliar
    int tamanhoInicial=Att->tamanho;                 //Salva Tamanho da Fila do instante de entrada
    int* Dest;
    for(int i=0 ; i < tamanhoInicial ; i++){
        Salvando=TiraElementoDaFila(Att);            //Tira o primeiro elemento da fila para escrever seus dados
        for(j=0;j<4;j++){                            //Escreve os dados do estado retirado
            fprintf(saida,"%d ",Salvando->maos[j]);
        }
        fprintf(saida,"%d ",Salvando->quantidade);
        fprintf(saida,"%lf %d ",Salvando->winrate,Salvando->possibs);      //Escreve o número de possibilidades que essa jogada pode levar
        for(j=0;j < Salvando->possibs;j++){                 //Para cada uma das possibilidade, escreve onde elas estão e suas winrates
            Dest=TiraElementoDaFila(Salvando->localDestino);
            fprintf(saida,"%d ", *Dest);
            InserirNaFila(Salvando->localDestino,Dest);
        }
        fprintf(saida,"\n");
        InserirNaFila(Att,Salvando);
    }
    fclose(saida);
}

Estado* ProcuraNosDados(Fila* Lido, Estado* Atual){
    int i,j,k,confere=0;
    Estado* auxLido;
    for(i=0 ;i < Lido->tamanho ;i++){
        auxLido = AcessaElemento(Lido,i);
        confere=0;
        for(j=0;j<5;j++){
            if(auxLido->maos[j] != Atual->maos[j]){
                break;
            }
            confere++;
        }
        if(confere>=4){
            return auxLido;
        }
    }
    return NULL;
}

void AtualizaEstatisticas(Fila* Lido, Fila* Agora, int Ganhador){
    Estado* analisando;                         //Auxiliar para coletar informação do estado a ser atualizado
    Estado* analisadoProximo;                   //Auxiliar para coletar inormação do estado posterior ao a ser atualizado

    Estado* procura;                            //Auxiliar para Procurar dados na fila Lido
    Estado* procura2;
    int tamanhoAgora = Agora->tamanho;
    int novosEstados=0;                         //Contador de novos estados
    Estado* auxFree;
    int* adicionarLinha;
    int booleana=0;
    ProcessaFilaFinal(Agora);
    //Ganhador sempre é o elemento tamanhoAgora-1 da fila agora
    //A partir dai vai alternando entre estado de derrota e vitoria
    for(int Contador = tamanhoAgora - 1; Contador >= 0 ; Contador--){
        analisando=AcessaElemento(Agora,Contador);                          //Começa a acessar a fila de trás pra frente
        procura = ProcuraNosDados(Lido,analisando);
        if(procura!=NULL){ 
            procura->quantidade++;                                                 //Se o estado já estiver nas estatisticas
            if(Contador == tamanhoAgora-1){                                 //O ultimo estado da fila é obrigatoriamente uma vitória
                continue;                                                   //Se o estado de vitoria já estiver nas estatisticas, nada a se muadr nele
            }
            /*Recebe o valor posterior ao sendo analisado da fila de agora
            Ou seja, pega o estado para o qual o estado que está sendo analisado
            foi no jogo atual.*/
            analisadoProximo = AcessaElemento(Agora,Contador+1);
            /*Procura por esse estado posterior nas estatistiacas */
            procura2 = ProcuraNosDados(Lido, analisadoProximo);
                /*Procura2 não pode ser nulo, pois se tratando de um estado posterior ao analisado,
                ele obrigatoriamente já está entre as estatisticas, podendo estar anteriormente a
                execução ou ter sido adicionado anteriormente ao elemento analisado agora*/
            

            /*Olha entre as "localdestino" do estado analisado na estatistica para ver se 
            a linha da proxima jogada já está lá*/
            booleana=1;
            for(int i=0;i < procura->localDestino->tamanho ;i++){
                adicionarLinha = AcessaElemento(procura->localDestino,i);
                if(*adicionarLinha == procura2->local)booleana=0;
            }
            /*Se não estiver, adiciona essa possbilidade a lista de possibilidades*/
            if(booleana){
                procura->possibs++;
                adicionarLinha = (int*)malloc(sizeof(int));
                *adicionarLinha = procura2->local;
                InserirNaFila(procura->localDestino, adicionarLinha);                            //Mudar
            }
            if((-(Contador+tamanhoAgora-1))%2==0){
                    procura->winrate=(((double)procura->winrate*(procura->quantidade-1))+1)/(double)procura->quantidade;
            }
            else{
                procura->winrate=(((double)procura->winrate*(procura->quantidade-1)))/(double)procura->quantidade;
            }  

        }
        /* Para algum Estado ainda que está fora das estatisticas */
        else{
            if(Contador == tamanhoAgora-1){
                analisando->possibs=0;
                analisando->local = Lido->tamanho;
                analisando->winrate=1;
            }
            else{
                analisadoProximo= AcessaElemento(Agora,Contador+1);
                procura2 = ProcuraNosDados(Lido,analisadoProximo);

                analisando->possibs = 1;
                analisando->local = Lido->tamanho;
                analisando->winrate=1;                              //Mudar

                adicionarLinha = (int*)malloc(sizeof(int));
                adicionarLinha[0] = procura2->local;
                InserirNaFila(analisando->localDestino, adicionarLinha);

            }
            if((-(Contador+tamanhoAgora-1))%2==0){
                    analisando->winrate=1;
            }
            else{
                analisando->winrate=0;
            }                             

            InserirNaFila(Lido, analisando);
        }
    }
    for(int i=0;i<Agora->tamanho;i++){
        analisando=AcessaElemento(Agora,i);
        booleana=ProcuraRef(Lido,analisando);
        if(booleana){
            i=-1;
            TiraEspecificDaFila(Agora,analisando);
        }
    }
    /* Para cada um dos elementos na fila Agora,
    Deve-se procurar qual linha é igual ao estado atual do jogo
    Ao achar, atualizar os dados das possibilidade
    vendo se a proxima jogada feita atualmente já está entre as outras
    Caso já esteja, atualiza seu winrate
    caso não, coloca-a lá */ 
}

void MelhorJogada(Player* p1, Player* p2, Fila* f, int* mao1, int* mao2){
    Estado* procura;
    procura = (Estado*)malloc(sizeof(Estado));
    procura->maos = (int*)malloc(4*sizeof(int));
    Estado* Encontrado;
    Estado* Evaluate;
    Estado* Best_Choice;
    double max_winrate = -1;
    int Linha_max;
    int aux_mao1,aux_mao2;
    int a,b,c,d,e;
    int booleana;
    int *Linha;
    int i,j;
    int o;
    Player* p1_m,*p2_m;

    p1_m=CriaJogador(2,5);
    p2_m=CriaJogador(2,5);
    for(i=0;i<2;i++){
        procura->maos[i]=p1->mao[i];
        procura->maos[i+2]=p2->mao[i];
    }
    Encontrado = ProcuraNosDados(f,procura);
    if(Encontrado!=NULL){
        for(i=0;i<Encontrado->localDestino->tamanho;i++){
            Linha = AcessaElemento(Encontrado->localDestino, i);
            Evaluate = AcessaElemento(f, *Linha);
            if(Evaluate->winrate > max_winrate){
                max_winrate = Evaluate->winrate;
                Best_Choice = Evaluate;
            }
        }
        printf("Estado encontrado: ");
        for(i=0;i<4;i++)printf("%d ",Encontrado->maos[i]);
        printf("\n");
        printf("Minha chance de Ganhar é %lf\n", Best_Choice->winrate);
        
        printf("O estado para o qual eu devo ir é: " );
        for(i=0;i<4;i++)printf("%d ",Best_Choice->maos[i]);
        printf("\n");
        for(i=0; i < 2;i++){
            p1_m->mao[i]=Best_Choice->maos[i+2];
            p2_m->mao[i]=Best_Choice->maos[i];
        }
        a = p1_m->mao[0] - Encontrado->maos[0]; 
        b = p1_m->mao[1] - Encontrado->maos[1];
        c = p2_m->mao[0] - Encontrado->maos[2];
        d = p2_m->mao[1] - Encontrado->maos[3];
        
        if(c!=0){
            if((p1->mao[0] + p2->mao[0])%5 == Best_Choice->maos[0]){
                *mao1=0;
                *mao2=0;
            }
            else{
                *mao1=1;
                *mao2=0;
            }
        }
        if(d!=0){
            if((p1->mao[0] + p2->mao[1])%5 == Best_Choice->maos[1]){
                *mao1=0;
                *mao2=1;
            }
            else{
                *mao1=1;
                *mao2=1;
            }
        }
        if(a!=0 && b!=0){
            if(a<0){
                *mao1=0;
                *mao2=-1;
            }
            else{
                *mao1=1;
                *mao2=-1;
            }
        }
        printf("Minha jogada será: %d %d\n", *mao1+1, *mao2+1);
        if(Best_Choice->winrate==0){
            i=0;
            j=0;
            c=0;
            for(i=0;i<2;i++){
                for(j=-1;j<2;j++){
                    if((JogadaValidaAtaque(p1,p2,i,j)||JogadaValidaSeparar(p1,i,j))&&(i!=*mao1 || j!=*mao2)){
                        *mao1=i;
                        *mao2=j;
                        c=1;
                        break;
                    }
                }
                if(c)break;
            }
        }
    
    }
    else{
        do{
            *mao1=(rand()%3)-1;
            *mao2=(rand()%3)-1;
        }while(!(JogadaValidaAtaque(p1,p2,*mao1,*mao2) || JogadaValidaSeparar(p1,*mao1,*mao2)));
        printf("Nunca joguei isso!\n");
    }
    free(procura->maos);
    free(procura);
    //free(Linha);
    free(p1_m->mao);
    free(p1_m);
    free(p2_m->mao);
    free(p2_m);
}

void SimPvRandGame(){
    /* Variaveis do Jogo */
    Player* p1;
    Player* p2;
    p1 = CriaJogador(2,5);
    p2 = CriaJogador(2,5);
    Player *Ataque;
    Player *Defesa;

    /* Controladores Do jogo */
    int Round=0;
    int mao1,mao2,Ganhador;

    /* Auxiliares para analise de dados */
    Fila* f;
    Fila* Entrada;
    f = CriaFilaVazia();
    Entrada = LeDadosEstatisca();
    srand(time(NULL));

    /* Loop Do Jogo */
    while(1){
        system("clear");
        PrintaJogo(p1,p2);
        printf("Jogador ");

        /* Mudança de turno */
        if(Round%2==0){
            Ataque=p1;
            Defesa=p2;
            printf("1 ");
        }
        else{
            Ataque=p2;
            Defesa=p1;
            printf("2 ");
        }
        printf("--> ");

        /* Jogada Aleatoria */
        if(Round%2==0){
            do{
                mao1=(rand()%3)-1;
                mao2=(rand()%3)-1;
            }while(!(JogadaValidaAtaque(p1,p2,mao1,mao2) || JogadaValidaSeparar(p1,mao1,mao2)));
        }
        else{
            //do{
                MelhorJogada(p2,p1,Entrada,&mao1,&mao2);
            //}while(!(JogadaValidaAtaque(p1,p2,mao1,mao2) || JogadaValidaSeparar(p1,mao1,mao2)));
        }

        /* Realiza jogada escolhida */
        if(mao2<0){    
            FazerJogadaSeparar(Ataque,mao1);
        }
        else{
            FazerJogadaAtaque(Ataque,Defesa,mao1,mao2);
        }

        /* Atualiza Dados coletados */
        AtualizaFila(Defesa,Ataque,f);
        if(VerificaSePerdeu(Defesa)){
            printf("Acabou o jogo\n");
            if(Round%2==0)Ganhador=1;
            else Ganhador = 2;
            break;
        }
        Round++;
    }
    AtualizaEstatisticas(Entrada,f,Ganhador);
    EscreveDados(Entrada);

    /* Liberando espaço alocado */
    Estado* auxFree;

    /* Free na Fila de Dados */
    while(!FVazia(Entrada)){
        auxFree=TiraElementoDaFila(Entrada);
        FreeFila(auxFree->localDestino);
        free(auxFree->maos);
        free(auxFree);
    }
    free(Entrada->Head);
    free(Entrada);

    /* Free na fila atual lida */
    while(!FVazia(f)){
        auxFree = TiraElementoDaFila(f);
        free(auxFree->maos);
        FreeFila(auxFree->localDestino);
        free(auxFree);
    }
    free(f->Head);
    free(f);

    /* Free mão dos player OK */
    free(p1->mao);
    free(p1);
    free(p2->mao);
    free(p2);
}
void SimPvBOTGame(){
    /* Variaveis do Jogo */
    Player* p1;
    Player* p2;
    p1 = CriaJogador(2,5);
    p2 = CriaJogador(2,5);
    Player *Ataque;
    Player *Defesa;

    /* Controladores Do jogo */
    int Round=0;
    int mao1,mao2,Ganhador;

    /* Auxiliares para analise de dados */
    Fila* f;
    Fila* Entrada;
    f = CriaFilaVazia();
    Entrada = LeDadosEstatisca();
    srand(time(NULL));

    /* Loop Do Jogo */
    while(1){
        printf("\n\n\n\n");
        //system("clear");
        PrintaJogo(p1,p2);
        printf("Jogador ");

        /* Mudança de turno */
        if(Round%2==0){
            Ataque=p1;
            Defesa=p2;
            printf("1 ");
        }
        else{
            Ataque=p2;
            Defesa=p1;
            printf("2 ");
        }
        printf("--> ");

        if(Round%2==0){
            do{
                scanf("%d %d",&mao1,&mao2);
                mao1--;
                mao2--;
                // mao1=(rand()%3)-1;
                // mao2=(rand()%3)-1;
            }while(!(JogadaValidaAtaque(p1,p2,mao1,mao2) || JogadaValidaSeparar(p1,mao1,mao2)));
        }
        else{
            //do{
                MelhorJogada(p2,p1,Entrada,&mao1,&mao2);
            //}while(!(JogadaValidaAtaque(p1,p2,mao1,mao2) || JogadaValidaSeparar(p1,mao1,mao2)));
        }

        /* Realiza jogada escolhida */
        if(mao2<0){    
            FazerJogadaSeparar(Ataque,mao1);
        }
        else{
            FazerJogadaAtaque(Ataque,Defesa,mao1,mao2);
        }

        /* Atualiza Dados coletados */
        AtualizaFila(Defesa,Ataque,f);
        if(VerificaSePerdeu(Defesa)){
            printf("Acabou o jogo\n");
            if(Round%2==0)Ganhador=1;
            else Ganhador = 2;
            break;
        }
        Round++;
    }
    AtualizaEstatisticas(Entrada,f,Ganhador);
    EscreveDados(Entrada);

    /* Liberando espaço alocado */
    Estado* auxFree;

    /* Free na Fila de Dados */
    while(!FVazia(Entrada)){
        auxFree=TiraElementoDaFila(Entrada);
        FreeFila(auxFree->localDestino);
        free(auxFree->maos);
        free(auxFree);
    }
    free(Entrada->Head);
    free(Entrada);

    /* Free na fila atual lida */
    while(!FVazia(f)){
        auxFree = TiraElementoDaFila(f);
        free(auxFree->maos);
        FreeFila(auxFree->localDestino);
        free(auxFree);
    }
    free(f->Head);
    free(f);

    /* Free mão dos player OK */
    free(p1->mao);
    free(p1);
    free(p2->mao);
    free(p2);
}
void SimBOTvBOTGame(){
    /* Variaveis do Jogo */
    Player* p1;
    Player* p2;
    p1 = CriaJogador(2,5);
    p2 = CriaJogador(2,5);
    Player *Ataque;
    Player *Defesa;

    /* Controladores Do jogo */
    int Round=0;
    int mao1,mao2,Ganhador;

    /* Auxiliares para analise de dados */
    Fila* f;
    Fila* Entrada;
    f = CriaFilaVazia();
    Entrada = LeDadosEstatisca();
    srand(time(NULL));

    /* Loop Do Jogo */
    while(1){
        printf("\n\n\n\n");
        //system("clear");
        PrintaJogo(p1,p2);
        printf("Jogador ");

        /* Mudança de turno */
        if(Round%2==0){
            Ataque=p1;
            Defesa=p2;
            printf("1 ");
        }
        else{
            Ataque=p2;
            Defesa=p1;
            printf("2 ");
        }
        printf("--> ");

        if(Round%2==0){
            // do{
            //     scanf("%d %d",&mao1,&mao2);
            //     mao1--;
            //     mao2--;
            //     // mao1=(rand()%3)-1;
            //     // mao2=(rand()%3)-1;
            // }while(!(JogadaValidaAtaque(p1,p2,mao1,mao2) || JogadaValidaSeparar(p1,mao1,mao2)));
            MelhorJogada(p1,p2,Entrada,&mao1,&mao2);

        }
        else{
            //do{
                MelhorJogada(p2,p1,Entrada,&mao1,&mao2);
            //}while(!(JogadaValidaAtaque(p1,p2,mao1,mao2) || JogadaValidaSeparar(p1,mao1,mao2)));
        }

        /* Realiza jogada escolhida */
        if(mao2<0){    
            FazerJogadaSeparar(Ataque,mao1);
        }
        else{
            FazerJogadaAtaque(Ataque,Defesa,mao1,mao2);
        }

        /* Atualiza Dados coletados */
        AtualizaFila(Defesa,Ataque,f);
        if(VerificaSePerdeu(Defesa)){
            printf("Acabou o jogo\n");
            if(Round%2==0)Ganhador=1;
            else Ganhador = 2;
            break;
        }
        Round++;
    }
    AtualizaEstatisticas(Entrada,f,Ganhador);
    EscreveDados(Entrada);

    /* Liberando espaço alocado */
    Estado* auxFree;

    /* Free na Fila de Dados */
    while(!FVazia(Entrada)){
        auxFree=TiraElementoDaFila(Entrada);
        FreeFila(auxFree->localDestino);
        free(auxFree->maos);
        free(auxFree);
    }
    free(Entrada->Head);
    free(Entrada);

    /* Free na fila atual lida */
    while(!FVazia(f)){
        auxFree = TiraElementoDaFila(f);
        free(auxFree->maos);
        FreeFila(auxFree->localDestino);
        free(auxFree);
    }
    free(f->Head);
    free(f);

    /* Free mão dos player OK */
    free(p1->mao);
    free(p1);
    free(p2->mao);
    free(p2);
}

void SimRandvRandGame(){
    /* Variaveis do Jogo */
    Player* p1;
    Player* p2;
    p1 = CriaJogador(2,5);
    p2 = CriaJogador(2,5);
    Player *Ataque;
    Player *Defesa;

    /* Controladores Do jogo */
    int Round=0;
    int mao1,mao2,Ganhador;

    /* Auxiliares para analise de dados */
    Fila* f;
    Fila* Entrada;
    f = CriaFilaVazia();
    Entrada = LeDadosEstatisca();
    srand(time(NULL));

    /* Loop Do Jogo */
    while(1){
        system("clear");
        PrintaJogo(p1,p2);
        printf("Jogador ");

        /* Mudança de turno */
        if(Round%2==0){
            Ataque=p1;
            Defesa=p2;
            printf("1 ");
        }
        else{
            Ataque=p2;
            Defesa=p1;
            printf("2 ");
        }
        printf("--> ");

        /* Jogada Aleatoria */
        if(Round%2==0){
            do{
                mao1=(rand()%3)-1;
                mao2=(rand()%3)-1;
            }while(!(JogadaValidaAtaque(p1,p2,mao1,mao2) || JogadaValidaSeparar(p1,mao1,mao2)));
        }
        else{
            do{
                mao1=(rand()%3)-1;
                mao2=(rand()%3)-1;
            }while(!(JogadaValidaAtaque(p2,p1,mao1,mao2) || JogadaValidaSeparar(p2,mao1,mao2)));
        }

        /* Realiza jogada escolhida */
        if(mao2<0){    
            FazerJogadaSeparar(Ataque,mao1);
        }
        else{
            FazerJogadaAtaque(Ataque,Defesa,mao1,mao2);
        }

        /* Atualiza Dados coletados */
        AtualizaFila(Defesa,Ataque,f);
        if(VerificaSePerdeu(Defesa)){
            printf("Acabou o jogo\n");
            if(Round%2==0)Ganhador=1;
            else Ganhador = 2;
            break;
        }
        Round++;
    }
    AtualizaEstatisticas(Entrada,f,Ganhador);
    EscreveDados(Entrada);

    /* Liberando espaço alocado */
    Estado* auxFree;

    /* Free na Fila de Dados */
    while(!FVazia(Entrada)){
        auxFree=TiraElementoDaFila(Entrada);
        FreeFila(auxFree->localDestino);
        free(auxFree->maos);
        free(auxFree);
    }
    free(Entrada->Head);
    free(Entrada);

    /* Free na fila atual lida */
    while(!FVazia(f)){
        auxFree = TiraElementoDaFila(f);
        free(auxFree->maos);
        FreeFila(auxFree->localDestino);
        free(auxFree);
    }
    free(f->Head);
    free(f);

    /* Free mão dos player OK */
    free(p1->mao);
    free(p1);
    free(p2->mao);
    free(p2);
}