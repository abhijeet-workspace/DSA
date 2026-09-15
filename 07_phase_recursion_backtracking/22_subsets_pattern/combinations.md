# Combinations

## 1. Problem Statement
[LeetCode 77](https://leetcode.com/problems/combinations/) — return all possible combinations of `k` numbers chosen from the range `[1, n]`.

- **Inputs:** `int n`, `int k`.
- **Output:** all C(n,k) combinations.
- **Valid answer:** unordered sets of size k; order of lists does not matter.
- **Edges:** `k=1`; `k=n`; `k=0` (empty combo only if allowed by constraints).

## 2. Intuition
Classic cascade: from `start`, pick next number `x` then continue at `x+1` until path length is `k`.

## 3. Brute Force → Optimal
- **Brute:** generate all subsets then filter size — 2^n.
- **Optimal:** stop at depth k with prune when remaining integers are insufficient.

## 4. Data Structure / Approach Justification
**Chosen:** for-loop DFS building path of length k.

- **vs include/exclude:** for-loop is the standard combinations template.
- **vs iterative:** same complexity; recursion is clearer for teaching.

## 5. Logic Walkthrough
If `path.size()==k`, push copy. Else for `x=start..n` (with prune), push, recurse `x+1`, pop.

## 6. Dry Run
`n=4`, `k=2` → `[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]` (6).

## 7. Time & Space Complexity
Time **O(k · C(n,k))** (copy each combo). Space **O(k)** recursion. Why: C(n,k) outputs (section 4).

## 8. Trade-offs & Alternatives
Lexicographic iterative generators exist; DFS matches interview whiteboard style.

## 9. Common Mistakes / Edge Cases
Using `x` instead of `x+1` (duplicates); missing prune; off-by-one on `n`.

## 10. Interview Follow-ups / Variations
Combinations with duplicates; combination sum; permutations of length k.

## 11. Tags
`backtracking`, `combinations`, `leetcode-77`, `difficulty:medium`
