# Kth Largest Element in an Array (Max Heap)

## 1. Problem Statement
[LeetCode 215](https://leetcode.com/problems/kth-largest-element-in-an-array/) — return the kth largest element in `nums` (1-indexed in sorted descending order).

- **Inputs:** `vector<int> nums`, `int k` (1 ≤ k ≤ n).
- **Output:** single `int` — the kth largest value.
- **Valid answer:** kth in sorted order, not kth distinct (duplicates count).
- **Edges:** k = 1 (max); k = n (min); duplicates; negatives.

## 2. Intuition
Build a max-heap over all N elements. The root is the largest; after popping `k - 1` times, the new root is the kth largest.

## 3. Brute Force → Optimal
- **Brute:** sort descending, take index `k-1` — O(N log N).
- **This file (max-heap):** heapify all, pop k − 1 — O(N + K log N).
- **Better when K ≪ N:** size-k min-heap — O(N log K).
- **Also optimal average:** Quickselect — O(N) average, O(N²) worst.

## 4. Data Structure / Approach Justification
**Chosen:** `priority_queue` max-heap over the full array, then pop `k - 1`.

- **vs size-k min-heap:** same answer; min-heap uses O(K) space and O(N log K) time — better when K is small.
- **vs full sort:** same asymptotic order when K ≈ N; heap stops after K pops.
- **vs Quickselect:** simpler to code; Quickselect wins on average time and extra space when mutation is allowed.

## 5. Logic Walkthrough
1. Construct max-heap from `nums` (O(N) heapify via range constructor).
2. Pop once for each of the top `k - 1` values.
3. `maxHeap.top()` is the kth largest.

## 6. Dry Run
`nums=[3,2,1,5,6,4]`, `k=2`:
- heapify → root **6**
- pop once → root **5**
- return **5**

## 7. Time & Space Complexity
Time **O(N + K log N)**. Space **O(N)** for the heap. Why: heapify is linear; each of K − 1 pops is log N.

## 8. Trade-offs & Alternatives
Max-heap is clear when teaching “pop the largest K times.” Prefer size-k min-heap for streaming / small K; prefer Quickselect for average O(N) in-place selection.

## 9. Common Mistakes / Edge Cases
Using a max-heap of size k (that tracks the k smallest, not k largest); popping k times instead of k − 1; confusing kth largest with kth distinct.

## 10. Interview Follow-ups / Variations
Kth smallest → min-heap + pop k − 1, or size-k max-heap. Online stream → size-k min-heap. Find median → dual heaps.

## 11. Tags
`heap`, `top-k`, `max-heap`, `leetcode-215`, `difficulty:medium`
