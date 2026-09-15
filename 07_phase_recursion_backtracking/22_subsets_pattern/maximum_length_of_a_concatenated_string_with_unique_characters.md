# Maximum Length of a Concatenated String with Unique Characters

## 1. Problem Statement
[LeetCode 1239](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/) — concatenate a subset of `arr` so all characters stay unique; maximize total length.

- **Inputs:** `vector<string> arr`.
- **Output:** max length (0 if none).
- **Valid answer:** any valid subset concatenation length.
- **Edges:** empty words; internal duplicates; overlapping letters.

## 2. Intuition
Subsets of words with bitmasks: include a word only if its mask is disjoint from the used mask.

## 3. Brute Force → Optimal
- **Brute:** all subsets, check uniqueness — 2^n.
- **Optimal:** same with bitmask prune; n≤16 typically.

## 4. Data Structure / Approach Justification
**Chosen:** cascade DFS over word indices with OR-masks.

- **vs DP on bitsets:** similar; DFS is clear for subsets teaching.

## 5. Logic Walkthrough
Precompute mask per word (−1 if internal dup). DFS from `i`: try include word `j≥i` if disjoint; track best length.

## 6. Dry Run
`["un","iq","ue"]` → `"uniq"` length **4**.

## 7. Time & Space Complexity
Time **O(2^n)**. Space **O(n)**. Why: subset of words (section 4).

## 8. Trade-offs & Alternatives
Iterative bit DP over subsets of indices when n is tiny.

## 9. Common Mistakes / Edge Cases
Allowing internal duplicate words; not skipping conflicting masks; empty string edge.

## 10. Interview Follow-ups / Variations
Return the actual string; limit alphabet; count ways.

## 11. Tags
`backtracking`, `bitmask`, `subsets`, `leetcode-1239`, `difficulty:medium`
