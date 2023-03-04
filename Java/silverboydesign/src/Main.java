import java.util.Random;

public class Main {
    public static void findMax(int [] data){
        long begin, end, time;
        begin = System.nanoTime();

        int max_val = data[0];

        for (int val:data) {
            if(val > max_val)
                max_val = val;
        }

        end = System.nanoTime();
        time = end - begin;
        System.out.println("\nMaximum value of " + data.length + " integers : " + max_val);
        System.out.println("Execution time : " + time);

    }

    public static void displayExecutionTime(int size){
        Random r = new Random();

        int[] data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = r.nextInt(2 * size) - size;
        }

        findMax(data);
    }
    public static void main(String[] args) {

        displayExecutionTime(10);
        displayExecutionTime(100);
        displayExecutionTime(10000);
        displayExecutionTime(10000000);


    }
}
