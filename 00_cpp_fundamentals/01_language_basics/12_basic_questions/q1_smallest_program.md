# Q1 — Smallest Program

## 1. Problem Statement
Write the smallest valid C++ program: an empty `main`.

- **Input:** none
- **Output:** none
- **Valid answer:** compiles and exits with status 0
- **Edges:** empty body is legal only because `main` has a special implicit return

## 2. Intuition
Every hosted C++ program needs `main` as the entry point. If it does nothing, the process still starts and stops cleanly.

## 3. Brute Force → Optimal
- **Naive:** assume includes, namespaces, and prints are mandatory.
- **This approach:** `int main() {}` — the true minimum.

## 4. Data Structure / Approach Justification
None.

| Alternative | Why it loses here |
|-------------|-------------------|
| `return 0;` explicitly | Equally valid; slightly more verbose |
| Global-only side effects | Not a clear teaching skeleton |

## 5. Logic Walkthrough
1. Control enters `main`.
2. Body is empty.
3. Falling off `main` yields exit code 0.

## 6. Dry Run
Enter `main` → leave `main` → OS sees success.

## 7. Time & Space Complexity
- **Time:** O(1)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Prefer explicit `return 0;` when teaching exit codes; prefer Hello World next for I/O.

## 9. Common Mistakes / Edge Cases
Misspelled `main` (link error); wrong signature; expecting console output.

## 10. Interview Follow-ups / Variations
Valid `main` signatures; static initialization before `main`; `std::exit` vs return.

## 11. Tags
`cpp-basics`, `main`, `beginner`, `practice`
