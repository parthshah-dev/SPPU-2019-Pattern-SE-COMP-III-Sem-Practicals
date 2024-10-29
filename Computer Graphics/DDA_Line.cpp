#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;

void drawLineDDA(int x1, int y1, int x2, int y2){
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = max(abs(dx), abs(dy));

    float xinc = dx/float(steps);
    float yinc = dy/float(steps);

    //Intial points
    float x = x1;
    float y = y1;

    for(int i=0; i<steps; i++){
        putpixel(round(x), round(y), WHITE);
        x += xinc;
        y += yinc;
    }
}
int main(){
    int gd=DETECT, gm;
    initgraph(&gd, &gm, NULL);

    drawLineDDA(200, 200, 100, 300);

    getch();
    cleardevice();
    return 0;
}
