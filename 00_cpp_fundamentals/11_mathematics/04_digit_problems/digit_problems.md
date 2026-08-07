# Digit Problems

## 1. Problem Statement
Classic digit-manipulation drills:

1. Count digits
2. Sum of digits
3. Reverse an integer (detect overflow)
4. Palindrome number check
5. Armstrong (narcissistic) number check for 3-digit style / general power

- **Input:** demo integers
- **Output:** counts, reversed value, bools
- **Edges:** negatives (define policy); trailing zeros in reverse; `INT_MAX` overflow

## 2. Intuition
Digits are base-10 place values. `n % 10` peels the last digit; `n /= 10` shifts. Palindrome ↔ number equals its reverse. Armstrong: sum of each digit raised to the count of digits equals the number.

## 3. Brute Force → Optimal
String conversion works but costs allocation. Pure arithmetic is O(digits) = O(log₁₀ n).

## 4. Data Structure / Approach Justification
Integer loops only — no strings required for learning these patterns.

| Alternative | Trade-off |
|-------------|-----------|
| `to_string` | Clear for palindrome; hides arithmetic |
| Digits array | Useful when order matters repeatedly |

## 5. Logic Walkthrough
1. Count / sum: loop `%10` / `/10`.
2. Reverse: `rev = rev*10 + dig`; abort if overflow.
3. Palindrome: compare to reverse (non-negative).
4. Armstrong: `sum dig^k` with `k = digit count`.

## 6. Dry Run
`371`: digits 3; sum 11; reverse 173; not palindrome; Armstrong yes (3³+7³+1³=371).

## 7. Time & Space Complexity
All O(log n) time, O(1) space (ignoring recursion).

## 8. Trade-offs & Alternatives
LeetCode-style reverse often requires overflow → 0. For huge numbers use strings / big int.

## 9. Common Mistakes / Edge Cases
Losing leading zeros after reverse (`120` → `21`); treating negatives as palindromes; `pow` floating error — prefer integer multiply loop.

## 10. Interview Follow-ups / Variations
Add digits until single digit; happy numbers; next palindrome.

## 11. Tags
`cpp-fundamentals`, `mathematics`, `digits`, `palindrome`, `armstrong`, `beginner`

## 12. Next Steps
`05_power_and_roots`.
