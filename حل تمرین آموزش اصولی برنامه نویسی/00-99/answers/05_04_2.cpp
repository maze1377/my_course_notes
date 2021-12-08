#include<iostream>

using namespace std;

int isArithmetic(int n) {
    int avg = 1 + n;
    int count = 2;
    for(int i = 2; i <= n/2; i++) {
        if(n % i == 0) {
            avg += i;
            count++;
        }
    }
    return avg % count == 0;
}

int isPalindrome(int n) {
    int rev = 0;
    int copy = n;
    while(n > 0) {
        rev = n % 10 + rev * 10;
        n /= 10;
    }
    return copy == rev;
}

int pow(int n, int p) {
    if(p == 0)
        return 1;
    int res = 1;
    for(int i = 0; i < p; i++) {
        res *= n;
    }
    return res;
}

int convertToBase(int n, int base) {
    int res = 0;
    int i = 0;
    while(n > 0) {
        res = res + (n % base) * pow(10, i);
        n /= base;
        i++;
    }
    return res;
}

int solve(int index, int base) {
    int i;
    for(i = 0; ; i++) {
        if(isArithmetic(i) && isPalindrome(convertToBase(i, base))) {
            index--;
        }
        if(index == 0)
            return i;
    }
}

int main() {
    int n, b;
    cin >> n >> b;
    cout << solve(n, b);
    return 0;
}
