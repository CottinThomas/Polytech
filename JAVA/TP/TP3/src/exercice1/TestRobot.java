package exercice1;
public class TestRobot {

	public static void main(String args[]) {

		Robot r1 = new Robot(5);
		System.out.println(r1);

		try {
			r1.ajoute(new Outil(1, "outil 1"));
		} catch (CaseException e) {
			e.printStackTrace();
		}

		try {
			r1.deplaceBras(3);
		} catch (DeplacementException e) {
			e.printStackTrace();
		}
		
		try {
			r1.ajoute(new Marteau(2, "marteau 2", 5));
		} catch (CaseException e) {
			e.printStackTrace();
		}

		try {
			r1.deplaceBras(0);

		} catch (DeplacementException e) {
			e.printStackTrace();
		}

		try {
			Outil o = r1.retire();
			System.out.println(o);
		} catch (CaseException e) {
			e.printStackTrace();
		}

	}
}
