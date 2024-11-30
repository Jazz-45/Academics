class NumberThread extends Thread {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println("Number: " + i);
        }
    }
}

public class PrintNumbers {
    public static void main(String[] args) {
        NumberThread thread = new NumberThread();
        thread.start();
    }
}
