#include<stdio.h>

long long factorial(int n) {
    long long result = 1;
    for(int i = 1; i <= n; i++)
        result *= i;
    return result;
}

long long power(int a, int b) {
    if(b == 0)
        return 1;

    long long result = 1;
    for(int i = 0; i < b; i++) {
        result *= a;
    }

    return  result;
}

double f(int x, int i) {
    return (double) power(x, 2 * i) / (double) factorial(2 * i);
}

double cos(int x, int n) {
    int sign = 1;
    double result = 0;
    for(int i = 0; i < n; i++) {
        result += (double) sign * f(x, i);

        sign *= -1;
    }
    return result;
}

int main() {
    int x, n;
    scanf("%d %d", &x, &n);
    printf("%.3lf", cos(x, n));
}
