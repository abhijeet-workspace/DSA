// Reservoir sampling — k samples from stream (LC 382 related)
#include <cstdlib>
#include <iostream>
#include <vector>

std::vector<int> reservoir(const std::vector<int>& stream, int k) {
    std::vector<int> R;
    for (int i = 0; i < (int)stream.size(); ++i) {
        if (i < k)
            R.push_back(stream[i]);
        else {
            int j = std::rand() % (i + 1);
            if (j < k)
                R[j] = stream[i];
        }
    }
    return R;
}

int main() {
    std::srand(5);
    auto R = reservoir({1, 2, 3, 4, 5}, 2);
    std::cout << "sample:";
    for (int x : R)
        std::cout << " " << x;
    std::cout << "\n";
    return 0;
}
