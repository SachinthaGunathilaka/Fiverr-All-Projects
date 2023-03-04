import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        launch("test1.txt");
        launch("test2.txt");
    }

    public static void launch(String filename){
        LinkedList linkedList = new LinkedList();
        try {
            FileInputStream fis = new FileInputStream(filename);
            Scanner scanner = new Scanner(fis);
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String [] data = line.strip().split(" ");
                int id = Integer.parseInt(data[0]);
                double mark = Double.parseDouble(data[1]);
                Node node = new Node(id, mark);
                linkedList.insert(node);
            }
            scanner.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

        linkedList.display();
        Node median_node = linkedList.getMedian(linkedList.head, linkedList.tail);
        System.out.printf("\nThe median mark is %.2f, by student number %d.\n\n", median_node.getMark(), median_node.getStd_number());
    }

}
