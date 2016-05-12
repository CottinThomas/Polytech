package exercice2;
import java.util.Scanner;


/**
 *  gestion d'un CdAudio
 *  @version 1.0
 *  @author Dominique BOUTHINON
 */
  
public class CdAudio extends Media
{
	
	// VARIABLES MEMBRES 
	
	private int duree ;

	
	// METHODES
		
	/**
	 *  constructeur vide
	 */
	public CdAudio() 
	{
		super() ;
	}
	// fin constructeur 
	
	
	/**
	 *  initialise le CdAudio courant avec le titre et la duree (pas de numero)
	 */
	 public CdAudio(String unTitre, int uneDuree)
	 {
	 	super(unTitre) ;
	 	this.duree = uneDuree ;
	 }
	// fin constructeur 
	
	
	/**
	 *  constructeur par copie (ne copie pas le numero du CdAudio)
	 */
	 public CdAudio(CdAudio d) 
	 {
		 super(d) ;
		 this.duree = d.duree ;
	 }
	// fin constructeur 
	

	// METHODES D'ACCES
	
	/**
	 *  retourne la duree du CdAudio courant
	 */
	public int getDuree()
	{
		return this.duree ;
	}
	// fin methode getDuree
	
	
	// METHODES UTILITAIRES
	

	/**
	 *  initialise interactivement le CdAudio courant (pas le numero)
	 */
	public void init() 
	{
		super.init() ;
		Scanner in = new Scanner(System.in);
		this.duree = in.nextInt() ;
		in.close();
	}
	// fin methode init


	/**
	 *  retourne la chaine de caracteres representant du CdAudio courant
	 */
	public String toString() 
	{
		return(super.toString() + " cd audio d'une duree de " +  
		       this.duree + " minutes \n") ;
	}
	// fin methode toString
	
	
	/**
	 *  retourne true si le CdAudio o a les memes caracteristiques que le 
	 *  CdAudio courant
	 */
	public boolean equals(Object o)
	{
		if (o == null) 
		   return false ;
	
		if (!(o instanceof CdAudio))
		   return false ;
	   	
	    CdAudio c = (CdAudio) o ; // evite cas multiples
	   
		return(
			   super.equals(c) && 
			   this.duree == c.duree
			  ) ;
	}
	// fin methode equals
	
}
// fin classe CdAudio
