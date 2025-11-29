#include <stdio.h>
#include <string.h>

int inverter(int x) {
    int r = 0;
    while (x > 0) {
        r = r * 10 + (x % 10);
        x = x / 10;
    }
    return r;
}

int fila[20000];
int frente, tras;
int visitado[20000];
int dist[20000];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int A, B;
        scanf("%d %d", &A, &B);

        memset(visitado, 0, sizeof(visitado));
        frente = 0;
        tras = 0;

        fila[tras] = A;
        tras++;
        visitado[A] = 1;
        dist[A] = 0;

        while (frente < tras) {
            int atual = fila[frente];
            frente++;

            if (atual == B) break;

            int op1 = atual + 1;
            if (op1 <= 10000 && visitado[op1] == 0) {
                visitado[op1] = 1;
                dist[op1] = dist[atual] + 1;
                fila[tras] = op1;
                tras++;
            }

            int op2 = inverter(atual);
            if (op2 <= 10000 && visitado[op2] == 0) {
                visitado[op2] = 1;
                dist[op2] = dist[atual] + 1;
                fila[tras] = op2;
                tras++;
            }
        }

        printf("%d\n", dist[B]);
    }
    return 0;
}
