package JeuEchec;

import JeuEchec.Pieces.Piece;
import JeuEchec.Pieces.Pion;

public class Plateau {
	
	private Couleur tour;
	
	private Piece[][] cases;
	
	public Plateau(){
		this.tour = Couleur.Blanc;
		this.cases = new Piece[8][8];
	}
	
	public String getTour(){
		return tour.toString();
	}
	
	public Piece getPiece(int x, int y){
		return cases[x][y];
	}
	
	public void ajoutPiece(Piece p, int x, int y){
		cases[x][y] = p;
	}
	
	public boolean deplace(int depuisX, int depuisY, int versX, int versY){
		if(depuisX < 0 || depuisX > 8 || versX < 0 || versX > 8)
			return false;
		if(depuisX < 0 || depuisX > 8 || versX < 0 || versX > 8)
			return false;
		if(cases[depuisX][depuisY] == null)
			return false;
		Piece p = cases[depuisX][depuisY];
		if(p.getCouleur() != tour){
			return false;
		}
		Piece dest = cases[versX][versY];
		if(dest != null){			
			if(dest.getCouleur() == p.getCouleur()){
				return false;
			}
			if(p instanceof Pion){
				if(((Pion)p).priseValide(depuisX, depuisY, versX, versY)){
					deplacer(depuisX, depuisY, versX, versY);
					return true;
				}
				return false;
			}
			if( p.priseValide(depuisX, depuisY, versX, versY)){
				deplacer(depuisX, depuisY, versX, versY);
				return true;
			}
			return false;
		}
		else{
			if( p.deplacementValide(depuisX, depuisY, versX, versY)){
				deplacer(depuisX, depuisY, versX, versY);
				return true;
			}
			return false;
		}
	}
	
	private void deplacer(int depuisX, int depuisY, int versX, int versY){
		cases[versX][versY] = cases[depuisX][depuisY];
		cases[depuisX][depuisY] = null;
		if(this.tour == Couleur.Blanc)
			this.tour = Couleur.Noir;
		else
			this.tour = Couleur.Blanc;
	}
	
	public String toString(){
		StringBuilder r = new StringBuilder();
		for(int i = 0; i< 8; i++){
			for(int j = 0; j < 8; j++){
				if(cases[i][j] != null){
					r.append("[ Case "+i+","+j+" ] "+cases[i][j].toString()+"\n");
				}
			}
		}
		return r.toString();
	}
}
