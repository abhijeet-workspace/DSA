# Kth Smallest Element in a BST

## Problem Statement
[LeetCode 230](https://leetcode.com/problems/kth-smallest-element-in-a-bst/) — return the k-th smallest value in a BST (1-indexed).

- **Inputs:** `TreeNode* root`, `int k` (1 ≤ k ≤ number of nodes).
- **Output:** integer value of the k-th node in sorted order.
- **Valid answer:** unique for a given BST and k.
- **Edges:** `k == 1` (minimum); `k == n` (maximum); skewed tree.

## Intuition
BST inorder visits values ascending. Count visits and stop when the count hits k.

## Brute Force → Optimal
- **Brute:** full inorder into array, index `k-1` — always O(N).
- **Optimal:** early-stop inorder — O(H + K); with subtree sizes, O(H) per query.

## Data Structure / Approach Justification
**Chosen:** recursive inorder with a shared visit counter.

- **vs stack iterator:** same idea, iterative control.
- **vs subtree-size augmentation:** better for frequent kth after updates.

## Logic Walkthrough
Recurse left; increment count; if `count == k` store value and stop; else recurse right. Skip work once `count >= k`.

## Dry Run
BST `[3,1,4,null,2]`, `k=1`:
- Visit left spine → node 1 → count=1 → result=1 stop.

`k=3`: visit 1,2,3 → result=3.

## Time & Space Complexity
Time **O(H + K)**. Space **O(H)** recursion. Why: inorder stops after k nodes (section 4).

## Trade-offs & Alternatives
Morris traversal O(1) extra space but mutates links. Augment nodes with sizes when many queries interleave with inserts/deletes.

## Common Mistakes / Edge Cases
Counting after both children (wrong order); off-by-one on 0- vs 1-index; not pruning after finding k.

## Interview Follow-ups / Variations
Frequent insert/delete then kth? kth largest? Follow-up with subtree counts.

## Tags
`bst`, `inorder`, `recursion`, `leetcode-230`, `difficulty:medium`
