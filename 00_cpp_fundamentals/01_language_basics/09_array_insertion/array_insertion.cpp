// Array Insertion — C++ basics
// Fill a fixed int array from stdin, then print values and addresses.
#include <iostream>

int main() {
    std::cout << "Insert on Array" << std::endl;

    int arr[10]; // fixed capacity of 10 ints
    int arrLength = static_cast<int>(sizeof(arr) / sizeof(arr[0])); // element count
    std::cout << "arrLength => " << arrLength << std::endl;
    std::cout << "sizeOf int : " << sizeof(arrLength) << std::endl; // bytes of an int

    for (int i = 0; i < arrLength; i++) { // read each slot
        std::cout << "insert element at index " << i << " : ";
        std::cin >> arr[i]; // store user value at index i
        std::cout << std::endl;
    }

    for (int i = 0; i < arrLength; i++) { // dump values and addresses
        std::cout << "value at index " << i << " " << arr[i]
                  << " stored on address " << &arr[i] << std::endl;
    }
    return 0;
}
