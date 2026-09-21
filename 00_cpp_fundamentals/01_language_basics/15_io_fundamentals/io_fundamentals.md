# I/O Fundamentals

## 1. Problem Statement
Show basic console I/O: `std::cout`, `std::cin >>`, `std::getline`, clearing the leftover newline after `>>`, and checking stream state.

- **Input:** one integer, then one full line (interactive)
- **Output:** echoed values plus `good`/`fail` flags
- **Valid answer:** `>>` stops at whitespace; `getline` keeps spaces; ignore prevents empty line
- **Edges:** non-numeric input sets `failbit`

## 2. Intuition
`>>` extracts tokens. `getline` reads until newline. Mixing them without consuming the leftover `\n` is a classic beginner bug.

## 3. Brute Force → Optimal
- **Naive:** only use `cin >>` for everything (breaks on spaces).
- **This approach:** `>>` for tokens, `getline` for lines, `ignore` to bridge them.

## 4. Data Structure / Approach Justification
`std::string` for the line; scalars for the int.

| Alternative | Why it loses here |
|-------------|-------------------|
| C `scanf`/`printf` | Works; less idiomatic modern C++ |
| `iomanip` formatting | Covered in `08_builtin_functions` |

## 5. Logic Walkthrough
1. Print sample values with `cout`.
2. Read `n` with `cin >>`.
3. `ignore` remaining characters until newline.
4. `getline` into `line` and print size.
5. Report `good()` / `fail()`.

## 6. Dry Run
| User types | After `>>` | After `ignore` | After `getline` |
|------------|------------|----------------|-----------------|
| `42` then Enter, then `hello world` | n=42, `\n` left | buffer clear | line=`hello world` |

## 7. Time & Space Complexity
- **Time:** O(L) for line length L
- **Space:** O(L) for the string
- Why: line storage dominates

## 8. Trade-offs & Alternatives
- Prefer `getline` + parse when input format is free-form.
- Prefer `>>` for simple token streams.
- Check `fail()` after every critical read in real programs.

## 9. Common Mistakes / Edge Cases
- Mixing `>>` and `getline` without `ignore`
- Ignoring failed extraction and using the old value
- Assuming `cin >> string` reads spaces

## 10. Interview Follow-ups / Variations
- How do you clear `failbit` and retry?
- Difference between `'\n'` and `std::endl`?
- When use `std::cerr` vs `std::cout`?

## 11. Tags
`cpp-basics`, `iostream`, `getline`, `beginner`
