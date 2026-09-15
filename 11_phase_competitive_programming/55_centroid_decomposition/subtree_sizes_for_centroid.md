# Subtree Sizes for Centroid

## 1. Problem Statement
Building-block lab — rooted subtree sizes `sz[v]` used by every centroid / CD routine.

- **Inputs:** tree, root.
- **Output:** `sz[v]` = nodes in subtree of `v` including itself.
- **Edges:** root leaf; star hub root.

## 2. Intuition
`sz[v] = 1 + sum sz[child]`; parent-side size is `n - sz[v]`.

## 3. Brute Force → Optimal
- **Brute:** count via DFS from each node.
- **Optimal:** one DFS O(N).

## 4. Data Structure / Approach Justification
**Chosen:** single rooted DFS.

| Alternative | Note |
|-------------|------|
| Rerooting | Needed when every root’s sizes matter |

## 5. Logic Walkthrough
Post-order accumulate child sizes into parent.

## 6. Dry Run
Root 1 with children 2 and 3(with 4,5) → `sz = [-,5,1,3,1,1]`.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(N)**.

## 8. Trade-offs & Alternatives
On live CD components, skip `dead` nodes in the same recursion.

## 9. Common Mistakes / Edge Cases
Forgetting `sz[v]=1` base; counting parent edge.

## 10. Interview Follow-ups / Variations
Live-component sizing with `dead[]`.

## 11. Tags
`subtree-size`, `centroid`, `dfs`, `cp`, `difficulty:easy`
