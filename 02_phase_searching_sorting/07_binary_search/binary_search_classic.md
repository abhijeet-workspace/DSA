# Binary Search (Classic)

## Problem Statement
[LeetCode 704](https://leetcode.com/problems/binary-search/) — sorted ascending `nums`; return index of `target` or `-1`.

- **Inputs:** `vector<int> nums` (sorted ascending), `int target`.
- **Output:** index of `target`, or `-1` if absent.
- **Valid answer:** any index where `nums[i] == target` (distinct values here).
- **Edges:** empty; single element; target smaller/larger than all; not present.

## Intuition
Sorted order lets each mid comparison discard half the remaining range. Teach both iterative and recursive forms (`binarySearchIterative` / `binarySearchRecursive`).

## Brute Force → Optimal
- **Brute:** linear scan — O(N).
- **Optimal:** binary search — O(log N) compares.

## Data Structure / Approach Justification
**Chosen:** closed interval `[left, right]` with overflow-safe `mid = left + (right - left) / 2`.

- **vs linear scan:** log-time on large N; requires sorted input.
- **vs STL `lower_bound`:** manual form shows the loop invariant interviewers expect.

## Logic Walkthrough
While `left <= right`, compare `nums[mid]` to `target`. Equal → return `mid`. Too small → `left = mid + 1`. Too large → `right = mid - 1`. Exhausted → `-1`. Recursive helper mirrors the same splits.

## Dry Run
`nums = [-1,0,3,5,9,12]`, `target = 9`:
- mid → `3` (idx 2) < 9 → left = 3
- mid → `9` (idx 4) == 9 → return 4

## Time & Space Complexity
Time **O(log N)**. Space **O(1)** iterative / **O(log N)** recursive stack. Why: halve each step (section 4).

## Trade-offs & Alternatives
Iterative preferred in production (no stack). Recursive is clearer for teaching the divide.

## Common Mistakes / Edge Cases
`(left + right) / 2` overflow; `left < right` vs `<=` confusion; forgetting empty array (`right = -1`).

## Interview Follow-ups / Variations
Lower/upper bound; search insert position; duplicates.

## Tags
`binary-search`, `array`, `divide-conquer`, `difficulty:easy`
