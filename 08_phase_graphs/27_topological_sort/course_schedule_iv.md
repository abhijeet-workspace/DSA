# Course Schedule IV

## Problem Statement
[LeetCode 1462](https://leetcode.com/problems/course-schedule-iv/) — given prereqs `[a,b]` meaning `a` is a prerequisite of `b` (edge `a→b`), answer queries: is `u` a (direct or indirect) prerequisite of `v`?

- **Inputs:** `numCourses`, `prerequisites`, `queries`.
- **Output:** `vector<bool>` per query.
- **Valid answer:** reachability in the directed prereq graph.
- **Edges:** no edges; disconnected; long chains.

## Intuition
Precompute transitive closure / reachability once, then O(1) per query. Graph is a DAG in valid course graphs but algorithm works generally for reachability.

## Brute Force → Optimal
- **Brute:** DFS/BFS per query — O(Q·(V+E)).
- **Optimal:** Floyd boolean closure O(V³), or DFS from each node filling reach matrix O(V·(V+E)).

## Data Structure / Approach Justification
**Chosen:** DFS from each source into `reach[u][v]` with neighbor-union of reach sets.

- **vs Floyd-Warshall bool:** simple O(V³); good when V small (≤100).
- **vs per-query DFS:** fine for few queries, poor for many.

## Logic Walkthrough
Build `a→b`. For each start `i`, DFS and mark all descendants in `reach[i][*]`. Answer `reach[u][v]` for each query.

## Dry Run
Edges `1→2`, `1→0`, `2→0`: `1` reaches `0` and `2` → queries `[1,0]`, `[1,2]` both true.

## Time & Space Complexity
Time **O(V·(V+E) + Q)** DFS-from-each (or **O(V³+Q)** Floyd). Space **O(V²)** reach matrix. Why: closure stored explicitly (section 4).

## Trade-offs & Alternatives
Floyd is shortest to code. Bitsets accelerate row ORs. Topo DP: process in order and OR reachability from predecessors.

## Common Mistakes / Edge Cases
Reversing edge meaning; answering only direct edges; assuming undirected.

## Interview Follow-ups / Variations
Return one prereq chain; count prereqs per course; Course Schedule I/II.

## Tags
`graph`, `reachability`, `transitive-closure`, `dfs`, `leetcode-1462`, `difficulty:medium`
