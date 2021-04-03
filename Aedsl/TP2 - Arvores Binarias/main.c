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

Node *new_no(Pessoa *p) {
    Node *novo = malloc(sizeof(Node));
    novo->pessoa = p;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}
Pessoa *new_pessoa(Pessoa pessoa){
    Pessoa *aux = malloc(sizeof(Pessoa));
    strcpy(aux->nome,pessoa.nome);
    strcpy(aux->profissao,pessoa.profissao);
    aux->cpf = pessoa.cpf;
    return aux;
}

int insertByCpf(Node **ppRoot, Pessoa *pessoa) {
    if (*ppRoot == NULL) {
        *ppRoot = new_no(pessoa);
        return 1;
    }
    if (pessoa->cpf < (*ppRoot)->pessoa->cpf && strcmp(pessoa->nome, (*ppRoot)->pessoa->nome)) {
        insertByCpf(&((*ppRoot)->dir), pessoa);
    }

    if (pessoa->cpf > (*ppRoot)->pessoa->cpf && strcmp(pessoa->nome, (*ppRoot)->pessoa->nome)) {
        insertByCpf(&((*ppRoot)->esq), pessoa);
    }
    return 0;

}

int insertByNome(Node **ppRoot, Pessoa* pessoa){
    if (*ppRoot == NULL) {
        *ppRoot = new_no(pessoa);
        return 1;
    }
    if (strcmp(pessoa->nome,(*ppRoot)->pessoa->nome) > 0) insertByNome(&((*ppRoot)->dir), pessoa);
    if (strcmp(pessoa->nome,(*ppRoot)->pessoa->nome) < 0) insertByNome(&((*ppRoot)->dir), pessoa);
}

void central(Node *pRaiz) {
    if (pRaiz != NULL) {
        central(pRaiz->dir);
        printf("-------------------\n");
        printf("Nome: %s\n", pRaiz->pessoa->nome);
        printf("Cpf: %lld\n", pRaiz->pessoa->cpf);
        printf("Profissao: %s\n", pRaiz->pessoa->profissao);
        central(pRaiz->esq);
    }
}


int main() {
    Node *rootCPF = NULL;
    Node *rootNome = NULL;
    int num;
    while (1) {
        /*Menu tarefas*/
        printf("Digite a tarefa desejada: \n");
        printf("1- Cadastrar funcionaro. \n");
        printf("4- Exibir funcionarios ordenados pelo nome. \n");
        fflush(stdin);
        scanf("%d", &num);

        switch (num) {
            case 1:
                printf("Nome:\n");
                Pessoa pessoa;
                fflush(stdin);
                gets(pessoa.nome);
                printf("CPF:\n");
                fflush(stdin);
                scanf("%lld", &pessoa.cpf);
                printf("Profissao:\n");
                fflush(stdin);
                gets(pessoa.profissao);
                insertByCpf(&rootCPF,new_pessoa(pessoa));
                insertByNome(&rootNome,new_pessoa(pessoa));
                break;
            case 4:
                central(rootNome);
            case 8:
                break;
        }
        if (num == 5) break;
    }
    return 0;
}
