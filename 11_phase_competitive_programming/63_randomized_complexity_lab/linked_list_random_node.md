# Linked List Random Node (LC 382)

## 1. Problem Statement
Given a singly linked list, return a random node's value with equal probability (unknown length).

- **Inputs:** list head; `getRandom` calls.
- **Output:** uniform over nodes.
- **Valid answer:** [LC 382](https://leetcode.com/problems/linked-list-random-node/).
- **Edges:** single node; long list.
- **Link:** [LC 382](https://leetcode.com/problems/linked-list-random-node/)

## 2. Intuition
Reservoir sampling k=1 while walking the list.

## 3. Brute Force → Optimal
- **Brute:** count length then second pass.
- **Reservoir:** one pass O(1) space.

## 4. Data Structure / Approach Justification
**Chosen:** classic one-pass reservoir.

| Alternative | Note |
|-------------|------|
| Store all values | O(N) memory |

## 5. Logic Walkthrough
1. ans=head; i=1.
2. For each next node ++i; replace ans with prob 1/i.

## 6. Dry Run
List 10→1→2→3; getRandom uniform on {10,1,2,3}.

## 7. Time & Space Complexity
**O(N)** per getRandom.

## 8. Trade-offs & Alternatives
Optimal space when list immutable and huge.

## 9. Common Mistakes / Edge Cases
Starting count at 0; modifying list.

## 10. Interview Follow-ups / Variations
k random nodes; weighted nodes.

## 11. Tags
`linked-list`, `reservoir`, `lc-382`, `difficulty:medium`
