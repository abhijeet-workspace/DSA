# Kosaraju SCC

## 1. Problem Statement
Classic Kosaraju: find strongly connected components of a directed graph via two DFS passes (graph then transpose) using finishing-time order.

- **Inputs:** `n`, directed edges.
- **Output:** list of components (node groups).
- **Valid answer:** partition into SCCs.
- **Edges:** single nodes; one big SCC; DAG of SCCs.

## 2. Intuition
First DFS finishing order; second DFS on reversed edges processes sinks of the condensation in order, peeling SCCs.

## 3. Brute Force → Optimal
- **Brute:** pairwise reachability O(n(n+E)).
- **Optimal:** Kosaraju/Tarjan O(n+E).

## 4. Data Structure / Approach Justification
**Chosen:** adj + transpose adj + two DFS.

- **vs Tarjan:** one pass with lowlink; Kosaraju is simpler to teach.
- **vs Gabow:** less common in interviews.

## 5. Logic Walkthrough
DFS all nodes recording postorder. Clear visited. Process postorder reverse on transpose; each tree is an SCC.

## 6. Dry Run
Edges forming a 3-cycle plus chain → **3** components.

## 7. Time & Space Complexity
Time **O(n+E)**. Space **O(n+E)**. Why: two DFS passes (section 4).

## 8. Trade-offs & Alternatives
Tarjan for single-pass; condensation DAG for 2-SAT style follow-ups.

## 9. Common Mistakes / Edge Cases
Forgetting transpose; wrong processing order; not resetting visited.

## 10. Interview Follow-ups / Variations
[Critical Connections](https://leetcode.com/problems/critical-connections-in-a-network/) (bridges); 2-SAT; longest path in condensation.

## 11. Tags
`scc`, `kosaraju`, `dfs`, `classic`, `difficulty:hard`
