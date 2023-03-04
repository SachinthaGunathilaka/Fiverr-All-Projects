package Practical_11;

public class Student implements Comparable<Student> {
    private String student_id;
    private String name;
    private String surname;
    private int age;

    public Student(String student_id, String name, String surname, int age) {
        this.student_id = student_id;
        this.name = name;
        this.surname = surname;
        this.age = age;
    }

    public String getStudent_id() {
        return student_id;
    }

    public String getName() {
        return name;
    }

    public String getSurname() {
        return surname;
    }

    public int getAge() {
        return age;
    }

    public String toString() {
        return "Student ID: " + student_id +
                ", Name: " + name +
                ", Surname: " + surname +
                ", Age: " + age;
    }

    public int compareTo(Student student) {
        return student.student_id.compareTo(this.getStudent_id());
    }


}
