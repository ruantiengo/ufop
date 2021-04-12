//
// Created by ruant on 11/04/2021.
//

#ifndef UNTITLED_TREE_H
#define UNTITLED_TREE_H

#include <stdio.h>
#include "stdlib.h"
#include "string.h"

typedef struct Est_Pessoa {
    char nome[50];
    long long int cpf;
    char profissao[30];
} Pessoa;

typedef struct Est_Node {
    struct Est_Node *esq;
    struct Est_Node *dir;
    Pessoa *pessoa;
} Node;

// Recebe uma pessoa e retorna um novo no contendo essa pessoa
Node *new_no(Pessoa *p) {
    Node *novo = malloc(sizeof(Node));
    novo->pessoa = p;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Recebe uma estrutura pessoa e retorna um ponteiro apontando para essa pessoa.
Pessoa *new_pessoa(Pessoa pessoa) {
    Pessoa *aux = malloc(sizeof(Pessoa));
    strcpy(aux->nome, pessoa.nome);
    strcpy(aux->profissao, pessoa.profissao);
    aux->cpf = pessoa.cpf;
    return aux;
}

// Recebe a arvore e o ponteiro de pessoa a ser inserido, verifica se não há pessoas já inseridas com o mesmo nome ou cpf.
// Organiza do menor para o maior CPF.
int insertByCpf(Node **ppRoot, Pessoa *pessoa) {
    if (*ppRoot == NULL) {
        *ppRoot = new_no(pessoa);
        return 1;
    }
    if (pessoa->cpf < (*ppRoot)->pessoa->cpf && strcmp(pessoa->nome, (*ppRoot)->pessoa->nome)) {
        insertByCpf(&((*ppRoot)->esq), pessoa);
    }

    if (pessoa->cpf > (*ppRoot)->pessoa->cpf && strcmp(pessoa->nome, (*ppRoot)->pessoa->nome)) {
        insertByCpf(&((*ppRoot)->dir), pessoa);
    }
    return 0;

}

// Recebe a arvore e o ponteiro de pessoa a ser inserido, verifica se não há pessoas já inseridas com o mesmo nome ou cpf.
// Organiza pela ordem alfabetica.
int insertByNome(Node **ppRoot, Pessoa *pessoa) {
    if (*ppRoot == NULL) {
        *ppRoot = new_no(pessoa);
        return 1;
    }
    if (strcmp(pessoa->nome, (*ppRoot)->pessoa->nome) > 0) insertByNome(&((*ppRoot)->dir), pessoa);
    if (strcmp(pessoa->nome, (*ppRoot)->pessoa->nome) < 0) insertByNome(&((*ppRoot)->esq), pessoa);
    return 0;
}

// Passa o elemento que sucedera o elemento que foi eliminado.
void sucessor(Node **arvore, Node *no) {
    Node *aux;
    if ((*arvore)->esq != NULL) {
        sucessor(&(*arvore)->esq, no);
        return;
    }
    no->pessoa->cpf = (*arvore)->pessoa->cpf;
    strcpy(no->pessoa->nome, (*arvore)->pessoa->nome);
    strcpy(no->pessoa->profissao, (*arvore)->pessoa->profissao);
    aux = (*arvore);
    *arvore = (*arvore)->dir;
    free(aux);
}

// Recebe a arvore e a pessoa, e a função é incubida de deletar aquela pessoa.
int removeByName(Node **root, Pessoa *pessoa) {
    Node *aux;

    if (*root == NULL) return 0;
    if (strcmp(pessoa->nome, (*root)->pessoa->nome) > 0) return removeByName(&(*root)->esq, pessoa);
    if (strcmp(pessoa->nome, (*root)->pessoa->nome) < 0) return removeByName(&(*root)->dir, pessoa);
    if (strcmp(pessoa->nome, (*root)->pessoa->nome) == 0) {
        if ((*root)->dir == NULL) {
            aux = *root;
            *root = (*root)->esq;
            free(aux);
            return 1;
        }
        if ((*root)->esq = NULL) {
            aux = *root;
            *root = (*root)->dir;
            free(aux);
            return 1;
        }

        sucessor(&(*root)->dir, *root);
        return 1;
    }
}

// Recebe a arvore e a pessoa, e a função é incubida de deletar aquela pessoa.
int removeByCpf(Node **root,Pessoa *pessoa){
    Node *aux;

    if(*root == NULL)
        return 0;

    if(pessoa->cpf < (*root)->pessoa->cpf) return removeByCpf(&(*root)->esq,pessoa);
    if(pessoa->cpf > (*root)->pessoa->cpf) return removeByCpf(&(*root)->dir,pessoa);
    if(pessoa->cpf == (*root)->pessoa->cpf){
        if((*root)->dir == NULL){
            aux = *root;
            *root = (*root)->esq;
            free(aux);
            return 1;
        }
        if((*root)->esq = NULL){
            aux = *root;
            *root = (*root)->dir;
            free(aux);
            return 1;
        }

        sucessor(&(*root)->dir,*root);
        return 1;
    }
}
// Recebe uma raiz e um cpf e retorna a pessoa que tem aquele CPF.
Pessoa *buscaByCpf(Node *pRaiz, long long int cpfDigitado) {
    Pessoa *aux;
    if (pRaiz == NULL) return 0;
    if (cpfDigitado < pRaiz->pessoa->cpf) return buscaByCpf(pRaiz->esq, cpfDigitado);
    if (cpfDigitado > pRaiz->pessoa->cpf) return buscaByCpf(pRaiz->dir, cpfDigitado);
    if (cpfDigitado == pRaiz->pessoa->cpf) {
        aux = pRaiz->pessoa;
        return aux;
    }
}

// Recebe uma raiz e um nome e retorna a pessoa que tem aquele nome,
Pessoa *buscaByName(Node *pRaiz, char nomeDigitado[]) {
    Pessoa *aux;
    if (pRaiz == NULL) return 0;
    if (strcmp(nomeDigitado, pRaiz->pessoa->nome) > 0) return buscaByName(pRaiz->esq, nomeDigitado);
    if (strcmp(nomeDigitado, pRaiz->pessoa->nome) < 0) return buscaByName(pRaiz->dir, nomeDigitado);
    if (strcmp(nomeDigitado, pRaiz->pessoa->nome) == 0) {
        aux = pRaiz->pessoa;
        return aux;
    }
}

// Limpa a arvore passada como parametro
int removeAll(Node *root) {
    if (root != NULL) {
        removeAll(root->esq);
        removeAll(root->dir);
        free(root);
    }
}

// Imprime os funcionarios ordenados.
void central(Node *pRaiz) {
    if (pRaiz != NULL) {
        central(pRaiz->esq);
        printf("-------------------\n");
        printf("Nome: %s\n", pRaiz->pessoa->nome);
        printf("Cpf: %lld\n", pRaiz->pessoa->cpf);
        printf("Profissao: %s\n\n", pRaiz->pessoa->profissao);
        central(pRaiz->dir);
    }
}

int NomeIsInTree(Node *root, char name[]){
    while(root != NULL){
        if(strcmp(root->pessoa->nome,name) == 0) return 1;
        NomeIsInTree(root->esq,name);
        NomeIsInTree(root->dir,name);
        return 0;
    }
}

int CpfIsInTree(Node *root, long long int cpf){
    while(root != NULL){
        if(root->pessoa->cpf == cpf) return 1;
        CpfIsInTree(root->esq,cpf);
        CpfIsInTree(root->dir,cpf);
        return 0;
    }
}

#endif //UNTITLED_TREE_H
