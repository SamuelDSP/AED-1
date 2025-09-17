#include <stdio.h>
#include <string.h>

typedef struct fila {
    int frente;
    int tras;
    char elementos[101];
} fila;

void inicializar_fila(fila *f) {
    f->frente = 0;
    f->tras = 0;
}

int esta_vazia(fila *f) {
    return f->frente == f->tras;
}

void enfileirar(fila *f, char c) {
    f->elementos[f->tras] = c;
    f->tras++;
}

char desenfileirar(fila *f) {
    char c = f->elementos[f->frente];
    f->frente++;
    return c;
}

int e_subsequencia(char *s, char *r) {
    fila fila_r;
    inicializar_fila(&fila_r);

    for (int i = 0; r[i] != '\0'; i++) {
        enfileirar(&fila_r, r[i]);
    }

    for (int i = 0; s[i] != '\0'; i++) {
        if (!esta_vazia(&fila_r) && s[i] == fila_r.elementos[fila_r.frente]) {
            desenfileirar(&fila_r);
        }
    }

    return esta_vazia(&fila_r);
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char s[100001];
        scanf("%s", s);

        int q;
        scanf("%d", &q);

        while (q--) {
            char r[101];
            scanf("%s", r);

            if (e_subsequencia(s, r)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }

    return 0;
}
