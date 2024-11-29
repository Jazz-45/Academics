// Superclass
abstract class LibraryItem {
    String title;
    int id;

    LibraryItem(String title, int id) {
        this.title = title;
        this.id = id;
    }

    abstract void displayDetails();
}

// Subclass: Book
class Book extends LibraryItem {
    String author;
    String ISBN;

    Book(String title, int id, String author, String ISBN) {
        super(title, id);
        this.author = author;
        this.ISBN = ISBN;
    }

    @Override
    void displayDetails() {
        System.out.println("Book Title: " + title + ", ID: " + id + ", Author: " + author + ", ISBN: " + ISBN);
    }
}

// Subclass: Magazine
class Magazine extends LibraryItem {
    int issueNumber;

    Magazine(String title, int id, int issueNumber) {
        super(title, id);
        this.issueNumber = issueNumber;
    }

    @Override
    void displayDetails() {
        System.out.println("Magazine Title: " + title + ", ID: " + id + ", Issue Number: " + issueNumber);
    }
}

// Test Class
public class LibraryTest {
    public static void main(String[] args) {
        LibraryItem[] collection = {
            new Book("Java Programming", 101, "Author A", "1234567890"),
            new Magazine("Tech Monthly", 202, 12)
        };

        for (LibraryItem item : collection) {
            item.displayDetails();
        }
    }
}
