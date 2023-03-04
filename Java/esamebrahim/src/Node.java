// Node class
public class Node {

    public Patient data;
    public Node next;
    public Node prev;

    public Node(Patient data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}
