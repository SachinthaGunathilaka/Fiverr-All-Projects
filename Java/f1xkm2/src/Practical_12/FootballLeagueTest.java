package Practical_12;

import org.junit.jupiter.api.Test;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

import static org.junit.jupiter.api.Assertions.*;

class FootballLeagueTest {

    FootballLeague footballLeague;
    private Team team1;
    private Team team2;
    private Team team3;
    private Team team4;
    private Team team5;
    private final ByteArrayOutputStream outContent = new ByteArrayOutputStream();
    private final PrintStream originalOut = System.out;

    @org.junit.jupiter.api.BeforeEach
    public void init() {

        footballLeague = new FootballLeague();
        team1 = new Team("Manchester United");
        team2 = new Team("Manchester City");
        team3 = new Team("Arsenal");
        team4 = new Team("Barcelona");
        team5 = new Team("Liverpool");
        System.setOut(new PrintStream(outContent));

    }

    @org.junit.jupiter.api.AfterEach
    public void restoreStreams() {
        System.setOut(originalOut);
    }

    @Test
    void addTeam() {

        footballLeague.addTeam(team1);
        footballLeague.addTeam(team2);
        footballLeague.addTeam(team1);
        String result = "Team Manchester United added to the league.\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Team                 | Points  | Wins    | Draws   | Losses  |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Manchester United    | 0       | 0       | 0       | 0       |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "Team Manchester City added to the league.\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Team                 | Points  | Wins    | Draws   | Losses  |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Manchester City      | 0       | 0       | 0       | 0       |\n" +
                "| Manchester United    | 0       | 0       | 0       | 0       |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "Team Manchester United already exists in the league.\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Team                 | Points  | Wins    | Draws   | Losses  |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Manchester City      | 0       | 0       | 0       | 0       |\n" +
                "| Manchester United    | 0       | 0       | 0       | 0       |\n" +
                "+----------------------|---------|---------|---------|---------+\n";
        assertEquals(result, outContent.toString().replace("\r", ""));


    }

    @Test
    void removeTeam() {
        footballLeague.addTeam(team1);
        footballLeague.addTeam(team2);
        footballLeague.addTeam(team3);
        footballLeague.removeTeam(team1);
        footballLeague.removeTeam(team5);
        footballLeague.removeTeam(team3);
        footballLeague.removeTeam(team2);
        footballLeague.removeTeam(team1);

        String result = "Team Manchester United added to the league.\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Team                 | Points  | Wins    | Draws   | Losses  |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Manchester United    | 0       | 0       | 0       | 0       |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "Team Manchester City added to the league.\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Team                 | Points  | Wins    | Draws   | Losses  |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Manchester City      | 0       | 0       | 0       | 0       |\n" +
                "| Manchester United    | 0       | 0       | 0       | 0       |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "Team Arsenal added to the league.\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Team                 | Points  | Wins    | Draws   | Losses  |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Arsenal              | 0       | 0       | 0       | 0       |\n" +
                "| Manchester City      | 0       | 0       | 0       | 0       |\n" +
                "| Manchester United    | 0       | 0       | 0       | 0       |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "Team Manchester United removed from the league.\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Team                 | Points  | Wins    | Draws   | Losses  |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Arsenal              | 0       | 0       | 0       | 0       |\n" +
                "| Manchester City      | 0       | 0       | 0       | 0       |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "Team Liverpool trying to remove from the league. It does not exists.\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Team                 | Points  | Wins    | Draws   | Losses  |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Arsenal              | 0       | 0       | 0       | 0       |\n" +
                "| Manchester City      | 0       | 0       | 0       | 0       |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "Team Arsenal removed from the league.\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Team                 | Points  | Wins    | Draws   | Losses  |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Manchester City      | 0       | 0       | 0       | 0       |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "Team Manchester City removed from the league.\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Team                 | Points  | Wins    | Draws   | Losses  |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "Team Manchester United trying to remove from the league. It does not exists.\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Team                 | Points  | Wins    | Draws   | Losses  |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "+----------------------|---------|---------|---------|---------+\n";
        assertEquals(result, outContent.toString().replace("\r", ""));
    }


    @Test
    void playGame() {
        footballLeague.addTeam(team1);
        footballLeague.addTeam(team2);
        footballLeague.addTeam(team3);

        footballLeague.playGame(team1, team2, team1);
        footballLeague.playGame(team2, team3, team2);
        footballLeague.playGame(team1, team3, null);
        String result = "Team Manchester United added to the league.\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Team                 | Points  | Wins    | Draws   | Losses  |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Manchester United    | 0       | 0       | 0       | 0       |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "Team Manchester City added to the league.\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Team                 | Points  | Wins    | Draws   | Losses  |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Manchester City      | 0       | 0       | 0       | 0       |\n" +
                "| Manchester United    | 0       | 0       | 0       | 0       |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "Team Arsenal added to the league.\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Team                 | Points  | Wins    | Draws   | Losses  |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Arsenal              | 0       | 0       | 0       | 0       |\n" +
                "| Manchester City      | 0       | 0       | 0       | 0       |\n" +
                "| Manchester United    | 0       | 0       | 0       | 0       |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "Game between Manchester United and Manchester City. Manchester United beats Manchester City.\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Team                 | Points  | Wins    | Draws   | Losses  |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Manchester United    | 3       | 1       | 0       | 0       |\n" +
                "| Manchester City      | 0       | 0       | 0       | 1       |\n" +
                "| Arsenal              | 0       | 0       | 0       | 0       |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "Game between Manchester City and Arsenal. Manchester City beats Arsenal.\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Team                 | Points  | Wins    | Draws   | Losses  |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Manchester United    | 3       | 1       | 0       | 0       |\n" +
                "| Manchester City      | 3       | 1       | 0       | 1       |\n" +
                "| Arsenal              | 0       | 0       | 0       | 1       |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "Game between Manchester United and Arsenal. Game draw.\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Team                 | Points  | Wins    | Draws   | Losses  |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Manchester United    | 4       | 1       | 1       | 0       |\n" +
                "| Manchester City      | 3       | 1       | 0       | 1       |\n" +
                "| Arsenal              | 1       | 0       | 1       | 1       |\n" +
                "+----------------------|---------|---------|---------|---------+\n";
        assertEquals(result, outContent.toString().replace("\r", ""));
    }

    @Test
    void displayTable() {
        footballLeague.addTeam(team1);
        footballLeague.addTeam(team2);
        footballLeague.addTeam(team3);
        footballLeague.addTeam(team4);
        footballLeague.addTeam(team5);

        footballLeague.playGame(team1, team2, team1);
        footballLeague.playGame(team2, team3, team2);
        footballLeague.playGame(team1, team3, null);

        outContent.reset();
        footballLeague.displayTable();
        String result = "+----------------------|---------|---------|---------|---------+\n" +
                "| Team                 | Points  | Wins    | Draws   | Losses  |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Manchester United    | 4       | 1       | 1       | 0       |\n" +
                "| Manchester City      | 3       | 1       | 0       | 1       |\n" +
                "| Arsenal              | 1       | 0       | 1       | 1       |\n" +
                "| Barcelona            | 0       | 0       | 0       | 0       |\n" +
                "| Liverpool            | 0       | 0       | 0       | 0       |\n" +
                "+----------------------|---------|---------|---------|---------+\n";
        assertEquals(result, outContent.toString().replace("\r", ""));

        outContent.reset();
        footballLeague.playGame(team4, team5, team5);
        footballLeague.playGame(team1, team5, null);
        footballLeague.playGame(team3, team4, team3);
        outContent.reset();

        footballLeague.displayTable();
        result = "+----------------------|---------|---------|---------|---------+\n" +
                "| Team                 | Points  | Wins    | Draws   | Losses  |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Manchester United    | 5       | 1       | 2       | 0       |\n" +
                "| Liverpool            | 4       | 1       | 1       | 0       |\n" +
                "| Arsenal              | 4       | 1       | 1       | 1       |\n" +
                "| Manchester City      | 3       | 1       | 0       | 1       |\n" +
                "| Barcelona            | 0       | 0       | 0       | 2       |\n" +
                "+----------------------|---------|---------|---------|---------+\n";
        assertEquals(result, outContent.toString().replace("\r", ""));

    }

    @Test
    public void relegatesTeams() {
        footballLeague.addTeam(team1);
        footballLeague.addTeam(team2);
        footballLeague.addTeam(team3);
        footballLeague.addTeam(team4);
        footballLeague.addTeam(team5);

        footballLeague.playGame(team1, team2, team1);
        footballLeague.playGame(team2, team3, team2);
        footballLeague.playGame(team1, team3, null);
        footballLeague.playGame(team4, team5, team5);
        footballLeague.playGame(team1, team5, null);
        footballLeague.playGame(team3, team4, team3);

        outContent.reset();
        footballLeague.relegateTeams(3);

        String result = "Trying to relegates last 3 teams.\n" +
                "Last 3 teams were relegated.\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Team                 | Points  | Wins    | Draws   | Losses  |\n" +
                "+----------------------|---------|---------|---------|---------+\n" +
                "| Manchester United    | 5       | 1       | 2       | 0       |\n" +
                "| Liverpool            | 4       | 1       | 1       | 0       |\n" +
                "+----------------------|---------|---------|---------|---------+\n";
        assertEquals(result, outContent.toString().replace("\r", ""));


    }


}