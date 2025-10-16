#include <stdio.h>
#include <stdlib.h>

void troca(int *a,int *b){ int t=*a;*a=*b;*b=t; }

int part(int *v,int l,int r){
    int pivot = v[l + rand() % (r-l+1)];
    int i = l-1, j = r+1;
    while(1){
        do i++; while(v[i]<pivot);
        do j--; while(v[j]>pivot);
        if(i>=j) return j;
        troca(&v[i],&v[j]);
    }
}

void quicksort(int *v,int l,int r){
    if(l<r){
        int p = part(v,l,r);
        quicksort(v,l,p);
        quicksort(v,p+1,r);
    }
}

int main(){
    int nc,n,i;
    scanf("%d",&nc);
    while(nc--){
        scanf("%d",&n);
        int *v = malloc(n*sizeof(int));
        for(i=0;i<n;i++) scanf("%d",&v[i]);
        quicksort(v,0,n-1);
        for(i=0;i<n;i++){
            if(i) printf(" ");
            printf("%d",v[i]);
        }
        printf("\n");
        free(v);
    }
    return 0;
}
