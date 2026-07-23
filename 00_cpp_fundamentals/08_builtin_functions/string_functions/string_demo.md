# String Demo (`<string>`)

## Problem Statement
1. Parse an email: split username/domain; mask middle of username.
2. Parse a CSV line `"Name,Age,Salary"` into typed fields via `find`/`substr`/`stoi`/`stod`.

Also show `append`, `length`, `to_string`.

**Inputs:** email string; CSV line.  
**Edges:** missing `@`; fewer/more commas; non-numeric age/salary (`stoi` throws).

## Intuition
Most string parsing is “find delimiter → slice → convert.” `std::string` owns memory and exposes those primitives directly.

## Brute Force → Optimal
- **Brute:** character-by-character state machine or `stringstream` for every field.
- **Optimal for fixed 2–3 fields:** two `find`s + `substr` + `stoi`/`stod` → O(N).

## Data Structure / Approach Justification (REQUIRED)
`std::string` for owning text; `Employee` POD for typed CSV result.
- **vs `string_view`:** better for non-owning slices, but demo needs owned `Employee` fields and mutation (`append`, mask build).
- **vs regex:** heavier and overkill for single `@` / two commas.

## Logic Walkthrough
- `parseEmail`: `find('@')`; substr username/domain; build mask with front + stars + back.
- `parseCSVRecord`: first/second comma indices; `stoi`/`stod` conversions.
- `main`: append/`to_string` demos then both problems.

## Dry Run
`abhijeet.dev@gmail.com` → `a**********v@gmail.com`, domain `gmail.com`.  
`Rahul Sharma,21,75000.50` → name `Rahul Sharma`, age 21, salary 75000.5.

## Time & Space Complexity
**O(N)** time/space for masking and substrings (copies). Why: each field is copied into owning strings (section 4).

## Trade-offs & Alternatives
`string_view` + indices to avoid copies; `std::getline` with `stringstream` for N fields; dedicated CSV library for quoted commas.

## Common Mistakes / Edge Cases
Not checking `npos`; `substr` length off-by-one between commas; uncaught `std::invalid_argument` from `stoi`.

## Interview Follow-ups / Variations
RFC-compliant email parsing; quoted CSV fields; streaming large files line-by-line.

## Tags
`string`, `parsing`, `conversion`, `beginner`
