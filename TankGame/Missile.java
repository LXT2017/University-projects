package TankGame;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.util.List;

public class Missile {
	/*�ӵ���������*/
	public int op;  //�ӵ�����
	int x,y;  //�ӵ�λ��
	public static int XSPEED = 15;  //�����ƶ��ٶ�
	public static int YSPEED = 15;  //�����ƶ��ٶ�
	public static final int Whith = 10;    //�ӵ���
	public static final int Higth = 10;    //�ӵ���
	private boolean live = true;  //�ж��ӵ��Ĵ��
	int i;
	//private boolean good;  //�ж��ӵ�����Ӫ
   
	private TankClient tc;//����Ȩ��
   
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
   
  /*��ȡ�ӵ��Ĵ��*/
  public boolean isLive() {
    return live;
  }
  /*�����ӵ��Ĵ��*/
  public void setLive(boolean live) {
    this.live = live;
  }
  public void draw(Graphics g){
    /*����ӵ�����״̬������ӵ����ӵ�������ɾ��*/
    if(!live){
      tc.missiles.remove(this);  //������ɾ��
      return;
    }
    if(i==1)
    	g.setColor(Color.yellow);  //����̹�����û�����ɫΪ��ɫ
    else
    	g.setColor(Color.red);
    /*���ӵ�*/
    g.fillOval(x, y, Whith, Higth); 
    move();  //�ƶ�
  }
   
  public void move(){
    /*�ж��ƶ������ƶ�̹��λ��*/
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
    /*�ж��ӵ���Խ��������������ӵ����������ӵ�������ɾȥ*/
    if(x<0||y<0||x>600||y>500)
      live = false;
  }
  
  /*��ײ����ȡ�ӵ��ķ�Χ*/
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
  
  /*ѭ��̹�˼��Ϸֱ�����ж��ӵ���ײ*/
  public boolean hitTanks(List<MyTank> tanks){
    for  (int i = 0; i < tanks.size(); i++){
      if(hitTank(tanks.get(i)))
        return true;
    }
    return false;
  }
}