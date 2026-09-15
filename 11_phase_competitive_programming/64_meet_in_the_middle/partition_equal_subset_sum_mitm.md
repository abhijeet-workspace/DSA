# Partition Equal Subset Sum (MITM Angle)

## 1. Problem Statement
Decide if array can be partitioned into two subsets with equal sum.

- **Inputs:** `nums` (positives).
- **Output:** true/false.
- **Related:** [LC 416](https://leetcode.com/problems/partition-equal-subset-sum/).
- **Note:** Standard is DP bitset; MITM works when n small and sum large.
- **Link:** [LC 416](https://leetcode.com/problems/partition-equal-subset-sum/)

## 2. Intuition
If total odd → false; else subset sum to total/2 — MITM or DP.

## 3. Brute Force → Optimal
- **DP O(n·sum).**
- **MITM O(2^(n/2))**.

## 4. Data Structure / Approach Justification
**Chosen:** MITM subset-sum to total/2 for teaching transfer; mention DP for LC constraints.

| Alternative | Note |
|-------------|------|
| Bitset DP | Usual LC 416 |

## 5. Logic Walkthrough
1. Sum; if odd false.
2. MITM target total/2.

## 6. Dry Run
`[1,5,11,5]` → true.

## 7. Time & Space Complexity
**O(2^(n/2))**.

## 8. Trade-offs & Alternatives
Pick algorithm from constraints.

## 9. Common Mistakes / Edge Cases
Odd total; empty subset only.

## 10. Interview Follow-ups / Variations
Count partitions; min diff.

## 11. Tags
`partition`, `subset-sum`, `lc-416`, `mitm`, `difficulty:medium`
