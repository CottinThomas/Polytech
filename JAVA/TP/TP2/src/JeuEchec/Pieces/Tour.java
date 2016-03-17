package JeuEchec.Pieces;

import JeuEchec.Couleur;

public class Tour extends Piece {

	public Tour(Couleur couleur) {
		super(couleur);
	}

	@Override
	public boolean deplacementValide(int depuisX, int depuisY, int versX, int versY) {
		if(versX-depuisX == versY-depuisY || versX-depuisX == versY+depuisY)
			return true;
		if(depuisX != versX && depuisY!=versY)
			return false;
		return true;
	}
	
	public String toString(){
		return "Tour : "+ super.getCouleur();
	}

}
