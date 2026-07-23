# Smallest Program

## 1. Problem Statement
Write the smallest valid C++ program: an empty `main`.

- **Input:** none
- **Output:** none
- **Valid answer:** compiles and exits successfully (implicit `return 0` for `main`)
- **Edges:** empty body is legal; other functions still need a return if non-void

## 2. Intuition
The linker looks for `main` as the program entry. If `main` does nothing, the process still starts and stops cleanly.

## 3. Brute Force → Optimal
- **Naive:** believe you always need `#include`, namespaces, and prints for a “program”.
- **This approach:** strip to `int main() {}` to see the true minimum.

## 4. Data Structure / Approach Justification
No data structures or I/O.

| Alternative | Why it loses here |
|-------------|-------------------|
| `int main(){ return 0; }` | Equally valid; slightly more explicit |
| Global constructors only | Not a teaching-friendly “program” shape |

## 5. Logic Walkthrough
1. OS/loader transfers control to `main`.
2. Body is empty — no statements run.
3. C++ implicitly returns `0` from `main` when control falls off the end.

## 6. Dry Run
| Step | State |
|------|-------|
| Enter `main` | running |
| Leave `main` | exit code 0 |

## 7. Time & Space Complexity
- **Time:** O(1)
- **Space:** O(1)
- Why: empty body

## 8. Trade-offs & Alternatives
- Prefer explicit `return 0;` when teaching beginners about exit codes.
- Prefer real I/O demos once the skeleton is understood (see Hello World).

## 9. Common Mistakes / Edge Cases
- Misspelling `main` → link error
- Wrong signature that some toolchains reject
- Assuming empty `main` prints something
- Putting executable code at global scope without care

## 10. Interview Follow-ups / Variations
- What are valid `main` signatures?
- Difference between return from `main` and `std::exit`?
- What runs before `main` (static initialization)?

## 11. Tags
`cpp-basics`, `main`, `minimal-program`, `beginner`
