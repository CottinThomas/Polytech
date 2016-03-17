package JeuEchec.Pieces;

import JeuEchec.Couleur;

public class Fou extends Piece {
	
	public Fou(Couleur couleur){
		super(couleur);
	}
	
	@Override
	public boolean deplacementValide(int depuisX, int depuisY, int versX, int versY) {
		if(depuisX == versX && depuisY == versY)
			return false;
		if(versX-depuisX == versY-depuisY || versX-depuisX == versY+depuisY)
			return true;
		return false;
	}

	
	public String toString(){
		return "Fou : "+ super.getCouleur();
	}

}
