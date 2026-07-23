// Structure Basics — C++ fundamentals
// Define a Student struct, initialize two ways, print members, call a member function.
#include <iostream>
#include <string>

struct Student {
    int id; // student id
    std::string name; // student name
    float marks; // marks scored

    int sumOfTwo(int s1, int s2) { // member helper
        return s1 + s2;
    }
};

int main() {
    Student s1; // default-init then assign
    s1.id = 101;
    s1.name = "Rahul";
    s1.marks = 87.5f;

    Student s2 = {102, "Amit", 92.0f}; // aggregate init

    std::cout << "Student 1 -> ID: " << s1.id << ", Name: " << s1.name
              << ", Marks: " << s1.marks << std::endl;
    std::cout << "Student 2 -> ID: " << s2.id << ", Name: " << s2.name
              << ", Marks: " << s2.marks << std::endl;
    std::cout << "Sum from structure member function: " << s1.sumOfTwo(20, 22)
              << std::endl;
    return 0;
}
