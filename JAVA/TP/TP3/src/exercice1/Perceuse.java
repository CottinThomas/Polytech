package exercice1;
import java.util.Scanner;

public class Perceuse extends Outil {
	private int vitesse;

	/**
	 * Constructeur vide initilialise la marque avec une chaine vide la
	 * reference de la Perceuse avec la valeur 0 et la vitesse maximmum à 3600
	 * tr/mn
	 */
	public Perceuse() {
		super();
		this.vitesse = 3600;
	}

	public Perceuse(long reference, String uneMarque, int uneVitesse) {
		super(reference, uneMarque);
		this.vitesse = uneVitesse;
	}

	public Perceuse(Perceuse perceuse) {
		super(perceuse);
		this.vitesse = perceuse.getVitesse();

	}

	public int getVitesse() {
		return this.vitesse;
	}

	/**
	 * Initialisation interactive d'un Marteau
	 */
	public void init() {
		super.init();
		Scanner s = new Scanner(System.in);
		System.out.println("Vitesse de la perceuse (tours/minute) ? ");
		this.vitesse = s.nextInt();
	}

	/**
	 * Compare les Marteau par leur reference (code barre) et leur vitesse de
	 * rotation
	 */
	public boolean equals(Object o) {
		if (o == null)
			return false;
		if (!(o instanceof Perceuse))
			return false;

		Perceuse perceuse = (Perceuse) o;
		return super.equals(o)
				&& perceuse.getReference() == this.getReference()
				&& perceuse.getVitesse() == this.getVitesse();
	}

	public String toString() {
		return "perceuse;" + super.toString() + ";" + this.vitesse;
	}
}