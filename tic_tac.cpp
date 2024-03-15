#include <iostream>
#include<string>
using namespace std;

const int SIZE = 4;
string board[SIZE][SIZE];

void initializeBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = std::to_string(i * SIZE + j + 1);
        }
    }
}
void printBoard() {
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    for (int i = 0; i < SIZE; ++i) {
        cout << "\t";
        for (int j = 0; j < SIZE; ++j) {
            if (j != SIZE - 1)
                cout << " " << board[i][j] << " |";
            else
                cout << " " << board[i][j];
        }
        cout << "\n";
        if (i != SIZE - 1)
            cout << "\t---|---|---|---\n";
    }
    cout << "\n";
}

bool isWin() {
    // Check rows
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] != "-" && board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3])
            return true;
    }

    // Check columns
    for (int i = 0; i < SIZE; ++i) {
        if (board[0][i] != "-" && board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i])
            return true;
    }

    // Check diagonals
    if (board[0][0] != "-" && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3])
        return true;
    if (board[0][3] != "-" && board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0])
        return true;

    return false;
}

bool isDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (!(board[i][j] == "X") || !(board[i][j] == "0"))
                return false;  // Game is not yet finished
        }
    }
    return true;  // It's a draw
}


void playerTurn(int player) {
    char mark = (player == 1) ? 'X' : 'O';
    while (true) {
        int choice;
        cout << "Player " << player << ", enter a number: ";
        cin >> choice;
        --choice;  // To get 0-based index
        int x = choice / SIZE;
        int y = choice % SIZE;
        if (board[x][y] != "X" && board[x][y] != "O") {
            board[x][y] = mark;
            break;
        } else {
            cout << "Invalid choice, try again.\n";
        }
    }
}

int main() {
    initializeBoard();
    int player = 1;
    do {
        printBoard();
        playerTurn(player);
        player = 3 - player;  // Switch player
    } while (!isWin() && !isDraw());
    printBoard();
    if (isWin()) {
        cout << "Player " << (3 - player) << " wins!\n";
    } else {
        cout << "It's a draw.\n";
    }
    return 0;
}
