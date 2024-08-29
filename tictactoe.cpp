#include <iostream>
#include <cstdlib>  
using namespace std;

char board[3][3];
char currentMarker;
int currentPlayer;

void drawBoard() {
    system("cls");
    cout << endl << endl ;
    cout << "\t\t\t\t     KDA-TIC-TAC-TOE"<< endl;
    cout << endl;
    cout << "\t\t\t\t\t" << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "\t\t\t\t\t" << "---|---|---" << endl;
    cout << "\t\t\t\t\t"<< " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "\t\t\t\t\t" << "---|---|---" << endl;
    cout << "\t\t\t\t\t" << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '1' + (i * 3 + j);
        }
    }
}

bool placeMarker(int slot, char marker) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = marker;
        return true;
    } else {
        return false;
    }
}

void undoMove(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    board[row][col] = '1' + (row * 3 + col);
}

int winner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return (board[i][0] == 'X') ? 1 : 2;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return (board[0][i] == 'X') ? 1 : 2;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return (board[0][0] == 'X') ? 1 : 2;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return (board[0][2] == 'X') ? 1 : 2;
    }
    return 0;
}

bool boardIsFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

int minimax(bool isMaximizing) {
    int score = winner();
    if (score == 1) return -10;
    if (score == 2) return 10;
    if (boardIsFull()) return 0;

    if (isMaximizing) {
        int bestScore = -1000;
        for (int i = 1; i <= 9; i++) {
            int row = (i - 1) / 3;
            int col = (i - 1) % 3;
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = 'O';
                int score = minimax(false);
                board[row][col] = '1' + (row * 3 + col);
                bestScore = max(score, bestScore);
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int i = 1; i <= 9; i++) {
            int row = (i - 1) / 3;
            int col = (i - 1) % 3;
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = 'X';
                int score = minimax(true);
                board[row][col] = '1' + (row * 3 + col);
                bestScore = min(score, bestScore);
            }
        }
        return bestScore;
    }
}

void swapPlayerAndMarker() {
    if (currentMarker == 'X') {
        currentMarker = 'O';
    } else {
        currentMarker = 'X';
    }

    if (currentPlayer == 1) {
        currentPlayer = 2;
    } else {
        currentPlayer = 1;
    }
}

void computerMove() {
    int bestMove = -1;
    int bestScore = -1000;

    for (int i = 1; i <= 9; i++) {
        int row = (i - 1) / 3;
        int col = (i - 1) % 3;
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = 'O';
            int moveScore = minimax(false);
            board[row][col] = '1' + (row * 3 + col);

            if (moveScore > bestScore) {
                bestScore = moveScore;
                bestMove = i;
            }
        }
    }

    if (bestMove != -1) {
        placeMarker(bestMove, 'O');
    }
}

void playGame() {
    initializeBoard();
    drawBoard();

    while (true) {
        int slot;
        if (currentPlayer == 1) {
            cout << endl;
            cout << "It's your turn: ";
            cin >> slot;

            if (!placeMarker(slot, 'X')) {
                cout << "Slot occupied! Try again.\n";
                continue;
            }

            system("cls"); 
            drawBoard();

            int win = winner();
            if (win == 1) {
                cout << "You win!\n";
                break;
            } else if (boardIsFull()) {
                cout << "It's a tie!\n";
                break;
            }
        }

        swapPlayerAndMarker();

        if (currentPlayer == 2) {
            computerMove();
            system("cls"); 
            drawBoard();

            int win = winner();
            if (win == 2) {
                cout << "Computer wins!\n";
                break;
            } else if (boardIsFull()) {
                cout << "It's a tie!\n";
                break;
            }

            swapPlayerAndMarker();
        }
    }
}

int main() {
    system ("cls");
    char playAgain;
    do {
        cout << "\t\t\t\t\tWelcome to Tic-Tac-Toe!\n";
        cout << "\t\t\t\t\tChoose your marker: ";
        char markerP1;
        cin >> markerP1;

        currentPlayer = 1;
        currentMarker = markerP1;

        playGame();

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain == 'n' || playAgain == 'N') {
            exit(0);
        }
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}