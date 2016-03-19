package JeuEchec.Pieces;

import JeuEchec.Couleur;

public class Reine extends Piece {

	public Reine(Couleur couleur) {
		super(couleur);
	}

	@Override
	public boolean deplacementValide(int depuisX, int depuisY, int versX, int versY) {
		if(depuisX == versX && depuisY == versY)
			return false;
		if(depuisX == versX || depuisY == versY)
			return true;
		if(versX-depuisX == versY-depuisY || versX-depuisX == versY+depuisY)
			return true;
		return false;
	}

}
