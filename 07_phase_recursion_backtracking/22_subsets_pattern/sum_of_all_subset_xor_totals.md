# Sum of All Subset XOR Totals

## 1. Problem Statement
[LeetCode 1863](https://leetcode.com/problems/sum-of-all-subset-xor-totals/) — the XOR total of a subset is the XOR of its elements (0 for empty). Return the sum of XOR totals over all subsets.

- **Inputs:** `vector<int> nums`.
- **Output:** integer sum.
- **Valid answer:** includes empty contribution 0.
- **Edges:** single element; all zeros.

## 2. Intuition
Include/exclude DFS accumulates running XOR; add to answer at leaves. (Closed form: each bit contributes independently.)

## 3. Brute Force → Optimal
- **Brute:** DFS 2^n — fine for n≤12.
- **Optimal math:** for each bit, if present in any num, it appears in half of subsets → O(n · 32).

## 4. Data Structure / Approach Justification
**Chosen:** include/exclude DFS to reinforce subsets pattern.

- **vs O(n) bit formula:** faster; teach after understanding subsets.

## 5. Logic Walkthrough
At `i`: recurse exclude with same XOR; include with `curXor ^ nums[i]`. At end add `curXor`.

## 6. Dry Run
`[1,3]`: subsets XOR 0,1,3,2 → sum **6**.

## 7. Time & Space Complexity
Time **O(2^n)**. Space **O(n)**. Why: full power set (section 4).

## 8. Trade-offs & Alternatives
Prefer bit contribution formula in production.

## 9. Common Mistakes / Edge Cases
Forgetting empty; using OR instead of XOR; mutating shared state without undo (XOR is self-undo via branch).

## 10. Interview Follow-ups / Variations
Count subsets with XOR=k; maximum subset XOR.

## 11. Tags
`backtracking`, `bit-manipulation`, `leetcode-1863`, `difficulty:easy`
