# Stream of Characters

## 1. Problem Statement
[LeetCode 1032](https://leetcode.com/problems/stream-of-characters/) — given a dictionary, stream letters one-by-one and report whether any suffix of the stream is a word.

- **Inputs:** dictionary; stream of `query(c)`.
- **Output:** bool per query.
- **Valid answer:** true iff some dictionary word is a suffix of the typed stream.
- **Edges:** single-letter words; long stream; overlapping matches.

## 2. Intuition
Insert **reversed** words into a trie; walk backward from the newest character, capped by max word length.

## 3. Brute Force → Optimal
- **Brute:** test all suffixes against a set after each char.
- **Optimal:** reverse trie + O(maxLen) walk per query.

## 4. Data Structure / Approach Justification
**Chosen:** reverse-word trie + deque of recent chars.

- **vs Aho-Corasick:** stronger multi-match; reverse trie is enough here.

## 5. Logic Walkthrough
On `query(c)`, push front; walk trie up to maxLen; return true on any `isEnd`.

## 6. Dry Run
dict=`["cd","f","kl"]`; stream `a,b,c,d` → false,false,false,**true**.

## 7. Time & Space Complexity
Build **O(total)**. Query **O(maxLen)**. Space **O(total)**. Why: reverse walk bounded by longest word (section 4).

## 8. Trade-offs & Alternatives
Aho-Corasick avoids reversing; reverse trie is simpler under interview time.

## 9. Common Mistakes / Edge Cases
Forgetting to reverse dictionary words; walking the entire stream; missing end flags.

## 10. Interview Follow-ups / Variations
Return the matched word; online dictionary updates.

## 11. Tags
`trie`, `stream`, `string`, `leetcode-1032`, `difficulty:hard`
