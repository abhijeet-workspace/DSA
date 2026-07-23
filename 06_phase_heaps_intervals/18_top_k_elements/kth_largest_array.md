# Kth Largest Element in an Array

## Problem Statement
[LeetCode 215](https://leetcode.com/problems/kth-largest-element-in-an-array/) — return the kth largest element in `nums` (1-indexed in sorted descending order).

- **Inputs:** `vector<int> nums`, `int k` (1 ≤ k ≤ n).
- **Output:** single `int` — the kth largest value.
- **Valid answer:** kth in sorted order, not kth distinct (duplicates count).
- **Edges:** k = 1 (max); k = n (min); duplicates; negatives.

## Intuition
Maintain the “current top-k largest” in a min-heap of size k. The heap root is the smallest of those k → exactly the kth largest overall.

## Brute Force → Optimal
- **Brute:** sort descending, take index `k-1` — O(N log N).
- **Optimal (heap):** one pass with size-k min-heap — O(N log K).
- **Also optimal average:** Quickselect — O(N) average, O(N²) worst.

## Data Structure / Approach Justification
**Chosen:** `priority_queue` min-heap of size k.

- **vs full sort:** same answer, worse when K ≪ N.
- **vs max-heap of all N then pop k times:** O(N + K log N); size-k min-heap is better when K is small.
- **vs Quickselect:** faster average but mutates array and has worse worst-case.

## Logic Walkthrough
For each `num`, push into `minHeap`. If size > k, pop. After the scan, `minHeap.top()` is the answer.

## Dry Run
`nums=[3,2,1,5,6,4]`, `k=2`:
- push 3,2 → heap `[2,3]`; push 1 → pop 1 → `[2,3]`
- push 5 → pop 2 → `[3,5]`; push 6 → pop 3 → `[5,6]`; push 4 → pop 4 → `[5,6]`
- top = **5**

## Time & Space Complexity
Time **O(N log K)**. Space **O(K)** for the heap. Why: each of N inserts/pops is log K on a bounded heap (section 4).

## Trade-offs & Alternatives
Heap is interview-friendly and stable. Prefer Quickselect when average O(N) and in-place mutation are allowed; prefer sort when N is tiny or you need full order anyway.

## Common Mistakes / Edge Cases
Using a max-heap of size k (tracks smallest, not largest); confusing kth largest with kth distinct; off-by-one on k.

## Interview Follow-ups / Variations
Kth smallest → max-heap of size k. Online stream → same heap. Find median → dual heaps. Quickselect deep-dive.

## Tags
`heap`, `top-k`, `min-heap`, `leetcode-215`, `difficulty:medium`
