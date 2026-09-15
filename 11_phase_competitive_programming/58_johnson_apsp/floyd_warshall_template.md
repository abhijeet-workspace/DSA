# Floyd–Warshall Template

## 1. Problem Statement
CP classic — all-pairs shortest paths on a dense digraph; detect negative cycles via `d[i][i]<0`.

- **Inputs:** `n`, weighted directed edges.
- **Output:** `dist[][]`; neg-cycle flag.
- **Edges:** disconnected INF; zero-weight.

## 2. Intuition
`d[i][j] = min(d[i][j], d[i][k]+d[k][j])` for all k as intermediate.

## 3. Brute Force → Optimal
- **Brute:** V×Bellman–Ford.
- **Floyd:** O(V³) always.

## 4. Data Structure / Approach Justification
**Chosen:** adjacency matrix DP.

| Alternative | Note |
|-------------|------|
| Johnson | Better sparse |
| V×Dijkstra | Nonnegative only |

## 5. Logic Walkthrough
Init edges; triple loop k,i,j; check diagonal.

## 6. Dry Run
`0→1(1),1→2(-1),0→2(3)` → `d[0][2]=0`.

## 7. Time & Space Complexity
Time **O(V³)**. Space **O(V²)**.

## 8. Trade-offs & Alternatives
Prefer when V≤400 dense; else Johnson.

## 9. Common Mistakes / Edge Cases
Overflow without INF guards; missing `i→i=0`.

## 10. Interview Follow-ups / Variations
Path reconstruction via `next[i][j]`.

## 11. Tags
`floyd-warshall`, `apsp`, `cp`, `difficulty:medium`
