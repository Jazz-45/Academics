class TicketBookingSystem {
    private int availableTickets;

    TicketBookingSystem(int availableTickets) {
        this.availableTickets = availableTickets;
    }

    public synchronized void bookTicket(String user, int tickets) {
        if (tickets <= availableTickets) {
            System.out.println(user + " booked " + tickets + " ticket(s).");
            availableTickets -= tickets;
        } else {
            System.out.println(user + " tried to book " + tickets + " ticket(s), but only " + availableTickets + " are available.");
        }
        System.out.println("Tickets remaining: " + availableTickets);
    }
}

class TicketBookingThread extends Thread {
    private final TicketBookingSystem system;
    private final String user;
    private final int tickets;

    TicketBookingThread(TicketBookingSystem system, String user, int tickets) {
        this.system = system;
        this.user = user;
        this.tickets = tickets;
    }

    public void run() {
        system.bookTicket(user, tickets);
    }
}

public class TicketBooking {
    public static void main(String[] args) {
        TicketBookingSystem system = new TicketBookingSystem(10);
        new TicketBookingThread(system, "User1", 4).start();
        new TicketBookingThread(system, "User2", 6).start();
        new TicketBookingThread(system, "User3", 2).start();
    }
}
