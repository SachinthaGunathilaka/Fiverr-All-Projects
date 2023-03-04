// Fichier :     Population.java
// Création:     
// Auteurs :     
//
// Ce code n'est pas protégé par un copyright.
// 
// Historique :
//  Créé pour le cours IFT1025 H22
//

/**
   class Population
    implements EcoSysteme, Iterable<Animal>

**/

import java.util.Iterator;
import java.lang.Iterable;
import java.util.Collections;
import java.util.ArrayList;
import java.util.Random;

// Defines a population of herb and animals (preys and predators), iterable
public class Population implements EcoSysteme, Iterable<Animal> {

    // TO BE COMPLETED //
    private ArrayList<Animal> individus = new ArrayList<>();

    public Population( Herbe herbe, ArrayList<Animal> proies, ArrayList<Animal> predateurs ) {
	
	// TO BE COMPLETED //
	
    }

    // TO BE COMPLETED //
    public ArrayList<Animal> getIndividus(){
		return this.individus;
	}
}
