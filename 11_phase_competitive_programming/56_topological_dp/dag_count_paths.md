# DAG Count Paths

## 1. Problem Statement
CP classic — count paths from `src` to `sink` on a DAG.

- **Inputs:** DAG, `src`, `sink`.
- **Output:** number of directed paths.
- **Edges:** `src=sink` → 1; unreachable → 0.

## 2. Intuition
`ways[v] += ways[u]` for edges `u→v` in topological order; seed `ways[src]=1`.

## 3. Brute Force → Optimal
- **Brute:** DFS enumerate.
- **Optimal:** topo DP O(V+E).

## 4. Data Structure / Approach Justification
**Chosen:** Kahn + `ways[]`.

| Alternative | Note |
|-------------|------|
| DFS memo | Same |
| Matrix powers | Dense overkill |

## 5. Logic Walkthrough
Topo process; accumulate ways along edges.

## 6. Dry Run
Diamond `1→2→4`, `1→3→4` → `2`.

## 7. Time & Space Complexity
Time **O(V+E)**. Space **O(V)**.

## 8. Trade-offs & Alternatives
Add modulo for contest constraints.

## 9. Common Mistakes / Edge Cases
Seeding all sources with 1 (wrong unless counting from any source).

## 10. Interview Follow-ups / Variations
Count paths of length exactly L.

## 11. Tags
`dag`, `path-counting`, `topological-dp`, `cp`, `difficulty:easy`
