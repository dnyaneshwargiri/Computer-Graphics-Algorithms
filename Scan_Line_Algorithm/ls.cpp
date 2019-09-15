
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
 class draw
 { public:
     int x1,y1,x2,y2,length,length1,length2,i;
     float Dx,Dy,x,y;
     float w,wy,wx;
     
     void getvalue()
     {   cout<<"Enter x1";
         cin>>x1;
         cout<<"Enter y1";
         cin>>y1;
         cout<<"\nEnter x2";
         cin>>x2;
         cout<<"\nEnter x2";
         cin>>y2;
         
     }
     void drawline_dda_doted()
     {
		 x1=x1-20;
		 x2=x2-20;
		 y1=y1+20;
		 y2=y2+20;
		 
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
          {
			   
		 if (i%2==0 )
         {   
			 
			 
	     } 
        else
        
          {
		 
			  putpixel(x,y,RED);
             
		  }
		    x=x+Dx;
             y=y+Dy;
             i++; 
          }
       }
		 
		
     void drawline_dda_solid()
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
     
     
     void drawline_dda_dashed()
     {
         x1=x1-20;
		 x2=x2-20;
		 y1=y1+20;
		 y2=y2+20;
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
        
          { /* if(i%9==0)*/
              if(i%9>4)
              {
             
              }
              else
              {
                   putpixel(x,y,RED);
              }
              x=x+Dx;
              y=y+Dy;
             i++; 
          }
         
         
     }
      void drawline_dda_dashed_dotted()
     {
       	 x1=x1-20;
		 x2=x2-20;
		 y1=y1+20;
		 y2=y2+20;
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
        
          {  if(i%9<2) 
			  {}
			  
              else if(i%9<6)
              putpixel(x,y,RED);
              
              else if(i%9==7) 
              {}
              
              else
              putpixel(x,y,RED);
              x=x+Dx;
              y=y+Dy;
              i++; 
          }
         
         
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
     {x1=x1-20;
		 x2=x2-20;
		 y1=y1+20;
		 y2=y2+20;
      
      w=5;
     wy=((w-1)/2)*((((x2-x1)^2)+((y2-y1)^2))^1/2)/(x2-x1);
     wx=((w-1)/2)*((((x2-x1)^2)+((y2-y1)^2))^1/2)/(y2-y1);
     if(x2-x1==0)
     {for(int i=1;i<=wx;i++)
    {
     drawline_dda_solid(x1+i,y1,x2+i,y2);
     drawline_dda_solid(x1,y1,x2,y2);
     drawline_dda_solid(x1-i,y1,x2-i,y2);
    }
		 }
		 else{
     for(int i=1;i<=wy;i++)
    {
     drawline_dda_solid(x1,y1+i,x2,y2+i);
     drawline_dda_solid(x1,y1,x2,y2);
     drawline_dda_solid(x1,y1-i,x2,y2-i);
    }}
    
}
     
};

        
        
     
     int main()
     {
         int gd,gm;
         draw obj;
         gd=DETECT;
         obj.getvalue();
         initgraph(&gd,&gm,NULL);
   
          obj.drawline_dda_solid();
          obj.drawline_dda_doted();
           obj.drawline_dda_dashed();
          obj.drawline_dda_dashed_dotted();
         obj.drawline_dda_thick();
       
         getch();
         closegraph();
         return 0;
      }
