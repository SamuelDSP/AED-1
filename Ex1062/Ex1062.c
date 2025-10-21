#include <stdio.h>

int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        while (1) {
            int a[1000];
            scanf("%d", &a[0]);
            if (a[0] == 0) {
                printf("\n");
                break;
            }
            for (int i = 1; i < n; i++) scanf("%d", &a[i]);
            int pilha[1000], topo = 0, atual = 1, ok = 1;
            for (int i = 0; i < n; i++) {
                while (atual <= n && (topo == 0 || pilha[topo - 1] != a[i])) {
                    pilha[topo++] = atual++;
                }
                if (pilha[topo - 1] == a[i]) topo--;
                else {
                    ok = 0;
                    break;
                }
            }
            if (ok) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
