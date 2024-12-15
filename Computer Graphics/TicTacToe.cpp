#include <graphics.h>
#include <conio.h>
#include <iostream>

using namespace std;

int board[3][3]; // Tic-Tac-Toe board (0: empty, 1: player 'O', 2: player 'X')

// Function to draw the Tic-Tac-Toe grid
void drawGrid() {
    // Vertical lines
    line(200, 100, 200, 400);
    line(300, 100, 300, 400);
    // Horizontal lines
    line(100, 200, 400, 200);
    line(100, 300, 400, 300);
}

// Function to draw 'O' (circle) at the given grid position
void drawO(int x, int y) {
    int centerX = 150 + x * 100; // X-coordinate for the center
    int centerY = 150 + y * 100; // Y-coordinate for the center
    circle(centerX, centerY, 40);
}

// Function to draw 'X' (cross) at the given grid position
void drawX(int x, int y) {
    int startX = 110 + x * 100;
    int startY = 110 + y * 100;
    int endX = 190 + x * 100;
    int endY = 190 + y * 100;
    line(startX, startY, endX, endY);      // First diagonal line
    line(startX, endY, endX, startY);      // Second diagonal line
}

// Function to check if a player has won
int checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0) {
            return board[i][0];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0) {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0) {
        return board[0][2];
    }

    return 0; // No winner yet
}

// Main game logic
void playGame() {
    int player = 1; // Player 'O' starts
    int moves = 0;  // Track number of moves made

    while (true) {
        int x, y;
        cout << "Player " << (player == 1 ? "'O'" : "'X'") << "'s turn. Enter row and column (0-2): ";
        cin >> x >> y;

        if (x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != 0) {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        board[x][y] = player; // Mark the board

        // Draw the player's move on the screen
        if (player == 1) {
            drawO(x, y);
        } else {
            drawX(x, y);
        }

        // Check for a winner
        int winner = checkWin();
        if (winner != 0) {
            cout << "Player " << (winner == 1 ? "'O'" : "'X'") << " wins!" << endl;
            break;
        }

        // Switch player and increment move count
        player = (player == 1) ? 2 : 1;
        moves++;

        // If all moves are made and no winner, it's a draw
        if (moves == 9) {
            cout << "It's a draw!" << endl;
            break;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Initialize the board to be empty
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = 0;
        }
    }

    // Draw the Tic-Tac-Toe grid
    drawGrid();

    // Play the game
    playGame();

    getch();
    closegraph();
    return 0;
}
