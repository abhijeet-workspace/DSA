# Auto Type Inference

## 1. Problem Statement
Demonstrate C++ `auto` type deduction on a boolean comparison expression, and call a separately defined function `getValue()`.

- **Input:** none
- **Output:** `1` then `36` (true, then `4 * 9`)
- **Valid answer:** `auto` deduces a printable boolean-compatible type; `getValue` returns 36
- **Edges:** comparison chain `(10 <= 20) > 0` is unusual but legal; prefer clearer bool code in production

## 2. Intuition
`auto` asks the compiler to deduce the variable’s type from the initializer. You still need an initializer — `auto x;` is illegal.

## 3. Brute Force → Optimal
- **Naive:** always write the type explicitly even when it is obvious and noisy (`std::vector<...>::iterator`).
- **This approach:** use `auto` where the initializer makes the type clear; keep explicit types for APIs/docs.

## 4. Data Structure / Approach Justification
No container — scalar `auto` plus a free function.

| Alternative | Why it loses here |
|-------------|-------------------|
| Explicit `bool result = ...` | Clearer here, but wouldn’t teach `auto` |
| `decltype` | More powerful/verbose; later topic |

## 5. Logic Walkthrough
1. `(10 <= 20)` is `true`; `true > 0` is `true` → `result` deduces as `bool`.
2. Print `result` (`1`).
3. `getValue()` computes `result = 4 * 9` and returns `36`.

## 6. Dry Run
| Expression | Value | Deduced / return type |
|------------|-------|------------------------|
| `(10 <= 20) > 0` | `true` | `bool` via `auto` |
| `getValue()` | `36` | `int` |

## 7. Time & Space Complexity
- **Time:** O(1)
- **Space:** O(1)
- Why: fixed expressions; `auto` is compile-time only

## 8. Trade-offs & Alternatives
- Prefer explicit types when they document intent better than `auto`.
- Prefer `auto` for long iterator/template types.
- `auto` never deduces references/top-level const unless you write `const auto&`.

## 9. Common Mistakes / Edge Cases
- `auto x;` without initializer — compile error
- Unexpected deduction from braced init / proxy types
- Assuming `auto` is dynamic typing (it is not)
- Unintended copies: use `const auto&` for large objects

## 10. Interview Follow-ups / Variations
- Difference between `auto`, `decltype`, and `decltype(auto)`?
- How does `auto` interact with templates?
- When does `auto` deduce a proxy (e.g. `vector<bool>`)?

## 11. Tags
`cpp-basics`, `auto`, `type-inference`, `beginner`
