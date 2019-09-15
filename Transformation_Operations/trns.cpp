#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

class mat
{
    public:
    int p,q;
    
    int m,a[20][20],c[20][20],i,j,k;
    public:
    void mul(double b[20][20]);
    void objectDraw();
    void objectDraw1();
    void accept();
    void display();
    void display1();
    void operator * (double b[20][20]);
};
void mat :: operator * (double b[20][20])
{
	 for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            c[i][j]=0;
            for(int k=0;k<m;k++)
            {
                c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
            }
        }
    }
	
}
/*void mat::mul(double b[20][20])
{
  
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            c[i][j]=0;
            for(int k=0;k<m;k++)
            {
                c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
            }
        }
    }
  
}*/

void mat::objectDraw()
{
    for( i=0;i<m-1;i++)
    {
      
        line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
    }
  
    line(a[0][0],a[0][1],a[i][0],a[i][1]);  
}
void mat::objectDraw1()
{   
    for( i=0;i<m-1;i++)
    {
      
        line(a[i][0]+p,a[i][1]+q,a[i+1][0]+p,a[i+1][1]+q);
    }
  
    line(a[0][0]+p,a[0][1]+q,a[i][0]+p,a[i][1]+q);  
}

void mat::accept()
{
    cout<<"Enter no of edges";
    cin>>m;
    cout<<"\nEnter matrix";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(j==2)
            { a[i][j]=1;
            continue; }
            else
            cin>>a[i][j];
        }
    }
}

void mat::display()
{
  
for( i=0;i<m-1;i++)
    {
      
        line(c[i][0],c[i][1],c[i+1][0],c[i+1][1]);
    }
  
    line(c[0][0],c[0][1],c[i][0],c[i][1]);  
}
void mat::display1()
{
    p=getmaxx()/2;
    q=getmaxy()/2;
for( i=0;i<m-1;i++)
    {
      
        line(c[i][0]+p,c[i][1]+q,c[i+1][0]+p,c[i+1][1]+q);
    }
  
    line(c[0][0]+p,c[0][1]+q,c[i][0]+p,c[i][1]+q);  
}

int main()
{
    int gd,gm;
    gd=DETECT;
    int ch,tx,ty,sx,sy,a,shx,shy;
    double deg,theta,b[20][20];
    mat t;
   t.accept();
   initgraph(&gd,&gm,NULL);
        cout<<"\nEnter your choice";
        cout<<"\n1.Translation\n2.Scaling\n3.Rotation\n4.shear\t\n5.Reflection";
        cin>>ch;
      
        switch(ch)
        {
     case 1:   cout<<"\nTRANSLATION\n";
               cout<<"Enter value for tx,ty";
               cin>>tx;
               cin>>ty;
               b[0][0]=b[2][2]=b[1][1]=1;
               b[0][1]=b[0][2]=b[1][0]=b[1][2]=0;
               b[2][0]=tx;
               b[2][1]=ty;
              // t.mul(b);
                t*b;
               t.objectDraw();
               t.display();
              
               break;
        
     case 2:   cout<<"\nSCALING\n";
               cout<<"Enter value for sx,sy";
               cin>>sx;
               cin>>sy;
               b[0][0]=sx;
               b[1][1]=sy;
               b[0][1]=b[0][2]=b[1][0]=b[1][2]=0;
               b[2][0]=b[2][1]=0;
              // t.mul(b);
               t*b;
               t.objectDraw();
               t.display();
            
               break;
   case 3:     cout<<"\nROTATION\n";
               cout<<"Enter value for angle";
               cin>>deg;
               theta=deg*(3.14/360);
               b[0][0]=b[1][1]=cos(theta);
               b[0][1]=sin(theta);
               b[1][0]=-sin(theta);
               b[1][1]=cos(theta);
               b[0][2]=b[1][2]=b[2][0]=b[2][1]=0;
               b[2][2]=1;
               //t.mul(b);
               t*b;
               t.objectDraw();
               t.display();
             
               break;
    case 4:
        cout<<"\nSHEAR\n";
        cout<<"Enter choice \n1 X shear\n2. Y shear\n3.Both";
        cin>>a; 
        if(a==1)
        {
        cout<<"Enter value for Shx";
        cin>>shx;
         b[0][0]=b[1][1]=b[2][2]=1;
         b[1][0]=shx;
         b[1][1]=1;
         b[0][1]=b[0][2]=b[1][2]=b[2][0]=b[2][1]=0;
        // t.mul(b);
          t*b;
         t.objectDraw();
         t.display();
        }
        if (a==2)
        {
        cout<<"Enter value for Shy";
        cin>>shy;
        b[0][0]=b[1][1]=b[2][2]=1;
        b[0][1]=shy;
        b[1][0]=b[0][2]=b[1][2]=b[2][0]=b[2][1]=0;
        //t.mul(b);
         t*b;
        t.objectDraw();
        t.display();
        }
        else
        cout<<"Enter value for shx & Shy";
        cin>>shx;
        cin>>shy;
        b[0][0]=b[1][1]=b[2][2]=1;
        b[1][0]=shx;
        b[0][1]=shy;
        b[0][2]= b[1][2]= b[2][0]= b[2][1]=0;
       // t.mul(b);
         t*b;
        t.objectDraw();
        t.display();
    case 5:
    cout<<"\nREFLECTION\n";
    cout<<"Enter choice \n1. About X \n2. About Y \n3.About origin\n4.About y=x\n5.About y=-x";
    cin>>a;
    switch(a)
    {
    case 1:
     b[0][0]=b[2][2]=1;
     b[1][1]=-1;
     b[0][1]=b[1][0]=b[0][2]= b[1][2]= b[2][0]= b[2][1]=0;
   // t.mul(b);
    t*b;
    t.objectDraw();
    t.display();
    break;
    case 2:
     b[2][2]=b[1][1]=1;
     b[0][0]=-1;
     b[0][1]=b[1][0]=b[0][2]= b[1][2]= b[2][0]= b[2][1]=0;
   // t.mul(b);
    t*b;
    t.objectDraw();
    t.display();
    break;
  case 3:
    b[0][0]=b[1][1]=-1;
    b[2][2]=1;
    b[0][1]=b[1][0]=b[0][2]= b[1][2]= b[2][0]= b[2][1]=0;
    //t.mul(b);
     t*b;
    t.objectDraw();
    t.display();
    break;
  case 4:
    b[0][1]=b[1][0]=b[2][2]=1;
    b[0][1]=b[0][2]= b[1][2]=b[1][1]= b[2][0]= b[2][1]=0;
  //  t.mul(b);
   t*b;
    t.objectDraw1();
    t.display1();
    break;
  case 5:
    b[0][1]=b[1][0]=b[2][2]=-1;
    b[0][1]=b[0][2]= b[1][2]=b[1][1]= b[2][0]= b[2][1]=0;
    //t.mul(b);
     t*b;
    t.objectDraw1();
    t.display1();
    break;
    
    }
      
}
getch();
closegraph();
return 0;
}
