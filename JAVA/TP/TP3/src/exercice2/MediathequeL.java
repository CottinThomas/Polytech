package exercice2;

import java.util.ArrayList;

public class MediathequeL {
	private String nomMediatheque;
	private ArrayList<Media> medias;
	private int prochainIdentifiant;
	
	public MediathequeL(String unNom) {
		this.nomMediatheque = unNom;
		this.medias = new ArrayList<Media>();
	}
	
	public Media getMedia(int ident) throws MediaNotFoundedException{
		for(Media media : medias){
			if(media.getNumeroMedia() == ident)
				return media;
		}
		throw new MediaNotFoundedException(ident);
	}
	
	public Media retirerMedia(int ident){
		try{
			Media mediaToDelete = getMedia(ident);
			medias.remove(mediaToDelete);
			return mediaToDelete;
		} catch(MediaNotFoundedException e){
			e.printStackTrace();
		}
		return null;
	}
	
	public boolean ajouterMedia(Media media) throws MediaDejaPresent{
		if(medias.contains(media)){
			throw new MediaDejaPresent(media);
		}
		else{
			media.setNumeroMedia(prochainIdentifiant);
			prochainIdentifiant++;
			medias.add(media);
			return true;
		}
	}
	
	public static void main(String[] args) {
		
		MediathequeL mediatheque = new MediathequeL("My mediatheque");
		Livre l1 = new Livre("Martine a la plage", 15);
		Livre l2 = new Livre("Jojo l'escargot", 13);
		Livre l3 = new Livre("L'assomoire", 500);
		CdAudio cd1 = new CdAudio("BlackIce", 123);
		CdAudio cd2 = new CdAudio("666667Club", 125);
		CdAudio cd3 = new CdAudio("Bleu pétrol", 200);
		
		try{
			mediatheque.ajouterMedia(l1);
			mediatheque.ajouterMedia(l2);
			mediatheque.ajouterMedia(l3);
			mediatheque.ajouterMedia(cd1);
			mediatheque.ajouterMedia(cd2);
			mediatheque.ajouterMedia(cd3);
		} catch(Exception e){
			e.printStackTrace();
		}
		
		
	}
	
}
