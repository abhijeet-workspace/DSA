#include <iostream>
#include <vector>

using ll = long long;
using Mat = std::vector<std::vector<ll>>;

Mat mul(const Mat& A, const Mat& B) {
    Mat C(2, std::vector<ll>(2));
    for (int i = 0; i < 2; ++i)
        for (int k = 0; k < 2; ++k)
            for (int j = 0; j < 2; ++j)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

Mat powM(Mat A, int e) {
    Mat R = {{1, 0}, {0, 1}};
    while (e) {
        if (e & 1)
            R = mul(R, A);
        A = mul(A, A);
        e >>= 1;
    }
    return R;
}

int fib(int n) {
    if (n == 0)
        return 0;
    return (int)powM({{1, 1}, {1, 0}}, n - 1)[0][0];
}

int main() {
    std::cout << "fib(10)=" << fib(10) << " (expected 55)\n";
    return 0;
}
