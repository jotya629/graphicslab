/*#include<bits/stdc++.h>
using namespace std;
int main()
{

    float xin,yin,xend,yend,steps,m,xnew,ynew,xf,yf;
    cout<<"give me the value of starting co-ordinates : ";
    cin>>xin>>yin;
    cout<<"give me the value of ending co-ordinates : ";
    cin>>xend>>yend;
    m=(yend-yin)/(xend-xin);
    if((abs(xend-xin))>(abs(yend-yin))){
        steps=abs(xend-xin);
    }

    else
        steps=abs(yend-yin);
    for(int i=0;i<steps;i++)
    {
        if(m<1)
        {
            xnew=(1+xin);
            ynew=(m+yin);
            xf=round(xnew);
            yf=round(ynew);
            xin=xnew;
            yin=ynew;

        }
        else if(m==1)
        {
            xnew=(1+xin);
            ynew=(1+yin);
            xf=round(xnew);
            yf=round(ynew);
            xin=xnew;
            yin=ynew;


        }
        else{
            xnew=((1/m)+xin);
            ynew=(1+yin);
            xf=round(xnew);
            yf=round(ynew);
            xin=xnew;
            yin=ynew;
        }
        cout<<" ( "<<xf<<" , "<<yf<<" )";

    }  }*/
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
/*#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    float x1=100, y1=100, x2=300, y2=200;

    float dx = x2 - x1;
    float dy = y2 - y1;

    float steps = max(abs(dx), abs(dy));

    float xinc = dx / steps;
    float yinc = dy / steps;

    float x = x1, y = y1;

    char text[50];

    for (int i = 0; i <= steps; i++) {
        int px = round(x);
        int py = round(y);

        putpixel(px, py, WHITE);

        // text বানানো
        sprintf(text, "(%d,%d)", px, py);

        // screen এ show
        outtextxy(px+5, py+5, text);

        x += xinc;
        y += yinc;
        delay(50);
    }

    getch();
    closegraph();
}*/
