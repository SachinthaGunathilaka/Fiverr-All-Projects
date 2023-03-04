import java.util.Scanner;

public class PlayerRoster {

    private int jersey_number;
    private int rating;


    public PlayerRoster(int jersey_number, int rating) {
        this.jersey_number = jersey_number;
        this.rating = rating;
    }

    public String toString() {
        return "Jersey number: " + jersey_number + ", Rating: " + rating;
    }

    public int getJersey_number() {
        return jersey_number;
    }

    public int getRating() {
        return rating;
    }

    public void setRating(int rating) {
        this.rating = rating;
    }
}