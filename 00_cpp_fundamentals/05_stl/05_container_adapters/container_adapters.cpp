// Container Adapters — stack, queue, priority_queue
// LIFO stack, FIFO queue, and max/min heap adapters over underlying containers.
#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

void demonstrateStack() {
    std::cout << "--- std::stack (LIFO - Last In First Out) ---" << std::endl;
    std::stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Stack Top: " << s.top() << std::endl;
    s.pop();
    std::cout << "Stack Top after Pop: " << s.top() << std::endl;
    std::cout << "Stack Size: " << s.size() << std::endl;
}

void demonstrateQueue() {
    std::cout << "\n--- std::queue (FIFO - First In First Out) ---" << std::endl;
    std::queue<std::string> q;
    q.push("Customer A");
    q.push("Customer B");
    q.push("Customer C");

    std::cout << "Queue Front: " << q.front() << " | Queue Back: " << q.back()
              << std::endl;
    q.pop();
    std::cout << "Queue Front after Pop: " << q.front() << std::endl;
}

void demonstratePriorityQueue() {
    std::cout << "\n--- std::priority_queue (Heap Interface) ---" << std::endl;

    std::priority_queue<int> maxHeap; // largest on top
    maxHeap.push(15);
    maxHeap.push(5);
    maxHeap.push(30);
    maxHeap.push(20);
    std::cout << "Max-Heap Top (should be 30): " << maxHeap.top() << std::endl;
    maxHeap.pop();
    std::cout << "Max-Heap Top after Pop (should be 20): " << maxHeap.top()
              << std::endl;

    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    minHeap.push(15);
    minHeap.push(5);
    minHeap.push(30);
    minHeap.push(20);
    std::cout << "Min-Heap Top (should be 5): " << minHeap.top() << std::endl;
    minHeap.pop();
    std::cout << "Min-Heap Top after Pop (should be 15): " << minHeap.top()
              << std::endl;
}

int main() {
    std::cout << "=== STL: Container Adapters ===" << std::endl;
    demonstrateStack();
    demonstrateQueue();
    demonstratePriorityQueue();
    return 0;
}
