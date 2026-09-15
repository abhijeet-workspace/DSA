# Longest Univalue Path

## 1. Problem Statement
[LeetCode 687](https://leetcode.com/problems/longest-univalue-path/) — longest path (number of **edges**) where all nodes have the same value. Path may or may not pass through root.

- **Inputs:** `TreeNode* root`.
- **Output:** `int` edge count.
- **Valid answer:** any same-value chain of edges.
- **Edges:** empty → 0; all distinct; entire tree same value.

## 2. Intuition
Like diameter: at each node, extend univalue arrow from left/right if child value matches; path through node is sum of both arrows; return single best arrow upward.

## 3. Brute Force → Optimal
- **Brute:** from every node explore — O(N²).
- **Optimal:** one postorder tracking global max — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** DFS returning longest univalue arrow length (edges) downward.

| Alternative | Why it loses here |
|-------------|-------------------|
| Explicit path storage | Unnecessary |
| Separate same-value components | Harder with tree edges |

## 5. Logic Walkthrough
1. Recurse children → `Larrow`, `Rarrow`.
2. `left = (left && left.val==val) ? Larrow+1 : 0` (same for right).
3. Update `ans = max(ans, left+right)`.
4. Return `max(left,right)` to parent.

## 6. Dry Run
`[5,4,5,1,1,null,5]`: right spine 5-5 is 1 edge; left not univalue through root → answer **2** if both children of a 5 match (example dependent). Classic LC example answer **2**.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(H)
- Why: diameter-style single pass.

## 8. Trade-offs & Alternatives
Same pattern as binary tree diameter / max path sum with a value filter.

## 9. Common Mistakes / Edge Cases
Returning nodes instead of edges; extending arrow when values differ; not considering path using both children.

## 10. Interview Follow-ups / Variations
Diameter (543); binary tree max path sum (124); longest consecutive path (298).

## 11. Tags
`binary-tree`, `dfs`, `path`, `leetcode-687`, `difficulty:medium`
