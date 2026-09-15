# Convert Sorted List to Binary Search Tree

## 1. Problem Statement
[LeetCode 109](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/) — height-balanced BST from ascending singly linked list.

- **Inputs:** `ListNode* head`.
- **Output:** `TreeNode*`.
- **Valid answer:** balanced BST with inorder = list order.
- **Edges:** empty; one node; two nodes.

## 2. Intuition
Find mid with slow/fast; mid becomes root; recurse on left half (head..mid) and right half (mid->next..).

## 3. Brute Force → Optimal
- **Brute:** copy to array then LC 108 — O(N) extra space.
- **Optimal:** in-place mid split recursion — O(N log N) time / O(log N) stack, or inorder simulation O(N).

## 4. Data Structure / Approach Justification
**Chosen:** slow-fast mid cut + recurse.

| Alternative | Why it loses here |
|-------------|-------------------|
| Array conversion | Extra O(N) memory |
| Inorder numbered build | Elegant O(N); more setup |

## 5. Logic Walkthrough
1. Null / single → base.
2. Find prev of mid; disconnect left list; root=mid; right=mid->next.
3. Recurse left list and right list.

## 6. Dry Run
`[-10,-3,0,5,9]` → mid 0 root; left `[-10,-3]`; right `[5,9]`.

## 7. Time & Space Complexity
- **Time:** O(N log N) mid-find each level / O(N) inorder method
- **Space:** O(log N) recursion
- Why: each split scans current list segment.

## 8. Trade-offs & Alternatives
Prefer array if memory OK. Inorder “count then build” is optimal time.

## 9. Common Mistakes / Edge Cases
Not disconnecting mid from left; infinite recurse on mid; losing right head.

## 10. Interview Follow-ups / Variations
Sorted array to BST; flatten BST to list.

## 11. Tags
`bst`, `linked-list`, `two-pointers`, `leetcode-109`, `difficulty:medium`
