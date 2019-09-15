#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;
int main()
{  int gm,gd,i,j,n,x[20],y[20],k,temp_x,y_,x_int[20];
  float dy,dx,slope[20];
    
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
    for(i=0;i<n;i++)
    {
        line(x[i],y[i],x[i+1],y[i+1]);
    }
    for(i=0;i<n;i++)
    {
        dy=y[i+1]-y[i];
        dx=x[i+1]-x[i];
        if(dy==0)
        {
            slope[i]=1;
        }
        else if(dx==0)
        {
        slope[i]=0;
        }
        else
        slope[i]=dx/dy;
    }
    for(y_=0;y_<getmaxy();y_++)
{
    k=0;
    for(i=0;i<n;i++)
    {
        if (((y[i]<=y_)&&(y[i+1]>y_))||((y[i]>y_) && (y[i+1]<=y_)))
        {
            x_int[k]=(x[i]+(slope[i]*(y_-y[i])));
            k++;
        }
    }
    

for(i=0;i<k-1;i++)
  {for(j=0;j<k-1;j++)
  {
    if(x_int[j]>x_int[j+1])
    {
        temp_x=x_int[j];
        x_int[j]=x_int[j+1];
        x_int[j+1]=temp_x;
        
    }
  }
  }



  setcolor(RED);


  for(i=0;i<k;i=i+2)
  {
      line(x_int[i],y_,x_int[i+1],y_);
  }
 
}

    getch();
    closegraph();
    
    return 0;
}
