package exercice2;

public class FilePleineException extends Exception {
	
	public FilePleineException(String[] file, String elem) {
		super();
	}
	
	public String toString(){
		StringBuilder sb = new StringBuilder();
		sb.append(super.toString());
		sb.append("\nTrying to add a new element to a full array");
		return sb.toString();
	}

}
