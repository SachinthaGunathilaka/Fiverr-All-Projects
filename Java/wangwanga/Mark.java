public class Mark {
    private String std_id;
    private double mark;

    public Mark(String std_id, double mark) {
        this.std_id = std_id;
        this.mark = mark;
    }

    public String getStd_id() {
        return std_id;
    }

    public double getMark() {
        return mark;
    }

    public void setStd_id(String std_id) {
        this.std_id = std_id;
    }

    public void setMark(double mark) {
        this.mark = mark;
    }

    public void displayMark(){
        System.out.print(mark);
    }


}
