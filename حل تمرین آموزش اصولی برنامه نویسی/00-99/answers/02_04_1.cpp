#include<stdio.h>

int main(){
    int A[1000];
    int B[100];
    int C[10];
    int n,t;
    for(int i=0;i<100;i++){
        B[i]=0;
        C[i/10]=0;
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
        B[i/10]+=A[i];
        C[i/100]+=A[i];
    }

    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        x--; // A starts from zero
        y--; // A starts from zero
        int sum=0;
        for(int j=x;j<=y;){
            if((j%100==0) && (y-j>=99)){
                sum+=C[j/100];
                j+=100;
            }
            else if((j%10==0) && (y-j>=9)){
                sum+=B[j/10];
                j+=10;
            }
            else{
                sum+=A[j];
                j++;
            }
        }
        printf("%d\n",sum);
    }
}
