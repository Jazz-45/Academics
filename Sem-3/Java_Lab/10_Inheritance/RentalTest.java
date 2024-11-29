// Abstract Class
abstract class Vehicle {
    String model;
    boolean isAvailable;
    double baseRate;

    Vehicle(String model, double baseRate) {
        this.model = model;
        this.baseRate = baseRate;
        this.isAvailable = true;
    }

    abstract double calculateRentalCost(int days);

    boolean checkAvailability() {
        return isAvailable;
    }

    void rent() {
        if (isAvailable) {
            isAvailable = false;
            System.out.println(model + " has been rented.");
        } else {
            System.out.println(model + " is not available.");
        }
    }

    void returnVehicle() {
        isAvailable = true;
        System.out.println(model + " has been returned.");
    }
}

// Subclass: Car
class Car extends Vehicle {
    boolean isLuxury;

    Car(String model, double baseRate, boolean isLuxury) {
        super(model, baseRate);
        this.isLuxury = isLuxury;
    }

    @Override
    double calculateRentalCost(int days) {
        return days * baseRate * (isLuxury ? 1.2 : 1.0);
    }
}

// Subclass: Motorcycle
class Motorcycle extends Vehicle {
    boolean isHighPower;

    Motorcycle(String model, double baseRate, boolean isHighPower) {
        super(model, baseRate);
        this.isHighPower = isHighPower;
    }

    @Override
    double calculateRentalCost(int days) {
        return days * baseRate * (isHighPower ? 1.15 : 1.0);
    }
}

// Test Class
public class RentalTest {
    public static void main(String[] args) {
        Vehicle car = new Car("Sedan", 50, true);
        Vehicle bike = new Motorcycle("Ducati", 30, true);

        car.rent();
        System.out.println("Rental cost for car (3 days): $" + car.calculateRentalCost(3));
        car.returnVehicle();

        bike.rent();
        System.out.println("Rental cost for bike (5 days): $" + bike.calculateRentalCost(5));
        bike.returnVehicle();
    }
}
