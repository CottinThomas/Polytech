package tp1_1;

public class Exercice1 {

	public static void main(String[] args) {
		System.out.println("Hello, World!");
		Point a = new Point('A', 4, 2.75);
		Point b = new Point('B',0,0);
		Point c = new Point('C',-5,2.75);
		Point d = new Point('D',0.0001,0.0001);
		
		double distAC = a.distance(c);
		System.out.println("La distance entre A et C est de "+distAC);
		if(b.confondu(d))
			System.out.println("B et D sont confondus");
		else
			System.out.println("B et D ne sont pas confondus");
		if(!d.translate(Double.POSITIVE_INFINITY, 3.0)){
			System.out.println("Check ok");
		}
	}

}
