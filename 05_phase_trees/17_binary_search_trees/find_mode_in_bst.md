# Find Mode in Binary Search Tree

## Problem Statement
[LeetCode 501](https://leetcode.com/problems/find-mode-in-binary-search-tree/) — return all modes (most frequent values) in a BST. May have multiple modes; any order OK.

- **Inputs:** `TreeNode* root` (BST; duplicates allowed as equal children).
- **Output:** `vector<int>` of all modes.
- **Valid answer:** every value achieving the maximum frequency.
- **Edges:** single node; all unique; all same; multiple modes.

## Intuition
BST inorder is sorted, so equal values are contiguous. Stream counts with a `prev` pointer: update running streak vs `max_count`, collect values that tie the max.

## Brute Force → Optimal
- **Brute:** hash frequencies of all nodes — O(N) time, O(N) space.
- **Optimal:** inorder counting (or Morris) — O(N) time, O(H) / O(1) extra.

## Data Structure / Approach Justification
**Chosen:** recursive inorder with prev/count/max and result vector.

- **vs hash map:** wastes the BST property.
- **vs Morris traversal:** O(1) aux space; same counting logic, more code.

## Logic Walkthrough
Inorder visit: if value equals prev, `count++`; else `count=1`. If `count > max`, reset modes to `{val}`; if equal, append. Set `prev = node`.

## Dry Run
Tree `1 → 2 ← 2`: inorder `1,2,2`. Counts 1 then 1 then 2 → mode `{2}`.

Tree with two `1`s and two `2`s: both reach max count 2 → `{1,2}`.

## Time & Space Complexity
Time **O(N)**. Space **O(H)** recursion (+ output). Why: one inorder pass (section 4).

## Trade-offs & Alternatives
Two-pass inorder (first find max freq, second collect) also works if you dislike clearing the vector mid-stream.

## Common Mistakes / Edge Cases
Forgetting multiple modes; not resetting when a new higher count appears; treating non-BST as if equals aren't contiguous.

## Interview Follow-ups / Variations
Mode in unsorted tree (hash); Morris O(1) space; k most frequent values.

## Tags
`bst`, `inorder`, `counting`, `leetcode-501`, `difficulty:easy`
