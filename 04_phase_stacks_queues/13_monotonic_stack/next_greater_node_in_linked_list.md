# Next Greater Node In Linked List

## 1. Problem Statement
[LeetCode 1019](https://leetcode.com/problems/next-greater-node-in-linked-list/) — for each node, return the value of the next node to the right with a **strictly greater** value (0 if none).

- **Inputs:** singly linked list `head`.
- **Output:** `vector<int>` parallel to list order.
- **Edges:** single node; strictly decreasing (all zeros); duplicates (strict `>`).

## 2. Intuition
Same as next greater element / daily temperatures: materialize values into an array, then monotonic decreasing index stack resolves waiting smaller values when a greater one arrives.

## 3. Brute Force → Optimal
- **Brute:** from each node walk `next` until greater — O(N²).
- **Optimal:** array + monotonic stack — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** convert list → `vector`, then classic NGE stack.

| Alternative | Why it loses here |
|-------------|-------------------|
| Stack of node pointers without array | Harder to emit index-aligned answer |
| Recursion reverse then previous-greater | Clever but less clear in interviews |

## 5. Logic Walkthrough
1. Traverse list into `vals`.
2. For each index `i`, while `vals[top] < vals[i]`, set `res[top] = vals[i]` and pop.
3. Push `i`. Leftovers stay `0`.

## 6. Dry Run
`2 → 1 → 5`:
- `5` resolves `1` then `2` → answer `[5,5,0]`.

## 7. Time & Space Complexity
- **Time:** O(N).
- **Space:** O(N) for values, answer, and stack.

## 8. Trade-offs & Alternatives
Reverse the list and compute previous greater into a stack of answers without a full value array — similar asymptotics, more pointer care.

## 9. Common Mistakes / Edge Cases
Using `<=` (equals are not greater); returning indices instead of values; forgetting to zero-initialize unresolved nodes.

## 10. Interview Follow-ups / Variations
Next greater element I/II; daily temperatures; delete nodes with greater value on right.

## 11. Tags
`stack`, `monotonic-stack`, `linked-list`, `leetcode-1019`, `difficulty:medium`
