public class Item {

    private int item_number;
    private String title;
    private int available;

    public Item(int item_number, String title) {
        this.item_number = item_number;
        this.title = title;
        this.available = 10;
    }

    public Item(int item_number, String title, int available) {
        this.item_number = item_number;
        this.title = title;
        this.available = available;
    }


    public int getItem_number() {
        return item_number;
    }

    public String getTitle() {
        return title;
    }

    public int getAvailable() {
        return available;
    }

    public int  borrowItem() {
        if (available == 0){
            System.out.println("Item with item number : " + item_number + " and title : " + title + " is out of stock!");
            return 0;
        }
        System.out.println("Item with item number : " + item_number + " and title : " + title + " is borrowed!");
        available--;
        return 1;
    }

    public void display() {
        System.out.println("Item number =" + item_number + ", Title=" + title + ", Available=" + available);
    }

    public void returnItem(){
        available++;
    }
}
