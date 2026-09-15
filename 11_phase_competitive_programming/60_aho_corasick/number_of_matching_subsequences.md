# Number of Matching Subsequences (LC 792)

## 1. Problem Statement
Count how many strings in `words` are subsequences of `s`.

- **Inputs:** string `s`, list `words`.
- **Output:** count of matching words.
- **Valid answer:** [LC 792](https://leetcode.com/problems/number-of-matching-subsequences/).
- **Edges:** duplicate words; empty word; letters not in `s`.
- **AC angle:** multi-pointer buckets / next-position maps are usual; AC can match patterns as subsequences only with care — lab uses next-index pointers (standard).
- **Link:** [LC 792](https://leetcode.com/problems/number-of-matching-subsequences/)

## 2. Intuition
Process all words in parallel: bucket waiting heads by next needed char; advance when that char appears in `s`.

## 3. Brute Force → Optimal
- **Brute:** check each word as subsequence O(|s|·Σ|w|).
- **Better:** one pass over `s` with buckets — O(|s| + Σ|w|).

## 4. Data Structure / Approach Justification
**Chosen:** queues of (word index, offset) keyed by next character.

| Alternative | Note |
|-------------|------|
| Precompute next[pos][c] | Also common |
| Aho on patterns | Better for contiguous substrings |

## 5. Logic Walkthrough
1. Bucket each word at its first char.
2. For each char `c` in `s`, pop that bucket and advance offsets.
3. Finished words increment answer.

## 6. Dry Run
`s=abcde`, words `{a,bb,acd,ace}` → **3** (`bb` fails).

## 7. Time & Space Complexity
**O(|s| + Σ|w|)**. Space **O(#words)**.

## 8. Trade-offs & Alternatives
Bucket method is the LC sweet spot. Reserve AC for contiguous multi-pattern.

## 9. Common Mistakes / Edge Cases
Treating subsequence as substring; advancing past end incorrectly.

## 10. Interview Follow-ups / Variations
List matching words; online stream of `s`; case with huge alphabet.

## 11. Tags
`subsequence`, `multi-pointer`, `lc-792`, `difficulty:medium`
