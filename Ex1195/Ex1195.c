#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int v;
    struct no *e;
    struct no *d;
} No;

No* inserir(No *r, int v) {
    if (r == NULL) {
        r = (No*)malloc(sizeof(No));
        r->v = v;
        r->e = NULL;
        r->d = NULL;
    } else {
        if (v < r->v) r->e = inserir(r->e, v);
        else r->d = inserir(r->d, v);
    }
    return r;
}

void prefixo(No *r) {
    if (r == NULL) return;
    printf("%d", r->v);
    if (r->e != NULL) {
        printf(" ");
        prefixo(r->e);
    }
    if (r->d != NULL) {
        printf(" ");
        prefixo(r->d);
    }
}

void infixo(No *r) {
    if (r == NULL) return;
    if (r->e != NULL) {
        infixo(r->e);
        printf(" ");
    }
    printf("%d", r->v);
    if (r->d != NULL) {
        printf(" ");
        infixo(r->d);
    }
}

void posfixo(No *r) {
    if (r == NULL) return;
    if (r->e != NULL) {
        posfixo(r->e);
        printf(" ");
    }
    if (r->d != NULL) {
        posfixo(r->d);
        printf(" ");
    }
    printf("%d", r->v);
}

void liberar(No *r) {
    if (r == NULL) return;
    liberar(r->e);
    liberar(r->d);
    free(r);
}

int main() {
    int C, N, v, i, caso = 1;
    scanf("%d", &C);

    while (C--) {
        scanf("%d", &N);
        No *r = NULL;

        for (i = 0; i < N; i++) {
            scanf("%d", &v);
            r = inserir(r, v);
        }

        printf("Case %d:\n", caso++);
        printf("Pre.: ");
        prefixo(r);
        printf("\n");

        printf("In..: ");
        infixo(r);
        printf("\n");

        printf("Post: ");
        posfixo(r);
        printf("\n\n");

        liberar(r);
    }

    return 0;
}
