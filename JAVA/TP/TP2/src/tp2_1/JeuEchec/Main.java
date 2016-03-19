package JeuEchec;
import java.util.Scanner;

import JeuEchec.Pieces.*;

public class Main {

	public static void main(String[] args) {
		
		Plateau plateau = new Plateau();
		for(int i = 0; i < 8; i++)
			plateau.ajoutPiece(new Pion(Couleur.Blanc), i, 1);

		for(int i = 0; i < 8; i++)
			plateau.ajoutPiece(new Pion(Couleur.Noir), i, 6);
		
		plateau.ajoutPiece(new Tour(Couleur.Blanc), 0, 0);
		plateau.ajoutPiece(new Tour(Couleur.Blanc), 7, 0);
		plateau.ajoutPiece(new Fou(Couleur.Blanc), 1, 0);
		plateau.ajoutPiece(new Fou(Couleur.Blanc), 6, 0);
		plateau.ajoutPiece(new Cavalier(Couleur.Blanc), 2, 0);
		plateau.ajoutPiece(new Cavalier(Couleur.Blanc), 5, 0);
		plateau.ajoutPiece(new Roi(Couleur.Blanc), 3, 0);
		plateau.ajoutPiece(new Reine(Couleur.Blanc), 4, 0);
		
		plateau.ajoutPiece(new Tour(Couleur.Noir), 0, 7);
		plateau.ajoutPiece(new Tour(Couleur.Noir), 7, 7);
		plateau.ajoutPiece(new Fou(Couleur.Noir), 1, 7);
		plateau.ajoutPiece(new Fou(Couleur.Noir), 6, 7);
		plateau.ajoutPiece(new Cavalier(Couleur.Noir), 2, 7);
		plateau.ajoutPiece(new Cavalier(Couleur.Noir), 5, 7);
		plateau.ajoutPiece(new Roi(Couleur.Noir), 4, 7);
		plateau.ajoutPiece(new Reine(Couleur.Noir), 3, 7);

		
		System.out.println(plateau.toString());
		
		boolean continuer = true;
		
		while(continuer){
			System.out.println("Tour de "+plateau.getTour());
			Scanner s = new Scanner(System.in);
			int x = s.nextInt();
			int y = s.nextInt();
			int nx = s.nextInt();
			int ny = s.nextInt();
			boolean res = plateau.deplace(x, y, nx, ny);
			while(!res){
				System.out.println("Mauvais déplacement");
				x = s.nextInt();
				y = s.nextInt();
				nx = s.nextInt();
				ny = s.nextInt();
				res = plateau.deplace(x, y, nx, ny);
			}
			s.close();
		}
		

	}

}
