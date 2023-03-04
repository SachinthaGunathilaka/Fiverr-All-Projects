import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;

public class AllTransactions {
    private static final ArrayList<Transaction> transactions = new ArrayList<>();

    public static void readFromFile(String transaction_id, int item_id, int member_id, String date) {
        Transaction transaction = new Transaction(transaction_id, item_id, member_id, date);

        AllUsers.readFromFile(member_id, item_id);

        transactions.add(transaction);
    }

    public static void addTransaction(String transaction_id, int item_id, int member_id, String date) {
        Transaction transaction = new Transaction(transaction_id, item_id, member_id, date);

        transactions.add(transaction);
    }


    public static void displayTransactions() {
        System.out.println();
        for (Transaction transaction : transactions) {
            transaction.display();
        }
    }

    public static void checkForExpiredItems() throws ParseException {
        ArrayList<Transaction> expired = new ArrayList<>();
        for (Transaction transaction : transactions) {
            SimpleDateFormat formatter1 = new SimpleDateFormat("dd/MM/yyyy");
            Date date = formatter1.parse(transaction.getDate());
            Date today = new Date();

            Calendar c1 = Calendar.getInstance();
            c1.setTime(date);
            c1.add(Calendar.DATE, 7);

            Calendar c2 = Calendar.getInstance();
            c2.setTime(today);


            if (c2.after(c1)) {
                expired.add(transaction);
            }

        }

        for (Transaction transaction:expired) {
            AllItems.returnItem(transaction.getItem_id());
            AllUsers.returnItem(transaction.getMember_id(), transaction.getItem_id());
            transactions.remove(transaction);
        }
    }


}
