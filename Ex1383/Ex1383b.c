#include <stdio.h>
#include <stdlib.h>

int verifica_linha(int **matriz, int linha) {
    int visto[10] = {0};
    for (int j = 0; j < 9; j++) {
        int num = matriz[linha][j];
        if (num < 1 || num > 9 || visto[num]) return 0;
        visto[num] = 1;
    }
    return 1;
}

int verifica_coluna(int **matriz, int coluna) {
    int visto[10] = {0};
    for (int i = 0; i < 9; i++) {
        int num = matriz[i][coluna];
        if (num < 1 || num > 9 || visto[num]) return 0;
        visto[num] = 1;
    }
    return 1;
}

int verifica_submatriz(int **matriz, int linha, int coluna) {
    int visto[10] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num = matriz[linha + i][coluna + j];
            if (num < 1 || num > 9 || visto[num]) return 0;
            visto[num] = 1;
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int instancia = 1; instancia <= n; instancia++) {
        int **matriz = (int **)malloc(9 * sizeof(int *));
        for (int i = 0; i < 9; i++) {
            matriz[i] = (int *)malloc(9 * sizeof(int));
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        int valido = 1;

        // Verifica linhas
        for (int i = 0; i < 9 && valido; i++) {
            if (!verifica_linha(matriz, i)) valido = 0;
        }

        // Verifica colunas
        for (int j = 0; j < 9 && valido; j++) {
            if (!verifica_coluna(matriz, j)) valido = 0;
        }

        // Verifica submatrizes 3x3
        for (int i = 0; i < 9 && valido; i += 3) {
            for (int j = 0; j < 9 && valido; j += 3) {
                if (!verifica_submatriz(matriz, i, j)) valido = 0;
            }
        }

        printf("Instancia %d\n", instancia);
        if (valido) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }

        for (int i = 0; i < 9; i++) {
            free(matriz[i]);
        }
        free(matriz);
    }

    return 0;
}
