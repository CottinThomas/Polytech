package app3.java.Cottin.exercice3;

public class DemoThreads {
	
	public static void main(String[] args) {
		new MessageThread().start();
		while(true){
			System.out.println("Le main n'est pas bloqué");
			try {
				Thread.sleep(5000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	

}
