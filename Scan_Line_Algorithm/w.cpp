
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
 class draw
 {public:
     int x1,y1,x2,y2,length,length1,length2,i;
     float w,wy;
     float Dx,Dy,x,y;
     void getvalue()
     {   cout<<"Enter x1";
         cin>>x1;
         cout<<"Enter y1";
         cin>>y1;
         cout<<"\nEnter x2";
         cin>>x2;
         cout<<"\nEnter x2";
         cin>>y2;
        
      cout<<"\nEnter w";
      cin>>w;
        
     }
     void drawline_dda_solid(int x1,int y1,int x2,int y2)
     {
      
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
     void drawline_dda_thick()
     {
      
          
     wy=((w-1)/2)*((((x2-x1)^2)+((y2-y1)^2))^1/2)/(x2-x1);
     for(int i=1;i<=wy;i++)
    {
     drawline_dda_solid(x1,y1+i,x2,y2+i);
     drawline_dda_solid(x1,y1,x2,y2);
     drawline_dda_solid(x1,y1-i,x2,y2-i);
    }
        
        
     }
    
};
     int main()
     {
         int gd,gm;
         draw obj;
         gd=DETECT;
         obj.getvalue();
         initgraph(&gd,&gm,NULL);
         obj.drawline_dda_thick();
         getch();
         closegraph();
         return 0;
    }
