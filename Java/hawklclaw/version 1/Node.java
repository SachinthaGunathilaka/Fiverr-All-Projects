public class Node {
    private int std_number;
    private double mark;
    Node next;
    Node previous;

    public Node(int std_number, double mark) {
        this.std_number = std_number;
        this.mark = mark;
        this.next = null;
        this.previous = null;
    }

    public int getStd_number() {
        return std_number;
    }

    public double getMark() {
        return mark;
    }

    public String toString() {
        return String.format("     %s      %s", std_number, mark);
    }
}
