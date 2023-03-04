import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        LinkedList linkedList1 = new LinkedList();
        LoadFromFile(linkedList1, "test1.txt");
        linkedList1.display();
        Node median_node = linkedList1.getMedian(linkedList1.head, linkedList1.tail);
        System.out.printf("\nThe median mark is %.2f, by student number %d.\n\n", median_node.mark, median_node.std_number);

        LinkedList linkedList2 = new LinkedList();
        LoadFromFile(linkedList2, "test2.txt");
        linkedList2.display();
        median_node = linkedList2.getMedian(linkedList2.head, linkedList2.tail);
        System.out.printf("\nThe median mark is %.2f, by student number %d.\n\n", median_node.mark, median_node.std_number);
    }

    public static void LoadFromFile(LinkedList linkedList, String filename) {
        try {
            FileInputStream fis = new FileInputStream(filename);
            Scanner scanner = new Scanner(fis);
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] data = line.strip().split(" ");
                int id = Integer.parseInt(data[0]);
                double mark = Double.parseDouble(data[1]);
                Node node = new Node(id, mark);
                linkedList.insert(node);
            }
            scanner.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

}
