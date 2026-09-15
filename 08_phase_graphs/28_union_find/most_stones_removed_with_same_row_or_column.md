# Most Stones Removed with Same Row or Column

## 1. Problem Statement
[LeetCode 947](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/) — stones on a 2D plane; remove a stone if another shares its row or column. Return max stones removable.

- **Inputs:** `stones` as `[x, y]` pairs (distinct positions).
- **Output:** maximum removals.
- **Edges:** one stone; all isolated; fully connected via shared lines.

## 2. Intuition
You can remove every stone in a connected component except one. Answer = `n - components`. Connect stones that share a row or column (via DSU on row/col nodes).

## 3. Brute Force → Optimal
- **Brute:** O(n²) pairwise unions on stone indices.
- **Optimal:** unite each stone’s row id with column id — O(n α(n)).

## 4. Data Structure / Approach Justification
**Chosen:** DSU on row nodes and offset column nodes; each stone `unite(row, col+OFF)`.

| Alternative | Why skip |
|-------------|---------|
| Explicit stone×stone edges | O(n²); fine for n≤1e3 but heavier |
| DFS on built graph | Same idea; more adjacency code |

## 5. Logic Walkthrough
1. For each stone `(r,c)`, `unite(r, c+OFFSET)`.
2. `components` = connected components among used row/col nodes (= stone groups).
3. Return `n - components`.

## 6. Dry Run
`[[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]`: one big component → remove **5**, leave 1.

## 7. Time & Space Complexity
- **Time:** O(n α(n))
- **Space:** O(n) for DSU map

## 8. Trade-offs & Alternatives
Stone-indexed O(n²) DSU is easier to see “share row/col” but slower.

## 9. Common Mistakes / Edge Cases
Returning `components` instead of `n - components`; colliding row/col ids without offset; empty input.

## 10. Interview Follow-ups / Variations
Min stones left; remove with diagonal also; online insertions.

## 11. Tags
`union-find`, `graph`, `leetcode-947`, `difficulty:medium`
