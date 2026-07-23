# Randomized Quickselect

## 1. Problem Statement
Find the k-th smallest element (0-based) in expected linear time.

- **Inputs:** mutable array `a`, index `k`.
- **Output:** value that would be at index `k` in sorted order.
- **Valid answer:** correct order statistic (duplicates allowed via `<=` partition).
- **Edges:** `k` out of range (caller responsibility); `n=1`; all equal.

Related: [LeetCode 215](https://leetcode.com/problems/kth-largest-element-in-an-array/) (k-th largest variant).

## 2. Intuition
Random pivot → partition like quicksort; recurse into only one side. Expected subproblem size shrinks by a constant factor.

## 3. Brute Force → Optimal
- **Brute:** sort O(N log N).
- **Optimal:** expected O(N) quickselect; worst O(N²) with tiny probability.

## 4. Data Structure / Approach Justification
**Chosen:** in-place Lomuto-style partition with random pivot index.

| Alternative | Note |
|-------------|------|
| Heap O(N log k) | Great for streaming top-k |
| Median-of-medians | Worst-case O(N), heavy |

## 5. Logic Walkthrough
1. Pick random pivot, swap to `hi`, partition.
2. If pivot index `p == k`, done.
3. Else shrink to left (`k < p`) or right (`k > p`).

## 6. Dry Run
`[7,2,1,6,8,5]`, `k=2` → sorted `1,2,5,...` → answer **5**.

## 7. Time & Space Complexity
Expected **O(N)** time, **O(1)** extra space (iterative). Why: random pivot geometry (section 4).

## 8. Trade-offs & Alternatives
Simple and fast in practice; not worst-case guaranteed. Use MoM or heap when you need guarantees.

## 9. Common Mistakes / Edge Cases
Off-by-one between 0-based `k` and partition index; unstable RNG seeding in tests.

## 10. Interview Follow-ups / Variations
Make it worst-case linear; k-th largest; quickselect vs heap tradeoffs.

## 11. Tags
`quickselect`, `randomized`, `order-statistic`, `leetcode-215`, `difficulty:medium`
