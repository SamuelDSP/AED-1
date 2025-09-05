#include <stdio.h>

int main(){
    int N;
    int X[1000];
    int posicao = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &X[i]);
    }
    int menor = X[0];
    for(int j = 0; j < N; j++){
        if(X[j]< menor){
            menor = X[j];
            posicao = j;
        }

    }
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n",posicao);
}
