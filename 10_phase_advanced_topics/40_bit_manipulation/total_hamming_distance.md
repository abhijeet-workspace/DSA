# Total Hamming Distance

## 1. Problem Statement
[LeetCode 477](https://leetcode.com/problems/total-hamming-distance/) — sum of Hamming distances over all pairs.

- **Inputs:** `vector<int> nums`.
- **Output:** total pairwise Hamming distance.
- **Valid answer:** exact sum.
- **Edges:** N≤1; all equal; mixed high bits.

## 2. Intuition
Per bit independently: if `c` numbers have the bit set and `N-c` do not, that bit contributes `c·(N-c)` to the total.

## 3. Brute Force → Optimal
- **Brute:** all pairs popcount — O(N²).
- **Optimal:** 32 bit counts — O(32N).

## 4. Data Structure / Approach Justification
**Chosen:** for each bit 0..31 count set bits; add `c*(n-c)`.

- **vs pair XOR:** too slow at scale.

## 5. Logic Walkthrough
For b in 0..31: count `c`; `ans += c * (n-c)`.

## 6. Dry Run
`[4,14,2]` → **6**.

## 7. Time & Space Complexity
Time **O(32N)**. Space **O(1)**. Why: fixed bit width (section 4).

## 8. Trade-offs & Alternatives
Works only because Hamming is bit-separable; not for arbitrary pairwise metrics.

## 9. Common Mistakes / Edge Cases
Overflow on `c*(n-c)` for large N (use long); stopping at bit 30.

## 10. Interview Follow-ups / Variations
Weighted distances; 64-bit integers.

## 11. Tags
`bit-manipulation`, `counting`, `leetcode-477`, `difficulty:medium`
