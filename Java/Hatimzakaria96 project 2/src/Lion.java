// Fichier :     Lion.java
// Création:     
// Auteurs :
//
// Ce code n'est pas protégé par un copyright.
// 
// Historique :
//  Créé pour le cours IFT1025 H22
//

/**
   class Lion
    extends Animal

**/

// Lion class (Sub class of Animal class)
class Lion extends Animal{
    // static variable to hold the Maximum age of Anitilope
    // Set it to 50
    public static int AGEMAX = 50;

    // Constructor
    // Parameter => growth factor
    public Lion(double lionGrowthFactor){
        // set maturityAge to 5
        maturityAge = 5;

        // set max age  and growth factor
        maxAge = Lion.AGEMAX;
        growthFactor = lionGrowthFactor;

        // set prey as false
        predator = true;
    }
}
