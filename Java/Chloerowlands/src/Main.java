import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.println("\nWelcome to Wormhole.");


        System.out.println("Please enter the width dimension of your board?");
        int width = Integer.parseInt(scanner.nextLine());

        while (width < 5 || width > 10) {
            System.out.println("Width should be between 5 - 10");
            System.out.println("Please enter the width dimension of your board?");
            width = Integer.parseInt(scanner.nextLine());
        }
        Game game = new Game(width);
        game.generateBoard();

        System.out.println("\nPlease enter the number of players?");
        int players = Integer.parseInt(scanner.nextLine());

        for (int i = 0; i < players; i++) {
            System.out.println("\nPlease enter the name of player " + (i + 1) + "?");
            game.addPlayer(scanner.nextLine());
        }

        game.setModes();


        System.out.println("\nLet's play.");
        game.playGame();


    }
}
