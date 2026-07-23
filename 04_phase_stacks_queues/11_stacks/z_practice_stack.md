# Practice Stack

## Problem Statement
Scratchpad: a minimal `Stack<T>` on `vector` for practice drills (extend with `top()`, private storage, tests).

- **Inputs:** demo pushes 1,2,3 in `main`.
- **Output:** LIFO print `3 2 1`.
- **Valid answer:** back-of-vector as top.
- **Edges:** `pop` on empty prints and returns.

## Intuition
Same LIFO mechanics as `basics_stack` — intentional duplicate skeleton for exercises without editing the lesson file.

## Brute Force → Optimal
- **Naive:** reimplement with linked nodes for every drill.
- **This:** reuse vector-backed template and grow the API yourself.

## Data Structure / Approach Justification
**Chosen:** public `vector<T>` stack (teaching/practice).

- **vs editing `basics_stack`:** keeps lesson file stable.
- **vs `std::stack`:** hides the storage you’re meant to practice on.

## Logic Walkthrough
Push 1,2,3; while not empty, print `back()`, pop.

## Dry Run
`[1,2,3]` → print 3,2,1 → empty.

## Time & Space Complexity
Ops **O(1)** amortized. Space **O(N)**. Why: vector end operations (section 4).

## Trade-offs & Alternatives
Graduate to private `elements` + `top()`; then switch drills to `std::stack`.

## Common Mistakes / Edge Cases
Accessing `back()` when empty; forgetting to pop after reading top.

## Interview Follow-ups / Variations
Add `top()`; min-stack on this skeleton; match parentheses using it.

## Tags
`stack`, `practice`, `vector`, `template`, `difficulty:easy`
