package exercice3;

import java.util.Scanner;

public class FractionPositive {
	
	private int numerateur;
	private int denominateur;
	
	public FractionPositive(int numerateur, int denominateur) throws ArithmeticException, NegativeFractionException{
		if(denominateur == 0){
			throw new ArithmeticException("Devided by zero");
		}
		if(numerateur/denominateur < 0){
			throw new NegativeFractionException(numerateur, denominateur);
		}
		
		this.denominateur = denominateur;
		this.numerateur = numerateur;
	}
	
	public Double getDoubleValue(){
		return (double)numerateur/denominateur;
	}
	
	public static void main(String[] args) {
		do{
			Scanner s = new Scanner(System.in);
			System.out.println("Entrez le numerateur : ");
			int numerateur = s.nextInt();
			System.out.println("Entrez le denominateur : ");
			int denominateur = s.nextInt();
			s.close();
			try{
				FractionPositive fp = new FractionPositive(numerateur, denominateur);
				System.out.println(fp.getDoubleValue());
			} catch(NegativeFractionException e){
				e.printStackTrace();
			} catch(ArithmeticException e){
				e.printStackTrace();
			}
		} while(true);
	}

}
