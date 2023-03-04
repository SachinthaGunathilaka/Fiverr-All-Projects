import java.io.FileInputStream;
import java.util.Scanner;

public class Marks {
    Node head, tail;

    public Marks() {
        head = tail = null;
    }

    public void insertNode(Node node) {
        if (head == null) {
            head = tail = node;
            return;
        }

        Node temp = head;
        while (temp != null) {
            if (temp.mark < node.mark) {
                if (temp.prev != null) {

                    node.next = temp;
                    node.prev = temp.prev;
                    temp.prev.next = node;
                    temp.prev = node;

                }
                else{
                    head.prev = node;
                    node.next = head;
                    head = node;
                }
                return;
            }
            temp = temp.next;
        }

        tail.next = node;
        node.prev = tail;
        tail = node;
    }

    public void displayMarks() {
        System.out.println("Student Number  Mark\n");
        Node temp = head;
        while (temp != null) {
            System.out.println(temp);
            temp = temp.next;
        }
    }

    public Node findMedian(Node top, Node bottom) {
        if (top.mark <= bottom.mark) {
            return top;
        }

        return findMedian(top.next, bottom.prev);
    }

    public static void main(String[] args) {
        String[] file_names = {"test1.txt", "test2.txt"};

        for (String filename : file_names) {
            Marks marks = new Marks();

            try {
                FileInputStream fis = new FileInputStream(filename);
                Scanner scanner = new Scanner(fis);
                while (scanner.hasNextLine()) {
                    String line = scanner.nextLine();
                    String[] data = line.strip().split(" ");
                    int id = Integer.parseInt(data[0]);
                    double mark = Double.parseDouble(data[1]);
                    Node node = new Node(id, mark);
                    marks.insertNode(node);
                }
                scanner.close();
            } catch (Exception e) {
                e.printStackTrace();
            }

            marks.displayMarks();
            Node median_node = marks.findMedian(marks.head, marks.tail);
            System.out.printf("\nThe median mark is %.2f, by student number %d.\n", median_node.mark, median_node.std_number);
        }
    }


}
