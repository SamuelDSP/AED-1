#include <stdio.h>

void bubble_sort(int v[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (v[j] < v[j+1]) {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}

int main(){
    int N;
    scanf("%d", &N);
    for(int j = 0; j < N; j++){
    int M;
    scanf("%d", &M);
    int P[1000];
    for(int i = 0; i < M; i++){
        scanf("%d", &P[i]);
    }
    int copia[1000];
    for(int i = 0; i < M; i++){
        copia[i] = P[i];
    }
    bubble_sort(copia, M);
    int contador = 0;
    for(int i = 0; i < M; i++){
        if(copia[i] == P[i]){
            contador++;
        }
    }
    printf("%d\n", contador);
}
    return 0;
}
