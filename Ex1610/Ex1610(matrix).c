#include <stdio.h>
#include <stdlib.h>

#define MAXN 10004
#define MAXM 30004

int *adj[MAXN];
int grau[MAXN];
int estado[MAXN];
int tem_ciclo;

void dfs(int u) {
    if (tem_ciclo) return;
    estado[u] = 1;
    for (int i = 0; i < grau[u]; i++) {
        int v = adj[u][i];
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
            grau[i] = 0;
            estado[i] = 0;
            if (adj[i]) {
                free(adj[i]);
                adj[i] = NULL;
            }
        }

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            grau[A]++;
            adj[A] = realloc(adj[A], grau[A] * sizeof(int));
            adj[A][grau[A] - 1] = B;
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
