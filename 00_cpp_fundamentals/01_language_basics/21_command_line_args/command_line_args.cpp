// Command-line Arguments — C++ basics
// Read argc/argv and print each argument; show argv[0] is the program name.
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "argc=" << argc << '\n';
    for (int i = 0; i < argc; ++i) {
        std::cout << "argv[" << i << "]=" << argv[i] << '\n';
    }

    if (argc >= 2) {
        std::cout << "first user arg=" << argv[1] << '\n';
    } else {
        std::cout << "no user args (try: ./a.out hello 42)\n";
    }
    return 0;
}
