import java.util.*;
import java.io.*;

class Main {

    public static String ArrayChallenge(String[] strArr) {
        for (int i = 1; i < strArr[0].length(); i++) {
            String first = strArr[0].substring(0, i);
            String second = strArr[0].substring(i);

            String[] array = strArr[1].split(",");

            boolean flag = false;

            int count = 0;
            for (int j = 0; j < array.length; j++) {
                if (Objects.equals(array[j], first)) {
                    count++;
                    break;
                }
            }

            for (int j = 0; j < array.length; j++) {
                if (Objects.equals(array[j], second)) {
                    count++;
                    break;
                }
            }

            if (count == 2)
                return first + "," + second;
        }

        return "not possible";
    }

    public static void main (String[] args) {
        String token = "qbfetxod2";
        int index = 4;
        char replaced_val = '_';

//        String [] input = new String[]{"baseball", "a,all,b,ball,bas,base,cat,code,d,e,quit,z"};
//        String [] input = new String[]{"abcgefd", "a,ab,abc,abcg,b,c,dog,e,efd,zzzz"};

        // keep this function call here
        Scanner s = new Scanner(System.in);
        StringBuilder final_output = new StringBuilder(ArrayChallenge(s.nextLine()) + token);
//        StringBuilder final_output = new StringBuilder(token+ ":"+ ArrayChallenge(input));
        final_output.reverse();

        System.out.print(final_output);
    }

}