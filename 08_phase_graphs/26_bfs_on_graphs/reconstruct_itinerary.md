# Reconstruct Itinerary

## Problem Statement
[LeetCode 332](https://leetcode.com/problems/reconstruct-itinerary/) — given airline tickets `[from, to]`, rebuild the itinerary starting at `"JFK"` that uses every ticket once; if multiple, choose the lexicographically smallest.

- **Inputs:** list of tickets (directed multigraph).
- **Output:** airport sequence of length `tickets+1`.
- **Valid answer:** valid Euler path; lexical when ties.
- **Edges:** duplicate tickets; dead-ends that must be taken last (Hierholzer).

## Intuition
This is an Euler path. Hierholzer: always take the smallest unused outgoing edge; append node **after** exploring — reverse at end.

## Brute Force → Optimal
- **Brute:** backtracking all paths — exponential.
- **Optimal:** Hierholzer with ordered edges — **O(E log E)** with `multiset`.

## Data Structure / Approach Justification
**Chosen:** `map<string, multiset<string>>` + post-order DFS.

- **vs priority_queue:** similar ordering; multiset erase-begin is simple.
- **vs plain backtracking:** fails large `E`.

## Logic Walkthrough
Insert all edges. `dfs(u)`: while outs remain, pop smallest `v`, recurse; then push `u` to `route`. Reverse `route`.

## Dry Run
Tickets JFK→MUC→LHR→SFO→SJC → route after reverse: `JFK MUC LHR SFO SJC`.

## Time & Space Complexity
Time **O(E log E)** for ordered inserts/erases. Space **O(E)**. Why: each edge used once (section 4).

## Trade-offs & Alternatives
`min-heap` per node also works. Problem lives under BFS topic folder but algorithm is Hierholzer DFS (Euler).

## Common Mistakes / Edge Cases
Greedy forward without post-order; not handling duplicate edges; wrong start airport.

## Interview Follow-ups / Variations
Undirected Euler circuit (Hierholzer); Chinese Postman; validity when Euler path may not exist (guaranteed here).

## Tags
`graph`, `euler-path`, `hierholzer`, `dfs`, `leetcode-332`, `difficulty:hard`
