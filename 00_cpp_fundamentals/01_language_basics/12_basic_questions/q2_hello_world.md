# Q2 — Hello World

## 1. Problem Statement
Print `Hello, World!` twice: once with `printf`, once with `std::cout`.

- **Input:** none
- **Output:** two identical greeting lines
- **Valid answer:** both APIs print the text plus newline
- **Edges:** forgetting `<cstdio>` for `printf`; mixing flush behavior

## 2. Intuition
C++ can call C stdio and C++ iostreams. Beginners should recognize both when reading mixed codebases.

## 3. Brute Force → Optimal
- **Naive:** only one style forever without knowing the other exists.
- **This approach:** place both side-by-side for the same string.

## 4. Data Structure / Approach Justification
No DS — two output calls.

| Alternative | Why it loses here |
|-------------|-------------------|
| Only `puts` | Narrower demo |
| Only `std::cout` | Misses C interop lesson in this question |

## 5. Logic Walkthrough
1. `std::printf` writes the C-string format.
2. `std::cout << ...` inserts the same text via streams.
3. `return 0` exits successfully.

## 6. Dry Run
Console:
```
Hello, World! 
Hello, World! 
```

## 7. Time & Space Complexity
- **Time:** O(1)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Prefer `std::cout` for type-safe C++; prefer `printf` for terse format strings / C APIs.

## 9. Common Mistakes / Edge Cases
Missing includes; `using namespace std;`; format/string mismatch with `printf`.

## 10. Interview Follow-ups / Variations
`std::endl` vs `'\n'`; syncing iostream with stdio (`std::ios::sync_with_stdio`).

## 11. Tags
`cpp-basics`, `iostream`, `cstdio`, `beginner`, `practice`
