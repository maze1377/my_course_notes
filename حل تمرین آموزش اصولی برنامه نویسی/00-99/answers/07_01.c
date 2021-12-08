#include <stdio.h>

int findShortestLumberHeight(int lumbers[], int start, int end) {
    int min = lumbers[start];
    for(int i = start + 1; i <= end; i++) {
        if(lumbers[i] < min)
            min = lumbers[i];
    }
    return min;
}

int main() {
    int n;
    scanf("%d", &n);

    int lumbers[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &lumbers[i]);
    }

    int maxArea = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int shortestLumberHeight = findShortestLumberHeight(lumbers, i, j);
            int area = (j - i + 1) * shortestLumberHeight;
            if(area > maxArea)
                maxArea = area;
        }
    }

    printf("%d", maxArea);
}