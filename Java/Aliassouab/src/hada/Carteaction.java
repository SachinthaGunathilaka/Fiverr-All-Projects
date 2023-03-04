package hada;

public class Carteaction extends Carte {
	final int num=20; //pour le cout 
	action act;
	String nom;
    enum action{ ajouterdeux,changsens,passetour};
	public Carteaction(couleur col,action act) {
		super( col);
	    this.act=act;   
	}
	public Boolean Cartejouable(Carte defausse) {
		return (this.act==defausse.act);
		
	}
	public void Nom() {
		if(this.act==act.ajouterdeux) {
			nom="+2";
		}
		if(this.act==act.changsens) {
			nom="changersens";
		}
		if(this.act==act.passetour) {
			nom="passtour";
		}
		
	}
	
		
	

}
