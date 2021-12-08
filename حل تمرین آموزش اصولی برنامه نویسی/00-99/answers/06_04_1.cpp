#include<iostream>

using namespace std;

int calculateSum(int array[], int start, int end) {
    int sum = 0;
    for(int i = start; i <= end; i++) {
        sum += array[i];
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    int array[n];
    for(int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int max = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int sum = calculateSum(array, i, j);

            if(sum > max)
                max = sum;
        }
    }

    cout << max;
    return 0;
}
