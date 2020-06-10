
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no {
  char info[100];
  struct no *anterior;
  struct no *proximo;
};
typedef struct no No;

typedef struct {
  No *inicio;
  No *fim;
}Lista;


void inicializeList(Lista *l){
    l->inicio = NULL;
    l->fim = NULL;
}

int isEmptyList(Lista *l){
   if(l->inicio == NULL && l->fim == NULL){
      return 1;
   } else {
      return 0;
   }
}


int listar(Lista *l){
    if(isEmptyList(l) == 1){
        return 0;
    } else {
        No *noAux;
        noAux = l->inicio;
        printf("\nCARTAS DO DEQUE\n");
        while(noAux != NULL){
            printf("\n%s\n", noAux->info);
            noAux = noAux->proximo;
        }
        return 1;
    }
}


int insereNoInicio(Lista *l, char info[]){
    No *novoNo;
    novoNo = (No*) malloc(sizeof(No));
    if(novoNo != NULL) {
       strcpy(novoNo->info,info);
        if(isEmptyList(l)== 1){
            novoNo->anterior = NULL;
            novoNo->proximo = NULL;
            l->fim = novoNo;
            l->inicio = novoNo;
        }else{
            novoNo->proximo = l->inicio;
            novoNo->anterior= NULL;
            l->inicio->anterior = novoNo;
            l->inicio = novoNo;
        }
        return 1;
    }else{
        return 0;
    }
}

int insereNoFim(Lista *l, char info[]){
    No *novoNo;
    novoNo = (No*) malloc(sizeof(No));
    if(novoNo != NULL) {
       strcpy(novoNo->info, info);
        if(isEmptyList(l)== 1){
            novoNo->anterior = NULL;
            novoNo->proximo = NULL;
            l->fim = novoNo;
            l->inicio = novoNo;
        }else{
            novoNo->proximo = NULL;
            novoNo->anterior= l->fim;
            l->fim->proximo = novoNo;
            l->fim= novoNo;
        }
        return 1;
    }else{
        return 0;
    }
}


char* removeNoInicio(Lista *l) {
    No *novoNo;
    char *removido;
    if (l->fim == NULL){
        return NULL;
    }
    novoNo = l->inicio;
    if(l->inicio == l->fim){
        l->inicio = l->fim = NULL;
    }else{
        l->inicio = novoNo->proximo;
        l->inicio->anterior = NULL;
    }
    strcpy(removido,novoNo->info);
    free(novoNo);
    return removido;
}



char* removeNoFim(Lista *l) {
    No *novoNo;
    char *removido;
    if (l->inicio == NULL){
        return NULL;
    }
    novoNo = l->fim;
    if(l->inicio == l->fim){
        l->inicio = l->fim = NULL;
    }else{
        l->fim = novoNo->anterior;
        l->fim->proximo = NULL;
    }
     strcpy(removido,novoNo->info);
    free(novoNo);
    return removido;
}

