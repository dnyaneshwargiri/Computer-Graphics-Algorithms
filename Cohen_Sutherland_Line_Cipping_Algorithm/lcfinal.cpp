

#include<iostream>
#include<graphics.h>
using namespace std;
class clip
{ 
    public:
    int x1, y1, x2, y2,xmin, ymin, xmax, ymax;
    void getwindow()
    {
        xmax=500;
        xmin=100;
        ymax=300;
        ymin=100;    
    /*cout<<"\n enter co-ord. of screen : ";
    cin>>xmin>>ymin>>xmax>>ymax;*/
    cout<<"\n enter end-points of line : ";
    cin>>x1>>y1>>x2>>y2;    
    rectangle(xmin, ymin, xmax, ymax);
    line(x1,y1,x2,y2);
    getch();
    }    
    void  visible(int,int,int,int,int,int,int,int);
    void  cut(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);
};

void clip::visible(int x1,int y1,int x2,int y2,int xmin,int ymin,int xmax,int ymax)
 {
 int  a1, a2, a3, a4, b1, b2, b3, b4,c1, c2, c3, c4;
 int qa, qb;
 if(x1<xmin)
 {
  a3 = 0; a4 = 1;
 }
 if(x1>xmin && x1<xmax)
 {
  a3 = 0; a4 = 0;
 }
 if(x1>xmax)
 {
  a3 = 1; a4 = 0;
 }
 if(y1<ymin)
 {
	 a1 = 1; a2 = 0;
  //a1 = 0; a2 = 1;
 }
 if(y1>ymin && y1<ymax)
 {
	
 a1 = 0; a2 = 0;
 }
 if(y1>ymax)
 {a1 = 0; a2 = 1;
 // a1 = 1; a2 = 0;
 }
 if(x2<xmin)
 {
  b3 = 0; b4 = 1;
 }
 if(x2>xmin && x2<xmax)
 {
  b3 = 0; b4 = 0;
 }
 if(x2>xmax)
 {
  b3 = 1; b4 = 0;
 }
 if(y2<ymin)
 {b1 = 1; b2 = 0;
  //b1 = 0; b2 = 1;
 }
 if(y2>ymin && y2<ymax)
 {
  b1 = 0; b2 = 0;
 }
 if(y2>ymax)
 { b1 = 0; b2 = 1;
  //b1 = 1; b2 = 0;
 }
 if(a1 == 0 && a2 == 0 && a3 == 0 && a4 == 0)
 {
  qa = 5;
 }
 if(b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0)
 {
  qb = 5;
 }
 c1 = a1&b1;
 c2 = a2&b2;
 c3 = a3&b3;
 c4 = a4&b4;
 if(c1 == 0 && c2 == 0 && c3 == 0 && c4 == 0)
 {
  if(a1 == 0 && a2 == 0 && a3 == 0 && a4 == 0 && b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0)
    cout<<"\n line is completely inside";
   else
   {
    cout<<"\n line is partially inside";
    cut(x1,y1,x2,y2,xmin,ymin,xmax,ymax,qa,qb,b3,b4,b2,b1,a1,a2,a3,a4);
   }
  }
 else
   cout<<"\n line is completely outside";
   getch();
}

void clip::cut(int x1,int y1,int x2,int y2,int xmin,int ymin,int xmax,int ymax,int qa,int qb,int b3,int b4,int b2,int b1,int a1,int a2,int a3,int a4)
{
int xint1, yint1, xint2,  yint2;
cleardevice();
if(x2-x1 == 0 || y2-y1 == 0)
{
 if(x2 - x1 == 0) //if vertical line
 {
  if(qa == 5)
 {  if(y2>=ymax)
	line(x1,y1,x2,ymax);
	if(y2<=ymin)
	line(x1,y1,x2,ymin);
   
}
   if(qb == 5)
  {  if(y1>=ymax)
	line(x1,ymax,x2,y2);
	if(y1<=ymin)
	line(x1,ymin,x2,y2);
  }
  if(y1<=ymin && y2>=ymax)
    line(x1,ymin, x2, ymax);
  
 }
 if(y2 - y1 == 0)  //if horizontal line
 {
  if(qa == 5)
  {
   if(x2>=xmax)
	line(x1,y1,xmax,y2);
	if(x2<=xmin)
	line(x1,y1,xmin,y2);
			}
  if(qb == 5)
  {
  if(x1>=xmax)
				line(xmax,y1,x2,y2);
				if(x2<=xmin)
				line(xmin,y1,x2,y2);
 }
  if(x1<=xmin && x2>=xmax)
  line(xmin, y1, xmax, y2);
 }
}
else
{
    xint1 = abs(((x2-x1)*(ymin-y1)/(y2-y1))+x1);  //top x intersection pt 
    xint2 = abs(((x2-x1)*(ymax-y1)/(y2-y1))+x1);  //bottom x intersection pt
    yint1 = abs(((xmin-x1)*(y2-y1)/(x2-x1))+y1);  // left y intersection pt
    yint2 = abs(((xmax-x1)*(y2-y1)/(x2-x1))+y1); //right y intersection pt
    
 if(qa == 5 || qb == 5)
 {
	
 if(qa == 5)
  {
	  if(b1==1 && b3==1)
   {
     line(x1, y1, xint1, ymin);
     
    
   }
  else if(b1==1 && b4==1)
   {
     line(x1, y1, xmin, yint1);
    
   }
  else if(b2==1 && b4==1)
   {
     line(x1, y1, xint2, ymax);
    
   }
  else if(b2==1 && b3==1)
   {
     line(x1, y1, xint2, ymax);
    
   }
	else if(b3==1 && b1==0 && b2==0)
   {
     line(x1, y1, xmax, yint2);
   }
   
   
   else if(b4==1 && b1==0 && b2==0 )
   {   
   line(x1, y1, xmin, yint1);
   
   }
    else if(b2==1 && b3==0 && b4==0)
   {
      line(x1,y1,xint2,ymax); 
      
   }
   else if(b1==1  && b3==0 && b4==0)
   { 
    line(x1,y1,xint1,ymin);
     
   }
  }
 if(qb == 5)
 {
   if(a1==1 && a3==1)
   {
     line(x2, y2, xint1, ymin);
    
   }
  else if(a1==1 && a4==1)
   {
     line(x2, y2, xmin, yint1);
    
   }
  else if(a2==1 && a4==1)
   {
     line(x2, y2, xint2, ymax);
    
   }
  else if(a2==1 && a3==1)
   {
     line(x2, y2, xint2, ymax);
    
   }
	else if(a3==1 && a1==0 && a2==0)
   {
     line(x2, y2, xmax, yint2);
   }
   
   
   else if(a4==1 && a1==0 && a2==0 )
   {   
   line(x2, y2, xmin, yint1);
   
   }
    else if(a2==1 && a3==0 && a4==0)
   {
      line(x2,y2,xint2,ymax); 
      
   }
   else if(a1==1  && a3==0 && a4==0)
   { 
    line(x2,y2,xint1,ymin);
     
   }
}
}
  
 
 else
 {
 if(xint1>=xmin && xint1<=xmax)  // upper line intersection
  {
  if(yint2>=ymin && yint2<=ymax)
    line(xint1, ymin, xmax, yint2);
  if(yint1>=ymin &&yint1<=ymax)
    line(xint1,ymin,xmin,yint1);
  if(xint2>=xmin && xint2<=xmax)
    line(xint2,ymax,xint1,ymin);  
  }
  if(xint2>=xmin && xint2<=xmax) //lower line intersection
  {
      if(yint2>=ymin && yint2<=ymax)
      line(xint2,ymax,xmax,yint2);
      if(yint1>=ymin && yint1<=ymax)
      line(xint2,ymax,xmin,yint1); 
  }   
 }
 }
 rectangle(xmin, ymin, xmax, ymax);
 getch();
}

int main()
{
clip p;
int gd = DETECT, gm;
  initgraph(&gd, &gm,NULL);
  cleardevice();
  p.getwindow();
  p.visible(p.x1,p.y1,p.x2,p.y2,p.xmin,p.ymin,p.xmax,p.ymax);
  getch();
  closegraph();
  return 0;
}




