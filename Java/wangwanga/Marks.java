import java.util.ArrayList;
import java.util.HashMap;
import java.util.Objects;

public class Marks {
    HashMap<String, ArrayList<Mark>> marks;


    public Marks() {
        marks = new HashMap<String, ArrayList<Mark>>();
    }

    public boolean addMark(String unit_id, Mark mark) {
        if (!marks.containsKey(unit_id)) {
            marks.put(unit_id, new ArrayList<Mark>());
        }
        for (Mark cur_mark : marks.get(unit_id)) {
            if (Objects.equals(cur_mark.getStd_id(), mark.getStd_id())) {
                return false;
            }
        }

        marks.get(unit_id).add(mark);
        return true;

//        System.out.println("Mark added successfully!");

    }

    public boolean editMark(String unit_id, String std_id, double mark) {
        if (!marks.containsKey(unit_id)) {
            return false;
        }
        for (Mark cur_mark : marks.get(unit_id)) {
            if (Objects.equals(cur_mark.getStd_id(), std_id)) {
                cur_mark.setMark(mark);
                return true;
            }
        }

        return false;

//        System.out.println("Mark added successfully!");

    }


    public void displayMarksSubjectsVise() {
        for (String key : marks.keySet()) {
            System.out.println("\n Unit ID   :   " + key);
            System.out.println("-----------------------");
            System.out.print(String.format("%-15s  %s\n", "Student ID", "Mark"));

            double total = 0;;
            for (Mark mark : marks.get(key)) {
                System.out.print(String.format("%-15s  %.2f\n", mark.getStd_id(), mark.getMark()));
                total += mark.getMark();

            }

            if(marks.get(key).size() != 0)
                System.out.printf("\nAverage Mark : %.2f\n", total/marks.get(key).size());

            else
                System.out.printf(String.format("\t\t  %15s", "No marks found\n"));

        }
    }

    public void displayAllUnitReport(Subjects subjects){
        for (Subject subject:subjects.getSubjects()) {
            System.out.printf("\n%s\t(%s)\n", subject.getName(), subject.getId());
            System.out.println("--------------------------------------");

            if(marks.get(subject.getId()) == null)
                System.out.printf(String.format("\t\t  %15s", "No marks found\n"));
            else
                displayUnitReport(subject.getId());
        }
    }

    public void displayAllStdReport(Students students, Subjects subjects){
        for (Student student:students.getStudents()) {
            System.out.printf("\n%s\t(%s)\n", student.getName(), student.getId());
            System.out.println("--------------------------------------");

            displayStudentResults(student.getId(), subjects);
        }
    }

    public boolean deleteMark(String unit_id, String std_id) {
        if (!marks.containsKey(unit_id)) {
            return false;
        }
        int i;
        for (i = 0; i < marks.get(unit_id).size(); i++) {
            if (Objects.equals(marks.get(unit_id).get(i).getStd_id(), std_id)) {
                break;
            }
        }
        if (i == marks.get(unit_id).size())
            return false;

        marks.get(unit_id).remove(i);
        if(marks.get(unit_id).size() == 0)
            marks.remove(unit_id);
        return true;
    }

    public Mark getMark(String unit_id, String std_id) {
        if (!marks.containsKey(unit_id)) {
            return null;
        }

        for (Mark mark : marks.get(unit_id)) {
            if (Objects.equals(mark.getStd_id(), std_id))
                return mark;
        }
        return null;
    }

    public double getStudentMark(ArrayList<Mark> marks, String id){
        for (Mark mark:marks) {
            if(Objects.equals(mark.getStd_id(), id))
                return mark.getMark();

        }
        return -1;
    }

    public void displayStudentResults(String std_id, Subjects subjects){
        double total = 0;
        int count = 0;
        System.out.print(String.format("%-30s  %s\n\n", "Unit Name", "Mark"));
        for (String key : marks.keySet()) {
            double mark = getStudentMark(marks.get(key),std_id);
            if(mark != -1){
                System.out.print(String.format("%-30s  %.2f\n", subjects.getSubject(key).getName(), mark));
                total += mark;
                count++;
            }
        }

        if(count != 0)
            System.out.printf("\nAverage Mark : %.2f\n", total/count);

        else
            System.out.printf(String.format("\t\t  %15s", "No marks found\n"));

    }

    public void displayUnitReport(String unit_id){
        double total = 0;
        System.out.print(String.format("%-30s  %s\n\n", "Student ID", "Mark"));
        for (Mark mark:marks.get(unit_id)) {
            System.out.print(String.format("%-30s  %s\n", mark.getStd_id(), mark.getMark()));
            total += mark.getMark();
        }

        if(marks.get(unit_id).size() != 0)
            System.out.printf("\nAverage Mark : %.2f\n", total/marks.get(unit_id).size());

        else
            System.out.printf(String.format("\t\t  %15s", "No marks found\n"));
    }
    public HashMap<String, ArrayList<Mark>> getMarks() {
        return marks;
    }
}
