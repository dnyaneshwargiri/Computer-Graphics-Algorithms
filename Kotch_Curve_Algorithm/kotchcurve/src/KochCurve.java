
import java.awt.Graphics;
import javax.swing.JApplet;
import javax.swing.JOptionPane;
public class KochCurve extends JApplet 
{
    int depth;
    public void init()
{
    
    String obj = JOptionPane.showInputDialog("Enter the depth");
    depth=Integer.parseInt(obj);
}
    @Override
    
public void paint(Graphics g)
{
     drawCurve(g,depth,280,150,150,150);
}
public void drawCurve(Graphics g,int dep, int x1, int y1, int x5, int y5 )
{
      int deltaX, deltaY, x2, y2, x3, y3, x4, y4;
      
      if (dep == 0){

          g.drawLine(x1, y1, x5, y5);
      }
      else{
            deltaX = x5 - x1;
            deltaY = y5 - y1;

            x2 = x1 + deltaX / 3;
            y2 = y1 + deltaY / 3;

            x3 = (int) (0.5 * (x1+x5) + Math.sqrt(3) * (y1-y5)/6);
            y3 = (int) (0.5 * (y1+y5) + Math.sqrt(3) * (x5-x1)/6);

            x4 = x1 + 2 * deltaX /3;
            y4 = y1 + 2 * deltaY /3;

            drawCurve (g,dep-1, x1, y1, x2, y2);
            drawCurve (g,dep-1, x2, y2, x3, y3);
            drawCurve (g,dep-1, x3, y3, x4, y4);
            drawCurve (g,dep-1, x4, y4, x5, y5);
}
    

}

}
