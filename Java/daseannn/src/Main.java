import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        MinHeap minHeap = null;
        Random random = new Random();

        while (true) {
            System.out.println("\n1) Create empty heap\n" +
                    "2) Create min heap using given integers\n" +
                    "3) Insert element\n" +
                    "4) Remove element\n" +
                    "5) Sort heap\n" +
                    "6) Calculate elapsed time for sorting operation\n" +
                    "7) Quit");
            System.out.print("\nEnter your option : ");
            int option = Integer.parseInt(scanner.nextLine());


            if (option == 1) {
                minHeap = createEmptyHeap();
                System.out.println("Empty heap is created");
            } else if (option == 2) {
                System.out.print("Enter integers as comma separated values : ");
                String[] str_values = scanner.nextLine().split(",");
                int[] int_values = new int[str_values.length];
                for (int i = 0; i < str_values.length; i++) {
                    int_values[i] = Integer.parseInt(str_values[i]);
                }

                minHeap = buildHeap(int_values);
                minHeap.print();

            } else if (option == 3) {
                if (minHeap == null) {
                    System.out.println("Minheap is not created yet.");
                    continue;
                }
                System.out.print("Enter the element : ");
                int element = Integer.parseInt(scanner.nextLine());
                insert(minHeap, element);
                minHeap.print();


            } else if (option == 4) {
                if (minHeap == null) {
                    System.out.println("Minheap is not created yet.");
                    continue;
                }
                System.out.print("Enter the element : ");
                int element = Integer.parseInt(scanner.nextLine());
                removeElement(minHeap, element);
                minHeap.print();
            } else if (option == 5) {
                if (minHeap == null) {
                    System.out.println("Minheap is not created yet.");
                    continue;
                }

                minHeap.sort();
                minHeap.print();
            } else if (option == 6) {
                System.out.print("Enter the length : ");
                long len = Integer.parseInt(scanner.nextLine());

                minHeap = createEmptyHeap();
                for (int i = 0; i < len; i++) {
                    int rnum = random.nextInt(2000) - 1000;
                    minHeap.insert(rnum);
                }

                long start = System.currentTimeMillis();
                minHeap.sort();
                minHeap.sortByStd();
                long end = System.currentTimeMillis();
                long elapsedTime = end - start;

                if (elapsedTime > 1000) {
                    System.out.println("Elapsed Time : " + elapsedTime / 1000 + " seconds");
                } else {
                    System.out.println("Elapsed Time : " + elapsedTime + " milliseconds");
                }

            } else if (option == 7) {
                break;
            } else {
                System.out.println("Invalid input");
            }

        }
    }

    public static MinHeap createEmptyHeap() {
        return new MinHeap(1000);
    }

    public static MinHeap buildHeap(int[] values) {
        MinHeap minHeap = new MinHeap(1000);

        for (int val : values) {
            minHeap.insert(val);
        }

        return minHeap;
    }

    public static void insert(MinHeap minHeap, int element) {
        minHeap.insert(element);
    }

    public static void removeElement(MinHeap minHeap, int element) {
        minHeap.removeElement(element);
    }


}
