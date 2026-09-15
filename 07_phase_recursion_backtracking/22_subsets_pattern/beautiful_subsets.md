# The Number of Beautiful Subsets

## 1. Problem Statement
[LeetCode 2597](https://leetcode.com/problems/the-number-of-beautiful-subsets/) — count non-empty subsets of `nums` such that no two elements differ by `k`.

- **Inputs:** `vector<int> nums`, `int k`.
- **Output:** count of beautiful subsets.
- **Valid answer:** exclude empty set.
- **Edges:** single element; all conflict; duplicates.

## 2. Intuition
Include/exclude each element; when including, check that `v-k` and `v+k` are absent from the current multiset (frequency map).

## 3. Brute Force → Optimal
- **Brute:** enumerate all 2^n subsets and validate — OK for n≤20.
- **Optimal:** same DFS with prune on conflict (still exponential).

## 4. Data Structure / Approach Justification
**Chosen:** DFS with value-frequency array after sorting.

- **vs DP on residue classes mod k:** faster asymptotically for large n; DFS teaches subsets pattern.

## 5. Logic Walkthrough
At index `i`: always skip; include if freqs of `v±k` are 0; update freq; recurse; undo.

## 6. Dry Run
`nums=[2,4,6]`, `k=2`: beautiful `{2},{4},{6},{2,6}` → **4**.

## 7. Time & Space Complexity
Time **O(2^n)**. Space **O(n + max(nums))** recursion/freq. Why: include/exclude tree (section 4).

## 8. Trade-offs & Alternatives
Group by `x % k` and DP independent chains for better complexity.

## 9. Common Mistakes / Edge Cases
Counting empty; forgetting undo; checking only one side of ±k.

## 10. Interview Follow-ups / Variations
List the subsets; constrain size; beautiful arrangements.

## 11. Tags
`backtracking`, `subsets`, `leetcode-2597`, `difficulty:medium`
