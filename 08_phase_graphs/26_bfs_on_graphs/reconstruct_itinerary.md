# Reconstruct Itinerary

## 1. Problem Statement
[LeetCode 332](https://leetcode.com/problems/reconstruct-itinerary/) — given airline tickets `[from, to]`, rebuild the itinerary starting at `"JFK"` that uses every ticket once; if multiple, choose the lexicographically smallest.

- **Inputs:** list of tickets (directed multigraph).
- **Output:** airport sequence of length `tickets+1`.
- **Valid answer:** valid Euler path; lexical when ties.
- **Edges:** duplicate tickets; dead-ends that must be taken last (Hierholzer).

## 2. Intuition
This is an Euler path. Hierholzer: always take the smallest unused outgoing edge; append node **after** exploring — reverse at end.

## 3. Brute Force → Optimal
- **Brute:** backtracking all paths — exponential.
- **Optimal:** Hierholzer with ordered edges — **O(E log E)** with `multiset`.

## 4. Data Structure / Approach Justification
**Chosen:** `map<string, multiset<string>>` + post-order DFS.

- **vs priority_queue:** similar ordering; multiset erase-begin is simple.
- **vs plain backtracking:** fails large `E`.

## 5. Logic Walkthrough
Insert all edges. `dfs(u)`: while outs remain, pop smallest `v`, recurse; then push `u` to `route`. Reverse `route`.

## 6. Dry Run
Tickets JFK→MUC→LHR→SFO→SJC → route after reverse: `JFK MUC LHR SFO SJC`.

## 7. Time & Space Complexity
Time **O(E log E)** for ordered inserts/erases. Space **O(E)**. Why: each edge used once (section 4).

## 8. Trade-offs & Alternatives
`min-heap` per node also works. Problem lives under BFS topic folder but algorithm is Hierholzer DFS (Euler).

## 9. Common Mistakes / Edge Cases
Greedy forward without post-order; not handling duplicate edges; wrong start airport.

## 10. Interview Follow-ups / Variations
Undirected Euler circuit (Hierholzer); Chinese Postman; validity when Euler path may not exist (guaranteed here).

## 11. Tags
`graph`, `euler-path`, `hierholzer`, `dfs`, `leetcode-332`, `difficulty:hard`
