
// PatientsList class (Doubly Linked list)
public class PatientsList {
    private Node head;
    private Node tail;
    public static int next_id = 0;
    public int size;

    // Constructor
    public PatientsList() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    // Method to add a patient
    public void addPatient(Patient data) {
        Node newNode = new Node(data);

        // If the list is empty
        if (head == null) {
            head = newNode;
            tail = newNode;
            head.prev = null;
            tail.next = null;
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
            tail.next = null;
        }

        this.size++;
        System.out.println("Patient added successfully.");

    }

    // Method to edit a patient
    public void editPatient(Patient patient) {
        Node current = head;
        // If the list is empty
        if (head == null) {
            System.out.println("Patient List is empty.");
            return;
        }

        while (current != null) {
            if (current.data.getId() == patient.getId()) {
                current.data = patient;
                System.out.println("Patient details updated successfully.");
                return;
            }
            current = current.next;
        }

        System.out.println("Patient does not found.");
    }

    // Method to delete a patient
    public void deletePatient(int id) {

        // If the list is empty
        if (head == null) {
            System.out.println("Patient List is empty.");
            return;
        }


        // If the searching patients is the first patient in the list
        if (head.data.getId() == id) {

            head = head.next;
            this.size--;
            System.out.println("Patient removed successfully.");
            return;

        }

        Node current = head;

        while (current != null) {
            if (current.data.getId() == id) {

                if (current.next != null) {
                    current.next.prev = current.prev;
                }

                if (current.prev != null) {
                    current.prev.next = current.next;
                }
                this.size--;
                System.out.println("Patient removed successfully.");
                return;
            }
            current = current.next;
        }

        System.out.println("Patient does not found.");


    }

    // Method to search for a patient
    public Patient searchPatient(int id) {
        Node current = head;

        // If the list is empty
        while (current != null) {
            if (current.data.getId() == id) {
                return current.data;
            }
            current = current.next;
        }

        return null;
    }

    // Method to display all the patients
    public void displayPatients() {

        System.out.println();
        System.out.printf("%-3s | %-20s | %-5s | %-10s | %-30s\n", "ID", "Name", "Age", "Gender", "Address");
        System.out.printf("-------------------------------------------------------------------------------------------------\n");

        Node current = head;
        while (current != null) {
            current.data.display();
            current = current.next;
        }
    }

    // Method to sort the patients by name, age or address
    public void sortList(int sort_option) {
        int swapped, i;
        Node current;
        Node prev = null;
        boolean need_swap = false;

        // If the list is empty
        if (head == null)
            return;

        do {
            swapped = 0;
            current = head;

            while (current.next != prev) {
                need_swap = false;

                // Sort by name
                if (sort_option == 1)
                    need_swap = current.data.getName().compareToIgnoreCase(current.next.data.getName()) > 0;

                // Sort by age
                else if (sort_option == 2)
                    need_swap = current.data.getAge() > current.next.data.getAge();

                // Sort by address
                else
                    need_swap = current.data.getAddress().compareToIgnoreCase(current.next.data.getAddress()) > 0;


                if (need_swap) {
                    Patient temp = current.data;
                    current.data = current.next.data;
                    current.next.data = temp;
                    swapped = 1;
                }
                current = current.next;
            }
            prev = current;
        }

        // If there is no swapped the list has already sorted.
        while (swapped != 0);

        System.out.println("Patient list is sorted successfully.");
    }

    // Method to clear the list
    public void clearList(){
        Node temp;
        while(this.head != null) {
            temp = this.head;
            this.head = this.head.next;
            temp = null;
        }

        this.size = 0;
        System.out.println("Patient list clear successfully.");
    }

}
