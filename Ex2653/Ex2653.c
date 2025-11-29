#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOIAS 1000000

char* joias[MAX_JOIAS];
int total = 0;

int comparar(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

int main() {
    char buffer[1000005];

    while(fgets(buffer, sizeof(buffer), stdin)) {
        // Remove '\n' do final
        size_t len = strlen(buffer);
        if(len > 0 && buffer[len-1] == '\n') buffer[len-1] = '\0';

        joias[total] = (char*)malloc(strlen(buffer)+1);
        strcpy(joias[total], buffer);
        total++;
    }

    qsort(joias, total, sizeof(char*), comparar);

    int distintos = 0;
    for(int i = 0; i < total; i++) {
        if(i == 0 || strcmp(joias[i], joias[i-1]) != 0) distintos++;
    }

    printf("%d\n", distintos);

    // libera memória
    for(int i = 0; i < total; i++) free(joias[i]);

    return 0;
}
