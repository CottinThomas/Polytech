package exercice2_implements_Deque;

import java.util.Collection;
import java.util.Deque;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class MaDoubleFileImpDeque implements Deque<String>{

	private String[] queue;
	private int first;
	private int last;
	
	public MaDoubleFileImpDeque(){
		this.queue = new String[5];
		this.first = -1;
		this.last = -1;
	}
	
	public void increaseQueue(){
		if(this.size() == queue.length){
			String[] tab = new String[queue.length*2];
			Iterator<String> itr = this.descendingIterator();
			int pos = 0;
			while(itr.hasNext()){
				tab[pos] = itr.next();
				pos++;
			}
			first = queue.length-1;
			last = 0;
			this.queue = tab;
		}
	}
	
	@Override
	public boolean isEmpty() {
		return this.size()==0;
	}

	@Override
	public Object[] toArray() {
		String[] tab = new String[this.size()];
		Iterator<String> itr = this.iterator();
		int pos = 0;
		while(itr.hasNext()){
			tab[pos] = itr.next();
			pos++;
		}
		return tab;
	}

	@Override
	public <T> T[] toArray(T[] a) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public boolean containsAll(Collection<?> c) {
		boolean contains = true;
		for(Object e  : c){
			if(e==null)
				throw new NullPointerException();
			if(!(e instanceof String))
				throw new ClassCastException();
			contains &= this.contains(e);
			if(contains == false)
				break;
		}
		return contains;
	}

	@Override
	public boolean addAll(Collection<? extends String> c) {
		for(Object e : c){
			if(e==null)
				throw new NullPointerException();
			if(!(e instanceof String))
				throw new ClassCastException();
			this.add((String)e);
		}
		return true;
	}

	@Override
	public boolean removeAll(Collection<?> c) {
		boolean contains = false;
		for(Object e : c){
			if(e==null)
				throw new NullPointerException();
			if(!(e instanceof String))
				throw new ClassCastException();
			boolean removed;
			do{
				removed = this.remove(e);
				contains = contains || removed;
			}while(removed);
		}
		return true;
	}

	@Override
	public boolean retainAll(Collection<?> c) {
		// TODO
		return false;
	}

	@Override
	public void clear() {
		this.first = -1;
		this.last = -1;
	}

	@Override
	public void addFirst(String e) {
		if(e == null)
			throw new NullPointerException();
		this.increaseQueue();
		first++;
		if(first == queue.length)
			first = 0;
		queue[first] = e;
		if(last == -1) // only happens at first insertion
			last = first;
	}

	@Override
	public void addLast(String e) {
		if(e == null)
			throw new NullPointerException();
		this.increaseQueue();
		last--;
		if(last <= -1)
			last = queue.length-1;
		queue[last] = e;
		if(first == -1) // only happens at first insertion
			first = last;
	}

	@Override
	public boolean offerFirst(String e) {
		if(e == null)
			throw new NullPointerException();
		this.increaseQueue();
		first++;
		if(first == queue.length)
			first = 0;
		queue[first] = e;
		if(last == -1) // only happens at first insertion
			last = first;
		return true;
	}

	@Override
	public boolean offerLast(String e) {
		if(e == null)
			throw new NullPointerException();
		this.increaseQueue();
		last--;
		if(last <= -1)
			last = queue.length-1;
		queue[last] = e;
		if(first == -1) // only happens at first insertion
			first = last;
		return true;
	}

	@Override
	public String removeFirst() {
		if(this.size()==0)
			throw new NoSuchElementException();
		String element = queue[first];
		first--;
		if(first == -1)
			first = queue.length-1;
		return element;
	}

	@Override
	public String removeLast() {
		if(this.size()==0)
			throw new NoSuchElementException();
		String element = queue[last];
		last++;
		if(last == queue.length)
			last = 0;
		return element;
	}

	@Override
	public String pollFirst() {
		try{
			return this.removeFirst();
		}catch(NoSuchElementException e){
			return null;
		}
	}

	@Override
	public String pollLast() {
		try{
			return this.removeLast();
		}catch(NoSuchElementException e){
			return null;
		}
	}

	@Override
	public String getFirst() {
		if(this.size()==0)
			throw new NoSuchElementException();
		return queue[first];
	}

	@Override
	public String getLast() {
		if(this.size()==0)
			throw new NoSuchElementException();
		return queue[last];
	}

	@Override
	public String peekFirst() {
		try{
			return this.getFirst();
		}catch(NoSuchElementException e){
			return null;
		}
	}

	@Override
	public String peekLast() {
		try{
			return this.getLast();
		}catch(NoSuchElementException e){
			return null;
		}
	}

	@Override
	public boolean removeFirstOccurrence(Object o) {
		if(o == null)
			throw new NullPointerException();
		if(!(o instanceof String))
			throw new ClassCastException();
		Iterator<String> itr = this.iterator();
		boolean founded = false;
		while(! founded && itr.hasNext()){
			if(itr.next().equals(o)){
				itr.remove();
				return true;
			}
		}
		return false;
	}

	@Override
	public boolean removeLastOccurrence(Object o) {
		if(o == null)
			throw new NullPointerException();
		if(!(o instanceof String))
			throw new ClassCastException();
		Iterator<String> itr = this.descendingIterator();
		boolean founded = false;
		while(! founded && itr.hasNext()){
			if(itr.next().equals(o)){
				itr.remove();
				return true;
			}
		}
		return false;
	}

	@Override
	public boolean add(String e) {
		this.addLast(e);
		return true;
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
		return removeFirstOccurrence(o);
	}

	@Override
	public boolean contains(Object o) {
		if(o == null)
			throw new NullPointerException();
		if(!(o instanceof String))
			throw new ClassCastException();
		Iterator<String> itr = this.iterator();
		boolean founded = false;
		while(! founded && itr.hasNext()){
			if(itr.next().equals(o)){
				return true;
			}
		}
		return false;
	}

	@Override
	public int size() {
		if(first == -1 || last == -1)
			return 0;
		else if(first > last)
			return first-last+1;
		else
			return queue.length+first-last+1;
	}
	
	@Override
	public Iterator<String> iterator() {
		return new Iterator<String>() {
			
			int next = first;
			boolean oneLastMove = false;

			@Override
			public boolean hasNext() {
				if(oneLastMove){
					return true;
				}
				else return next != last;
			}

			@Override
			public String next() {
				if(this.hasNext()){
					String cur = queue[next];
					if(! oneLastMove){
						next--;
						if(next==-1)
							next=queue.length-1;
						if(next == last)
							oneLastMove = true;
					}
					else
						oneLastMove = false;
					return cur;
				}
				throw new NoSuchElementException();
			}

			@Override
			public void remove() {
				int pos = next++;
				pos++;
				if(pos>=queue.length)
					pos=0;
				while(pos != first){
					int posNext = pos+1;
					if(posNext == queue.length)
						posNext = 0;
					queue[pos] = queue[posNext];
					pos++;
					if(pos == queue.length)
						pos = 0;
				}
				first--;
			}
		};
	}

	@Override
	public Iterator<String> descendingIterator() {
		return new Iterator<String>() {
			
			int next = last;
			boolean oneLastMove = false;

			@Override
			public boolean hasNext() {
				if(oneLastMove){
					return true;
				}
				else return next != first;
			}

			@Override
			public String next() {
				if(this.hasNext()){
					String cur = queue[next];
					if(! oneLastMove){
						next++;
						if(next==queue.length)
							next=0;
						if(next == first)
							oneLastMove = true;
					}
					else
						oneLastMove = false;
					return cur;
				}
				throw new NoSuchElementException();
			}

			@Override
			public void remove() {
				int pos = next--;
				pos--;
				if(pos<=-1)
					pos=queue.length-1;
				while(pos != last){
					int posNext = pos-1;
					if(posNext == -1)
						posNext = queue.length-1;
					queue[pos] = queue[posNext];
					pos--;
					if(pos == -1)
						pos = queue.length-1;
				}
				last++;
			}
		};
	}
	
	public String toString(){
		StringBuilder sb = new StringBuilder();
		sb.append("SIZE = "+this.size()).append("\n");
		sb.append("FIRST = "+first).append("\n");
		sb.append("LAST = "+last).append("\n");
		int i = first;
		while(i != last){
			sb.append("Index : ").append(i).append("\tValue : ").append(queue[i]).append("\n");
			i--;
			if(i==-1){
				i=queue.length-1;
			}
		}
		sb.append("Index : ").append(last).append("\tValue : ").append(queue[last]).append("\n");
		return sb.append("\n").toString();
	}

}
