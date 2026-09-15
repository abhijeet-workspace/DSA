# Hopcroft–Karp Demo on Grid

## 1. Problem Statement
Teaching lab — run Hopcroft–Karp on a small complete bipartite graph motivated by checkerboard grid adjacency (black↔white).

- **Inputs:** left/right parts + edges (encoded in code).
- **Output:** matching size.
- **Edges:** empty; perfect matching.

## 2. Intuition
Layered BFS + multi-DFS phases; grid bipartition is the natural left/right split.

## 3. Brute Force → Optimal
- **Brute:** Kuhn O(VE).
- **HK:** O(E√V).

## 4. Data Structure / Approach Justification
**Chosen:** classic HK with NIL sentinel.

| Alternative | Note |
|-------------|------|
| Dinic unit network | Same complexity class |

## 5. Logic Walkthrough
While BFS finds free right at finite dist: DFS augment along layers.

## 6. Dry Run
`K_{2,2}` → matching `2`.

## 7. Time & Space Complexity
Time **O(E√V)**. Space **O(V+E)**.

## 8. Trade-offs & Alternatives
Concrete visualization for the existing `hopcroft_karp` template.

## 9. Common Mistakes / Edge Cases
Broken distance checks; 0-index without NIL.

## 10. Interview Follow-ups / Variations
Max matching on larger grids; forbidden cells.

## 11. Tags
`hopcroft-karp`, `grid`, `teaching`, `difficulty:medium`
