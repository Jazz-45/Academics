import java.util.concurrent.Semaphore;

class Worker extends Thread {
    private final Semaphore semaphore;
    private final int workerId;

    Worker(Semaphore semaphore, int workerId) {
        this.semaphore = semaphore;
        this.workerId = workerId;
    }

    public void run() {
        try {
            semaphore.acquire();
            System.out.println("Worker " + workerId + " is accessing the resource.");
            Thread.sleep(1000); // Simulating resource usage
            System.out.println("Worker " + workerId + " is done.");
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        } finally {
            semaphore.release();
        }
    }
}

public class SemaphoreExample {
    public static void main(String[] args) {
        Semaphore semaphore = new Semaphore(2); // Allowing 2 threads at a time
        for (int i = 1; i <= 5; i++) {
            new Worker(semaphore, i).start();
        }
    }
}
