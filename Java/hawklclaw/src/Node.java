public class Node {
    int std_number;
    double mark;
    Node next, prev;

    public Node(int id, double mark_) {
        std_number = id;
        mark = mark_;
        next = this.prev = null;
    }

    public String toString() {
        return "\t" + std_number + "\t\t" + mark;
    }
}
