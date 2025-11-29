#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

int main() {
    int N;
    scanf("%d", &N);
    for(int caso = 0; caso < N; caso++) {
        int M, C;
        scanf("%d %d", &M, &C);

        No* tabela[M];
        for(int i = 0; i < M; i++) tabela[i] = NULL;

        for(int i = 0; i < C; i++) {
            int chave;
            scanf("%d", &chave);
            int indice = chave % M;

            No* novo = criarNo(chave);
            if(tabela[indice] == NULL) tabela[indice] = novo;
            else {
                No* p = tabela[indice];
                while(p->prox != NULL) p = p->prox;
                p->prox = novo;
            }
        }

        for(int i = 0; i < M; i++) {
            printf("%d ->", i);
            No* p = tabela[i];
            while(p != NULL) {
                printf(" %d ->", p->valor);
                p = p->prox;
            }
            printf(" \\\n");
        }

        for(int i = 0; i < M; i++) {
            No* p = tabela[i];
            while(p != NULL) {
                No* temp = p;
                p = p->prox;
                free(temp);
            }
        }

        if(caso != N-1) printf("\n");
    }
    return 0;
}
