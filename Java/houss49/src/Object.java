public class Object {
    private String code;
    private double price;
    private double VAT;
    private int total_quantity;
    private String category;
    private String description;

    public Object(){

    }

    public Object(String code, double price, double VAT, int total_quantity, String category, String description) {
        this.code = code;
        this.price = price;
        this.VAT = VAT;
        this.total_quantity = total_quantity;
        this.category = category;
        this.description = description;
    }

    public double calculateVATPrice(){
        return price + VAT;
    }

    public double calculateQuantityPrice(int quantity){
        return calculateVATPrice() * quantity;
    }

    public boolean checkAvailability(){
        return total_quantity != 0;
    }

    public String getCode() {
        return code;
    }

    public double getPrice() {
        return price;
    }

    public double getVAT() {
        return VAT;
    }

    public int getTotal_quantity() {
        return total_quantity;
    }

    public String getCategory() {
        return category;
    }

    public String getDescription() {
        return description;
    }
}
