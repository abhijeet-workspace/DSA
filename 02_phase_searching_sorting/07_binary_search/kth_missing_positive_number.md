# Kth Missing Positive Number

## Problem Statement
[LeetCode 1539](https://leetcode.com/problems/kth-missing-positive-number/) — strictly increasing positive `arr`; return the k-th missing positive integer.

- **Inputs:** `vector<int> arr`, `int k`.
- **Output:** `int`.
- **Valid answer:** the k-th positive not in `arr`.
- **Edges:** k missing before arr[0]; all missing after the array; arr starts at 1.

## Intuition
At index i, `arr[i] - (i+1)` numbers are missing before it. Find the first index where missing ≥ k.

## Brute Force → Optimal
- **Brute:** walk 1,2,3,... skipping present values — O(arr.back()).
- **Optimal:** binary search on missing counts — O(log N).

## Data Structure / Approach Justification
**Chosen:** lower bound on `missing(i)`; answer `lo + k`.

- **vs hash set:** O(N) extra memory
- **vs linear scan of arr:** O(N); BS is the study-plan point

## Logic Walkthrough
If `missing(mid) < k`, the k-th missing is to the right. After the loop, `lo` is how many arr values sit before that missing number.

## Dry Run
`[2,3,4,7,11]`, k=5: missing at 7 is 3; at 11 is 6 ≥ 5 → answer 9.

## Time & Space Complexity
Time **O(log N)**. Space **O(1)**. Why: binary search indices.

## Trade-offs & Alternatives
Linear two-pointer is easier to code if N is tiny.

## Common Mistakes / Edge Cases
Returning `arr[hi]+(k-missing)` with the wrong hi; 0-based vs 1-based missing formula.

## Interview Follow-ups / Variations
H-Index II; missing number in 0..n.

## Tags
`binary-search`, `array`, `leetcode-1539`, `difficulty:easy`
