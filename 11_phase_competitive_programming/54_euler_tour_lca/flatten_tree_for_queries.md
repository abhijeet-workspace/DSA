# Flatten Tree for Queries

## 1. Problem Statement
Teaching-lab — Euler **enter-only** flatten: subtree ↔ contiguous subarray of `flat`.

## 2. Intuition
Enables reducing subtree problems to array range problems.

## 3. Brute Force → Optimal
- Explicit recursion. Flatten + segtree is CP default.

## 4. Data Structure / Approach Justification
**Chosen:** in/out indices + flat order.

**Pedagogy:** framed for **Euler tour / LCA query machinery** (in/out times, RMQ, binary lifting). Tree-DFS topic may cover recursive LC 236; here we build CP-style offline/online tree query tools.

## 5. Logic Walkthrough
DFS push on enter; out=last index in subtree.

## 6. Dry Run
Subtree(1) contains {1,3,4} contiguously.

## 7. Time & Space Complexity
**O(n)**.

## 8. Trade-offs & Alternatives
Full enter-exit tour for path RMQ LCA.

## 9. Common Mistakes / Edge Cases
Using out exclusive incorrectly.

## 10. Interview Follow-ups / Variations
Path queries need LCA extras.

## 11. Tags
`euler-tour`, `flatten`, `teaching-lab`, `difficulty:easy`

