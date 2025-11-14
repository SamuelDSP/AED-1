#include <stdio.h>
#include <stdlib.h>

typedef struct { int linha, coluna; } Ponto;

int N, M;
char imagem[1024][1024];
int visitado[1024][1024];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) scanf("%s", imagem[i]);

    int cliques = 0;

    Ponto *fila = malloc(N*M*sizeof(Ponto));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(imagem[i][j] == '.' && !visitado[i][j]) {
                int frente = 0, tras = 0;
                fila[tras++] = (Ponto){i,j};
                visitado[i][j] = 1;

                while(frente < tras) {
                    Ponto p = fila[frente++];
                    for(int k = 0; k < 4; k++) {
                        int nx = p.linha + dx[k];
                        int ny = p.coluna + dy[k];
                        if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                            if(imagem[nx][ny] == '.' && !visitado[nx][ny]) {
                                visitado[nx][ny] = 1;
                                fila[tras++] = (Ponto){nx, ny};
                            }
                        }
                    }
                }
                cliques++;
            }
        }
    }

    printf("%d\n", cliques);
    free(fila);
    return 0;
}
