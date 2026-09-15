# Hungarian Assignment (Small)

## 1. Problem Statement
Teaching lab — minimum-cost assignment on an `n×n` cost matrix (small `n` via permutations; Hungarian conceptually in §4).

- **Inputs:** square cost matrix.
- **Output:** minimum assignment cost.
- **Edges:** zeros; already diagonal optimal.

## 2. Intuition
Bijection workers→jobs minimizing sum of costs; classical Hungarian / min-cost matching.

## 3. Brute Force → Optimal
- **Brute:** n! (this demo).
- **Hungarian:** O(n³).

## 4. Data Structure / Approach Justification
**Chosen:** permutation search for verifiable tiny instances.

| Alternative | Note |
|-------------|------|
| Kuhn-Munkres | Production |
| Successive shortest paths | Min-cost flow |

## 5. Logic Walkthrough
Enumerate permutations; track min sum `cost[i][p[i]]`.

## 6. Dry Run
Matrix `[[9,2,7],[6,4,3],[5,8,1]]` → min `10` (2+3+5).

## 7. Time & Space Complexity
Time **O(n·n!)** demo / **O(n³)** Hungarian. Space **O(n²)**.

## 8. Trade-offs & Alternatives
Use real Hungarian when n grows past ~10.

## 9. Common Mistakes / Edge Cases
Allowing non-square without padding; maximizing instead of minimizing.

## 10. Interview Follow-ups / Variations
LC 1947 / 1066 as max-score variants.

## 11. Tags
`hungarian`, `assignment`, `teaching`, `difficulty:medium`
