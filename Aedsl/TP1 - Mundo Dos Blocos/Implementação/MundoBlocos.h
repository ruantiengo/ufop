//
// Created by ruant on 04/03/2021.
//

#ifndef TP1_TBLOCOS_H

#include "LinkedList.h"

#define TP1_TBLOCOS_H
/*Structure of the Blocks containing a Pointer pointing to several pointers and an integer n> 0, which represents the number
of lists*/
typedef struct ESTMundoBlocos {
    Lista **listas;
    int nListas;
} TBlocos;

/*the function below receives a variable of type TBlocos and an integer n> 0, it allocates space for the lists
 * inside of the variable mundoBlocos and creates the number of lists and the number of blocks needed*/
void IniciaBlocos(TBlocos *mundoBlocos, int numListas) {
    mundoBlocos->nListas = numListas;
    mundoBlocos->listas = malloc(mundoBlocos->nListas * sizeof(Lista *));
    int cont = 0;
    while (cont != mundoBlocos->nListas) {
        mundoBlocos->listas[cont] = malloc(sizeof(Lista));
        IniciaLista(mundoBlocos->listas[cont]);
        Insere(mundoBlocos->listas[cont], generateItem(cont));
        cont++;
    }
}

/*/ * Receive a variable of type TBlocos and an int value and search for the position of the block in the
 * list array * /*/
TCelula *ProcuraBloco(TBlocos *bloco, int value) {

    for (int i = 0; i < bloco->nListas; i++) {
        TCelula *celula = bloco->listas[i]->primeiro->nextCelula;
        for (int j = 0; j < TamanhoLista(bloco->listas[i]); j++) {
            if (celula->item.numBloco == value) {
                return celula;
            }
            celula = celula->nextCelula;
        }
    }
    return NULL;
}

/*Print the mBlocos (in the left the numbers of lists and in the right the array of lists)*/
void imprimeBloco(TBlocos *mBlocos) {
    for (int i = 0; i < mBlocos->nListas; i++) {
        printf("%d   ", i);
        ImprimeLista(mBlocos->listas[i]);
    }
}

// Receive a variable celula and return the Block number who have this number
int getNumBloco(TCelula *celula) {
    return celula->item.numBloco;
}


/* Receives a variable of type TBloco and an int value and looks for the position of the block in the array of lists */
int BuscaPosListas(TBlocos *mBlocos, TCelula *a) {
    TCelula *aux;
    int cont = 0;
    for (int i = 0; i < mBlocos->nListas; i++) {
        cont = 0;
        aux = mBlocos->listas[i]->primeiro->nextCelula;
        while (aux != NULL) {
            if (aux->item.numBloco == a->item.numBloco) {
                return i;
            }
            cont++;
            aux = aux->nextCelula;
        }
    }
}


/*Receive a variable type TBlocos and a list and make the element passed as a parameter in the function who was called
 * as the last element in the list and return anothers blocks for the original position*/
void TornaUltimo(TBlocos *bloco, Lista *lista) {
    TCelula *aux = lista->primeiro->nextCelula;
    int cont = TamanhoLista(lista);
    while (cont != 0) {
        TCelula *aux2 = lista->ultimo;
        int valor = getNumBloco(lista->ultimo);
        InserirElementoCelula(bloco->listas[valor], aux2);
        RetiraUltimo(lista);
        cont--;
    }
}

/*Move the block on top of block b, returning blocks that are already loaded on
a or b to their original positions.*/
void moveAontoB(TBlocos *mBlocos, TCelula *a, TCelula *b) {

    // Find the list where the block is
    int posA = BuscaPosListas(mBlocos, a);
    int posB = BuscaPosListas(mBlocos, b);


    // check that there are no blocks above, and if so, return those blocks to their original position
    Lista *listaA = mBlocos->listas[posA];
    Lista *listaB = mBlocos->listas[posB];
    if (listaA->ultimo != a) TornaUltimo(mBlocos, listaA);
    if (listaB->ultimo != b) TornaUltimo(mBlocos, listaB);


    // add a element
    InserirElementoCelula(listaB, a);

    // remove the last element
    RetiraElementoCelula(listaA, a);

}
/*Moves block a at the top of the hill where block b is, returning any blocks that
are already over to their original positions*/
void moveAoverB(TBlocos *mBlocos, TCelula *a, TCelula *b) {
    // Find the list where the block is
    int posA = BuscaPosListas(mBlocos, a);
    int posB = BuscaPosListas(mBlocos, b);
    Lista *listaA = mBlocos->listas[posA];
    Lista *listaB = mBlocos->listas[posB];

    // check that there are no blocks above, and if so, return those blocks to their original position
    if (listaA->ultimo != a) TornaUltimo(mBlocos, listaA);

    // add a element
    InserirElementoCelula(listaB, a);
    // remove the last element
    RetiraElementoCelula(listaA, a);

}

/*Stack the list elements from the blockA in listB and remove them from listA*/
void Pile(Lista *listaA, Lista *listaB, TCelula *a) {
    TCelula *aux = listaA->primeiro->nextCelula;
    TCelula *passado = listaA->ultimo;
    while (aux->item.numBloco != a->item.numBloco) {
        aux = aux->nextCelula;
    }
    while (aux != NULL) {
        InserirElementoCelula(listaB, aux);
        aux = aux->nextCelula;
    }
    while (passado->item.numBloco != a->item.numBloco) {
        RetiraUltimo(listaA);
        passado = listaA->ultimo;
    }
    RetiraElementoCelula(listaA, a);
}
/*Moves the block a together with all the blocks that are on it on top of the
block b, returning any blocks that are already on b to their original positions.*/
void pileAontoB(TBlocos *mBlocos, TCelula *a, TCelula *b) {
    int posA = BuscaPosListas(mBlocos, a);
    int posB = BuscaPosListas(mBlocos, b);
    Lista *listaA = mBlocos->listas[posA];
    Lista *listaB = mBlocos->listas[posB];
    if (listaB->ultimo != b) TornaUltimo(mBlocos, listaB);
    Pile(listaA, listaB, a);
}
/*Place block a together with all the blocks that are on it on the mound
that contains block b.*/
void pileAoverB(TBlocos *mBlocos, TCelula *a, TCelula *b) {
    int posA = BuscaPosListas(mBlocos, a);
    int posB = BuscaPosListas(mBlocos, b);
    Lista *listaA = mBlocos->listas[posA];
    Lista *listaB = mBlocos->listas[posB];
    Pile(listaA, listaB, a);
}

/*Drawing*/
void desenhoLogo() {
    printf("\n"
           " _____ ______   ___  ___  ________   ________  ________          \n"
           "|\\   _ \\  _   \\|\\  \\|\\  \\|\\   ___  \\|\\   ___ \\|\\   __  \\         \n"
           "\\ \\  \\\\\\__\\ \\  \\ \\  \\\\\\  \\ \\  \\\\ \\  \\ \\  \\_|\\ \\ \\  \\|\\  \\        \n"
           " \\ \\  \\\\|__| \\  \\ \\  \\\\\\  \\ \\  \\\\ \\  \\ \\  \\ \\\\ \\ \\  \\\\\\  \\       \n"
           "  \\ \\  \\    \\ \\  \\ \\  \\\\\\  \\ \\  \\\\ \\  \\ \\  \\_\\\\ \\ \\  \\\\\\  \\      \n"
           "   \\ \\__\\    \\ \\__\\ \\_______\\ \\__\\\\ \\__\\ \\_______\\ \\_______\\     \n"
           "    \\|__|     \\|__|\\|_______|\\|__| \\|__|\\|_______|\\|_______|     \n"
           "                                                                 \n"
           "                                                                 \n"
           "                                                                 \n"
           "              ________  ________  ________                       \n"
           "             |\\   ___ \\|\\   __  \\|\\   ____\\                      \n"
           "             \\ \\  \\_|\\ \\ \\  \\|\\  \\ \\  \\___|_                     \n"
           "              \\ \\  \\ \\\\ \\ \\  \\\\\\  \\ \\_____  \\                    \n"
           "               \\ \\  \\_\\\\ \\ \\  \\\\\\  \\|____|\\  \\                   \n"
           "                \\ \\_______\\ \\_______\\____\\_\\  \\                  \n"
           "                 \\|_______|\\|_______|\\_________\\                 \n"
           "                                    \\|_________|                 \n"
           "                                                                 \n"
           "                                                                 \n"
           " ________  ___       ________  ________  ________  ________      \n"
           "|\\   __  \\|\\  \\     |\\   __  \\|\\   ____\\|\\   __  \\|\\   ____\\     \n"
           "\\ \\  \\|\\ /\\ \\  \\    \\ \\  \\|\\  \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\___|_    \n"
           " \\ \\   __  \\ \\  \\    \\ \\  \\\\\\  \\ \\  \\    \\ \\  \\\\\\  \\ \\_____  \\   \n"
           "  \\ \\  \\|\\  \\ \\  \\____\\ \\  \\\\\\  \\ \\  \\____\\ \\  \\\\\\  \\|____|\\  \\  \n"
           "   \\ \\_______\\ \\_______\\ \\_______\\ \\_______\\ \\_______\\____\\_\\  \\ \n"
           "    \\|_______|\\|_______|\\|_______|\\|_______|\\|_______|\\_________\\\n"
           "                                                     \\|_________|\n"
           "                                                                 \n"
           "                                                                 ");
}

/* Program */
int Program() {
    desenhoLogo();
    TBlocos *mBlocos = malloc(sizeof(TBlocos));
    int tam;
    printf("\nDigite o numero de listas: \n");
    scanf("%d", &tam);
    while (tam < 2) {
        printf("Valor invalido, digite outro: \n");
        fflush(stdin);
        scanf("%d", &tam);
    }
    IniciaBlocos(mBlocos, tam);
    while (1) {
        imprimeBloco(mBlocos);
        int digito;
        printf("\nDigite o comando a ser feito \n 0- quit \n 1- Move A onto B\n 2- Move A over B\n");
        printf(" 3- Pile A onto B\n 4- Pile A over B\n");
        fflush(stdin);
        scanf("%d", &digito);
        if (digito == 0) {
            free(mBlocos);
            break;
        }
        if (digito == 1) {
            int a;
            int b;
            printf("---------------------------------\n");
            printf("A posição das listas variam de 0 a %d\n", mBlocos->nListas - 1);
            printf("---------------------------------\n");
            printf("Digite o valor do mundoBlocos a: \n");
            fflush(stdin);
            scanf("%d", &a);

            printf("Digite o valor de mundoBlocos b: \n");
            fflush(stdin);
            scanf("%d", &b);
            if (a > mBlocos->nListas - 1 || b > mBlocos->nListas - 1) {
                printf("Numero superior ao numero de listas, tente novamente");
            } else if (mBlocos->nListas == 1) {
                printf("Não ha listas sufiencentes para realizar essa operação, inicie o programa novamente");
            } else if (a == b) {
                printf("A = B, tente novamente");
            } else if (BuscaPosListas(mBlocos, ProcuraBloco(mBlocos, a)) ==
                       BuscaPosListas(mBlocos, ProcuraBloco(mBlocos, b))) {
                printf("Lista igual");
            } else {
                moveAontoB(mBlocos, ProcuraBloco(mBlocos, a), ProcuraBloco(mBlocos, b));
            }
            printf("\n");
        }
        if (digito == 2) {
            int a;
            int b;
            printf("---------------------------------\n");
            printf("A posição das listas variam de 0 a %d\n", mBlocos->nListas - 1);
            printf("---------------------------------\n");
            printf("Digite o valor do a: \n");
            fflush(stdin);
            scanf("%d", &a);

            printf("Digite o valor de b: \n");
            fflush(stdin);
            scanf("%d", &b);
            if (a > mBlocos->nListas - 1 || b > mBlocos->nListas - 1) {
                printf("Numero superior ao numero de listas, tente novamente");
            } else if (mBlocos->nListas == 1) {
                printf("Não ha listas sufiencentes para realizar essa operação, inicie o programa novamente");
            } else if (a == b) {
                printf("A = B, tente novamente");
            } else if (BuscaPosListas(mBlocos, ProcuraBloco(mBlocos, a)) ==
                       BuscaPosListas(mBlocos, ProcuraBloco(mBlocos, b))) {
                printf("Lista igual");
            } else
                moveAoverB(mBlocos, ProcuraBloco(mBlocos, a), ProcuraBloco(mBlocos, b));
            printf("\n");
        }
        if (digito == 3) {
            int a;
            int b;
            printf("---------------------------------\n");
            printf("A posição das listas variam de 0 a %d\n", mBlocos->nListas - 1);
            printf("---------------------------------\n");
            printf("Digite o valor do a: \n");
            fflush(stdin);
            scanf("%d", &a);

            printf("Digite o valor de b: \n");
            fflush(stdin);
            scanf("%d", &b);
            if (a > mBlocos->nListas - 1 || b > mBlocos->nListas - 1) {
                printf("Numero superior ao numero de listas, tente novamente");
            } else if (mBlocos->nListas == 1) {
                printf("Não ha listas sufiencentes para realizar essa operação, inicie o programa novamente");
            } else if (a == b) {
                printf("A = B, tente novamente");
            } else if (BuscaPosListas(mBlocos, ProcuraBloco(mBlocos, a)) ==
                       BuscaPosListas(mBlocos, ProcuraBloco(mBlocos, b))) {
                printf("Lista igual");
            } else
                pileAontoB(mBlocos, ProcuraBloco(mBlocos, a), ProcuraBloco(mBlocos, b));
            printf("\n");
        }
        if (digito == 4) {
            int a;
            int b;
            printf("---------------------------------\n");
            printf("A posição das listas variam de 0 a %d\n", mBlocos->nListas - 1);
            printf("---------------------------------\n");
            printf("Digite o valor do a: \n");
            fflush(stdin);
            scanf("%d", &a);

            printf("Digite o valor de b: \n");
            fflush(stdin);
            scanf("%d", &b);
            if (a > mBlocos->nListas - 1 || b > mBlocos->nListas - 1) {
                printf("Numero superior ao numero de listas, tente novamente");
            } else if (mBlocos->nListas == 1) {
                printf("Não ha listas sufiencentes para realizar essa operação, inicie o programa novamente");
            } else if (a == b) {
                printf("A = B, tente novamente");
            } else if (BuscaPosListas(mBlocos, ProcuraBloco(mBlocos, a)) ==
                       BuscaPosListas(mBlocos, ProcuraBloco(mBlocos, b))) {
                printf("Lista igual");
            } else
                pileAoverB(mBlocos, ProcuraBloco(mBlocos, a), ProcuraBloco(mBlocos, b));
            printf("\n");
        }
    }
}

#endif //TP1_TBLOCOS_H