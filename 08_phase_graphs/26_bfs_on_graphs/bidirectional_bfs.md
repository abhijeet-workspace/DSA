# Bidirectional BFS

## 1. Problem Statement
Find the length of the shortest path between `src` and `dst` in an **unweighted** undirected/directed graph by BFS from both ends until frontiers meet.

- **Inputs:** `V`, adjacency list, `src`, `dst`.
- **Output:** hop distance, or `-1` if unreachable.
- **Edges:** `src == dst`; disconnected graph; branching graphs where meeting early saves work.

## 2. Intuition
One-sided BFS explores ~`b^d` nodes. Growing from both ends meets near the middle and explores ~`2·b^(d/2)` — much smaller when branching factor `b` is large.

## 3. Brute Force → Optimal
- **Brute:** plain BFS from `src` — O(V+E).
- **Bidirectional:** same worst-case class, often fewer expansions in practice on large branching.

## 4. Data Structure / Approach Justification
**Chosen:** two queues + two distance maps; expand the smaller frontier each round.

- **vs plain BFS:** same correctness for unweighted shortest path; better when `d` is large.
- **vs Dijkstra:** unnecessary on unit weights.

## 5. Logic Walkthrough
Seed queues at `src`/`dst`. Alternately expand one layer. When a neighbor is already in the other side’s visited set, return `distMine + distOther`.

## 6. Dry Run
Path `0-1-3-4-5`: frontiers meet around node 3 → distance **4**.

## 7. Time & Space Complexity
Time **O(V+E)** worst case; often ~**O(b^(d/2))** expansions. Space **O(V)** for both visited sets.

## 8. Trade-offs & Alternatives
Harder to reconstruct path (need parents from both sides). Prefer when only distance matters or branching is high.

## 9. Common Mistakes / Edge Cases
Forgetting `src == dst`; mixing directed edges incorrectly; not checking meeting on neighbor discovery.

## 10. Interview Follow-ups / Variations
Word Ladder II style meet-in-middle BFS; reconstruct full path; bidirectional Dijkstra.

## 11. Tags
`graph`, `bfs`, `bidirectional-search`, `shortest-path`, `difficulty:medium`
