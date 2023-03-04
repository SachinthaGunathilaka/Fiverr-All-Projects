import java.util.RandomAccess;
import java.util.Scanner;

public class Rosters {
    private PlayerRoster[] rosters;
    private int roster_count;

    public Rosters() {
        this.rosters = new PlayerRoster[5];
        this.roster_count = 0;
    }

    public void addRoster(int jersey_num, int rating) {
        PlayerRoster roster = new PlayerRoster(jersey_num, rating);

        this.rosters[roster_count++] = roster;
    }

    public void outputRoster() {
        System.out.println("\nROSTER");
        for (int i = 0; i < 5; i++) {
            System.out.println("Player " + (i + 1) + " -- " + rosters[i]);
        }
    }

    public boolean updateRoster(int jersey_number, int new_rating) {
        for (int i = 0; i < roster_count; i++) {
            if (rosters[i].getJersey_number() == jersey_number) {
                rosters[i].setRating(new_rating);
                return true;
            }
        }

        return false;
    }

    public void outputPlayersAboveRating(int rating) {
        System.out.println("\nABOVE " + rating);
        for (int i = 0; i < roster_count; i++) {
            if (rosters[i].getRating() > rating)
                System.out.println("Player " + (i + 1) + " -- " + rosters[i]);
        }
    }

    public void replacePlayer(int jersey_number){
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < roster_count; i++) {
            if(rosters[i].getJersey_number() == jersey_number){
                System.out.println("\nEnter a new jersey number: ");
                int new_jersey_num = Integer.parseInt(scanner.nextLine());

                System.out.println("Enter a rating for the new player: ");
                int rating = Integer.parseInt(scanner.nextLine());

                PlayerRoster roster = new PlayerRoster(new_jersey_num, rating);
                rosters[i] = roster;
                return;
            }
        }

        System.out.println("Jersey number does not exist!");
    }


}
