package app3.java.Cottin.exercice2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class TP5Exercice2 {
	
	public static final String FILE_PATH = "/home/thomas/Polytech/JAVA/TP/TP5_note/";
	public static final String INPUT_FILE_NAME = "prenoms.txt";
	public static final String OUTPUT_FILE_NAME = "prenoms_out.txt";
	
	
	public static void main(String[] args) {
		System.out.println("Ouverture du fichier "+FILE_PATH+INPUT_FILE_NAME);
		try{
			File f = new File(FILE_PATH+INPUT_FILE_NAME);
			if(!f.canRead()){
				throw new Exception("Can't open file");
			}
			FileReader fr = new FileReader(f);
			BufferedReader in = new BufferedReader(fr);
			List<String> listePrenoms = new ArrayList<String>();
			System.out.println("Extraction de son contenu dans une liste");
			String line = in.readLine();
			while(line != null){
				listePrenoms.add(line);
				line = in.readLine();
			}
			in.close();
			fr.close();

			System.out.println("tri de la liste");
			Collections.sort(listePrenoms);
			

			System.out.println("Ecriture de la liste triée dans "+FILE_PATH+OUTPUT_FILE_NAME);
			File out = new File(FILE_PATH+OUTPUT_FILE_NAME);
			FileWriter fw = new FileWriter(out);
			BufferedWriter bw = new BufferedWriter(fw);
			for(String prenom : listePrenoms)
				bw.write(prenom+"\n");
			bw.close();
			fw.close();			
			
		} catch(FileNotFoundException e){
			System.out.println("Le fichier specifié n'existe pas.");
		} catch(IOException e){
			System.out.println("Erreur de lecture");
		} catch(Exception e){
			System.out.println(e.getMessage());
		}
	}
	
}
