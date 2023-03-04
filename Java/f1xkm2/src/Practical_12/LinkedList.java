package Practical_12;

import java.util.Objects;

public class LinkedList {

    Node head;
    int size;

    static class Node {

        Team team;
        Node next;

        Node(Team d) {
            team = d;
            next = null;
        }
    }

    public LinkedList() {
        head = null;
        size = 0;
    }

    public void insert(Team team) {
        Node currNode = this.head;

        while (currNode != null) {
            if (Objects.equals(currNode.team.getName(), team.getName())) {
                System.out.println("Team " + team.getName() + " already exists in the league.");
                return;
            }

            currNode = currNode.next;
        }

        Node new_node = new Node(team);
        new_node.next = head;
        head = new_node;
        System.out.println("Team " + team.getName() + " added to the league.");
        size++;


    }

    public void displayTable() {
        Node currNode = this.head;

        System.out.println("+----------------------|---------|---------|---------|---------+");
        System.out.printf("| %-20s | %-7s | %-7s | %-7s | %-7s |\n", "Team", "Points", "Wins", "Draws", "Losses");
        System.out.println("+----------------------|---------|---------|---------|---------+");

        while (currNode != null) {
            System.out.printf("| %-20s | %-7d | %-7d | %-7d | %-7d |\n", currNode.team.getName(), currNode.team.getPoints(),
                    currNode.team.getWins(), currNode.team.getDraws(), currNode.team.getLosses());

            currNode = currNode.next;
        }
        System.out.println("+----------------------|---------|---------|---------|---------+");

    }

    public void remove(Team team) {
        Node temp = head;
        Node prev = null;

        if (temp != null && Objects.equals(temp.team.getName(), team.getName())) {
            head = temp.next;
            System.out.println("Team " + team.getName() + " removed from the league.");
            size--;
            return;
        } else {
            while (temp != null && temp.team != team) {
                prev = temp;
                temp = temp.next;
            }

            if (temp == null) {
                System.out.println("Team " + team.getName() + " trying to remove from the league. It does not exists.");
                return;

            }

            System.out.println("Team " + team.getName() + " removed from the league.");
            size--;
            prev.next = temp.next;

        }
    }

    public void sortList() {
        Node current = head, nextNode = null;

        Team temp;

        if (head == null) {
            return;
        } else {
            while (current != null) {
                nextNode = current.next;

                while (nextNode != null) {
                    if (current.team.compareTo(nextNode.team) < 0) {
                        temp = current.team;
                        current.team = nextNode.team;
                        nextNode.team = temp;
                    }

                    nextNode = nextNode.next;
                }
                current = current.next;
            }
        }
    }

    public void updateDetails(Team team, int result) {
        Node currNode = this.head;

        while (currNode != null) {

            if (Objects.equals(currNode.team.getName(), team.getName())) {
                if (result == 1) {
                    currNode.team.setWins(currNode.team.getWins() + 1);
                    currNode.team.setPoints(currNode.team.getPoints() + 3);

                } else if (result == -1) {
                    currNode.team.setLosses(currNode.team.getLosses() + 1);
                } else {
                    currNode.team.setDraws(currNode.team.getDraws() + 1);
                    currNode.team.setPoints(currNode.team.getPoints() + 1);
                }
                return;
            }


            currNode = currNode.next;
        }
    }

    public void relegateTeams(int n) {
        System.out.println("Trying to relegates last " + n + " teams.");

        Node currNode = this.head;

        int index = 0;
        while (currNode != null) {
            if (index == size - n - 1) {
                currNode.next = null;
                System.out.println("Last " + n + " teams were relegated.");
                return;
            }
            currNode = currNode.next;
            index++;
        }

        System.out.println("Last " + size + " teams were relegated.");

    }
}
