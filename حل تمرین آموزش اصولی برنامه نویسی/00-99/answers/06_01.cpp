#include <iostream>

using namespace std;

bool isNayaraCows(int n) {
    if(n == 1)
        return true;

    int a, b, c, d = 0;
    a = b = c = 1;
    while(d < n) {
        d = c + a;
        a = b;
        b = c;
        c = d;
    }

    return d == n;
}

bool isDesired(int n, int minNayaraDivisorCount) {
    for(int i = 1; i <= n && minNayaraDivisorCount > 0; i++) {
        if(n % i == 0 && isNayaraCows(i))
            minNayaraDivisorCount--;
    }
    return minNayaraDivisorCount == 0;
}

int count(int start, int end, int min) {
    int count = 0;
    for(int i = start; i <= end; i++) {
        if(isDesired(i, min)) {
            count++;
        }
    }
    return count;
}


int main() {
    int a, b, n;
    cin >> a >> b >> n;
    cout << count(a, b, n);
}
