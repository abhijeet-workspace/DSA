# Cctype Demo (`<cctype>`)

## Problem Statement
Use character classification/case APIs to:
1. Validate password strength (length, upper, lower, digit, punct).
2. Sanitize free text: keep alphanumerics lowercase, collapse whitespace, drop punctuation.

**Inputs:** password string; dirty free-form string.  
**Valid answer:** per-rule Pass/FAIL + bool; cleaned string.  
**Edges:** empty input, all-whitespace, Unicode beyond `unsigned char` (demo assumes ASCII).

## Intuition
Passwords and sanitizers are character-class problems — `<cctype>` answers “what kind of char is this?” without manual range checks (`'A'..'Z'`).

## Brute Force → Optimal
- **Brute:** hand-coded ASCII ranges / regex for every class → verbose, easy to miss cases.
- **Optimal:** one pass with `isupper`/`islower`/`isdigit`/`ispunct`/`isalnum`/`isspace`/`tolower` → O(N).

## Data Structure / Approach Justification (REQUIRED)
Use `std::string` as the mutable/owning buffer for cleaned output.
- **vs C-string `char*`:** no automatic growth; harder to append safely.
- **vs `std::vector<char>`:** works but loses string convenience (`length`, `pop_back`, print).
Classification on `unsigned char` avoids UB for negative `char` values.

## Logic Walkthrough
- `validatePassword`: flags for each class; print metrics; return conjunction with `length >= 8`.
- `sanitizeInput`: alnum → lowercased append; space → single `' '` if not already; skip punct; trim trailing space.
- `main`: weak vs strong password; dirty input demo.

## Dry Run
`"P@ss123"` → length FAIL (7). `"SecureP@ss1234"` → all Pass.  
`"  Hello,   C++   World!!  123#  "` → `"hello c world 123"` (punctuation dropped, spaces collapsed).

## Time & Space Complexity
**O(N)** time, **O(N)** space for `cleaned` (worst case keep almost all chars). Why: single linear scan (section 4).

## Trade-offs & Alternatives
Locale-aware `std::isupper(c, locale)` for non-ASCII; Unicode needs ICU/`char32_t` — `<cctype>` is ASCII-centric.

## Common Mistakes / Edge Cases
Passing signed `char` to `<cctype>` without cast; treating `ispunct` as “all symbols” (currency etc. vary); forgetting trailing-space trim.

## Interview Follow-ups / Variations
Password entropy scoring; allowlist vs blocklist sanitization; streaming sanitizer without allocating full output.

## Tags
`cctype`, `strings`, `validation`, `beginner`
