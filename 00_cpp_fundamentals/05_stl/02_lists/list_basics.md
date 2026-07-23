# STL Lists

## 1. Problem Statement
Demonstrate `std::list` (doubly linked) and `std::forward_list` (singly linked): end ops, bidirectional vs forward traversal, insert/remove, `insert_after`.

- **Input:** none
- **Output:** traversals and post-mutation contents
- **Valid answer:** list supports `push_front`/`back` and reverse iterators; forward_list has no `size`/`back` in this demo path
- **Edges:** no random indexing `l[i]`; `remove` deletes all matching values

## 2. Intuition
Linked lists trade contiguous locality for O(1) splice/insert/erase once you hold an iterator. `forward_list` stores only a next pointer (cheaper nodes, forward-only).

## 3. Brute Force → Optimal
- **Brute:** `vector` insert in the middle (O(n) shifts) for every edit.
- **This approach:** list when middle edits dominate and locality is secondary.

## 4. Data Structure / Approach Justification
**Chosen:** `list` + `forward_list` demos side by side.

| Alternative | Why it loses / wins |
|-------------|---------------------|
| `vector` | Best default; cache friendly |
| `deque` | Fast ends; random access |
| Intrusive lists | Max control; more bugs |

## 5. Logic Walkthrough
1. Seed list `{10,20,30}`; push back/front; walk both directions.
2. `advance` to index 2; `insert` 15; `remove(20)`.
3. `forward_list`: `push_front`, `insert_after`, `pop_front`.

## 6. Dry Run
List after ends: `5 10 20 30 40` → insert 15 → `5 10 15 20 30 40` → remove 20 → `5 10 15 30 40`.
Forward: `50 75 100 200 300` → pop_front → `75 100 200 300`.

## 7. Time & Space Complexity
- **Insert/erase given iterator:** O(1) pointer rewires (+ O(n) to find)
- **Traversal / `remove(value)`:** O(n)
- **Space:** O(n) nodes (2 pointers for list, 1 for forward_list)
- Why: non-contiguous nodes

## 8. Trade-offs & Alternatives
- Prefer `vector` unless profiling says otherwise.
- `forward_list` saves memory but loses reverse/`size` convenience.
- Splicing between lists is a list superpower.

## 9. Common Mistakes / Edge Cases
- Expecting `operator[]`
- Invalidating assumptions like vector (iterators to other nodes usually stay valid on insert)
- Using `erase` vs `remove` (value-based) incorrectly
- Advancing past `end`

## 10. Interview Follow-ups / Variations
- Implement LRU with `list` + `unordered_map`
- Compare splice vs vector erase/insert costs
- When `forward_list::before_begin` matters

## 11. Tags
`stl`, `list`, `forward_list`, `difficulty:easy`
