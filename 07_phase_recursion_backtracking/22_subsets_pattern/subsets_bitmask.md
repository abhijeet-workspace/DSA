# Subsets (Bitmask)

## 1. Problem Statement
[LeetCode 78](https://leetcode.com/problems/subsets/) — return all subsets of distinct `nums`, generated via bitmasks (teaching companion to DFS subsets).

- **Inputs:** `vector<int> nums` (distinct).
- **Output:** power set.
- **Valid answer:** 2^n subsets including empty.
- **Edges:** empty input; n up to ~20 practical.

## 2. Intuition
Each subset ↔ integer mask in `[0, 2^n)`. Bit `i` set means include `nums[i]`.

## 3. Brute Force → Optimal
- **Brute/Optimal:** enumerate all masks — asymptotically optimal for listing.

## 4. Data Structure / Approach Justification
**Chosen:** loop masks + inner bit test.

- **vs DFS backtracking:** same output; bitmasks avoid recursion and clarify 2^n structure.
- **vs iterative doubling:** also good; bitmasks map cleanly to DP-on-subsets later.

## 5. Logic Walkthrough
For `mask` in `0..(1<<n)-1`, build vector of `nums[i]` where bit i is set.

## 6. Dry Run
`[1,2,3]`: mask 0→`[]`, 1→`[1]`, 2→`[2]`, 3→`[1,2]`, … → 8 subsets.

## 7. Time & Space Complexity
Time **O(n · 2^n)**. Space **O(n · 2^n)** output. Why: each mask builds up to n elements (section 4).

## 8. Trade-offs & Alternatives
Prefer DFS when you need prune mid-search; prefer masks when teaching subset DP.

## 9. Common Mistakes / Edge Cases
Off-by-one on `1<<n`; signed shift UB for n≥31; assuming order matches DFS order.

## 10. Interview Follow-ups / Variations
Subsets II with duplicates via masks+sort; subset-sum DP; SOS DP.

## 11. Tags
`bitmask`, `subsets`, `leetcode-78`, `difficulty:medium`
