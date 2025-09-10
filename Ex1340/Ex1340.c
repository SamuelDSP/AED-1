#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
} Fila;

typedef struct {
    int dados[MAX];
    int tamanho;
} FilaPrioridade;

void inicializaPilha(Pilha* p) {
    p->topo = -1;
}

void empilha(Pilha* p, int x) {
    p->dados[++(p->topo)] = x;
}

int desempilha(Pilha* p) {
    return p->dados[(p->topo)--];
}

void inicializaFila(Fila* f) {
    f->inicio = 0;
    f->fim = 0;
}

void enfileira(Fila* f, int x) {
    f->dados[f->fim++] = x;
}

int desenfileira(Fila* f) {
    return f->dados[f->inicio++];
}

void inicializaFilaPrioridade(FilaPrioridade* fp) {
    fp->tamanho = 0;
}

void insereFilaPrioridade(FilaPrioridade* fp, int x) {
    fp->dados[fp->tamanho++] = x;
    int i = fp->tamanho - 1;
    while (i > 0 && fp->dados[i] > fp->dados[(i - 1) / 2]) {
        int temp = fp->dados[i];
        fp->dados[i] = fp->dados[(i - 1) / 2];
        fp->dados[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int removeFilaPrioridade(FilaPrioridade* fp) {
    int valor = fp->dados[0];
    fp->dados[0] = fp->dados[--fp->tamanho];
    int i = 0;
    while (2 * i + 1 < fp->tamanho) {
        int filho = 2 * i + 1;
        if (filho + 1 < fp->tamanho && fp->dados[filho] < fp->dados[filho + 1]) {
            filho++;
        }
        if (fp->dados[i] >= fp->dados[filho]) break;
        int temp = fp->dados[i];
        fp->dados[i] = fp->dados[filho];
        fp->dados[filho] = temp;
        i = filho;
    }
    return valor;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int comando, valor;
        Pilha p;
        Fila f;
        FilaPrioridade fp;
        int ehPilha = 1, ehFila = 1, ehFilaPrioridade = 1;

        inicializaPilha(&p);
        inicializaFila(&f);
        inicializaFilaPrioridade(&fp);

        for (int i = 0; i < n; i++) {
            scanf("%d", &comando);
            if (comando == 1) {
                scanf("%d", &valor);
                empilha(&p, valor);
                enfileira(&f, valor);
                insereFilaPrioridade(&fp, valor);
            } else if (comando == 2) {
                scanf("%d", &valor);
                if (ehPilha && (desempilha(&p) != valor)) ehPilha = 0;
                if (ehFila && (desenfileira(&f) != valor)) ehFila = 0;
                if (ehFilaPrioridade && (removeFilaPrioridade(&fp) != valor)) ehFilaPrioridade = 0;
            }
        }

        if (ehPilha + ehFila + ehFilaPrioridade > 1) {
            printf("not sure\n");
        } else if (ehPilha) {
            printf("stack\n");
        } else if (ehFila) {
            printf("queue\n");
        } else if (ehFilaPrioridade) {
            printf("priority queue\n");
        } else {
            printf("impossible\n");
        }
    }
    return 0;
}
