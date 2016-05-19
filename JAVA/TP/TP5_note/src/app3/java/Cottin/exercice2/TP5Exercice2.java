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
	
	public static void main(String[] args) {
		try{
			File f = new File(FILE_PATH+"prenoms.txt");
			if(!f.canRead()){
				throw new Exception("Can't open file");
			}
			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
			List<String> listePrenoms = new ArrayList<String>();
			String line = br.readLine();
			while(line != null){
				listePrenoms.add(line);
				line = br.readLine();
			}
			br.close();
			fr.close();
			
			Collections.sort(listePrenoms);
			
			File out = new File(FILE_PATH+"prenoms_out.txt");
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
