
public class Patient {

    private int id;
    private String name;
    private int age;
    private String sex;
    private String address;

    public Patient(String name, int age, String sex, String address) {
        this.id = PatientsList.next_id++;
        this.name = name;
        this.address = address;
        this.age = age;
        this.sex = sex;
    }

    public void display() {
        System.out.printf("%-3d | %-20s | %-5d | %-10s | %-30s\n", id, name, age, sex, address);
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public String getSex() {
        return sex;
    }

    public String getAddress() {
        return address;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public void setAddress(String address) {
        this.address = address;
    }

}