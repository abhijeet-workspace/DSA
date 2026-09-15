# Find All Anagrams in a String

## Problem Statement
[LeetCode 438](https://leetcode.com/problems/find-all-anagrams-in-a-string/) — find all start indices in `s` where a substring is an anagram of `p`.

- **Input:** strings `s`, `p` (lowercase English)
- **Output:** list of starting indices
- **Edges:** `|p| > |s|`; overlapping anagrams; empty `p` (not on LC)

## Intuition
Anagrams share letter counts. A fixed window of length `|p|` is an anagram iff its 26-count equals `p`'s count.

## Brute Force → Optimal
- **Brute:** for each start, sort substring or recount — O(N·M) or worse with sorting.
- **Optimal:** slide fixed window updating counts in O(1) — O(N).

## Data Structure / Approach Justification
Two `vector<int>(26)` frequency arrays; compare equality each step (or maintain a “matches” counter).

| Alternative | Why it loses here |
|-------------|-------------------|
| Sort each window | O(N · M log M) |
| Hash sorted key | Extra allocations |

## Logic Walkthrough
1. Build `need` from `p`; fill first window of `s`.
2. If equal, record index 0.
3. Slide: add `s[i]`, remove `s[i-m]`; if equal, record `i-m+1`.

## Dry Run
`s="cbaebabacd"`, `p="abc"`: window `[0..2]=cba` matches → 0; later `[6..8]=bac` matches → **[0,6]**.

## Time & Space Complexity
- **Time:** O(N) with O(1) alphabet compare (26)
- **Space:** O(1) for counts (+ O(K) for answer)
- Why: each character enters/leaves once.

## Trade-offs & Alternatives
Same as Permutation in String (567) but collect all starts. Match-counter avoids full array compares.

## Common Mistakes / Edge Cases
Variable window instead of fixed `|p|`; forgetting to remove left char; assuming non-overlapping only.

## Interview Follow-ups / Variations
Permutation in String (567); Group Anagrams (49); unicode alphabet.

## Tags
`sliding-window`, `anagram`, `hashing`, `leetcode-438`, `medium`
