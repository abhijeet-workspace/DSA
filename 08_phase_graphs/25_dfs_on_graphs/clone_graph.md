# Clone Graph

## Problem Statement
[LeetCode 133](https://leetcode.com/problems/clone-graph/) — deep-copy a connected undirected graph given a node reference; return the clone of that node.

- **Inputs:** `Node* node` with `val` and `neighbors`.
- **Output:** root of an isomorphic copy (new nodes, wired neighbors).
- **Valid answer:** structure and values match; no shared node pointers with the original.
- **Edges:** `nullptr`; single node; cycles / diamonds (shared neighbors).

## Intuition
While DFS/BFS walks the original, build a parallel node and remember `original → clone` so cycles reuse the same clone instead of infinite recursion.

## Brute Force → Optimal
- **Brute:** must visit all nodes/edges anyway.
- **Optimal:** hash map + DFS or BFS — **O(V+E)** time, **O(V)** map/stack.

## Data Structure / Approach Justification
**Chosen:** `unordered_map<Node*, Node*>` + recursive DFS.

- **vs BFS queue:** same complexity; avoids deep recursion on long paths.
- **vs two-pass create-then-connect:** clearer separation, more code.

## Logic Walkthrough
Null → null. If `node` in `seen`, return clone. Else create copy, store in `seen`, recurse on neighbors into `copy->neighbors`.

## Dry Run
Cycle `1—2—3—4—1`: clone(1) creates n1′, maps it, clones 2 and 4 into neighbors; later edges reuse mapped clones — no infinite loop.

## Time & Space Complexity
Time **O(V+E)**. Space **O(V)**. Why: one clone + map entry per vertex (section 4).

## Trade-offs & Alternatives
DFS is short; BFS preferred for deep/skinny graphs. Freeing clones needs care in production (not shown in demo).

## Common Mistakes / Edge Cases
Shallow-copying neighbor vectors; forgetting memo before recursing; reusing a global map across calls.

## Interview Follow-ups / Variations
Disconnected graph (iterate all starts); copy list with random pointer (138); serialize/deserialize graph.

## Tags
`graph`, `dfs`, `hash-map`, `clone`, `leetcode-133`, `difficulty:medium`
