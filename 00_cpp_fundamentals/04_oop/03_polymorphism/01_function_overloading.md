# Function Overloading

## 1. Problem Statement
Provide multiple `Calculator::add` overloads (2 ints, 3 ints, 2 floats) and call each from `main` so the compiler selects by signature.

- **Input:** literal arguments in `main`
- **Output:** 15, 30, and 6.2 (approx)
- **Valid answer:** correct overload chosen at compile time for each call
- **Edge cases:** ambiguous calls (e.g. `add(1, 2.0)` without a matching overload)

## 2. Intuition
One verb, several arities/types. Overloading keeps a single conceptual name while the compiler disambiguates using parameter types/count.

## 3. Brute Force → Optimal
- **Naive:** `add2i`, `add3i`, `add2f` — noisy API.
- **This approach:** overload `add`; resolve at compile time (static polymorphism).

## 4. Data Structure / Approach Justification
**Chosen:** member function overloads in a class.

| Alternative | Why it loses here |
|-------------|-------------------|
| Distinct function names | Works but worse readability |
| Templates only | More powerful; overkill for fixed demos |
| Runtime `virtual` | Wrong tool — signatures differ at compile time |

Trade-off: overload sets can become ambiguous; keep conversions simple.

## 5. Logic Walkthrough
1. Three `add` declarations form an overload set.
2. `add(5,10)` → two-int overload → 15.
3. `add(5,10,15)` → three-int → 30.
4. `add(2.5f,3.7f)` → float overload → 6.2f.

## 6. Dry Run
| Call | Chosen overload | Result |
|------|-----------------|--------|
| add(5,10) | int,int | 15 |
| add(5,10,15) | int,int,int | 30 |
| add(2.5f,3.7f) | float,float | 6.2 |

## 7. Time & Space Complexity
- **Time:** O(1) per call
- **Space:** O(1)
- Why: fixed arithmetic; overload resolution is compile-time

## 8. Trade-offs & Alternatives
- Prefer templates when the algorithm is identical across types.
- Prefer distinct names when overloads would be confusingly different behaviors.
- Default arguments can reduce overload count but may introduce ambiguity.

## 9. Common Mistakes / Edge Cases
- Overloading only by return type (illegal)
- Narrowing/`double` literals matching unexpected overloads
- Silent conversions causing wrong overload

## 10. Interview Follow-ups / Variations
- Overload vs override vs hide?
- How does Koenig lookup interact with overloads?
- Can you overload on `const` for member functions?

## 11. Tags
`oop`, `polymorphism`, `overloading`, `compile-time`, `difficulty:easy`
