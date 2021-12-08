#include <stdio.h>

int main() {
    
    int n;
    scanf("%d", &n);

    printf("*\n");

    for (int i=1; i<=n; i++) {
        printf("*");
        for (int j=1; j<=i; j++) {
            printf("%d", j);
        }
        for (int j=i-1; j>=1; j--) {
            printf("%d", j);
        }
        printf("*\n");
    }

    for (int i=n-1; i>=1; i--) {
        printf("*");
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        for (int j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }
        printf("*\n");
    }

    printf("*\n");

    return 0;
}