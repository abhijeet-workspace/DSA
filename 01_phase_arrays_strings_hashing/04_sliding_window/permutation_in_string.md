# Permutation in String

## 1. Problem Statement
Return `true` if `s2` contains a permutation of `s1` as a contiguous substring.

- **Input:** strings `s1`, `s2` (lowercase a-z)
- **Output:** bool
- **Valid answer:** some window of length `|s1|` matches `s1`'s frequency
- **Edges:** `|s1| > |s2|`; equal strings; single char

## 2. Intuition
A permutation is a frequency match. Slide a fixed window of size `|s1|` over `s2`.

## 3. Brute Force → Optimal
- **Brute:** for each window, sort/compare — O((N−M)·M log M).
- **Optimal:** maintain 26-count arrays; compare after each slide — O(N).

## 4. Data Structure / Approach Justification
Two `vector<int>(26)` count arrays; fixed window of length `n1`.

| Alternative | Why it loses here |
|-------------|-------------------|
| Sort each window | Extra log / copy cost |
| `matches` counter | Faster compares, more bookkeeping |

## 5. Logic Walkthrough
1. If `n1 > n2` → false.
2. Count first window of `s2` and all of `s1`.
3. Equal → true; else slide: ++incoming, −−outgoing; recheck.

## 6. Dry Run
`s1=ab`, `s2=eidbaooo`
- windows of size 2: ei, id, db, **ba** (matches) → **true**

## 7. Time & Space Complexity
- **Time:** O(N) where N = `|s2|` (26-compare is O(1))
- **Space:** O(1) (26 buckets)
- Why: each char enters/leaves once.

## 8. Trade-offs & Alternatives
Track a `matches` integer to avoid full array compare each step — same asymptotics, less constant.

## 9. Common Mistakes / Edge Cases
Variable window instead of fixed `|s1|`; forgetting length guard; uppercase input.

## 10. Interview Follow-ups / Variations
Find all start indices (LC 438 Find All Anagrams)?

## 11. Tags
`sliding-window`, `anagram`, `leetcode-567`, `medium`
