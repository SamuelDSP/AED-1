#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char valor;
    struct no *esq;
    struct no *dir;
} No;

No* criar(char v) {
    No* n = (No*)malloc(sizeof(No));
    n->valor = v;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

No* inserir(No* raiz, char v) {
    if (raiz == NULL) return criar(v);
    if (v < raiz->valor) raiz->esq = inserir(raiz->esq, v);
    else if (v > raiz->valor) raiz->dir = inserir(raiz->dir, v);
    return raiz;
}

int buscar(No* raiz, char v) {
    if (raiz == NULL) return 0;
    if (v == raiz->valor) return 1;
    if (v < raiz->valor) return buscar(raiz->esq, v);
    return buscar(raiz->dir, v);
}

void infixa(No* r, int *primeiro) {
    if (r == NULL) return;
    infixa(r->esq, primeiro);
    if (*primeiro == 0) printf(" ");
    printf("%c", r->valor);
    *primeiro = 0;
    infixa(r->dir, primeiro);
}

void prefixa(No* r, int *primeiro) {
    if (r == NULL) return;
    if (*primeiro == 0) printf(" ");
    printf("%c", r->valor);
    *primeiro = 0;
    prefixa(r->esq, primeiro);
    prefixa(r->dir, primeiro);
}

void posfixa(No* r, int *primeiro) {
    if (r == NULL) return;
    posfixa(r->esq, primeiro);
    posfixa(r->dir, primeiro);
    if (*primeiro == 0) printf(" ");
    printf("%c", r->valor);
    *primeiro = 0;
}

int main() {
    No* raiz = NULL;
    char comando[20];
    char v;

    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &v);
            raiz = inserir(raiz, v);
        } else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &v);
            if (buscar(raiz, v)) printf("%c existe\n", v);
            else printf("%c nao existe\n", v);
        } else if (strcmp(comando, "INFIXA") == 0) {
            int primeiro = 1;
            infixa(raiz, &primeiro);
            printf("\n");
        } else if (strcmp(comando, "PREFIXA") == 0) {
            int primeiro = 1;
            prefixa(raiz, &primeiro);
            printf("\n");
        } else if (strcmp(comando, "POSFIXA") == 0) {
            int primeiro = 1;
            posfixa(raiz, &primeiro);
            printf("\n");
        }
    }

    return 0;
}
