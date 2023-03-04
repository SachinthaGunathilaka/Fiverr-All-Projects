package hada;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

import hada.Carte.couleur;
import hada.Carteaction.action;
import hada.Cartenoir.effet;

public class Eenscarte {
    private ArrayList<Carte> cards = new ArrayList<Carte>();

	public ArrayList<Carte> getCards() {
		return cards;
	}

	public void setCards(ArrayList<Carte> cards) {
		setCards(cards);
	}
	public Boolean estvide() {
		return cards.isEmpty() ;	
	}
	public int taille() {
		cards.size();
		return cards.size();
		
	}
	//pour melanger les cartes 
	public void swap(ArrayList<Carte> a, int i, int j){
		Carte tmp = a.get(i);
		a.set(i, a.get(j));
		a.set(j, tmp);
		}
	public void melange(ArrayList<Carte> list, Random rnd){
		for (int i = list.size(); i > 1; i--)
		swap(list, i - 1, rnd.nextInt(i));
		}
	public Eenscarte() {
		cards.add(new Cartenormale(0,couleur.bleue));
		cards.add(new Cartenormale(0,couleur.rouge));
		cards.add(new Cartenormale(0,couleur.vert));
		cards.add(new Cartenormale(0,couleur.jaune));
		for(int j=0; j<2;j++) {
			for(int i=0;i<9;i++) {
				cards.add(new Cartenormale(i+1,couleur.bleue));
				cards.add(new Cartenormale(i+1,couleur.rouge));
				cards.add(new Cartenormale(i+1,couleur.jaune));
				cards.add(new Cartenormale(i+1,couleur.vert));
			}
			
		}
		for(int j=0;j<2;j++) {
		cards.add(new Carteaction(couleur.bleue,Carteaction.action.ajouterdeux));
		cards.add(new Carteaction(couleur.vert,action.ajouterdeux));
		cards.add(new Carteaction(couleur.jaune,action.ajouterdeux));
		cards.add(new Carteaction(couleur.rouge,action.ajouterdeux));
		cards.add(new Carteaction(couleur.bleue,action.changsens));
		cards.add(new Carteaction(couleur.vert,action.changsens));
		cards.add(new Carteaction(couleur.rouge,action.changsens));
		cards.add(new Carteaction(couleur.jaune,action.changsens));
		cards.add(new Carteaction(couleur.bleue,action.passetour));
		cards.add(new Carteaction(couleur.vert,action.passetour));
		cards.add(new Carteaction(couleur.rouge,action.passetour));
		cards.add(new Carteaction(couleur.jaune,action.passetour));
		
	}
	for(int i=0;i<4;i++) {
		cards.add(new Cartenoir(couleur.noir,effet.ajoutquatre));
		cards.add(new Cartenoir(couleur.noir,effet.joker));
		
	}
		
		
		
	}
	
	

}
