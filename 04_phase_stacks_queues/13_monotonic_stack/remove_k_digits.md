# Remove K Digits

## 1. Problem Statement
[LeetCode 402](https://leetcode.com/problems/remove-k-digits/) — remove exactly `k` digits from num (string) so the remaining digits form the **smallest possible integer**. Return as string without leading zeros (`"0"` if empty).

- **Inputs:** `string num`, `int k`.
- **Output:** smallest number string after removals.
- **Edges:** remove all digits; leading zeros after removal; already increasing digits; `k = 0`.

## 2. Intuition
To minimize the number, delete peaks early: whenever a digit is larger than the next one, removing the peak shrinks the most-significant place. Maintain an increasing digit stack and spend `k` removals on descents.

## 3. Brute Force → Optimal
- **Brute:** try all subsets of removals — exponential.
- **Greedy monotonic stack:** O(N) build + strip zeros.

## 4. Data Structure / Approach Justification
**Chosen:** string used as increasing stack of kept digits.

| Alternative | Why it loses here |
|-------------|-------------------|
| DP over (index, remaining k) | Heavier; same greedy optimum |
| Always delete largest digits | Ignores place value (wrong) |

## 5. Logic Walkthrough
1. For each digit `c`, while `k > 0` and stack top `> c`, pop and `--k`.
2. Push `c`.
3. If `k` remains, pop from the end (digits were non-decreasing).
4. Strip leading `'0'`; return `"0"` if empty.

## 6. Dry Run
`num="1432219"`, `k=3`:
- drop `4`, `3`, `2` at peaks → stack `1219`.

`num="10200"`, `k=1`: drop `1` → `0200` → `"200"`.

## 7. Time & Space Complexity
- **Time:** O(N).
- **Space:** O(N) for the stack/answer.

## 8. Trade-offs & Alternatives
Same idea builds the largest number by flipping the comparison. Digit DP is for digit-constrained counting, not this removal problem.

## 9. Common Mistakes / Edge Cases
Leaving leading zeros; forgetting leftover `k` on sorted input; removing too many when `k == num.size()`; comparing as ints instead of chars (OK for digits `'0'`–`'9'`).

## 10. Interview Follow-ups / Variations
Remove duplicate letters (greedy stack + last occurrence); create maximum number; monotonic stack for lexicographically smallest subsequence.

## 11. Tags
`stack`, `greedy`, `monotonic-stack`, `string`, `leetcode-402`, `difficulty:medium`
