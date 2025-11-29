#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, p;
} Cabo;

int comparar(const void *a, const void *b) {
    Cabo *c1 = (Cabo*)a;
    Cabo *c2 = (Cabo*)b;
    return c1->p - c2->p;
}

int pai[65];

int encontrar(int x) {
    if(pai[x] != x) pai[x] = encontrar(pai[x]);
    return pai[x];
}

void unir(int x, int y) {
    int px = encontrar(x);
    int py = encontrar(y);
    if(px != py) pai[px] = py;
}

int main() {
    int R, C;
    scanf("%d %d", &R, &C);
    Cabo cabos[C];
    for(int i = 0; i < C; i++) {
        scanf("%d %d %d", &cabos[i].u, &cabos[i].v, &cabos[i].p);
    }

    for(int i = 1; i <= R; i++) pai[i] = i;

    qsort(cabos, C, sizeof(Cabo), comparar);

    int custoTotal = 0;
    for(int i = 0; i < C; i++) {
        if(encontrar(cabos[i].u) != encontrar(cabos[i].v)) {
            unir(cabos[i].u, cabos[i].v);
            custoTotal += cabos[i].p;
        }
    }

    printf("%d\n", custoTotal);
    return 0;
}
