// Beam Search — keep only the best K partial candidates each step
// Demo: find a path string of length L over alphabet that maximizes score.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Candidate {
    std::string path;
    int score;
};

// Toy score: prefer 'a' early, 'b' late (illustrative heuristic).
int stepScore(char ch, int pos, int len) {
    if (ch == 'a') return len - pos;
    if (ch == 'b') return pos + 1;
    return 1;
}

std::string beamSearch(int length, int beamWidth) {
    const std::string alphabet = "abc";
    std::vector<Candidate> beam = {{"", 0}};

    for (int pos = 0; pos < length; ++pos) {
        std::vector<Candidate> next;
        for (const auto& c : beam) {
            for (char ch : alphabet) {
                next.push_back({c.path + ch, c.score + stepScore(ch, pos, length)});
            }
        }
        std::sort(next.begin(), next.end(),
                  [](const Candidate& x, const Candidate& y) { return x.score > y.score; });
        if (static_cast<int>(next.size()) > beamWidth) {
            next.resize(static_cast<size_t>(beamWidth));
        }
        beam.swap(next);
    }
    return beam.empty() ? "" : beam.front().path;
}

int main() {
    int L = 5, K = 3;
    std::string best = beamSearch(L, K);
    std::cout << "Beam (K=" << K << ") best path: " << best << "\n";
    return 0;
}
