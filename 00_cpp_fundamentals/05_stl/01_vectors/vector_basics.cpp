// Vector Basics — STL contiguous dynamic array
// Construct, access, grow with reserve/push, erase-remove, and sort+unique.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
static void print_vec(const std::vector<T>& v, const std::string& name) {
    std::cout << name << " (size=" << v.size() << ", cap=" << v.capacity() << "): ";
    for (const T& x : v) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> a; // empty
    std::vector<int> b(5); // five zeros
    std::vector<int> c(5, 42); // five 42s
    std::vector<int> d = {1, 2, 3, 4}; // brace init
    print_vec(a, "a");
    print_vec(b, "b");
    print_vec(c, "c");
    print_vec(d, "d");

    std::cout << "d[2]=" << d[2] << " at(2)=" << d.at(2)
              << " front=" << d.front() << " back=" << d.back() << '\n';

    std::vector<std::string> names;
    names.reserve(2); // avoid early realloc
    names.emplace_back("Alice"); // in-place construct
    names.emplace_back("Bob");
    print_vec(names, "names");

    std::vector<int> v;
    std::size_t last_cap = v.capacity();
    for (int i = 1; i <= 8; ++i) { // watch capacity growth
        v.push_back(i);
        if (v.capacity() != last_cap) {
            std::cout << "capacity " << last_cap << " -> " << v.capacity()
                      << " after push " << i << '\n';
            last_cap = v.capacity();
        }
    }
    print_vec(v, "v");

    std::vector<int> er = {1, 2, 3, 2, 4, 2, 5};
    er.erase(std::remove(er.begin(), er.end(), 2), er.end()); // erase-remove
    print_vec(er, "er");

    std::vector<int> du = {5, 3, 2, 3, 1, 5, 4};
    std::sort(du.begin(), du.end());
    du.erase(std::unique(du.begin(), du.end()), du.end()); // dedupe sorted
    print_vec(du, "du");

    return 0;
}
