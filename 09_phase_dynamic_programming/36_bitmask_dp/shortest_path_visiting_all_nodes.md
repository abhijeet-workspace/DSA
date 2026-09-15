# Shortest Path Visiting All Nodes

## Problem Statement
[LeetCode 847](https://leetcode.com/problems/shortest-path-visiting-all-nodes/) — shortest path length that visits every node (may revisit).

- **Inputs:** undirected `graph` adjacency list.
- **Output:** min path length (edges).
- **Valid answer:** BFS on (node, visited_mask).
- **Edges:** n=1; complete graph.

## Intuition
State is (current node, bitmask of visited); BFS for shortest.

## Brute Force → Optimal
- **Brute:** permutations with revisits hard.
- **Optimal:** BFS O(N^2 * 2^N).

## Data Structure / Approach Justification
**Chosen:** queue + seen[node][mask].

## Logic Walkthrough
Start from all nodes; stop when mask full.

## Dry Run
graph=[[1,2,3],[0],[0],[0]] -> **4**.

## Time & Space Complexity
Time **O(N^2*2^N)**. Space **O(N*2^N)**. Why: states (section 4).

## Trade-offs & Alternatives
Classic TSP-path bitmask BFS.

## Common Mistakes / Edge Cases
Not allowing revisits; starting from one node only.

## Interview Follow-ups / Variations
TSP teaching; Find Shortest Superstring.

## Tags
`bitmask-dp`, `bfs`, `leetcode-847`, `difficulty:hard`
