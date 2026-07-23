// Map Basics — ordered map vs unordered_map
// Key-value inserts, sorted vs hash iteration, and lookups.
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

void demonstrateMap() {
    std::cout << "--- std::map (Sorted Keys, Key-Value Pairs) ---" << std::endl;
    std::map<std::string, int> ageMap;

    ageMap["Rahul"] = 21; // insert/assign
    ageMap["Amit"] = 25;
    ageMap["Zack"] = 19;
    ageMap.insert({"Bob", 30});

    std::cout << "Map Contents (Sorted by Key):" << std::endl;
    for (const auto& [name, age] : ageMap) { // structured binding
        std::cout << "  " << name << " -> " << age << std::endl;
    }

    std::string searchKey = "Rahul";
    if (ageMap.find(searchKey) != ageMap.end()) {
        std::cout << "Found " << searchKey << " with age " << ageMap[searchKey]
                  << std::endl;
    } else {
        std::cout << searchKey << " not found." << std::endl;
    }
}

void demonstrateUnorderedMap() {
    std::cout << "\n--- std::unordered_map (Hash Table, Key-Value Pairs) ---"
              << std::endl;
    std::unordered_map<std::string, double> priceMap;

    priceMap["Apple"] = 1.99;
    priceMap["Banana"] = 0.59;
    priceMap["Orange"] = 1.25;

    std::cout << "Unordered Map Contents (Arbitrary Order):" << std::endl;
    for (const auto& [item, price] : priceMap) {
        std::cout << "  " << item << " -> $" << price << std::endl;
    }

    std::string item = "Banana";
    if (priceMap.count(item)) {
        std::cout << item << " price is $" << priceMap[item] << std::endl;
    }
}

int main() {
    std::cout << "=== STL: Maps ===" << std::endl;
    demonstrateMap();
    demonstrateUnorderedMap();
    return 0;
}
