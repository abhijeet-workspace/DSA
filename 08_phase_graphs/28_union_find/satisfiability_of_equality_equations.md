# Satisfiability of Equality Equations

## 1. Problem Statement
[LeetCode 990](https://leetcode.com/problems/satisfiability-of-equality-equations/) — equations on variables `a`–`z` of form `xi==xj` or `xi!=xj`. Return whether all can be true simultaneously.

- **Inputs:** `vector<string> equations` each length 4.
- **Output:** `bool`.
- **Valid answer:** true iff no contradiction.
- **Edges:** only `==`; only `!=`; `a==a`; `a!=a`.

## 2. Intuition
Equality is an equivalence relation → Union-Find. Process all `==` first, then each `!=` fails if both sides share a root.

## 3. Brute Force → Optimal
- **Brute:** try assignments — 26! nonsense.
- **Optimal:** DSU — **O(e α(26))**.

## 4. Data Structure / Approach Justification
**Chosen:** 26-node DSU; two-pass (equals then unequals).

- **vs graph coloring / bipartition:** wrong model (not 2-SAT lite without care).
- **vs one pass interleaved:** can reject too early before all equalities merge.

## 5. Logic Walkthrough
Unite all `==`. For each `!=`, if `find(x)==find(y)` → false. Else true.

## 6. Dry Run
`a==b`, `b!=a`: after unite, `!=` same root → false.  
`a==b`, `b==c`, `a==c`: consistent → true.

## 7. Time & Space Complexity
Time **O(e α(26))**. Space **O(1)** (26 parents). Why: alphabet fixed (section 4).

## 8. Trade-offs & Alternatives
Build adjacency for `==` and BFS components — same idea.

## 9. Common Mistakes / Edge Cases
Checking `!=` before all unions; `a!=a` immediately false; ignoring that `==` is transitive.

## 10. Interview Follow-ups / Variations
Variables beyond 26; weighted equalities; 2-SAT with OR constraints.

## 11. Tags
`union-find`, `equality`, `leetcode-990`, `difficulty:medium`
