#include <stdio.h>
#include <string.h>

int main(void) {
  int n, valido = 1;
  scanf("%d",&n);
  int matriz[9][9];
  char respostas[n][4];
  for(int i = 0; i < n; i++){
    valido = 1;
    for(int j = 0;j < 9;j++){
      for(int k = 0;k < 9;k++){
        scanf("%d",&matriz[j][k]);
      }
    }
    for(int j = 0; j < 9 && valido; j++){
      int numeros[10] = {0};
      for(int k = 0; k < 9; k++){
        int num = matriz[j][k];
        if(num < 1 || num > 9 || numeros[num]){
          valido = 0;
          break;
        }
        numeros[num] = 1;
      }
    }
    for(int j = 0; j < 9 && valido; j++){
      int numeros[10] = {0};
      for(int k = 0; k < 9; k++){
        if(valido == 0){
          break;
        }
        int num = matriz[k][j];
        if(num < 1 || num > 9 || numeros[num]){
          valido = 0;
          break;
        }
        numeros[num] = 1;
      }
    }
  for (int linha = 0; linha < 9 && valido; linha += 3) {
    for (int coluna = 0; coluna < 9 && valido; coluna += 3) {
      int numeros[10] = {0};
      for (int x = 0; x < 3; x++) {
          for (int y = 0; y < 3; y++) {
            if(valido == 0){
              break;
            }
            int num = matriz[linha + x][coluna + y];
            if (num < 1 || num > 9 || numeros[num]) {
            valido = 0;
            break;
                        }
          numeros[num] = 1;
                    }
                }
            }
        }
    if(valido == 0){
      strcpy(respostas[i], "NAO");
    }else{
      strcpy(respostas[i], "SIM");
    }
  }
  for(int i = 0; i < n; i++){
    printf("Instancia %d\n",i+1);
    printf("%s\n\n",respostas[i]);
  }

  return 0;
}
