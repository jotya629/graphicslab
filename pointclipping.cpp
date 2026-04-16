#include <graphics.h>
#include <iostream>
using namespace std;

// Clipping window
int xmin = 150, ymin = 150, xmax = 300, ymax = 300;

// Check function
bool isInside(int x, int y) {
    return (x >= xmin && x <= xmax &&
            y >= ymin && y <= ymax);
}

int main() {
    cout << "Point Clipping\n";

    // Points (array দিয়ে)
    int x[] = {100, 200, 250, 350, 180};
    int y[] = {100, 200, 280, 200, 120};

    int n = 5;

    // Console output
    for (int i = 0; i < n; i++) {
        if (isInside(x[i], y[i]))
            cout << "(" << x[i] << "," << y[i] << ") -> INSIDE\n";
        else
            cout << "(" << x[i] << "," << y[i] << ") -> OUTSIDE\n";
    }

    // Graphics
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    rectangle(xmin, ymin, xmax, ymax);

    for (int i = 0; i < n; i++) {
        if (isInside(x[i], y[i]))
            setcolor(GREEN);
        else
            setcolor(RED);

        circle(x[i], y[i], 3);
    }

    getch();
    closegraph();
    return 0;
}
