
#include<iostream>
#include<graphics.h>

using namespace std;

int main()

{
    int gd,gm,mx,my,i;
    gd=DETECT;
    initgraph(&gd,&gm,NULL);
    mx=getmaxx();
    my=getmaxy();
   // bar(190,20,200,400);
    circle(195,15,5);
    for(int i=0;i<150;i=i+10)
    {cleardevice();
    setcolor(WHITE);
    bar(190,20,200,400);
    circle(195,15,5);
    floodfill(195,15,WHITE);
    setcolor(12);
    bar(200,200-i, 400,250-i);
    setcolor(WHITE);
    bar(200,250-i, 400,300-i);
    setcolor(GREEN);
    bar(200,300-i,400,350-i);
    setcolor(BLUE);
    circle(300,275-i,25);
    floodfill(300,275-i,BLUE);
    //bar(100,450,290,450);
    delay(100);
    }
    //rectangle(100,400,400,300);
   /*for(int i=0;i<mx;i=i+10)
    {cleardevice();
    rectangle(150+i,200, 300+i, 350);
    delay(10);
    }*/
    //rectangle(150,200, 300, 350);
    //ellipse(200, 400, 60,55,900,600);
    //circle(0,0,100);
    getch();
    closegraph();
    return 0;
}


