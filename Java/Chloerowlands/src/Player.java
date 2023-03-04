public class Player {
    private String name;
    private int position;
    private int mode;

    public Player(String name) {
        this.name = name;
        this.position = 0;
    }

    public String getName() {
        return name;
    }

    public int getPosition() {
        return position;
    }

    public int getMode() {
        return mode;
    }

    public void setMode(int mode) {
        this.mode = mode;
    }

    public void display() {
        System.out.println(name + " is on square " + (position + 1) + ".");
    }

    public void setPosition(int position, int width) {

        this.position = Math.min(position, width * width - 1);
    }


}
