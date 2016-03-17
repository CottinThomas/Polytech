package JeuEchec.Pieces;

import JeuEchec.Couleur;

public abstract class Piece {

	private Couleur couleur;
	
	public Piece(Couleur couleur){
		this.couleur = couleur;
	}
	
	public abstract boolean deplacementValide(int depuisX, int depuisY, int versX, int versY);
	
	public boolean priseValide(int depuisX, int depuisY, int versX, int versY){
		return deplacementValide(depuisX, depuisY, versX, versY);
	}
	
	public Couleur getCouleur(){
		return couleur;
	}
	
	public String toString(){
		if(this instanceof Pion){
			return ((Pion)this).toString();
		}
		return "Couleur : "+couleur.toString();
	}
	
}
