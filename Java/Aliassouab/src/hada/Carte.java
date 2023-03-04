package hada;

import hada.Carteaction.action;
import hada.Cartenoir.effet;

public abstract class Carte {
	couleur col;
	action act=null;
	String nom;
	effet acti=null;
	int num;
	enum couleur{bleue,rouge,jaune,vert,noir};
	public Carte(couleur cole) {
		setCol(cole);
	}
	
	public couleur getCol() {
		return col;
	}
	public void setCol(couleur col) {
		this.col = col;
	}
	
	
	

}
