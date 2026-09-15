# Smallest Range Covering Elements from K Lists

## 1. Problem Statement
[LeetCode 632](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/) — k sorted lists; find smallest range `[a,b]` that contains at least one number from each list.

- **Inputs:** `nums` — k sorted arrays.
- **Output:** `[a,b]` with minimal `b-a` (tie → smallest a).
- **Valid answer:** sliding window over k-way merge pointers.
- **Edges:** k=1; identical elements; negative numbers.

## 2. Intuition
Maintain one pointer per list in a min-heap; track current max. The range [heap.min, max] covers all lists; advance the list that provides the min.

## 3. Brute Force → Optimal
- **Brute:** all candidate pairs — too slow.
- **Optimal:** heap k-way — O(N log K).

## 4. Data Structure / Approach Justification
**Chosen:** min-heap of current heads + running max.

- **vs multiset of all:** heavier.

## 5. Logic Walkthrough
Seed heap with first of each list. While possible: update best range; push next from list of popped min; update max; stop when a list exhausts.

## 6. Dry Run
lists example → range **[20,24]**.

## 7. Time & Space Complexity
Time **O(N log K)**. Space **O(K)**. Why: each element enters heap once (section 4).

## 8. Trade-offs & Alternatives
Flagship hard k-way problem.

## 9. Common Mistakes / Edge Cases
Stopping too early; not tracking max correctly; off-by-one on range length.

## 10. Interview Follow-ups / Variations
Merge k lists; smallest range II (different problem).

## 11. Tags
`heap`, `k-way-merge`, `two-pointers`, `leetcode-632`, `difficulty:hard`
