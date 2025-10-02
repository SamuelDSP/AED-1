#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char dado;
    struct No *prox;
} No;

void empilhar(No **topo, char valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = *topo;
    *topo = novo;
}

int desempilhar(No **topo) {
    if (*topo == NULL) return 0;
    No *temp = *topo;
    *topo = (*topo)->prox;
    free(temp);
    return 1;
}

void liberar(No **topo) {
    while (*topo != NULL) {
        No *temp = *topo;
        *topo = (*topo)->prox;
        free(temp);
    }
}

int main() {
    char expressao[1001];

    while (scanf("%s", expressao) != EOF) {
        No *pilha = NULL;
        int correto = 1;

        for (int i = 0; expressao[i] != '\0'; i++) {
            if (expressao[i] == '(') {
                empilhar(&pilha, '(');
            } else if (expressao[i] == ')') {
                if (!desempilhar(&pilha)) {
                    correto = 0;
                    break;
                }
            }
        }

        if (correto && pilha == NULL) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }

        liberar(&pilha);
    }

    return 0;
}
