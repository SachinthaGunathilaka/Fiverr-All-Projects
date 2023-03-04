package hada;

import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class Partie {
	 Eenscarte car = new Eenscarte();
	 int nbjoueurs;
	 Joueur[] players;
	 Random n= new Random();
	 int i=0;
	 int grandscore=0;
	 int petitscore=10000;
	 ArrayList<Carte> TALON= new ArrayList<Carte>();
	// Eenscarte defausse;//les cartes deja jouées 
	 Scanner lect=new Scanner(System.in);
	 //liste des carte piocher soit pour la distribution de 7 soit l'ajout de 2 ou de 4
	 public void distribuer() {
		 int j=0;
		 car.melange(car.getCards(), n);
		 System.out.println("Entrer le nombre des joueurs: ");
		 nbjoueurs=lect.nextInt();
		 players = new Joueur[nbjoueurs];
		 /*for(int j=0;j<=nbjoueurs-1;j++) {
			 System.out.println("entrer le nom du joueur"+j+1+": ");
			 players[j].nom=lect.next();
			 players[j].setNumero(j+1);
			 players[j].piocher(car,6,TALON);
			 if(j<nbjoueurs-1) {
				 players[j].suivant=players[j+1]; 
			 }
			 else players[j].suivant=players[0];
			 if(j>0) {
				 players[j].precedent=players[j-1];
			 }
			 else players[j].precedent=players[nbjoueurs-1];
		 }*/
		 while(j<nbjoueurs) {
			 players[j]= new Joueur("",0);
			 System.out.println("entrer le nom du joueur"+(j+1)+": ");
			 players[j].nom=lect.next();
			 players[j].setNumero(j);
			 players[j].piocher(car,6,TALON);
			 if(j<nbjoueurs-1) {
				 players[j].suivant=players[j+1]; 
			 }
			 else players[j].suivant=players[0];
			 if(j>0) {
				 players[j].precedent=players[j-1];
			 }
			 else players[j].precedent=players[nbjoueurs-1];
			 j++;
			 
		 }
		 
	 }	 
	 
	 //methode pour afficher à chaque fois ce que un joueur a posé 
	 public void affichecartejouée(Joueur d,Carte cartejouee) {
		 String fct=null;
		 if(cartejouee.act==Carteaction.action.ajouterdeux) {
			 fct="+2";	 
		 }
		 if(cartejouee.act==Carteaction.action.changsens) {
			 fct="changersens";
		 }
		 if(cartejouee.act==Carteaction.action.passetour) {
			 fct="passer le tour";
		 }
		 if(cartejouee.acti==Cartenoir.effet.ajoutquatre) {
			 fct="+4";
		 }
		 if(cartejouee.acti==Cartenoir.effet.joker) {
			 fct="joker";
		 }
		 if(cartejouee.nom=="carte numerotée") {
			 fct=("")+d.getNumero();
		 }
		 System.out.println(""+d.nom+" joue"+fct);
		 
	 }
	 public void posetalon() {
		 int j=car.taille()-1;
		 Carte d=null;
		 car.melange(car.getCards(),n);
		 d=car.getCards().get(j);
		 while(d.acti==Cartenoir.effet.ajoutquatre) {
			 car.melange(car.getCards(),n);
			 d=car.getCards().get(j);	 
		 }
		 TALON.add(d);
		 car.getCards().remove(j);
		 if(d.act==Carteaction.action.ajouterdeux) {
			 players[i].piocher(car, 2, TALON);
			 i++;
		 }
		 if(d.act==Carteaction.action.changsens) {
			 //faut terminer
		 }
		 if(d.act==Carteaction.action.passetour) {
			 i++;
		 }
		 if(d.acti==Cartenoir.effet.joker) {
			 players[i].choisircouleur();
			 players[i].choisir(car, d, TALON);
			 i++;
		 }	 
	 }
	 
	 public void Manche() { 
		 String rep;
		 Joueur v;
		 boolean finmanche=false;
		//distribution et declaration des joueurs
		 distribuer();
		 posetalon();
		 while(!finmanche) {//ici
			 players[i].choisir(car,TALON.get(TALON.size()-1), TALON);
			 if(players[i].poser1(TALON.get(TALON.size()-1), TALON).act==Carteaction.action.ajouterdeux) {
				 players[i].suivant.piocher(car, 2, TALON);
				 i=players[i].suivant.suivant.getNumero();
			 }
			 if(players[i].poser1(TALON.get(TALON.size()-1), TALON).act==Carteaction.action.changsens) {
				 for(int j=0;j<nbjoueurs;j++) {
					 v=players[j].precedent;
					 players[j].precedent=players[j].suivant;
					 players[j].suivant=v;
					 
				 }
				 i=players[i].suivant.getNumero();
				 
			 }
			 if(players[i].poser1(TALON.get(TALON.size()-1), TALON).act==Carteaction.action.passetour) {
				 i=players[i].suivant.suivant.getNumero();
			 }
			 if(players[i].poser1(TALON.get(TALON.size()-1), TALON).acti==Cartenoir.effet.ajoutquatre) {
				 System.out.println("voulez vous faire un défi?(oui/non) : ");
				 rep=lect.next();
				 if(rep=="oui"||rep=="Oui"|| rep=="OUI") {
					 if(players[i].bluffer(TALON.get(TALON.size()-1))) {
						 players[i].piocher(car, 4, TALON);
						 i=players[i].suivant.getNumero();
					 }else {
						 players[i].suivant.piocher(car, 6, TALON);
						 i=players[i].suivant.suivant.getNumero();
					 }
				 }else {
					 players[i].suivant.piocher(car, 4, TALON);
					 i=players[i].suivant.suivant.getNumero();
					 
				 } 
			 }
			 if(players[i].poser1(TALON.get(TALON.size()-1), TALON).acti==Cartenoir.effet.joker) {
				players[i].choisircouleur();
				 i=players[i].suivant.getNumero();
			 }
			 if(players[i].poser1(TALON.get(TALON.size()-1), TALON) instanceof Cartenormale) {
			     i=players[i].suivant.getNumero();
			 }
			 if(players[i].poser1(TALON.get(TALON.size()-1), TALON)==null) {
				 i=players[i].suivant.getNumero();
			 }
			 if(i==players.length-1) {
				 i=players[i].suivant.getNumero();
			 }
			 if (players[i].getMain().isEmpty()) {
				 finmanche=true;
				 
			 }
			 vidertalon();//la condition est dedans 
			 
			 
			 
		 }
		 for(int z=0;z<players.length;z++) {
			 for(int j=0;j<players[z].getMain().size();j++) { 
				 players[z].setScore(players[z].getScore()+players[z].getMain().get(j).num);
			 }
			 System.out.println(""+players[z].nom+": "+players[z].getScore());
		 }
		 
	 }
	 public void vidertalon() {
		 if (car.estvide()) {
			 for(int i=0;i<TALON.size()-1;i++) {
				 car.getCards().add(TALON.get(i));
				 TALON.remove(i);
			 }
			 car.melange(car.getCards(), n);
			 
			 
		 }
	 }
	 public void plusgrandscore() {
		 for(int f=0;f<nbjoueurs;f++) {
			 if(players[f].getScore()>grandscore) {
				 grandscore=players[f].getScore();
			 }
		 }	 
	 }
	 public void pluspetitscore() {
		 for(int m=0;m<nbjoueurs;m++) {
			 if(players[m].getScore()<petitscore) {
				 petitscore=players[m].getScore();
			 }
			 	 
		 }
		 
	 }
	 public boolean egalite() {
		 int occ=0;
		 for(int q=0;q<nbjoueurs;q++) {
			 if(players[q].getScore()==petitscore){
				 occ=occ+1;
				 
			 }
		 }
		 return (occ>=2);
	 }
	 public void partie() {
		 do {
			 do {
				 Manche();
				 plusgrandscore();
				
			 }while(grandscore<=500);
			 pluspetitscore();
			 egalite();
			 
		 }while(egalite());
		 for(int f=0;f<nbjoueurs;f++) {
			 if(players[i].getScore()==petitscore) {
				 System.out.println("le joueur "+players[f].nom+"  est le gangant d'un score de "+players[f].getScore());
			 }
		 }
		
	 } 
}


