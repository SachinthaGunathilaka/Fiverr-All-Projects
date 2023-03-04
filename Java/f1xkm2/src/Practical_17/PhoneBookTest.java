package Practical_17;

import Practical_11.Module;
import Practical_11.Student;
import org.junit.jupiter.api.Test;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

import static org.junit.jupiter.api.Assertions.*;

class PhoneBookTest {

    private PhoneBook phoneBook;
    private PhoneBookEntry entry1;
    private PhoneBookEntry entry2;
    private PhoneBookEntry entry3;
    private PhoneBookEntry entry4;
    private PhoneBookEntry entry5;

    private final ByteArrayOutputStream outContent = new ByteArrayOutputStream();
    private final PrintStream originalOut = System.out;


    @org.junit.jupiter.api.BeforeEach
    public void init() {
        System.setOut(new PrintStream(outContent));
        phoneBook = new PhoneBook();
        entry1 = new PhoneBookEntry("John Watson", "+1 234 7854", "john@gmail.com", "address john");
        entry2 = new PhoneBookEntry("Carl Mayers", "+1 653 1980", "carlmayers@gmail.com", "address carl");
        entry3 = new PhoneBookEntry("John Watson", "+23 456 0562", "john20@gmail.com", "address john2");
        entry4 = new PhoneBookEntry("Chris Mary", "+43 872 1098", "chris@gmail.com", "address chris");
        entry5 = new PhoneBookEntry("David Malan", "+32 021 5921", "david@gmail.com", "address david");
    }

    @org.junit.jupiter.api.AfterEach
    public void restoreStreams() {
        System.setOut(originalOut);
    }

    @Test
    void insert() {
        phoneBook.insert(entry1);
        phoneBook.insert(entry2);
        phoneBook.insert(entry1);

        String output = "John Watson added to the phone book.\n" +
                "Carl Mayers added to the phone book.\n" +
                "John Watson already exists in the phone book.\n";

        assertEquals(output, outContent.toString().replace("\r", ""));
    }

    @Test
    void update() {
        phoneBook.insert(entry1);
        phoneBook.insert(entry2);
        phoneBook.insert(entry3);

        entry1.setEmail("johnnew@gmail.com");
        entry1.setPhone_number("+1 234 7854");
        phoneBook.update(entry1);
        phoneBook.update(entry5);

        String output = "John Watson added to the phone book.\n" +
                "Carl Mayers added to the phone book.\n" +
                "John Watson added to the phone book.\n" +
                "Updating John Watson(address john) entry\n" +
                "John Watson(address john) updated\n" +
                "Updating David Malan(address david) entry\n" +
                "David Malan(address david) entry not found\n";

        assertEquals(output, outContent.toString().replace("\r", ""));
    }

    @Test
    void delete() {
        phoneBook.insert(entry1);
        phoneBook.insert(entry2);
        phoneBook.insert(entry3);

        phoneBook.delete(entry1);
        phoneBook.delete(entry3);
        phoneBook.delete(entry5);

        String output = "John Watson added to the phone book.\n" +
                "Carl Mayers added to the phone book.\n" +
                "John Watson added to the phone book.\n" +
                "Deleting John Watson(address john) entry\n" +
                "John Watson(address john) removed from the phone book\n" +
                "Deleting John Watson(address john2) entry\n" +
                "John Watson(address john2) removed from the phone book\n" +
                "Deleting David Malan(address david) entry\n" +
                "David Malan(address david) entry not found\n";

        assertEquals(output, outContent.toString().replace("\r", ""));

        outContent.reset();
        phoneBook.displayAll();
        output = "+-------------------------------------------------------------------------------------------+\n" +
                "| Full Name            | Address              | Phone Number         | Email                |\n" +
                "+-------------------------------------------------------------------------------------------+\n" +
                "| Carl Mayers          | address carl         | +1 653 1980          | carlmayers@gmail.com |\n" +
                "+-------------------------------------------------------------------------------------------+\n";

        assertEquals(output, outContent.toString().replace("\r", ""));

    }

    @Test
    void displayAll() {
        phoneBook.insert(entry1);
        phoneBook.insert(entry2);
        phoneBook.insert(entry3);
        phoneBook.insert(entry4);
        phoneBook.insert(entry5);

        outContent.reset();
        phoneBook.displayAll();

        String output = "+-------------------------------------------------------------------------------------------+\n" +
                "| Full Name            | Address              | Phone Number         | Email                |\n" +
                "+-------------------------------------------------------------------------------------------+\n" +
                "| John Watson          | address john         | +1 234 7854          | john@gmail.com       |\n" +
                "| John Watson          | address john2        | +23 456 0562         | john20@gmail.com     |\n" +
                "| David Malan          | address david        | +32 021 5921         | david@gmail.com      |\n" +
                "| Carl Mayers          | address carl         | +1 653 1980          | carlmayers@gmail.com |\n" +
                "| Chris Mary           | address chris        | +43 872 1098         | chris@gmail.com      |\n" +
                "+-------------------------------------------------------------------------------------------+\n";

        assertEquals(output, outContent.toString().replace("\r", ""));

    }

    @Test
    void searchByFullName() {
        phoneBook.insert(entry1);
        phoneBook.insert(entry2);
        phoneBook.insert(entry3);


        outContent.reset();
        phoneBook.searchByFullName("John Watson");
        phoneBook.searchByFullName("Chris Mary");

        String output = "Searching for John Watson\n" +
                "+-------------------------------------------------------------------------------------------+\n" +
                "| Full Name            | Address              | Phone Number         | Email                |\n" +
                "+-------------------------------------------------------------------------------------------+\n" +
                "| John Watson          | address john         | +1 234 7854          | john@gmail.com       |\n" +
                "+-------------------------------------------------------------------------------------------+\n" +
                "Searching for Chris Mary\n" +
                "Chris Mary not found in the phonebook\n";

        assertEquals(output, outContent.toString().replace("\r", ""));

        phoneBook.delete(entry1);
        outContent.reset();
        phoneBook.searchByFullName("John Watson  ");

        output = "Searching for John Watson  \n" +
                "John Watson   not found in the phonebook\n";
        assertEquals(output, outContent.toString().replace("\r", ""));
    }

    @Test
    void searchByFPhoneNumber() {
        phoneBook.insert(entry1);
        phoneBook.insert(entry2);
        phoneBook.insert(entry3);


        outContent.reset();
        phoneBook.searchByPhoneNumber("+1 234 7854");
        phoneBook.searchByPhoneNumber("+43 872 1098");

        String output = "Searching for +1 234 7854\n" +
                "+-------------------------------------------------------------------------------------------+\n" +
                "| Full Name            | Address              | Phone Number         | Email                |\n" +
                "+-------------------------------------------------------------------------------------------+\n" +
                "| John Watson          | address john         | +1 234 7854          | john@gmail.com       |\n" +
                "+-------------------------------------------------------------------------------------------+\n" +
                "Searching for +43 872 1098\n" +
                "+43 872 1098 not found in the phonebook\n";

        assertEquals(output, outContent.toString().replace("\r", ""));

        phoneBook.delete(entry1);
        outContent.reset();
        phoneBook.searchByPhoneNumber("+1 234 7854 ");

        output = "Searching for +1 234 7854 \n" +
                "+1 234 7854  not found in the phonebook\n";
        assertEquals(output, outContent.toString().replace("\r", ""));
    }
}