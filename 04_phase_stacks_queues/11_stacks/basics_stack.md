# Basics Stack

## Problem Statement
Implement a minimal `Stack<T>` on `vector` (`push`/`pop`/`empty`) and demo mutations including capacity shrink.

- **Inputs:** seed `{10,20,30}` then push/pop sequence in `main`.
- **Output:** printed elements and capacity before/after `shrink_to_fit`.
- **Valid answer:** LIFO via `push_back` / `pop_back`.
- **Edges:** `pop` on empty prints a message and no-ops.

## Intuition
A stack is just controlled access to one end of a dynamic array — here the vector back.

## Brute Force → Optimal
- **Naive:** linked list of nodes for every push.
- **This approach:** `vector` back ops — amortized O(1) and cache-friendly.

## Data Structure / Approach Justification
**Chosen:** `vector<T>` as storage (public for teaching encapsulation trade-offs).

- **vs `std::stack`:** STL hides storage; this shows the mechanism.
- **vs `list`:** unnecessary pointer chasing for LIFO-only.

## Logic Walkthrough
Seed three values; push 40,50; pop twice; push 70; print; `shrink_to_fit`; print again.

## Dry Run
Start `[10,20,30]` → push → `[...,40,50]` → pop×2 → `[10,20,30]` → push 70 → `[10,20,30,70]`.

## Time & Space Complexity
`push`/`pop` **O(1)** amortized. Space **O(N)** (+ unused capacity until shrink). Why: vector end ops (section 4).

## Trade-offs & Alternatives
Make `elements` private in real code. Prefer `std::stack` unless teaching internals.

## Common Mistakes / Edge Cases
Popping empty without check; exposing storage so callers bypass `push`/`pop`.

## Interview Follow-ups / Variations
Add `top()`; bound capacity; implement with linked list; compare to `std::stack`.

## Tags
`stack`, `vector`, `template`, `basics`, `difficulty:easy`
