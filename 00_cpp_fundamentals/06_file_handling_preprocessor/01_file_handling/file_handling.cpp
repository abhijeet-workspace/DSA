// File Handling — local teaching demo
// Read and write a text file with ofstream / ifstream.
#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ofstream out("data.txt"); // open for write
    out << "Hello File" << std::endl; // write one line
    out.close(); // flush and release

    std::ifstream in("data.txt"); // open for read
    std::string line;
    std::getline(in, line); // read first line
    std::cout << "Read: " << line << '\n';
    in.close();

    return 0;
}
