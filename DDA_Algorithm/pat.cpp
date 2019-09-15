
#include<iostream>
#include<graphics.h>
using namespace std;
class Draw
{

public:
float x1,y1,x2,y2,x3,y3,x4,y4;
void drawdds(int x1,int y1,int x2,int y2);                             //DDA

void getval1();
void getval2();
void getval3();
void getval4();
void rect(int x1,int y1,int x2,int y2);
};
void Draw::rect(int x1,int y1,int x2,int y2)
{
    int a,b,c1,d1,c2,d2,g,h,i;
    
    drawdds( x1, y1, x2, y1); //top
    drawdds( x1, y2, x2, y2); //bottom
    drawdds(x1, y1, x1, y2); //left
    drawdds( x2, y1, x2, y2); //right
    
    a=(x1+x2)/2;//topmid
    b=(y1+y2)/2; //leftmid
{
    drawdds(x1,b,a,y1); 
    drawdds(x1,b,a,y2); 
    drawdds(a,y1,x2,b); 
    drawdds(a,y2,x2,b); 
}

 c1=(x1+a)/2;//topleft  x
d1=(b+y1)/2;//top left y
c2=(a+x2)/2;//bottom right x
d2=(y2+b)/2;//top right y

drawdds(c1,d1,c2,d1); 
drawdds(c1,d2,c2,d2); 
drawdds(c1,d1,c1,d2); 
drawdds(c2,d1,c2,d2); 

}
void Draw::getval1()
{
    cout<<"\n Enter X1,Y1";
    cin>>x1>>y1;

}
void Draw::getval2()
{
    cout<<"\n Enter X2,Y2";
    cin>>x2>>y2;
}
void Draw::getval3()
{
    cout<<"\n Enter X3,Y3";
    cin>>x3>>y3;

}
void Draw::getval4()
{
    cout<<"\n Enter X4,Y4";
    cin>>x4>>y4;

}
void Draw::drawdds(int x1,int y1,int x2,int y2)   //DDA
{
    float x,y,dx,dy;
    int i,len;
if(abs(x2-x1)>=abs(y2-y1))
{
    len=(x2-x1);
}
else
{
    len=(y2-y1);
}
dx=(x2-x1)/len;
dy=(y2-y1)/len;

x=x1+0.5;
y=y1+0.5;

i=0;
setcolor(RED);
while(i<=len)
{
    putpixel(x,y,RED);
    x=x+dx;
    y=y+dy;
    i++;
}
}


int main()

{
Draw p;

int gd,gm;
gd=DETECT;
cout<<"\n Enter 1st point=";
p.getval1();
cout<<"\n Enter 2nd point=";
p.getval2();
/*cout<<"\n Enter 3rd point=";
p.getval3();
cout<<"\n Enter 4th point=";
p.getval4();*/
initgraph(&gd,&gm,NULL);

p.rect(p.x1,p.y1,p.x2,p.y2);

delay(100);

getch();
closegraph();
return 0;
}
