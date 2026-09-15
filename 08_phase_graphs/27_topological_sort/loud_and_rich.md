# Loud and Rich

## 1. Problem Statement
[LeetCode 851](https://leetcode.com/problems/loud-and-rich/) — `richer[i]=[a,b]` means `a` is richer than `b`. `quiet[i]` is quietness of person `i` (unique). For each person `x`, answer the person `y` with smallest `quiet[y]` among all who are at least as rich as `x` (including `x`).

- **Inputs:** `richer`, `quiet`.
- **Output:** `answer[0..n-1]`.
- **Valid answer:** memoized best over richer ancestors.
- **Edges:** no richer edges; total order; disconnected.

## 2. Intuition
Build graph edges from richer → poorer? For each `x`, neighbors that are directly richer. DFS/topo memo: best quiet person in richer-closure.

## 3. Brute Force → Optimal
- **Brute:** per person DFS without memo — repeated work.
- **Optimal:** DFS memo / Kahn DP O(n+E).

## 4. Data Structure / Approach Justification
**Chosen:** adjacency `richerPeople[x]` + memo DFS.

- **vs explicit topo then DP:** equivalent.

## 5. Logic Walkthrough
For edge `(a,b)` (a richer than b), add `a` into list of `b`. DFS(u) returns quietest among u and richer; memoize.

## 6. Dry Run
LC sample → `answer = [5,5,2,5,4,5,6,7]`.

## 7. Time & Space Complexity
Time **O(n+E)**. Space **O(n+E)**. Why: each node/edge once with memo (section 4).

## 8. Trade-offs & Alternatives
Process richer people first via topo order and push minima downward.

## 9. Common Mistakes / Edge Cases
Reversing richer direction; forgetting self-comparison; no memo.

## 10. Interview Follow-ups / Variations
Course schedule style prerequisites; smallest in ancestor set.

## 11. Tags
`dfs`, `topo`, `memoization`, `leetcode-851`, `difficulty:medium`
