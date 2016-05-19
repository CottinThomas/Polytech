package app3.java.Cottin.exercice1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.LineNumberReader;
import java.util.Scanner;

public class TP5Exercice1 {
	
	public enum E_Mode {LINE, LINENUMBER, DIRECTORY}
	
	
	public static void lineFunction(File f) throws FileNotFoundException,IOException {
		FileReader fr = new FileReader(f);
		BufferedReader br = new BufferedReader(fr);
		String line = br.readLine();
		while(line != null){
			System.out.println("Line : "+line);
			line = br.readLine();
		}
		br.close();
		fr.close();
	}
	
	public static void lineNumberFunction(File f) throws FileNotFoundException,IOException {
		FileReader fr = new FileReader(f);
		LineNumberReader lnr = new LineNumberReader(fr);
		String line2 = lnr.readLine();
		while(line2 != null){
			System.out.println("Line " +lnr.getLineNumber()+" : "+line2);
			line2 = lnr.readLine();
		}
		lnr.close();
		fr.close();
	}
	
	public static void directoryFunction(File f){
		if(f.isDirectory()){
			for(File file : f.listFiles()){
				if(file.isDirectory())
					System.out.println("[D] "+file.getName());
				else
					System.out.println("[F] "+file.getName());
			}
		}
	}
	
	public static void main(String[] args) {
		
		E_Mode m = E_Mode.DIRECTORY;
		System.out.println("Veuillez entrer un nom de fichier :");
		Scanner s = new Scanner(System.in);
		String path = s.nextLine();
		try{
			File f = new File(path);
			if(!f.canRead()){
				throw new Exception("Can't open file");
			}	
			switch (m) {
				case LINE:
					lineFunction(f);
					break;
				case LINENUMBER:
					lineNumberFunction(f);
					break;
				case DIRECTORY:
					directoryFunction(f);
					break;
				default:
					break;
			}			
			System.out.println("Lecture finie");
		} catch(FileNotFoundException e){
			System.out.println("Le fichier specifié n'existe pas.");
		} catch(IOException e){
			System.out.println("Erreur de lecture");
		} catch(Exception e){
			System.out.println(e.getMessage());
		}
		
		
		
	}

}
