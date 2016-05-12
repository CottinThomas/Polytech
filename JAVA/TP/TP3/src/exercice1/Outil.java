package exercice1;
import java.util.*;

public class Outil {
	private String marque;
	private long reference;

	/**
	 * Constructeur vide initilialise la marque avec une chaine vide et la
	 * reference de l'Outil avec la valeur 0
	 */
	public Outil() {
		this.marque = "";
		this.reference = 0;
	}

	/**
	 * Constructeur
	 * 
	 * @param reference
	 *            refercnce de l'Outil
	 * @param uneMarque
	 *            marque de l'Outil
	 */
	public Outil(long reference, String uneMarque) {
		this.reference = reference;
		this.marque = uneMarque;
	}

	public Outil(Outil outil) {
		this.marque = new String(outil.getMarque());
		this.reference = outil.getReference();
	}

	public long getReference() {
		return this.reference;
	}

	public void setReference(long reference) {
		this.reference = reference;
	}

	public String getMarque() {
		return this.marque;
	}

	public void setMarque(String marque) {
		this.marque = marque;
	}

	public String toString() {
		return this.getReference() + ";" + this.marque;
	}

	/**
	 * Initialisation interactive d'un Outil
	 */
	public void init() {
		Scanner s = new Scanner(System.in);
		System.out.println("Marque de l'outil ? ");
		this.marque = s.nextLine();
		System.out.println("Reference de l'outil ? ");
		this.reference = s.nextInt();
	}

	/**
	 * Compare les Outils par leur reference (code barre)
	 */
	public boolean equals(Object o) {
		if (o == null)
			return false;
		if (!(o instanceof Outil))
			return false;

		return ((Outil) o).getReference() == this.getReference();
	}
}
