package tp1_2;

public class Fibonacci {
	
	public static int compteur = 0;
	
	public static int fib(int n){
		compteur +=1;
		if(n <= 0)
			return 0;
		if(n == 1)
			return 1;
		return fib(n-1) + fib(n-2);
	}
	
	public static int appels(int n){
		if(n<=1)
			return 1;
		return appels(n-1)+appels(n-2)+1;
	}
	
	public static void main(String[] args) {
		/*
		for(int i = 0; i <= 100; i++)
			System.out.println(i + ":" + fib(i));
		*/
		System.out.println("Il y a "+appels(20)+" appels pour n = 20 et "+appels(30)+" pour n = 30");
		fib(20);
		System.out.println("fib(20) : compteur = "+compteur);
	}

}
