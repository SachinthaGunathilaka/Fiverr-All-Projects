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
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;
import java.util.stream.Collectors;

public class NestingChecker {
    /*
     * Instructor-provided code to assist your development and testing.  Do not alter these methods.
     */
    @SuppressWarnings("unused")
    private static final long serialVersionUID = 8683452581122892189L;

    /*
     * This function converts a String to a Queue of NestableCharacter
     */
    public static Queue<NestableCharacter> getNestableCharactersFromString(String input) {
        return input.chars().mapToObj(NestableCharacter::new)
                .collect(Collectors.toCollection(LinkedList<NestableCharacter>::new));
    }

    /*
     * This function reads a file into a Queue of NestableCharacter
     */
    public static Queue<NestableCharacter> getNestableCharactersFromFile(String filename) throws IOException {
        Queue<NestableCharacter> out = new LinkedList<>();
        FileReader in = new FileReader(filename);

        while (in.ready())
            out.add(new NestableCharacter(in.read()));
        in.close();

        return out;
    }

    /*
     * This function reads an HTML file and outputs its structure as the HtmlTags
     * only. You do not need to modify this code for this assignment but can use it
     * for your testing!
     */
    public static Queue<HtmlTag> getTagsFromHtmlFile(String filename) throws IOException {
        InputStream stream = new FileInputStream(filename);
        StringBuffer buffer = new StringBuffer();
        int ch;
        while ((ch = stream.read()) > 0) {
            buffer.append((char) ch);
        }
        stream.close();
        String htmlFileString = buffer.toString();
        return HtmlTag.tokenize(htmlFileString);
    }

    /*
     * A function to interactively try your nesting checker. "jshell" is an easy way to use this.
     * From a command line in the directory with your java files, run:
     *    jshell Nestable.java NestingReport.java NestableCharacter.java HtmlTag.java NestingChecker.java
     * On the jshell command line, run:
     *    NestingChecker.interact();
     */
    public static void interact() {
        java.util.Scanner in = new java.util.Scanner(System.in);
        System.out.println("Nesting reports will be printed for each line of text you enter." +
                "\nEnter a line with only \".\" to stop");

        String line;
        boolean done = false;
        do {
            System.out.print("check> ");
            System.out.flush();
            line = in.nextLine();
            if (line == null || line.equals(".")) {
                done = true;
                System.out.println("Thank you for using the interactive nesting checker. Have a nice day.");
            } else {
                Queue<? extends Nestable> characters = getNestableCharactersFromString(line);
                NestingReport result = checkNesting(characters);
                System.out.println(result);
                System.out.println();
            }
        } while (!done);
    }

    /*
     * Implement this method! It must return a non-null NestingReport and should not
     * throw an exception.
     */


    public static void main(String args[]) {
        Queue<HtmlTag> elements = new LinkedList<HtmlTag>();

        try {
            File myObj = new File("a.html");
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                String line = myReader.nextLine();
                String [] words = line.split(" |\n|\t");
                for (String word: words) {
                    word = word.strip();
                    if(word.startsWith("<") && word.endsWith(">")){
                        word = word.substring(1, word.length()-1);
                        if(word.startsWith("/"))
                            elements.add(new HtmlTag(word.substring(1), Nestable.NestEffect.CLOSE));

                        else
                            elements.add(new HtmlTag(word, Nestable.NestEffect.OPEN));

                    }
                    else{
                        elements.add(new HtmlTag(word, Nestable.NestEffect.NEUTRAL));

                    }
                }
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }



//        Queue<? extends Nestable> elements = {'(', '[', '2', 'A', ']', '+', 'E', ')'};
//        Queue<? extends Nestable> elementsFailing = {'(', '[', '2', 'A', ']', '+', 'E'};
//        Queue<? extends Nestable> elementsFailing2 = {'[', '[', '2', 'A', ']', '+', ')'};
//
//
        NestingReport report = checkNesting(elements);
         System.out.println(report.toString());

    }

    public static NestingReport checkNesting(Queue<? extends Nestable> elements) {
        Nestable b;
        Nestable ch;
        Stack<Nestable> stack = new Stack<>();

        // if queue completly empty
        if (elements.isEmpty()) {
            return new NestingReport(NestingReport.Status.NULL_INPUT, null, null);
        }


        // 1. get each character from queue (        <head=HTML1.2(bill){sdsad}>), looping
        while (!elements.isEmpty()) {
            b = elements.poll();

            if (b == null) {
                return new NestingReport(NestingReport.Status.NULL_ITEM, null, stack);
            }

            if (b.getEffect() == Nestable.NestEffect.CLOSE) {
                ch = stack.pop();

                if (ch.getEffect() == Nestable.NestEffect.OPEN) {
                    if (!ch.matches(b)) {
                        stack.push(ch);
                        return new NestingReport(NestingReport.Status.INVALID_CLOSE, b, stack);
                    }
                }
            } else if (b.getEffect() == Nestable.NestEffect.OPEN) {
                stack.push(b);
            }
        }

        if (stack.empty()) {
            // good
            return new NestingReport(NestingReport.Status.VALID, null, stack);
        } else {
            // bad (still things left over to match)
            return new NestingReport(NestingReport.Status.NOT_TERMINATED, null, stack);
        }

        /*
        for (Character c : elements)
        {
        	if (c == null)  return new NestingReport(NestingReport.Status.NULL_ITEM, null, stack);
        		
        	if (c == '{' || c == '(' || c == '[')
        	{
        		stack.push(c);	
        	}
        	
        	if (c == '}') 
        	{
        		if (stack.peek() == '{')
        		{
        			// good
    				stack.pop();
        		}
        		else
        		{
        			// bad 
        	        return new NestingReport(NestingReport.Status.INVALID_CLOSE, c, stack);
        		}
        	}
        	if (c == ')') 
        	{
        		if (stack.peek() == '(')
        		{
        			// good
    				stack.pop();
        		}
        		else
        		{
        			// bad 
        	        return new NestingReport(NestingReport.Status.INVALID_CLOSE, c, stack);
        		}
        	}
        	if (c == ']')
        	{
        		if (stack.peek() == '[')
        		{
        			// good
    				stack.pop();
        		}
        		else
        		{
        			// bad 
        	        return new NestingReport(NestingReport.Status.INVALID_CLOSE, c, stack);
        		}
        	}
        	
        }
        
        if (stack.empty())
        {
        	// good
	        return new NestingReport(NestingReport.Status.VALID, null, stack);
        }
        else
        {
        	// bad (still things left over to match)
	        return new NestingReport(NestingReport.Status.NOT_TERMINATED, null, stack);
        }
        */
        // 2. put them in the stack
        // 2A. if char is opening parenthesis, psuh to stack
        // 2B. if it is closing, take it out of the stack
        // 2C. fail
        // 3. when queue is empty/done, does stack still have stuff?

    }


    public static int RPNCalculator(String input){

    }
}
