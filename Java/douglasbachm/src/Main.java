import java.util.*;
import java.io.*;

public class Main {

    public static String StringChallenge(String str){
        String result = "";
        boolean flag = false;
        for (int i = 0; i < str.length(); i++) {
            char ch = Character.toLowerCase(str.charAt(i));

            if(flag){
                result += Character.toUpperCase(ch);
                flag = false;
                continue;
            }
            if(!Character.isLetter(ch)){
                flag = true;
            }else {
                result += ch;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        String token = "qbfetxod2";

        // keep this function call here
        Scanner s = new Scanner(System.in);


        StringBuilder final_output = new StringBuilder(StringChallenge(s.nextLine()) + ":" +token);
//        StringBuilder final_output = new StringBuilder(token  + ":" + StringChallenge("cats AND*Dogs-are Awesome"));
//        StringBuilder final_output = new StringBuilder(token  + ":" + StringChallenge("a b c d-e-f%g"));
        final_output.reverse();

        System.out.print(final_output);

    }
}
