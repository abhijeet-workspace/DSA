# Satisfiability of Equality Equations

## Problem Statement
[LeetCode 990](https://leetcode.com/problems/satisfiability-of-equality-equations/) — equations on variables `a`–`z` of form `xi==xj` or `xi!=xj`. Return whether all can be true simultaneously.

- **Inputs:** `vector<string> equations` each length 4.
- **Output:** `bool`.
- **Valid answer:** true iff no contradiction.
- **Edges:** only `==`; only `!=`; `a==a`; `a!=a`.

## Intuition
Equality is an equivalence relation → Union-Find. Process all `==` first, then each `!=` fails if both sides share a root.

## Brute Force → Optimal
- **Brute:** try assignments — 26! nonsense.
- **Optimal:** DSU — **O(e α(26))**.

## Data Structure / Approach Justification
**Chosen:** 26-node DSU; two-pass (equals then unequals).

- **vs graph coloring / bipartition:** wrong model (not 2-SAT lite without care).
- **vs one pass interleaved:** can reject too early before all equalities merge.

## Logic Walkthrough
Unite all `==`. For each `!=`, if `find(x)==find(y)` → false. Else true.

## Dry Run
`a==b`, `b!=a`: after unite, `!=` same root → false.  
`a==b`, `b==c`, `a==c`: consistent → true.

## Time & Space Complexity
Time **O(e α(26))**. Space **O(1)** (26 parents). Why: alphabet fixed (section 4).

## Trade-offs & Alternatives
Build adjacency for `==` and BFS components — same idea.

## Common Mistakes / Edge Cases
Checking `!=` before all unions; `a!=a` immediately false; ignoring that `==` is transitive.

## Interview Follow-ups / Variations
Variables beyond 26; weighted equalities; 2-SAT with OR constraints.

## Tags
`union-find`, `equality`, `leetcode-990`, `difficulty:medium`
