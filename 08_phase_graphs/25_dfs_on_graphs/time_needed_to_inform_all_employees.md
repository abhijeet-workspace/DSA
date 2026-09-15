# Time Needed to Inform All Employees

## 1. Problem Statement
[LeetCode 1376](https://leetcode.com/problems/time-needed-to-inform-all-employees/) — company tree: `manager[i]` is manager of `i` (`headID` has `-1`). `informTime[i]` minutes for `i` to inform all direct reports. Return minutes until all know the news from head.

- **Inputs:** `n`, `headID`, `manager`, `informTime`.
- **Output:** total minutes.
- **Valid answer:** max time along any root-to-leaf inform chain.
- **Edges:** n=1; star under head; deep chain.

## 2. Intuition
Build children lists; DFS returns max time to inform subtree: `informTime[u] + max over children`.

## 3. Brute Force → Optimal
- **Brute/Optimal:** one tree DFS O(n).

## 4. Data Structure / Approach Justification
**Chosen:** adjacency children + recursive DFS.

- **vs BFS with times:** also fine for trees.

## 5. Logic Walkthrough
For each employee, attach to manager's child list. DFS from headID.

## 6. Dry Run
Head 2 informs five reports in 1 minute → **1**.

## 7. Time & Space Complexity
Time **O(n)**. Space **O(n)**. Why: tree traversal (section 4).

## 8. Trade-offs & Alternatives
Bottom-up DP from leaves; iterative stack.

## 9. Common Mistakes / Edge Cases
Summing instead of maxing parallel informs; ignoring informTime at non-leaves.

## 10. Interview Follow-ups / Variations
Minimum time with multiple messengers; weighted edges.

## 11. Tags
`dfs`, `tree`, `leetcode-1376`, `difficulty:medium`
