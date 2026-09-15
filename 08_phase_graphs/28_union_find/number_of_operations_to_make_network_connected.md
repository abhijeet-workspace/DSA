# Number of Operations to Make Network Connected

## Problem Statement
[LeetCode 1319](https://leetcode.com/problems/number-of-operations-to-make-network-connected/) — `n` computers, undirected cables. One operation moves a cable between any two machines. Return min operations to make all connected, or `-1`.

- **Inputs:** `n`, `connections` as `[a,b]`.
- **Output:** min moves, or `-1`.
- **Valid answer:** `components - 1` if enough cables (`|E| ≥ n-1`).
- **Edges:** already connected; tree; too few edges.

## Intuition
Connecting `c` components needs `c-1` edges. Redundant edges inside components can be relocated. If total edges `< n-1`, impossible.

## Brute Force → Optimal
- **Brute:** search moves — unnecessary.
- **Optimal:** DSU count components + edge count check — **O(n + e)**.

## Data Structure / Approach Justification
**Chosen:** DSU; answer `components-1` when `|E|≥n-1`.

- **vs DFS count components:** same idea.
- **vs tracking `extra` explicitly:** optional; `|E|≥n-1` already implies enough spares globally.

## Logic Walkthrough
If `connections.size() < n-1` → `-1`. Union all edges. Return `components - 1`.

## Dry Run
`n=4`, edges form triangle on `{0,1,2}` and isolated `3`: 2 components → `1` operation.

## Time & Space Complexity
Time **O(n + e)** with α. Space **O(n)**. Why: one pass unions (section 4).

## Trade-offs & Alternatives
Count extras if you want a local “spare cables” story; globally `|E|≥n-1` suffices.

## Common Mistakes / Edge Cases
Returning `extra` instead of `components-1`; forgetting impossibility when too few cables.

## Interview Follow-ups / Variations
Min cost to connect (MST). Redundant connection. Critical edges.

## Tags
`union-find`, `connected-components`, `graph`, `leetcode-1319`, `difficulty:medium`
