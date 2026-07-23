# Implement Queue using Stacks

## Problem Statement
[LeetCode 232](https://leetcode.com/problems/implement-queue-using-stacks/) — implement FIFO queue with only stack ops: `push`, `pop`, `peek`, `empty`.

- **Inputs:** sequence of queue operations.
- **Output:** FIFO order (front is oldest).
- **Valid answer:** amortized O(1) per op with two stacks.
- **Edges:** pop/peek when one stack empty; interleaved push/pop.

## Intuition
One stack receives pushes. To serve the front, reverse into a second stack once; subsequent pops stay cheap until that stack drains.

## Brute Force → Optimal
- **Brute:** move all between stacks on every pop — O(N) per op.
- **Optimal:** lazy transfer only when output stack is empty — amortized O(1).

## Data Structure / Approach Justification
**Chosen:** `in_` (push) + `out_` (pop/peek) with lazy reverse.

- **vs single stack:** cannot get FIFO without O(N) reshuffles every time.
- **vs real queue/`deque`:** trivial but violates the constraint.

## Logic Walkthrough
`push` → `in_`. `pop`/`peek` → if `out_` empty, pour `in_`→`out_`; then use `out_.top`.

## Dry Run
push 1,2 → `in_=[1,2]`. peek → transfer → `out_=[2,1]`, front 1. pop → 1. empty? false (`out_` has 2).

## Time & Space Complexity
`push` **O(1)**. `pop`/`peek` **O(1) amortized**. Space **O(N)**. Why: each element moves at most once to `out_` (section 4).

## Trade-offs & Alternatives
Make `push` expensive instead (pour on every push) — same amortized bound, worse push latency.

## Common Mistakes / Edge Cases
Transferring when `out_` nonempty (reorders); forgetting both stacks in `empty()`.

## Interview Follow-ups / Variations
Stack using queues (225); true amortized analysis argument.

## Tags
`stack`, `queue`, `amortized`, `leetcode-232`, `difficulty:easy`
