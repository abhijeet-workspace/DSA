# Centroid Decomposition Path Count

## 1. Problem Statement
CP classic — undirected tree; count unordered pairs with `dist(u,v) == K` using centroid decomposition.

- **Inputs:** tree on `n`, integer `K`.
- **Output:** number of unordered pairs at distance `K`.
- **Valid answer:** each path counted once through its highest centroid.
- **Edges:** `K=0`; star; path.

## 2. Intuition
Every path has a unique highest centroid; at each centroid count depth pairs that sum to `K`.

## 3. Brute Force → Optimal
- **Brute:** BFS from every node — O(N²).
- **Optimal:** CD + depth frequency — O(N log N).

## 4. Data Structure / Approach Justification
**Chosen:** CD with `freq[depth]` queried before merge (avoid same-subtree doubles).

| Alternative | Note |
|-------------|------|
| Rerooting DP | Great for sum-of-distances, less flexible for exact K |
| Binary lifting | Heavier for pure counting |

## 5. Logic Walkthrough
Size live component → centroid → for each subtree collect depths, add `freq[K-d]`, then merge → mark dead → recurse.

## 6. Dry Run
Path `1-2-3-4`, `K=2` → answer `2`.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(N+K)**. Why: O(log N) layers, each node once per layer (section 4).

## 8. Trade-offs & Alternatives
Same skeleton extends to weighted / XOR / constrained path counts.

## 9. Common Mistakes / Edge Cases
Merging before querying; forgetting depth 0 at centroid.

## 10. Interview Follow-ups / Variations
Count `dist ∈ [L,R]`; weighted edges; XOR of edge labels.

## 11. Tags
`centroid-decomposition`, `path-counting`, `tree`, `cp`, `difficulty:hard`
