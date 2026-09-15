# To Lower Case

## 1. Problem Statement
[LeetCode 709](https://leetcode.com/problems/to-lower-case/) — Return `s` with all uppercase English letters converted to lowercase.

- **Inputs:** `string s`.
- **Output:** Lowercased string.
- **Edges:** Already lowercase; empty; mixed with digits/symbols.

## 2. Intuition
ASCII uppercase sits in a contiguous block — offset by `'a' - 'A'` when `'A' <= c <= 'Z'`.

## 3. Brute Force → Optimal
`std::tolower` per char is fine; a manual range check makes the transform explicit for this topic.

## 4. Data Structure / Approach Justification
**Chosen:** in-place scan mutating each `char`.

| Alternative | Why it loses here |
|-------------|-------------------|
| Build a new string with `push_back` | Extra allocation; same asymptotics |
| Locale-aware `tolower` | Heavier; LC expects ASCII English |

Plain char-transform loop — no containers beyond the string itself.

## 5. Logic Walkthrough
1. For each character `c` in `s`.
2. If `'A' <= c <= 'Z'`, set `c = c - 'A' + 'a'`.
3. Return `s`.

## 6. Dry Run
`Hello` → `hello`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) extra (in-place)

## 8. Trade-offs & Alternatives
In-place vs copy depends on API; LC accepts either.

## 9. Common Mistakes / Edge Cases
Calling `tolower` on a signed `char` without an `unsigned char` cast on some platforms; transforming non-letters.

## 10. Interview Follow-ups / Variations
Toggle case; title case; Unicode (out of scope for LC ASCII).

## 11. Tags
`string`, `simulation`, `leetcode-709`, `difficulty:easy`
