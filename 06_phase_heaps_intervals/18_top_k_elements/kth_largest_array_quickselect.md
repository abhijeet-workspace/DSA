# Kth Largest Element in an Array (Quickselect)

## 1. Problem Statement
[LeetCode 215](https://leetcode.com/problems/kth-largest-element-in-an-array/) — return the kth largest element in `nums` (1-indexed in sorted descending order).

- **Inputs:** `vector<int> nums`, `int k` (1 ≤ k ≤ n).
- **Output:** single `int` — the kth largest value.
- **Valid answer:** kth in sorted order, not kth distinct (duplicates count).
- **Edges:** k = 1 (max); k = n (min); duplicates; negatives.

## 2. Intuition
kth largest ≡ ascending index `n - k`. Partition around a random pivot like quicksort, then discard the region that cannot contain that index. Only one side continues. Duplicates are their own middle band so a long run of equal values is finished in one pass.

## 3. Brute Force → Optimal
- **Brute:** sort descending, take index `k-1` — O(N log N).
- **Heap:** size-k min-heap — O(N log K), no full mutation needed.
- **Optimal average (this file):** Quickselect — O(N) average, O(N²) worst.

## 4. Data Structure / Approach Justification
**Chosen:** in-place three-way (Dutch-flag) partition with random pivot; iterative Quickselect to target `n - k`.

- **vs full sort:** same answer, better average when you only need one order statistic.
- **vs size-k min-heap:** faster average O(N) vs O(N log K); heap wins for streaming / when mutation is forbidden.
- **vs median-of-medians:** MoM is worst-case O(N) but heavier to code under interview time.

## 5. Logic Walkthrough
1. Set `target = n - k`.
2. Pick a random pivot. Three-way partition into `< pivot`, `== pivot` `[eqLo, eqHi]`, `> pivot`.
3. If `target` lies in `[eqLo, eqHi]`, return `a[target]` (every index in that band holds the pivot).
4. Else shrink to the left (`target < eqLo`) or the right (`target > eqHi`); repeat.

## 6. Dry Run
`nums=[3,2,1,5,6,4]`, `k=2` → `target = 6 - 2 = 4` (ascending sorted `1,2,3,4,5,6` → index 4 is **5**).

Example partition path (one possible RNG):
- pivot’s equal band does not cover index 4 → discard the irrelevant side
- next partition places 5 at index 4 → return **5**

## 7. Time & Space Complexity
Time **O(N)** average, **O(N²)** worst. Space **O(1)** extra (iterative; input copy if caller must preserve `nums`). Why: expected geometric shrink of the active range with random pivots. A duplicate run is discarded as one band, so an array that is almost all the same value is one partition, not N of them.

## 8. Trade-offs & Alternatives
Prefer Quickselect when average O(N) and in-place mutation are allowed. Prefer heap when K is tiny, input is a stream, or worst-case must stay O(N log K). Prefer sort when N is tiny or full order is needed anyway.

## 9. Common Mistakes / Edge Cases
Using `k` as the ascending index instead of `n - k`; confusing kth largest with kth distinct; off-by-one on `lo`/`hi`; two-way Lomuto (`<=` pivot) on a long duplicate run — every equal value lands on one side, the window shrinks by one, and `n = 1e5` of `1`s is O(N²) / TLE. Random pivot does not fix that, because the pivot is almost always the repeated value. Three-way partition returns as soon as `target` falls inside the equal band.

## 10. Interview Follow-ups / Variations
Kth smallest → target index `k - 1`. Worst-case linear → median-of-medians. Online stream → heap. Find median → dual heaps or Quickselect at `n/2`.

## 11. Tags
`quickselect`, `top-k`, `partition`, `leetcode-215`, `difficulty:medium`
