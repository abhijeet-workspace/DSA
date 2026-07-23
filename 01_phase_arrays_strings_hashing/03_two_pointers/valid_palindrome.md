# Valid Palindrome

## 1. Problem Statement
Check whether `s` is a palindrome ignoring non-alphanumeric characters and case.

- **Input:** string `s`
- **Output:** true/false
- **Edges:** empty; only punctuation; single char

## 2. Intuition
Opposite pointers skip junk and compare the filtered sequence without building a new string.

## 3. Brute Force → Optimal
- **Brute:** filter to lowercase alnum string, reverse-compare — O(N) space.
- **Optimal:** in-place two pointers — O(1) extra.

## 4. Data Structure / Approach Justification
Two indices on `string`; `isalnum`/`tolower` with `unsigned char` casts for defined behavior.

| Alternative | Why it loses here |
|-------------|-------------------|
| Build filtered copy | Extra O(N) memory |
| Regex then reverse | Heavier; same asymptotics |

## 5. Logic Walkthrough
1. `L`/`R` at ends.
2. Skip non-alnum on both sides.
3. Compare `tolower`; mismatch → false.
4. Meet → true.

## 6. Dry Run
`"A man, a plan, a canal: Panama"` → filtered `amanaplanacanalpanama` → true.
`"race a car"` → mismatch → false.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) auxiliary

## 8. Trade-offs & Alternatives
Unicode / locale-aware alnum is a separate product requirement; ASCII is the LC default.

## 9. Common Mistakes / Edge Cases
Missing `unsigned char` cast UB on signed char; not lowercasing; comparing before skip.

## 10. Interview Follow-ups / Variations
Almost palindrome (LC 680); palindrome linked list.

## 11. Tags
`two-pointers`, `string`, `palindrome`, `leetcode-125`
