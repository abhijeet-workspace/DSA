# Beam Search

## 1. Problem Statement
Search a large combinatorial space while keeping only the **top K** partial solutions (the beam) at each expansion step — common in NLP decoding and heuristic search.

- **Inputs:** sequence length, beam width `K`, scoring rule.
- **Output:** best complete candidate under the heuristic score (not necessarily globally optimal).
- **Edges:** `K=1` (greedy); `K` huge (approaches BFS/exhaustive).

## 2. Intuition
Full BFS/DFS explodes. Beam search prunes aggressively: expand all beam members, score children, keep only the best `K`.

## 3. Brute Force → Optimal
- **Brute:** explore all `Σ^L` strings.
- **Beam:** time ~ O(L · K · |Σ|) with pruning — approximate.

## 4. Data Structure / Approach Justification
**Chosen:** vector of `(path, score)` candidates, sort & truncate each layer.

- **vs BFS:** BFS keeps entire frontier; beam caps it at `K`.
- **vs A*:** A* is optimal with admissible `h`; beam is a bounded-width heuristic and may miss the optimum.

## 5. Logic Walkthrough
Start with empty path. For each position, expand every beam item by each alphabet symbol, score, keep top `K`. Return best finished path.

## 6. Dry Run
Length 5, `K=3`, toy score favoring early `'a'` / late `'b'` → beam retains high-scoring prefixes and emits one best string.

## 7. Time & Space Complexity
Time **O(L · K · |Σ| · cost(sort))** (or better with partial select). Space **O(K · L)**.

## 8. Trade-offs & Alternatives
Not optimal. Increase `K` for quality; use exact search (DP/A*) when the state space is manageable.

## 9. Common Mistakes / Edge Cases
Confusing beam width with depth; assuming optimality; `K=0`.

## 10. Interview Follow-ups / Variations
Sequence decoding (CTC/attention); diverse beam search; comparison to Viterbi.

## 11. Tags
`beam-search`, `heuristic`, `nlp`, `pruning`, `difficulty:medium`
