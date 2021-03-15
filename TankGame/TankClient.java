package TankGame;

import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.ArrayList;

import javax.swing.JOptionPane;

import org.omg.CORBA.TCKind;

import TankGame.MyTank;


public class TankClient extends Applet{

	/**
	 * 
	 */
	private static final long serialVersionUID = -6815253464696444440L;
	MyTank tank=null;
	ArrayList<Missile> missiles=null;
	ArrayList<MyTank> tanks=null;

	@Override
	public void init() {
		// TODO Auto-generated method stub
		super.init();
		this.setSize(600,500);
		this.setBackground(Color.DARK_GRAY);
		missiles=new ArrayList<Missile>();
		 tanks=new ArrayList<MyTank>();
		//new TankClient().LoadFrame();
		tank=new MyTank(this,1);
		 for (int i = 0; i < 10; i=i+2){
		      tanks.add(new MyTank(50+40*(i+1), 50,0,2, this));
		    }
	}
	
	public void start() {
		// TODO Auto-generated method stub
		super.start();
		this.addKeyListener(new KeyMontion());
		this.setVisible(true);	
		new Thread(new PaintThread()).start();
	}
	public void stop() {
		Thread.yield();
	}
	@Override
	public void paint(Graphics g) {
		// TODO Auto-generated method stub
		super.paint(g);
		if(tank!=null)
			tank.paint(g);
		 for (int i = 0; i < missiles.size(); i++){
		      Missile m = missiles.get(i);  //获取当前子弹
		      m.draw(g);  //画子弹  
		      m.hitTanks(tanks);
		      m.hitTank(tank);
		 }
		 for (int i = 0; i < tanks.size(); i++){
		      MyTank t = tanks.get(i);
		      t.paint(g); //画敌方坦克
		      //t.hitTank();  //打中我方坦克
		 }
	}
	//键盘事件
	private class KeyMontion extends KeyAdapter{
		public void keyPressed(KeyEvent e) {
			super.keyPressed(e);
			tank.KeyPressed(e);
		}
		public void keyReleased(KeyEvent e){
			super.keyReleased(e);
			tank.keyReleased(e);
		}
	}
	

private class PaintThread implements Runnable{
	private int result;

	public void run() {
		// TODO Auto-generated method stub
		while(true) {
			repaint();
			if(tank.isLive()==false) {
				result = JOptionPane.showConfirmDialog(null,"you are lose!", "是否重新开始?", JOptionPane.YES_NO_OPTION);
				if(result!=JOptionPane.YES_OPTION)
					System.exit(0);
				else {
					tanks=null;
					missiles=null;
					init();		
					
				}
			}
			else if(tanks.isEmpty()==true) {
				result = JOptionPane.showConfirmDialog(null,"you are win!", "是否重新开始?", JOptionPane.YES_NO_OPTION);
				if(result!=JOptionPane.YES_OPTION)
					System.exit(0);
				else 
					init();
			}
		try {
			Thread.sleep(50);
		} catch (Exception e) {
			// TODO: handle exception
			 e.printStackTrace();
			}
		}
	}
	}
}
