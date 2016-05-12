package exercice1;
public class DeplacementException extends Exception {
	/**
	 * Exception declenchee si une anomalie survient lors du deplacement du bras
	 * du Robot. L'exception encapsulera un message et la position voulue
	 * fautive
	 */

	private int position;

	public DeplacementException(String message, int position) {
		super(message);
		this.position = position;
	}

	public int getPosition() {
		return this.position;
	}

	public String toString() {
		return super.toString() + "###" + this.getPosition() + "\n";
	}
}
