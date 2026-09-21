# deque

## 1. Problem Statement
Demonstrate `std::deque`: efficient `push_front`/`push_back`, `pop_front`/`pop_back`, indexing, and a middle insert.

- **Input:** none
- **Output:** sequence evolution `10 20 30` → `20` → `20 99`
- **Valid answer:** front and back ops are amortized O(1); middle insert is linear
- **Edges:** `front`/`back` on empty deque is UB

## 2. Intuition
A deque (double-ended queue) is for workloads that grow/shrink on **both** ends. Vector is weak at `push_front`.

## 3. Brute Force → Optimal
- **Naive:** `vector` + `insert(begin, ...)` for front pushes (O(n) each).
- **This approach:** `deque` when both ends matter; `vector` when mostly back growth + random access locality matters more.

## 4. Data Structure / Approach Justification
**Chosen:** `std::deque<int>`.

| Alternative | Why it loses / wins |
|-------------|---------------------|
| `vector` | Best contiguous cache locality; slow front inserts |
| `list` | O(1) splice; no random-access `[]` |
| `queue` adapter | Restricts interface on purpose |

## 5. Logic Walkthrough
1. `push_back` 20,30 then `push_front` 10.
2. Read front/back and `d[1]`.
3. Pop both ends.
4. Insert near the middle.

## 6. Dry Run
| Op | deque |
|----|-------|
| push_back 20,30 | 20 30 |
| push_front 10 | 10 20 30 |
| pop_front+pop_back | 20 |
| insert at begin+1 | 20 99 |

## 7. Time & Space Complexity
- **push/pop ends:** amortized O(1)
- **operator[]:** O(1)
- **insert middle:** O(n)
- **Space:** O(n) (chunked blocks; not one contiguous allocation)
- Why: blocked storage enables cheap ends

## 8. Trade-offs & Alternatives
- Prefer `vector` for mostly-append + tight iteration.
- Prefer `deque` for sliding windows / both-end queues.
- Prefer adapters (`queue`/`stack`) when you want a restricted API.

## 9. Common Mistakes / Edge Cases
- Assuming deque stores one contiguous block like vector
- Calling `front` on empty deque
- Using deque when vector locality would dominate performance

## 10. Interview Follow-ups / Variations
- How is deque typically implemented (chunks + map)?
- Iterator invalidation differences vs vector?
- When is `deque` the default underlying container for `stack`/`queue`?

## 11. Tags
`stl`, `deque`, `containers`, `beginner`
