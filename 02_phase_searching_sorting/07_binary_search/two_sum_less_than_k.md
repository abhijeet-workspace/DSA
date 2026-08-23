# Two Sum Less Than K

## Problem Statement
[LeetCode 1099](https://leetcode.com/problems/two-sum-less-than-k/) — return the maximum `nums[i]+nums[j]` (i<j) strictly less than `k`, or `-1`. Premium.

- **Inputs:** `vector<int> nums`, `int k`.
- **Output:** `int`.
- **Valid answer:** max pair sum < k.
- **Edges:** no valid pair; duplicates; negative-free typical LC data.

## Intuition
After sorting, for each left value the best partner is the rightmost number `< k-nums[i]` — an upper-bound search.

## Brute Force → Optimal
- **Brute:** all pairs — O(N²).
- **Optimal:** sort + binary search — O(N log N). Two pointers after sort is O(N).

## Data Structure / Approach Justification
**Chosen:** binary search as a tool on a sorted array (study-plan group).

- **vs two pointers:** O(N) after sort; preferred in interviews unless the plan requires BS
- **vs hash:** harder for “less than k” max

## Logic Walkthrough
Sort. For each i, binary search the largest nums[j] < k-nums[i] with j>i.

## Dry Run
`[34,23,1,24,75,33,54,8]`, k=60 → 34+24=58.

## Time & Space Complexity
Time **O(N log N)**. Space **O(1)** extra besides sort. Why: N binary searches after O(N log N) sort.

## Trade-offs & Alternatives
Two pointers is the faster sibling of the same idea.

## Common Mistakes / Edge Cases
Allowing i==j; using ≤ k.

## Interview Follow-ups / Variations
Valid triangle number; 3Sum closest.

## Tags
`binary-search`, `sorting`, `premium`, `leetcode-1099`, `difficulty:easy`
