/*
 * I attest that the code in this file is entirely my own except for the starter
 * code provided with the assignment and the following exceptions:
 * <Enter all external resources and collaborations here.>
 *
 * Note external code may reduce your score but appropriate citation is required
 * to avoid academic integrity violations. Please see the Course Syllabus as
 * well as the university code of academic integrity:
 *    https://catalog.upenn.edu/pennbook/code-of-academic-integrity/
 *
 * Signed,
 * Author: YOUR NAME HERE
 * Penn email: <YOUR-EMAIL-HERE@seas.upenn.edu>
 * Date: YYYY-MM-DD
 */

import java.io.*;
import java.util.*;

public class Analyzer {

    /*
     * Implement this method in Part 1
     */
    public static List<Sentence> readFile(String filename) {

        List<Sentence> sentences = new ArrayList<Sentence>();
        {
            try {
                FileInputStream fis = new FileInputStream(filename);
                Scanner sc = new Scanner(fis);
                while (sc.hasNextLine()) {
                    String line = sc.nextLine();
                    String [] score_text = line.split("\\s", 2);

                    try {
                        int score = Integer.parseInt(score_text[0]);
                        if(score < -2 || score > 2)
                            continue;

                        Sentence sentence = new Sentence(score, score_text[1]);
                        sentences.add(sentence);


                    }catch (Exception e){
                        continue;
                    }


                }
                sc.close();
            } catch (Exception e) {
                return new ArrayList<Sentence>();
            }

            return sentences;


        }
    }

        /*
         * Implement this method in Part 2
         */
        public static Set<Word> allWords (List < Sentence > sentences) {

            HashMap<String, Word> wordHashMap = new HashMap<String, Word>();

            if(sentences == null)
                return new HashSet<>(wordHashMap.values());


            for (Sentence s:sentences) {
                if(s == null || s.getText().length() == 0)
                    continue;
                String [] s_words = s.getText().toLowerCase().split(" ");

                for (String word:s_words) {
                    if(word.length() == 0 || !Character.isAlphabetic(word.charAt(0)))
                        continue;

                    Word temp;
                    if(wordHashMap.containsKey(word)){
                        temp = wordHashMap.get(word);
                    }
                    else{
                        temp = new Word(word);
                    }
                    temp.increaseTotal(s.getScore());
                    wordHashMap.put(word, temp);

                }
            }

            return new HashSet<>(wordHashMap.values());


        }

        /*
         * Implement this method in Part 3
         */
        public static Map<String, Double> calculateScores (Set < Word > words) {
            Map<String, Double> scores= new HashMap<String, Double>();

            for (Word word:words) {
                if(word == null)
                    continue;

                scores.put(word.getText(), word.calculateScore());
            }

            return scores;
        }

        /*
         * Implement this method in Part 4
         */
        public static double calculateSentenceScore (Map < String, Double > wordScores, String sentence){
            if(wordScores == null || wordScores.isEmpty())
                return 0;
            String [] words = sentence.split(" ");

            double score = 0;
            int count = 0;
            for (String word: words) {
                if(word.length() == 0)
                    continue;

                if(wordScores.containsKey(word)){
                    score += wordScores.get(word);
                }
                count++;
            }

            if(count != 0)
                return score/count;

            return 0;
        }

        /*
         * You do not need to modify this code but can use it for testing your program!
         */
        public static void main (String[] args){
            if (args.length == 0) {
                System.out.println("Please specify the name of the input file");
                System.exit(0);
            }
            String filename = args[0];
            System.out.print("Please enter a sentence: ");
            Scanner in = new Scanner(System.in);
            String sentence = in.nextLine();
            in.close();
            List<Sentence> sentences = Analyzer.readFile(filename);


            Set<Word> words = Analyzer.allWords(sentences);

            Map<String, Double> wordScores = Analyzer.calculateScores(words);

            double score = Analyzer.calculateSentenceScore(wordScores, sentence);
            System.out.println("The sentiment score is " + score);
        }
    }
