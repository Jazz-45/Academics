import java.awt.*;
import java.awt.event.*;

public class CounterApp {
    private static int count = 0;

    public static void main(String[] args) {
        Frame frame = new Frame("Counter Example");
        Label label = new Label("Count:");
        TextField textField = new TextField("0", 10);
        Button button = new Button("Count");

        textField.setEditable(false);

        frame.setLayout(new FlowLayout());
        frame.add(label);
        frame.add(textField);
        frame.add(button);

        button.addActionListener(e -> textField.setText(String.valueOf(++count)));

        frame.setSize(300, 200);
        frame.setVisible(true);

        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }
}
