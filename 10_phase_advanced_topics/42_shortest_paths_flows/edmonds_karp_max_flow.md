# Edmonds-Karp Max Flow

## Problem Statement
Maximum s–t flow via Ford–Fulkerson using BFS for shortest residual augmenting paths (Edmonds–Karp).

- **Inputs:** capacity matrix `cap[u][v]`, source `s`, sink `t`.
- **Output:** max flow value.
- **Valid answer:** max flow (= min cut).
- **Edges:** disconnected; zero caps; need reverse residual edges.

## Intuition
Each augmentation pushes bottleneck capacity along a shortest (fewest-edge) residual path. Bounding the number of augmentations yields a polynomial algorithm.

## Brute Force → Optimal
- **Ford–Fulkerson (DFS):** may be slow / depend on path choice.
- **Edmonds–Karp:** O(VE²).
- **Dinic / push-relabel:** faster practical alternatives.

## Data Structure / Approach Justification
**Chosen:** dense residual matrix + BFS parents (clear teaching demo).

- **vs adj-list residual:** better for sparse graphs.
- **vs Dinic:** EK is the usual first interview implementation.

## Logic Walkthrough
BFS from `s` on positive residual caps; if `t` unreachable, stop. Compute bottleneck on parent path; subtract forward, add reverse; add to flow.

## Dry Run
Same network as Dinic demo → successive BFS paths augment until flow 15.

## Time & Space Complexity
Time **O(V·E²)**. Space **O(V²)** for matrix (or O(V+E) with lists). Why: O(VE) augmentations × O(E) BFS (section 4).

## Trade-offs & Alternatives
Simplest correct flow code; slower than Dinic on large instances. Prefer adj-list residual in CP.

## Common Mistakes / Edge Cases
Not updating reverse capacity; mutating original caps without copy when reuse needed.

## Interview Follow-ups / Variations
Reconstruct min cut; bipartite matching; compare with Dinic complexity.

## Tags
`graph`, `max-flow`, `edmonds-karp`, `bfs`, `network-flow`, `difficulty:medium`
