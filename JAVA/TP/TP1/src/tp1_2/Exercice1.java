/**
 * 
 */
package tp1_2;

import java.util.Scanner;

/**
 * @author thomas.cottin
 *
 */
public class Exercice1 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		System.out.println("Exercice 2 :");

		Scanner lecteur = new Scanner(System.in);
		/*
		System.out.println("Entrer votre nom :");
		String name = lecteur.nextLine();
		System.out.println("Bonjour " + name + " !");
		*/
		
		/*
		System.out.println("Combien de nombres souhaitez vous entrer ?");
		int nbNumber = Integer.parseInt(lecteur.nextLine());
		while (nbNumber < 1 && nbNumber > 10){
			System.out.println("Merci de saisir un nombre entre 1 et 10");
			nbNumber = Integer.parseInt(lecteur.nextLine());
		}
		int sum = 0;
		/*
		for(int i = 1; i <= nbNumber; i++){
			System.out.println("Saisir le nombre "+i);
			sum += Integer.parseInt(lecteur.nextLine());
		}
		*/
		/*
		int i = 1;
		while(i<=nbNumber){
			System.out.println("Saisir le nombre "+i);
			sum += Integer.parseInt(lecteur.nextLine());
			i++;
		}
		*/
		String line = lecteur.nextLine();
		int sum = 0;
		while(!line.isEmpty()){
			sum += Integer.parseInt(line);
			line = lecteur.nextLine();
		}
		System.out.println(sum);
		lecteur.close();
		
	}

}
