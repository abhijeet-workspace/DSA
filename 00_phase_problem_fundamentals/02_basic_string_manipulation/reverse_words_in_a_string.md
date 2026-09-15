# Reverse Words in a String

## 1. Problem Statement
[LeetCode 151](https://leetcode.com/problems/reverse-words-in-a-string/) — Reverse the order of words in `s`. Trim leading/trailing spaces and collapse multiple spaces to one.

- **Inputs:** `string s`.
- **Output:** Normalized reversed-word string.
- **Edges:** Leading/trailing spaces; repeated spaces; single word.

## 2. Intuition
First normalize spacing, then either (a) split and reverse the word list, or (b) reverse the whole string and reverse each word span (classic in-place style).

## 3. Brute Force → Optimal
`stringstream` into a vector, reverse, join — clear O(N) with extra memory. Clean + double reverse is also O(N) and teaches span reverses.

## 4. Data Structure / Approach Justification
**Chosen:** build a cleaned string, reverse all, reverse each word.

| Alternative | Why it loses / when to use |
|-------------|----------------------------|
| Stack of words | Natural; extra structures |
| Only `stringstream` | Fine in interviews; less index practice |

Word-span reverses reuse the same position-arithmetic habit as LC 557, now with order reversal.

## 5. Logic Walkthrough
1. Scan `s` into `cleaned` with single spaces and no edges.
2. Reverse entire `cleaned`.
3. Reverse each `[i, j)` word span.
4. Return.

## 6. Dry Run
`  hello world  ` → `hello world` → `dlrow olleh` → `world hello`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(N) for cleaned copy (can be tightened with in-place two-pass edits)

## 8. Trade-offs & Alternatives
Fully in-place cleaning is a common follow-up; a vector of words is the fastest to code under time pressure.

## 9. Common Mistakes / Edge Cases
Leaving double spaces; trailing space after join; reversing characters but not word order.

## 10. Interview Follow-ups / Variations
LC 557 (per-word only); rotate words by k; in-place O(1) extra.

## 11. Tags
`string`, `reverse`, `leetcode-151`, `difficulty:medium`
