#include "headers.h"
#include <stdlib.h>
#include <stdio.h>

/* Inicializa a Fila dos Clientes, usando uma célula cabeça */
Fila* CriaFilaVazia(){
    Fila* f;
    f=(Fila*)malloc(sizeof(Fila));
    if(f==NULL)exit(1);
    f->Head=(Lista*)malloc(sizeof(Lista));
    f->Tail=f->Head;
    f->tamanho=0;
    return f;
}
/* Insere um elemento em uma fila qualquer */
void InserirNaFila(Fila* f, void* elemento){
    f->Tail->prox=(Lista*)malloc(sizeof(Lista));
    f->Tail->prox->info=elemento;
    f->Tail=f->Tail->prox;
    f->tamanho++;
}

/* Insere cliente em fila levando em conta a prioridade */

/*********************/

void* TiraElementoDaFila(Fila* f){
    Lista* aux;
    void* Retorno;
    aux=f->Head;
    f->Head=aux->prox;
    Retorno=f->Head->info;
    free(aux);
    f->tamanho--;
    return Retorno;
} 

int FVazia(Fila* f){
    if(f->Head==f->Tail){
        return 1;
    }
    else return 0;
}

void FreeFila(Fila* f){
    while(!FVazia(f)){
        free(TiraElementoDaFila(f));
    }
    free(f->Head);
    free(f);
}

void* AcessaElemento(Fila* f, int n){
    Lista* aux = f->Head->prox;
    for(int i =0;i < n;i++){
        aux=aux->prox;
    }
    return aux->info;
}
void TiraEspecificDaFila(Fila* f, void* inf){
    Lista* aux =f->Head;
    Lista* freeAux;
    while(aux->prox->info != inf){
        aux=aux->prox;
    }
    if(aux->prox==f->Tail)f->Tail=aux;
    freeAux=aux->prox;
    aux->prox=freeAux->prox;
    free(freeAux);
    f->tamanho--;
}
int ProcuraRef(Fila* f, void* inf){
    Lista* aux;
    aux=f->Head->prox;
    while(aux!=f->Tail->prox){
        if(aux->info == inf){
            return 1;
        }
        aux=aux->prox;
    }
    return 0;
}