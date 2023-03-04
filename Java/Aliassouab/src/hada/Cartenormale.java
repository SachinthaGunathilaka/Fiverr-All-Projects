package hada;

public class Cartenormale extends Carte{
	final int  cout;
	private final String nom="carte numerotée";
	private int num;
	public Cartenormale(int nm, couleur col) {
		super(col);
		this.num=nm;
		this.cout=nm;
		// TODO Auto-generated constructor stub
	}
	public Boolean Cartejouable(Carte defausse) {
		return this.num==defausse.num || this.col==defausse.col;	
	}
	public int getNum() {
		return num;
	}
	public void setNum(int num) {
		this.num = num;
	}
	public String getNom() {
		return nom;
	}
	

	

}
