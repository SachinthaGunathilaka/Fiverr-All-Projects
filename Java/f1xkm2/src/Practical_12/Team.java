package Practical_12;

public class Team  implements Comparable<Team>{
    private String name;
    private int wins;
    private int losses;
    private int draws;
    private int points;

    public Team(String name) {
        this.name = name;
        this.wins = 0;
        this.draws = 0;
        this.losses = 0;
        this.points = 0;

    }

    public String getName() {
        return name;
    }

    public int getWins() {
        return wins;
    }

    public int getLosses() {
        return losses;
    }

    public int getDraws() {
        return draws;
    }

    public int getPoints() {
        return points;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setWins(int wins) {
        this.wins = wins;
    }

    public void setLosses(int losses) {
        this.losses = losses;
    }

    public void setDraws(int draws) {
        this.draws = draws;
    }

    public void setPoints(int points) {
        this.points = points;
    }

    public String toString(){
        return "Team name: " + name + " ,wins : " + wins + " draws: " + draws + " losses: " + losses + " points: " + points;
    }

    public int compareTo(Team team) {
        return Integer.compare(this.points, team.points);
    }
}
