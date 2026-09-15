# Minimum Number of Vertices to Reach All Nodes

## 1. Problem Statement
[LeetCode 1557](https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/) — directed acyclic graph. Find the smallest set of vertices from which all nodes are reachable.

- **Inputs:** `n`, directed `edges`.
- **Output:** list of start vertices (any valid minimal set; unique here).
- **Valid answer:** all nodes with indegree 0.
- **Edges:** single node; one source; many sources.

## 2. Intuition
In a DAG, every node is reachable from the set of indegree-0 nodes; those must be included, and they suffice.

## 3. Brute Force → Optimal
- **Brute:** try subsets of starts — exponential.
- **Optimal:** collect indegree 0 — O(n+E).

## 4. Data Structure / Approach Justification
**Chosen:** boolean `hasIn` from edge ends.

- **vs full reachability search:** unnecessary given DAG theorem.

## 5. Logic Walkthrough
Mark nodes that appear as edge destinations. Return unmarked nodes.

## 6. Dry Run
Edges create indegrees; nodes 0 and 3 have indegree 0 → `{0,3}`.

## 7. Time & Space Complexity
Time **O(n+E)**. Space **O(n)**. Why: one edge scan (section 4).

## 8. Trade-offs & Alternatives
If cycles exist, need SCCs (condensation sources).

## 9. Common Mistakes / Edge Cases
Returning outdegree 0; including all nodes; ignoring isolated nodes (they have indegree 0).

## 10. Interview Follow-ups / Variations
With cycles; minimum path cover; dominating set (harder).

## 11. Tags
`dag`, `indegree`, `leetcode-1557`, `difficulty:medium`
