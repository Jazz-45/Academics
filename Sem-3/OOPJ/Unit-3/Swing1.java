import javax.swing.JFrame;
import javax.swing.JLabel;

public class Swing1{
  public static void main(String[] args){
    Jframe frame = new JFrame("Swing Demo 1");
    frame.setSize(200,300);
    frame.setVisibility(true);
    frame.setDeafaultCloseOperation(Jframe.EXIT_ON_CLOSE);

    JLabel label =new JLabel("Swing Label 1");
    frame.add(label);
  }
}
