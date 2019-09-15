#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

void BoundaryFill4(int x, int y, int newcolor, int edgecolor)
{
int current;
current = getpixel(x, y);
if(current != edgecolor && current != newcolor)
{
putpixel(x,y,newcolor);
BoundaryFill4(x, y-1, newcolor, edgecolor);
BoundaryFill4(x+1, y, newcolor, edgecolor);
BoundaryFill4(x, y+1, newcolor, edgecolor);
BoundaryFill4(x-1, y, newcolor, edgecolor);


}
}

int main()
{  int gm,gd,i,n,x[20],y[20];

    
    cout<<"Enter the no of edges of polygon";
    cin>>n;
    for(i=0;i<n;i++)
    {cout<<"Enter the coordinates of edge x"<<i<<"  y"<<i;
     cin>>x[i];
     cin>>y[i];
    }
    x[n]=x[0];
    y[n]=y[0];
    gd=DETECT;
    initgraph(&gd,&gm,NULL);
   setcolor(RED);
   for(i=0;i<n;i++)
    {
        line(x[i],y[i],x[i+1],y[i+1]);
    }
  BoundaryFill4(100,150, YELLOW, RED);
  getch();
   closegraph();
    
    return 0;
}

    

