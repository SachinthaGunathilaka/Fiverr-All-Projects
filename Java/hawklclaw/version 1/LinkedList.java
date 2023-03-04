public class LinkedList {
    Node head;
    Node tail;

    public LinkedList() {
        head = null;
        tail = null;
    }

    public void insert(Node node) {
        if (head == null) {
            head = node;
            tail = node;
            return;
        }

        Node temp = head;
        while (temp != null) {
            if (temp.getMark() < node.getMark()) {
                if (temp.previous == null) {
                    head.previous = node;
                    node.next = head;
                    head = node;
                    return;
                }

                node.next = temp;
                node.previous = temp.previous;
                temp.previous.next = node;
                temp.previous = node;
                return;
            }
            temp = temp.next;
        }

        tail.next = node;
        node.previous = tail;
        tail = node;


    }

    public void display() {
        System.out.println("\nStudent Number: Mark:\n" +
                "=============== =====");
        Node temp = head;
        while (temp != null) {
            System.out.println(temp);
            temp = temp.next;
        }
    }

    public Node getMedian(Node top, Node bottom) {
        if (top.getMark() <= bottom.getMark() ) {
            return top;
        }

        return getMedian(top.next, bottom.previous);
    }


}
