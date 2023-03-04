package Practical_11;

public class Module {
    private String module_id;
    Student[] students;
    int size;
    int max_size;


    public Module(String module_id) {
        this.module_id = module_id;
        this.size = 0;
        this.max_size = 1;
        this.students = new Student[max_size];
    }

    public void enroll(Student student) {
        if (size == max_size) {
            max_size = max_size*2;
            Student [] new_students = new Student[max_size];
            for (int i = 0; i < size; i++) {
                new_students[i] = students[i];
            }
            students = new_students;
        }
        int i;
        for (i = 0; i < size; i++) {

            if (student.compareTo(students[i]) == 0) {
                System.out.println("Student " + student.getStudent_id() + "  already enrolled to Module " + module_id);
                return;
            }

            if (student.compareTo(students[i]) > 0) {
                break;
            }
        }
        for (int j = size - 1; j >= i; j--) {
            students[j + 1] = students[j];
        }
        students[i] = student;

        System.out.println("Student " + student.getStudent_id() + "  enrolled to Module " + module_id);
        size++;
    }

    public void unenroll(Student student) {
        int i;
        for (i = 0; i < size; i++) {

            if (student.compareTo(students[i]) == 0) {
                break;
            }
        }

        if (i == size) {
            System.out.println("Student " + student.getStudent_id() + "  does not enrolled to Module " + module_id);
            return;
        }

        for (int j = i; j < size - 1; j++) {
            students[j] = students[j + 1];
        }

        System.out.println("Student " + student.getStudent_id() + "  unenrolled from Module " + module_id);
        size--;
    }


    public void display() {
        System.out.println("\nModule : " + module_id);
        for (int i = 0; i < size; i++) {
            System.out.println("\t" + students[i]);
        }
    }
}
