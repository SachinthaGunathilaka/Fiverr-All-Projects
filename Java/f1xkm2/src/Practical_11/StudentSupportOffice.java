package Practical_11;

public class StudentSupportOffice {
    public static void main(String[] args) {
        Module module2206 = new Module("CIS2206");
        Module module2360 = new Module("CIS2360");
        Module module2205 = new Module("CIS2205");

        Student student1 = new Student("U0000001", "John", "Charles", 20);
        Student student2 = new Student("U0000002", "Kane", "William", 25);
        Student student3 = new Student("U0000003", "Kevin", "Williamson", 21);
        Student student4 = new Student("U0000004", "Ahmed", "Shezard", 20);
        Student student5 = new Student("U0000005", "Mary", "Thomas", 23);

        System.out.println();
        module2206.enroll(student1);
        module2206.enroll(student5);

        module2360.enroll(student1);
        module2360.enroll(student3);
        module2360.enroll(student4);

        module2205.enroll(student2);
        module2205.enroll(student4);
        module2205.enroll(student5);

        System.out.println("\n---------------------------------------------------------------");
        System.out.println("                         INITIALLY");
        System.out.println("---------------------------------------------------------------");
        module2206.display();
        module2360.display();
        module2205.display();

        System.out.println();
        module2206.enroll(student3);
        module2206.enroll(student4);
        module2206.unenroll(student5);

        module2360.enroll(student2);
        module2360.enroll(student5);

        module2205.enroll(student1);
        module2205.enroll(student3);
        module2205.unenroll(student2);
        module2205.unenroll(student5);

        System.out.println("\n---------------------------------------------------------------");
        System.out.println("                          FINALLY");
        System.out.println("---------------------------------------------------------------");
        module2206.display();
        module2360.display();
        module2205.display();
    }
}
