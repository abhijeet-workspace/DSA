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

Mat powM(Mat A, ll e) {
    Mat R = {{1, 0}, {0, 1}};
    while (e) {
        if (e & 1)
            R = mul(R, A);
        A = mul(A, A);
        e >>= 1;
    }
    return R;
}

int climbStairs(int n) {
    if (n <= 2)
        return n;
    Mat T = powM({{1, 1}, {1, 0}}, n - 2);
    return (int)(T[0][0] * 2 + T[0][1]);
}

int main() {
    std::cout << "climb(3)=" << climbStairs(3) << " (expected 3)\nclimb(5)=" << climbStairs(5)
              << " (expected 8)\n";
    return 0;
}
