#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int width = 640, height = 480;
int snakeX[100], snakeY[100]; // arrays to store snake position
int snakeLength = 3;
int foodX, foodY;
int score = 0;
char direction = 'R';

void drawSnake() {
    for (int i = 0; i < snakeLength; i++) {
        rectangle(snakeX[i], snakeY[i], snakeX[i] + 10, snakeY[i] + 10);
        setfillstyle(SOLID_FILL, GREEN);
        floodfill(snakeX[i] + 1, snakeY[i] + 1, WHITE);
    }
}

void generateFood() {
    foodX = (rand() % (width / 10)) * 10;
    foodY = (rand() % (height / 10)) * 10;
    rectangle(foodX, foodY, foodX + 10, foodY + 10);
    setfillstyle(SOLID_FILL, RED);
    floodfill(foodX + 1, foodY + 1, WHITE);
}

void updateScore() {
    setcolor(WHITE);
    rectangle(0, 0, width, 20);
    char scoreText[20];
    sprintf(scoreText, "Score: %d", score);
    outtextxy(10, 5, scoreText);
}

void moveSnake() {
    for (int i = snakeLength - 1; i > 0; i--) {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }

    switch (direction) {
        case 'R': snakeX[0] += 10; break;
        case 'L': snakeX[0] -= 10; break;
        case 'U': snakeY[0] -= 10; break;
        case 'D': snakeY[0] += 10; break;
    }
}

bool checkCollision() {
    if (snakeX[0] < 0 || snakeX[0] >= width || snakeY[0] < 20 || snakeY[0] >= height)
        return true;
    for (int i = 1; i < snakeLength; i++)
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i])
            return true;
    return false;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    srand(time(0));

    // Initial snake position
    snakeX[0] = 100; snakeY[0] = 100;
    for (int i = 1; i < snakeLength; i++) {
        snakeX[i] = snakeX[i - 1] - 10;
        snakeY[i] = snakeY[i - 1];
    }

    generateFood();
    updateScore();

    while (1) {
        cleardevice();
        drawSnake();
        rectangle(foodX, foodY, foodX + 10, foodY + 10);
        setfillstyle(SOLID_FILL, RED);
        floodfill(foodX + 1, foodY + 1, WHITE);
        updateScore();

        if (kbhit()) {
            char ch = getch();
            if (ch == 0 || ch == 224) { // Arrow keys are identified by two codes
                ch = getch();
                switch (ch) {
                    case 72: if (direction != 'D') direction = 'U'; break; // Up arrow
                    case 80: if (direction != 'U') direction = 'D'; break; // Down arrow
                    case 75: if (direction != 'R') direction = 'L'; break; // Left arrow
                    case 77: if (direction != 'L') direction = 'R'; break; // Right arrow
                }
            }
        }

        moveSnake();

        if (snakeX[0] == foodX && snakeY[0] == foodY) {
            snakeLength++;
            score += 10;
            generateFood();
        }

        if (checkCollision()) {
            char gameOverText[] = "Game Over!";
            outtextxy(width / 2 - 50, height / 2, gameOverText);
            getch();
            break;
        }
        delay(100);
    }

    closegraph();
    return 0;
}
