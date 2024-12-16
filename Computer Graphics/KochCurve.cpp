#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

void drawKochCurve(int depth, int x1, int y1, int x2, int y2) {
    if (depth == 0) {
        line(x1, y1, x2, y2); 
        return;
    }

    int dx = (x2 - x1) / 3;
    int dy = (y2 - y1) / 3;

    int x3 = x1 + dx;
    int y3 = y1 + dy;

    int x5 = x2 - dx;
    int y5 = y2 - dy;

    int x4 = (int)(0.5 * (x1 + x2) + sqrt(3) * (y2 - y1) / 6);
    int y4 = (int)(0.5 * (y1 + y2) - sqrt(3) * (x2 - x1) / 6);

    drawKochCurve(depth - 1, x1, y1, x3, y3);
    drawKochCurve(depth - 1, x3, y3, x4, y4);
    drawKochCurve(depth - 1, x4, y4, x5, y5);
    drawKochCurve(depth - 1, x5, y5, x2, y2);
}


int main() {
    int iterations;
    cout << "Enter number of iterations: ";
    cin >> iterations;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    drawKochCurve(iterations, 100, 200, 500, 200);

    getch();
    closegraph();
    return 0;
}
