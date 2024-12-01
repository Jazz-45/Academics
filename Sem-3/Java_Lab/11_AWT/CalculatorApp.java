import java.awt.*;
import java.awt.event.*;

public class CalculatorApp {
    public static void main(String[] args) {
        Frame frame = new Frame("Simple Calculator");
        Label num1Label = new Label("Number 1:");
        Label num2Label = new Label("Number 2:");
        Label resultLabel = new Label("Result:");
        TextField num1Field = new TextField(10);
        TextField num2Field = new TextField(10);
        TextField resultField = new TextField(10);
        Button addButton = new Button("Add");

        resultField.setEditable(false);

        frame.setLayout(new FlowLayout());
        frame.add(num1Label);
        frame.add(num1Field);
        frame.add(num2Label);
        frame.add(num2Field);
        frame.add(addButton);
        frame.add(resultLabel);
        frame.add(resultField);

        addButton.addActionListener(e -> {
            try {
                int num1 = Integer.parseInt(num1Field.getText());
                int num2 = Integer.parseInt(num2Field.getText());
                resultField.setText(String.valueOf(num1 + num2));
            } catch (NumberFormatException ex) {
                resultField.setText("Invalid input");
            }
        });

        frame.setSize(350, 200);
        frame.setVisible(true);

        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }
}
