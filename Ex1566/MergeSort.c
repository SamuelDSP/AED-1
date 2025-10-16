#include <stdio.h>
#include <stdlib.h>
void merge(int *v,int *aux,int l,int m,int r){
    int i=l,j=m+1,k=l;
    while(i<=m&&j<=r){
        if(v[i]<=v[j]) aux[k++]=v[i++];
        else aux[k++]=v[j++];
    }
    while(i<=m) aux[k++]=v[i++];
    while(j<=r) aux[k++]=v[j++];
    for(i=l;i<=r;i++) v[i]=aux[i];
}
void mergesort(int *v,int *aux,int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergesort(v,aux,l,m);
        mergesort(v,aux,m+1,r);
        merge(v,aux,l,m,r);
    }
}
int main(){
    int nc,n,i;
    scanf("%d",&nc);
    while(nc--){
        scanf("%d",&n);
        int *v=malloc(n*sizeof(int));
        int *aux=malloc(n*sizeof(int));
        for(i=0;i<n;i++) scanf("%d",&v[i]);
        mergesort(v,aux,0,n-1);
        for(i=0;i<n;i++){
            if(i) printf(" ");
            printf("%d",v[i]);
        }
        printf("\n");
        free(v);
        free(aux);
    }
    return 0;
}
