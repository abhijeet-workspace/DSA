// Sequentially Ordinal Rank Tracker —
// https://leetcode.com/problems/sequentially-ordinal-rank-tracker/ Dual ordered sets: best
// `queryCount` vs rest; get() returns the i-th best (i grows).
#include <iostream>
#include <set>
#include <string>

struct Loc {
    int score;
    std::string name;
    bool operator<(const Loc& o) const {
        if (score != o.score) {
            return score > o.score; // higher score is better (comes first)
        }
        return name < o.name;
    }
};

class SORTracker {
    std::multiset<Loc> good; // best queryCount locations
    std::multiset<Loc> rest;
    int queryCount = 0;

  public:
    void add(std::string name, int score) {
        good.insert({score, std::move(name)});
        if (static_cast<int>(good.size()) > queryCount) {
            auto worst = std::prev(good.end());
            rest.insert(*worst);
            good.erase(worst);
        }
    }

    std::string get() {
        ++queryCount;
        if (!rest.empty()) {
            auto bestRest = rest.begin();
            good.insert(*bestRest);
            rest.erase(bestRest);
        }
        return std::prev(good.end())->name; // i-th best = worst among good
    }
};

int main() {
    SORTracker t;
    t.add("bradford", 2);
    t.add("branford", 3);
    std::cout << t.get() << " (expected branford)\n";
    t.add("alps", 2);
    std::cout << t.get() << " (expected alps)\n";
    t.add("orland", 2);
    std::cout << t.get() << " (expected bradford)\n";
    return 0;
}
