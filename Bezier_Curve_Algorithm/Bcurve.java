import java.awt.*;
import java.applet.*;



public class Bcurve extends Applet {
    
    public
    float x,y;
    int n;
    

    public void paint(Graphics g)
    {
 
      /* x=100;
       y=200;
       bezier(150,50,200,50,250,200,4);
       x=250;
       y=200;
       bezier(300,350,350,350,400,200,4);*/
          x=100;
           y=100;
         
          bezier(50,200,50,80,100,100,4);
             bezier(60,30,160,30,100,100,4);
          bezier(180,50,200,150,100,100,4);
          bezier(140,120,120,140,100,200,4);
           /*x=250;
           y=200;
           bezier(300,350,350,350,400,200,4);*/
    }

    public void line1(float x2, float y2) 
    {
        Graphics g1 = getGraphics();
        g1.drawLine((int)x,(int)y,(int)x2,(int) y2);
        x = x2;
        y = y2;
    }



    public  void bezier(float xb, float yb, float xc, float yc, float xd, float yd, int n) {
        {
        float xab, yab, xbc, ybc, xcd, ycd;
        float xabc, yabc, xbcd, ybcd;
        float xabcd, yabcd;
        Graphics g = getGraphics();
        
        if(n == 0) {
            line1(xb, yb);
            line1(xc, yc);
            line1(xd, yd);
        } else {
            xab = (x + xb) / 2;
            yab = (y + yb) / 2;
            xbc = (xb + xc) / 2;
            ybc = (yb + yc) / 2;
            xcd = (xc + xd) / 2;
            ycd = (yc + yd) / 2;
            xabc = (xab + xbc) / 2;
            yabc = (yab + ybc) / 2;
            xbcd = (xbc + xcd) / 2;
            ybcd = (ybc + ycd) / 2;
            xabcd = (xabc + xbcd) / 2;
            yabcd = (yabc + ybcd) / 2;
            n = n - 1;
            bezier(xab, yab, xabc, yabc, xabcd, yabcd, n);
            bezier(xbcd, ybcd, xcd, ycd, xd, yd, n);
        }
    }

    
        
        
        
    }

    
}
