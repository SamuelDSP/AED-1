#include <stdio.h>

int main() {
    int N;
    int X[1000];
    int *p;              
    int *menor;          
    int posicao = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }
    menor = &X[0];
    for (p = X; p < X + N; p++) {
        if (*p < *menor) {
            menor = p;
        }
    }

    posicao = menor - X;
    printf("Menor valor: %d\n", *menor);
    printf("Posicao: %d\n", posicao);

    return 0;
}
