#include <stdio.h>
#include <stdlib.h>

typedef struct trem {
    int *vagoes;
    int tamanho;
} trem;

int contar_trocas(trem *t) {
    int trocas = 0;
    for (int i = 0; i < t->tamanho - 1; i++) {
        for (int j = 0; j < t->tamanho - i - 1; j++) {
            if (t->vagoes[j] > t->vagoes[j + 1]) {
                int temp = t->vagoes[j];
                t->vagoes[j] = t->vagoes[j + 1];
                t->vagoes[j + 1] = temp;
                trocas++;
            }
        }
    }
    return trocas;
}

int main() {
    int casos_teste;
    scanf("%d", &casos_teste);

    while (casos_teste--) {
        trem t;
        scanf("%d", &t.tamanho);

        t.vagoes = (int *)malloc(t.tamanho * sizeof(int));
        for (int i = 0; i < t.tamanho; i++) {
            scanf("%d", &t.vagoes[i]);
        }

        int trocas = contar_trocas(&t);
        printf("Optimal train swapping takes %d swaps.\n", trocas);

        free(t.vagoes);
    }

    return 0;
}
