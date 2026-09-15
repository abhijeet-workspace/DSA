# Subtree Update Euler

## 1. Problem Statement
Teaching-lab — **subtree add** by range-updating `[in[u], out[u]]` on Euler times (Fenwick diff).

## 2. Intuition
Subtree = contiguous Euler segment for enter-only times.

## 3. Brute Force → Optimal
- DFS recompute. Euler+BIT O(log n) updates.

## 4. Data Structure / Approach Justification
**Chosen:** in/out + Fenwick range-add/point-query.

**Pedagogy:** framed for **Euler tour / LCA query machinery** (in/out times, RMQ, binary lifting). Tree-DFS topic may cover recursive LC 236; here we build CP-style offline/online tree query tools.

## 5. Logic Walkthrough
DFS times; rangeAdd subtree; point query via prefix.

## 6. Dry Run
Add 5 under node 1 → nodes 1 and 3 get 5; 2 stays 0.

## 7. Time & Space Complexity
**O(n)** build; **O(log n)** update/query.

## 8. Trade-offs & Alternatives
Related `subtree_sum_euler_fenwick` already in folder.

## 9. Common Mistakes / Edge Cases
Mixing enter-exit timer schemes.

## 10. Interview Follow-ups / Variations
Path updates via rerooting tricks.

## 11. Tags
`euler-tour`, `fenwick`, `teaching-lab`, `difficulty:medium`

