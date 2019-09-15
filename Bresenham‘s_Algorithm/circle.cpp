#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

class circle1
{
public :
float x,y;
int r,d;
float x1,y1,x2,y2,dx,dy,length,i;
void draw_bresenham(int i);


};
void circle1::draw_bresenham(int i)
{
    r=i;
    x=0;
    y=r;
    d=3-(2*r);
    
    while(x<y)
    {
    
        putpixel(200+x,200+y,RED);
        delay(100);
        putpixel(200+y,200+x,RED);
        putpixel(200+y,200-x,RED);
        putpixel(200+x,200-y,RED);
        putpixel(200-x,200+y,RED);
        putpixel(200-y,200+x,RED);
        putpixel(200-y,200-x,RED);
        putpixel(200-x,200-y,RED);
        if(d<0)
        {
        d=d+(4*x+6)    ;
        }
        else
        {
        d=d+(4*(x-y))+10;
        y=y-1;    
        }
        x=x+1;
    }
    

}

int main()
{   
    circle1 obj[5];
    int gm,gd,i;
    gd=DETECT;
    //cout<<"Enter the radius ";
    //cin>>i;
    i=100;
    initgraph(&gd,&gm,NULL);
    obj[0].draw_bresenham(i);
    getch();
    closegraph();
    return 0;    
}



