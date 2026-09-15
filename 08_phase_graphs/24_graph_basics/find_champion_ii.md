# Find Champion II

## 1. Problem Statement
[LeetCode 2924](https://leetcode.com/problems/find-champion-ii/) — `n` teams `0..n-1`. Edge `u→v` means `u` is stronger than `v`. A champion is stronger than every other team (possibly indirectly). Return the champion if unique, else `-1`.

- **Inputs:** `n`, directed `edges`.
- **Output:** champion id or -1.
- **Valid answer:** unique indegree-0 node in the DAG of comparisons (problem guarantees a DAG-like tournament structure usable via indegree).
- **Edges:** one team; multiple sources; chain.

## 2. Intuition
Only a team with indegree 0 can be undefeated at the top. If exactly one such team exists, it is the champion; otherwise ambiguous.

## 3. Brute Force → Optimal
- **Brute:** compute reachability from each source.
- **Optimal:** count indegree-0 nodes — O(n+E).

## 4. Data Structure / Approach Justification
**Chosen:** indegree array.

- **vs Floyd reachability:** heavier and unnecessary.

## 5. Logic Walkthrough
Tally indegrees. Scan for indegree 0; if more than one, return -1; else return that team.

## 6. Dry Run
`0→1→2` → champion **0**. Two sources → **-1**.

## 7. Time & Space Complexity
Time **O(n+E)**. Space **O(n)**. Why: indegree pass (section 4).

## 8. Trade-offs & Alternatives
If not a single hierarchy, verify the source reaches all nodes.

## 9. Common Mistakes / Edge Cases
Returning any indegree 0 without uniqueness check; mixing up edge direction.

## 10. Interview Follow-ups / Variations
Find the town judge; minimum vertices to reach all; topological sources.

## 11. Tags
`graph`, `indegree`, `leetcode-2924`, `difficulty:medium`
