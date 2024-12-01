import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DecimalFormat;

public class Calculator extends JFrame {
    private JTextField displayField;
    private double firstNumber = 0;
    private String operator = "";
    private boolean startNewNumber = true;
    private DecimalFormat df = new DecimalFormat("#.##");

    public Calculator() {
        // Set up the main frame
        setTitle("Simple Calculator");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        setSize(300, 400);

        // Create display field
        displayField = new JTextField("0");
        displayField.setEditable(false);
        displayField.setHorizontalAlignment(JTextField.RIGHT);
        displayField.setFont(new Font("Arial", Font.PLAIN, 24));
        add(displayField, BorderLayout.NORTH);

        // Create button panel
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(4, 4, 5, 5));

        // Define button labels
        String[] buttonLabels = {
            "7", "8", "9", "/",
            "4", "5", "6", "*",
            "1", "2", "3", "-",
            "0", ".", "=", "+"
        };

        // Create buttons
        for (String label : buttonLabels) {
            JButton button = new JButton(label);
            button.setFont(new Font("Arial", Font.PLAIN, 18));
            button.addActionListener(new ButtonClickListener());
            buttonPanel.add(button);
        }

        // Add Clear button
        JButton clearButton = new JButton("Clear");
        clearButton.setFont(new Font("Arial", Font.PLAIN, 18));
        clearButton.addActionListener(e -> {
            displayField.setText("0");
            firstNumber = 0;
            operator = "";
            startNewNumber = true;
        });

        // Add buttons to main frame
        add(buttonPanel, BorderLayout.CENTER);
        add(clearButton, BorderLayout.SOUTH);
    }

    private class ButtonClickListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String command = e.getActionCommand();

            // Handle number and decimal point input
            if ((command.charAt(0) >= '0' && command.charAt(0) <= '9') || command.equals(".")) {
                if (startNewNumber) {
                    displayField.setText(command.equals(".") ? "0." : command);
                    startNewNumber = false;
                } else {
                    // Prevent multiple decimal points
                    if (command.equals(".") && displayField.getText().contains(".")) {
                        return;
                    }
                    displayField.setText(displayField.getText() + command);
                }
            }
            // Handle operators
            else if (command.equals("+") || command.equals("-") || 
                     command.equals("*") || command.equals("/")) {
                // If there's a previous operation pending, calculate first
                if (!operator.isEmpty()) {
                    calculateResult();
                }
                
                firstNumber = Double.parseDouble(displayField.getText());
                operator = command;
                startNewNumber = true;
            }
            // Handle equals
            else if (command.equals("=")) {
                calculateResult();
                operator = "";
            }
        }

        private void calculateResult() {
            try {
                double secondNumber = Double.parseDouble(displayField.getText());
                double result = 0;

                switch (operator) {
                    case "+":
                        result = firstNumber + secondNumber;
                        break;
                    case "-":
                        result = firstNumber - secondNumber;
                        break;
                    case "*":
                        result = firstNumber * secondNumber;
                        break;
                    case "/":
                        if (secondNumber == 0) {
                            displayField.setText("Error: Div by 0");
                            startNewNumber = true;
                            return;
                        }
                        result = firstNumber / secondNumber;
                        break;
                }

                // Format result to two decimal places
                String formattedResult = df.format(result);
                displayField.setText(formattedResult);
                firstNumber = Double.parseDouble(formattedResult);
                startNewNumber = true;
            } catch (NumberFormatException ex) {
                displayField.setText("Error");
                startNewNumber = true;
            }
        }
    }

    public static void main(String[] args) {
        // Ensure GUI is created on the Event Dispatch Thread
        SwingUtilities.invokeLater(() -> {
            Calculator calculator = new Calculator();
            calculator.setVisible(true);
        });
    }
}
