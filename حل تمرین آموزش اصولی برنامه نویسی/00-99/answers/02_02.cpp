#include<stdio.h>

const int maxSize=1e7+1;
bool isPrime[maxSize];
int main(){
    for(int i=2;i<maxSize;i++){
        isPrime[i]=true;
    }
    for(int i=2;i<maxSize;i++){
        if (!isPrime[i]){
            continue; // Not necessary but more optimized
        }
        for(int j=2*i;j<maxSize;j+=i){ // Consider that each time j is increased by i, not 1
            isPrime[j]=false; // one common mistake is change isPrime[i] instead of isPrime[j]
        }
    }
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        if(isPrime[tmp]){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
}
