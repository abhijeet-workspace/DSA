// Corporate Flight Bookings — https://leetcode.com/problems/corporate-flight-bookings/
// Difference array: +seats at first, -seats after last; prefix → answer.
#include <iostream>
#include <vector>

std::vector<int> corpFlightBookings(const std::vector<std::vector<int>>& bookings, int n) {
    std::vector<int> diff(static_cast<size_t>(n + 1), 0);
    for (const auto& b : bookings) {
        const int first = b[0];
        const int last = b[1];
        const int seats = b[2];
        diff[static_cast<size_t>(first - 1)] += seats; // flights are 1-indexed
        if (last < n) {
            diff[static_cast<size_t>(last)] -= seats; // exclusive after last
        }
    }
    std::vector<int> answer(static_cast<size_t>(n));
    int running = 0;
    for (int i = 0; i < n; ++i) {
        running += diff[static_cast<size_t>(i)];
        answer[static_cast<size_t>(i)] = running;
    }
    return answer;
}

int main() {
    const auto a = corpFlightBookings({{1, 2, 10}, {2, 3, 20}, {2, 5, 25}}, 5);
    std::cout << "answer:";
    for (int x : a) {
        std::cout << " " << x;
    }
    std::cout << " (expected 10 55 45 25 25)\n";
    return 0;
}
