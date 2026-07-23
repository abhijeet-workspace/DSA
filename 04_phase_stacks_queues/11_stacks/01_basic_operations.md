# Basic Stack Operations

## Problem Statement
Demonstrate `std::stack` primitives: `push`, `pop`, `top`, `size`, and `empty`.

- **Inputs:** integers pushed in order 10, 20, 30, 40.
- **Output:** size/top before pops; LIFO pop order 40→10; empty afterward.
- **Valid answer:** top is always the last pushed unread element.
- **Edges:** `top`/`pop` on empty is undefined behavior — always check `empty()`.

## Intuition
A stack is LIFO: the last push is the only accessible element until it is popped. All adapter ops are O(1).

## Brute Force → Optimal
- **Naive:** use a `vector` and remember to only touch the back.
- **Optimal here:** `std::stack` encodes LIFO in the type (default underlying `deque`).

## Data Structure / Approach Justification
**Chosen:** `std::stack<int>` for a clear LIFO interface.

- **vs raw `vector`:** same asymptotics; stack prevents accidental random access.
- **vs `list`/`deque` directly:** more surface area than needed for pure LIFO.

## Logic Walkthrough
Push four values; print size/top; while not empty, print `top` then `pop`; confirm empty.

## Dry Run
Push 10,20,30,40 → size=4, top=40. Pops: 40,30,20,10. Final size=0, empty=yes.

## Time & Space Complexity
Each op **O(1)** amortized. Space **O(N)** for N elements. Why: adapter end ops on deque/vector (section 4).

## Trade-offs & Alternatives
Prefer `stack` when only LIFO is needed. Use `vector` if you also need random access or iteration.

## Common Mistakes / Edge Cases
Calling `top`/`pop` on empty; expecting `pop` to return a value (it returns `void`).

## Interview Follow-ups / Variations
Implement stack with array; min-stack; queue via two stacks.

## Tags
`stack`, `stl`, `lifo`, `basics`, `difficulty:easy`
