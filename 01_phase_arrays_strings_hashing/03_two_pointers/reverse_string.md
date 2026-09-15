# Reverse String

## Problem Statement
[LeetCode 344](https://leetcode.com/problems/reverse-string/) — reverse a character array **in-place** with O(1) extra memory.

- **Input:** `vector<char> s`
- **Output:** same vector reversed (modify in place)
- **Edges:** empty; length 1; even/odd length

## Intuition
Mirror positions: first ↔ last, second ↔ second-last. Two pointers closing from the ends implement that swap pattern.

## Brute Force → Optimal
- **Brute:** build a new reversed array — O(N) extra space.
- **Optimal:** in-place two-pointer swaps — O(1) space.

## Data Structure / Approach Justification
Index pair `(L, R)` on the mutable array — no auxiliary buffer needed.

| Alternative | Why it loses here |
|-------------|-------------------|
| Extra buffer + copy | Violates O(1) space constraint |
| `std::reverse` | Fine in practice; interview wants the pointer logic |

## Logic Walkthrough
1. `L = 0`, `R = n - 1`.
2. While `L < R`, swap `s[L]` and `s[R]`, then `++L`, `--R`.

## Dry Run
`['h','e','l','l','o']`: swap h↔o, e↔l → `['o','l','l','e','h']`.

## Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) auxiliary
- Why: each element swapped at most once.

## Trade-offs & Alternatives
Recursive reverse uses O(N) stack. Library reverse is identical asymptotically.

## Common Mistakes / Edge Cases
Looping while `L <= R` and double-swapping the middle; allocating a new string; off-by-one on empty input.

## Interview Follow-ups / Variations
Reverse words in a string (151); reverse only vowels; reverse linked list analogy.

## Tags
`two-pointers`, `in-place`, `string`, `leetcode-344`, `easy`
