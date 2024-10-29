/*
3. A) Write a c++ program inscribed and circumscribed circles in triangle
*/

#include<iostream>
#include<graphics.h>
using namespace std;

void ddaAlg(int x1, int y1, int x2, int y2)
{
    int dx = x2-x1;
    int dy = y2 - y1;

    int steps = dx>dy?dx:dy;

    float xinc = dx/float(steps);
    float yinc = dy/float(steps);

    float x = x1;
    float y = y1;

    for(int i=0; i<=steps; i++){
        putpixel(x,y,WHITE);
        x+=xinc;
        y+=yinc;
    }
}
void display(int xc, int yc, int x, int y){
    putpixel(xc+x, yc+y, WHITE);
    putpixel(xc-x, yc+y, WHITE);
    putpixel(xc+x, yc-y, WHITE);
    putpixel(xc-x, yc-y, WHITE);
    putpixel(xc+y, yc+x, WHITE);
    putpixel(xc-y, yc+x, WHITE);
    putpixel(xc+y, yc-x, WHITE);
    putpixel(xc-y, yc-x, WHITE);
}
void circleB(int x1, int y1, int rad){
    int x = 0, y = rad;
    int d = 3 - 2*(rad);
    display(x1, y1, x, y); //Plotting initial starting point of circle

    while(x<=y){
        x++;
        if(d<0){
            d = d+(4*x)+6;
        }        
        else{
            y--;
            d = d+4*(x-y)+10;
        }
        display(x1, y1, x, y); //plot new points
    }
}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,NULL);

    circleB(150,180,57); //outer circle
    circleB(150,180,57/2); //inner circle
    ddaAlg(103, 180 + 30, 198, 180 + 30);
    ddaAlg(103, 180 + 30, 150, 122);   // Left side of the triangle
    ddaAlg(150, 122, 198, 180 + 30);   // Right side of the triangle

    getch();
    closegraph();
    return 0;
}

