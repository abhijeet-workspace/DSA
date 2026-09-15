# Find All Possible Recipes from Given Supplies

## 1. Problem Statement
[LeetCode 2115](https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/) — recipes with ingredient lists; initial `supplies`. A recipe can be cooked if all ingredients are available (supplies or other cooked recipes). Return all recipes you can make.

- **Inputs:** `recipes`, `ingredients`, `supplies`.
- **Output:** list of makeable recipes (order free).
- **Valid answer:** recipes reachable via topo cooking order.
- **Edges:** cyclic dependencies; missing ingredients; chain of recipes.

## 2. Intuition
Model recipe creation as a graph: each ingredient points to recipes that need it. Kahn BFS from supplies reducing indegrees of recipes.

## 3. Brute Force → Optimal
- **Brute:** repeatedly scan recipes — O(n²).
- **Optimal:** Kahn O(n+E).

## 4. Data Structure / Approach Justification
**Chosen:** indegree per recipe + queue of available items.

- **vs DFS cycle detect:** Kahn naturally lists only cookable ones.

## 5. Logic Walkthrough
Set indegree = ingredient count. Edges from ingredient → recipe. BFS supplies; when recipe indegree hits 0, cook and enqueue it.

## 6. Dry Run
Supplies yeast+flour → cook `bread`.

## 7. Time & Space Complexity
Time **O(n+E)**. Space **O(n+E)**. Why: topo cook (section 4).

## 8. Trade-offs & Alternatives
DFS with states (visiting/done) also works.

## 9. Common Mistakes / Edge Cases
Not enqueueing cooked recipes as new supplies; double-counting; ignoring cycles (those stay indegree>0).

## 10. Interview Follow-ups / Variations
Course schedule; alien dictionary; build order.

## 11. Tags
`topological-sort`, `kahn`, `leetcode-2115`, `difficulty:medium`
