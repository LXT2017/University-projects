package TankGame;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.event.KeyEvent;
import java.util.Random;

import javax.swing.JPanel;

public class MyTank extends JPanel {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	int op=0;    //控制方向
	int x=120,y=380;
	int hitx,hity;
	int xspeed=5;
	int yspeed=5;
	int i;
	private boolean live = true;  //判断坦克是否存活
	private Random r = new Random();//设置一个随机值变量
	private int step = r.nextInt(12)+3;  //敌方坦克随机移动步骤3-14步
	private TankClient tc;  //主类权限
	
	public int Isgood() {
		return i;
	}
	
	public boolean isLive() {
		return live;
	}
	public MyTank(TankClient tc,int i) {
		// TODO Auto-generated constructor stub
		this.tc=tc;
		this.i=i;
	}
	public MyTank(int x,int y,int i,int op,TankClient tc) {
		this.tc=tc;
		this.i=i;
		this.x=x;
		this.y=y;
		this.op=op;
		this.tc=tc;
	}
	
	public void setlive(boolean live) {
		this.live=live;
	}
	public void drawTank(Graphics g, int op, int x, int y, int i) {
        if (i == 1) {
            g.setColor(Color.yellow);//我方黄色,敌方红色
        } else {
            g.setColor(Color.red);
        }

        if (op == 0) {
        	hitx=x + 15;
        	hity=y - 20;
            g.fillRect(x, y, 40, 40); //坦克体
            g.setColor(Color.black);
            g.drawRect(x + 10, y + 5, 20, 20);//轮廓
            g.drawRect(x, y, 40, 40);
            g.drawRect(x - 5, y - 5, 10, 50);//左右两侧履带
            g.fillOval(x - 5, y - 5, 10, 10);
            g.fillOval(x - 5, y + 5, 10, 10);
            g.fillOval(x - 5, y + 15, 10, 10);
            g.fillOval(x - 5, y + 25, 10, 10);
            g.fillOval(x - 5, y + 35, 10, 10);
            g.drawRect(x + 35, y - 5, 10, 50);
            g.fillOval(x + 35, y - 5, 10, 10);
            g.fillOval(x + 35, y + 5, 10, 10);
            g.fillOval(x + 35, y + 15, 10, 10);
            g.fillOval(x + 35, y + 25, 10, 10);
            g.fillOval(x + 35, y + 35, 10, 10);
            g.fillRect(hitx, hity, 10, 40); //炮口
            g.fillOval(x + 5, y + 30, 10, 10); //天线
            g.fillOval(x + 25, y + 30, 10, 10);
        }// end of if ( op == 1 )

        if (op == 1) {
        	hitx=x+20;
        	hity=y+15;
            g.fillRect(x, y, 40, 40);
            g.setColor(Color.black);
            g.drawRect(x + 15, y + 10, 20, 20);
            g.drawRect(x, y, 40, 40);
            g.drawRect(x - 5, y - 5, 50, 10);
            g.fillOval(x - 5, y - 5, 10, 10);
            g.fillOval(x + 5, y - 5, 10, 10);
            g.fillOval(x + 15, y - 5, 10, 10);
            g.fillOval(x + 25, y - 5, 10, 10);
            g.fillOval(x + 35, y - 5, 10, 10);
            g.drawRect(x - 5, y + 35, 50, 10);
            g.fillOval(x - 5, y + 35, 10, 10);
            g.fillOval(x + 5, y + 35, 10, 10);
            g.fillOval(x + 15, y + 35, 10, 10);
            g.fillOval(x + 25, y + 35, 10, 10);
            g.fillOval(x + 35, y + 35, 10, 10);
            g.fillRect(hitx, hity, 40, 10);
            g.fillOval(x, y + 5, 10, 10);
            g.fillOval(x, y + 25, 10, 10);
        }// end of if (op==2)

        if (op == 2) {
        	hitx=x+15;
        	hity=y+20;
            g.fillRect(x, y, 40, 40);
            g.setColor(Color.black);
            g.drawRect(x + 10, y + 15, 20, 20);
            g.drawRect(x, y, 40, 40);
            g.drawRect(x - 5, y - 5, 10, 50);
            g.fillOval(x - 5, y - 5, 10, 10);
            g.fillOval(x - 5, y + 5, 10, 10);
            g.fillOval(x - 5, y + 15, 10, 10);
            g.fillOval(x - 5, y + 25, 10, 10);
            g.fillOval(x - 5, y + 35, 10, 10);
            g.drawRect(x + 35, y - 5, 10, 50);
            g.fillOval(x + 35, y - 5, 10, 10);
            g.fillOval(x + 35, y + 5, 10, 10);
            g.fillOval(x + 35, y + 15, 10, 10);
            g.fillOval(x + 35, y + 25, 10, 10);
            g.fillOval(x + 35, y + 35, 10, 10);
            g.fillRect(hitx, hity, 10, 40);
            g.fillOval(x + 5, y, 10, 10);
            g.fillOval(x + 25, y, 10, 10);
        } //end of if ( op == 3 )

        if (op == 3) {
        	hitx=x-20;
        	hity=y+15;
            g.fillRect(x, y, 40, 40);
            g.setColor(Color.black);
            g.drawRect(x + 5, y + 10, 20, 20);
            g.drawRect(x, y, 40, 40);
            g.drawRect(x - 5, y - 5, 50, 10);
            g.fillOval(x - 5, y - 5, 10, 10);
            g.fillOval(x + 5, y - 5, 10, 10);
            g.fillOval(x + 15, y - 5, 10, 10);
            g.fillOval(x + 25, y - 5, 10, 10);
            g.fillOval(x + 35, y - 5, 10, 10);
            g.drawRect(x - 5, y + 35, 50, 10);
            g.fillOval(x - 5, y + 35, 10, 10);
            g.fillOval(x + 5, y + 35, 10, 10);
            g.fillOval(x + 15, y + 35, 10, 10);
            g.fillOval(x + 25, y + 35, 10, 10);
            g.fillOval(x + 35, y + 35, 10, 10);
            g.fillRect(hitx, hity, 40, 10);
            g.fillOval(x + 30, y + 5, 10, 10);
            g.fillOval(x + 30, y + 25, 10, 10);
        } //end of if ( op == 4 )
    }

	public void paint(Graphics g) {
		 if(!live){ 
		      if(i==0){
		        tc.tanks.remove(this);  //敌方坦克死亡时在集合中删除
		        //tc.tanks.add(new MyTank(r.nextInt(500),r.nextInt(400),0,r.nextInt(3),this.tc));
		      }
		      else {
				tc.tank.setlive(false);
			}
		      return;
		    }
        Color c = g.getColor();
        g.setColor(c);
        drawTank(g,op,x,y,i);
        Move();
	}
	
	
	public void KeyPressed(KeyEvent e) {
		 int key = e.getKeyCode();  //将键盘监听到的摁键以整数保存
		 switch (key) {
		case KeyEvent.VK_W:
			op=0;
			y-=yspeed;
			break;
		case KeyEvent.VK_A:
			op=3;
			x-=xspeed;
			break;
		case KeyEvent.VK_D:
			op=1;
			x+=xspeed;
			break;
		case KeyEvent.VK_S:
			op=2;
			y+=yspeed;
			break;
		}
		 Move();
	}
	public void Move() {
		if(x<25)
			x=25;
		else if(x>530)
			x=530;
		else if(y<50)
			y=50;
		else if(y>430)
			y=430;
		 /*敌方坦克自动移动*/
        if(i==0){
        	switch (op) {
    		case 0:
    			y-=yspeed;
    			break;
    		case 1:
    			x+=xspeed;
    			break;
    		case 2:
    			y+=yspeed;
    			break;
    		case 3:
    			x-=xspeed;
    			break;
    		}
          if(step == 0){
            step = r.nextInt(15)+1;     //随机移动步骤
            //x+=step;
            //y+=step;
            int randomNumber = r.nextInt(4);  //随机移动方向
            op=randomNumber;
          }
          step--;
          if(r.nextInt(40)>35) this.Fire();  //随机是否发射炮弹
        }
	}
	public void keyReleased(KeyEvent e) {
	if(e.getKeyCode()== KeyEvent.VK_J) //单发子弹
	        Fire();
	}
	public void Fire() {
		Missile m=new Missile(op, hitx, hity,i,tc);
		tc.missiles.add(m); //创建新的子弹类加入到子弹集合中
	}
	
	 public Rectangle getRect(){
		    return new Rectangle(x,y,40,40);
		  }
}
