#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int x, sum = 0, max = 0;
    for(int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
        if(sum < 0)
            sum = 0;
        if(sum > max)
            max = sum;
    }
    cout << max;
    return 0;
}
