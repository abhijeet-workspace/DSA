# Design Circular Deque

## 1. Problem Statement
[LeetCode 641](https://leetcode.com/problems/design-circular-deque/) — fixed-capacity double-ended queue: insert/delete at both ends; get front/rear; empty/full.

- **Inputs:** capacity `k`; front/rear insert and delete.
- **Output:** bool success / end values / flags.
- **Edges:** capacity 1; wrap both directions; empty/full transitions.

## 2. Intuition
Same ring buffer as circular queue, but also write at `head-1` and shrink from rear. Track `head` and `count`.

## 3. Brute Force → Optimal
- **Brute:** linked list or shifting vector.
- **Optimal:** circular array — O(1) all ops.

## 4. Data Structure / Approach Justification
**Chosen:** array + `head` + `count`.

| Alternative | Note |
|-------------|------|
| Doubly linked list | Classic deque; more pointers |
| Two stacks | Awkward for both ends |

## 5. Logic Walkthrough
1. Insert front: `head = (head-1+k)%k`, write, `++count`.
2. Insert last: write at `(head+count)%k`, `++count`.
3. Delete front: advance `head`; delete last: `--count`.
4. Get rear at `(head+count-1)%k`.

## 6. Dry Run
`k=3`: insertLast 1,2; insertFront 3 → front 3, rear 2; deleteLast → rear 1.

## 7. Time & Space Complexity
- **Time:** O(1) per op
- **Space:** O(k)

## 8. Trade-offs & Alternatives
`std::deque` is the STL analogue; interview wants the ring design.

## 9. Common Mistakes / Edge Cases
Negative modulo for `head-1`; mixing front/rear indices after wrap.

## 10. Interview Follow-ups / Variations
Circular queue (622); unbounded deque; sliding-window extrema.

## 11. Tags
`deque`, `design`, `array`, `leetcode-641`, `difficulty:medium`
