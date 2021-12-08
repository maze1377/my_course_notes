#include <iostream>

using namespace std;

unsigned long int factorial(int number) {
    if (number == 0)
        return 1;

    unsigned long int result = 1;
    for (int i = 2; i <= number; i++) {
        result *= i;
    }

    return result;
}

unsigned long int combination(int m, int n) {
    return factorial(m) / (factorial(n) * factorial(m - n));
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << combination(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}