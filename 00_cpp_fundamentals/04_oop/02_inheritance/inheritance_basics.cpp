// Inheritance — OOP pillar 2
// Single, multilevel, hierarchical, and virtual diamond inheritance demos.
#include <iostream>
#include <string>

class Animal {
protected:
    std::string name; // visible to derived
public:
    Animal(std::string n) : name(n) {}
    void eat() { std::cout << name << " is eating." << std::endl; }
};

class Dog : public Animal {
public:
    Dog(std::string n) : Animal(n) {}
    void bark() { std::cout << name << " is barking: Woof! Woof!" << std::endl; }
};

class GermanShepherd : public Dog {
public:
    GermanShepherd(std::string n) : Dog(n) {}
    void guard() { std::cout << name << " is guarding the house." << std::endl; }
};

class Cat : public Animal {
public:
    Cat(std::string n) : Animal(n) {}
    void meow() { std::cout << name << " is meowing: Meow!" << std::endl; }
};

class LivingThing {
public:
    LivingThing() { std::cout << "LivingThing constructor called." << std::endl; }
    void breathe() { std::cout << "Breathing..." << std::endl; }
};

class ParentA : virtual public LivingThing { // virtual base
public:
    ParentA() { std::cout << "ParentA constructor called." << std::endl; }
};

class ParentB : virtual public LivingThing {
public:
    ParentB() { std::cout << "ParentB constructor called." << std::endl; }
};

class Child : public ParentA, public ParentB {
public:
    Child() { std::cout << "Child constructor called." << std::endl; }
};

int main() {
    std::cout << "=== OOP Pillar 2: Inheritance ===" << std::endl;

    std::cout << "\n--- 1. Testing Single Inheritance ---" << std::endl;
    Dog dog("Buddy");
    dog.eat();
    dog.bark();

    std::cout << "\n--- 2. Testing Multilevel Inheritance ---" << std::endl;
    GermanShepherd gs("Rex");
    gs.eat();
    gs.bark();
    gs.guard();

    std::cout << "\n--- 3. Testing Hierarchical Inheritance ---" << std::endl;
    Cat cat("Whiskers");
    cat.eat();
    cat.meow();

    std::cout << "\n--- 4. Testing Multiple/Virtual Inheritance (Diamond Problem Resolution) ---"
              << std::endl;
    Child child;
    child.breathe();

    return 0;
}
