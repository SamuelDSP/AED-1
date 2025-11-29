#include <stdio.h>
#include <stdlib.h>

#define MAX 2005

typedef struct No {
    int v;
    struct No* prox;
} No;

No* adj[MAX];
No* adjT[MAX];
int visitado[MAX];

void adicionarAresta(No* lista[], int u, int v) {
    No* novo = (No*)malloc(sizeof(No));
    novo->v = v;
    novo->prox = lista[u];
    lista[u] = novo;
}

void limpar(No* lista[], int n) {
    for(int i = 1; i <= n; i++) {
        No* p = lista[i];
        while(p != NULL) {
            No* temp = p;
            p = p->prox;
            free(temp);
        }
        lista[i] = NULL;
    }
}

void dfs(int u, No* lista[]) {
    visitado[u] = 1;
    No* p = lista[u];
    while(p != NULL) {
        if(!visitado[p->v]) dfs(p->v, lista);
        p = p->prox;
    }
}

int main() {
    while(1) {
        int N, M;
        scanf("%d %d", &N, &M);
        if(N == 0 && M == 0) break;

        limpar(adj, N);
        limpar(adjT, N);

        for(int i = 0; i < M; i++) {
            int V, W, P;
            scanf("%d %d %d", &V, &W, &P);
            adicionarAresta(adj, V, W);
            adicionarAresta(adjT, W, V);
            if(P == 2) {
                adicionarAresta(adj, W, V);
                adicionarAresta(adjT, V, W);
            }
        }

        for(int i = 1; i <= N; i++) visitado[i] = 0;
        dfs(1, adj);
        int conectado = 1;
        for(int i = 1; i <= N; i++) {
            if(!visitado[i]) { conectado = 0; break; }
        }

        if(conectado) {
            for(int i = 1; i <= N; i++) visitado[i] = 0;
            dfs(1, adjT);
            for(int i = 1; i <= N; i++) {
                if(!visitado[i]) { conectado = 0; break; }
            }
        }

        printf("%d\n", conectado);
        limpar(adj, N);
        limpar(adjT, N);
    }
    return 0;
}
