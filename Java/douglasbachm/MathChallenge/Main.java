import java.util.*;
import java.io.*;

public class Main {

    public static int MathChallenge(int num1, int num2) {
        if (num2 == 0) return num1;
        return MathChallenge(num2, num1 % num2);
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print(MathChallenge(s.nextLine()));

    }
}
