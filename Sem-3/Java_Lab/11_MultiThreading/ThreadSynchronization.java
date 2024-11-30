class Counter {
    private int count = 0;

    public synchronized void increment() {
        count++;
    }

    public int getCount() {
        return count;
    }
}

class Incrementer extends Thread {
    private final Counter counter;

    Incrementer(Counter counter) {
        this.counter = counter;
    }

    public void run() {
        for (int i = 0; i < 1000; i++) {
            counter.increment();
        }
    }
}

public class ThreadSynchronization {
    public static void main(String[] args) throws InterruptedException {
        Counter counter = new Counter();
        Thread t1 = new Incrementer(counter);
        Thread t2 = new Incrementer(counter);

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        System.out.println("Final Counter Value: " + counter.getCount());
    }
}
