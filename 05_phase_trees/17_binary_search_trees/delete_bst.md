# Delete Node in a BST

## Problem Statement
[LeetCode 450](https://leetcode.com/problems/delete-node-in-a-bst/) — delete the node with value `key` from a BST and return the (possibly new) root.

- **Inputs:** `TreeNode* root`, `int key`.
- **Output:** root after deletion (BST property preserved).
- **Valid answer:** any valid BST shape with `key` removed (or unchanged if missing).
- **Edges:** missing key; delete leaf; delete one-child node; delete two-child node; delete root.

## Intuition
Search like BST insert. At the target: promote the only child, or replace value with inorder successor (min of right) and delete that successor.

## Brute Force → Optimal
- **Brute:** rebuild tree from all values except `key` — O(N).
- **Optimal:** recursive BST delete along one path — O(H) time/space.

## Data Structure / Approach Justification
**Chosen:** recursive search + successor copy for the two-child case.

- **vs predecessor (max of left):** equally valid; pick one consistently.
- **vs parent pointers:** unnecessary if recursion returns new subtree roots.

## Logic Walkthrough
If `key < root`: recurse left. If `>`: recurse right. Else: no left → return right; no right → return left; else copy min(right) into node and delete that min in the right subtree.

## Dry Run
Delete `3` from `5 / 3(2,4) \ 6(\7)`:
- Find 3 with both children → successor = 4
- Set 3’s node to 4; delete 4 from left subtree → leaf gone
- Inorder: `2 4 5 6 7`

## Time & Space Complexity
Time **O(H)**. Space **O(H)** recursion. Why: one root-to-leaf path + successor walk (section 4).

## Trade-offs & Alternatives
Iterative delete needs careful parent links. Self-balancing trees (AVL/RB) add rotations after structural change.

## Common Mistakes / Edge Cases
Deleting successor without updating links; leaking the removed node; assuming key always exists; wrong successor (must be min of right, not any right child).

## Interview Follow-ups / Variations
Delete in AVL/RB? Return whether deleted? Soft-delete with tombstones?

## Tags
`bst`, `delete`, `recursion`, `successor`, `leetcode-450`, `difficulty:medium`
