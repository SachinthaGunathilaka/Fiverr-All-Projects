import java.util.ArrayList;

public class Members {
    private static ArrayList<Member> members = new ArrayList<>();

    public static void addMember(int member_id, String name) {
        for (Member member : members) {
            if (member.getMember_id() == member_id) {
                System.out.println("Member id already exists!");
                return;
            }
        }
        Member member = new Member(member_id, name);
        members.add(member);
    }

    public static void requestItem(int member_id, int item_number) {
        for (Member member : members) {
            if (member.getMember_id() == member_id) {
                member.requestItem(item_number);
                return;
            }
        }

        System.out.println("Invalid member id!");
    }

    public static void readFromFile(int member_id, int item_number) {
        for (Member member : members) {
            if (member.getMember_id() == member_id) {
                member.readFromFile(item_number);
                break;
            }
        }
    }

    public static void displayMembers() {
        for (Member member : members) {
            member.display();
        }
    }

    public static void returnItem(int member_id, int item_number){
        for (Member member:members) {
            if(member.getMember_id() == member_id){
                member.returnItem(item_number);
                break;
            }
        }
    }
}
