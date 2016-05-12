package exercice2;

public class MediaDejaPresent extends Exception {
	
	private Media media;
	
	public MediaDejaPresent(Media media){
		super();
		this.media = media;
	}
	
	public Media getMedia(){
		return media;
	}
	
	public String toString(){
		StringBuilder sb = new StringBuilder();
		sb.append(super.toString());
		sb.append("\n");
		sb.append(media.toString());
		return sb.toString();
	}

}
