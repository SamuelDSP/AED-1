#include <stdio.h>
#include <stdlib.h>
int main(){
    int nc,n,i,j,min,t;
    scanf("%d",&nc);
    while(nc--){
        scanf("%d",&n);
        int *v = malloc(n*sizeof(int));
        for(i=0;i<n;i++) scanf("%d",&v[i]);
        for(i=0;i<n-1;i++){
            min=i;
            for(j=i+1;j<n;j++) if(v[j]<v[min]) min=j;
            t=v[i]; v[i]=v[min]; v[min]=t;
        }
        for(i=0;i<n;i++){
            if(i) printf(" ");
            printf("%d",v[i]);
        }
        printf("\n");
        free(v);
    }
    return 0;
}
