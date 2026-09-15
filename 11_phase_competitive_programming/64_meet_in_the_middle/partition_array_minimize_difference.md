# Partition Array Into Two Arrays to Minimize Sum Difference (LC 2035)

## 1. Problem Statement
Split `2n` elements into two arrays of size `n` minimizing `|sum1-sum2|`.

- **Inputs:** even-length `nums`.
- **Output:** minimum absolute difference of subset sums with size n.
- **Valid answer:** [LC 2035](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/).
- **Edges:** n=1; negatives.
- **Link:** [LC 2035](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/)

## 2. Intuition
MITM on halves with **sized** subset sums; match counts that add to n.

## 3. Brute Force → Optimal
- **Brute:** C(2n,n).
- **MITM:** enum sized subsets per half.

## 4. Data Structure / Approach Justification
**Chosen:** for each half, map count→sorted sums; match i + (n-i).

| Alternative | Note |
|-------------|------|
| DP | If values small |

## 5. Logic Walkthrough
1. Split into two halves of n.
2. Enumerate all subsets with popcount → sum lists.
3. For k=0..n, match left k with right n-k closest to total/2.

## 6. Dry Run
`[3,9,7,3]` → partition diff **2**.

## 7. Time & Space Complexity
**O(2^n · n)** with n≤15 typically.

## 8. Trade-offs & Alternatives
Sized MITM is the key LC trick.

## 9. Common Mistakes / Edge Cases
Ignoring cardinality; using unsigned sums wrong with negatives.

## 10. Interview Follow-ups / Variations
Unbalanced sizes; modulo constraints.

## 11. Tags
`meet-in-the-middle`, `partition`, `lc-2035`, `difficulty:hard`
