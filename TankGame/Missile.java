package TankGame;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.util.List;

public class Missile {
	/*子弹本身数据*/
	public int op;  //子弹方向
	int x,y;  //子弹位置
	public static int XSPEED = 15;  //横向移动速度
	public static int YSPEED = 15;  //纵向移动速度
	public static final int Whith = 10;    //子弹宽
	public static final int Higth = 10;    //子弹高
	private boolean live = true;  //判断子弹的存活
	int i;
	//private boolean good;  //判断子弹和阵营
   
	private TankClient tc;//主类权限
   
 public int isgood() {
	 return i;
 }
  public Missile(int op, int x, int y,int i) {
    super();
      this.op=op;
      this.x = x;
      this.y = y;
      this.i=i;
  }
  public Missile(int op,int x, int y,Integer i,TankClient tc){
    this(op,x,y,i);
    this.tc = tc;
  }
   
  /*获取子弹的存活*/
  public boolean isLive() {
    return live;
  }
  /*设置子弹的存活*/
  public void setLive(boolean live) {
    this.live = live;
  }
  public void draw(Graphics g){
    /*如果子弹死亡状态将这个子弹在子弹集合中删除*/
    if(!live){
      tc.missiles.remove(this);  //集合中删除
      return;
    }
    if(i==1)
    	g.setColor(Color.yellow);  //本方坦克设置画笔颜色为黄色
    else
    	g.setColor(Color.red);
    /*画子弹*/
    g.fillOval(x, y, Whith, Higth); 
    move();  //移动
  }
   
  public void move(){
    /*判断移动方向移动坦克位置*/
    switch(op){
    case 3:
      this.x-=XSPEED;
      break;
    case 0:
      this.y-=YSPEED;
      break;
    case 1:
      this.x+=XSPEED;
      break;
    case 2:
      this.y+=YSPEED;
      break;
    }
    /*判断子弹的越界情况；出界则子弹死亡，在子弹集合中删去*/
    if(x<0||y<0||x>600||y>500)
      live = false;
  }
  
  /*碰撞；获取子弹的范围*/
  public Rectangle getRect(){
    return new Rectangle(x,y,Whith,Higth);
  }
  
  public boolean hitTank(MyTank t) {
	  if(this.live&&this.getRect().intersects(t.getRect())&&this.isgood()!=t.Isgood()) {
		  t.setlive(false);
		  this.live=false;
		  return true;
	  }
	  return false;
  }
  
  /*循环坦克集合分别进行判断子弹碰撞*/
  public boolean hitTanks(List<MyTank> tanks){
    for  (int i = 0; i < tanks.size(); i++){
      if(hitTank(tanks.get(i)))
        return true;
    }
    return false;
  }
}