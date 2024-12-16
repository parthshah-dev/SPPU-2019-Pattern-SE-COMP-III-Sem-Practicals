#include <graphics.h>
#include <iostream>

void drawScene(int sunY) {
    cleardevice();
    
    // Draw sky color based on sun position
    if (sunY < 200) {
        setbkcolor(LIGHTBLUE); // Daytime
    } else {
        setbkcolor(LIGHTRED); // Evening
    }
    cleardevice();

    // Draw ground
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    rectangle(0, 400, 640, 480);
    floodfill(1, 401, GREEN);

    // Draw sun
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    circle(320, sunY, 40);
    floodfill(320, sunY, YELLOW);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm,  NULL);

    int sunY;

    // Sunrise
    for (sunY = 400; sunY >= 100; sunY -= 5) {
        drawScene(sunY);
        delay(50);
    }
    delay(2000);

    // Sunset
    for (sunY = 100; sunY <= 400; sunY += 5) {
        drawScene(sunY);
        delay(50);
    }

    closegraph();
    return 0;
}
