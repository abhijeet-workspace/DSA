# Cousins in Binary Tree

## 1. Problem Statement
[LeetCode 993](https://leetcode.com/problems/cousins-in-binary-tree/) — two nodes `x` and `y` are cousins if same depth but different parents.

- **Inputs:** `TreeNode* root`, `int x`, `int y`.
- **Output:** `bool`.
- **Valid answer:** depth(x)==depth(y) and parent(x)!=parent(y).
- **Edges:** siblings (same parent) → false; different depths → false.

## 2. Intuition
BFS track parent + depth for x and y when found; compare.

## 3. Brute Force → Optimal
- **Brute:** DFS find depth/parent separately.
- **Optimal:** one BFS — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** BFS storing `(node, parent)` or recording when values match.

| Alternative | Why it loses here |
|-------------|-------------------|
| Two DFS searches | Two passes |
| Build parent map fully | Extra work |

## 5. Logic Walkthrough
1. Queue pairs `(node, parent)`.
2. When dequeue matches x/y, store depth & parent.
3. After both found (or level ends), compare.

## 6. Dry Run
`[1,2,3,4]`, x=4,y=3: depths differ → false. `[1,2,3,null,4,null,5]` x=5,y=4 → cousins true.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(W)
- Why: stop early once both found.

## 8. Trade-offs & Alternatives
DFS with depth parameter is equally fine.

## 9. Common Mistakes / Edge Cases
Calling siblings cousins; comparing values not parents; missing null parent for root.

## 10. Interview Follow-ups / Variations
Cousins II (2641); same-depth queries.

## 11. Tags
`binary-tree`, `bfs`, `leetcode-993`, `difficulty:easy`
