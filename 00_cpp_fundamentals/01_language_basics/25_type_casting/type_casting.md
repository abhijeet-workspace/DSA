# Type Casting

## 1. Problem Statement
Show implicit conversion, `static_cast`, `reinterpret_cast` (without dereference), `dynamic_cast` on a polymorphic hierarchy, and why C-style casts are discouraged.

- **Input:** none
- **Output:** truncated int, char `'A'`, successful/failed dynamic casts
- **Valid answer:** `dynamic_cast` needs RTTI + polymorphic base (`virtual`)
- **Edges:** `reinterpret_cast` is easy to misuse; failed `dynamic_cast` on pointers yields `nullptr`

## 2. Intuition
Casts change how a value/pointer is interpreted. Prefer the narrowest cast that expresses intent so the compiler can still check relatedness.

## 3. Brute Force → Optimal
- **Naive:** C-style `(T)x` everywhere.
- **This approach:** `static_cast` for related conversions; `dynamic_cast` for safe polymorphic downcasts; avoid `reinterpret_cast` unless ABI/bit-level work requires it.

## 4. Data Structure / Approach Justification
Tiny polymorphic `Base`/`Derived` for `dynamic_cast`.

| Alternative | Why it loses here |
|-------------|-------------------|
| `const_cast` | Separate lesson flavor; only removes const |
| Design that needs fewer casts | Best long-term; still must know casts |

## 5. Logic Walkthrough
1. Implicit `double`→`int` truncates.
2. `static_cast<char>(65)` → `'A'`.
3. Upcast `Derived*`→`Base*` implicitly; downcast with `dynamic_cast`.
4. Show failed downcast on a pure `Base` object.

## 6. Dry Run
| Expression | Result |
|------------|--------|
| `(int)3.7` / implicit | 3 |
| `static_cast<char>(65)` | `'A'` |
| `dynamic_cast<Derived*>(&der)` | non-null |
| `dynamic_cast<Derived*>(&plainBase)` | nullptr |

## 7. Time & Space Complexity
- **Time:** `static_cast` O(1); `dynamic_cast` may use RTTI checks
- **Space:** O(1)
- Why: no containers

## 8. Trade-offs & Alternatives
- Prefer redesign / virtual APIs over downcasts.
- Prefer `static_cast` over C-style for readability and grepping.
- Prefer `unique_ptr`/`variant` over type-erased base pointers when possible.

## 9. Common Mistakes / Edge Cases
- `dynamic_cast` on non-polymorphic types
- Dereferencing a failed `dynamic_cast` reference (throws `bad_cast`)
- Using `reinterpret_cast` for arithmetic conversions

## 10. Interview Follow-ups / Variations
- `const_cast` use cases and UB risks?
- Cross-casts in multiple inheritance?
- Cost of RTTI in embedded systems?

## 11. Tags
`cpp-basics`, `casting`, `rtti`, `beginner`
