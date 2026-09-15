// Replace Words — LC 648 (trie; AC unnecessary for prefixes)
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Trie {
    Trie* next[26]{};
    bool end = false;
};

void insert(Trie* root, const std::string& w) {
    Trie* cur = root;
    for (char ch : w) {
        int c = ch - 'a';
        if (!cur->next[c])
            cur->next[c] = new Trie();
        cur = cur->next[c];
    }
    cur->end = true;
}

std::string rootOf(Trie* root, const std::string& w) {
    Trie* cur = root;
    std::string pref;
    for (char ch : w) {
        int c = ch - 'a';
        if (!cur->next[c])
            return w;
        cur = cur->next[c];
        pref.push_back(ch);
        if (cur->end)
            return pref;
    }
    return w;
}

std::string replaceWords(const std::vector<std::string>& dictionary, const std::string& sentence) {
    Trie* root = new Trie();
    for (auto& d : dictionary)
        insert(root, d);
    std::stringstream ss(sentence);
    std::string word, out;
    bool first = true;
    while (ss >> word) {
        if (!first)
            out.push_back(' ');
        first = false;
        out += rootOf(root, word);
    }
    return out;
}

int main() {
    auto ans = replaceWords({"cat", "bat", "rat"}, "the cattle was rattled by the battery");
    std::cout << ans << "\n(expected: the cat was rat by the bat)\n";
    return 0;
}
