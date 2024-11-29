// Superclass
class User {
    String username, email;

    User(String username, String email) {
        this.username = username;
        this.email = email;
    }

    void viewProfile() {
        System.out.println("Username: " + username + ", Email: " + email);
    }
}

// Subclass: AdminUser
class AdminUser extends User {
    int adminLevel;

    AdminUser(String username, String email, int adminLevel) {
        super(username, email);
        this.adminLevel = adminLevel;
    }

    void postMessage() {
        System.out.println("Admin " + username + " posted a message.");
    }
}

// Subclass: RegularUser
class RegularUser extends User {
    String[] friendsList;

    RegularUser(String username, String email, String[] friendsList) {
        super(username, email);
        this.friendsList = friendsList;
    }

    void postMessage() {
        System.out.println("User " + username + " posted a message.");
    }
}

// Test Class
public class UserTest {
    public static void main(String[] args) {
        User admin = new AdminUser("AdminUser", "admin@example.com", 1);
        User regular = new RegularUser("RegularUser", "user@example.com", new String[]{"Friend1", "Friend2"});

        admin.viewProfile();
        regular.viewProfile();

        ((AdminUser) admin).postMessage();
        ((RegularUser) regular).postMessage();
    }
}
