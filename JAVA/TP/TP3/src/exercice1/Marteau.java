package exercice1;

import java.util.Scanner ;

public class Marteau extends Outil
{
	private float poids ;
	
	/**
	 * Constructeur vide
	 * initilialise la marque avec une chaine vide
	 * la reference de du Marteau avec la valeur 0
	 * et le poids � O
	 */
	public Marteau(){
		super();
		this.poids = 0;
	}
	
	/**
	 * Constructeur
	 * @param reference	refercnce de l'Outil
	 * @param uneMarque marque de l'Outil
	 * @param unPoids poids de du Marteau
	 */
	public Marteau(long reference, String uneMarque, float unPoids) 
    {
      super(reference, uneMarque) ;	
      this.poids = unPoids ;	
    }

	public Marteau(Marteau marteau){
		super(marteau);
		this.poids = marteau.getPoids();
	}
	
	public float getPoids()
	{
		return this.poids ;
	}	
		
	public void setPoids(float poids){
		this.poids = poids;
	}
	
	
	/**
	 * Initialisation interactive d'un Marteau
	 */
	public void init(){
		super.init();
		System.out.println("poids du marteau ?") ;
		Scanner s = new Scanner(System.in) ;
		this.poids = s.nextFloat();
	}
	
	
	/**
	 * Compare les Marteau par leur reference (code barre) et leur poids
	 */
	public boolean equals(Object o){
		if (o==null) return false;
		if (!(o instanceof Marteau)) return false;
		
		Marteau marteau = (Marteau) o;
		return super.equals(o)&&marteau.getReference() == this.getReference() && marteau.getPoids()==this.getPoids() ;
	}
	public String toString()
	{
		return "marteau;" + super.toString() + 
			   ";" + this.poids;	
	}		
}