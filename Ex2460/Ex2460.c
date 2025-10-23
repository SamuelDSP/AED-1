#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i, id, primeiro = 1;
    scanf("%d", &n);
    int *fila = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) scanf("%d", &fila[i]);
    scanf("%d", &m);
    int *saiu = calloc(100001, sizeof(int));
    for (i = 0; i < m; i++) {
        scanf("%d", &id);
        saiu[id] = 1;
    }
    for (i = 0; i < n; i++) {
        if (!saiu[fila[i]]) {
            if (!primeiro) printf(" ");
            printf("%d", fila[i]);
            primeiro = 0;
        }
    }
    printf("\n");
    free(fila);
    free(saiu);
    return 0;
}
