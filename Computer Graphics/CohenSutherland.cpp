#include<graphics.h>
#include<iostream>
using namespace std;

int computeCode(int x, int y, int xmin, int xmax, int ymin, int ymax){
    int code = 0;
    if(x < xmin) code |= 1;
    if(x > xmax) code |= 2;
    if(y < ymin) code |= 4;
    if(y > ymax) code |= 8;

    return code;
}
void findIntersection(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax, int code, int &x, int &y){
    if (code == 1){
        x = xmin;
        y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
    }
    else if(code == 2){
        x = xmax;
        y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
    }
    else if(code == 4){
        y = ymin;
        x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
    }
    else{
        y = ymax;
        x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
    }
}
int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int xmin = 100, ymin = 100, xmax = 400, ymax = 400;
    int x1 = 50, y1 = 150, x2 = 300, y2 = 450;

    rectangle(xmin, ymin, xmax, ymax);
    line(x1, y1, x2, y2);

    int code1 = computeCode(x1, y1, xmin, xmax, ymin, ymax);
    int code2 = computeCode(x2, y2, xmin, xmax, ymin, ymax);

    delay(1000);
    cleardevice();

    rectangle(xmin, ymin, xmax, ymax); //redraw clipping window

    if (code1 != 0) {
        findIntersection(x1, y1, x2, y2, xmin, ymin, xmax, ymax, code1, x1, y1);
    }
    if (code2 != 0) {
        findIntersection(x1, y1, x2, y2, xmin, ymin, xmax, ymax, code2, x2, y2);
    }

    line(x1, y1, x2, y2); //redraw clipped line

    delay(10000);
    getch();
    closegraph();
    return 0;
}
