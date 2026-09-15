# K-th Smallest Prime Fraction

## 1. Problem Statement
[LeetCode 786](https://leetcode.com/problems/k-th-smallest-prime-fraction/) — sorted arr of primes; consider fractions arr[i]/arr[j] (i<j); return the k-th smallest as `[arr[i],arr[j]]`.

- **Inputs:** `arr`, `k`.
- **Output:** pair of ints representing the fraction.
- **Valid answer:** heap over fractions with fixed numerator moving denominator, or binary search.
- **Edges:** k=1 → smallest arr[0]/arr[n-1]; k=C(n,2).

## 2. Intuition
For each i, fractions arr[i]/arr[j] increase as j decreases. Seed heap with arr[i]/arr[n-1]; pop k times advancing j.

## 3. Brute Force → Optimal
- **Brute:** all pairs + sort — O(N² log N).
- **Heap:** O(K log N).
- **Binary search on value:** O(N log W).

## 4. Data Structure / Approach Justification
**Chosen:** min-heap of `{frac,i,j}`.

- **vs binary search:** often preferred in interviews for clarity of counting.

## 5. Logic Walkthrough
Seed (i, n-1) for each i. Pop min; push (i, j-1) if j-1>i. After k-1 pops, top is answer.

## 6. Dry Run
`[1,2,3,5]`, k=3 → **1/5**.

## 7. Time & Space Complexity
Time **O(K log N)**. Space **O(N)**. Why: heap frontier (section 4).

## 8. Trade-offs & Alternatives
Good k-way analogue on pairs; mention binary-search alternative.

## 9. Common Mistakes / Edge Cases
Allowing i≥j; floating equality issues (use indices in heap carefully); off-by-one k.

## 10. Interview Follow-ups / Variations
Kth smallest pair distance; find k pairs with smallest sums.

## 11. Tags
`heap`, `k-way-merge`, `binary-search`, `leetcode-786`, `difficulty:medium`
