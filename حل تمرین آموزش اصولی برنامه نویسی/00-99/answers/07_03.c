#include <stdio.h>
#include <math.h>
#define MOUSE 1
#define CHEESE 2

int main() {
    int rowCount, colCount;
    scanf("%d %d", &rowCount, &colCount);

    int map[rowCount][colCount];

    // Save input and find the mouse
    int rowMouse, colMouse;
    for (int row = 0; row < rowCount; row++) {
        for (int col = 0; col < colCount; col++) {
            scanf("%d", &map[row][col]);

            if (map[row][col] == MOUSE) {
                rowMouse = row;
                colMouse = col;
            }
        }
    }


    int distance = 0;
    int minDistance = 100;
    for (int row = 0; row < rowCount; row++) {
        for (int col = 0; col < colCount; col++) {
            if (map[row][col] == CHEESE) {
                distance = abs(row - rowMouse) + abs(col - colMouse);

                if (distance < minDistance)
                    minDistance = distance;
            }
        }
    }

    printf("%d", minDistance);

    return 0;
}