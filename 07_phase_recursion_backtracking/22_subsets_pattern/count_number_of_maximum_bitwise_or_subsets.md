# Count Number of Maximum Bitwise-OR Subsets

## 1. Problem Statement
[LeetCode 2044](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/) — let `maxOR` be the bitwise OR of the entire array. Count non-empty? subsets whose OR equals `maxOR` (LC counts all subsets achieving max, empty OR is 0 so usually excluded automatically unless nums empty).

- **Inputs:** `vector<int> nums`.
- **Output:** count of subsets with OR == maxOR.
- **Valid answer:** as on LeetCode (empty only if maxOR=0).
- **Edges:** all equal; single element.

## 2. Intuition
First compute `target = OR(all)`. Include/exclude DFS; count leaves where running OR equals target.

## 3. Brute Force → Optimal
- **Brute:** 2^n DFS — n≤16 constraints.
- **Optimal:** same; prune when `cur == target` early count 2^(remaining) shortcut.

## 4. Data Structure / Approach Justification
**Chosen:** include/exclude with running OR.

- **vs DP on OR value:** useful when values are small.

## 5. Logic Walkthrough
Compute target. DFS exclude/include. At end, if `cur==target` increment.

## 6. Dry Run
`[3,1]`: maxOR=3; subsets `{3}`, `{3,1}` → **2**.

## 7. Time & Space Complexity
Time **O(2^n)**. Space **O(n)**. Why: power-set search (section 4).

## 8. Trade-offs & Alternatives
Early prune: if `cur==target`, add `1<<(n-i)` and return.

## 9. Common Mistakes / Edge Cases
Comparing to wrong target; double-counting; forgetting include branch uses OR not XOR.

## 10. Interview Follow-ups / Variations
List subsets; maximize AND; count with size constraint.

## 11. Tags
`backtracking`, `bit-manipulation`, `leetcode-2044`, `difficulty:medium`
