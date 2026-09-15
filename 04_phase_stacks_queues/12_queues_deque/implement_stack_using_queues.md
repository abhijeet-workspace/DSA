# Implement Stack using Queues

## 1. Problem Statement
[LeetCode 225](https://leetcode.com/problems/implement-stack-using-queues/) — implement LIFO stack using only standard queue operations.

- **Inputs:** `push`, `pop`, `top`, `empty`.
- **Output:** stack semantics via one or two queues.
- **Valid answer:** last pushed is first popped / topped.
- **Edges:** single element; empty checks; alternating push/pop.

## 2. Intuition
Queue is FIFO. After each `push`, rotate so the newest element sits at the front — then `pop`/`top` are O(1).

## 3. Brute Force → Optimal
- **Brute / two queues:** push into empty queue then dump the other — O(N) push.
- **Optimal (one queue):** push then rotate `size-1` elements — same O(N) push, less storage.

## 4. Data Structure / Approach Justification
**Chosen:** single queue with rotate-on-push.

| Alternative | Why not preferred |
|-------------|-------------------|
| Two queues | Equivalent asymptotics; more storage |
| Rotate-on-pop | Push O(1), but pop/top become O(N) |

## 5. Logic Walkthrough
1. `push(x)`: enqueue `x`, then move the previous `n-1` fronts to the back.
2. `pop`/`top` read front.
3. `empty` checks queue empty.

## 6. Dry Run
`push(1)` → `[1]`. `push(2)` → enqueue 2 → `[1,2]` → rotate → `[2,1]`. `top` → 2. `pop` → 2, left `[1]`.

## 7. Time & Space Complexity
- **Time:** Push O(N); pop/top/empty O(1)
- **Space:** O(N)

## 8. Trade-offs & Alternatives
Make pop O(N) and push O(1) if push-heavy. Two-queue version is fine in interviews.

## 9. Common Mistakes / Edge Cases
Forgetting to rotate after push; confusing with queue-from-stacks (amortized O(1) there); calling pop on empty.

## 10. Interview Follow-ups / Variations
Implement queue with stacks (232); min-stack; amortized analysis discussion.

## 11. Tags
`stack`, `queue`, `design`, `leetcode-225`, `difficulty:easy`
