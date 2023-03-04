package hada;

public class Cartenoir extends Carte {
	final String couleur="noir";
	effet acti;
	final int num=20;
	String nom;
	enum effet{joker,ajoutquatre};

	public Cartenoir(couleur cole, effet act) {
		super(cole);
		this.acti=act;
		
		// TODO Auto-generated constructor stub
	}
	public void Nom() {
		if(this.acti==acti.ajoutquatre) {
			nom="+4";
		}
		if(this.acti==acti.joker) {
			nom="joker";
		}
		
	}

}
