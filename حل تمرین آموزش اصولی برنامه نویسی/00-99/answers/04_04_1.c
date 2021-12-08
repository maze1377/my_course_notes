#include <stdio.h>

int main() {
    
    int n;
    scanf("%d", &n);

    while(n > 0) {
        int m;
        scanf("%d", &m);

        int primes_count = 1;
        int very_primes_count = 0;

        int p = 2;

        while (very_primes_count < m) {
            p++;
            int is_p_prime = 1;
            for (int i=2; i<p; i++) {
                if (p % i == 0) {
                    is_p_prime = 0;
                    break;
                }
            }

            if (is_p_prime == 1) {
                primes_count++;
                int is_very_prime = 1;
                for (int i = 2; i < primes_count; i++) {
                    if (primes_count % i == 0) {
                        is_very_prime = 0;
                        break;
                    }
                }
                if (is_very_prime == 1) {
                    very_primes_count++;
                }
            }
        }

        printf("%d\n", p);

        n--;
    }

    return 0;
}