# Implement Queue using Stacks

## 1. Problem Statement
[LeetCode 232](https://leetcode.com/problems/implement-queue-using-stacks/) — implement FIFO queue using only stack operations.

- **Inputs:** `push`, `pop`, `peek`, `empty`.
- **Output:** queue semantics via one or two stacks.
- **Valid answer:** earliest pushed is first popped / peeked.
- **Edges:** single element; empty checks; push after partial pops.

## 2. Intuition
Stack reverses order. Two stacks: `in` accepts pushes; when `out` is empty, dump `in`→`out` so front sits on `out.top`.

## 3. Brute Force → Optimal
- **Brute:** move everything on every pop — O(N) each op.
- **Optimal:** lazy transfer only when `out` empty — amortized O(1) per op.

## 4. Data Structure / Approach Justification
**Chosen:** two stacks (`in`, `out`) with lazy transfer.

| Alternative | Why not here |
|-------------|--------------|
| One stack + recursion | Uses call stack; not pure stack ADT |
| Rotate on every push | Correct but worse constants |

## 5. Logic Walkthrough
1. `push(x)` → `in.push(x)`.
2. Before `pop`/`peek`: if `out` empty, while `in` not empty move top to `out`.
3. `pop`/`peek` use `out.top`; `empty` iff both empty.

## 6. Dry Run
`push(1)`, `push(2)` → `in=[1,2]`, `out=[]`. `peek` transfers → `out=[2,1]`, front `1`. `pop` → `1`.

## 7. Time & Space Complexity
- **Time:** amortized O(1) per op (each element moves at most twice)
- **Space:** O(N)

## 8. Trade-offs & Alternatives
Make push O(N) and pop O(1) if preferred. Contrast with stack-from-queues (225).

## 9. Common Mistakes / Edge Cases
Transferring when `out` still has elements (reverses wrong); not checking both stacks for empty.

## 10. Interview Follow-ups / Variations
Amortized vs worst-case O(1); implement stack with queues.

## 11. Tags
`queue`, `stack`, `design`, `leetcode-232`, `difficulty:easy`
