#include <graphics.h>
#include <iostream>
using namespace std;

// Window
double xmin=150, ymin=150, xmax=250, ymax=250;

// Check inside
bool inside(double x, double y, int edge) {
    if(edge==0) return x >= xmin; // LEFT
    if(edge==1) return x <= xmax; // RIGHT
    if(edge==2) return y >= ymin; // BOTTOM
    return y <= ymax;             // TOP
}

// Find intersection
void intersect(double x1,double y1,double x2,double y2,int edge,double &x,double &y) {
    double m = (y2-y1)/(x2-x1+0.00001);

    if(edge==0){ x=xmin; y=y1+m*(xmin-x1); }
    if(edge==1){ x=xmax; y=y1+m*(xmax-x1); }
    if(edge==2){ y=ymin; x=x1+(ymin-y1)/m; }
    if(edge==3){ y=ymax; x=x1+(ymax-y1)/m; }
}

int main() {
    int gd=DETECT, gm;
    initgraph(&gd,&gm,NULL);

    // polygon (triangle)
    double x[10]={100,200,300};
    double y[10]={150,250,200};
    int n=3;

    // draw window
    rectangle(xmin,ymin,xmax,ymax);

    // draw original polygon
    setcolor(RED);
    for(int i=0;i<n;i++)
        line(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);

    // clipping
    for(int edge=0; edge<4; edge++){
        double newx[10], newy[10];
        int k=0;

        for(int i=0;i<n;i++){
            double x1=x[(i+n-1)%n], y1=y[(i+n-1)%n];
            double x2=x[i], y2=y[i];

            if(inside(x2,y2,edge)){
                if(!inside(x1,y1,edge)){
                    intersect(x1,y1,x2,y2,edge,newx[k],newy[k]);
                    k++;
                }
                newx[k]=x2; newy[k]=y2; k++;
            }
            else if(inside(x1,y1,edge)){
                intersect(x1,y1,x2,y2,edge,newx[k],newy[k]);
                k++;
            }
        }

        // update polygon
        n=k;
        for(int i=0;i<n;i++){
            x[i]=newx[i];
            y[i]=newy[i];
        }
    }

    // draw clipped polygon
    setcolor(GREEN);
    for(int i=0;i<n;i++)
        line(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);

    getch();
    closegraph();
}
