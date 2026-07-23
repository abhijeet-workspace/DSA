// Amortized Analysis — dynamic array resize costs
// Track aggregate, accounting ($3/push), and potential Phi=2*size-capacity.
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

class SimulatedDynamicArray {
private:
    int* data;
    int capacity;
    int size;
    long long total_actual_cost;
    long long total_tokens_bank;

public:
    struct PushMetrics {
        int actual_cost;
        int amortized_cost_accounting;
        int potential;
    };

    SimulatedDynamicArray()
        : data(new int[1]), capacity(1), size(0), total_actual_cost(0),
          total_tokens_bank(0) {}

    ~SimulatedDynamicArray() { delete[] data; }

    PushMetrics push(int value) {
        int actual_cost = 1; // insert
        if (size == capacity) {
            capacity *= 2;
            int* new_data = new int[capacity];
            for (int i = 0; i < size; ++i) {
                new_data[i] = data[i]; // copy on resize
            }
            delete[] data;
            data = new_data;
            actual_cost += size; // pay for copies
        }
        data[size++] = value;
        total_actual_cost += actual_cost;

        int charged_amortized = 3; // accounting charge
        total_tokens_bank += (charged_amortized - actual_cost);

        int potential_after = 2 * size - capacity; // Phi
        return {actual_cost, charged_amortized, potential_after};
    }

    int getSize() const { return size; }
    int getCapacity() const { return capacity; }
    long long getTotalActualCost() const { return total_actual_cost; }
    long long getTokens() const { return total_tokens_bank; }
};

int main() {
    std::cout << "=== Amortized Analysis (Dynamic Array) ===\n\n";

    SimulatedDynamicArray arr;
    const int num_elements = 16;

    std::cout << std::setw(5) << "Push" << std::setw(10) << "Size"
              << std::setw(12) << "Capacity" << std::setw(15) << "Actual Cost"
              << std::setw(20) << "Bank (Tokens)" << std::setw(15)
              << "Potential" << "\n";
    std::cout << std::string(77, '-') << "\n";

    for (int i = 1; i <= num_elements; ++i) {
        auto metrics = arr.push(std::rand() % 100);
        std::cout << std::setw(5) << i << std::setw(10) << arr.getSize()
                  << std::setw(12) << arr.getCapacity() << std::setw(15)
                  << metrics.actual_cost << std::setw(20) << arr.getTokens()
                  << std::setw(15) << metrics.potential << "\n";
    }

    std::cout << std::string(77, '-') << "\n";
    std::cout << "Total actual cost for " << num_elements
              << " pushes: " << arr.getTotalActualCost() << "\n";
    std::cout << "Amortized (aggregate): "
              << static_cast<double>(arr.getTotalActualCost()) / num_elements
              << "\n";
    std::cout << "Remaining tokens (accounting): " << arr.getTokens()
              << " (should be >= 0)\n";
    return 0;
}
