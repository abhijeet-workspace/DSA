# Zigzag Iterator

## 1. Problem Statement
[LeetCode 281](https://leetcode.com/problems/zigzag-iterator/) — iterate two (or k) vectors in zigzag/round-robin order: v1[0], v2[0], v1[1], v2[1], …

- **Inputs:** vectors `v1`, `v2`.
- **Output:** sequence via `next` / `hasNext`.
- **Valid answer:** queue of frontiers per vector.
- **Edges:** one empty; unequal lengths.

## 2. Intuition
Keep a queue of which vector to read next; after reading, re-enqueue that vector if it still has elements.

## 3. Brute Force → Optimal
- **Brute:** precompute merged list.
- **Optimal:** O(1) amortized next with a queue of indices.

## 4. Data Structure / Approach Justification
**Chosen:** `queue<{vecIdx,elemIdx}>`.

- **k-way adjacent:** same frontier idea without value ordering.

## 5. Logic Walkthrough
Seed non-empty vectors. next: pop frontier, emit value, push next index if any.

## 6. Dry Run
`[1,2]` + `[3,4,5,6]` → `1 3 2 4 5 6`.

## 7. Time & Space Complexity
Time **O(1)** per next. Space **O(K)**. Why: queue of K frontiers (section 4).

## 8. Trade-offs & Alternatives
Premium problem; great warm-up for merge-k iterators.

## 9. Common Mistakes / Edge Cases
Re-enqueueing exhausted vectors; off-by-one on sizes.

## 10. Interview Follow-ups / Variations
Flatten 2D Vector (251); Merge k lists.

## 11. Tags
`design`, `queue`, `k-way-merge-adjacent`, `leetcode-281`, `difficulty:medium`
