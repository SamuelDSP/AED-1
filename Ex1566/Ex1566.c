#include <stdio.h>

int main() {
    int NC, N, i, h, j;
    scanf("%d", &NC);

    while (NC > 0) {
        scanf("%d", &N);

        static int c[231];
        for (i = 0; i <= 230; i++) c[i] = 0;

        for (i = 0; i < N; i++) {
            scanf("%d", &h);
            c[h] = c[h] + 1;
        }

        int first = 1;
        for (i = 20; i <= 230; i++) {
            j = c[i];
            while (j > 0) {
                if (first) {
                    printf("%d", i);
                    first = 0;
                } else {
                    printf(" %d", i);
                }
                j = j - 1;
            }
        }
        printf("\n");

        NC = NC - 1;
    }
    return 0;
}
