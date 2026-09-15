# Number of Substrings Containing All Three Characters

## 1. Problem Statement
[LeetCode 1358](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/) — given a string `s` of only `a`, `b`, and `c`, return how many substrings contain at least one of each character.

- **Input:** string `s` over `{a,b,c}`
- **Output:** count of valid substrings
- **Valid answer:** every substring that includes a, b, and c at least once
- **Edges:** length < 3; first valid at end; alternating pattern

**Prerequisite note:** Still a window idea (coverage of three chars), but often solved with last-seen indices — a compressed form of “shrink until all three present.” Two pointers with a frequency map of size ≤ 3 is the formal window version.

## 2. Intuition
At index `i`, if `a`, `b`, and `c` all appeared somewhere in `s[0..i]`, every start position from `0` through `min(lastA,lastB,lastC)` forms a valid substring ending at `i`.

## 3. Brute Force → Optimal
- **Brute:** all substrings + set of chars — O(N²).
- **Optimal:** last-index / sliding window — O(N).

## 4. Data Structure / Approach Justification
Three ints for last positions, or a window + `unordered_map`/`array<int,3>` counts.

| Alternative | Why it loses here |
|-------------|-------------------|
| Nested scans | O(N²) |
| Full min-window search per start | Heavier constant |

## 5. Logic Walkthrough
1. Update last index of `s[i]`.
2. Let `m = min(lastA, lastB, lastC)`.
3. If `m ≥ 0`, add `m + 1` to the answer.

## 6. Dry Run
`"abc"` — at index 2, min last = 0 → add 1 → **1**. `"abcabc"` accumulates to **10**.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)
- Why: one pass; constant state for three letters.

## 8. Trade-offs & Alternatives
Explicit expand/shrink with counts is clearer pedagogically; last-index is shorter for interviews.

## 9. Common Mistakes / Edge Cases
Adding `i − m` instead of `m + 1`; treating “exactly one each” vs “at least one”; empty / short strings.

## 10. Interview Follow-ups / Variations
At least K distinct; minimum window covering a,b,c; count substrings with all vowels.

## 11. Tags
`sliding-window`, `counting`, `string`, `leetcode-1358`, `medium`
