#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#include <time.h>

Player* CriaJogador(int bracos, int dedos){
    Player* Jogador = (Player*)malloc(sizeof(Player));  //Alocando espaço Para jogador
    Jogador->mao = (int*)malloc(bracos*sizeof(int));    //Alocando espaço Para maos
    for(int i=0; i < bracos; i++){                      //Inicializando todas as mão para começarem com 1 dedo
        Jogador->mao[i]=1;
    }
    Jogador->bracos=bracos;                             //Inicializando quantidade de braços
    Jogador->dedos = dedos;                             //Inicializando quantidade de dedos
    return Jogador;
}

int VerificaSePerdeu(Player* p){
    for(int i = 0; i < p->bracos ;i++){                 //Se alguma mão tiver quantidade de dedos diferente de 0,
        if(p->mao[i]!=0){                               //o player ainda não perdeu
            return 0;
        }
    }
    return 1;
}

int JogadaValidaAtaque(Player* p1, Player* p2, int maoAtaque, int maoDestino){
    if(maoAtaque > (p1->bracos) || maoAtaque < 0)return 0;                      //Se o ataque estiver for feito por uma mão inexistente, o ataque é inválido
    if(p1->mao[maoAtaque] == 0)return 0;                                          //Se a mão de ataque estiver morta, é inválido
    if(maoAtaque > (p2->bracos) || maoDestino < 0)return 0;                     //Se o destino for uma mão inexistente, o ataque é inválido
    if(p2->mao[maoDestino]== 0)return 0;                                         //Se o destino for uma mão morta, o ataque é inválido
    return 1;                                                                   //Se nada disso ocorre, o ataque é válido
}

int FazerJogadaAtaque(Player* p1, Player* p2, int maoAtaque, int maoDestino){
    if(!JogadaValidaAtaque(p1,p2,maoAtaque,maoDestino)){                        //Para ter certeza que não ocorrerão bugs
        printf("Jogada Invaliada\n");
        exit(1);
    }
    p2->mao[maoDestino]+=p1->mao[maoAtaque];                                    //Soma a quantidade de dedos da mão de ataque na mão de Destino
    p2->mao[maoDestino]= p2->mao[maoDestino]%p2->dedos;                         //Usa o % para garantir que não passe do máximo de número de dedos da mão
}

int JogadaValidaSeparar(Player* p, int mao, int validar){
    int ConfereMaos=0;
    if(validar>=0)return 0;                                                         
    if(mao<0)return 0;
    for(int i =0;i<p->bracos;i++){
        if(p->mao[i]==0){
            ConfereMaos=1;                                                      //Se Alguma das mãos estiver morta, deixa confere mãos como 1 ("Verdadeiro")
            break;
        }
    }
    if(p->mao[mao]!=0 && ConfereMaos && (p->mao[mao]%2 == 0)){                  //Para que a jogada de separar seja válida, temos que ter:
        return 1;                                                               //Mão que está separando não sendo 0, deve haver mão para reviver
    }                                                                           //E a divisão por da mão que está dividindo deve ser divisivel por 2
    return 0;
}

int FazerJogadaSeparar(Player* p, int mao){
    if(!JogadaValidaSeparar(p,mao,-1)){
        printf("Jogada Invaliada\n");
        exit(1);
    }
    int PrimeriaVazia;
    for(PrimeriaVazia = 0; PrimeriaVazia < p->bracos ; PrimeriaVazia++){
        if(p->mao[PrimeriaVazia]==0)break;                                      //Acha a primeira mão vazia para receber os dedos
    }
    p->mao[PrimeriaVazia] = p->mao[mao]/2;                                      //"Revive" a mão morta tornando sua quantidade igual a metade daquela que está dividindo
    p->mao[mao] = p->mao[mao]/2;                                                // Divide a quantidade de dedos da mão divisora pela metade 
}

/* Printa o Jogo atual*/
void PrintaJogo(Player* p1, Player* p2){
    int Contador=0;
    int i;
    printf("\n\tJOGADOR 2:\n");
    for(i=0;i<p2->bracos;i++)
    printf("Mão %d:\t\t",i+1);
    printf("\n");
    for(i = 0; i < p2->bracos ;i ++){
        for(Contador = 0 ; Contador < p2->dedos ; Contador++){
            if(Contador < p2->mao[i]){
                printf("| ");
            }
            else printf("  ");
        }
        printf("\t");   
    }

    printf("\n\n\n\tJOGADOR 1:\n");
    for(i=0;i<p1->bracos;i++){
        printf("Mão %d:\t\t",i+1);
    }
    printf("\n");
    for(i = 0; i < p1->bracos ;i ++){
        for(Contador = 0 ; Contador < p1->dedos ; Contador++){
            if(Contador < p1->mao[i]){
                printf("| ");
            }
            else printf("  ");
        }
        printf("\t");   
    }
    printf("\n\n");
}
void FreePlayer(Player* p){
    free(p->mao);
    free(p);
}
void SimPvPGame(){
    Player* p1;
    Player* p2;
    time_t tempo;
    p1 = CriaJogador(2,5);
    p2 = CriaJogador(2,5);
    Player *Ataque;
    Player *Defesa;
    int Round=0;
    int mao1,mao2;
    Fila* f;
    f = CriaFilaVazia();
    srand(tempo);
    while(1){
        system("clear");
        PrintaJogo(p1,p2);
        printf("Jogador ");
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
        do{
            scanf(" %d %d", &mao1,&mao2);
            mao1--;
            mao2--;
        }while(!(JogadaValidaAtaque(Ataque,Defesa,mao1,mao2) || JogadaValidaSeparar(Ataque,mao1,mao2)));
        if(mao2<0){    
            FazerJogadaSeparar(Ataque,mao1);
        }
        else{
            FazerJogadaAtaque(Ataque,Defesa,mao1,mao2);
        }
        if(VerificaSePerdeu(Defesa)){
            printf("Acabou o jogo\n");
            break;
        }
        Round++;
    }
    FreeFila(f);
    free(p1->mao);
    free(p1);
    free(p2->mao);
    free(p2);
}