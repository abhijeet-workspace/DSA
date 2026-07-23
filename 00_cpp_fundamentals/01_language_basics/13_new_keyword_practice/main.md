# Multi-file Demo — `main.cpp`

## 1. Problem Statement
Show how `main` consumes functions declared in a header (`my_function.h`) and defined in another `.cpp`.

- **Input:** none (hardcoded `20`, `30`)
- **Output:** greeting from `sayHello`, then `Sum of two number: 50`
- **Valid answer:** links against `my_function.cpp` definitions
- **Edges:** missing header include → compile error; missing object at link → undefined reference

## 2. Intuition
Split interface (`.h`) from implementation (`.cpp`). `main` only needs declarations to call; the linker stitches definitions.

## 3. Brute Force → Optimal
- **Naive:** put every function in one giant `.cpp`.
- **This approach:** header prototypes + separate translation unit — scales to real projects.

## 4. Data Structure / Approach Justification
No DS — modular free functions.

| Alternative | Why it loses here |
|-------------|-------------------|
| Everything in `main.cpp` | Works; hides multi-file linking lesson |
| `inline` in header only | Fine for tiny funcs; skips `.cpp` pairing demo |

Note: folder name says “new keyword”; this pair actually teaches **multi-file functions**, not heap `new`.

## 5. Logic Walkthrough
1. `#include "my_function.h"` brings `sayHello` / `printSumOfTwoNumber` prototypes.
2. `sayHello()` prints from the other file.
3. `value = printSumOfTwoNumber(20, 30)` → 50, then printed.

## 6. Dry Run
| Call | Result |
|------|--------|
| `sayHello()` | `Hello from a separate file!` |
| `printSumOfTwoNumber(20,30)` | `50` |

## 7. Time & Space Complexity
- **Time:** O(1)
- **Space:** O(1)
- Why: two calls, no containers

## 8. Trade-offs & Alternatives
Prefer headers for shared declarations; prefer `static`/`anonymous namespace` for file-local helpers; build systems compile each `.cpp` then link.

## 9. Common Mistakes / Edge Cases
- Forgetting to compile/link `my_function.cpp` with `main.cpp`
- Duplicate definitions if function bodies live in the header without `inline`
- Include-guard mistakes in the `.h`
- `using namespace std;` in headers (avoided)

## 10. Interview Follow-ups / Variations
One-definition rule (ODR); when to use `inline`; difference between `#include "..."` and `<...>`.

## 11. Tags
`cpp-basics`, `headers`, `multi-file`, `linking`, `beginner`
