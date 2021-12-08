#include<stdio.h>

int sum(int n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int isPrime(int n) {
    if(n == 1) return 0;

    for(int i = 2; i < n; i++) {
        if(n % i == 0)
            return 0;
    }

    return 1;
}

int isVeryPrime(int n) {
    if(!isPrime(n))
        return 0;

    if(n < 10)
        return 1;

    return isVeryPrime(sum(n));
}

int solve(int index) {
    int num = 2;
    while(1) {
        if(isVeryPrime(num)) {
            index--;
            if(index == 0)
                return num;
        }
        num++;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", solve(n));
}