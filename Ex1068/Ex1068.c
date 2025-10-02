#include <stdio.h>
#include <string.h>

int main() {
    char expressao[1001];
    
    while (scanf("%s", expressao) != EOF) {
        int topo = -1;
        char pilha[1001];
        int correto = 1;
        
        for (int i = 0; expressao[i] != '\0'; i++) {
            if (expressao[i] == '(') {
                pilha[++topo] = '(';
            } else if (expressao[i] == ')') {
                if (topo >= 0) {
                    topo--;
                } else {
                    correto = 0;
                    break;
                }
            }
        }
        
        if (correto && topo == -1) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    
    return 0;
}
