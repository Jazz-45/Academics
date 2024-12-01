import javax.swing.*;
import java.awt.event.*;

public class CountdownTimerApp {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Countdown Timer");
        JLabel label = new JLabel("10", JLabel.CENTER);
        Timer timer;

        label.setFont(label.getFont().deriveFont(50f));
        frame.add(label);

        timer = new Timer(1000, new ActionListener() {
            int timeLeft = 10;

            @Override
            public void actionPerformed(ActionEvent e) {
                timeLeft--;
                if (timeLeft >= 0) {
                    label.setText(String.valueOf(timeLeft));
                } else {
                    label.setText("Time's up!");
                    ((Timer) e.getSource()).stop();
                }
            }
        });

        timer.start();

        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
