#include <stdio.h>
#include <string.h>

void posfixo(char pre[], char in[], int n) {
    if(n == 0) return;

    char raiz = pre[0];
    int idx;
    for(idx = 0; idx < n; idx++) {
        if(in[idx] == raiz) break;
    }

    posfixo(pre+1, in, idx);
    posfixo(pre+1+idx, in+idx+1, n-idx-1);
    printf("%c", raiz);
}

int main() {
    int C;
    scanf("%d", &C);

    for(int caso = 0; caso < C; caso++) {
        int N;
        char pre[60], in[60];
        scanf("%d %s %s", &N, pre, in);
        posfixo(pre, in, N);
        printf("\n");
    }

    return 0;
}
