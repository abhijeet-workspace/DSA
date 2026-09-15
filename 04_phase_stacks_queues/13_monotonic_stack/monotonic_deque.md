# Monotonic Deque (MaxQueue)

## 1. Problem Statement
Implement a queue that supports FIFO `push` / `pop` and `getMax` in amortized O(1) using a monotonic deque.

- **Ops:** `push(val)`, `pop()`, `getMax()`, `empty()`.
- **Output:** `getMax` returns the maximum among elements currently in the queue.
- **Edges:** pop on empty (no-op); getMax on empty (error); duplicates of the max; decreasing then increasing sequences.

## 2. Intuition
A FIFO queue alone cannot answer max quickly. Keep a second decreasing deque of candidate maxima; when a larger value arrives, purge smaller backs that can never win.

## 3. Brute Force → Optimal
- **Brute:** scan queue on each getMax — O(N) per query.
- **Heap + lazy delete:** O(log N) ops.
- **Optimal:** monotonic deque — amortized O(1) push/pop, O(1) getMax.

## 4. Data Structure / Approach Justification
**Chosen:** `queue` for order + `deque` of values in decreasing order.

| Alternative | Why it loses here |
|-------------|-------------------|
| Multiset | O(log N) and more memory |
| Two stacks (max stack) | Also O(1) amortized; deque mirrors sliding-window max |

## 5. Logic Walkthrough
`push`: enqueue; while `max_dq.back() < val` pop back; push `val`. `pop`: if front equals `max_dq.front()`, pop max deque too. `getMax`: `max_dq.front()`.

## 6. Dry Run
Push `4,1,3,2` → max deque `[4,3,2]`, max `4`. Pop `4` → `[3,2]`, max `3`. Pop `1` (not max) → still `3`. Pop `3` → max `2`.

## 7. Time & Space Complexity
- **Time:** push O(1) amortized; pop/getMax O(1).
- **Space:** O(N).

## 8. Trade-offs & Alternatives
Storing indices helps if values duplicate and you need identity; values alone work if equality matches FIFO (as here). MinQueue uses increasing deque.

## 9. Common Mistakes / Edge Cases
Forgetting to pop max when front equals max; using `<=` vs `<` with duplicate maxima; calling getMax when empty.

## 10. Interview Follow-ups / Variations
Sliding window maximum; MinQueue; design queue with getMin and getMax together.

## 11. Tags
`deque`, `queue`, `monotonic-queue`, `design`, `difficulty:medium`
