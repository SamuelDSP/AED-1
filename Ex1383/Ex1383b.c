#include <stdio.h>

int verifica(int *matriz) {
    int i, j, k;
    int vetor[9];

    for(i = 0; i < 9; i++) {
        for(k = 0; k < 9; k++) vetor[k] = 0;
        for(j = 0; j < 9; j++) {
            int valor = *(matriz + i*9 + j);
            if(valor < 1 || valor > 9 || vetor[valor-1]) return 0;
            vetor[valor-1] = 1;
        }
    }

    for(j = 0; j < 9; j++) {
        for(k = 0; k < 9; k++) vetor[k] = 0;
        for(i = 0; i < 9; i++) {
            int valor = *(matriz + i*9 + j);
            if(valor < 1 || valor > 9 || vetor[valor-1]) return 0;
            vetor[valor-1] = 1;
        }
    }

    for(i = 0; i < 9; i += 3) {
        for(j = 0; j < 9; j += 3) {
            for(k = 0; k < 9; k++) vetor[k] = 0;
            for(int di = 0; di < 3; di++) {
                for(int dj = 0; dj < 3; dj++) {
                    int valor = *(matriz + (i+di)*9 + (j+dj));
                    if(valor < 1 || valor > 9 || vetor[valor-1]) return 0;
                    vetor[valor-1] = 1;
                }
            }
        }
    }

    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    for(int inst = 1; inst <= n; inst++) {
        int matriz[9][9];
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                scanf("%d", &matriz[i][j]);

        printf("Instancia %d\n", inst);
        if(verifica(&matriz[0][0]))
            printf("SIM\n\n");
        else
            printf("NAO\n\n");
    }

    return 0;
}
