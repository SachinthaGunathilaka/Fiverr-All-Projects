import java.util.ArrayList;
import java.util.Objects;

public class Students {
    ArrayList<Student> students;

    public Students() {
        students = new ArrayList<Student>();
    }

    public void addStudent(Student student) {
        students.add(student);
    }

    public boolean editStudent(String id, String name){
        for (Student student:students) {
            if(Objects.equals(student.getId(), id)){
                student.setName(name);
                return true;
            }

        }
        return false;
    }

    public Student getStudent(String id) {
        for (Student student : students) {
            if (Objects.equals(student.getId(), id))
                return student;
        }
        return null;
    }

    public void displayStudent(String id) {
        for (Student student : students) {
            if (student.getId() == id){
                student.displayStudent();
                return;
            }

        }
        System.out.println("Student not found!");
    }

    public void displayStudents() {
        System.out.println();
        for (Student student : students) {
            student.displayStudent();

        }
    }

    public boolean deleteStudent(String id){
        int i;
        for (i = 0; i < students.size(); i++) {
            if(Objects.equals(students.get(i).getId(), id))
                break;
        }
        if(i == students.size())
            return false;

        students.remove(i);
        return true;
    }

    public boolean isExist(String id){
        for (Student student:students) {
            if(Objects.equals(student.getId(), id))
                return true;
        }
        return false;
    }

    public Student getStudentByIndex(int index){
        return students.get(index);
    }

    public ArrayList<Student> getStudents() {
        return students;
    }

    public int getNumOfStudents(){
        return students.size();
    }
}
