# Minimum Time to Collect All Apples in a Tree

## 1. Problem Statement
[LeetCode 1443](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/) — undirected tree rooted at 0. `hasApple[i]` marks apples. Starting at 0, moving along an edge costs 1 second. Return minimum seconds to collect all apples and return to 0.

- **Inputs:** `n`, `edges`, `hasApple`.
- **Output:** minimum time.
- **Valid answer:** traverse each needed edge twice (down/up) if subtree has apples.
- **Edges:** no apples → 0; apple only at root.

## 2. Intuition
DFS: if a child subtree contains any apple, add 2 to the answer for the edge to that child, then recurse.

## 3. Brute Force → Optimal
- **Brute:** try all Euler tours — unnecessary.
- **Optimal:** one DFS O(n).

## 4. Data Structure / Approach Justification
**Chosen:** tree DFS returning whether subtree has apples / apple count.

- **vs rerooting DP:** overkill for fixed root 0.

## 5. Logic Walkthrough
Build undirected adj. DFS from 0: for each child with apples in subtree, `time += 2`.

## 6. Dry Run
Sample → **8** seconds.

## 7. Time & Space Complexity
Time **O(n)**. Space **O(n)**. Why: tree edges once (section 4).

## 8. Trade-offs & Alternatives
Post-order boolean `needVisit` without counting apples explicitly.

## 9. Common Mistakes / Edge Cases
Adding 1 instead of 2; collecting without returning; treating as directed.

## 10. Interview Follow-ups / Variations
Multiple roots; weighted edges; only deliver not return.

## 11. Tags
`dfs`, `tree`, `leetcode-1443`, `difficulty:medium`
