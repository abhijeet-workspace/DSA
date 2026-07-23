# Keywords & Literals

## 1. Problem Statement
Demonstrate C++ absolute basics: reserved **keywords**, **literals**, a **const** binding, and **escape sequences** in printed text.

- **Input:** none
- **Output:** printed samples of each literal kind and the constant `PI`
- **Valid answer:** program shows integers, floats, chars, strings, bools, and escapes correctly
- **Implied edges:** distinguish `'X'` (char) vs `"X"` (string); `0.5f` vs `0.5` (double)

## 2. Intuition
Keywords are reserved words the language owns (`int`, `const`, `bool`, …). Literals are raw values written in source (`42`, `'X'`, `"hi"`, `true`). Escape sequences like `\n` and `\t` encode special characters inside string/char literals.

## 3. Brute Force → Optimal
- **Naive:** memorize keywords as “magic words” without separating keyword vs identifier vs literal.
- **This approach:** declare one example of each common literal, bind `PI` with `const`, and print with escapes so the mental model sticks.

## 4. Data Structure / Approach Justification
Uses scalar locals and `std::string` for the string sample.

| Alternative | Why it loses here |
|-------------|-------------------|
| C-string `char[]` only | Misses C++ `std::string` literal usage beginners need next |
| Macros (`#define PI ...`) | Old style; `const`/`constexpr` is the modern teaching path |

Honest trade-off: `float` is shown for the `f` suffix lesson; prefer `double` in most real code.

## 5. Logic Walkthrough
1. `PI` is a `const double` — keyword `const` prevents reassignment.
2. `decimal_literal`, `float_literal`, `char_literal`, `string_literal`, `bool_literal` hold each literal family.
3. Prints use `"\n"` and `"\t"` to show escape sequences.
4. Final line dumps the remaining samples so nothing is “dead” code under `-Werror` unused checks.

## 6. Dry Run
| Variable | Value after init |
|----------|------------------|
| `PI` | `3.14159265` |
| `decimal_literal` | `42` |
| `float_literal` | `0.5` |
| `char_literal` | `'X'` |
| `string_literal` | `"Antigravity"` |
| `bool_literal` | `true` (prints as `1` by default) |

Console includes a tabbed line `Tabbed	Text	Demo`.

## 7. Time & Space Complexity
- **Time:** O(1)
- **Space:** O(1) for scalars; `string_literal` stores a short fixed string
- Why: no loops; fixed-size demo data

## 8. Trade-offs & Alternatives
- Prefer `constexpr` for compile-time constants when the value is known at compile time.
- Prefer `double` over `float` unless memory/API forces `float`.
- Raw string literals `R"(...)"` avoid escape noise for paths/regex later.

## 9. Common Mistakes / Edge Cases
- Using a keyword as an identifier (`int int = 1;` — illegal)
- Forgetting `f` on float literals when you intend `float`
- Confusing `'\n'` (char) with `"\n"` (string)
- Modifying a `const` object

## 10. Interview Follow-ups / Variations
- What is the difference between `const` and `constexpr`?
- How are integer literals in hex (`0xFF`) / binary (`0b1010`) written?
- Why is `std::string` preferred over decaying `char*` for ownership?

## 11. Tags
`cpp-basics`, `keywords`, `literals`, `const`, `escape-sequences`, `beginner`
