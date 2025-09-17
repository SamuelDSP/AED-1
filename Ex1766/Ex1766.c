#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[101];
    int peso;
    int idade;
    float altura;
} Rena;

int comparar(const void *a, const void *b) {
    Rena *rena1 = (Rena *)a;
    Rena *rena2 = (Rena *)b;

    if (rena1->peso != rena2->peso) 
        return rena2->peso - rena1->peso;
    if (rena1->idade != rena2->idade) 
        return rena1->idade - rena2->idade;
    if (rena1->altura != rena2->altura) 
        return (rena1->altura > rena2->altura) ? 1 : -1;
    return strcmp(rena1->nome, rena2->nome);
}

int main() {
    int T, N, M;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        scanf("%d %d", &N, &M);

        Rena renas[N];
        for (int j = 0; j < N; j++) {
            scanf("%s %d %d %f", renas[j].nome, &renas[j].peso, &renas[j].idade, &renas[j].altura);
        }

        qsort(renas, N, sizeof(Rena), comparar);

        printf("CENARIO {%d}\n", i);
        for (int j = 0; j < M; j++) {
            printf("%d - %s\n", j + 1, renas[j].nome);
        }
    }

    return 0;
}
