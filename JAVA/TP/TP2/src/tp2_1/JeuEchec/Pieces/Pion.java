package JeuEchec.Pieces;

import JeuEchec.Couleur;

public class Pion extends Piece {
	
	public Pion(Couleur couleur){
		super(couleur);
	}

	@Override
	public boolean deplacementValide(int depuisX, int depuisY, int versX, int versY) {
		if(versX-depuisX == versY-depuisY || versX-depuisX == versY+depuisY)
			return true;
		if(depuisX != versX)
			return false;
		if(super.getCouleur()==Couleur.Blanc)
			if(depuisY+1 != versY)
				return false;
		else if(super.getCouleur() == Couleur.Noir)
			if(depuisY-1 != versY)
				return false;
		return true;
	}
	
	public boolean priseValide(int depuisX, int depuisY, int versX, int versY){
		if(depuisX != versX-1 && depuisX != versX+1){
			return false;
		}
		if(super.getCouleur()==Couleur.Blanc)
			if(depuisY+1 != versY)
				return false;
		else if(super.getCouleur() == Couleur.Noir)
			if(depuisY-1 != versY)
				return false;
		return true;
	}
	
	public String toString(){
		return "Pion : "+ super.getCouleur();
	}

}
