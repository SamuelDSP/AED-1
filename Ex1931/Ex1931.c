#include <stdio.h>
#include <stdlib.h>

#define INFINITO 1000000000
#define MAXCIDADES 10005

typedef struct {
    int destino, custo;
} Estrada;

typedef struct {
    Estrada estradas[50];
    int quantidade;
} Cidade;

Cidade cidades[MAXCIDADES];
int distancia[MAXCIDADES][2];
int visitado[MAXCIDADES][2];

typedef struct {
    int cidade, custo, paridade;
} Estado;

Estado fila[1000000];
int tamanhoFila;

void inserir(int cidade, int custo, int paridade) {
    fila[tamanhoFila].cidade = cidade;
    fila[tamanhoFila].custo = custo;
    fila[tamanhoFila].paridade = paridade;
    int i = tamanhoFila++;
    while(i > 0) {
        int pai = (i-1)/2;
        if(fila[pai].custo <= fila[i].custo) break;
        Estado temp = fila[pai]; fila[pai] = fila[i]; fila[i] = temp;
        i = pai;
    }
}

Estado remover() {
    Estado resultado = fila[0];
    fila[0] = fila[--tamanhoFila];
    int i = 0;
    while(1) {
        int esquerda = 2*i + 1;
        int direita = 2*i + 2;
        int menor = i;
        if(esquerda < tamanhoFila && fila[esquerda].custo < fila[menor].custo) menor = esquerda;
        if(direita < tamanhoFila && fila[direita].custo < fila[menor].custo) menor = direita;
        if(menor == i) break;
        Estado temp = fila[i]; fila[i] = fila[menor]; fila[menor] = temp;
        i = menor;
    }
    return resultado;
}

int main() {
    int totalCidades, totalEstradas;
    while(scanf("%d %d", &totalCidades, &totalEstradas) == 2) {
        for(int i = 1; i <= totalCidades; i++) cidades[i].quantidade = 0;

        for(int i = 0; i < totalEstradas; i++) {
            int c1, c2, pedagio;
            scanf("%d %d %d", &c1, &c2, &pedagio);
            cidades[c1].estradas[cidades[c1].quantidade].destino = c2;
            cidades[c1].estradas[cidades[c1].quantidade].custo = pedagio;
            cidades[c1].quantidade++;
            cidades[c2].estradas[cidades[c2].quantidade].destino = c1;
            cidades[c2].estradas[cidades[c2].quantidade].custo = pedagio;
            cidades[c2].quantidade++;
        }

        for(int i = 1; i <= totalCidades; i++) {
            distancia[i][0] = INFINITO;
            distancia[i][1] = INFINITO;
            visitado[i][0] = 0;
            visitado[i][1] = 0;
        }

        distancia[1][0] = 0;
        tamanhoFila = 0;
        inserir(1, 0, 0);

        while(tamanhoFila) {
            Estado atual = remover();
            int u = atual.cidade;
            int custoAtual = atual.custo;
            int paridadeAtual = atual.paridade;

            if(visitado[u][paridadeAtual]) continue;
            visitado[u][paridadeAtual] = 1;

            for(int i = 0; i < cidades[u].quantidade; i++) {
                int v = cidades[u].estradas[i].destino;
                int novoCusto = custoAtual + cidades[u].estradas[i].custo;
                int novaParidade = paridadeAtual ^ 1;
                if(novoCusto < distancia[v][novaParidade]) {
                    distancia[v][novaParidade] = novoCusto;
                    inserir(v, novoCusto, novaParidade);
                }
            }
        }

        if(distancia[totalCidades][0] == INFINITO) printf("-1\n");
        else printf("%d\n", distancia[totalCidades][0]);
    }
    return 0;
}
