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
            if (temp.mark < node.mark) {
                if (temp.prev == null) {
                    head.prev = node;
                    node.next = head;
                    head = node;
                    return;
                }

                node.next = temp;
                node.prev = temp.prev;
                temp.prev.next = node;
                temp.prev = node;
                return;
            }
            temp = temp.next;
        }

        tail.next = node;
        node.prev = tail;
        tail = node;


    }

    public void display() {
        System.out.println("\nStudent Number  Mark");
        Node temp = head;
        while (temp != null) {
            System.out.println(temp);
            temp = temp.next;
        }
    }

    public Node getMedian(Node top, Node bottom) {
        if (top.mark <= bottom.mark ) {
            return top;
        }

        return getMedian(top.next, bottom.prev);
    }


}
