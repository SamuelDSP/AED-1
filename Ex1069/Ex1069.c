#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char vetor[1001];
        scanf("%s", vetor);

        int diamantes = 0;
        int abertos = 0;

        for (int i = 0; vetor[i] != '\0'; i++) {
            if (vetor[i] == '<') {
                abertos++;     
            } 
            else if (vetor[i] == '>' && abertos > 0) {
                abertos--;     
                diamantes++; 

            }
        }

        printf("%d\n", diamantes);
    }

    return 0;
}
