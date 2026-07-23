# Operator Overloading

## 1. Problem Statement
Overload `+`, `==`, and `<<` for a `Complex` type so arithmetic/printing look natural.

- **Input:** none (`c1=(3.5,2.5)`, `c2=(1.5,4.5)`, `c4=c1`)
- **Output:** printed complexes, sum `(5,7)`, equality message
- **Valid answer:** `c1+c2` uses `operator+`; streaming uses friend `operator<<`
- **Edges:** floating equality is exact here; NaN/`eps` not handled

## 2. Intuition
Operators are just functions with special names. Overloading lets user types participate in familiar syntax while keeping encapsulation (`<<` as friend).

## 3. Brute Force → Optimal
- **Brute:** `add(c1,c2)`, `equals(c1,c4)`, `print(c1)` free helpers.
- **This approach:** idiomatic operators matching built-in types’ look.

## 4. Data Structure / Approach Justification
**Chosen:** member `+`/`==`; non-member friend `<<` (left operand is `ostream`).

| Alternative | Why it loses / wins |
|-------------|---------------------|
| Non-member `+` | Better symmetry with conversions |
| `fmt`/`to_string` only | Fine APIs; less teaching of `<<` |
| Exact `double` `==` | Simple demo; production uses epsilon |

## 5. Logic Walkthrough
1. `operator+` builds temp with summed real/imag.
2. `operator==` compares both parts.
3. Friend `operator<<` prints `a + bi` and returns the stream.
4. `main` adds, prints, compares `c1` and `c4`.

## 6. Dry Run
`c1 + c2` → real `5.0`, imag `7.0`.
`c1 == c4` → true → EQUAL message.

## 7. Time & Space Complexity
- **Time:** O(1) per op
- **Space:** O(1) temps
- Why: two doubles per object

## 8. Trade-offs & Alternatives
- Prefer non-member arithmetic when implicit conversions on the left matter.
- Mark operators `const` where they don’t mutate `*this`.
- Avoid overloading operators with surprising meanings.

## 9. Common Mistakes / Edge Cases
- Returning reference to local in `operator+`
- Forgetting to return `ostream&` from `<<`
- Using `==` on floats without tolerance in real code
- Missing `const` on RHS parameter / method

## 10. Interview Follow-ups / Variations
- Implement `+=` in terms of `+` (or vice versa)
- Three-way comparison (`<=>`)
- Why `<<` cannot be a member of `Complex`

## 11. Tags
`oop`, `operator-overloading`, `friend`, `difficulty:easy`
