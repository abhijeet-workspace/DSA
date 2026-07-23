# Multi-file Demo — `my_function.cpp`

## 1. Problem Statement
Provide definitions for `sayHello` and `printSumOfTwoNumber` declared in `my_function.h`.

- **Input:** none for `sayHello`; two `int`s for the sum helper
- **Output:** greeting line from `sayHello`; numeric return from the sum function
- **Valid answer:** signatures match the header exactly
- **Edges:** mismatched prototype vs definition → compile/link errors

## 2. Intuition
A `.cpp` includes its own header so the compiler checks definitions against declarations early.

## 3. Brute Force → Optimal
- **Naive:** define functions without including the header (drift risk).
- **This approach:** `#include "my_function.h"` then define — declaration/definition stay aligned.

## 4. Data Structure / Approach Justification
Free functions; no heap/`new` (despite folder name).

| Alternative | Why it loses here |
|-------------|-------------------|
| Class methods | Heavier than needed for first multi-file demo |
| Header-only bodies | Skips separate translation-unit practice |

## 5. Logic Walkthrough
1. Include `<iostream>` and `my_function.h`.
2. `sayHello` prints a fixed greeting.
3. `printSumOfTwoNumber(num1, num2)` returns `num1 + num2`.

## 6. Dry Run
`printSumOfTwoNumber(20, 30)` → returns `50`.  
`sayHello()` → prints `Hello from a separate file!`.

## 7. Time & Space Complexity
- **Time:** O(1)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Keep headers minimal (declarations); keep heavy includes in `.cpp` to reduce compile coupling.

## 9. Common Mistakes / Edge Cases
Signature drift vs `.h`; missing include guards in header; exporting `using namespace std` from headers.

## 10. Interview Follow-ups / Variations
Forward declarations vs includes; build times and PCH; when `new`/`delete` actually belong (dynamic allocation lesson elsewhere).

## 11. Tags
`cpp-basics`, `headers`, `function-definition`, `beginner`
