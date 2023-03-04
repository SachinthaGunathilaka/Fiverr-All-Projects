package Practical_12;

import java.util.Objects;

public class FootballLeague {
    private LinkedList teams;

    public FootballLeague() {
        teams = new LinkedList();
    }

    public void addTeam(Team team) {
        teams.insert(team);
        teams.sortList();
        teams.displayTable();
    }

    public void removeTeam(Team team) {
        teams.remove(team);
        teams.sortList();
        teams.displayTable();

    }

    public void displayTable() {
        teams.displayTable();
    }

    public void playGame(Team team1, Team team2, Team winning_team) {

        if (winning_team == null) {
            teams.updateDetails(team1, 0);
            teams.updateDetails(team2, 0);

            System.out.println("Game between " + team1.getName() + " and " + team2.getName() +
                    ". " + "Game draw.");
        } else if (Objects.equals(team1.getName(), winning_team.getName())){
            teams.updateDetails(team1, 1);
            teams.updateDetails(team2, -1);

            System.out.println("Game between " + team1.getName() + " and " + team2.getName() +
                    ". " + team1.getName() + " beats " + team2.getName() + ".");
        } else if (Objects.equals(team2.getName(), winning_team.getName())) {
            teams.updateDetails(team1, -1);
            teams.updateDetails(team2, 1);
            System.out.println("Game between " + team1.getName() + " and " + team2.getName() +
                    ". " + team2.getName() + " beats " + team1.getName() + ".");
        }

        teams.sortList();
        teams.displayTable();

    }

    public void relegateTeams(int n){
        teams.relegateTeams(n);
        teams.displayTable();
    }
}
