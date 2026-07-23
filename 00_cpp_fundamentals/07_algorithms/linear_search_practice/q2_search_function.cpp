// Linear search as a reusable function
// Return index of key or -1.
#include <iostream>

int linearSearch(int arr[], int length, int searchKey) {
    for (int i = 0; i < length; ++i) { // scan
        if (arr[i] == searchKey) {
            return i; // found
        }
    }
    return -1; // not found
}

int main() {
    std::cout << "Code For Linear Search" << std::endl;
    int arr[10] = {1, 3, 2, 45, 6, 4, 8, 5, 0, 9};
    int value = linearSearch(arr, 10, 9); // search for 9
    std::cout << "search key index : " << value << std::endl;
    return 0;
}
