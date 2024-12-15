#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <iostream>

#define PI 3.14159265

// Translation class to move the object
class Translate {
public:
    int tx, ty;
    Translate(int x, int y) {
        tx = x;
        ty = y;
    }
};

// Rotation class to rotate the object
class Rotate {
public:
    float deg;
    Rotate(float angle) {
        deg = angle;
    }
};

// Scaling class to scale the object
class Scale {
public:
    int sx, sy;
    Scale(int x, int y) {
        sx = x;
        sy = y;
    }
};

// Rectangle class that holds coordinates of the rectangle
class Rectangle {
public:
    int x1, y1, x2, y2;
    
    // Constructor to initialize the coordinates
    Rectangle() {
        x1 = 100;
        y1 = 100;
        x2 = 200;
        y2 = 200;
    }

    // Constructor to initialize with custom coordinates
    Rectangle(int x_1, int y_1, int x_2, int y_2) {
        x1 = x_1;
        y1 = y_1;
        x2 = x_2;
        y2 = y_2;
    }

    // Operator overloading for translation
    Rectangle operator+(const Translate& t) {
        Rectangle r;
        r.x1 = x1 + t.tx;
        r.y1 = y1 + t.ty;
        r.x2 = x2 + t.tx;
        r.y2 = y2 + t.ty;
        return r;
    }

    // Operator overloading for scaling
    Rectangle operator*(const Scale& s) {
        Rectangle r;
        r.x1 = x1;
        r.y1 = y1;
        r.x2 = x2 * s.sx;
        r.y2 = y2 * s.sy;
        return r;
    }

    // Operator overloading for rotation
    Rectangle operator^(const Rotate& r) {
        Rectangle res;
        float radians = r.deg * PI / 180;
        double c = cos(radians);
        double s = sin(radians);
        
        // Rotate the coordinates
        int newX1 = round(x1 * c - y1 * s);
        int newY1 = round(x1 * s + y1 * c);
        int newX2 = round(x2 * c - y2 * s);
        int newY2 = round(x2 * s + y2 * c);
        
        res.x1 = newX1;
        res.y1 = newY1;
        res.x2 = newX2;
        res.y2 = newY2;
        
        return res;
    }

    // Draw the rectangle on the screen
    void draw() {
        rectangle(x1, y1, x2, y2);
    }
};

int main() {
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, NULL);

    // Create initial rectangle
    Rectangle r1(100, 100, 200, 200);
    r1.draw();  // Draw original rectangle

    // Apply translation to the rectangle
    Translate t1(50, 50);
    Rectangle r2 = r1 + t1;
    r2.draw();  // Draw translated rectangle

    // Apply scaling to the rectangle
    Scale s(2, 2);
    Rectangle r3 = r2 * s;
    r3.draw();  // Draw scaled rectangle

    // Apply rotation to the rectangle
    Rotate rot(45);
    Rectangle r4 = r1 ^ rot;
    r4.draw();  // Draw rotated rectangle

    getch();  // Wait for user input
    closegraph();  // Close the graphics window

    return 0;
}
