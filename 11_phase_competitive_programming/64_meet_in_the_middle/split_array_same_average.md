# Split Array With Same Average (LC 805)

## 1. Problem Statement
Check if array can be split into two nonempty subsets with equal averages.

- **Inputs:** `nums`.
- **Output:** true/false.
- **Valid answer:** [LC 805](https://leetcode.com/problems/split-array-with-same-average/).
- **Edges:** n=1 false; all equal true.
- **Link:** [LC 805](https://leetcode.com/problems/split-array-with-same-average/)

## 2. Intuition
Equal average ⇔ some nonempty proper subset with sum/k = total/n ⇔ `n*sum = k*total`. MITM on subset sums by size.

## 3. Brute Force → Optimal
- **Brute:** all subsets.
- **MITM/DP bitsets:** n≤30.

## 4. Data Structure / Approach Justification
**Chosen:** meet-in-middle / DP sets of achievable sums per cardinality.

| Alternative | Note |
|-------------|------|
| Full MITM halves | Also valid |

## 5. Logic Walkthrough
1. Total S, n.
2. For k=1..n/2 check if some subset size k has sum = S*k/n (exact).
3. Use bitset/DP or MITM.

## 6. Dry Run
`[1,2,3,4,5,6,7,8]` → true.

## 7. Time & Space Complexity
**O(n·Σ)** DP or **O(2^(n/2))** MITM.

## 8. Trade-offs & Alternatives
LC constraints favor DP bitsets; MITM teaches transfer.

## 9. Common Mistakes / Edge Cases
Allowing empty; integer divisibility check.

## 10. Interview Follow-ups / Variations
Count splits; minimize |avg diff|.

## 11. Tags
`meet-in-the-middle`, `subset`, `lc-805`, `difficulty:hard`
