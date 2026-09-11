# Kth Largest Element in an Array (Quickselect)

## Problem Statement
[LeetCode 215](https://leetcode.com/problems/kth-largest-element-in-an-array/) — return the kth largest element in `nums` (1-indexed in sorted descending order).

- **Inputs:** `vector<int> nums`, `int k` (1 ≤ k ≤ n).
- **Output:** single `int` — the kth largest value.
- **Valid answer:** kth in sorted order, not kth distinct (duplicates count).
- **Edges:** k = 1 (max); k = n (min); duplicates; negatives.

## Intuition
kth largest ≡ ascending index `n - k`. Partition around a random pivot like quicksort, then discard the half that cannot contain that index. Only one side continues.

## Brute Force → Optimal
- **Brute:** sort descending, take index `k-1` — O(N log N).
- **Heap:** size-k min-heap — O(N log K), no full mutation needed.
- **Optimal average (this file):** Quickselect — O(N) average, O(N²) worst.

## Data Structure / Approach Justification
**Chosen:** in-place Lomuto partition with random pivot; iterative Quickselect to target `n - k`.

- **vs full sort:** same answer, better average when you only need one order statistic.
- **vs size-k min-heap:** faster average O(N) vs O(N log K); heap wins for streaming / when mutation is forbidden.
- **vs median-of-medians:** MoM is worst-case O(N) but heavier to code under interview time.

## Logic Walkthrough
1. Set `target = n - k`.
2. Pick random pivot, swap to `hi`, Lomuto-partition (`<=` pivot).
3. If pivot index `p == target`, return `a[p]`.
4. Else shrink to left (`target < p`) or right (`target > p`); repeat.

## Dry Run
`nums=[3,2,1,5,6,4]`, `k=2` → `target = 6 - 2 = 4` (ascending sorted `1,2,3,4,5,6` → index 4 is **5**).

Example partition path (one possible RNG):
- pivot lands so `p` ≠ 4 → discard the irrelevant side
- next partition places 5 at index 4 → return **5**

## Time & Space Complexity
Time **O(N)** average, **O(N²)** worst. Space **O(1)** extra (iterative; input copy if caller must preserve `nums`). Why: expected geometric shrink of the active range with random pivots.

## Trade-offs & Alternatives
Prefer Quickselect when average O(N) and in-place mutation are allowed. Prefer heap when K is tiny, input is a stream, or worst-case must stay O(N log K). Prefer sort when N is tiny or full order is needed anyway.

## Common Mistakes / Edge Cases
Using `k` as the ascending index instead of `n - k`; confusing kth largest with kth distinct; off-by-one on `lo`/`hi`; forgetting random pivot (adversarial arrays hit O(N²)).

## Interview Follow-ups / Variations
Kth smallest → target index `k - 1`. Worst-case linear → median-of-medians. Online stream → heap. Find median → dual heaps or Quickselect at `n/2`.

## Tags
`quickselect`, `top-k`, `partition`, `leetcode-215`, `difficulty:medium`
