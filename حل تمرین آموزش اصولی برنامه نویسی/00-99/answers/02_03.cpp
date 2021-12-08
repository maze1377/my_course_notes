#include<stdio.h>

int main(){
    int A[1000],B[1000];
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&B[i]);
    }
    int p1=0,p2=0;
    while(p1+p2<n+m){
        if(p1==n){
            printf("%d ",B[p2]);
            p2++;
        }
        else if(p2==m){
            printf("%d ",A[p1]);
            p1++;
        }
        else if(A[p1]<B[p2]){
            printf("%d ",A[p1]);
            p1++;
        }
        else{
            printf("%d ",B[p2]);
            p2++;
        }
    }
}
