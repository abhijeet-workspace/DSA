// Algorithm Design Techniques — six paradigm demos
// Brute force, D&C, greedy, DP, backtracking, branch & bound on classic problems.
#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

int maxSubarrayBrute(const std::vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    int best = INT_MIN;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) { // all subarrays
            sum += arr[j];
            best = std::max(best, sum);
        }
    }
    return best;
}

int maxSubarrayKadane(const std::vector<int>& arr) {
    int best = arr[0];
    int cur = arr[0];
    for (int i = 1; i < static_cast<int>(arr.size()); ++i) {
        cur = std::max(arr[i], cur + arr[i]); // restart or extend
        best = std::max(best, cur);
    }
    return best;
}

long long mergeAndCount(std::vector<int>& arr, int lo, int hi) {
    if (lo >= hi) {
        return 0;
    }
    int mid = lo + (hi - lo) / 2;
    long long count = 0;
    count += mergeAndCount(arr, lo, mid);
    count += mergeAndCount(arr, mid + 1, hi);
    std::vector<int> temp;
    int i = lo;
    int j = mid + 1;
    while (i <= mid && j <= hi) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            count += (mid - i + 1); // split inversions
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }
    while (j <= hi) {
        temp.push_back(arr[j++]);
    }
    for (int k = lo; k <= hi; ++k) {
        arr[k] = temp[k - lo];
    }
    return count;
}

struct Activity {
    int start;
    int end;
};

int activitySelection(std::vector<Activity>& activities) {
    std::sort(activities.begin(), activities.end(),
              [](const Activity& a, const Activity& b) { return a.end < b.end; });
    int count = 1;
    int lastEnd = activities[0].end;
    std::cout << "  Selected: [" << activities[0].start << "," << activities[0].end
              << "] ";
    for (int i = 1; i < static_cast<int>(activities.size()); ++i) {
        if (activities[i].start >= lastEnd) { // no overlap
            std::cout << "[" << activities[i].start << "," << activities[i].end
                      << "] ";
            lastEnd = activities[i].end;
            ++count;
        }
    }
    std::cout << "\n";
    return count;
}

int knapsack(const std::vector<int>& weights, const std::vector<int>& values, int W) {
    int n = static_cast<int>(weights.size());
    std::vector<int> dp(W + 1, 0); // 1D space-optimized
    for (int i = 0; i < n; ++i) {
        for (int w = W; w >= weights[i]; --w) { // reverse prevents reuse
            dp[w] = std::max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }
    return dp[W];
}

int nQueensCount = 0;

bool isSafeQueen(const std::vector<int>& cols, int row, int col) {
    for (int r = 0; r < row; ++r) {
        if (cols[r] == col) {
            return false; // same column
        }
        if (std::abs(cols[r] - col) == row - r) {
            return false; // diagonal
        }
    }
    return true;
}

void solveNQueens(int n, int row, std::vector<int>& cols) {
    if (row == n) {
        ++nQueensCount;
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (isSafeQueen(cols, row, col)) {
            cols[row] = col; // place
            solveNQueens(n, row + 1, cols);
            cols[row] = -1; // undo
        }
    }
}

struct Item {
    int weight;
    int value;
    double ratio;
};

double upperBound(std::vector<Item>& items, int idx, int capacity, double currentValue) {
    double bound = currentValue;
    int w = capacity;
    for (int i = idx; i < static_cast<int>(items.size()) && w > 0; ++i) {
        if (items[i].weight <= w) {
            bound += items[i].value;
            w -= items[i].weight;
        } else {
            bound += items[i].ratio * w; // fractional fill
            w = 0;
        }
    }
    return bound;
}

int bestValue = 0;

void branchAndBound(std::vector<Item>& items, int idx, int capacity, int currentValue) {
    if (idx == static_cast<int>(items.size())) {
        bestValue = std::max(bestValue, currentValue);
        return;
    }
    if (upperBound(items, idx, capacity, currentValue) <= bestValue) {
        return; // prune
    }
    if (items[idx].weight <= capacity) {
        branchAndBound(items, idx + 1, capacity - items[idx].weight,
                       currentValue + items[idx].value); // take
    }
    branchAndBound(items, idx + 1, capacity, currentValue); // skip
}

int main() {
    std::cout << "=== Algorithm Design Techniques Demo ===\n\n";

    std::cout << "1. Brute Force vs Optimal (Max Subarray)\n";
    std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << "  Brute O(N^2): " << maxSubarrayBrute(arr) << "\n";
    std::cout << "  Kadane O(N):  " << maxSubarrayKadane(arr) << "\n";
    std::cout << "  Expected 6\n\n";

    std::cout << "2. Divide & Conquer (Inversion Count)\n";
    std::vector<int> inv = {5, 4, 3, 2, 1};
    std::cout << "  [5,4,3,2,1] inversions: "
              << mergeAndCount(inv, 0, static_cast<int>(inv.size()) - 1)
              << " (expected 10)\n\n";

    std::cout << "3. Greedy (Activity Selection)\n";
    std::vector<Activity> acts = {{1, 3}, {2, 5}, {4, 6}, {6, 7}, {5, 8},
                                  {8, 9}, {8, 11}, {2, 13}, {12, 14}};
    std::cout << "  Max activities: " << activitySelection(acts) << "\n\n";

    std::cout << "4. Dynamic Programming (0/1 Knapsack)\n";
    std::vector<int> weights = {2, 3, 4, 5};
    std::vector<int> values = {3, 4, 5, 6};
    int capacity = 8;
    std::cout << "  Max value: " << knapsack(weights, values, capacity)
              << " (expected 10)\n\n";

    std::cout << "5. Backtracking (N-Queens)\n";
    for (int n = 1; n <= 8; ++n) {
        nQueensCount = 0;
        std::vector<int> cols(n, -1);
        solveNQueens(n, 0, cols);
        std::cout << "  N=" << n << ": " << nQueensCount << " solutions\n";
    }
    std::cout << "\n";

    std::cout << "6. Branch & Bound (Knapsack with pruning)\n";
    std::vector<Item> items = {{2, 3, 1.5}, {3, 4, 1.33}, {4, 5, 1.25}, {5, 6, 1.2}};
    std::sort(items.begin(), items.end(),
              [](const Item& a, const Item& b) { return a.ratio > b.ratio; });
    bestValue = 0;
    branchAndBound(items, 0, capacity, 0);
    std::cout << "  B&B max value: " << bestValue << " (matches DP)\n";
    return 0;
}
