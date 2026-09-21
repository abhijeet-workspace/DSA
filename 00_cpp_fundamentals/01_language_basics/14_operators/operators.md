# Operators

## 1. Problem Statement
Demonstrate core C++ operators: arithmetic, relational, logical, assignment/compound, pre/post increment, and precedence with parentheses.

- **Input:** none (hardcoded `a=10`, `b=3`, `x=5`, `n=5`)
- **Output:** labeled demo lines matching the printed expressions
- **Valid answer:** `a/b` is `3` (truncated); `x` ends as `21`; post-inc prints old value
- **Edges:** `%` needs integers; short-circuit `&&`/`||` not fully shown here

## 2. Intuition
Operators combine values. Precedence decides order unless you force it with `()`. Pre vs post increment differs when the expression *uses* the value.

## 3. Brute Force → Optimal
- **Naive:** memorize every result by running code once without grouping concepts.
- **This approach:** one section per operator family so each rule is visible.

## 4. Data Structure / Approach Justification
Stack `int` locals only — operators apply to scalars first.

| Alternative | Why it loses here |
|-------------|-------------------|
| Overloadable operators on classes | Later OOP topic |
| Bitwise operators | Covered in `10_bit_manipulation` |

## 5. Logic Walkthrough
1. Print `+ - * / %` for `10` and `3`.
2. Print comparisons and boolean combinations.
3. Apply `+=` then `*=` to `x`.
4. Contrast `n++` vs `++n`.
5. Show `2+3*4` vs `(2+3)*4`.

## 6. Dry Run
| Expression | Result |
|------------|--------|
| `10/3` | 3 |
| `10%3` | 1 |
| `x=5; x+=2; x*=3` | 21 |
| `n++` when n=5 | prints 5, n becomes 6 |
| `2+3*4` | 14 |

## 7. Time & Space Complexity
- **Time:** O(1)
- **Space:** O(1)
- Why: fixed scalar ops

## 8. Trade-offs & Alternatives
- Prefer parentheses over relying on obscure precedence.
- Prefer `++i` in loops unless post-inc value is required.
- Use floating types when fractional division is needed.

## 9. Common Mistakes / Edge Cases
- Expecting `10/3 == 3.33` with `int`
- Using `=` instead of `==` in conditions
- Assuming `n++` and `++n` always print the same
- Forgetting `%` with non-integers is invalid

## 10. Interview Follow-ups / Variations
- What does short-circuit evaluation mean for `&&`/`||`?
- Difference between `i++` and `++i` for user-defined types?
- Operator associativity for `=`?

## 11. Tags
`cpp-basics`, `operators`, `precedence`, `beginner`
