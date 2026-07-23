// Modern C++ Features — C++11/14/17 for DSA
// Structured bindings, lambdas, move, smart pointers, optional, string_view, if constexpr.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <string_view>
#include <optional>
#include <memory>
#include <algorithm>
#include <queue>
#include <tuple>
#include <type_traits>
#include <utility>

void demoStructuredBindings() {
    std::cout << "\n--- 1. Auto & Structured Bindings (C++17) ---\n";

    std::pair<int, std::string> p = {101, "Alice"};
    auto [id, name] = p; // unpack pair into named locals
    std::cout << "Pair unpacked -> ID: " << id << ", Name: " << name << "\n";

    std::tuple<int, double, char> t = {42, 3.14, 'Z'};
    auto [iVal, dVal, cVal] = t; // unpack tuple
    std::cout << "Tuple unpacked -> Int: " << iVal << ", Double: " << dVal
              << ", Char: " << cVal << "\n";

    std::unordered_map<std::string, std::vector<int>> studentGrades = {
        {"Bob", {85, 90}},
        {"Charlie", {78, 88, 92}}
    };

    for (const auto& [student, grades] : studentGrades) { // avoid copying key/value
        std::cout << "  Student: " << student << " | Grades: ";
        for (int grade : grades) std::cout << grade << " ";
        std::cout << "\n";
    }
}

struct Interval {
    int start;
    int end;
};

void demoLambdas() {
    std::cout << "\n--- 2. Lambdas as Custom Comparators ---\n";

    std::vector<Interval> intervals = {{5, 8}, {1, 4}, {3, 6}};
    std::sort(intervals.begin(), intervals.end(),
              [](const Interval& a, const Interval& b) {
                  return a.start < b.start; // sort by start ascending
              });

    std::cout << "Sorted Intervals (by start time):\n";
    for (const auto& interval : intervals) {
        std::cout << "  [" << interval.start << ", " << interval.end << "]";
    }
    std::cout << "\n";

    auto minHeapCmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first > b.first; // greater-first => min-heap on distance
    };

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        decltype(minHeapCmp)>
        pq(minHeapCmp);

    pq.push({10, 2});
    pq.push({3, 1});
    pq.push({7, 3});

    std::cout << "Priority Queue (Min-Heap) extraction:\n";
    while (!pq.empty()) {
        auto [dist, node] = pq.top();
        pq.pop();
        std::cout << "  Node: " << node << " with Distance: " << dist << "\n";
    }
}

class LargeBuffer {
public:
    std::string name;
    std::vector<int> data;

    LargeBuffer(std::string n, int size) : name(std::move(n)), data(size, 99) {
        std::cout << "  [Constructor] Created buffer '" << name << "' of size " << size << "\n";
    }

    LargeBuffer(const LargeBuffer& other)
        : name(other.name + " (Copy)"), data(other.data) {
        std::cout << "  [Copy Constructor] Deep-copied data for '" << name << "'\n";
    }

    LargeBuffer(LargeBuffer&& other) noexcept
        : name(std::move(other.name) + " (Moved)"), data(std::move(other.data)) {
        std::cout << "  [Move Constructor] Transferred resources from original buffer\n";
    }
};

void demoMoveSemantics() {
    std::cout << "\n--- 3. Move Semantics & std::move ---\n";

    LargeBuffer original("BufA", 10000);
    LargeBuffer copied = original; // deep copy of 10k ints
    LargeBuffer moved = std::move(original); // O(1) steal; original left empty

    std::cout << "  Copied data size: " << copied.data.size() << "\n";
    std::cout << "  Moved data size: " << moved.data.size() << "\n";
    std::cout << "  Original (after move) data size: " << original.data.size()
              << " (safe empty state)\n";
}

struct TreeNode {
    int val;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

void printTreeInOrder(const TreeNode* node) {
    if (!node) return;
    printTreeInOrder(node->left.get()); // raw view for recursion
    std::cout << node->val << " ";
    printTreeInOrder(node->right.get());
}

void demoSmartPointers() {
    std::cout << "\n--- 4. Smart Pointers (unique_ptr) ---\n";

    auto root = std::make_unique<TreeNode>(10); // exclusive ownership
    root->left = std::make_unique<TreeNode>(5);
    root->right = std::make_unique<TreeNode>(15);

    std::cout << "In-order tree traversal: ";
    printTreeInOrder(root.get());
    std::cout << "\n  (Memory is automatically cleaned up when root goes out of scope!)\n";
}

std::optional<int> findFirstEven(const std::vector<int>& nums) {
    for (int num : nums) {
        if (num % 2 == 0) return num; // wrap found value
    }
    return std::nullopt; // explicit empty
}

void demoOptional() {
    std::cout << "\n--- 5. std::optional (C++17) ---\n";

    std::vector<int> v1 = {1, 3, 5, 8, 9};
    std::vector<int> v2 = {1, 3, 5, 7};

    auto result1 = findFirstEven(v1);
    if (result1.has_value()) {
        std::cout << "v1 even found: " << result1.value() << " (or " << *result1 << ")\n";
    } else {
        std::cout << "v1: No even numbers found.\n";
    }

    auto result2 = findFirstEven(v2);
    std::cout << "v2 even found (with fallback): " << result2.value_or(-1) << "\n";
}

void printPrefix(std::string_view sv, size_t length) {
    if (length > sv.length()) length = sv.length();
    std::string_view prefix = sv.substr(0, length); // O(1) non-owning slice
    std::cout << "  Prefix: " << prefix << " (size: " << prefix.size() << ")\n";
}

void demoStringView() {
    std::cout << "\n--- 6. std::string_view (C++17) ---\n";
    std::string largeString = "leetcode_is_awesome";
    printPrefix(largeString, 8);
    printPrefix("direct_literal", 6);
}

template <typename T>
void printValueInfo(T val) {
    if constexpr (std::is_integral_v<T>) { // compile-time branch
        std::cout << "  Integral value: " << val << " | Even? "
                  << (val % 2 == 0 ? "Yes" : "No") << "\n";
    } else {
        std::cout << "  Non-integral value: " << val << "\n";
    }
}

void demoIfConstexpr() {
    std::cout << "\n--- 7. if constexpr (C++17) ---\n";
    printValueInfo(42);
    printValueInfo(3.14159);
}

int main() {
    std::cout << "==========================================\n";
    std::cout << "      MODERN C++ (C++17) FOR DSA DEMO     \n";
    std::cout << "==========================================\n";

    demoStructuredBindings();
    demoLambdas();
    demoMoveSemantics();
    demoSmartPointers();
    demoOptional();
    demoStringView();
    demoIfConstexpr();

    std::cout << "\n==========================================\n";
    return 0;
}
