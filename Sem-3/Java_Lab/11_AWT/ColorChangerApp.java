import java.awt.*;
import java.awt.event.*;

public class ColorChangerApp {
    public static void main(String[] args) {
        Frame frame = new Frame("Background Color Changer");
        Label label = new Label("Select a color:");
        Choice colorChoice = new Choice();

        colorChoice.add("Red");
        colorChoice.add("Green");
        colorChoice.add("Blue");

        frame.setLayout(new FlowLayout());
        frame.add(label);
        frame.add(colorChoice);

        colorChoice.addItemListener(e -> {
            String selectedColor = colorChoice.getSelectedItem();
            switch (selectedColor) {
                case "Red":
                    frame.setBackground(Color.RED);
                    break;
                case "Green":
                    frame.setBackground(Color.GREEN);
                    break;
                case "Blue":
                    frame.setBackground(Color.BLUE);
                    break;
            }
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
