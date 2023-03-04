package Practical_11;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Test;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

import static org.junit.jupiter.api.Assertions.*;

class ModuleTest {

    private Module module1;
    private Module module2;

    private Student student1;
    private Student student2;
    private Student student3;
    private final ByteArrayOutputStream outContent = new ByteArrayOutputStream();
    private final PrintStream originalOut = System.out;


    @org.junit.jupiter.api.BeforeEach
    public void init() {
        System.setOut(new PrintStream(outContent));
        module1 = new Module("CIS2206");
        module2 = new Module("CIS2360");
        student1 = new Student("U0000001", "John", "Charles", 20);
        student2 = new Student("U0000002", "Kane", "William", 25);
        student3 = new Student("U0000003", "Kevin", "Williamson", 21);
    }

    @org.junit.jupiter.api.AfterEach
    public void restoreStreams() {
        System.setOut(originalOut);
    }


    @Test
    void enroll() {
        module1.enroll(student1);
        module1.enroll(student2);
        module1.enroll(student2);

        String result = "Student U0000001  enrolled to Module CIS2206\n" +
                "Student U0000002  enrolled to Module CIS2206\n" +
                "Student U0000002  already enrolled to Module CIS2206\n";

        assertEquals(result, outContent.toString().replace("\r", ""));
    }

    @Test
    void unenroll() {
        module1.enroll(student1);
        module1.enroll(student2);
        module1.unenroll(student2);
        module1.unenroll(student3);

        String output = "Student U0000001  enrolled to Module CIS2206\n" +
                "Student U0000002  enrolled to Module CIS2206\n" +
                "Student U0000002  unenrolled from Module CIS2206\n" +
                "Student U0000003  does not enrolled to Module CIS2206\n";

        assertEquals(output, outContent.toString().replace("\r", ""));
    }


    @Test
    void display() {
        module1.enroll(student1);
        module1.enroll(student2);
        module1.unenroll(student1);
        module1.enroll(student3);

        module2.enroll(student1);
        module2.enroll(student3);
        module2.unenroll(student3);
        module2.unenroll(student2);

        String output = "Student U0000001  enrolled to Module CIS2206\n" +
                "Student U0000002  enrolled to Module CIS2206\n" +
                "Student U0000001  unenrolled from Module CIS2206\n" +
                "Student U0000003  enrolled to Module CIS2206\n" +
                "Student U0000001  enrolled to Module CIS2360\n" +
                "Student U0000003  enrolled to Module CIS2360\n" +
                "Student U0000003  unenrolled from Module CIS2360\n" +
                "Student U0000002  does not enrolled to Module CIS2360\n";

        assertEquals(output, outContent.toString().replace("\r", ""));


    }


}