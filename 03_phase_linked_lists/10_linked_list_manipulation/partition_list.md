# Partition List

## 1. Problem Statement
[LeetCode 86](https://leetcode.com/problems/partition-list/) — rearrange a singly linked list so all nodes with `val < x` come before nodes with `val ≥ x`, preserving relative order within each side (stable partition).

- **Inputs:** `ListNode* head`, integer `x`.
- **Output:** head of partitioned list.
- **Valid answer:** stable split on value threshold `x`.
- **Edges:** all `< x`; all `≥ x`; empty; `x` equal to some values; duplicates.

## 2. Intuition
Build two lists in one scan — “less” and “greater-or-equal” — then splice less’s tail to ge’s head and null-terminate ge.

## 3. Brute Force → Optimal
- **Brute:** collect values, stable_partition array, rebuild — O(N) space.
- **Optimal:** two dummy chains, one pass — O(1) extra.

## 4. Data Structure / Approach Justification
**Chosen:** `lessDummy` / `geDummy` with tails `less` / `ge`.

| Alternative | Why we skip it here |
|-------------|---------------------|
| In-place swaps like Dutch flag | Hard to keep stability on a linked list |
| Sort entire list | Changes order beyond the partition requirement |

## 5. Logic Walkthrough
1. Walk `curr`; append to less if `val < x`, else to ge.
2. `ge->next = nullptr`.
3. `less->next = geDummy.next`; return `lessDummy.next`.

## 6. Dry Run
`1→4→3→2→5→2`, `x=3`: less `1→2→2`, ge `4→3→5` → `1→2→2→4→3→5`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Clear two-list build is interview-standard; mutating in place without dummies is error-prone.

## 9. Common Mistakes / Edge Cases
Forgetting to null-terminate ge (cycle); returning wrong dummy; treating `== x` as less.

## 10. Interview Follow-ups / Variations
Odd/even by index (LC 328); Dutch national flag on arrays; quicksort partition intuition.

## 11. Tags
`linked-list`, `two-pointers`, `partition`, `dummy-node`, `leetcode-86`, `difficulty:medium`
