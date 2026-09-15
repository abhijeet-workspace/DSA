# Persistent Treap Split / Merge

## 1. Problem Statement
Maintain versions of a treap: each split/merge/insert creates a new root without destroying old versions.

- **Inputs:** sequence of inserts producing version roots.
- **Output:** membership queries on older versions still valid.
- **Edges:** empty version; query missing key.

## 2. Intuition
Path copying: when rotating/splitting, allocate new nodes along the touched path; share untouched subtrees.

## 3. Brute Force → Optimal
- **Brute:** deep-copy whole tree per update.
- **Persistent:** O(log N) new nodes per op.

## 4. Data Structure / Approach Justification
**Chosen:** immutable nodes with `shared_ptr`-style raw sharing (lab uses indices).

| Alternative | Note |
|-------------|------|
| Persistent segtree | For arrays/order stats |
| Fat nodes | Different persistence model |

## 5. Logic Walkthrough
1. `merge`/`split` allocate new parents.
2. Store root id per version.
3. `find` walks a chosen root.

## 6. Dry Run
Insert 1,2,3 as versions; erase on v3; v2 still contains erased key.

## 7. Time & Space Complexity
Expected **O(log N)** time/space per update.

## 8. Trade-offs & Alternatives
Memory grows with versions; GC needed in production.

## 9. Common Mistakes / Edge Cases
Mutating shared children in place; non-random priorities.

## 10. Interview Follow-ups / Variations
Implicit keys; range reverse persistence.

## 11. Tags
`persistent`, `treap`, `path-copying`, `difficulty:hard`
