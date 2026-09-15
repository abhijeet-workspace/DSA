# Merge k Sorted Lists (K-Way Merge)

## 1. Problem Statement
[LeetCode 23](https://leetcode.com/problems/merge-k-sorted-lists/) — merge `k` sorted linked lists into one sorted list.

- **Inputs:** `vector<ListNode*> lists`.
- **Output:** head of the merged sorted list.
- **Valid answer:** all nodes from all lists in non-decreasing order.
- **Edges:** empty `lists`; null heads; `k==1`; single-node lists.

## 2. Intuition
Always take the smallest current head among the `k` lists. A min-heap of size ≤ K exposes that next node in O(log K).

## 3. Brute Force → Optimal
- **Brute:** concatenate all nodes and sort — O(N log N); or repeatedly merge two lists.
- **Optimal:** min-heap over K frontiers — O(N log K) for N total nodes.

## 4. Data Structure / Approach Justification
**Chosen:** `priority_queue` of `{val, ListNode*}`; after popping a node, push its `next` if any.

- **vs pairwise divide-and-conquer merge:** also O(N log K), less heap overhead.
- **vs comparing all heads each step:** O(N K) without a heap.

## 5. Logic Walkthrough
Seed heap with non-null heads. Pop min, append to result, push that list’s next. Repeat until heap empty. Related demos use the same frontier-heap pattern on matrices/arrays/pairs.

## 6. Dry Run
Lists `[1,4,7]`, `[2,5]`, `[0,3]`: heap starts `{0,1,2}` → pop 0 push 3 → pop 1 push 4 → … → `0,1,2,3,4,5,7`.

## 7. Time & Space Complexity
Time **O(N log K)**. Space **O(K)** for the heap. Why: each of N nodes enters/leaves the heap once (section 4).

## 8. Trade-offs & Alternatives
Heap is clear for interviews. Divide-and-conquer pairwise merge avoids storing K pointers and can be more cache-friendly.

## 9. Common Mistakes / Edge Cases
Pushing null heads; comparing `ListNode*` addresses instead of values; forgetting to advance `next` after pop.

## 10. Interview Follow-ups / Variations
Merge K sorted arrays; kth smallest in sorted matrix (378); k smallest pairs (373); external merge sort.

## 11. Tags
`heap`, `k-way-merge`, `linked-list`, `priority-queue`, `leetcode-23`, `difficulty:hard`
