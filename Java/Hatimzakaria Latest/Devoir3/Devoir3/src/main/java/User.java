import java.util.UUID;

public class User {
    private String id;
    private Member member;
    private boolean isSuspended;
    private boolean isActive;
    private String confirmationDate;
    private String lastLoginDate;
    private String registrationDate;

    public User() {

    }

    public User(Member member) {
        this.id = UUID.randomUUID().toString();
        this.member = member;
        this.isSuspended = true;
        this.isActive = false;
        this.confirmationDate = "";
        this.lastLoginDate = "";
        this.registrationDate = java.time.LocalDate.now().toString();

    }

    public void validate() {
        isSuspended = false;
    }

    public void setActive(boolean active) {
        isActive = active;
    }

    public void setConfirmationDate(String confirmationDate) {
        this.confirmationDate = confirmationDate;
    }

    public void setLastLoginDate(String lastLoginDate) {
        this.lastLoginDate = lastLoginDate;
    }

    public boolean isValid() {
        return !isSuspended;
    }

    public String getId() {
        return id;
    }

    public Member getMember() {
        return member;
    }


    public String getConfirmationDate() {
        return confirmationDate;
    }

    public String getLastLoginDate() {
        return lastLoginDate;
    }

    public String getRegistrationDate() {
        return registrationDate;
    }

    @Override
    public String toString() {
        return "User{" +
                "id='" + id + '\'' +
                ", member=" + member +
                ", isSuspended=" + isSuspended +
                ", isActive=" + isActive +
                ", confirmationDate='" + confirmationDate + '\'' +
                ", lastLoginDate='" + lastLoginDate + '\'' +
                ", registrationDate='" + registrationDate + '\'' +
                '}';
    }
}
