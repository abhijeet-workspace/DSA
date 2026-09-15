# Two-SAT Template

## 1. Problem Statement
Teaching-lab — 2-SAT via implication graph + strongly connected components. Demo forces `x0=true`, `x1=false`.

## 2. Intuition
`(a∨b)` ⇒ `(¬a⇒b)` and `(¬b⇒a)`. Unsat iff `x` and `¬x` share an SCC.

## 3. Brute Force → Optimal
- **Brute:** try 2^n. **Optimal:** O(n+m) Kosaraju/Tarjan 2-SAT.

## 4. Data Structure / Approach Justification
**Chosen:** Kosaraju 2-SAT.

**Pedagogy:** contest skeleton / teaching-lab — paste-ready CP snippet. Not a full contest statement; demos prove the template compiles and solves a tiny case. Full DS deep-dives live in Fenwick/SegTree/graph topics.

## 5. Logic Walkthrough
Build implications; SCC; assign by component order.

## 6. Dry Run
Clauses force x0 and ¬x1 → assignment 10.

## 7. Time & Space Complexity
Time **O(n+m)**. Space **O(n+m)**.

## 8. Trade-offs & Alternatives
Tarjan SCC; AtCoder Library `two_sat`.

## 9. Common Mistakes / Edge Cases
Wrong literal indexing; forgetting both implications.

## 10. Interview Follow-ups / Variations
Graph coloring reductions; scheduling.

## 11. Tags
`2-sat`, `scc`, `template`, `difficulty:hard`
