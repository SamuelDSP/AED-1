#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j, diamantes;
    char entrada[1001];
    
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%s", entrada);
        int topo = -1;
        char pilha[1001];
        diamantes = 0;

        for(j = 0; entrada[j] != '\0'; j++) {
            if(entrada[j] == '<') {
                pilha[++topo] = '<';
            } else if(entrada[j] == '>') {
                if(topo >= 0) {
                    topo--;
                    diamantes++;
                }
            }
        }

        printf("%d\n", diamantes);
    }

    return 0;
}
