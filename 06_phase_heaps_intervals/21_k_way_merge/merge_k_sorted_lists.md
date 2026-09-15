# Merge k Sorted Lists

## 1. Problem Statement
[LeetCode 23](https://leetcode.com/problems/merge-k-sorted-lists/) — merge k sorted linked lists into one sorted list.

- **Inputs:** `vector<ListNode*> lists`.
- **Output:** head of merged list.
- **Valid answer:** all nodes in non-decreasing order.
- **Edges:** empty lists; null heads; k=1.

## 2. Intuition
Always take the smallest current head among k lists — min-heap of size ≤ k.

## 3. Brute Force → Optimal
- **Brute:** concatenate + sort; or pairwise merge repeatedly.
- **Optimal:** heap of heads — O(N log K).

## 4. Data Structure / Approach Justification
**Chosen:** min-heap `{val, node*}`.

- **vs divide-and-conquer pairwise:** also O(N log K).

## 5. Logic Walkthrough
Seed heap with non-null heads. Pop min, append, push next. Repeat.

## 6. Dry Run
`[1,4,5],[1,3,4],[2,6]` → `1->1->2->3->4->4->5->6`.

## 7. Time & Space Complexity
Time **O(N log K)**. Space **O(K)**. Why: each of N nodes heap-pushed once (section 4).

## 8. Trade-offs & Alternatives
Canonical k-way merge. See also `k_way_merge` demos for arrays/matrix.

## 9. Common Mistakes / Edge Cases
Pushing null; comparing pointers; leaking nodes in demos.

## 10. Interview Follow-ups / Variations
Merge k sorted arrays; kth smallest in matrix (378).

## 11. Tags
`heap`, `k-way-merge`, `linked-list`, `leetcode-23`, `difficulty:hard`
