# Minimize Deviation in Array

## 1. Problem Statement
[LeetCode 1675](https://leetcode.com/problems/minimize-deviation-in-array/) — for each nums[i]: if even you may divide by 2 any times; if odd you may multiply by 2 once. Minimize max(nums)-min(nums) after operations.

## 2. Intuition
Odds can only go up once — multiply all odds by 2 first so every value is even and may only shrink by /2. Repeatedly shrink the current maximum; track max-min.

## 3. Brute Force → Optimal
- **Brute:** explore all reachable values — huge.
- **Optimal:** ordered multiset / two-heap simulation — O(N log N · log A).

## 4. Data Structure / Approach Justification
**Chosen:** `std::set` as ordered structure (max/min in O(1)); repeatedly replace even max with max/2.

- **vs priority_queue alone:** need current minimum too — set gives both.
- **vs binary search deviation:** need feasibility checker.

## 5. Logic Walkthrough
Insert evenized values. While max even: replace with max/2; update best deviation.

## 6. Dry Run
`[1,2,3,4]` → deviation **1**.

## 7. Time & Space Complexity
Time **O(N log N · log A)**. Space **O(N)**. Why: each /2 reduces max (section 4).

## 8. Trade-offs & Alternatives
Set is the clean “two-heaps” stand-in for min and max simultaneously.

## 9. Common Mistakes / Edge Cases
Forgetting to evenize odds; stopping while max odd early is correct; duplicates.

## 10. Interview Follow-ups / Variations
Only multiply allowed; constrain operation counts.

## 11. Tags
`heap`, `ordered-set`, `greedy`, `leetcode-1675`, `difficulty:hard`
