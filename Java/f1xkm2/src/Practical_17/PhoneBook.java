package Practical_17;

import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

public class PhoneBook {
    private Map<String, Map<String, PhoneBookEntry>> namesToNumbers;
    private Map<String, PhoneBookEntry> numbersToEntries;

    public PhoneBook() {
        namesToNumbers = new HashMap<>();
        numbersToEntries = new HashMap<>();
    }

    public void insert(PhoneBookEntry entry) {
        if (!namesToNumbers.containsKey(entry.getFull_name())) {
            namesToNumbers.put(entry.getFull_name(), new HashMap<>());
        }
        Map<String, PhoneBookEntry> temp = namesToNumbers.get(entry.getFull_name());

        if (temp.containsKey(entry.getAddress())) {
            System.out.println(entry.getFull_name() + " already exists in the phone book.");
            return;
        }

        temp.put(entry.getAddress(), entry);

        namesToNumbers.put(entry.getFull_name(), temp);

        numbersToEntries.put(entry.getPhone_number(), entry);

        System.out.println(entry.getFull_name() + " added to the phone book.");


    }


    public void update(PhoneBookEntry entry) {
        System.out.println("Updating " + entry.getFull_name() + "(" + entry.getAddress() + ") entry");
        if (!namesToNumbers.containsKey(entry.getFull_name())) {
            System.out.println(entry.getFull_name() + "(" + entry.getAddress() + ") entry not found");
            return;
        }
        Map<String, PhoneBookEntry> temp = namesToNumbers.get(entry.getFull_name());
        temp.put(entry.getAddress(), entry);

        namesToNumbers.put(entry.getFull_name(), temp);
        numbersToEntries.put(entry.getPhone_number(), entry);


        System.out.println(entry.getFull_name() + "(" + entry.getAddress() + ") updated");
    }

    public void delete(PhoneBookEntry entry) {
        System.out.println("Deleting " + entry.getFull_name() + "(" + entry.getAddress() + ") entry");
        if (!namesToNumbers.containsKey(entry.getFull_name())) {
            System.out.println(entry.getFull_name() + "(" + entry.getAddress() + ") entry not found");
            return;
        }
        Map<String, PhoneBookEntry> temp = namesToNumbers.get(entry.getFull_name());

        if (!temp.containsKey(entry.getAddress())) {
            System.out.println(entry.getFull_name() + "(" + entry.getAddress() + ") entry not found");
            return;
        }
        temp.remove(entry.getAddress());

        namesToNumbers.put(entry.getFull_name(), temp);
        numbersToEntries.remove(entry.getPhone_number());


        System.out.println(entry.getFull_name() + "(" + entry.getAddress() + ") removed from the phone book");
    }

    public void displayAll() {
        System.out.println("+-------------------------------------------------------------------------------------------+");
        System.out.println("| Full Name            | Address              | Phone Number         | Email                |");
        System.out.println("+-------------------------------------------------------------------------------------------+");


        for (Map.Entry<String, Map<String, PhoneBookEntry>> section : namesToNumbers.entrySet()) {
            for (Map.Entry<String, PhoneBookEntry> entry : section.getValue().entrySet()) {
                System.out.printf("| %-20s | %-20s | %-20s | %-20s |\n", entry.getValue().getFull_name(), entry.getValue().getAddress(),
                        entry.getValue().getPhone_number(), entry.getValue().getEmail());
            }
        }
        System.out.println("+-------------------------------------------------------------------------------------------+");

    }

    void searchByFullName(String fullname) {
        System.out.println("Searching for " + fullname);


        for (Map.Entry<String, Map<String, PhoneBookEntry>> section : namesToNumbers.entrySet()) {
            for (Map.Entry<String, PhoneBookEntry> entry : section.getValue().entrySet()) {
                if (Objects.equals(entry.getValue().getFull_name(), fullname)) {
                    System.out.println("+-------------------------------------------------------------------------------------------+");
                    System.out.println("| Full Name            | Address              | Phone Number         | Email                |");
                    System.out.println("+-------------------------------------------------------------------------------------------+");
                    System.out.printf("| %-20s | %-20s | %-20s | %-20s |\n", entry.getValue().getFull_name(), entry.getValue().getAddress(),
                            entry.getValue().getPhone_number(), entry.getValue().getEmail());
                    System.out.println("+-------------------------------------------------------------------------------------------+");
                    return;
                }

            }
        }

        System.out.println(fullname + " not found in the phonebook");
    }

    void searchByPhoneNumber(String phoneNumber) {
        System.out.println("Searching for " + phoneNumber);


        for (Map.Entry<String, PhoneBookEntry> entry : numbersToEntries.entrySet()) {
            if (Objects.equals(entry.getValue().getPhone_number(), phoneNumber)) {
                System.out.println("+-------------------------------------------------------------------------------------------+");
                System.out.println("| Full Name            | Address              | Phone Number         | Email                |");
                System.out.println("+-------------------------------------------------------------------------------------------+");
                System.out.printf("| %-20s | %-20s | %-20s | %-20s |\n", entry.getValue().getFull_name(), entry.getValue().getAddress(),
                        entry.getValue().getPhone_number(), entry.getValue().getEmail());
                System.out.println("+-------------------------------------------------------------------------------------------+");
                return;
            }


        }

        System.out.println(phoneNumber + " not found in the phonebook");
    }


}
