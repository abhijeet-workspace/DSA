# Sum Root to Leaf Numbers

## 1. Problem Statement
[LeetCode 129](https://leetcode.com/problems/sum-root-to-leaf-numbers/) — each root-to-leaf path is a decimal integer; return the sum of those integers.

- **Inputs:** `TreeNode* root` (digits 0–9).
- **Output:** `int`.
- **Valid answer:** sum over all root-to-leaf numeric paths.
- **Edges:** single node; leading zeros on non-root digits still valid as digits.

## 2. Intuition
Carry a running value `cur = cur*10 + val` down the DFS; at leaves, contribute `cur`.

## 3. Brute Force → Optimal
- **Brute:** collect path digit vectors then convert — extra memory.
- **Optimal:** running integer along DFS — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** DFS with accumulated decimal value.

- **vs string paths then stoi:** slower and heavier.
- **vs BFS with (node, cur):** equivalent.

## 5. Logic Walkthrough
Null → 0. Update cur. Leaf → return cur. Else sum left+right.

## 6. Dry Run
`[1,2,3]`: paths 12 and 13 → 25.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(H)**. Why: one visit per node (section 4).

## 8. Trade-offs & Alternatives
Use `long long` if constraints grow beyond `int`.

## 9. Common Mistakes / Edge Cases
Adding non-leaf partials; resetting cur incorrectly; treating null child as a leaf number 0.

## 10. Interview Follow-ups / Variations
Binary Tree Paths (257); Path Sum (112).

## 11. Tags
`binary-tree`, `dfs`, `path`, `leetcode-129`, `difficulty:medium`
