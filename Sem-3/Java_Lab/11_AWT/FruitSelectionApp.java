import java.awt.*;
import java.awt.event.*;

public class FruitSelectionApp {
    public static void main(String[] args) {
        Frame frame = new Frame("Fruit Selection");
        Checkbox orange = new Checkbox("Orange");
        Checkbox banana = new Checkbox("Banana");
        Checkbox apple = new Checkbox("Apple");
        TextArea resultArea = new TextArea(3, 30);
        Button submitButton = new Button("Submit");
        Button clearButton = new Button("Clear");

        resultArea.setEditable(false);
        frame.setLayout(new FlowLayout());
        frame.add(orange);
        frame.add(banana);
        frame.add(apple);
        frame.add(submitButton);
        frame.add(clearButton);
        frame.add(resultArea);

        submitButton.addActionListener(e -> {
            StringBuilder selectedFruits = new StringBuilder();
            if (orange.getState()) selectedFruits.append("Orange ");
            if (banana.getState()) selectedFruits.append("Banana ");
            if (apple.getState()) selectedFruits.append("Apple ");
            resultArea.setText(selectedFruits.length() > 0 ? selectedFruits.toString() : "No fruits selected");
        });

        clearButton.addActionListener(e -> {
            orange.setState(false);
            banana.setState(false);
            apple.setState(false);
            resultArea.setText("");
        });

        frame.setSize(400, 300);
        frame.setVisible(true);

        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }
}
