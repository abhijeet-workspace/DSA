// Maximum Frequency Stack — LC 895
#include <iostream>
#include <unordered_map>
#include <vector>

class FreqStack {
    std::unordered_map<int, int> freq;
    std::unordered_map<int, std::vector<int>> group; // frequency -> stack of vals
    int maxFreq = 0;

  public:
    void push(int val) {
        int f = ++freq[val];
        maxFreq = std::max(maxFreq, f);
        group[f].push_back(val);
    }
    int pop() {
        int val = group[maxFreq].back();
        group[maxFreq].pop_back();
        --freq[val];
        if (group[maxFreq].empty())
            --maxFreq;
        return val;
    }
};

int main() {
    FreqStack st;
    st.push(5);
    st.push(7);
    st.push(5);
    st.push(7);
    st.push(4);
    st.push(5);
    std::cout << st.pop() << " (expected 5)\n";
    std::cout << st.pop() << " (expected 7)\n";
    std::cout << st.pop() << " (expected 5)\n";
    std::cout << st.pop() << " (expected 4)\n";
    return 0;
}
