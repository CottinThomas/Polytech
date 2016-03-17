package JeuEchec.Pieces;

import JeuEchec.Couleur;

public class Cavalier extends Piece {
	
	public Cavalier(Couleur couleur){
		super(couleur);
	}

	@Override
	public boolean deplacementValide(int depuisX, int depuisY, int versX, int versY) {
		if(depuisX == versX && depuisY == versY)
			return false;
		if(versX == depuisX+1)
			if(versY == depuisY+2 || versY == depuisY-2)
				return true;
		if(versX == depuisX-1)
			if(versY == depuisY+2 || versY == depuisY-2)
				return true;
		if(versX == depuisX+2)
			if(versY == depuisY+1 || versY == depuisY-1)
				return true;
		if(versX == depuisX-2)
			if(versY == depuisY+1 || versY == depuisY-1)
				return true;
		return false;
	}

	
	public String toString(){
		return "Cavalier : "+ super.getCouleur();
	}


}
