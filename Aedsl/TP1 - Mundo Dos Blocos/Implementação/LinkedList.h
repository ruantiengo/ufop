//
// Created by ruant on 03/03/2021.
//

#ifndef TP1_LINKEDLIST_H
#define TP1_LINKEDLIST_H

#include "stdlib.h"
#include "stdio.h"

typedef int TBloco;
typedef struct ESTItem {
    TBloco numBloco;
} TItem;

typedef struct ESTCelula {
    TItem item;
    struct ESTCelula *nextCelula;
} TCelula;

typedef struct ESTList {
    TCelula *primeiro;
    TCelula *ultimo;
} Lista;

void IniciaLista(Lista *lista) {
    lista->primeiro = (TCelula *) malloc(sizeof(TCelula));
    lista->ultimo = lista->primeiro;
    lista->primeiro->nextCelula = NULL;
}

void Insere(Lista *lista, TItem *item) {
    lista->ultimo->nextCelula = (TCelula *) malloc(sizeof(TCelula));
    lista->ultimo = lista->ultimo->nextCelula;
    lista->ultimo->item = *item;
    lista->ultimo->nextCelula = NULL;
}

int TamanhoLista(Lista *list) {
    int tam = 0;
    TCelula *aux = list->primeiro->nextCelula;
    while (aux != NULL) {
        tam++;
        aux = aux->nextCelula;
    }
    return tam;
}

void ImprimeLista(Lista *lista) {
    TCelula *aux = lista->primeiro->nextCelula;
    while (aux != NULL) {
        printf("|  %d  | - ", aux->item.numBloco);
        aux = aux->nextCelula;
    }
    printf("\n");
}

TItem *generateItem(int x) {
    TItem *a = malloc(sizeof(TItem));
    a->numBloco = x;
    return a;
}

TCelula *RetiraUltimo(Lista *lista) {
    TCelula *aux = lista->primeiro->nextCelula;
    TCelula *aux2;
    int cont = 0;
    while (cont < TamanhoLista(lista) - 2) {
        aux = aux->nextCelula;
        cont++;
    }
    lista->ultimo = aux;
    aux2 = aux->nextCelula;
    aux->nextCelula = NULL;
    return aux2;
}

void Retira(Lista *list,TItem* item) {
    TCelula *current = list->primeiro->nextCelula;
    TCelula *previous = list->primeiro;
    while (current != NULL) {
        if (current->item.numBloco == item->numBloco) {
            previous->nextCelula = current->nextCelula;
            if (current == list->ultimo)
                list->ultimo = previous;
            free(current);
            return;
        }
        previous = current;
        current = current->nextCelula;
    }
}

void InserirElementoCelula(Lista *lista, TCelula *celula) {
    TItem *item = malloc(sizeof(struct ESTItem));
    *item = celula->item;
    return Insere(lista, item);
}

void RetiraElementoCelula(Lista *lista, TCelula *celula) {
    TItem *item = malloc(sizeof(struct ESTItem));
    *item = celula->item;
    return Retira(lista, item);
}

#endif