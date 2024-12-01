import java.awt.*;

public class HelloWorldAWT {
    public static void main(String[] args) {
        Frame frame = new Frame("Hello World Example");
        Label label = new Label("Hello, World!", Label.CENTER);

        frame.add(label);
        frame.setSize(300, 200);
        frame.setVisible(true);

        frame.addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosing(java.awt.event.WindowEvent e) {
                System.exit(0);
            }
        });
    }
}
