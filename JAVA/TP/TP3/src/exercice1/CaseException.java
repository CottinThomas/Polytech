package exercice1;
public class CaseException extends Exception {
	/**
	 * Exception declenchee si une anomalie survient lors de l'ajout ou du
	 * retrait d'un Outil. L'exception encapsulera un la reference de l'ensemble
	 * des cases et la position voulue fautive
	 */

	private int position;
	private Outil[] cases;
	private Outil e;

	public CaseException(String message, Outil[] cases, int position, Outil e) {
		super(message);
		this.position = position;
		this.cases = cases;
		this.e = e;
	}

	public int getPosition() {
		return this.position;
	}

	public Outil[] getCases() {
		return this.cases;

	}

	public String toString() {
		String s = super.toString() + "\n";

		for (int i = 0; i < this.cases.length; i++) {
			if (i == this.position) {
				s = s + "************************\n";
				s = s + "-->" + i + "######" + this.cases[i] + "!!!!!!!!"
						+ this.e + "!!!!!!!!!\n";
				s = s + "************************\n";
			} else
				s = s + "-->" + i + "######" + this.cases[i] + "\n";
		}
		return s;
	}

}
