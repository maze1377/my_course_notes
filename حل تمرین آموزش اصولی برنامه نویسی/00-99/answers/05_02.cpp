#include <stdio.h>

int main() {

    unsigned long long int n;
    scanf("%lld", &n);

    while (n > 0) {
        int x = n % 10;
        n = n/10;

        printf("%d:", x);
        for (int i=0; i<x; i++) {
            printf("%d", x);
        }
        printf("\n");
    }

    return 0;
}