#include <stdio.h>

int main() {
    int n;
    while(scanf("%d", &n) && n) {
        int fila[100], inicio = 0, fim = n;
        int descartadas[50], d = 0;

        for(int i = 0; i < n; i++) fila[i] = i + 1;

        while(fim - inicio > 1) {
            descartadas[d++] = fila[inicio++];
            fila[fim++] = fila[inicio++];
        }

        printf("Discarded cards:");
        if(d > 0) {
            printf(" %d", descartadas[0]);
            for(int i = 1; i < d; i++) printf(", %d", descartadas[i]);
        }
        printf("\n");

        printf("Remaining card: %d\n", fila[inicio]);
    }
    return 0;
}
