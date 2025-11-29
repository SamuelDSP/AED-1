#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

No* inserir(No* raiz, int valor) {
    if(raiz == NULL) return criarNo(valor);
    if(valor < raiz->valor) raiz->esquerda = inserir(raiz->esquerda, valor);
    else if(valor > raiz->valor) raiz->direita = inserir(raiz->direita, valor);
    return raiz;
}

typedef struct Fila {
    No* nos[1000];
    int inicio;
    int fim;
} Fila;

void iniciarFila(Fila* f) {
    f->inicio = 0;
    f->fim = 0;
}

void enfileirar(Fila* f, No* no) {
    f->nos[f->fim++] = no;
}

No* desenfileirar(Fila* f) {
    return f->nos[f->inicio++];
}

int filaVazia(Fila* f) {
    return f->inicio == f->fim;
}

void bfs(No* raiz) {
    Fila fila;
    iniciarFila(&fila);
    enfileirar(&fila, raiz);
    int primeiro = 1;
    while(!filaVazia(&fila)) {
        No* atual = desenfileirar(&fila);
        if(primeiro) { printf("%d", atual->valor); primeiro = 0; }
        else printf(" %d", atual->valor);
        if(atual->esquerda) enfileirar(&fila, atual->esquerda);
        if(atual->direita) enfileirar(&fila, atual->direita);
    }
    printf("\n");
}

void liberar(No* raiz) {
    if(raiz == NULL) return;
    liberar(raiz->esquerda);
    liberar(raiz->direita);
    free(raiz);
}

int main() {
    int C;
    scanf("%d", &C);
    for(int caso = 1; caso <= C; caso++) {
        int N;
        scanf("%d", &N);
        No* raiz = NULL;
        for(int i = 0; i < N; i++) {
            int valor;
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }
        printf("Case %d:\n", caso);
        bfs(raiz);
        printf("\n");
        liberar(raiz);
    }
    return 0;
}
