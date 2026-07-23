// Function Overriding — runtime polymorphism
// Base pointer calls virtual `sound`; dynamic type selects Dog/Cat override.
#include <iostream>

class Animal {
public:
    virtual void sound() { // enable dynamic dispatch
        std::cout << "Animal makes a sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void sound() override { // override base
        std::cout << "Dog barks" << std::endl;
    }
};

class Cat : public Animal {
public:
    void sound() override { // override base
        std::cout << "Cat meows" << std::endl;
    }
};

int main() {
    Animal* animal; // base pointer

    Dog d;
    Cat c;

    animal = &d;
    animal->sound(); // Dog::sound via vtable

    animal = &c;
    animal->sound(); // Cat::sound via vtable
    return 0;
}
