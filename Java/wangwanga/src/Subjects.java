import java.util.ArrayList;
import java.util.Objects;

public class Subjects {
    ArrayList<Subject> subjects;

    public Subjects() {
        subjects = new ArrayList<Subject>();
    }

    public void addSubject(Subject subject) {
        subjects.add(subject);
//        System.out.println("Subject added successfully!");

    }

    public boolean editSubject(String id, String name){
        for (Subject subject:subjects) {
            if(Objects.equals(subject.getId(), id)){
                subject.setName(name);
                return true;
            }

        }
        return false;
    }

    public String findNameById(String id) {
        for (Subject subject : subjects) {
            if (subject.getId() == id)
                return subject.getName();
        }
        return null;
    }

    public void displaySubjects(){
        for (Subject subject:subjects) {
            subject.displaySubject();

        }
    }

    public boolean deleteSubject(String id){
        int i;
        for (i = 0; i < subjects.size(); i++) {
            if(Objects.equals(subjects.get(i).getId(), id))
                break;
        }
        if(i == subjects.size())
            return false;

        subjects.remove(i);
        return true;
    }

    public Subject getSubject(String id) {
        for (Subject subject : subjects) {
            if (Objects.equals(subject.getId(), id))
                return subject;
        }
        return null;
    }

    public boolean isExist(String id){
        for (Subject subject:subjects) {
            if(Objects.equals(subject.getId(), id))
                return true;
        }
        return false;
    }

    public ArrayList<Subject> getSubjects() {
        return subjects;
    }
}
