#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, menor, posicao;
    int *x;

    scanf("%d", &n);

    x = (int*) malloc(n * sizeof(int));

    for(i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    menor = x[0];
    posicao = 0;

    for(i = 1; i < n; i++) {
        if(x[i] < menor) {
            menor = x[i];
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    free(x);
    return 0;
}
