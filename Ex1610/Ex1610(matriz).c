#include <stdio.h>

#define MAXN 105

int grafo[MAXN][MAXN];
int estado[MAXN];
int N, M;
int tem_ciclo;

void dfs(int u) {
    if (tem_ciclo) return;
    estado[u] = 1;
    for (int v = 1; v <= N; v++) {
        if (grafo[u][v]) {
            if (estado[v] == 0) dfs(v);
            else if (estado[v] == 1) {
                tem_ciclo = 1;
                return;
            }
        }
    }
    estado[u] = 2;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) grafo[i][j] = 0;
            estado[i] = 0;
        }

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            grafo[A][B] = 1;
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
