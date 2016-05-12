package exercice2;
import java.util.*;
/**
 *  gestion d'un Media
 *  @version 1.0
 *  @author Dominique BOUTHINON
 */
  
public class Media
{
	
	// VARIABLES MEMBRES 
	
	private String titre  ;
	private int numeroMedia  ; // identifie un media de fa�on unique
	
	
	// METHODES
		
	/**
	 *  constructeur vide
	 */
	public Media() 
	{
	}
	// fin constructeur 
	
	
	/**
	 *  initialise le Media courant avec titre 
	/* (le numero sera attribue par Mediatheque)
	 */
	 public Media(String unTitre) 
	 {
		 this.titre = unTitre ;
	 }
	// fin constructeur 
	
	
	/**
	 *  constructeur par copie
	 */
	 public Media(Media m) 
	 {
		 this.titre = new String(m.titre) ;
	 }
	// fin constructeur 
	

	// METHODES D'ACCES
	

	/**
	 *  retourne le numero identifiant le Media courant
	 */
	public int getNumeroMedia()
	{
		return this.numeroMedia ;
	}
	// fin methode getNumero
	
	
	/**
	 *  retourne le titre du Media courant
	 */
	public String getTitre()
	{
		return this.titre ;
	}
	// fin methode getTitre
	
	
	/**
	 *  num devient le numero du Media courant
	 */
	public void setNumeroMedia(int num)
	{
		this.numeroMedia = num ;
	}
	// fin methode setNumeroMedia	
		
		
	
	// METHODES UTILITAIRES
	

	/**
	 *  initialise interactivement le Media courant (uniquement le titre)
	 */
	public void init() 
	{
		Scanner in = new Scanner(System.in);
		this.titre = in.next();
		in.close();
	}
	// fin methode init 

	/**
	 *  retourne la chaine de caracteres representant le Media courant (titre et numero)
	 */
	public String toString() 
	{
		return("numero = " + this.numeroMedia + " titre = " + this.titre +  " ") ;
	}
	// fin methode toString
	
	
	/**
	 *  retourne true si le Media o a meme titre que le Media courant
	 */
	public boolean equals(Object o)
	{
		if (o == null) 
		   return false ;
														   
		if (!(o instanceof Media))
		    return false ;
		   	
		return(this.titre.equals(((Media) o).titre)) ;
	}
	// fin methode equals 

	
	/**
	 *  cree un Media (au choix Livre, CdAudio ou Media), l'initialise interactivement et le retourne
	 */
	public static Media saisirMedia()
	{
			Media m ;
			
		   System.out.println("\nQuel media voulez-vous creer : ") ;
			System.out.println("1 - un cd audio  ?") ;
			System.out.println("2 - un livre ?" ) ;
			System.out.println("3 - un media indetermine ? \n" ) ;
			System.out.println("votre reponse (1, 2, 3) ? ");
			int rep ;
			do
			{
				Scanner in = new Scanner(System.in);
				rep = in.nextInt() ;
				in.close();
			}
			while (rep != 1 && rep != 2 && rep != 3) ;
			
			System.out.println() ;
			
			switch(rep)
			{
				case 1  : m = new CdAudio()  ; break ;
				case 2  : m = new Livre()    ; break ;
				default : m = new Media()    ;
			}
		
			m.init() ;              // init( ) est polymorphme
			
			return m ;
	}
	// fin methode saisirMedia
	
}
// fin classe Media
