/*#include <bits/stdc++.h>
using namespace std;

int main() {
    int xc, yc, r;
    cout << "Enter center (xc yc) and radius: ";
    cin >> xc >> yc >> r;

    int x = 0, y = r;
    int p = 1 - r;

    while (x <= y) {
        // 8 symmetric points
        cout << "(" << xc + x << "," << yc + y << ") ";
        cout << "(" << xc - x << "," << yc + y << ") ";
        cout << "(" << xc + x << "," << yc - y << ") ";
        cout << "(" << xc - x << "," << yc - y << ") ";
        cout << "(" << xc + y << "," << yc + x << ") ";
        cout << "(" << xc - y << "," << yc + x << ") ";
        cout << "(" << xc + y << "," << yc - x << ") ";
        cout << "(" << xc - y << "," << yc - x << ") ";
        cout << endl;

        x++;

        if (p < 0) {
            p = p + 2*x + 1;
        } else {
            y--;
            p = p + 2*x - 2*y + 1;
        }
    }

    return 0;
}*/
#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

void drawCircle(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = 100, yc = 100, r = 50;

    int x = 0, y = r;
    int p = 1 - r;

    while (x <= y) {
        drawCircle(xc, yc, x, y);
        x++;

        if (p < 0) p += 2*x + 1;
        else {
            y--;
            p += 2*x - 2*y + 1;
        }
    }

    getch();
    closegraph();
}
