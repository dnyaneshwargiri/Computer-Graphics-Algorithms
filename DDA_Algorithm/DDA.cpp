
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
 class pixel
 {   public:
     int x1,y1,x2,y2,length,length1,length2,i;
     float Dx,Dy,x,y;
     void getvalue()
     {   cout<<"Enter x1";
         cin>>x1;
         cout<<"Enter y1";
         cin>>y1;
         cout<<"\nEnter x2";
         cin>>x2;
         cout<<"\nEnter y2";
         cin>>y2;
         
     }
     void drawline()
     {
        
         /*x1=y1=20;
         x2=y2=200;*/
         length1=abs(x2-x1);
         length2=abs(y2-y1);
          if(length1>length2)
          {
            length=length1;  
          }
          else {length=length2;}
          
          Dx=(x2-x1)/length;
          Dy=(y2-y1)/length;
          x=x1+0.5;
          y=y1+0.5;
          i=0;
          while(i<length)
          {putpixel(x,y,RED);
              x=x+Dx;
              y=y+Dy;
             i++;  
          }
          
         
     }
      void drawline(int x1,int y1,int x2,int y2)
     {
		 float e;
        Dx=abs(x2-x1);
        Dy=abs(y2-y1);
        x=x1;
        y=y1;
        e=2*Dy-Dx;
        putpixel(x,y,RED);
        for(i=0;i<=Dx;i++)
        {
            while(e>=0)
            {y++;
             e=e-2*Dx;
            }
            x=x+1;
            e=e+(2*Dy);
            putpixel(x,y,RED);
            
        } 
     }
     
};
class dda:public pixel
{
	
};
class bresen :public pixel
{
	
};

     int main()
     {
         int gd,gm;
       
         dda d;
         bresen b;
         gd=DETECT;
        d.getvalue();
        b.getvalue();
         initgraph(&gd,&gm,NULL);
    
         d.drawline();
        // 
         //cleardevice();
         b.drawline(b.x1,b.y1,b.x2,b.y2);
       // delay(10000);
         closegraph();
         getch();
         return 0;
         }
