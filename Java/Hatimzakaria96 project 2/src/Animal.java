// Fichier :     Animal.java
// Création:     
// Auteurs :      
//
// Ce code n'est pas protégé par un copyright.
// 
// Historique :
//  Créé pour le cours IFT1025 H22
//

/**
 * class Animal
 * implements the Prey/Predator relationship
 **/


// Animal class
class Animal implements ProiePredateur {

    // Attributes
    protected boolean alive;
    private int age;
    protected int maxAge;
    protected int maturityAge;
    private double mass;
    protected boolean prey;
    protected boolean predator;
    protected double growthFactor;

    // Default constructor
    public Animal() {
        age = 0;
        mass = 10;
        alive = true;
        prey = false;
        predator = false;
    }

    // naitre() method
    @Override
    public void naitre() {
        // set alive to true
        alive = true;
    }

    // vieillir method
    @Override
    public void vieillir() {
        // Call manger method to increase the mass
        manger();
        // Increment age by 1
        age++;

        // If age is greater than maxAge set alive as false (Die the animal)
        if (age > maxAge)
            alive = false;
    }

    // manger() method
    @Override
    public void manger() {
        // Multiply mass with growthFactor
        // set that value as the new mass
        setMasse(getMasse() * growthFactor);
        ;
    }

    // accoucher() method
    @Override
    public Animal accoucher() {
        // Return this animal object
        return this;
    }

    // Method to kill the animal
    @Override
    public void mourir() {
        alive = false;
    }

    // Method to check whether the animal is alive or not
    @Override
    public boolean estVivant() {
        return alive;
    }

    // Method to check whether the animal is mature or not
    @Override
    public boolean estMature() {
        // If the animal is alive and age of the animal is greater or equal to maturityAge return true
        return (age >= maturityAge) && (alive);
    }

    // Method to set the animal as a prey
    @Override
    public void setProie(boolean proie) {
        prey = proie;
    }

    // Method to check whether the animal is a prey or not
    @Override
    public boolean estProie() {
        // If the animal is a prey return true
        return prey && alive;
    }

    public void setPredateur(boolean predateur) {
        predateur = true;
    }

    // Method to check whether the animal is a predator or not
    public boolean estPredateur() {
        // If the animal is a not a prey return true
        return predator && alive;
    }

    // Getters
    @Override
    public double getMasse() {
        return mass;
    }

    @Override
    public int getAge() {
        return age;
    }

    @Override
    public int getAgeMax() {
        return maxAge;
    }

    @Override
    public int getAgeMature() {
        return maturityAge;
    }


    // Setters
    @Override
    public void setMasse(double masse) {
        mass = masse;
    }

    @Override
    public void setAge(int age) {
        this.age = age;
    }


}
