import javax.swing.*;

public class WelcomeApp {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Welcome App");
        JLabel label = new JLabel("Welcome!", JLabel.CENTER);
        String name = JOptionPane.showInputDialog(frame, "Enter your name:");
        label.setFont(label.getFont().deriveFont(20f));

        if (name != null && !name.isEmpty()) {
            label.setText("Welcome, " + name + "!");
        }

        frame.add(label);
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
