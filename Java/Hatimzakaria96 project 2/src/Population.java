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
 * class Population
 * implements EcoSysteme, Iterable<Animal>
 **/

import java.util.Iterator;
import java.lang.Iterable;
import java.util.Collections;
import java.util.ArrayList;
import java.util.Random;

// Defines a population of herb and animals (preys and predators), iterable
public class Population implements EcoSysteme, Iterable<Animal> {


    // ArrayList to hold the all animals
    private ArrayList<Animal> individus = new ArrayList<>();
    // Herbe object
    private Herbe herbe;


    // Constructor
    public Population(Herbe herbe, ArrayList<Animal> proies, ArrayList<Animal> predateurs) {
        // set  herbe
        this.herbe = herbe;

        // put proies and predateurs into one list called animals
        individus = proies;
        individus.addAll(predateurs);
    }


    // method to get the number of proies
    @Override
    public int getNombreProies() {
        // Initialize numOfPreys to 0
        int numOfPreys = 0;

        // Iterate through each animal in animals list
        for (Animal animal : individus) {
            // If the current animal is a prey and alive
            if (animal.estProie()  && animal.estVivant())
                // Increment numOfPreys by 1
                numOfPreys++;
        }

        // return numOfPreys
        return numOfPreys;
    }

    // method to get the number of predators
    @Override
    public int getNombrePredateurs() {
        // Initialize numOfPredators to 0
        int numOfPredators = 0;

        // Iterate through each animal in animals list
        for (Animal animal : individus) {
            // If the current animal is a predator and alive
            if (animal.estPredateur() && animal.estVivant() )
                // Increment numOfPredators by 1
                numOfPredators++;
        }

        // return numOfPredators
        return numOfPredators;
    }

    // method to get the number of mature preys
    @Override
    public int getNombreProiesMatures() {
        // Initialize numOfMaturePreys to 0
        int numOfMaturePreys = 0;

        // Iterate through each animal in animals list
        for (Animal animal : individus) {
            // If the current animal is a prey and alive and mature
            if (animal.estProie() && animal.estVivant() && animal.estMature())
                // Increment numOfMaturePreys by 1
                numOfMaturePreys++;
        }

        // return numOfMaturePreys
        return numOfMaturePreys;
    }

    // method to get the number of mature predators
    @Override
    public int getNombrePredateursMatures() {
        // Initialize numOfMaturePreys to 0
        int numOfMaturePredator = 0;

        // Iterate through each animal in animals list
        for (Animal animal : individus) {
            // If the current animal is a predators and alive and mature
            if (animal.estPredateur() && animal.estVivant() && animal.estMature())
                // Increment numOfMaturePredator by 1
                numOfMaturePredator++;
        }
        // return numOfMaturePredator
        return numOfMaturePredator;
    }

    // method to get number of chassable preys
    @Override
    public int getNombreProiesChassables() {
        // return 20% of number  of preys
        return (int) Math.floor(getNombreProies() * 0.2);
    }

    // method to get total mass of proies
    @Override
    public double masseProies() {
        // Initialise preysMass to 0
        double preysMass = 0;

        // Iterate through each animal in animals list
        for (Animal animal : individus) {
            // If animal is a prey and alive
            if (animal.estProie()) {
                // Increment preysMass by the mass of the current animal
                preysMass += animal.getMasse();
            }
        }

        // return preysMass
        return preysMass;
    }

    // method to get total mass of predators
    @Override
    public double massePredateurs() {
        // Initialise predatorMass to 0
        double predatorMass = 0;

        // Iterate through each animal in animals list
        for (Animal animal : individus) {
            // If animal is a predator and alive
            if (animal.estPredateur()) {
                // Increment predatorMass by the mass of the current animal
                predatorMass += animal.getMasse();
            }
        }

        // return predatorMass
        return predatorMass;
    }

    // vieillir method
    @Override
    public void vieillir() {

        // Iterate through each animal in animals list
        for (Animal animal : individus) {
            // call vieillir for each animal(To increase age and eat)
            animal.vieillir();
        }
    }

    // chasser() method
    @Override
    public void chasser() {
        // shuffle the animals list
        melanger();

        // calculate number of chassable preys
       int numOfChaseablePreys = (int) Math.floor(getNombreProies() * 0.2);

        // Iterate through each animal in animals list
        for (Animal animal : individus) {
            // If the animal is died skip it
            if (!animal.alive)
                continue;

            // If the animal is a predator
            if (animal.estPredateur()) {
                // If there is no chassable preys left
                if (numOfChaseablePreys == 0) {
                    // Predator died
                    animal.mourir();
                    // skip to next animal
                    continue;
                }

                // calculate the mass that the predator should eat (Twice of the mass)
                double toEatMass = animal.getMasse() * 2;

                // Iterate through each animal in the animals list
                for (Animal prey : individus) {

                    // If predator has eaten to his limit
                    if (toEatMass <= 0)
                        // Terminate this loop and go to next animal
                        break;

                    // If the animal is prey
                    if (prey.estProie()) {
                        // Eat that prey and decrease toEatMass by mass of the prey
                        toEatMass -= prey.getMasse();

                        // Decrement numOfChaseablePreys by 1
                        numOfChaseablePreys--;
                        // Kill that prey
                        prey.mourir();
                    }
                }
            }

            // If the animal is a prey
            if (animal.estProie()) {
                // If prey has enough grass to eat
                if (herbe.getMasse() >= animal.getMasse() * 2) {
                    // Decrease mass of the total grass
                    herbe.setMasse(herbe.getMasse() - animal.getMasse() * 2);
                }
                // Otherwise, prey is died
                else {
                    animal.mourir();

                }
            }
        }

    }

    // reproduire() method
    @Override
    public void reproduire() {

        // If number of mature preys is a odd number
        if (getNombreProiesMatures() % 2 == 1) {

            // Set not mature prey as mature
            for (Animal animal : individus) {
                if (animal.estProie() && !animal.estMature() && animal.estVivant()) {
                    animal.setAge(5);
                    break;
                }
            }
        }

        // Calculate the number of prey babies (Half of number of prey matures)
        int preyBabies = (int) (getNombreProiesMatures() / 2);

        // Calculate the number of predator babies (Half of number of predator matures)
        int predatorBabies = (int) (getNombrePredateursMatures() / 2);

        if (getNombrePredateursMatures() % 2 == 1) {
                predatorBabies++;

            }

        // Create prey objects equals to number of babies
        for (int i = 0; i < preyBabies; i++) {
            individus.add(new Antilope(1));
        }

        // Create predator objects equals to number of babies
        for (int i = 0; i < predatorBabies; i++) {
            individus.add(new Lion(1));
        }


    }

    // method to shuffle the animals list
    @Override
    public void melanger() {
        Collections.shuffle(this.individus, new Random(4));
    }

    // Iterator method
    @Override
    public Iterator<Animal> iterator() {
        return individus.iterator();
    }

    // method to get animals list
    public ArrayList<Animal> getIndividus() {
        return individus;
    }
}
