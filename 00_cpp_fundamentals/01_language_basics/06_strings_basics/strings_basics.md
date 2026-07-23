# Strings Basics

## 1. Problem Statement
Show two ways to hold text in C++: a C-style `char` array and a `std::string`, and print their lengths.

- **Input:** none (hardcoded `"Rahul"` and `"Delhi"`)
- **Output:** length of `name`, then city text and `city.size()`
- **Valid answer:** `strlen(name) == 5`, `city.size() == 5`
- **Edges:** C-strings need a terminating `'\0'`; buffer must be large enough

## 2. Intuition
C-strings are raw character arrays ending in `'\0'`. `std::string` owns its buffer and exposes safer APIs like `size()`, `+`, and bounds-aware access patterns.

## 3. Brute Force → Optimal
- **Naive:** only use `char[]` / `strcpy` forever.
- **This approach:** place both side-by-side so you see when each appears in real codebases.

## 4. Data Structure / Approach Justification
| Choice | Role here |
|--------|-----------|
| `char name[20]` | Shows fixed buffer + `strlen` |
| `std::string city` | Shows owning dynamic string |

| Alternative | Why it loses here |
|-------------|-------------------|
| `std::string_view` | Great for non-owning views; advanced for this lesson |
| Only `printf("%s")` | Skips the C++ string type you’ll use in DSA code |

## 5. Logic Walkthrough
1. `name` is initialized with `"Rahul"` (compiler adds `'\0'`).
2. `std::strlen(name)` walks until `'\0'` → 5.
3. `city` stores `"Delhi"`; `city.size()` returns 5 without a manual scan API for beginners.

## 6. Dry Run
| Object | Content | Length API | Result |
|--------|---------|------------|--------|
| `name` | `R a h u l \0 ...` | `strlen` | 5 |
| `city` | `"Delhi"` | `size()` | 5 |

## 7. Time & Space Complexity
- **Time:** O(L) for `strlen` on length L; `size()` is O(1) for `std::string`
- **Space:** O(1) extra beyond the buffers shown (`name[20]` fixed; `city` heap/SSO)
- Why: length scan vs cached size field

## 8. Trade-offs & Alternatives
- Prefer `std::string` for ownership and growth.
- Prefer `string_view` for read-only non-owning slices (C++17+).
- Keep C-strings when talking to C APIs.

## 9. Common Mistakes / Edge Cases
- Buffer overflow writing past `name[20]`
- Forgetting null terminator when building C-strings manually
- Using `sizeof(name)` as string length (counts capacity, includes unused bytes)
- Modifying string literals via `char*` (undefined behavior) — use arrays or `std::string`

## 10. Interview Follow-ups / Variations
- How does SSO (small string optimization) work?
- Difference between `size()` and `capacity()`?
- How do you concatenate safely vs `strcat`?

## 11. Tags
`cpp-basics`, `strings`, `cstring`, `beginner`
