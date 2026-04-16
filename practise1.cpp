//midpoint circle draw

#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;
 void circleDraw(int xc,int yc,int x,int y)
 {
     putpixel(xc+x,yc+y,WHITE);
     putpixel(xc-x,yc+y,WHITE);
     putpixel(xc+x,yc-y,WHITE);
     putpixel(xc-x,yc-y,WHITE);
     putpixel(xc+y,yc+x,WHITE);
     putpixel(xc-y,yc+x,WHITE);
     putpixel(xc+y,yc-x,WHITE);
     putpixel(xc-y,yc-x,WHITE);

 }

 int main()
 {
     int gd=DETECT,gm;
     initgraph(&gd,&gm,NULL);
     int xc=100,yc=100,r=50;
     int x=0,y=r,p=1-r;

     while(x<=y)
     {
         circleDraw(xc,yc,x,y);
         x++;
         if(p<0)
         {
            p=p+(2*x)+1;
         }
         else
         {
             p=p+2*(x-y)+1;
            y--;
         }


     }
     getch();
     closegraph();
 }

 //bresenham circle draw


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









 //cohen sutherlan
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










//DDA









  #include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int gd = DETECT, gm;

    // init window
    initgraph(&gd, &gm, (char*)"");

    float x1, y1, x2, y2;
    cout << "Enter starting point (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter ending point (x2 y2): ";
    cin >> x2 >> y2;

    float dx = x2 - x1;
    float dy = y2 - y1;

    float steps = max(abs(dx), abs(dy));

    float xinc = dx / steps;
    float yinc = dy / steps;

    float x = x1;
    float y = y1;

    // draw line using DDA
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xinc;
        y += yinc;
        delay(20); // animation
    }

    getch();
    closegraph();
    return 0;
}














//2d translation

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    int points[n][3];

    cout << "Enter the coordinates (x y):" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1];
        points[i][2] = 1; // homogeneous coordinate
    }

    int tx, ty;
    cout << "Enter translation (tx ty): ";
    cin >> tx >> ty;

    // Translation matrix
    int T[3][3] = {
        {1, 0, tx},
        {0, 1, ty},
        {0, 0, 1}
    };

    int result[n][3];

    // Matrix multiplication
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            result[i][j] = 0;
            for(int k = 0; k < 3; k++)
            {
                result[i][j] += T[j][k] * points[i][k];
            }
        }
    }

    // Original points
    cout << "\nOriginal Points:" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "(" << points[i][0] << ", " << points[i][1] << ")" << endl;
    }

    // Translated points
    cout << "\nTranslated Points:" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "(" << result[i][0] << ", " << result[i][1] << ")" << endl;
    }

    return 0;
}

