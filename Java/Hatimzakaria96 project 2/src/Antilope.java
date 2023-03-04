// Fichier :     Antilope.java
// Création:     
// Auteurs :     
//
// Ce code n'est pas protégé par un copyright.
// 
// Historique :
//  Créé pour le cours IFT1025 H22
//

/**
 * class Antilope
 * extends Animal
 **/

// Antilope class (Sub class of Animal class)
class Antilope extends Animal{
    // static variable to hold the Maximum age of Anitilope
    // Set it to 15
    public static int AGEMAX = 15;

    // Constructor
    // Parameter => growth factor
    public Antilope(double antelopeGrowthFactor){
        // set maturityAge to 2
        maturityAge = 2;

        // set max age  and growth factor
        maxAge = Antilope.AGEMAX;
        growthFactor = antelopeGrowthFactor;

        // set prey as true
        prey = true;
    }



}
