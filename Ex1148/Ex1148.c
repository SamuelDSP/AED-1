#include <stdio.h>
#include <string.h>

#define INF 1000000000

int min(int a, int b) {
    return a < b ? a : b;
}

int N, E;
int adj[501][501];
int comp[501];

int main() {
    while(1) {
        scanf("%d %d", &N, &E);
        if(N == 0 && E == 0) break;

        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                adj[i][j] = (i == j) ? 0 : INF;

        for(int i = 0; i < E; i++) {
            int X, Y, H;
            scanf("%d %d %d", &X, &Y, &H);
            if(H < adj[X][Y]) adj[X][Y] = H;
        }

        for(int k = 1; k <= N; k++)
            for(int i = 1; i <= N; i++)
                for(int j = 1; j <= N; j++)
                    if(adj[i][k] < INF && adj[k][j] < INF)
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

        int c = 1;
        memset(comp, 0, sizeof(comp));
        for(int i = 1; i <= N; i++) {
            if(comp[i] == 0) {
                comp[i] = c;
                for(int j = 1; j <= N; j++)
                    if(adj[i][j] < INF && adj[j][i] < INF)
                        comp[j] = c;
                c++;
            }
        }

        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                if(comp[i] == comp[j])
                    adj[i][j] = 0;

        for(int k = 1; k <= N; k++)
            for(int i = 1; i <= N; i++)
                for(int j = 1; j <= N; j++)
                    if(adj[i][k] < INF && adj[k][j] < INF)
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

        int K;
        scanf("%d", &K);
        for(int i = 0; i < K; i++) {
            int O, D;
            scanf("%d %d", &O, &D);
            if(adj[O][D] >= INF) printf("Nao e possivel entregar a carta\n");
            else printf("%d\n", adj[O][D]);
        }
        printf("\n");
    }
    return 0;
}
