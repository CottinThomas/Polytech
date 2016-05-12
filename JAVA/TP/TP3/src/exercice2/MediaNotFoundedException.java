package exercice2;

public class MediaNotFoundedException extends Exception {
	
	int ident;
	
	public MediaNotFoundedException(int ident){
		super();
		this.ident=ident;
	}
	
	public String toString(){
		StringBuilder sb = new StringBuilder();
		sb.append(super.toString());
		sb.append("\n");
		sb.append("Id : "+ident);
		return sb.toString();
	}
	
}
