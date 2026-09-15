# Path with Maximum Probability

## 1. Problem Statement
[LeetCode 1514](https://leetcode.com/problems/path-with-maximum-probability/) — undirected edges with success probabilities. Return maximum probability of a path from `start` to `end` (product of edge probs), or 0 if none.

- **Inputs:** `n`, `edges`, `succProb`, `start`, `end`.
- **Output:** double probability.
- **Valid answer:** maximise product ≡ Dijkstra with multiplicative relax.
- **Edges:** disconnected; single edge; tiny probs.

## 2. Intuition
Dijkstra variant: maximize probability (max-heap), relax with multiplication instead of addition.

## 3. Brute Force → Optimal
- **Brute:** enumerate paths.
- **Optimal:** modified Dijkstra O((n+E) log n).

## 4. Data Structure / Approach Justification
**Chosen:** max-heap Dijkstra on probability.

- **vs log transform + min cost:** numerically different but same idea.
- **vs Bellman-Ford:** slower.

## 5. Logic Walkthrough
best[start]=1. PQ pops highest prob; multiply edge probs to improve neighbors.

## 6. Dry Run
Sample 0→1→2 with 0.5*0.5 → **0.25** beats direct 0.2.

## 7. Time & Space Complexity
Time **O((n+E) log n)**. Space **O(n+E)**. Why: Dijkstra (section 4).

## 8. Trade-offs & Alternatives
Use logs to avoid underflow on long paths.

## 9. Common Mistakes / Edge Cases
Adding probs; min-heap without negating; missing undirected reverse edges.

## 10. Interview Follow-ups / Variations
Network delay; cheapest flights; exchange rates (evaluate division).

## 11. Tags
`dijkstra`, `probability`, `leetcode-1514`, `difficulty:medium`
