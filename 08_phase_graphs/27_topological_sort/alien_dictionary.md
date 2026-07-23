# Alien Dictionary

## Problem Statement
[LeetCode 269](https://leetcode.com/problems/alien-dictionary/) (premium) — `words` is sorted in an unknown alien alphabet; return any valid letter order, or `""` if impossible.

- **Inputs:** `vector<string> words`.
- **Output:** string of unique letters in a valid order, or `""`.
- **Valid answer:** any topo order of the precedence graph (unless asked for lex-smallest).
- **Edges:** prefix invalid (`"apple"` before `"app"`); cycle; single word; unused letters must still appear.

## Intuition
Compare consecutive sorted words: first differing chars `u` then `v` imply edge `u → v` (u before v). Kahn topo sort yields an order iff the graph is a DAG.

## Brute Force → Optimal
- **Brute:** try all permutations of unique letters — O(U!).
- **Optimal:** build precedence graph + Kahn (or DFS) — O(C) in total characters.

## Data Structure / Approach Justification
**Chosen:** adjacency sets + indegree map + BFS queue (Kahn).

- **vs DFS postorder:** same asymptotics; Kahn makes cycle detection via size check obvious.
- **vs comparing all pairs:** consecutive pairs already encode the full order constraints.

## Logic Walkthrough
Init indegree for every letter. For each consecutive pair, find first mismatch → add edge once. Seed queue with indegree 0. Pop and append; decrease neighbors. If `|order| < |letters|`, cycle → `""`.

## Dry Run
`["wrt","wrf","er","ett","rftt"]`:
- `wrt`/`wrf` → `t→f`; `wrf`/`er` → `w→e`; `er`/`ett` → `r→t`; `ett`/`rftt` → `e→r`
- Kahn can produce `wertf`

## Time & Space Complexity
Time **O(C)**. Space **O(U + E)** for letters and edges. Why: each char and each precedence edge processed once (section 4).

## Trade-offs & Alternatives
Any valid order is OK on LeetCode. Use a min-heap instead of queue for lexicographically smallest. DFS finishing-time reverse is equivalent.

## Common Mistakes / Edge Cases
Skipping prefix check; only comparing non-consecutive words; forgetting letters with no edges in indegree init; duplicate edges double-counting indegree.

## Interview Follow-ups / Variations
Unique order? Lex-smallest order? Verify a candidate alphabet. Unicode / large alphabets.

## Tags
`graph`, `topological-sort`, `kahn`, `leetcode-269`, `difficulty:hard`
