import se.lth.cs.ptdc.window.SimpleWindow;
import java.awt.Color;

public class Linjer {
	public static void main(String[] args) {
		SimpleWindow w = new SimpleWindow(600, 600, "Linjer");
		
		int oldX=0;
		int oldY=0;
		
		int r=255;
		int g=0;
		int b=0;
		
		
		
		while (true) {
			
			Color col = new Color(r, g, b);
			w.setLineColor(col);
			
			w.waitForMouseClick();
			
			w.moveTo(oldX, oldY);
			w.lineTo(w.getMouseX(), w.getMouseY());
			
			oldX=w.getMouseX();
			oldY=w.getMouseY();
			
			
		}
		
	
	}
}
