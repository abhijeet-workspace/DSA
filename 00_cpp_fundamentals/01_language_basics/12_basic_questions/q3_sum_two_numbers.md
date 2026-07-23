# Q3 — Sum of Two Numbers

## 1. Problem Statement
Read two integers and print their sum.

- **Input:** `num1`, `num2`
- **Output:** `Sum of A and B is: S`
- **Valid answer:** `S == num1 + num2`
- **Edges:** overflow for extreme `int` values; non-numeric input fails `cin`

## 2. Intuition
Basic interactive arithmetic: store operands, add, print.

## 3. Brute Force → Optimal
- **Naive:** hardcode the numbers.
- **This approach:** `cin` both values so the program works for any pair.

## 4. Data Structure / Approach Justification
Three `int` scalars.

| Alternative | Why it loses here |
|-------------|-------------------|
| `long long` | Safer for large sums; slightly heavier for first I/O drill |
| No temps, print `num1+num2` inline | Fine; named `sum` is clearer for beginners |

## 5. Logic Walkthrough
1. Read `num1` then `num2`.
2. `sum = num1 + num2`.
3. Print labeled result.

## 6. Dry Run
Input `7` then `5` → `sum = 12` → `Sum of 7 and 5 is: 12`.

## 7. Time & Space Complexity
- **Time:** O(1)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Use `long long` when problem constraints exceed 32-bit; validate `cin` in production.

## 9. Common Mistakes / Edge Cases
Swapping prompts; integer overflow; not checking stream state.

## 10. Interview Follow-ups / Variations
Sum without `+` operator; handle big integers as strings.

## 11. Tags
`cpp-basics`, `iostream`, `arithmetic`, `beginner`, `practice`
