package Practical_12;

public class Dashboard {

    public static void main(String[] args) {
        FootballLeague footballLeague = new FootballLeague();
        Team team1 = new Team("Manchester United");
        Team team2 = new Team("Manchester City");
        Team team3 = new Team("Arsenal");
        Team team4 = new Team("Barcelona");
        Team team5 = new Team("Liverpool");

        System.out.println("\nAdding and Removing Teams\n");
        footballLeague.addTeam(team1);
        footballLeague.addTeam(team2);
        footballLeague.addTeam(team3);
        footballLeague.removeTeam(team5);
        footballLeague.addTeam(team4);
        footballLeague.addTeam(team5);
        footballLeague.removeTeam(team3);
        footballLeague.removeTeam(team3);

        System.out.println("\nPlaying Games\n");
        footballLeague.playGame(team1, team2, team1);
        footballLeague.playGame(team2, team4, team2);
        footballLeague.playGame(team1, team4, null);
        footballLeague.playGame(team1, team5, team5);
        footballLeague.playGame(team3, team5, null);
        footballLeague.playGame(team4, team5, team5);

        System.out.println("\nRelegating Teams\n");
        footballLeague.relegateTeams(3);


    }
}
