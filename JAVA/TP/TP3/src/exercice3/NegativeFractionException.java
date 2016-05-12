package exercice3;

public class NegativeFractionException extends ArithmeticException {

	private int numerateur;
	private int denominateur;
	
	public NegativeFractionException(int numerateur, int denominateur) {
		super();
		this.numerateur = numerateur;
		this.denominateur = denominateur;
	}
	
	public String toString(){
		StringBuilder sb = new StringBuilder();
		sb.append("Numérateur : ");
		sb.append(numerateur);
		sb.append("\tDénominateur : ");
		sb.append(denominateur);
		return sb.toString();
	}
	
}
