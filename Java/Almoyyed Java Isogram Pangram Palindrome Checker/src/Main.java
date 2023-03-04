/*
    A program to check whether the given word, phrase or sentence is an isogram, a pangram, a palindrome,
    or none of these.
 */
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("---*-*-*-*-*-*-*-*-*-*-*-*- Welcome to Play with Words-*-*-*-*-*-*-*-*-*-*-*-*---");

        String option;
        do {

            // Get user input
            System.out.print("Please enter a word, phrase, or sentence: ");
            String sentence = scanner.nextLine();
            System.out.print("\"" + sentence + "\"" +  " >>>");

            // Call functions
            boolean palindrome = isPalindrome(sentence);
            boolean pangram = isPangram(sentence);
            boolean isogram = isIsogram(sentence);

            // Display the output
            if(pangram && isogram){
                System.out.println(" is a Perfect Pangram.");
            }
            else if(palindrome && pangram){
                System.out.println(" is a Palindromic Pangram.");
            }
            else if(palindrome && isogram){
                System.out.println(" is a Palindromic Isogram.");
            }
            else if(pangram){
                System.out.println(" is a Pangram.");
            }
            else if(palindrome){
                System.out.println(" is a Palindrome.");
            }
            else if(isogram){
                System.out.println(" is a Isogram.");
            }
            else{
                System.out.println(" does not have any interesting linguistic phenomena.");
            }
            System.out.println("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");

            // Ask from the user whether he wants to play again
            System.out.print("\n\nWould like to play again: ");
            option = scanner.nextLine();

        }while (option.toLowerCase().charAt(0) == 'y');

        System.out.println("\tThank you for playing :)");

    }

    // Check whether the given string is a pangram
    public static boolean isPangram(String sentence) {
        String temp_sentence = sentence.toLowerCase();
        String existingChars = "";
        for (int i = 0; i < temp_sentence.length(); i++) {
            char ch = temp_sentence.charAt(i);
            if (existingChars.indexOf(ch) == -1 && Character.isAlphabetic(ch)) {
                existingChars += ch;
            }
        }
        if (existingChars.length() == 26) {
            return true;
        }
        return false;
    }

    // Check whether the given string is a isogram
    public static boolean isIsogram(String sentence) {
        String temp_sentence = sentence.toLowerCase();
        String existingChars = "";
        for (int i = 0; i < temp_sentence.length(); i++) {
            char ch = temp_sentence.charAt(i);

            if(!Character.isAlphabetic(ch))
                continue;
            if (existingChars.indexOf(ch) != -1) {
                return false;
            }
            existingChars += ch;
        }

        return true;
    }

    // Check whether the given string is a palindrome
    public static boolean isPalindrome(String sentence) {
        String temp_sentence = sentence.toLowerCase();
        String alphabetic_chars = "";
        for (int i = 0; i < temp_sentence.length(); i++) {
            if(Character.isAlphabetic(temp_sentence.charAt(i)))
                alphabetic_chars += temp_sentence.charAt(i);
        }

        for (int i = 0; i < alphabetic_chars.length()/2; i++) {
            if(alphabetic_chars.charAt(i) != alphabetic_chars.charAt(alphabetic_chars.length()-1-i))
                return false;
        }
        return true;
    }
}

/*
    Sample Inputs
    ---------------------------------------------------
    Fundamentals of Object Oriented Programming
    xnylwefsgabdhpziuqvtkcojrmrjocktvquizphdbagsfewlynx
    Mr. Owl ate my metal worm
    By Jove, my quick study of lexicography won a prize!
    GQ's oft lucky whiz Dr. J, ex-NBA MVP
    The big dwarf only jumps
    computerizably
    noon
 */
