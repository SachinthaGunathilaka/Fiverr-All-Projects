package Practical_17;

public class User {
    public static void main(String[] args) {
        PhoneBook phoneBook = new PhoneBook();
        PhoneBookEntry entry1 = new PhoneBookEntry("John Watson", "+1 234 7854", "john@gmail.com", "address john");
        PhoneBookEntry entry2 = new PhoneBookEntry("Carl Mayers", "+1 653 1980", "carlmayers@gmail.com", "address carl");
        PhoneBookEntry entry3 = new PhoneBookEntry("John Watson", "+23 456 0562", "john20@gmail.com", "address john2");
        PhoneBookEntry entry4 = new PhoneBookEntry("Chris Mary", "+43 872 1098", "chris@gmail.com", "address chris");
        PhoneBookEntry entry5 = new PhoneBookEntry("David Malan", "+32 021 5921", "david@gmail.com", "address david");

        phoneBook.insert(entry1);
        phoneBook.insert(entry2);
        phoneBook.insert(entry3);
        phoneBook.insert(entry4);
        phoneBook.insert(entry5);
        phoneBook.displayAll();

        entry1.setEmail("johnnew@gmail.com");
        entry1.setPhone_number("+1 234 7854");
        phoneBook.update(entry1);
        phoneBook.displayAll();

        phoneBook.delete(entry4);
        phoneBook.delete(entry4);
        phoneBook.displayAll();

        phoneBook.searchByFullName("David Malan");
        phoneBook.searchByFullName("Chris Mary");

        phoneBook.searchByPhoneNumber("+1 234 7854");
        phoneBook.searchByPhoneNumber("+43 872 1098");


    }




}
