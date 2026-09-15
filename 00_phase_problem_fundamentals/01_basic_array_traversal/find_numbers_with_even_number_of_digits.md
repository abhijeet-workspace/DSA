# Find Numbers with Even Number of Digits

## 1. Problem Statement
[LeetCode 1295](https://leetcode.com/problems/find-numbers-with-even-number-of-digits/) — Return how many integers in `nums` have an even number of digits.

- **Inputs:** `vector<int> nums` (positive integers per constraints).
- **Output:** Count of even-digit numbers.
- **Edges:** Single-digit only; all even-digit; includes powers of ten.

## 2. Intuition
For each value, count digits by repeated `/10`, then test parity. Outer loop is a plain array scan.

## 3. Brute Force → Optimal
Convert to string and check `size() % 2` — clear but allocates. Integer division digit count is O(log x) per element and allocation-free.

## 4. Data Structure / Approach Justification
**Chosen:** scan `nums`; helper `digitCount` via division.

| Alternative | Why it loses here |
|-------------|-------------------|
| `to_string(x).size()` | Extra allocations; hides numeric thinking |
| `log10(x) + 1` | Fine with care for floats/edges; division loop is safer pedagogically |

This is per-element work after an index/range-based scan — still fundamental traversal.

## 5. Logic Walkthrough
1. `ans = 0`.
2. For each `x`, count digits until `x` becomes 0.
3. If count is even, `++ans`.
4. Return `ans`.

## 6. Dry Run
`[12,345,2,6,7896]` → digits 2,3,1,1,4 → even at indices 0 and 4 → answer `2`.

## 7. Time & Space Complexity
- **Time:** O(N · D) with D ≤ 6 under typical constraints (effectively O(N))
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Constraints sometimes allow digit tables by magnitude ranges (`x < 10`, `< 100`, …) for branchy O(1) digit checks.

## 9. Common Mistakes / Edge Cases
`while (x > 0)` without a `do` mishandles `0` if ever allowed; floating `log10` off-by-one.

## 10. Interview Follow-ups / Variations
Count odd-digit numbers; sum of even-digit values.

## 11. Tags
`array`, `math`, `leetcode-1295`, `difficulty:easy`
