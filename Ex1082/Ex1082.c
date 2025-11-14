#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int V, E;
int adj[26][26];
int visitado[26];

void dfs(int u, char componente[], int *idx) {
    visitado[u] = 1;
    componente[(*idx)++] = 'a' + u;
    for(int v = 0; v < V; v++) {
        if(adj[u][v] && !visitado[v]) dfs(v, componente, idx);
    }
}

int cmp_char(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

int main() {
    int N;
    scanf("%d", &N);
    for(int caso = 1; caso <= N; caso++) {
        scanf("%d %d", &V, &E);
        memset(adj, 0, sizeof(adj));
        memset(visitado, 0, sizeof(visitado));

        for(int i = 0; i < E; i++) {
            char u, v;
            scanf(" %c %c", &u, &v);
            int ui = u - 'a';
            int vi = v - 'a';
            adj[ui][vi] = 1;
            adj[vi][ui] = 1;
        }

        printf("Case #%d:\n", caso);
        int componentes = 0;

        for(int i = 0; i < V; i++) {
            if(!visitado[i]) {
                char componente[26];
                int idx = 0;
                dfs(i, componente, &idx);
                componente[idx] = '\0';
                qsort(componente, idx, sizeof(char), cmp_char);
                for(int j = 0; j < idx; j++) printf("%c,", componente[j]);
                printf("\n");
                componentes++;
            }
        }

        printf("%d connected components\n\n", componentes);
    }
    return 0;
}
