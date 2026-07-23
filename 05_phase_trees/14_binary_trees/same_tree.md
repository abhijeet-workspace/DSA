# Same Tree

## Problem Statement
[LeetCode 100](https://leetcode.com/problems/same-tree/) — return true if two binary trees are structurally identical and have the same node values.

- **Inputs:** `TreeNode* p`, `TreeNode* q`.
- **Output:** `bool`.
- **Valid answer:** inductive equality on every corresponding pair of nodes.
- **Edges:** both empty; one empty; same values different shape; different values same shape.

## Intuition
Walk both trees together: null/null matches; exactly one null fails; else values equal and both child pairs match.

## Brute Force → Optimal
- **Brute:** serialize both then compare strings — O(N) with extra allocations.
- **Optimal:** simultaneous DFS/BFS — O(N) time, O(H) space.

## Data Structure / Approach Justification
**Chosen:** paired recursive DFS.

- **vs dual BFS queues:** same asymptotics; iterative for deep trees.
- **vs value multiset compare:** ignores structure — wrong.

## Logic Walkthrough
If `!p || !q`, return `p == q`. Else `p->val == q->val` and recurse on left pairs and right pairs.

## Dry Run
`p=q=[1,2,3]`: roots 1 match → left 2 match → right 3 match → true.  
`p=[1,2]`, `q=[1,null,2]`: after root, left of q is null while p has 2 → false.

## Time & Space Complexity
Time **O(N)** (N = min size until mismatch, worst both full). Space **O(H)**. Why: one paired visit (section 4).

## Trade-offs & Alternatives
Recursion is clearest. Iterative stack/queue for skewed inputs. Short-circuit on first mismatch.

## Common Mistakes / Edge Cases
Comparing value bags only; forgetting both-null true; using XOR-style null checks incorrectly.

## Interview Follow-ups / Variations
Subtree of another tree (572); symmetric tree (101); merge two trees (617).

## Tags
`binary-tree`, `dfs`, `recursion`, `leetcode-100`, `difficulty:easy`
