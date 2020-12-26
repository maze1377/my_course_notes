#include <iostream>

#define MAX 100

const int n = 9;
int board[MAX][MAX] = {
        {1, 1, 2, 3, 4, 5, 1, 6, 2},
        {1, 2, 4, 3, 2, 1, 1, 5, 4},
        {3, 1, 4, 2, 5, 5, 3, 5, 2},
        {5, 4, 3, 4, 4, 2, 5, 4, 1},
        {2, 2, 4, 5, 3, 3, 4, 2, 1},
        {1, 4, 4, 3, 3, 2, 4, 2, 5},
        {3, 2, 2, 1, 5, 4, 5, 1, 1},
        {1, 4, 2, 1, 5, 2, 2, 4, 2},
        {4, 3, 1, 2, 2, 5, 4, 4, 1}
};

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}

void swap(int &first, int &second) {
    int temp = first;
    first = second;
    second = temp;
}

int calc(int x, int y) {
    const int curr = board[y][x];

    int xCount = 0;
    for (int i = x + 1; i < n; i++) {
        if (board[y][i] == curr) xCount++;
        else break;
    }
    for (int i = x - 1; i >= 0; i--) {
        if (board[y][i] == curr) xCount++;
        else break;
    }

    int yCount = 0;
    for (int i = y + 1; i < n; i++) {
        if (board[i][x] == curr) yCount++;
        else break;
    }
    for (int i = y - 1; i >= 0; i--) {
        if (board[i][x] == curr) yCount++;
        else break;
    }

    int sum = 1;
    if (xCount >= 2) sum += xCount;
    if (yCount >= 2) sum += yCount;
    return sum;
}

void solve() {
    int max = -1;
    int x, y;
    char dir;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            swap(board[i][j], board[i][j + 1]);
            int firstCount = calc(j, i);
            int secondCount = calc(j + 1, i);
            int sum = 0;
            if (firstCount >= 3) {
                sum += firstCount;
            }
            if (secondCount >= 3) {
                sum += secondCount;
            }

            if (sum > max) {
                max = sum;
                x = j;
                y = i;
                dir = 'R';
            }
            swap(board[i][j], board[i][j + 1]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            swap(board[i][j], board[i + 1][j]);
            int firstCount = calc(j, i);
            int secondCount = calc(j, i + 1);
            int sum = 0;
            if (firstCount >= 3) {
                sum += firstCount;
            }
            if (secondCount >= 3) {
                sum += secondCount;
            }

            if (sum > max) {
                max = sum;
                x = j;
                y = i;
                dir = 'D';
            }
            swap(board[i][j], board[i + 1][j]);
        }
    }

    printf("%d\n", max);
    printf("%d %d\n", y, x);
    printf("%c\n", dir);
}

int main() {
    print();
    solve();
}