import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Random;

public class User {

    private int member_id;
    private String name;
    private ArrayList<Integer> borrowed_items;
    private ArrayList<Integer> requested_items;
    private static int MAX_ITEMS = 5;


    public User(int member_id, String name) {
        this.member_id = member_id;
        this.name = name;
        this.borrowed_items = new ArrayList<>();
        this.requested_items = new ArrayList<>();
    }

    public void readFromFile(int item_number) {
        borrowed_items.add(item_number);
    }

    public void requestItem(int item_number) {

        if (borrowed_items.size() + requested_items.size() == MAX_ITEMS) {
            System.out.println("Your limit has been exceeded!");
            return;
        }

        for (int cur_item_number : borrowed_items) {
            if (cur_item_number == item_number) {
                System.out.println("The item has been already borrowed!");
                return;
            }
        }

        for (int cur_item_number : requested_items) {
            if (cur_item_number == item_number) {
                System.out.println("The item has been already requested!");
                return;
            }
        }
        int status = AllItems.requestItem(item_number);
        if (status == 0) {
            requested_items.add(item_number);
        } else if (status == 1) {
            borrowed_items.add(item_number);
            String transaction_id = "";
            Random random = new Random();

            char base = 'A';
            for (int i = 0; i < 2; i++) {
                int rnd = (int) (Math.random() * 26);
                transaction_id += Character.toString((char) (base + rnd % 26));
            }
            String dateNow = new SimpleDateFormat("dd/MM/yyyy").format(Calendar.getInstance().getTime());


            transaction_id += random.nextInt(10000 - 1000) + 1000;
            AllTransactions.addTransaction(transaction_id, item_number, member_id, dateNow);
        }
    }

    public int getMember_id() {
        return member_id;
    }

    public String getName() {
        return name;
    }

    public void display() {
        System.out.println("\n" + name + " (ID " + member_id + ")");
        System.out.print("\tBorrowed Items : ");
        for (int item_number : borrowed_items) {
            System.out.print(item_number + "\t");
        }
        System.out.println();

        System.out.print("\tRequested Items : ");
        for (int item_number : requested_items) {
            System.out.print(item_number + "\t");
        }
        System.out.println();
    }

    public void returnItem(int item_number) {
        for (Integer item : borrowed_items) {
            if (item == item_number) {
                borrowed_items.remove(item);
                break;
            }
        }
    }


}
