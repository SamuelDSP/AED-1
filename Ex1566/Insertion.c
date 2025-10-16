#include <stdio.h>
#include <stdlib.h>
int main(){
    int nc,n,i,j,t;
    scanf("%d",&nc);
    while(nc--){
        scanf("%d",&n);
        int *v = malloc(n*sizeof(int));
        for(i=0;i<n;i++) scanf("%d",&v[i]);
        for(i=1;i<n;i++){
            t=v[i];
            j=i-1;
            while(j>=0 && v[j]>t){
                v[j+1]=v[j];
                j--;
            }
            v[j+1]=t;
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
