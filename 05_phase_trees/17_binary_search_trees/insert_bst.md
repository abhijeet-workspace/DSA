# Insert into a Binary Search Tree

## Problem Statement
[LeetCode 701](https://leetcode.com/problems/insert-into-a-binary-search-tree/) — insert `val` into a BST and return the root.

- **Inputs:** `TreeNode* root`, `int val` (guaranteed not already present).
- **Output:** root after insertion.
- **Valid answer:** any valid BST containing the old nodes plus `val`.
- **Edges:** empty tree; insert as new min/max; deep leaf on skewed path.

## Intuition
Walk left if `val < node`, else right, until a null child — create the new node there. BST order is preserved by construction.

## Brute Force → Optimal
- **Brute:** flatten, insert into sorted array, rebuild — O(N).
- **Optimal:** single path insert — O(H) time/space.

## Data Structure / Approach Justification
**Chosen:** recursive insert returning updated child pointers.

- **vs iterative:** same asymptotics; loop until parent with null child.
- **vs rebalance:** plain BST may skew; AVL/RB if height must stay log N.

## Logic Walkthrough
Base: `root == nullptr` → `new TreeNode(val)`. Else attach recurse result to left or right and return `root`.

## Dry Run
Insert `5` into `4 / 2(1,3) \ 7`:
- `5 > 4` → right `7`
- `5 < 7` → left null → create 5
- Inorder: `1 2 3 4 5 7`

## Time & Space Complexity
Time **O(H)**. Space **O(H)** recursion (O(1) iterative). Why: one search path (section 4).

## Trade-offs & Alternatives
Always insert as leaf — simple but height can become O(N). Prefer `std::set` / balanced trees when many updates need log N.

## Common Mistakes / Edge Cases
Creating a new root and forgetting to return it for empty tree; inserting duplicates when problem forbids them; breaking parent links by not assigning recurse results.

## Interview Follow-ups / Variations
Insert into AVL with rotations? Allow duplicates (multiset policy)? Bulk insert then balance?

## Tags
`bst`, `insert`, `recursion`, `leetcode-701`, `difficulty:medium`
