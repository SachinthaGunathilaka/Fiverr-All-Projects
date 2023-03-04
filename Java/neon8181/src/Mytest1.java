/**
 * MyTest1 implements an application that
 * displays four lines containing "Waves and Sailboats".
 *
 * @author yourName
 * @version 15.02
 * @since 10-03-2021
 */
public class Mytest1 {

    public static void main(String[] args) {
        int tab = 9;
        int nline = 10;
        int wave = 126;
        int air = 32;
        int hull = 95;
        int mast = 47;
        int sail = 41;
        String boat = "";

        boat = boat.concat(Character.toString((char) hull) + (char) mast + (char) sail);


        for (int i = 0; i < 2; i++) {
            System.out.printf("%s%s%s%s%s%s%c", Character.toString((char) tab).repeat(2), Character.toString((char) wave).repeat(4),
                    boat, Character.toString((char) wave).repeat(5), boat, Character.toString((char) wave).repeat(7), (char)nline);

            System.out.printf("%s%s%c", Character.toString((char) wave).repeat(5).concat(boat).repeat(2),
                    Character.toString((char) wave).repeat(14), (char)nline);

        }
    }
}
