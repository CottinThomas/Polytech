package JeuEchec.Pieces;

import JeuEchec.Couleur;

public class Roi extends Piece{

	public Roi(Couleur couleur) {
		super(couleur);
	}

	@Override
	public boolean deplacementValide(int depuisX, int depuisY, int versX, int versY) {
		if(versX-depuisX == versY-depuisY || versX-depuisX == versY+depuisY)
			return true;
		if(depuisX == versX)
			if(depuisY-1 == versY || depuisY+1 == versY)
				return true;
		if(depuisY-1 == versY || depuisY+1 == versY)
			return true;
		if(depuisX-1 == versX || depuisX+1 == versX){
			if(depuisY-1 == versY || depuisY+1 == versY)
				return true;
		}
		return false;
	}
	
	public String toString(){
		return "Roi : "+ super.getCouleur();
	}
}
