import javax.swing.*;

public class TabbedPaneApp {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Tabbed Pane Example");
        JTabbedPane tabbedPane = new JTabbedPane();

        JPanel inputPanel = new JPanel();
        JTextField textField = new JTextField(20);
        inputPanel.add(new JLabel("Enter text:"));
        inputPanel.add(textField);

        JPanel contentPanel = new JPanel();
        contentPanel.add(new JLabel("<html>Sample Content:<br>This is the second tab!</html>"));

        tabbedPane.addTab("Input Tab", inputPanel);
        tabbedPane.addTab("Content Tab", contentPanel);

        frame.add(tabbedPane);
        frame.setSize(400, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
