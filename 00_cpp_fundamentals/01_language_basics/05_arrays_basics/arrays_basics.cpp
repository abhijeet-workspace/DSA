// Arrays Basics — C++ basics
// 1D init/traverse plus 2D matrix sizing and nested traversal.
#include <iostream>

int main() {
    std::cout << "--- Single-Dimensional Arrays (1D) ---\n";

    int arr[5] = {10, 20, 30, 40, 50}; // full init
    int partial_arr[5] = {1, 2};       // rest zero-initialized
    int zero_arr[5] = {0};             // all zeros
    (void)partial_arr;                 // silence unused in demo
    (void)zero_arr;

    int n = static_cast<int>(sizeof(arr) / sizeof(arr[0])); // length
    std::cout << "Size of 1D array: " << n << " elements (" << sizeof(arr)
              << " bytes)\n";

    arr[2] = 99; // mutate index 2

    std::cout << "Standard loop traversal: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " "; // index access
    }
    std::cout << "\n";

    std::cout << "Range-based loop traversal: ";
    for (int val : arr) {
        std::cout << val << " "; // range-for over elements
    }
    std::cout << "\n\n";

    std::cout << "--- Multi-Dimensional Arrays (2D) ---\n";
    unsigned int matrix[3][2] = {{1, 2}, {3, 4}, {5, 6}}; // 3x2 matrix

    int total_size_in_bytes = static_cast<int>(sizeof(matrix));
    int single_element_size_in_bytes = static_cast<int>(sizeof(matrix[0][0]));
    int total_element_count = total_size_in_bytes / single_element_size_in_bytes;
    int single_row_size_in_bytes = static_cast<int>(sizeof(matrix[0]));
    int rows = total_size_in_bytes / single_row_size_in_bytes;
    int columns = single_row_size_in_bytes / single_element_size_in_bytes;

    std::cout << matrix[0][1] << std::endl; // row0 col1 -> 2
    std::cout << matrix[1][1] << std::endl; // row1 col1 -> 4

    std::cout << "total_size_in_bytes " << total_size_in_bytes << std::endl;
    std::cout << "single_element_size_in_bytes " << single_element_size_in_bytes
              << std::endl;
    std::cout << "total_element_count " << total_element_count << std::endl;
    std::cout << "single_row_size_in_bytes " << single_row_size_in_bytes << std::endl;
    std::cout << "rows " << rows << std::endl;
    std::cout << "columns " << columns << std::endl;
    std::cout << "2D Array Dimensions: " << rows << "x" << columns << " ("
              << total_size_in_bytes << " bytes)\n";

    matrix[1][1] = 60; // mutate row1 col1

    std::cout << "Matrix layout traversal:\n";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            std::cout << "matrix[" << r << "][" << c << "] = " << matrix[r][c]
                      << "\t";
        }
        std::cout << "\n";
    }

    std::cout << "Tabular format:\n";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            std::cout << matrix[r][c] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
