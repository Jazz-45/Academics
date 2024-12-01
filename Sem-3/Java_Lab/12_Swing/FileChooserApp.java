import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class FileChooserApp {
    public static void main(String[] args) {
        JFrame frame = new JFrame("File Chooser");
        JLabel label = new JLabel("Selected File Path: None", JLabel.CENTER);
        JButton button = new JButton("Choose File");

        button.addActionListener(e -> {
            JFileChooser fileChooser = new JFileChooser();
            int result = fileChooser.showOpenDialog(frame);
            if (result == JFileChooser.APPROVE_OPTION) {
                label.setText("Selected File Path: " + fileChooser.getSelectedFile().getAbsolutePath());
            }
        });

        frame.setLayout(new BorderLayout());
        frame.add(button, BorderLayout.NORTH);
        frame.add(label, BorderLayout.CENTER);

        frame.setSize(400, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
