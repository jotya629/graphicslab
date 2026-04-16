#include <graphics.h>
#include <iostream>
using namespace std;

// Clipping window
double xmin = 150, ymin = 150, xmax = 250, ymax = 250;

// Region codes
const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;

// Compute region code
int computeCode(double x, double y) {
    int code = INSIDE;

    if (x < xmin) code |= LEFT;
    else if (x > xmax) code |= RIGHT;

    if (y < ymin) code |= BOTTOM;
    else if (y > ymax) code |= TOP;

    return code;
}

// Cohen-Sutherland Line Clipping
bool cohenClip(double &x1, double &y1, double &x2, double &y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    while (true) {
        // both inside
        if (code1 == 0 && code2 == 0) {
            return true;
        }
        // both outside
        else if (code1 & code2) {
            return false;
        }
        // partially inside
        else {
            double x, y;
            int codeOut = code1 ? code1 : code2;

            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
}

int main() {
    cout << "Simple Line Clipping\n";

    // Triangle points (polygon)
    double x[3] = {100, 200, 300};
    double y[3] = {150, 250, 200};

    int n = 3;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Draw clipping window
    rectangle(xmin, ymin, xmax, ymax);

    // Draw original polygon (RED)
    setcolor(RED);
    for (int i = 0; i < n; i++) {
        line(x[i], y[i], x[(i+1)%n], y[(i+1)%n]);
    }

    // Clip each edge
    for (int i = 0; i < n; i++) {
        double x1 = x[i], y1 = y[i];
        double x2 = x[(i+1)%n], y2 = y[(i+1)%n];

        if (cohenClip(x1, y1, x2, y2)) {
            setcolor(GREEN);
            line(x1, y1, x2, y2);
        }
    }

    getch();
    closegraph();
    return 0;
}
