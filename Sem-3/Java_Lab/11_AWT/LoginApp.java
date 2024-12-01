import java.awt.*;
import java.awt.event.*;

public class LoginApp {
    public static void main(String[] args) {
        Frame frame = new Frame("Login Form");
        Label userLabel = new Label("Username:");
        Label passLabel = new Label("Password:");
        TextField userField = new TextField(20);
        TextField passField = new TextField(20);
        passField.setEchoChar('*');
        Button loginButton = new Button("Login");
        Button clearButton = new Button("Clear");
        Label messageLabel = new Label();

        frame.setLayout(new FlowLayout());
        frame.add(userLabel);
        frame.add(userField);
        frame.add(passLabel);
        frame.add(passField);
        frame.add(loginButton);
        frame.add(clearButton);
        frame.add(messageLabel);

        loginButton.addActionListener(e -> {
            String username = userField.getText();
            String password = passField.getText();
            if ("user".equals(username) && "password".equals(password)) {
                messageLabel.setText("Login successful!");
            } else {
                messageLabel.setText("Invalid username or password.");
            }
        });

        clearButton.addActionListener(e -> {
            userField.setText("");
            passField.setText("");
            messageLabel.setText("");
        });

        frame.setSize(300, 200);
        frame.setVisible(true);

        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }
}
