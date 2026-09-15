# Binary Tree Cameras

## Problem Statement
[LeetCode 968](https://leetcode.com/problems/binary-tree-cameras/) — min cameras on nodes covering node+parent+children.

- **Inputs:** `root`.
- **Output:** min cameras.
- **Valid answer:** cover all nodes.
- **Edges:** single node -> 1.

## Intuition
Greedy DFS states: covered / needs / has camera.

## Brute Force → Optimal
- **Brute:** place subsets.
- **Optimal:** O(N) greedy tree DP.

## Data Structure / Approach Justification
**Chosen:** return state enum; place camera when child needs.

## Logic Walkthrough
If either child needs camera, place here.

## Dry Run
Sample -> **1** or **2** depending on tree.

## Time & Space Complexity
Time **O(N)**. Space **O(H)**.

## Trade-offs & Alternatives
Root may still need a camera.

## Common Mistakes / Edge Cases
Leaving root uncovered.

## Interview Follow-ups / Variations
House Robber III style states.

## Tags
`tree-dp`, `leetcode-968`, `difficulty:hard`
