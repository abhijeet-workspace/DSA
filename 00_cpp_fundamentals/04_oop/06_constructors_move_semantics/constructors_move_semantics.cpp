// Constructors, deep copy, move semantics, virtual destructor
// Rule of Five on ResourceManager; Base/Derived delete via base pointer.
#include <algorithm>
#include <iostream>
#include <utility>

class ResourceManager {
private:
    int* data;
    int size;

public:
    ResourceManager(int sz) : size(sz) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = i * 10;
        }
        std::cout << "Constructor: Allocated " << size << " integers." << std::endl;
    }

    ResourceManager(const ResourceManager& other) : size(other.size) {
        data = new int[size]; // deep copy
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        std::cout << "Copy Constructor: Performed DEEP COPY of " << size << " integers."
                  << std::endl;
    }

    ResourceManager& operator=(const ResourceManager& other) {
        std::cout << "Copy Assignment Operator: Called." << std::endl;
        if (this == &other) {
            return *this;
        }
        delete[] data;
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        return *this;
    }

    ResourceManager(ResourceManager&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr; // leave source empty
        other.size = 0;
        std::cout << "Move Constructor: Moved " << size << " integers (Zero-allocation)."
                  << std::endl;
    }

    ResourceManager& operator=(ResourceManager&& other) noexcept {
        std::cout << "Move Assignment Operator: Called." << std::endl;
        if (this == &other) {
            return *this;
        }
        delete[] data;
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
        return *this;
    }

    void print() {
        if (!data) {
            std::cout << "No data (resource moved or empty)." << std::endl;
            return;
        }
        for (int i = 0; i < std::min(size, 5); i++) {
            std::cout << data[i] << " ";
        }
        if (size > 5) {
            std::cout << "...";
        }
        std::cout << std::endl;
    }

    ~ResourceManager() {
        if (data != nullptr) {
            std::cout << "Destructor: Deallocating memory." << std::endl;
            delete[] data;
        } else {
            std::cout << "Destructor: Nothing to free." << std::endl;
        }
    }
};

class Base {
public:
    Base() { std::cout << "Base constructor." << std::endl; }
    virtual ~Base() { std::cout << "Base destructor." << std::endl; }
};

class Derived : public Base {
private:
    int* derivedData;

public:
    Derived() {
        derivedData = new int[100];
        std::cout << "Derived constructor: Allocated resource." << std::endl;
    }
    ~Derived() override {
        delete[] derivedData;
        std::cout << "Derived destructor: Freed resource." << std::endl;
    }
};

int main() {
    std::cout << "=== OOP: Deep Copy, Move Semantics & Virtual Destructors ===" << std::endl;

    std::cout << "\n--- 1. Parametrized Constructor ---" << std::endl;
    ResourceManager r1(10);
    r1.print();

    std::cout << "\n--- 2. Deep Copy Constructor ---" << std::endl;
    ResourceManager r2 = r1;
    r2.print();

    std::cout << "\n--- 3. Move Constructor ---" << std::endl;
    ResourceManager r3 = std::move(r1);
    std::cout << "r3 (after move): ";
    r3.print();
    std::cout << "r1 (after move): ";
    r1.print();

    std::cout << "\n--- 4. Move Assignment ---" << std::endl;
    ResourceManager r4(5);
    r4 = std::move(r3);
    std::cout << "r4 (after move assignment): ";
    r4.print();

    std::cout << "\n--- 5. Testing Virtual Destructors ---" << std::endl;
    Base* polymorphicObj = new Derived();
    std::cout << "Deleting polymorphic pointer:" << std::endl;
    delete polymorphicObj;

    std::cout << "\n--- End of Execution (Local cleanups will occur) ---" << std::endl;
    return 0;
}
