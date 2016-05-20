package app3.java.Cottin.exercice3;

import java.time.Instant;
import java.time.ZoneId;

public class MessageThread extends Thread{

	@Override
	public void run() {
		while(true){
			System.out.println("Il est : "+Instant.now().atZone(ZoneId.of("Europe/Paris")));
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}

}
