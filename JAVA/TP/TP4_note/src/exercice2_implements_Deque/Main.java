package exercice2_implements_Deque;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		System.out.println("\n\n##################################");
		System.out.println("#  Working without the capacity  #");
		System.out.println("##################################\n");
		MaDoubleFileImpDeque file = new MaDoubleFileImpDeque();
		System.out.println("Filling the array.");
		file.offerFirst("Aaaa");
		file.offerFirst("Bbbb");
		file.offerFirst("Cccc");
		file.offerFirst("Dddd");
		file.offerFirst("Eeee");
		System.out.println(file);
		System.out.println("Adding one more element");
		file.offerFirst("Ffff");
		System.out.println(file);
		file.offerFirst("Gggg");
		file.offerFirst("Hhhh");
		file.offerFirst("Iiii");
		file.offerFirst("Jjjj");
		System.out.println(file);
		file.removeLast();
		System.out.println(file);
		file.offerFirst("Kkkk");
		System.out.println(file);
		file.offerFirst("Llll");
		System.out.println(file);
		file.removeFirstOccurrence("Hhhh");
		System.out.println(file);
		file.removeLastOccurrence("Eeee");
		System.out.println(file);
		
		
	}

}
