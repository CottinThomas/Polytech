package exercice2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Deque;
import java.util.Iterator;
import java.util.List;
import java.util.NoSuchElementException;

import com.sun.org.apache.bcel.internal.generic.CASTORE;

public class MaDoubleFileNoCapacity implements Deque<String>{

	
	private String[] tab;
	private int first;
	private int last;
	
	public MaDoubleFileNoCapacity(){
		tab = new String[5];
		first = -1;
		last = -1;
	}
	
	// corresponds to the add method
	public boolean offerFirst(String str){		
		int calculatedFirstKnowingTheLastPosition = (last-1)%tab.length;
		if(calculatedFirstKnowingTheLastPosition == -1)
			calculatedFirstKnowingTheLastPosition = tab.length-1;
		if(first == calculatedFirstKnowingTheLastPosition){
			manageOverflow();
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
		if(size()==0)
			throw new NoSuchElementException();
		return tab[first];
	}
	
	public String getLast(){
		if(size()==0)
			throw new NoSuchElementException();
		return tab[last];
	}
	
	public String removeFirst(){
		if(size()==0)
			throw new NoSuchElementException();
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
			throw new NoSuchElementException();
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
		return size;
	}
	
	private void manageOverflow(){
		if(size()==tab.length){
			String[] newTab = new String[2*tab.length];
			int i = last;
			int j = 0;
			while(i != first){
				newTab[j] = tab[i];
				i++;
				j++;
				if(i==tab.length){
					i=0;
				}
			}
			newTab[tab.length-1] = tab[first];
			first = tab.length-1;
			last = 0;
			tab = newTab;
		}			
	}

	@Override
	public boolean isEmpty() {
		return size()==0;
	}

	@Override
	public Object[] toArray() {
		String[] array = new String[tab.length];
		int i = last;
		int j = 0;
		while(i != first){
			array[j] = tab[i];
			i++;
			j++;
			if(i==tab.length){
				i=0;
			}
		}
		array[tab.length-1]=tab[first];
		return array;
	}

	@Override
	public <T> T[] toArray(T[] a) {
		if(a == null){
			throw new NullPointerException();
		}
		try{
			a = (T[])toArray();
		}catch(ClassCastException e){
			throw new ArrayStoreException();
		}
		return a;
	}

	@Override
	public boolean containsAll(Collection<?> c) {
		String[] s = (String[])toArray();
		List<String> l = Arrays.asList(s);
		return l.containsAll(c);
	}

	@Override
	public boolean addAll(Collection<? extends String> c) {
		for(String str : c)
			if(!offerFirst(str))
				return false;
		return true;
	}

	@Override
	public boolean removeAll(Collection<?> c) {
		for(Object str : c)
			if(!remove(str))
				return false;
		return true;
	}

	@Override
	public void clear() {
		first = -1;
		last = -1;
	}

	@Override
	public void addFirst(String e) {
		if(e == null){
			throw new NullPointerException();
		}
		offerFirst(e); 
	}

	@Override
	public void addLast(String e) {
		add(e);
	}

	@Override
	public boolean offerLast(String e) {
		return add(e);
	}

	@Override
	public String pollFirst() {
		if(size()==0)
			return null;
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

	@Override
	public String pollLast() {
		if(size()==0)
			return null;
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

	@Override
	public String peekFirst() {
		if(size()==0)
			return null;
		return tab[first];
	}

	@Override
	public String peekLast() {
		if(size()==0)
			return null;
		return tab[last];
	}

	@Override
	public boolean removeFirstOccurrence(Object o) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean removeLastOccurrence(Object o) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean offer(String e) {
		return offerLast(e);
	}

	@Override
	public String remove() {
		return removeFirst();
	}

	@Override
	public String poll() {
		return pollFirst();
	}

	@Override
	public String element() {
		return getFirst();
	}

	@Override
	public String peek() {
		return peekFirst();
	}

	@Override
	public void push(String e) {
		addFirst(e);
	}

	@Override
	public String pop() {
		return removeFirst();
	}

	@Override
	public boolean remove(Object o) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean contains(Object o) {
		String[] ar = (String[])toArray();
		List<String> l = Arrays.asList(ar);
		if(l.contains(o))
			return true;
		return false;
	}

	@Override
	public Iterator<String> iterator() {
		return new Iterator<String>() {
			
			int pos = first;

			@Override
			public boolean hasNext() {
				if(pos != last)
					return true;
				return false;
			}

			@Override
			public String next() {
				if(!hasNext())
					throw new NoSuchElementException();
				pos--;
				if(pos == -1)
					pos = tab.length;
				return tab[pos];
			}

			@Override
			public void remove() {
				throw new UnsupportedOperationException();
			}
			
		};
	}

	@Override
	public Iterator<String> descendingIterator() {
		return new Iterator<String>() {
			
			int pos = last;

			@Override
			public boolean hasNext() {
				if(pos != first)
					return true;
				return false;
			}

			@Override
			public String next() {
				if(!hasNext())
					throw new NoSuchElementException();
				pos++;
				if(pos == tab.length)
					pos = 0;
				return tab[pos];
			}

			@Override
			public void remove() {
				throw new UnsupportedOperationException();
			}
			
		};
	}

	@Override
	public boolean add(String e) {
		int calculatedFirstKnowingTheLastPosition = (last-1)%tab.length;
		if(calculatedFirstKnowingTheLastPosition == -1)
			calculatedFirstKnowingTheLastPosition = tab.length-1;
		if(first == calculatedFirstKnowingTheLastPosition){
			manageOverflow();
		}
		last--;
		if(last<=-1)
			last= tab.length-1;
		tab[last] = e;
		if(first == -1)
			first = last;
		return true;
	}

	@Override
	public boolean retainAll(Collection<?> c) {
		throw new UnsupportedOperationException();
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
		System.out.println("\n\n##################################");
		System.out.println("#  Working without the capacity  #");
		System.out.println("##################################\n");
		MaDoubleFileNoCapacity file = new MaDoubleFileNoCapacity();
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
	}
}
