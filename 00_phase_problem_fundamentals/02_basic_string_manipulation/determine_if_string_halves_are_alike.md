# Determine if String Halves Are Alike

## 1. Problem Statement
[LeetCode 1704](https://leetcode.com/problems/determine-if-string-halves-are-alike/) — Split even-length `s` into equal halves. Return whether both halves have the same number of vowels (`a,e,i,o,u`, case-insensitive).

- **Inputs:** `string s` (even length).
- **Output:** `bool`.
- **Edges:** No vowels; all vowels; mixed case.

## 2. Intuition
Count vowels on `[0, n/2)` and `[n/2, n)` independently; compare the counts.

## 3. Brute Force → Optimal
Extract halves with `substr` then count — extra copies. Index ranges avoid that.

## 4. Data Structure / Approach Justification
**Chosen:** two range scans + vowel helper predicate.

| Alternative | Why it loses here |
|-------------|-------------------|
| `substr` then scan | Extra O(N) allocations |
| Hash set of vowels | Fine; a five-letter predicate is enough |

Fixed vowel membership is a tiny predicate, not the general-key hashmap pattern from topic 6.

## 5. Logic Walkthrough
1. Count vowels in the left half.
2. Count vowels in the right half.
3. Return whether the counts are equal.

## 6. Dry Run
`book` → left `bo` (1), right `ok` (1) → true. `textbook` → 2 vs 4 → false.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
One pass with `+1` on the left half and `-1` on the right also works; two loops are clearer.

## 9. Common Mistakes / Edge Cases
Forgetting case-insensitivity; mid-index off-by-one (problem guarantees even length).

## 10. Interview Follow-ups / Variations
Alike under consonant counts; k-way splits.

## 11. Tags
`string`, `counting`, `leetcode-1704`, `difficulty:easy`
