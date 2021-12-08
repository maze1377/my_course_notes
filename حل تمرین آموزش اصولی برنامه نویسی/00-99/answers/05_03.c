#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int b = 0;
    while (n > 0) {
        b += n % 10;
        n = n/10;
    }

    // fib
    int prev = 1;
    int current = 1;
    for (int i=2; i<b; i++) {
        int new_item = prev + current;
        prev = current;
        current = new_item;
    }
    printf("%d", current);

    return 0;
}