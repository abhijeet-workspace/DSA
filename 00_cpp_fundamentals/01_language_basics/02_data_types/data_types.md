# Data Types

## 1. Problem Statement
Show the common C++ built-in types (`int`, `float`, `double`, `char`, `bool`): declare them, print them, and change one value.

- **Input:** none
- **Output:** one line of initial values, then `New Age: 30`
- **Valid answer:** types hold expected values; mutation of `age` is visible
- **Edges:** `bool` prints as `0`/`1` by default; `float` vs `double` precision

## 2. Intuition
A type tells the compiler how much storage to reserve and which operations are legal. Start with scalars before containers.

## 3. Brute Force → Optimal
- **Naive:** store everything as `int` or as untyped “variables” from dynamic languages.
- **This approach:** pick the smallest clear type for each kind of value and observe mutation.

## 4. Data Structure / Approach Justification
Plain stack locals — no heap, no containers.

| Alternative | Why it loses here |
|-------------|-------------------|
| `std::string` for grade | Overkill for a single character |
| Fixed-width types (`int32_t`) | Better for portability later; obscures the first lesson |

Trade-off: `float` is shown for completeness; prefer `double` for most real floating math.

## 5. Logic Walkthrough
1. Initialize `age`, `marks`, `pi`, `grade`, `isPass`.
2. Stream all five to `std::cout`.
3. Assign `age = 30` and print again to prove variables are mutable (unlike `const`).

## 6. Dry Run
| Step | `age` | Output fragment |
|------|-------|-----------------|
| init | 20 | `20 87.5 3.14159 A 1` |
| assign | 30 | `New Age: 30` |

## 7. Time & Space Complexity
- **Time:** O(1)
- **Space:** O(1)
- Why: fixed number of scalars and prints

## 8. Trade-offs & Alternatives
- Use `double` unless API/memory requires `float`.
- Use `char` for single characters; `std::string` for text.
- Prefer `bool` over `int` flags for readability.

## 9. Common Mistakes / Edge Cases
- Truncating on `int age = 20.9;` (fraction lost)
- Comparing floats with `==`
- Assuming `sizeof(int)` is always 4 (platform-dependent)
- Treating `char` as always unsigned

## 10. Interview Follow-ups / Variations
- What is the difference between signed and unsigned integers?
- When do you need `long long`?
- How does integer promotion work in mixed expressions?

## 11. Tags
`cpp-basics`, `data-types`, `variables`, `beginner`
