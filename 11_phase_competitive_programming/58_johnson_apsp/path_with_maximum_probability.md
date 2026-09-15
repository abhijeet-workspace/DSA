# Path with Maximum Probability

## 1. Problem Statement
[LeetCode 1514](https://leetcode.com/problems/path-with-maximum-probability/) — maximize product of success probabilities along a path.

- **Inputs:** undirected edges with probabilities, start, end.
- **Output:** max probability (0 if unreachable).
- **Edges:** no path; single edge.

## 2. Intuition
Dijkstra-like with max-heap on probability; multiply edge weights. Equivalent to shortest path on `-log(p)`.

## 3. Brute Force → Optimal
- **Brute:** enumerate paths.
- **Optimal:** modified Dijkstra O(E log V).

## 4. Data Structure / Approach Justification
**Chosen:** max-probability PQ search.

| Alternative | Note |
|-------------|------|
| -log + Dijkstra | Numerically stable |
| Bellman–Ford | Also fine |

## 5. Logic Walkthrough
Start prob 1; relax if `p*w` improves.

## 6. Dry Run
Sample → `0.25`.

## 7. Time & Space Complexity
Time **O(E log V)**. Space **O(V+E)**.

## 8. Trade-offs & Alternatives
Shows multiplicative weights ↔ additive via logs (APSP-related).

## 9. Common Mistakes / Edge Cases
Adding probabilities; using min-heap wrongly.

## 10. Interview Follow-ups / Variations
At most k edges; APSP of max products.

## 11. Tags
`leetcode-1514`, `dijkstra`, `probability`, `difficulty:medium`
