#include <stdio.h>

#define AMBIGUOUS -10000
#define NO_LIMIT -20000

double power(int a, int b) {
    double result = 1;
    for(int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

void differentiate(const int function[], int n, int result[]) {
    for(int i = 0; i < n - 1; i++) {
        result[i] = (i+1) * function[i+1];
    }
}

double calculateValue(const int function[], int n, int x) {
    double result = 0;
    for(int i = 0; i < n; i++) {
        result += power(x, i) * function[i];
    }
    return result;
}

double getValue(const int numerator[], int n, int denominator[], int m, int x) {
    double numeratorValue = calculateValue(numerator, n, x);
    double denominatorValue = calculateValue(denominator, m, x);

    if(numeratorValue == 0 && denominatorValue == 0)
        return AMBIGUOUS;

    if(denominatorValue == 0)
        return NO_LIMIT;

    return numeratorValue / denominatorValue;
}

double hopital(int x, int numerator[], int n, int denominator[], int m) {
    int numeratorNewLength = n - 1;
    int numeratorResult[numeratorNewLength];
    differentiate(numerator, n, numeratorResult);

    int denominatorNewLength = m - 1;
    int denominatorResult[denominatorNewLength];
    differentiate(denominator, m, denominatorResult);

    double result = getValue(numeratorResult, numeratorNewLength, denominatorResult, denominatorNewLength, x);
    return result;
}

void printAnswer(int numerator[], int n, int denominator[], int m, int x) {
    double result = getValue(numerator, n, denominator, m, x);
    while(result == AMBIGUOUS) {
        result = hopital(x, numerator, n, denominator, m);
    }

    if(result == NO_LIMIT) {
        printf("no limit");
    } else {
        printf("%.2f", result);
    }
}

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    n++;
    m++;

    int numerator[n];
    for(int i = n-1; i >= 0; i--)
        scanf("%d", &numerator[i]);

    int denominator[m];
    for(int i = m-1; i >= 0; i--)
        scanf("%d", &denominator[i]);

    printAnswer(numerator, n, denominator, m, x);
}