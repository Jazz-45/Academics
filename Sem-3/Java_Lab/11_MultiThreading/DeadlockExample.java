class Deadlock {
    private final Object lock1 = new Object();
    private final Object lock2 = new Object();

    public void method1() {
        synchronized (lock1) {
            System.out.println("Thread 1: Holding lock 1...");
            try { Thread.sleep(50); } catch (InterruptedException e) {}
            synchronized (lock2) {
                System.out.println("Thread 1: Acquired lock 2.");
            }
        }
    }

    public void method2() {
        synchronized (lock2) {
            System.out.println("Thread 2: Holding lock 2...");
            try { Thread.sleep(50); } catch (InterruptedException e) {}
            synchronized (lock1) {
                System.out.println("Thread 2: Acquired lock 1.");
            }
        }
    }
}

public class DeadlockExample {
    public static void main(String[] args) {
        Deadlock deadlock = new Deadlock();

        Thread t1 = new Thread(deadlock::method1);
        Thread t2 = new Thread(deadlock::method2);

        t1.start();
        t2.start();
    }
}
