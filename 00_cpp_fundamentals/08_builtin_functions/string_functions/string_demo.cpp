// String Demo — <string>
// Obfuscate email usernames and parse CSV employee records with find/substr/stoi/stod.
#include <iostream>
#include <string>

void parseEmail(const std::string& email) {
    size_t atPos = email.find('@'); // locate domain separator
    if (atPos == std::string::npos) {
        std::cout << "Invalid email address format!\n";
        return;
    }
    std::string username = email.substr(0, atPos);
    std::string domain = email.substr(atPos + 1);

    std::string masked = username;
    if (username.length() > 2) {
        masked = username.front()
                 + std::string(username.length() - 2, '*')
                 + username.back(); // keep first/last, star the middle
    }

    std::cout << "Masked Email: " << masked << "@" << domain << "\n";
    std::cout << "Domain: " << domain << "\n";
}

struct Employee {
    std::string name;
    int age;
    double salary;
};

Employee parseCSVRecord(const std::string& csvLine) {
    size_t firstComma = csvLine.find(',');
    size_t secondComma = csvLine.find(',', firstComma + 1); // second field boundary

    std::string name = csvLine.substr(0, firstComma);
    std::string ageStr = csvLine.substr(firstComma + 1, secondComma - firstComma - 1);
    std::string salStr = csvLine.substr(secondComma + 1);

    Employee emp;
    emp.name = name;
    emp.age = std::stoi(ageStr); // string -> int
    emp.salary = std::stod(salStr); // string -> double
    return emp;
}

int main() {
    std::cout << "=== Built-in Functions: <string> ===\n";

    std::string greet = "Hello ";
    greet.append("C++ World"); // concatenate in place
    std::cout << "Appended: " << greet << " | Length: " << greet.length() << "\n";

    double rate = 0.0575;
    std::cout << "Double to String: " << std::to_string(rate) << "\n";

    std::cout << "\n1. Email Parser/Obfuscator:\n";
    parseEmail("abhijeet.dev@gmail.com");

    std::cout << "\n2. CSV Row Parser:\n";
    Employee emp = parseCSVRecord("Rahul Sharma,21,75000.50");
    std::cout << "   Parsed Employee Profile:\n";
    std::cout << "     Name:   " << emp.name << "\n";
    std::cout << "     Age:    " << emp.age << " years\n";
    std::cout << "     Salary: $" << emp.salary << "\n";

    return 0;
}
