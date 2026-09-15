# Merge Two Binary Trees

## 1. Problem Statement
[LeetCode 617](https://leetcode.com/problems/merge-two-binary-trees/) — merge by summing values on overlapping nodes; take the non-null child otherwise.

- **Inputs:** `TreeNode* root1`, `TreeNode* root2`.
- **Output:** merged `TreeNode*` (may reuse nodes).
- **Valid answer:** structure is union of both shapes with summed overlaps.
- **Edges:** one tree empty; disjoint shapes; identical shapes.

## 2. Intuition
DFS both pointers together: null short-circuits to the other tree; else add values and merge children.

## 3. Brute Force → Optimal
- **Brute:** build a brand-new tree always — extra allocations.
- **Optimal:** mutate one tree in place — O(N) time.

## 4. Data Structure / Approach Justification
**Chosen:** recursive in-place merge into `t1`.

- **vs always-new nodes:** safer if inputs must stay immutable.
- **vs BFS queue of pairs:** same work, more code.

## 5. Logic Walkthrough
If !t1 return t2; if !t2 return t1; t1.val += t2.val; merge left/right; return t1.

## 6. Dry Run
`[1,3,2,5]` + `[2,1,3,null,4,null,7]` → root 3, left 4 with children 5/4, right 5 with right 7.

## 7. Time & Space Complexity
Time **O(min(N1,N2))** overlapping visits, worst O(N1+N2). Space **O(H)**. Why: paired recursion (section 4).

## 8. Trade-offs & Alternatives
In-place mutates `t1`/`t2` sharing; clone if callers need originals.

## 9. Common Mistakes / Edge Cases
Creating nodes when one side is null (unnecessary); forgetting to assign merged children back.

## 10. Interview Follow-ups / Variations
Same tree (100); merge k trees; immutable merge returning new roots only.

## 11. Tags
`binary-tree`, `dfs`, `recursion`, `leetcode-617`, `difficulty:easy`
