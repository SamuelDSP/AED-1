#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v;
    int peso;
} Estrada;

int cmp(const void *a, const void *b) {
    Estrada *ea = (Estrada*)a;
    Estrada *eb = (Estrada*)b;
    return ea->peso - eb->peso;
}

int pai[200001];
int tamanho[200001];

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
        int m, n;
        scanf("%d %d", &m, &n);
        if(m == 0 && n == 0) break;

        Estrada estradas[n];
        long long somaTotal = 0;
        for(int i = 0; i < n; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            estradas[i].u = x;
            estradas[i].v = y;
            estradas[i].peso = z;
            somaTotal += z;
        }

        for(int i = 0; i < m; i++) {
            pai[i] = i;
            tamanho[i] = 1;
        }

        qsort(estradas, n, sizeof(Estrada), cmp);

        long long custoMST = 0;
        for(int i = 0; i < n; i++) {
            if(unir(estradas[i].u, estradas[i].v))
                custoMST += estradas[i].peso;
        }

        printf("%lld\n", somaTotal - custoMST);
    }
    return 0;
}
