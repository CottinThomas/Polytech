package exercice2;
/**
 * 
 * @author Thomas COTTIN
 */
public class MaDoubleFile {
	
	private String[] tab;
	private int first;
	private int last;
	
	public MaDoubleFile(int capacity){
		tab = new String[capacity];
		first = -1;
		last = -1;
	}
	
	public boolean add(String str){
		
		int capacityFirst = (last-1)%tab.length;
		if(capacityFirst == -1)
			capacityFirst = tab.length-1;
		if(first == capacityFirst){
			try {
				throw new FilePleineException(tab, str);
			} catch (Exception e) {
				System.out.println(e);
				return false;
			}
		}
		
		first++;
		if(first==tab.length)
			first=0;
		tab[first] = str;
		if(last == -1)
			last = first;
		return true;
	}
	
	public String getFirst(){
		return tab[first];
	}
	
	public String getLast(){
		return tab[last];
	}
	
	public String removeFirst(){
		if(size()==0)
			throw new ArrayIndexOutOfBoundsException();
		String val = tab[first];
		first--;
		if(size()==0){
			last = -1;
			first = -1;
		}
		else if(first==-1)
			first=tab.length-1;
		return val;
	}
	
	public String removeLast(){
		if(size()==0)
			throw new ArrayIndexOutOfBoundsException();
		String val = tab[last];
		last++;
		if(size()==0){
			last = -1;
			first = -1;
		}
		else if(last==tab.length){
			last=0;
		}
		return val;
	}
	
	public int size(){
		int size;
		if(last <= first){
			size = first-last+1;
		}
		else{
			size =  tab.length+1+first-last;
		}
		System.out.println("Size = "+size);
		return size;
	}
	
	public String toString(){
		StringBuilder sb = new StringBuilder();
		sb.append("First = "+first).append("\n");
		int i = first;
		while(i != last){
			sb.append("Index : ").append(i).append("\tValue : ").append(tab[i]).append("\n");
			i--;
			if(i==-1){
				i=tab.length-1;
			}
		}
		sb.append("Index : ").append(last).append("\tValue : ").append(tab[last]).append("\n");
		sb.append("Last = "+last).append("\n");
		return sb.append("\n").toString();
	}
	
	public static void main(String[] args) {
		System.out.println("###############################");
		System.out.println("#  Working with the capacity  #");
		System.out.println("###############################\n");
		System.out.println("Question 7 scenario");
		System.out.println("------------------------------\n");
		MaDoubleFile file = new MaDoubleFile(5);
		System.out.println("Adding five elements to a 5 string long array\n");
		file.add("Aaaa");
		file.add("Bbbb");
		file.add("Cccc");
		file.add("Dddd");
		file.add("Eeee");
		System.out.println(file);
		System.out.println("Removing the first and the last elements\n");
		file.removeFirst();
		file.removeLast();
		System.out.println(file);
		System.out.println("\n\nCustom scenario");
		System.out.println("------------------------------\n");
		file = new MaDoubleFile(5);
		System.out.println("Adding 6 elements to a 5 string long array\n");
		file.add("Aaaa");
		file.add("Bbbb");
		file.add("Cccc");
		file.add("Dddd");
		file.add("Eeee");
		file.add("Ffff");
		System.out.println(file);
		System.out.println("Removing the two lasts elements\n");
		file.removeLast();
		file.removeLast();
		System.out.println(file);
		System.out.println("Adding another element (check if First goes to 0 and further)\n");
		try{
			file.add("Ffff");
		} catch(Exception e){
			System.out.println(e);
		}
		System.out.println(file);
	}
}
