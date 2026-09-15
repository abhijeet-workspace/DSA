# Implement Magic Dictionary

## 1. Problem Statement
[LeetCode 676](https://leetcode.com/problems/implement-magic-dictionary/) — `search(word)` is true iff some dict word differs in **exactly one** character (same length).

- **Inputs:** dictionary words; query words.
- **Output:** bool per search.
- **Valid answer:** exactly-one edit.
- **Edges:** identical word present (still false); no same-length neighbor.

## 2. Intuition
Trie DFS with a single mismatch budget; after spending it, the rest must match exactly and end on a word.

## 3. Brute Force → Optimal
- **Brute:** compare to every same-length word.
- **Optimal:** trie DFS with one-change flag.

## 4. Data Structure / Approach Justification
**Chosen:** 26-way trie + DFS `(node, i, changed)`.

- **vs generate 1-edit neighbors into a set:** also fine; trie avoids materializing neighbors.

## 5. Logic Walkthrough
Try matching child without spending change; try other children spending once. Success only if `changed` at a word end.

## 6. Dry Run
dict=`["hello","leetcode"]`; `hello`→false; `hhllo`→true; `hell`→false.

## 7. Time & Space Complexity
Build **O(total)**. Search **O(26·L)**. Space **O(total)**. Why: one mismatch expands alphabet once (section 4).

## 8. Trade-offs & Alternatives
Neighbor generation with a hash set is often shorter to code.

## 9. Common Mistakes / Edge Cases
Accepting zero mismatches; allowing length changes; not requiring end after change.

## 10. Interview Follow-ups / Variations
At most k changes; online inserts.

## 11. Tags
`trie`, `dfs`, `design`, `leetcode-676`, `difficulty:medium`
