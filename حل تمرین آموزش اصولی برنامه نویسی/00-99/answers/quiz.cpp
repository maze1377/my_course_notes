#include <iostream>

#define SOLDIER 1
#define HORSE 2
#define CASTLE 3
#define ELEPHANT 4
#define MINISTER 5
#define KING 6

using namespace std;

int board[8][8];

bool checkPawn(int row, int col, int pawn) {
    return board[row][col] == pawn || board[row][col] == -pawn;
}

bool isWhite(int row, int col) {
    return board[row][col] > 0;
}

bool isOpponent(int currentPawn, int row, int col) {
    return currentPawn * board[row][col] < 0;
}

bool isOpponentKing(int currentPawn, int row, int col) {
    return isOpponent(currentPawn, row, col) && checkPawn(row, col, KING);
}

bool isEmpty(int row, int col) {
    return board[row][col] == 0;
}

bool isNotEmpty(int row, int col) {
    return !isEmpty(row, col);
}

bool checkCastle(int row, int col) {
    int pawn = board[row][col];

    for(int r = row + 1; r < 8; r++) {
        if(isOpponentKing(pawn, r, col)) {
            return true;
        }

        if(isNotEmpty(r, col))
            break;
    }

    for(int r = row - 1; r >= 0; r--) {
        if(isOpponentKing(pawn, r, col)) {
            return true;
        }

        if(isNotEmpty(r, col))
            break;
    }

    for(int c = col + 1; c < 8; c++) {
        if(isOpponentKing(pawn, row, c)) {
            return true;
        }

        if(isNotEmpty(row, c))
            break;
    }

    for(int c = col - 1; c >= 0; c--) {
        if(isOpponentKing(pawn, row, c)) {
            return true;
        }

        if(isNotEmpty(row, c))
            break;
    }

    return false;
}

bool checkElephant(int row, int col) {
    int pawn = board[row][col];

    for(int r = row + 1, c = col + 1; r < 8 && c < 8; r++, c++) {
        if(isOpponentKing(pawn, r, c))
            return true;

        if(isNotEmpty(r, c))
            break;
    }

    for(int r = row - 1, c = col + 1; r >= 0 && c < 8; r--, c++) {
        if(isOpponentKing(pawn, r, c))
            return true;

        if(isNotEmpty(r, c))
            break;
    }

    for(int r = row + 1, c = col - 1; r < 8 && c >= 0; r++, c--) {
        if(isOpponentKing(pawn, r, c))
            return true;

        if(isNotEmpty(r, c))
            break;
    }

    for(int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) {
        if(isOpponentKing(pawn, r, c))
            return true;

        if(isNotEmpty(r, c))
            break;
    }

    return false;
}

bool checkMinister(int row, int col) {
    return checkElephant(row, col) || checkCastle(row, col);
}

bool checkSoldier(int row, int col) {
    int pawn = board[row][col];

    if(isWhite(row, col)) {
        return isOpponentKing(pawn, row - 1, col + 1) || isOpponentKing(pawn, row - 1, col - 1);
    } else {
        return isOpponentKing(pawn, row + 1, col + 1) || isOpponentKing(pawn, row + 1, col - 1);
    }
}

bool checkHorse(int row, int col) {
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            if(i != 0 && j != 0) {
                int newRow = row + i;
                int newCol = col + 2*j;
                if(newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
                    if(isOpponentKing(board[row][col], newRow, newCol)) {
                        return true;
                    }
                }

                newRow = row + 2*i;
                newCol = col + j;
                if(newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
                    if(isOpponentKing(board[row][col], newRow, newCol)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }

    for(int row = 0; row < 8; row++) {
        for(int col = 0; col < 8; col++) {
            bool isFound = false;

            switch (abs(board[row][col])) {
                case CASTLE:
                    isFound = checkCastle(row, col);
                    break;

                case MINISTER:
                    isFound = checkMinister(row, col);
                    break;

                case SOLDIER:
                    isFound = checkSoldier(row, col);
                    break;

                case ELEPHANT:
                    isFound = checkElephant(row, col);
                    break;

                case HORSE:
                    isFound = checkHorse(row, col);
                    break;
            }

            if(isFound) {
                cout << (isWhite(row, col) ? "BLACK" : "WHITE");
                return 0;
            }
        }
    }

    cout << "NOBODY";

}