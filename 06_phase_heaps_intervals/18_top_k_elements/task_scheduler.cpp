// Task Scheduler — https://leetcode.com/problems/task-scheduler/
// Min time to finish tasks with cooldown n between identical tasks.
#include <algorithm>
#include <iostream>
#include <vector>

int leastInterval(const std::vector<char>& tasks, int n) {
    std::vector<int> freq(26, 0);
    int max_freq = 0;
    for (char task : tasks) {
        ++freq[static_cast<size_t>(task - 'A')];
        max_freq = std::max(max_freq, freq[static_cast<size_t>(task - 'A')]);
    }
    int max_freq_count = 0;
    for (int count : freq) {
        if (count == max_freq) {
            ++max_freq_count; // how many tasks share the peak frequency
        }
    }
    const int part_count = max_freq - 1;
    const int part_length = n - (max_freq_count - 1);
    const int empty_slots = part_count * part_length;
    const int available_tasks =
        static_cast<int>(tasks.size()) - max_freq * max_freq_count;
    const int idles = std::max(0, empty_slots - available_tasks);
    return static_cast<int>(tasks.size()) + idles;
}

int main() {
    const std::vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    std::cout << leastInterval(tasks, 2) << " (expected 8)\n";
    return 0;
}
