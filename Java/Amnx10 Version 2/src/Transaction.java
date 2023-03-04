public class Transaction {
    private String transaction_id;
    private int item_id;
    private int member_id;
    private String date;

    public Transaction(String transaction_id, int item_id, int member_id, String date) {
        this.transaction_id = transaction_id;
        this.item_id = item_id;
        this.member_id = member_id;
        this.date = date;
    }

    public String getTransaction_id() {
        return transaction_id;
    }

    public int getItem_id() {
        return item_id;
    }

    public int getMember_id() {
        return member_id;
    }

    public String getDate() {
        return date;
    }

    public void display() {
        System.out.println(transaction_id + "\t\t" + item_id + "\t\t" + member_id + "\t\t" + date);
    }
}
