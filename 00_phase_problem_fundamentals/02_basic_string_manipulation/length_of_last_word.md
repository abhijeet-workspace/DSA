# Length of Last Word

## 1. Problem Statement
[LeetCode 58](https://leetcode.com/problems/length-of-last-word/) — Return the length of the last word in `s`. Words are non-space substrings; `s` may have leading/trailing spaces.

- **Inputs:** `string s` (contains at least one word).
- **Output:** Integer length.
- **Edges:** Trailing spaces; single word; multiple spaces between words.

## 2. Intuition
Scan from the right: skip trailing spaces, then count characters until a space (or the start).

## 3. Brute Force → Optimal
`trim` + `split` then take last — clear but allocates. Right-to-left index scan is O(N) / O(1).

## 4. Data Structure / Approach Justification
**Chosen:** reverse index walk with two phases (skip spaces, count letters).

| Alternative | Why it loses here |
|-------------|-------------------|
| `stringstream` extraction | Extra allocations |
| Regex | Overkill |

Right-to-left scanning mirrors topic 1’s “direction of traversal” lesson on strings.

## 5. Logic Walkthrough
1. `i = n - 1`; while `s[i] == ' '`, `--i`.
2. `len = 0`; while `i >= 0` and not space, `++len`, `--i`.
3. Return `len`.

## 6. Dry Run
`Hello World` → skip no trailing space → count `d,l,r,o,W` → 5.

## 7. Time & Space Complexity
- **Time:** O(N) worst case (all spaces then one word at front)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Forward scan tracking “length since last space” also works in one pass.

## 9. Common Mistakes / Edge Cases
Counting trailing spaces as letters; unsigned underflow when `i` is `size_t`.

## 10. Interview Follow-ups / Variations
Length of first word; k-th last word.

## 11. Tags
`string`, `scan`, `leetcode-58`, `difficulty:easy`
