package exercice2_adaptSize;

import java.util.NoSuchElementException;

public class MaDoubleFileAdaptSize {

	private String[] queue;
	private int first;
	private int last;
	
	public MaDoubleFileAdaptSize(){
		queue = new String[5];
		first = -1;
		last = -1;
	}
	
	public void increaseQueue(){
		if(this.size() == queue.length){
			String[] tab = new String[queue.length*2];
			int pos = last;
			for(int i=0; i<queue.length; i++){
				tab[i] = queue[pos];
				pos++;
				if(pos == queue.length){
					pos = 0;
				}
			}
			first = queue.length-1;
			last = 0;
			this.queue = tab;
		}
	}
	
	public boolean add(String str){
		
		int capacityFirst = (last-1)%queue.length;
		if(capacityFirst == -1)
			capacityFirst = queue.length-1;
		if(first == capacityFirst){
			increaseQueue();
		}
		
		first++;
		if(first==queue.length)
			first=0;
		queue[first] = str;
		if(last == -1)
			last = first;
		return true;
	}
	
	public String getFirst(){
		if(size()==-1)
			throw new NoSuchElementException();
		return queue[first];
	}
	
	public String getLast(){
		if(size()==-1)
			throw new NoSuchElementException();
		return queue[last];
	}
	
	public String removeFirst(){
		if(size()==0)
			throw new NoSuchElementException();
		String val = queue[first];
		first--;
		if(size()==0){
			last = -1;
			first = -1;
		}
		else if(first==-1)
			first=queue.length-1;
		return val;
	}
	
	public String removeLast(){
		if(size()==0)
			throw new NoSuchElementException();
		String val = queue[last];
		last++;
		if(size()==0){
			last = -1;
			first = -1;
		}
		else if(last==queue.length){
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
			size =  queue.length+1+first-last;
		}
		return size;
	}
	
	public String toString(){
		StringBuilder sb = new StringBuilder();
		sb.append("First = "+first).append("\n");
		int i = first;
		while(i != last){
			sb.append("Index : ").append(i).append("\tValue : ").append(queue[i]).append("\n");
			i--;
			if(i==-1){
				i=queue.length-1;
			}
		}
		sb.append("Index : ").append(last).append("\tValue : ").append(queue[last]).append("\n");
		sb.append("Last = "+last).append("\n");
		return sb.append("\n").toString();
	}
	
	public static void main(String[] args) {
		System.out.println("###############################");
		System.out.println("#  Working with the capacity  #");
		System.out.println("###############################\n");
		System.out.println("Question 7 scenario");
		System.out.println("------------------------------\n");
		MaDoubleFileAdaptSize file = new MaDoubleFileAdaptSize();
		System.out.println("Filling the array.");
		file.add("Aaaa");
		file.add("Bbbb");
		file.add("Cccc");
		file.add("Dddd");
		file.add("Eeee");
		System.out.println(file);
		System.out.println("Adding one more element");
		file.add("Ffff");
		System.out.println(file);
		file.add("Gggg");
		file.add("Hhhh");
		file.add("Iiii");
		file.add("Jjjj");
		System.out.println(file);
		file.removeLast();
		System.out.println(file);
		file.add("Kkkk");
		System.out.println(file);
		file.add("Llll");
		System.out.println(file);
		file.removeFirst();
		System.out.println(file);
		file.removeLast();
		System.out.println(file);
	}

}
