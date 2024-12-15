#include <iostream>
#include <graphics.h>
#include <cmath>
#include <conio.h>
using namespace std;

void drawSky(int color) {
    setfillstyle(SOLID_FILL, color); // Fill the sky with a color
    bar(0, 0, getmaxx(), getmaxy());
}

void drawSun(int x, int y, int color) {
    setcolor(color);             // Set the sun color
    setfillstyle(SOLID_FILL, color);
    fillellipse(x, y, 50, 50);   // Draw the sun as a filled circle
}

void sunrise() {
    int screenWidth = getmaxx();
    int screenHeight = getmaxy();
    int sunX = screenWidth / 2;  // Horizontal center of the screen
    int sunY = screenHeight;     // Start from bottom of the screen

    for (int i = screenHeight; i > screenHeight / 2; i--) {
        drawSky(LIGHTBLUE);      // Sky color during sunrise
        drawSun(sunX, i, YELLOW);
        delay(50);
        cleardevice();
    }
}

void sunset() {
    int screenWidth = getmaxx();
    int screenHeight = getmaxy();
    int sunX = screenWidth / 2;  // Horizontal center of the screen
    int sunY = screenHeight / 2; // Start from the middle of the screen

    for (int i = sunY; i < screenHeight; i++) {
        drawSky(RED);            // Sky color during sunset
        drawSun(sunX, i, YELLOW);
        delay(50);
        cleardevice();
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    cout << "Simulating Sunrise and Sunset..." << endl;

    sunrise(); // Simulate sunrise
    delay(2000);
    sunset();  // Simulate sunset

    getch();
    closegraph();
    return 0;
}
