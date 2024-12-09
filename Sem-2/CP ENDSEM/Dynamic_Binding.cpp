#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Virtual function
    virtual void makeSound() {
        cout << "Animal makes a sound" << endl;
    }
};

// Derived class 1
class Dog : public Animal {
public:
    // Override the virtual function
    void makeSound() override {
        cout << "Dog barks" << endl;
    }
};

// Derived class 2
class Cat : public Animal {
public:
    // Override the virtual function
    void makeSound() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    
    Animal *animalPtr = new Dog();
    animalPtr->makeSound();

    animalPtr = new Cat();
    animalPtr->makeSound();

    Animal w;
    w.makeSound();
    

    delete animalPtr;
    return 0;
}
