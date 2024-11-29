// Abstract Class
abstract class Notification {
    abstract void send();
}

// Subclass: EmailNotification
class EmailNotification extends Notification {
    String recipientEmail;

    EmailNotification(String recipientEmail) {
        this.recipientEmail = recipientEmail;
    }

    @Override
    void send() {
        System.out.println("Sending Email to: " + recipientEmail);
    }
}

// Subclass: SMSNotification
class SMSNotification extends Notification {
    String recipientPhoneNumber;

    SMSNotification(String recipientPhoneNumber) {
        this.recipientPhoneNumber = recipientPhoneNumber;
    }

    @Override
    void send() {
        System.out.println("Sending SMS to: " + recipientPhoneNumber);
    }
}

// Test Class
public class NotificationTest {
    public static void main(String[] args) {
        Notification email = new EmailNotification("user@example.com");
        Notification sms = new SMSNotification("1234567890");

        email.send();
        sms.send();
    }
}
