#include <stdio.h>
#include "stdlib.h"
#include "Tree.h"

int main() {
    Node *rootCPF = NULL;
    Node *rootNome = NULL;
    int num;


    while (1) {
        /*Menu tarefas*/
        printf("Digite a tarefa desejada: \n");
        printf("1- Cadastrar funcionaro. \n");
        printf("2- Excluir funcionario pelo nome. \n");
        printf("3- Excluir funcionario pelo CPF.\n");
        printf("4- Buscar funcionario pelo nome. \n");
        printf("5- Buscar funcionario pelo CPF. \n");
        printf("6- Exibir funcionarios ordenados pelo nome. \n");
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
                if (pessoa.cpf < 10000000000 || pessoa.cpf > 99999999999) printf("Cpf invalido, cadastre novamente\n");
                else if (NomeIsInTree(rootNome, pessoa.nome) == 1) printf("Um usuario com esse nome já existe.\n");
                else if (CpfIsInTree(rootCPF, pessoa.cpf) == 1) printf("Um usuario com esse cpf já existe.\n");
                else {
                    insertByCpf(&rootCPF, new_pessoa(pessoa));
                    insertByNome(&rootNome, new_pessoa(pessoa));
                }
                break;
            case 2:
                printf("Digite o nome a ser removido:\n");
                char nomeRemovido[50];
                fflush(stdin);
                gets(nomeRemovido);
                if (NomeIsInTree(rootNome, nomeRemovido) == 0) printf("Essa pessoa nao esta cadastrada.\n");
                else {
                    removeByName(&rootCPF, buscaByName(rootCPF, nomeRemovido));
                    removeByName(&rootNome, buscaByName(rootNome, nomeRemovido));
                }
                break;
            case 3:
                printf("Digite o CPF a ser removido:\n");
                long long int cpfRemovido;
                fflush(stdin);
                scanf("%lld", &cpfRemovido);
                if (CpfIsInTree(rootCPF, cpfRemovido) == 0) printf("Essa pessoa nao esta cadastrada.\n");
                else {
                    removeByCpf(&rootNome, buscaByCpf(rootCPF, cpfRemovido));
                    removeByCpf(&rootCPF, buscaByCpf(rootCPF, cpfRemovido));
                }
                break;
            case 4:
                printf("Digite o nome a ser buscado:\n");
                char nomeBuscado[50];
                fflush(stdin);
                gets(nomeBuscado);
                if (NomeIsInTree(rootNome, nomeRemovido) == 0) printf("Essa pessoa nao esta cadastrada.\n");
                else {
                    Pessoa pessoa2 = *(buscaByName(rootNome, nomeBuscado));
                    printf("Nome:  %s\n", pessoa2.nome);
                    printf("Cpf:  %lld\n", pessoa2.cpf);
                    printf("Profissao:  %s\n", pessoa2.profissao);
                }
                break;

            case 5:
                printf("Digite o CPF a ser buscado:\n");
                long long int cpfBuscado;
                fflush(stdin);
                scanf("%lld", &cpfBuscado);
                if (CpfIsInTree(rootCPF, cpfRemovido) == 0) printf("Essa pessoa nao esta cadastrada.\n");
                else {
                    Pessoa pessoa1 = *(buscaByCpf(rootCPF, cpfBuscado));
                    printf("Nome:  %s\n", pessoa1.nome);
                    printf("Cpf:  %lld\n", pessoa1.cpf);
                    printf("Profissao:  %s\n", pessoa1.profissao);
                }
                break;

            case 6:
                if (rootNome == NULL) printf("Arvore Vazia\n");
                else central(rootNome);
                break;
            case 7:
                removeAll(rootNome);
                removeAll(rootCPF);
                rootNome = NULL;
                rootCPF = NULL;
                printf("\nArvores limpas.\n");
                break;
            case 8:
                removeAll(rootNome);
                removeAll(rootCPF);
                break;
        }
        if (num == 8) break;
    }

    return 0;
}