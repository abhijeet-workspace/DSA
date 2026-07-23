// Design Twitter — https://leetcode.com/problems/design-twitter/
// Post, follow/unfollow, and get a user's 10 most recent news-feed tweets.
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

class Twitter {
    int time = 0;
    std::unordered_map<int, std::unordered_set<int>> followees;
    std::unordered_map<int, std::vector<std::pair<int, int>>> tweets; // {time, tweetId}

public:
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId}); // append chronologically
    }

    std::vector<int> getNewsFeed(int userId) {
        // max-heap: {time, tweetId, user, idx in that user's tweet list}
        std::priority_queue<std::tuple<int, int, int, int>> pq;
        auto push_user = [&](int u) {
            if (!tweets[u].empty()) {
                const int i = static_cast<int>(tweets[u].size()) - 1;
                pq.push({tweets[u][static_cast<size_t>(i)].first,
                         tweets[u][static_cast<size_t>(i)].second, u, i});
            }
        };
        push_user(userId); // self
        for (int f : followees[userId]) {
            push_user(f); // followees
        }
        std::vector<int> res;
        while (!pq.empty() && static_cast<int>(res.size()) < 10) {
            const auto [t, id, u, i] = pq.top();
            (void)t;
            pq.pop();
            res.push_back(id);
            if (i > 0) {
                const int ni = i - 1; // next older tweet from same user
                pq.push({tweets[u][static_cast<size_t>(ni)].first,
                         tweets[u][static_cast<size_t>(ni)].second, u, ni});
            }
        }
        return res;
    }

    void follow(int a, int b) {
        if (a != b) {
            followees[a].insert(b);
        }
    }

    void unfollow(int a, int b) { followees[a].erase(b); }
};

int main() {
    Twitter tw;
    tw.postTweet(1, 5);
    tw.follow(1, 2);
    tw.postTweet(2, 6);
    for (int x : tw.getNewsFeed(1)) {
        std::cout << x << " ";
    }
    std::cout << "(expected 6 5)\n";
    return 0;
}
