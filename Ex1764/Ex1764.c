#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cidade1, cidade2;
    int distancia;
} Rota;

int comparar(const void *a, const void *b) {
    Rota *ra = (Rota*)a;
    Rota *rb = (Rota*)b;
    return ra->distancia - rb->distancia;
}

int pai[40000];
int tamanho[40000];

int achar(int x) {
    if(pai[x] != x) pai[x] = achar(pai[x]);
    return pai[x];
}

int unir(int x, int y) {
    x = achar(x);
    y = achar(y);
    if(x == y) return 0;
    if(tamanho[x] < tamanho[y]) {
        pai[x] = y;
        tamanho[y] += tamanho[x];
    } else {
        pai[y] = x;
        tamanho[x] += tamanho[y];
    }
    return 1;
}

int main() {
    while(1) {
        int M, N;
        scanf("%d %d", &M, &N);
        if(M == 0 && N == 0) break;

        Rota rotas[N];
        for(int i = 0; i < N; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            rotas[i].cidade1 = x;
            rotas[i].cidade2 = y;
            rotas[i].distancia = z;
        }

        for(int i = 0; i < M; i++) {
            pai[i] = i;
            tamanho[i] = 1;
        }

        qsort(rotas, N, sizeof(Rota), comparar);

        long long somaMST = 0;
        for(int i = 0; i < N; i++) {
            if(unir(rotas[i].cidade1, rotas[i].cidade2))
                somaMST += rotas[i].distancia;
        }

        printf("%lld\n", somaMST);
    }
    return 0;
}
