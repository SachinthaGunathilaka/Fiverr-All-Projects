package Practical_17;

public class PhoneBookEntry {
    private String full_name;
    private String phone_number;
    private String email;
    private String address;

    public PhoneBookEntry(String full_name, String phone_number, String email, String address) {
        this.full_name = full_name;
        this.phone_number = phone_number;
        this.email = email;
        this.address = address;
    }

    @Override
    public String toString() {
        return "Full Name: " + full_name +
                ", Phone Number: " + phone_number +
                ", Email: " + email +
                ", Address: " + address;
    }

    public String getFull_name() {
        return full_name;
    }

    public String getPhone_number() {
        return phone_number;
    }

    public String getEmail() {
        return email;
    }

    public String getAddress() {
        return address;
    }

    public void setFull_name(String full_name) {
        this.full_name = full_name;
    }

    public void setPhone_number(String phone_number) {
        this.phone_number = phone_number;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void setAddress(String address) {
        this.address = address;
    }
}
