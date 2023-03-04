import java.util.ArrayList;
import java.util.Locale;
import java.util.Random;
import java.util.Scanner;

public class Game {
    private int width;
    private ArrayList<Player> players;


    private ArrayList<Integer> holes;
    private ArrayList<Integer> positive_holes;
    private ArrayList<Integer> negative_holes;

    Game(int width) {
        this.width = width;
        players = new ArrayList<Player>();
        holes = new ArrayList<Integer>();
        positive_holes = new ArrayList<Integer>();
        negative_holes = new ArrayList<Integer>();
    }

    public void generateBoard() {
        Random rand = new Random();


        for (int i = 0; i < width * 2; i++) {
            int rand_num = rand.nextInt(width * width - 2) + 1;
            while (holes.contains(rand_num))
                rand_num = rand.nextInt(width * width - 2) + 1;
            holes.add(rand_num);
        }

        for (int i = 0; i < width; i++) {
            if (holes.get(i) < holes.get(i + width)) {
                positive_holes.add(holes.get(i));
                positive_holes.add(holes.get(i + width));
            } else {
                negative_holes.add(holes.get(i));
                negative_holes.add(holes.get(i + width));
            }

        }


        System.out.print("\nThank you. The board has " + width * width + " squares. ");
        if (positive_holes.size() == 0)
            System.out.println("There are no positive wormholes.");
        else if (positive_holes.size() == 2) {
            System.out.print("There is a positive wormhole at " + (positive_holes.get(0) + 1));
            System.out.println(" and wormhole exists at " + (positive_holes.get(1) + 1) + ".");
        } else {
            System.out.print("There are positive wormhole entrances at ");
            for (int i = 0; i < positive_holes.size() / 2; i++) {
                if (i == positive_holes.size() / 2 - 1)
                    System.out.print(positive_holes.get(i * 2) + 1);
                else
                    System.out.print((positive_holes.get(i * 2) + 1) + ", ");
            }
            System.out.print(" and wormholes exist at ");
            for (int i = 0; i < positive_holes.size() / 2; i++) {
                if (i == positive_holes.size() / 2 - 1)
                    System.out.println((positive_holes.get(i * 2 + 1) + 1) + ".");
                else
                    System.out.print((positive_holes.get(i * 2 + 1) + 1) + ", ");
            }
        }
        if (negative_holes.size() == 0)
            System.out.println("There are no negative wormholes.");
        else if (negative_holes.size() == 2) {
            System.out.print("There is a negative wormhole at " + (negative_holes.get(0) + 1));
            System.out.println(" and wormhole exists at " + (negative_holes.get(1) + 1) + ".");
        } else {
            System.out.print("There are negative wormhole entrances at ");
            for (int i = 0; i < negative_holes.size() / 2; i++) {
                if (i == negative_holes.size() / 2 - 1)
                    System.out.print(negative_holes.get(i * 2) + 1);
                else
                    System.out.print((negative_holes.get(i * 2) + 1) + ", ");
            }
            System.out.print(" and wormholes exist at ");
            for (int i = 0; i < negative_holes.size() / 2; i++) {
                if (i == negative_holes.size() / 2 - 1)
                    System.out.println((negative_holes.get(i * 2 + 1) + 1) + ".");
                else
                    System.out.print((negative_holes.get(i * 2 + 1) + 1) + ", ");
            }
        }
    }

    public void addPlayer(String name) {
        Player player = new Player(name);
        players.add(player);
    }


    public int getNumOfPlayers() {
        return players.size();
    }

    public void setModes() {

        Scanner scanner = new Scanner(System.in);
        for (Player player : players) {
            System.out.println("\n" + player.getName() + " - " + "do you want to roll the dice, or shall I do it for you? \n" +
                    "Type \"Y\" to roll yourself or \"N\" to let me do it.");

            String choice = scanner.nextLine().toUpperCase(Locale.ROOT);
            while (!choice.equals("Y") && !choice.equals("N")) {
                System.out.println("\nInvalid Input");
                System.out.println(player.getName() + " - " + "do you want to roll the dice, or shall I do it for you? Type \"Y\" to roll yourself or \"N\" to let me do it.");
                choice = scanner.nextLine().toUpperCase(Locale.ROOT);
            }

            if (choice.equals("Y"))
                player.setMode(1);
            else
                player.setMode(0);
        }

    }

    public void displayGame() {
        System.out.println();
        for (Player player : players) {
            if (player.getPosition() + 1 == width * width)
                System.out.println(player.getName() + " is in square " + (player.getPosition() + 1) + " and has won!");
            else
                player.display();
        }
    }

    public void playGame() {


        Scanner scanner = new Scanner(System.in);
        boolean gameOver = false;

        while (true) {
            while (!gameOver) {
                for (Player player : players) {
                    displayGame();

                    if (gameOver)
                        break;
                    if (player.getMode() == 1) {
                        System.out.println("\n" + player.getName() + " - please roll the dice.");

                        while (true) {

                            try {
                                String[] dices = scanner.nextLine().split(",");
                                int dice1 = Integer.parseInt(dices[0]);
                                int dice2 = Integer.parseInt(dices[1]);

                                System.out.println(dice1 + " " + dice2);


                                player.setPosition(player.getPosition() + dice1 + dice2, width);

                                System.out.print("\n" + player.getName() + " moves to square " + (player.getPosition() + 1));

                                boolean isNegative = false;
                                for (int i = 0; i < negative_holes.size(); i += 2) {
                                    if (negative_holes.get(i) == player.getPosition()) {
                                        isNegative = true;
                                        System.out.println(" which is a NEGATIVE wormhole....");
                                        player.setPosition(negative_holes.get(i + 1), width);
                                        System.out.println(">>>>>>>>>>>>>>>>>> exit at " + (negative_holes.get(i + 1) + 1));
                                        break;
                                    }
                                }

                                boolean isPositive = false;
                                if (!isNegative) {
                                    for (int i = 0; i < positive_holes.size(); i += 2) {
                                        if (positive_holes.get(i) == player.getPosition()) {
                                            isPositive = true;
                                            System.out.println(" which is a POSITIVE wormhole....");
                                            player.setPosition(positive_holes.get(i + 1), width);
                                            System.out.println(">>>>>>>>>>>>>>>>>> exit at " + (positive_holes.get(i + 1) + 1));
                                            break;
                                        }
                                    }
                                }


                                if (!isNegative && !isPositive) {
                                    System.out.println(".");
                                }

                                break;


                            } catch (Exception e) {
                                System.out.println("\nInvalid Input");
                                System.out.println(player.getName() + " - please roll the dice.");

                            }


                        }

                    } else {
                        Random random = new Random();
                        int dice1 = random.nextInt(6) + 1;
                        int dice2 = random.nextInt(6) + 1;

                        System.out.println("\n" + player.getName() + " rolls " + dice1 + ", " + dice2 + ".");
                        player.setPosition(player.getPosition() + dice1 + dice2, width);
                        player.display();

                    }

                    if (player.getPosition() + 1 == width * width) {
                        gameOver = true;
                    }


                }
            }

            System.out.println("\nWould you like to play again? (Type \"Y\" to play again, or \"N\" to exit)");

            String yorn = scanner.nextLine().toUpperCase(Locale.ROOT);

            if (!yorn.equals("Y"))
                break;


        }


    }


}
