# Implement Stack using Queues

## Problem Statement
[LeetCode 225](https://leetcode.com/problems/implement-stack-using-queues/) — implement LIFO stack using only standard queue operations.

- **Inputs:** `push`, `pop`, `top`, `empty`.
- **Output:** stack semantics via one or two queues.
- **Valid answer:** last pushed is first popped / topped.
- **Edges:** single element; empty checks; alternating push/pop.

## Intuition
Queue is FIFO. After each `push`, rotate so the newest element sits at the front — then `pop`/`top` are O(1).

## Brute Force → Optimal
- **Brute / two queues:** push into empty queue then dump the other — O(N) push.
- **Optimal (one queue):** push then rotate `size-1` elements — same O(N) push, less storage.

## Data Structure / Approach Justification
**Chosen:** single queue with rotate-on-push.

- **vs two queues:** equivalent asymptotics; one queue is cleaner.
- **vs rotate-on-pop:** push O(1), but pop/top become O(N); either trade-off is acceptable.

## Logic Walkthrough
`push(x)`: enqueue `x`, then move the previous `n-1` fronts to the back. `pop`/`top` read front. `empty` checks queue empty.

## Dry Run
`push(1)` → `[1]`. `push(2)` → enqueue 2 → `[1,2]` → rotate → `[2,1]`. `top` → 2. `pop` → 2, left `[1]`.

## Time & Space Complexity
Push **O(N)**. Pop/top/empty **O(1)**. Space **O(N)**. Why: rotate walks current size (section 4).

## Trade-offs & Alternatives
Make pop O(N) and push O(1) if push-heavy. Two-queue version is fine in interviews.

## Common Mistakes / Edge Cases
Forgetting to rotate after push; confusing with queue-from-stacks (amortized O(1) there); calling pop on empty.

## Interview Follow-ups / Variations
Implement queue with stacks (232); min-stack; amortized analysis discussion.

## Tags
`stack`, `queue`, `design`, `leetcode-225`, `difficulty:easy`
