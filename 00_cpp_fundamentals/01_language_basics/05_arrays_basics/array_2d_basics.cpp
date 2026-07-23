// 2D Array Basics — C++ basics
// Initialize small matrices and derive rows/cols via sizeof.
#include <iostream>

int main() {
    int arr[2][5] = {{0, 1, 2, 3, 4}, {5, 6, 7, 8, 9}}; // 2x5 sample
    std::cout << arr[1][3] << std::endl; // row1 col3 -> 8

    int matrix[2][3] = {{1, 2}, {4, 5}}; // remaining slots zero-filled
    (void)matrix; // kept as init demo

    unsigned int matrix2[3][2] = {{1, 2}, {3, 4}, {5, 6}}; // 3x2 sample

    int total_size_in_bytes = static_cast<int>(sizeof(matrix2));
    int single_element_size_in_bytes = static_cast<int>(sizeof(matrix2[0][0]));
    int total_element_count = total_size_in_bytes / single_element_size_in_bytes;
    int single_row_size_in_bytes = static_cast<int>(sizeof(matrix2[0]));
    int rows = total_size_in_bytes / single_row_size_in_bytes;
    int columns = single_row_size_in_bytes / single_element_size_in_bytes;

    std::cout << matrix2[0][1] << std::endl; // 2
    std::cout << matrix2[1][1] << std::endl; // 4
    std::cout << "total_size_in_bytes " << total_size_in_bytes << std::endl;
    std::cout << "single_element_size_in_bytes " << single_element_size_in_bytes
              << std::endl;
    std::cout << "total_element_count " << total_element_count << std::endl;
    std::cout << "single_row_size_in_bytes " << single_row_size_in_bytes << std::endl;
    std::cout << "rows " << rows << std::endl;
    std::cout << "columns " << columns << std::endl;
    return 0;
}
