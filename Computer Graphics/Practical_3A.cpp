#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;

// Class for Drawing Shapes with Encapsulation
class PatternA {
private:
    int centerX, centerY, radius;

public:
    PatternA(int x, int y, int r) : centerX(x), centerY(y), radius(r) {}

    // Function to implement Bresenham's Circle Drawing Algorithm
    void drawCircle(int xc, int yc, int r) {
        int x = 0, y = r;
        int d = 3 - 2 * r;

        while (x <= y) {
            putpixel(xc + x, yc + y, WHITE);
            putpixel(xc - x, yc + y, WHITE);
            putpixel(xc + x, yc - y, WHITE);
            putpixel(xc - x, yc - y, WHITE);
            putpixel(xc + y, yc + x, WHITE);
            putpixel(xc - y, yc + x, WHITE);
            putpixel(xc + y, yc - x, WHITE);
            putpixel(xc - y, yc - x, WHITE);

            if (d < 0)
                d = d + 4 * x + 6;
            else {
                d = d + 4 * (x - y) + 10;
                y--;
            }
            x++;
        }
    }

    // Function to implement DDA Line Drawing Algorithm
    void drawLine(int x1, int y1, int x2, int y2) {
        int dx = x2 - x1, dy = y2 - y1;
        int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
        float xInc = dx / (float)steps, yInc = dy / (float)steps;

        float x = x1, y = y1;
        for (int i = 0; i <= steps; i++) {
            putpixel(round(x), round(y), WHITE);
            x += xInc;
            y += yInc;
        }
    }

    // Function to Draw the Complete Pattern
    void drawPattern() {
        // Draw the outer circle
        drawCircle(centerX, centerY, radius);

        // Draw the inner circle
        drawCircle(centerX, centerY, radius / 2);

        // Calculate vertices of the equilateral triangle
        int x1 = centerX;
        int y1 = centerY - radius;

        int x2 = centerX - (sqrt(3) / 2) * radius;
        int y2 = centerY + (radius / 2);

        int x3 = centerX + (sqrt(3) / 2) * radius;
        int y3 = centerY + (radius / 2);

        // Draw the triangle using DDA
        drawLine(x1, y1, x2, y2);
        drawLine(x2, y2, x3, y3);
        drawLine(x3, y3, x1, y1);
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Create object of class PatternA
    PatternA pattern(250, 250, 100);
    pattern.drawPattern();

    getch();
    closegraph();
    return 0;
}
