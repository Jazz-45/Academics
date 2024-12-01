import java.awt.*;
import java.awt.event.*;

public class ListSelectionApp {
    public static void main(String[] args) {
        Frame frame = new Frame("List Selection Example");
        List itemList = new List();
        TextField selectedItemField = new TextField(20);

        selectedItemField.setEditable(false);
        itemList.add("Apple");
        itemList.add("Banana");
        itemList.add("Cherry");

        frame.setLayout(new FlowLayout());
        frame.add(itemList);
        frame.add(selectedItemField);

        itemList.addItemListener(e -> selectedItemField.setText(itemList.getSelectedItem()));

        frame.setSize(300, 200);
        frame.setVisible(true);

        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }
}
