# Build a Matrix With Conditions

## 1. Problem Statement
[LeetCode 2392](https://leetcode.com/problems/build-a-matrix-with-conditions/) — place numbers `1..k` in a `k×k` matrix (others 0). `rowConditions`/`colConditions` pairs `[above,below]` / `[left,right]` must hold. Return any valid matrix or empty if impossible.

- **Inputs:** `k`, row/col condition lists.
- **Output:** matrix or `[]`.
- **Valid answer:** positions respect both topo orders.
- **Edges:** cycles → impossible; no conditions.

## 2. Intuition
Topologically order numbers for rows and for columns separately. Place number `x` at `(rowIndex[x], colIndex[x])`.

## 3. Brute Force → Optimal
- **Brute:** try permutations — factorial.
- **Optimal:** two Kahns O(k+E).

## 4. Data Structure / Approach Justification
**Chosen:** Kahn topo for rows and cols + position maps.

- **vs DFS topo:** same; cycle detection required.

## 5. Logic Walkthrough
Topo row conditions → row order. Topo col → col order. If either incomplete, fail. Fill matrix.

## 6. Dry Run
`k=3` sample yields a valid 3×3 placement of 1..3.

## 7. Time & Space Complexity
Time **O(k² + E)** (fill matrix). Space **O(k²)**. Why: topo + grid (section 4).

## 8. Trade-offs & Alternatives
Any linear extension works; queue order may vary.

## 9. Common Mistakes / Edge Cases
Not detecting cycles; 0-index vs 1..k labels; overwriting cells.

## 10. Interview Follow-ups / Variations
Alien dictionary; sequence reconstruction; 2D constraints.

## 11. Tags
`topological-sort`, `matrix`, `leetcode-2392`, `difficulty:hard`
