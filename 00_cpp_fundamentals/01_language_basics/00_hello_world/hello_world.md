# Hello World

## 1. Problem Statement
Write the smallest useful C++ program that prints `Hello World` to standard output.

- **Input:** none
- **Output:** the text `Hello World` followed by a newline
- **Valid answer:** program compiles, runs, and prints exactly that line
- **Edge cases:** none for this demo (no input parsing)

## 2. Intuition
Every C++ program needs an entry point (`main`) and a way to talk to the console. The standard library provides `std::cout` for text output once you include `<iostream>`.

## 3. Brute Force → Optimal
- **Naive:** call platform-specific print APIs or C `printf` without understanding the C++ I/O model.
- **This approach:** use `std::cout` and `std::endl` from the C++ standard library — the idiomatic teaching path for beginners.

## 4. Data Structure / Approach Justification
No data structure is needed. We use stream insertion (`operator<<`) on `std::cout`.

| Alternative | Why it loses here |
|-------------|-------------------|
| `printf` from `<cstdio>` | Valid C-style option, but hides C++ stream model this lesson teaches |
| Writing to a file | Overkill; goal is console output |

Trade-off: `std::endl` flushes the stream; `'\n'` alone is often enough and slightly cheaper.

## 5. Logic Walkthrough
1. `#include <iostream>` pulls in declarations for `std::cout` / `std::endl`.
2. `main()` is the program entry point.
3. `std::cout << "Hello World" << std::endl` inserts the string, then a newline (and flush).
4. `return 0` signals successful termination to the OS.

## 6. Dry Run
| Step | Action | Console |
|------|--------|---------|
| 1 | Enter `main` | (empty) |
| 2 | Insert `"Hello World"` | `Hello World` |
| 3 | Insert `std::endl` | `Hello World` + newline |
| 4 | `return 0` | exit |

## 7. Time & Space Complexity
- **Time:** O(1) — fixed amount of output work
- **Space:** O(1) — no dynamic allocation
- Why: single constant-size write; no loops or containers

## 8. Trade-offs & Alternatives
- Prefer `'\n'` over `std::endl` in hot loops to avoid unnecessary flushes.
- Prefer `std::cout` over `printf` for type-safe C++ style; use `printf` when interoperating with C or formatting APIs you already know.

## 9. Common Mistakes / Edge Cases
- Forgetting `#include <iostream>`
- Using `using namespace std;` at global scope (pollutes names) — this file uses `std::` explicitly
- Omitting `return 0` (allowed in C++ for `main`, but explicit is clearer for beginners)
- Mixing `printf` without including `<cstdio>`

## 10. Interview Follow-ups / Variations
- What does `std::endl` do beyond printing a newline?
- Difference between `std::cout`, `std::cerr`, and `std::clog`?
- How would you print without flushing every line?

## 11. Tags
`cpp-basics`, `iostream`, `main`, `beginner`
