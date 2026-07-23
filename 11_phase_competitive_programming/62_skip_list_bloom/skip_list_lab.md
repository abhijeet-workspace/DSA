# Skip List Lab

## 1. Problem Statement
Minimal skip list supporting `insert` and `contains`.

- **Inputs:** integer keys.
- **Output:** membership queries.
- **Valid answer:** contains iff previously inserted (duplicates ignored).
- **Edges:** empty; duplicates; keys near `INT_MIN` sentinel.

## 2. Intuition
Each node gets a random height; higher levels are sparse express lanes. Search drops level by level like a probabilistic BST.

## 3. Brute Force → Optimal
- **Brute:** linear linked list.
- **Skip list:** expected O(log N) search/insert.

## 4. Data Structure / Approach Justification
**Chosen:** fixed `MAXL` levels, coin-flip height, predecessor `update[]` array on insert.

| Alternative | Note |
|-------------|------|
| Treap / RB tree | Deterministic or different randomization |
| `std::set` | Production default |

## 5. Logic Walkthrough
1. Search: from top level, advance while `next->key < key`, then drop.
2. Insert: record predecessors per level; splice new node into levels `[0,h)`.

## 6. Dry Run
Insert 1,3,7; `contains(3)` true; `contains(2)` false.

## 7. Time & Space Complexity
Expected **O(log N)** per op, space **O(N)** with ~2N forward pointers. Why: geometric heights (section 4).

## 8. Trade-offs & Alternatives
Simpler mentally than rotations; worse constants than highly tuned trees. Lab leaks nodes (no destructor).

## 9. Common Mistakes / Edge Cases
Not updating all level pointers; off-by-one on height; infinite loop if comparison wrong.

## 10. Interview Follow-ups / Variations
Delete; range queries; concurrent skip lists.

## 11. Tags
`skip-list`, `probabilistic`, `ordered-set`, `lab`, `difficulty:medium`
