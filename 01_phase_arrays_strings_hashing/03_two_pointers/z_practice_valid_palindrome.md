# Practice — Valid Palindrome

## 1. Problem Statement
Practice drill: alphanumeric-only, case-insensitive palindrome check (LC 125 pattern).

- **Input:** string `s`
- **Output:** 1/0 (bool as int via stream)
- **Edges:** punctuation-only; mixed case

## 2. Intuition
Opposite pointers with skip + `tolower` — same as `valid_palindrome`.

## 3. Brute Force → Optimal
- **Brute:** filtered copy + reverse.
- **This drill:** O(1) space two pointers.

## 4. Data Structure / Approach Justification
String indices + `<cctype>` helpers with `unsigned char` casts.

| Alternative | Why it loses here |
|-------------|-------------------|
| Extra filtered string | Uses O(N) space |

## 5. Logic Walkthrough
Skip → compare → move inward until meet or mismatch.

## 6. Dry Run
Panama → true (1); race a car → false (0).

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Mirrors production `valid_palindrome.cpp`; keep casts for safety.

## 9. Common Mistakes / Edge Cases
Using `isalnum` on plain `char` (UB risk); forgetting case fold.

## 10. Interview Follow-ups / Variations
LC 680 almost-palindrome practice.

## 11. Tags
`practice`, `two-pointers`, `palindrome`, `string`
