package Practical_11;

import static org.junit.jupiter.api.Assertions.*;

class StudentTest {

    private Student student1;
    private Student student2;
    @org.junit.jupiter.api.BeforeEach
    public void init(){
        student1 = new Student("U0000001", "John", "Charles", 20);
        student2 = new Student("U0000002", "Kane", "William", 25);
    }

    @org.junit.jupiter.api.Test
    void getStudent_id() {
        assertEquals("U0000001", student1.getStudent_id());
    }

    @org.junit.jupiter.api.Test
    void getName() {
        assertEquals("John", student1.getName());
    }

    @org.junit.jupiter.api.Test
    void getSurname() {
        assertEquals("Charles", student1.getSurname());
    }

    @org.junit.jupiter.api.Test
    void getAge() {
        assertEquals(20, student1.getAge());

    }

    @org.junit.jupiter.api.Test
    void testToString() {
        assertEquals("Student ID: U0000001, Name: John, Surname: Charles, Age: 20", student1.toString());
    }

    @org.junit.jupiter.api.Test
    void compareTo() {
        assertEquals(1, student1.compareTo(student2));
    }
}