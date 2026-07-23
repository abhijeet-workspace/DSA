// Move Semantics — C++11 rvalue references
// Deep copy vs steal ownership via move ctor / move assignment.
#include <iostream>
#include <algorithm>
#include <utility>

class ResourceWrapper {
public:
    int* data;
    size_t size;

    ResourceWrapper(size_t sz) : size(sz) {
        data = new int[size]; // own a heap buffer
        std::cout << "Constructor: Allocated resource of size " << size << "\n";
    }

    ResourceWrapper(const ResourceWrapper& other) : size(other.size) {
        data = new int[size];
        std::copy(other.data, other.data + size, data); // deep copy
        std::cout << "Copy Constructor: Deep Copied resource of size " << size << "\n";
    }

    ResourceWrapper(ResourceWrapper&& other) noexcept
        : data(other.data), size(other.size) {
        other.data = nullptr; // leave source empty
        other.size = 0;
        std::cout << "Move Constructor: Stole resource of size " << size << "\n";
    }

    ResourceWrapper& operator=(const ResourceWrapper& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            std::copy(other.data, other.data + size, data);
            std::cout << "Copy Assignment: Deep Copied resource of size " << size << "\n";
        }
        return *this;
    }

    ResourceWrapper& operator=(ResourceWrapper&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data; // steal
            size = other.size;
            other.data = nullptr;
            other.size = 0;
            std::cout << "Move Assignment: Stole resource of size " << size << "\n";
        }
        return *this;
    }

    ~ResourceWrapper() {
        if (data) {
            std::cout << "Destructor: Freeing resource of size " << size << "\n";
            delete[] data;
        } else {
            std::cout << "Destructor: No resource to free (stolen state)\n";
        }
    }
};

int main() {
    std::cout << "=== Move Semantics Demonstration ===\n\n";

    std::cout << "--- 1. Creating Resource 1 ---\n";
    ResourceWrapper res1(100);

    std::cout << "\n--- 2. Creating Resource 2 via Copy ---\n";
    ResourceWrapper res2 = res1; // copy ctor

    std::cout << "\n--- 3. Creating Resource 3 via Move ---\n";
    ResourceWrapper res3 = std::move(res1); // move ctor; res1 emptied

    std::cout << "\n--- 4. Assigning Resource 2 to Resource 3 via Move Assignment ---\n";
    res3 = std::move(res2); // move assign; res2 emptied

    std::cout << "\n--- 5. End of Scope: Destructors will run ---\n";
    return 0;
}
