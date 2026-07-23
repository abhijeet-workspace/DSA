// Complete Headers Demo — local teaching demo
// Build: g++ -std=c++17 complete_headers_demo.cpp widget.cpp pimpl_widget.cpp -o complete_headers_demo
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <string_view>

#include <vector>
#include <deque>
#include <list>
#include <map>
#include <algorithm>
#include <numeric>

#include <optional>
#include <variant>
#include <any>

#include <memory>

#include <thread>
#include <chrono>

#include <filesystem>
#include <regex>
#include <random>
#include <cmath>

#include <cstring>
#include <cctype>

#include "config.h"
#include "basics.h"
#include "utils.h"
#include "math_ops.hpp"
#include "widget.h"
#include "pimpl_widget.h"

static void io_demo() {
    std::cout << "-- iostream / iomanip / sstream / fstream demo --\n";
    std::cout << std::setw(10) << std::left << "Name" << "|" << std::setw(5) << std::right << "Age" << '\n';
    std::stringstream ss;
    ss << "Alice 30\nBob 25\n";
    std::string name;
    int age = 0;
    while (ss >> name >> age) { // parse tokens
        std::cout << std::setw(10) << std::left << name << "|" << std::setw(5) << std::right << age << '\n';
    }
    {
        std::ofstream out("tmp_demo.txt");
        out << "demo\n"; // create temp file
    }
    std::ifstream in("tmp_demo.txt");
    std::string line;
    std::getline(in, line);
    std::cout << "read from tmp_demo.txt: " << line << '\n';
}

static void string_demo() {
    std::cout << "-- string / string_view demo --\n";
    std::string s = "hello";
    std::string_view sv = s; // non-owning view
    std::cout << "s.size=" << s.size() << ", sv[1]=" << sv[1] << '\n';
}

static void containers_demo() {
    std::cout << "-- containers demo --\n";
    std::vector<int> v = {1, 2, 3};
    std::deque<int> dq = {7, 8};
    std::list<int> lst = {9, 10};
    std::cout << "vector sum=" << std::accumulate(v.begin(), v.end(), 0)
              << " deque front=" << dq.front()
              << " list back=" << lst.back() << '\n';
    std::map<std::string, int> mp{{"x", 1}, {"y", 2}};
    std::cout << "map x=" << mp["x"] << '\n';
}

static void algorithm_demo() {
    std::cout << "-- algorithm demo (sort, unique) --\n";
    std::vector<int> w = {3, 1, 2, 3, 2};
    std::sort(w.begin(), w.end());
    w.erase(std::unique(w.begin(), w.end()), w.end()); // compact uniques
    std::cout << "unique sorted: ";
    for (int x : w) std::cout << x << ' ';
    std::cout << '\n';
}

static void smartptr_demo() {
    std::cout << "-- smart pointers demo --\n";
    std::unique_ptr<int> up = std::make_unique<int>(42);
    std::shared_ptr<int> sp = std::make_shared<int>(100);
    std::cout << "unique=" << *up << " shared=" << *sp << '\n';
}

static void regex_demo() {
    std::cout << "-- regex demo --\n";
    std::regex r(R"((\w+)@(\w+)\.(\w+))");
    std::string s = "user@example.com";
    std::smatch m;
    if (std::regex_search(s, m, r)) {
        std::cout << "email user=" << m[1] << " domain=" << m[2] << '\n';
    }
}

static void fs_demo() {
    std::cout << "-- filesystem demo --\n";
    namespace fs = std::filesystem;
    std::cout << "current path: " << fs::current_path() << '\n';
}

static void thread_demo() {
    std::cout << "-- thread demo --\n";
    std::thread t([] { std::cout << "hello from thread\n"; });
    t.join(); // wait for worker
}

static void random_demo() {
    std::cout << "-- random demo --\n";
    std::mt19937 rng(static_cast<unsigned>(
        std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> d(1, 6);
    std::cout << "roll=" << d(rng) << '\n';
}

static void math_demo() {
    std::cout << "-- math demo --\n";
    std::cout << "sqrt(2)=" << std::sqrt(2.0) << " pow(2,3)=" << std::pow(2.0, 3.0) << '\n';
}

static void types_demo() {
    std::cout << "-- optional/variant/any demo --\n";
    std::optional<int> oi = 5;
    std::cout << "optional has value=" << *oi << '\n';
    std::variant<int, std::string> vv = "hello";
    std::cout << "variant holds string? " << std::holds_alternative<std::string>(vv) << '\n';
    std::any a = 3.14;
    std::cout << "any contains type name=" << a.type().name() << '\n';
}

static void c_headers_demo() {
    std::cout << "-- C headers demo (cstring, cctype) --\n";
    const char* cs = "hello";
    std::cout << "strlen(cs)=" << std::strlen(cs) << '\n';
    char up = static_cast<char>(std::toupper(static_cast<unsigned char>(cs[0])));
    std::cout << "toupper(cs[0])=" << up << '\n';
}

static void manual_headers_demo() {
    std::cout << "-- manual project headers demo --\n";
    std::cout << greet("Demo") << '\n';
    std::cout << shout(std::string("hello from utils")) << '\n';
    std::cout << "add(2,3)=" << add<int>(2, 3) << " math_library=" << math_library << '\n';
    Widget w("DemoWidget");
    std::cout << "Widget: " << w.name() << '\n';
    PimplWidget pw("PimplDemo");
    std::cout << "Pimpl: " << pw.name() << '\n';
}

int main() {
    std::cout << "=== Complete headers demo (C++ standard + project headers) ===\n";
    io_demo();
    string_demo();
    containers_demo();
    algorithm_demo();
    smartptr_demo();
    regex_demo();
    fs_demo();
    thread_demo();
    random_demo();
    math_demo();
    types_demo();
    c_headers_demo();
    manual_headers_demo();
    std::cout << "=== demo complete ===\n";
    return 0;
}
