// Video Stitching — https://leetcode.com/problems/video-stitching/
// Sort clips by start; greedy jump-game style extend farthest end.
#include <algorithm>
#include <iostream>
#include <vector>

int videoStitching(std::vector<std::vector<int>>& clips, int time) {
    std::sort(clips.begin(), clips.end());
    int ans = 0, end = 0, farthest = 0, i = 0, n = static_cast<int>(clips.size());
    while (end < time) {
        while (i < n && clips[static_cast<size_t>(i)][0] <= end) {
            farthest = std::max(farthest, clips[static_cast<size_t>(i)][1]);
            ++i;
        }
        if (farthest == end) return -1; // cannot extend
        end = farthest;
        ++ans;
    }
    return ans;
}

int main() {
    std::vector<std::vector<int>> clips = {{0, 2}, {4, 6}, {8, 10}, {1, 9}, {1, 5}, {5, 9}};
    std::cout << videoStitching(clips, 10) << " (expected 3)\n";
    return 0;
}
