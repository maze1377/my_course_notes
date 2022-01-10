#include <stdio.h>

#define SIZE 10000

void swap(int array[], int a, int b) {
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void sort(int array[], int n) {
    for (int j=0; j<n; j++) {
        int minIndex = j;
        for (int i=j+1; i < n; i++) {
            if (array[i] < array[minIndex]) {
                minIndex = i;
            }
        }
        swap(array, j, minIndex);

    }
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    int array[SIZE];
    for (int i=0; i<m; i++)
        scanf("%d", &array[i]);

    sort(array, m);


    int min = array[n-1] - array[0];
    for (int i=1; i+n < m; i++) {
        int diff = array[i + n -1] - array[i];
        if (diff < min)
            min = diff;
    }

    printf("%d\n", min);

    return 0;
}
