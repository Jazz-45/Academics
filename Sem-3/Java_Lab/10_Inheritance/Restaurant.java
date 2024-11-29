// Abstract Class
abstract class MenuItem {
    String name;
    double basePrice;
    boolean isSpecial;

    MenuItem(String name, double basePrice, boolean isSpecial) {
        this.name = name;
        this.basePrice = basePrice;
        this.isSpecial = isSpecial;
    }

    abstract double calculatePrice();

    void applySpecialStatus(boolean status) {
        this.isSpecial = status;
    }

    abstract void displayDescription();
}

// Subclass: MainDish
class MainDish extends MenuItem {
    String cuisineType;

    MainDish(String name, double basePrice, boolean isSpecial, String cuisineType) {
        super(name, basePrice, isSpecial);
        this.cuisineType = cuisineType;
    }

    @Override
    double calculatePrice() {
        return isSpecial ? basePrice * 0.9 : basePrice;
    }

    @Override
    void displayDescription() {
        System.out.println("Main Dish: " + name + ", Cuisine: " + cuisineType + ", Price: $" + calculatePrice());
    }
}

// Subclass: Dessert
class Dessert extends MenuItem {
    int calories;

    Dessert(String name, double basePrice, boolean isSpecial, int calories) {
        super(name, basePrice, isSpecial);
        this.calories = calories;
    }

    @Override
    double calculatePrice() {
        return isSpecial ? basePrice * 0.85 : basePrice;
    }

    @Override
    void displayDescription() {
        System.out.println("Dessert: " + name + ", Calories: " + calories + ", Price: $" + calculatePrice());
    }
}

// Test Class
public class RestaurantTest {
    public static void main(String[] args) {
        MenuItem[] menuItems = {
            new MainDish("Pasta", 12.99, false, "Italian"),
            new Dessert("Ice Cream", 6.99, true, 200)
        };

        for (MenuItem item : menuItems) {
            item.displayDescription();
        }
    }
}
