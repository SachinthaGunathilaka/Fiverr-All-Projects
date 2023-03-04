package hada;


import java.util.Random;
import java.util.Scanner;

import java.util.ArrayList;

public class Joueur {
	String nom;
	private int numero;//pour la position du joueur
	private int score=0;
	private ArrayList<Carte> Main = new ArrayList<Carte>();
	Joueur suivant;
	Joueur precedent;
	Carte.couleur couleurchoisi;
	 Scanner lect=new Scanner(System.in);
	public Joueur(String nom, int numero) {
		this.nom = nom;
		setNumero(numero);
	}
	public ArrayList<Carte> getMain() {
		return Main;
	}
	public void setMain(ArrayList<Carte> main) {
		this.Main = main;
	}
	
	public int getNumero() {
		return numero;
	}
	public void setNumero(int numero) {
		this.numero = numero;
	}
	public int getScore() {
		return score;
	}
	public void setScore(int score) {
		this.score = score;
	}
	public void gagnant(Joueur e) {
		if (e.Main.isEmpty()) {
			System.out.println("vous étes gagnant yeeeeeees ;)");
		}
	}
	
	//la terminer????????????????????
	 public void piocher(Eenscarte car, int i,ArrayList<Carte> talon) {
		 Carte tmp=null;
		 int rep;
		 Random r= new Random();
		 int rr;
		 for(int j1=0;j1<i;j1++) {
			 rr=r.nextInt(car.getCards().size());
			 tmp = car.getCards().get(rr);
			 car.getCards().remove(rr);
			 getMain().add(tmp);
		 }
		 if(i==1) {
			System.out.println("Vous avez pioché une carte: "+this.Main.get(Main.size()-1).nom+" "+this.Main.get(Main.size()-1).num+" "+this.Main.get(Main.size()-1).col);//Lire quelle carte			
			 do {
				 System.out.println("voulez vous la jouer(oui:1 non:0): ");
				 rep=lect.nextInt(); 
				 
			 }while (rep!=1 && rep!=0);
			 if(rep==1) {
				 talon.add(tmp);
				 this.Main.remove(tmp);
			 }	 
		 }
	 }
	 
	 public void choisir(Eenscarte car,Carte def,ArrayList<Carte> talon) {
		 String rep = null;
		 int i;
		 boolean faire=false;
		 System.out.println("voulez vous jouer (/j)ou piocher(/p) ou voir la main(/m):  ");
		 rep=lect.next();
		 do {
			 switch (rep){
			 case ("/p"):
				 this.piocher(car,1,talon);
			 case ("/j"):
				 this.poser1(def,talon);
			 case ("/m"):
				 //c'est fauxxxxxxxx 
				 System.out.println("vous avez les cartes suivantes en ordre (de gauche):  ");
				 
				for(int b=0;b<this.Main.size();b++) {
					String fct=null;
					 if(Main.get(b) instanceof Cartenormale) {
						 fct=("")+Main.get(b).num;
					 }
					 if(Main.get(b).act==Carteaction.action.ajouterdeux) {
						 fct="+2";	 
					 }
					 if(Main.get(b).act==Carteaction.action.changsens) {
						 fct="changersens";
					 }
					 if(Main.get(b).act==Carteaction.action.passetour) {
						 fct="passer le tour";
					 }
					 if(Main.get(b).acti==Cartenoir.effet.ajoutquatre) {
						 fct="+4";
					 }
					 if(Main.get(b).acti==Cartenoir.effet.joker) {
						 fct="joker";
					 }
					 System.out.println(" "+fct+" "+Main.get(b).col);
					
				}
				
		 default : faire=true;
			 }	 
		 }while (faire);
	 }

	
	
	public ArrayList Cartejouable(Carte defausse) {
		ArrayList<Carte> cartejouable = null;
		for(int i=0;i<this.Main.size();i++) {
			if (this.Main.get(i).nom=="carte numerotée") {
				if(this.Main.get(i).num==defausse.num || this.Main.get(i).col==defausse.col)
				    cartejouable.add(i, this.Main.get(i));
			}
			if(defausse.act==Carteaction.action.ajouterdeux) {
				if(this.Main.get(i).col==defausse.col) {
					cartejouable.add(i, this.Main.get(i));
				}	
			}
			if(defausse.act==Carteaction.action.changsens) {
				if((this.Main.get(i).col==defausse.col) || (this.Main.get(i).act.equals(defausse.act.changsens))) {
					cartejouable.add(i, this.Main.get(i));
				}	
			}
			if(defausse.act==Carteaction.action.passetour) {
				if((this.Main.get(i).col==defausse.col) || (this.Main.get(i).act.equals(defausse.act.passetour))) {
					cartejouable.add(i, this.Main.get(i));
				}	
			}
			if (this.Main.get(i).acti==Cartenoir.effet.ajoutquatre) {
				cartejouable.add(i, this.Main.get(i));	
			}
			if (this.Main.get(i).acti==Cartenoir.effet.joker ) {
				cartejouable.add(i, this.Main.get(i));	
			}
			if (defausse.acti==Cartenoir.effet.joker || defausse.acti==Cartenoir.effet.ajoutquatre ) {
				if(this.getMain().get(i).col== couleurchoisi) {
					cartejouable.add(i, this.Main.get(i));
				}
				
			}
			
			
			
				
			
		}
		return cartejouable;
	}
	
	
	public Carte poser1(Carte defausse,ArrayList<Carte> talon) { 
		int i;
		Carte tmp;
		this.Cartejouable(defausse);
		do {
		  System.out.println("poser une carte jouable (entrer sa position): ");
		  i=lect.nextInt();
		}while (!(this.Cartejouable(defausse).contains( this.Main.get(i))));
		tmp =this.Main.get(i);
		/*if(tmp.acti==Cartenoir.effet.joker) {
			this.choisircouleur();
			
		}
		if(tmp.acti==Cartenoir.effet.ajoutquatre) {
			//pensez à la méthode bluffer 
			this.choisircouleur();
		}*/
		 talon.add(i, tmp);;
		 getMain().remove(tmp);
		return this.Main.get(i);
	}
	
	
	public void choisircouleur() {
		String coler=null;
		while(coler!="jaune" && coler!="rouge" && coler!="vert" && coler!="bleue") {
			System.out.println("choisissez la couleur: ");
			coler=lect.next();
			coler=coler.toLowerCase();
			if(coler=="jaune") {
				couleurchoisi=Carte.couleur.jaune;
			}
			if(coler=="rouge") {
				couleurchoisi=Carte.couleur.rouge;
			}
			if(coler=="bleue") {
				couleurchoisi=Carte.couleur.bleue;
			}
			if(coler=="vert") {
				couleurchoisi=Carte.couleur.vert;
			}
			
		}
		
		
	}
	
	
	public boolean bluffer(Carte def) {
		boolean bluf=false;
		int i=0;
		while(!bluf && i<this.Main.size()) {
			bluf=Main.get(i).col==def.col;	
		}
		return bluf;		
	}
}