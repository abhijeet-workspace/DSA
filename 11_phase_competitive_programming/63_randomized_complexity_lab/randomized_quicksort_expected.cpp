// Randomized quicksort — expected O(N log N)
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

int partition(std::vector<int>& a, int lo, int hi) {
    int pidx = lo + std::rand() % (hi - lo + 1);
    std::swap(a[pidx], a[hi]);
    int pivot = a[hi], i = lo;
    for (int j = lo; j < hi; ++j)
        if (a[j] <= pivot)
            std::swap(a[i++], a[j]);
    std::swap(a[i], a[hi]);
    return i;
}
void qsort(std::vector<int>& a, int lo, int hi) {
    if (lo >= hi)
        return;
    int p = partition(a, lo, hi);
    qsort(a, lo, p - 1);
    qsort(a, p + 1, hi);
}

int main() {
    std::srand(42);
    std::vector<int> a = {3, 1, 4, 1, 5};
    qsort(a, 0, (int)a.size() - 1);
    for (int x : a)
        std::cout << x << " ";
    std::cout << "(expected 1 1 3 4 5)\n";
    return 0;
}
