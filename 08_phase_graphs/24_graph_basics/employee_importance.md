# Employee Importance

## 1. Problem Statement
[LeetCode 690](https://leetcode.com/problems/employee-importance/) — each employee has an importance value and a list of direct subordinates. Return the total importance of an employee and all subordinates (transitive).

- **Inputs:** list of employees, query `id`.
- **Output:** sum of importances in the subtree.
- **Valid answer:** tree/forest sum from `id`.
- **Edges:** leaf employee; deep hierarchy.

## 2. Intuition
Org chart is a forest; DFS/BFS from the queried id summing importance.

## 3. Brute Force → Optimal
- **Brute/Optimal:** one traversal of the subtree O(n).

## 4. Data Structure / Approach Justification
**Chosen:** hash map id→employee + recursive DFS.

- **vs BFS queue:** same complexity.

## 5. Logic Walkthrough
Index employees by id. DFS returns importance + sum of DFS(subordinates).

## 6. Dry Run
Employee 1 importance 5 with subs 2 and 3 (3 each) → **11**.

## 7. Time & Space Complexity
Time **O(n)**. Space **O(n)** map/recursion. Why: each employee once (section 4).

## 8. Trade-offs & Alternatives
Build adjacency once if many queries.

## 9. Common Mistakes / Edge Cases
Missing transitive subordinates; assuming unique managers incorrectly.

## 10. Interview Follow-ups / Variations
Max importance path; count employees; nested list weight sum analogy.

## 11. Tags
`dfs`, `tree`, `hash-map`, `leetcode-690`, `difficulty:medium`
