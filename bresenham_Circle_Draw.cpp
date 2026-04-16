/*#include <bits/stdc++.h>
using namespace std;

int main() {
    int xc, yc, r;
    cout << "Enter center (xc yc) and radius: ";
    cin >> xc >> yc >> r;

    int x = 0, y = r;
    int pk = 1 - r;

    vector<pair<int,int>> points;

    while (x <= y) {
        // 8-way symmetry points
        points.push_back({ xc + x, yc + y });
        points.push_back({ xc - x, yc + y });
        points.push_back({ xc + x, yc - y });
        points.push_back({ xc - x, yc - y });
        points.push_back({ xc + y, yc + x });
        points.push_back({ xc - y, yc + x });
        points.push_back({ xc + y, yc - x });
        points.push_back({ xc - y, yc - x });

        x++;

        if (pk < 0) {
            pk = pk + 2 * x + 1;
        } else {
            y--;
            pk = pk + 2 * (x - y) + 1;
        }
    }

    cout << "\nCircle points:\n";
    for (auto p : points) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }

    return 0;
}*/
#include <graphics.h>
#include <iostream>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc, yc, r;
    cout << "Enter center (xc yc) and radius: ";
    cin >> xc >> yc >> r;

    int x = 0;
    int y = r;
    int d = 3 - 2 * r;

    while (x <= y) {

        // 8-way symmetry (important part)
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        x++;

        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            y--;
            d = d + 4 * (x - y) + 10;
        }
    }

    getch();
    closegraph();
    return 0;
}
