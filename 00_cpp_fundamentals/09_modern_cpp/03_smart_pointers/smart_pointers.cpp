// Smart Pointers — unique_ptr, shared_ptr, weak_ptr
// Exclusive vs shared ownership; break cycles with weak_ptr.
#include <iostream>
#include <string>
#include <utility>
#include <memory>

class Node {
public:
    std::string name;
    std::shared_ptr<Node> nextNode; // owning link (can form cycles)
    std::weak_ptr<Node> weakNextNode; // non-owning observer

    Node(std::string val) : name(std::move(val)) {
        std::cout << "Node \"" << name << "\" constructed.\n";
    }
    ~Node() {
        std::cout << "Node \"" << name << "\" destructed.\n";
    }
};

void demoUniquePtr() {
    std::cout << "\n--- unique_ptr Demonstration ---\n";
    {
        std::unique_ptr<Node> node1 = std::make_unique<Node>("UniqueNode1");
        std::unique_ptr<Node> node2 = std::move(node1); // transfer ownership
        if (!node1) {
            std::cout << "node1 is now null after moving.\n";
        }
        if (node2) {
            std::cout << "node2 now owns: " << node2->name << "\n";
        }
    } // UniqueNode1 destroyed here
    std::cout << "Scope of demoUniquePtr ended.\n";
}

void demoSharedPtr() {
    std::cout << "\n--- shared_ptr Demonstration ---\n";
    std::shared_ptr<Node> sharedRef1;
    {
        std::shared_ptr<Node> node1 = std::make_shared<Node>("SharedNode1");
        std::cout << "Reference Count: " << node1.use_count() << "\n";
        sharedRef1 = node1; // bump ref count
        std::cout << "Reference Count after copying to sharedRef1: "
                  << node1.use_count() << "\n";
    } // node1 drops; object lives via sharedRef1
    std::cout << "Reference Count outside scope: " << sharedRef1.use_count() << "\n";
} // SharedNode1 destroyed here

void demoWeakPtrCycle() {
    std::cout << "\n--- cyclic shared_ptr dependency (No weak_ptr -> Memory Leak) ---\n";
    {
        auto A = std::make_shared<Node>("NodeA");
        auto B = std::make_shared<Node>("NodeB");
        A->nextNode = B;
        B->nextNode = A; // cycle: ref counts never reach 0
    }
    std::cout << "Scope of cycle demo ended (Notice no destructors were run!).\n";
}

void demoWeakPtrResolution() {
    std::cout << "\n--- Resolving cyclic dependency using weak_ptr ---\n";
    {
        auto A = std::make_shared<Node>("NodeA_Safe");
        auto B = std::make_shared<Node>("NodeB_Safe");
        A->weakNextNode = B; // weak does not bump count
        B->weakNextNode = A;
    } // both destroyed
    std::cout << "Scope of safe weak_ptr demo ended.\n";
}

int main() {
    std::cout << "=== Smart Pointers Demonstration ===\n";
    demoUniquePtr();
    demoSharedPtr();
    demoWeakPtrCycle();
    demoWeakPtrResolution();
    return 0;
}
