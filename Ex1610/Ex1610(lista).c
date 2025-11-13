#include <stdio.h>

#define MAXN 10004
#define MAXM 30004

int head[MAXN], to[MAXM], next[MAXM];
int estado[MAXN];
int aresta;
int tem_ciclo;

void adicionar_aresta(int u, int v) {
    to[aresta] = v;
    next[aresta] = head[u];
    head[u] = aresta++;
}

void dfs(int u) {
    if (tem_ciclo) return;
    estado[u] = 1;
    for (int i = head[u]; i != -1; i = next[i]) {
        int v = to[i];
        if (estado[v] == 0) dfs(v);
        else if (estado[v] == 1) {
            tem_ciclo = 1;
            return;
        }
    }
    estado[u] = 2;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        for (int i = 1; i <= N; i++) {
            head[i] = -1;
            estado[i] = 0;
        }
        aresta = 0;

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            adicionar_aresta(A, B);
        }

        tem_ciclo = 0;
        for (int i = 1; i <= N && !tem_ciclo; i++) {
            if (estado[i] == 0) dfs(i);
        }

        if (tem_ciclo) printf("SIM\n");
        else printf("NAO\n");
    }
    return 0;
}
