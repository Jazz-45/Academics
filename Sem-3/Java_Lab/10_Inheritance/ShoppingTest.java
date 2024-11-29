// Superclass
abstract class Product {
    String name;
    double price;

    Product(String name, double price) {
        this.name = name;
        this.price = price;
    }

    abstract void displayDetails();
}

// Subclass: Electronics
class Electronics extends Product {
    int warrantyPeriod;

    Electronics(String name, double price, int warrantyPeriod) {
        super(name, price);
        this.warrantyPeriod = warrantyPeriod;
    }

    @Override
    void displayDetails() {
        System.out.println("Electronics: " + name + ", Price: $" + price + ", Warranty: " + warrantyPeriod + " years");
    }
}

// Subclass: Clothing
class Clothing extends Product {
    String size;

    Clothing(String name, double price, String size) {
        super(name, price);
        this.size = size;
    }

    @Override
    void displayDetails() {
        System.out.println("Clothing: " + name + ", Price: $" + price + ", Size: " + size);
    }
}

// Test Class
public class ShoppingTest {
    public static void main(String[] args) {
        Product[] products = {
            new Electronics("Laptop", 1200, 2),
            new Clothing("T-Shirt", 20, "M")
        };

        double total = 0;
        for (Product product : products) {
            product.displayDetails();
            total += product.price;
        }
        System.out.println("Total Price: $" + total);
    }
}
