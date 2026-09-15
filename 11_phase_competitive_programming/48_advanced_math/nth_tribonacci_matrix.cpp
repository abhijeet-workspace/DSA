#include <iostream>
#include <vector>
using ll = long long;
using Mat = std::vector<std::vector<ll>>;
Mat mul(const Mat& A, const Mat& B) {
    int n = A.size();
    Mat C(n, std::vector<ll>(n));
    for (int i = 0; i < n; ++i)
        for (int k = 0; k < n; ++k)
            for (int j = 0; j < n; ++j)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}
Mat powM(Mat A, int e) {
    int n = A.size();
    Mat R(n, std::vector<ll>(n));
    for (int i = 0; i < n; ++i)
        R[i][i] = 1;
    while (e) {
        if (e & 1)
            R = mul(R, A);
        A = mul(A, A);
        e >>= 1;
    }
    return R;
}
int tribonacci(int n) {
    if (n == 0)
        return 0;
    if (n <= 2)
        return 1;
    Mat T = powM({{1, 1, 1}, {1, 0, 0}, {0, 1, 0}}, n - 2);
    return (int)(T[0][0] * 1 + T[0][1] * 1);
}
int main() {
    std::cout << "T4=" << tribonacci(4) << " (expected 4)\nT25=" << tribonacci(25)
              << " (expected 1389537)\n";
    return 0;
}
