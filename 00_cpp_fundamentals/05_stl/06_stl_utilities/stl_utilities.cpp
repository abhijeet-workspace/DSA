// STL Utilities — pair, tuple, and common algorithms
// Show pair/tuple access plus sort, find, binary_search, lower_bound.
#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

void demonstratePairAndTuple() {
    std::cout << "--- std::pair and std::tuple ---" << std::endl;

    std::pair<int, std::string> student = {101, "Rahul"};
    std::cout << "Pair -> First (ID): " << student.first
              << ", Second (Name): " << student.second << std::endl;

    std::tuple<int, std::string, double> employee(201, "Amit", 75000.50);
    std::cout << "Tuple -> ID: " << std::get<0>(employee)
              << ", Name: " << std::get<1>(employee)
              << ", Salary: $" << std::get<2>(employee) << std::endl;

    int empId = 0;
    std::string empName;
    double empSalary = 0.0;
    std::tie(empId, empName, empSalary) = employee; // unpack
    std::cout << "Unpacked -> " << empName << " (ID: " << empId << ") earns $"
              << empSalary << std::endl;
}

void demonstrateAlgorithms() {
    std::cout << "\n--- STL Algorithms ---" << std::endl;
    std::vector<int> vec = {40, 10, 50, 20, 30};

    std::sort(vec.begin(), vec.end()); // O(n log n)
    std::cout << "Sorted Vector: ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    int target = 30;
    auto it = std::find(vec.begin(), vec.end(), target); // O(n)
    if (it != vec.end()) {
        std::cout << "Element " << target << " found at index "
                  << std::distance(vec.begin(), it) << " using std::find."
                  << std::endl;
    }

    int searchVal = 50;
    if (std::binary_search(vec.begin(), vec.end(), searchVal)) { // needs sorted
        std::cout << "Element " << searchVal
                  << " exists in the vector (verified by std::binary_search)."
                  << std::endl;
    }

    auto lb = std::lower_bound(vec.begin(), vec.end(), 25); // first >= 25
    std::cout << "Lower bound for 25: " << *lb << " (at index "
              << std::distance(vec.begin(), lb) << ")" << std::endl;
}

int main() {
    std::cout << "=== STL: Utilities and Algorithms ===" << std::endl;
    demonstratePairAndTuple();
    demonstrateAlgorithms();
    return 0;
}
