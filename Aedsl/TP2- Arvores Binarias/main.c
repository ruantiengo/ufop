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

Pessoa *new_pessoa(Pessoa pessoa) {
    Pessoa *aux = malloc(sizeof(Pessoa));
    strcpy(aux->nome, pessoa.nome);
    strcpy(aux->profissao, pessoa.profissao);
    aux->cpf = pessoa.cpf;
    return aux;
}

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

int insertByNome(Node **ppRoot, Pessoa *pessoa) {
    if (*ppRoot == NULL) {
        *ppRoot = new_no(pessoa);
        return 1;
    }
    if (strcmp(pessoa->nome, (*ppRoot)->pessoa->nome) > 0) insertByNome(&((*ppRoot)->dir), pessoa);
    if (strcmp(pessoa->nome, (*ppRoot)->pessoa->nome) < 0) insertByNome(&((*ppRoot)->esq), pessoa);
    return 0;
}

// Recebe uma raiz e um cpf e retorna a pessoa que tem aquele CPF
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

int removeAll(Node *root) {
    if (root != NULL) {
        removeAll(root->esq);
        removeAll(root->dir);
        free(root);
    }

}

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
int isInTree(Node *root,char nome[]){
    if (root != NULL){
        if(strcmp(nome,root->pessoa->nome) == 0) return 1;
        else isInTree(root->esq,nome);
    }
    if (root != NULL){
        if(strcmp(nome,root->pessoa->nome) == 0) return 1;
        else isInTree(root->dir,nome);
    }
    return 0;
}

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


int removeByCpf(Node **root, Pessoa *pessoa) {
    Node *aux;

    if (*root == NULL)
        return 0;

    if (pessoa->cpf < (*root)->pessoa->cpf) return removeByCpf(&(*root)->esq, pessoa);
    if (pessoa->cpf > (*root)->pessoa->cpf) return removeByCpf(&(*root)->dir, pessoa);
    if (pessoa->cpf == (*root)->pessoa->cpf) {
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

int main() {
    Node *rootCPF = NULL;
    Node *rootNome = NULL;
    int num;


    Pessoa pessoa;
    strcpy(pessoa.nome, "Ruan");
    pessoa.cpf = 1;
    strcpy(pessoa.profissao, "Pedreiro");
    insertByCpf(&rootCPF, new_pessoa(pessoa));
    insertByNome(&rootNome, new_pessoa(pessoa));

    Pessoa *pessoa2 = malloc(sizeof(Pessoa));
    strcpy(pessoa2->nome, "Pedro");
    pessoa2->cpf = 4;
    strcpy(pessoa2->profissao, "Medico");
    insertByCpf(&rootCPF, pessoa2);
    insertByNome(&rootNome, pessoa2);

    Pessoa *pessoa3 = malloc(sizeof(Pessoa));
    strcpy(pessoa3->nome, "Alex");
    pessoa3->cpf = 3;
    strcpy(pessoa3->profissao, "Medico");
    insertByCpf(&rootCPF, pessoa3);
    insertByNome(&rootNome, pessoa3);

    Pessoa *pessoa4 = malloc(sizeof(Pessoa));
    strcpy(pessoa4->nome, "Josue");
    pessoa4->cpf = 2;
    strcpy(pessoa4->profissao, "Medico");
    insertByCpf(&rootCPF, pessoa4);
    insertByNome(&rootNome, pessoa4);



    while (1) {
        /*Menu tarefas*/
        printf("Digite a tarefa desejada: \n");
        printf("1- Cadastrar funcionaro. \n");
        printf("2- Excluir funcionario pelo nome. \n");
        printf("3- Excluir funcionario pelo CPF.\n");
        printf("4- Buscar funcionario pelo nome. \n");
        printf("5- Buscar funcionario pelo CPF. \n");
        printf("6- Exibir funcionarios ordenados pelo CPF. \n");
        printf("7- Excluir todos os funcionarios. \n");
        printf("8- Sair. \n");
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
                insertByCpf(&rootCPF, new_pessoa(pessoa));
                insertByNome(&rootNome, new_pessoa(pessoa));
                break;
            case 2:
                printf("Digite o nome a ser removido:\n");
                char nomeRemovido[50];
                fflush(stdin);
                gets(nomeRemovido);
                removeByName(&rootCPF, buscaByName(rootNome, nomeRemovido));
                removeByName(&rootNome, buscaByName(rootNome, nomeRemovido));
                break;
            case 3:
                printf("Digite o CPF a ser removido:\n");
                long long int cpfRemovido;
                fflush(stdin);
                scanf("%lld", &cpfRemovido);
                removeByCpf(&rootCPF, buscaByCpf(rootCPF, cpfRemovido));
                removeByCpf(&rootNome, buscaByCpf(rootCPF, cpfRemovido));
                break;
            case 4:
                printf("Digite o nome a ser buscado:\n");
                char nomeBuscado[50];
                fflush(stdin);
                gets(nomeBuscado);
                Pessoa pessoa2 = *(buscaByName(rootCPF, nomeBuscado));
                printf("Nome:  %s\n", pessoa2.nome);
                printf("Cpf:  %lld\n", pessoa2.cpf);
                printf("Profissao:  %s\n", pessoa2.profissao);
                break;

            case 5:
                printf("Digite o CPF a ser buscado:\n");
                long long int cpfBuscado;
                fflush(stdin);
                scanf("%lld", &cpfBuscado);
                Pessoa pessoa1 = *(buscaByCpf(rootCPF, cpfBuscado));
                printf("Nome:  %s\n", pessoa1.nome);
                printf("Cpf:  %lld\n", pessoa1.cpf);
                printf("Profissao:  %s\n", pessoa1.profissao);

                break;

            case 6:
                central(rootNome);
                break;
            case 7:
                removeAll(rootNome);
                removeAll(rootCPF);
                break;
            case 8:
                break;
            case 9:
                printf("Digite o nome a ser buscado:\n");
                char nomePesquisado[50];
                fflush(stdin);
                gets(nomePesquisado);
                if(isInTree(rootNome,nomeBuscado) == 1) printf("Esta");
                else printf("Nao esta\n");
                break;
        }
        if (num == 8) break;
    }
    return 0;
}