# Minimum Window Substring

## 1. Problem Statement
Smallest substring of `s` that covers all characters in `t` (with multiplicities).

- **Input:** strings `s`, `t`
- **Output:** min window string, or `""` if impossible
- **Valid answer:** shortest covering substring (any if ties — usually leftmost found)
- **Edges:** t longer than s; no answer; duplicates in t; single char

## 2. Intuition
Expand right until need is satisfied; shrink left while still valid; remember the shortest.

## 3. Brute Force → Optimal
- **Brute:** all substrings — O(N² · Σ).
- **Optimal:** sliding window with need/have counters — O(|s|+|t|).

## 4. Data Structure / Approach Justification
`unordered_map` for `need` and `window`; `formed` vs `required` unique chars.

| Alternative | Why it loses here |
|-------------|-------------------|
| Set of chars | Fails when `t` has duplicates |
| Check all substrings | Quadratic |

## 5. Logic Walkthrough
1. Build `need` from `t`; `required = need.size()`.
2. Expand right; when `window[c] == need[c]`, ++formed.
3. While formed == required: update best, shrink left, maybe −−formed.
4. Return substring or `""`.

## 6. Dry Run
`s=ADOBECODEBANC`, `t=ABC` — first cover ends at C; shrink to **BANC** (len 4).

## 7. Time & Space Complexity
- **Time:** O(|s| + |t|)
- **Space:** O(|alphabet|)
- Why: each index enters/leaves at most once.

## 8. Trade-offs & Alternatives
Array[128] if ASCII. Sparse/RMQ approaches are overkill for interviews.

## 9. Common Mistakes / Edge Cases
Using a set instead of counts; updating `formed` on every increment (not only equality); empty `t`.

## 10. Interview Follow-ups / Variations
Return all min windows? Subsequence version?

## 11. Tags
`sliding-window`, `hash-map`, `leetcode-76`, `hard`
