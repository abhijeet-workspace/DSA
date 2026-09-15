# Persistent / Rollback DSU (Time-Travel)

## 1. Problem Statement
Disjoint Set Union with rollback: unite with undo stack so you can restore prior connectivity (time-travel / DFS-on-timeline).

- **Inputs:** unite ops; rollback to earlier state; same-set queries.
- **Output:** connectivity consistent with partial op prefix.
- **Edges:** unite already-connected; rollback to empty.
- **Note:** Fully persistent DSU is rarer; rollback DSU is the CP workhorse.

## 2. Intuition
Store parent/size changes on a stack; undo pops reverse the last unite.

## 3. Brute Force → Optimal
- **Brute:** rebuild DSU from scratch.
- **Rollback:** O(α(N)) unite + O(1) undo amortized with care.

## 4. Data Structure / Approach Justification
**Chosen:** union by size + explicit rollback stack (no path compression, or compress with undo).

| Alternative | Note |
|-------------|------|
| Path copying DSU | Heavier |
| Offline segment-tree on time | Another CP pattern |

## 5. Logic Walkthrough
1. `find` without persistent compression (or undoable).
2. `unite` pushes changed parents/sizes.
3. `rollback(k)` undoes until stack size k.

## 6. Dry Run
Unite(1,2), Unite(2,3); rollback one → 1 connected 2, not 3.

## 7. Time & Space Complexity
Almost **O(1)** per op without compression; with undoable compression still fine for CP.

## 8. Trade-offs & Alternatives
No path compression simplifies rollback.

## 9. Common Mistakes / Edge Cases
Path compression without undo; forgetting size updates.

## 10. Interview Follow-ups / Variations
Dynamic graph connectivity offline; DSU on tree.

## 11. Tags
`dsu`, `rollback`, `persistent-adjacent`, `difficulty:hard`
