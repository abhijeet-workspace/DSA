# Find the Difference

## Problem Statement
[LeetCode 389](https://leetcode.com/problems/find-the-difference/) — `t` is a shuffled copy of `s` with one extra letter inserted at a random position. Return that extra character.

- **Inputs:** strings `s`, `t` (lowercase a–z).
- **Output:** the added character.
- **Edges:** empty `s` (answer is the sole char in `t`); duplicate letters in `s`.

## Intuition
Every character in `s` appears exactly once in `t` except the added letter, which appears one extra time. XOR pairs cancel (`x ^ x = 0`), so XOR-ing all chars in both strings leaves only the extra character.

## Brute Force → Optimal
- **Brute:** sort both strings and scan for first mismatch — O(N log N).
- **Optimal:** XOR (or ASCII sum) over both strings — O(N).

## Data Structure / Approach Justification
**Chosen:** single `char` accumulator via XOR — O(1) space.

| Alternative | Why it loses here |
|-------------|-------------------|
| 26-count array | Works (like Valid Anagram); extra space vs XOR |
| `unordered_map` | Overkill for fixed lowercase alphabet |
| Sort + compare | Slower; no benefit when linear scan suffices |

## Logic Walkthrough
1. `diff = 0`.
2. XOR every char in `s` into `diff`.
3. XOR every char in `t` into `diff`.
4. Return `diff` — the unmatched extra character.

## Dry Run
`s=abcd`, `t=abcde` — shared letters cancel; `e` remains → **e**.  
`s=""`, `t=y` — only `y` XORed → **y**.

## Time & Space Complexity
Time **O(N)** where N = `|t|`. Space **O(1)**.

## Trade-offs & Alternatives
ASCII sum: `sum(t) - sum(s)` also works in O(N) O(1). Frequency array matches the Valid Anagram / Ransom Note style if you prefer counting.

## Common Mistakes / Edge Cases
Forgetting chars in `t` that have no pair in `s`; assuming `t` is only one char longer (given by problem).

## Interview Follow-ups / Variations
Valid Anagram (242); Ransom Note (383); Find All Anagrams (438).

## Tags
`bit-manipulation`, `string`, `leetcode-389`, `difficulty:easy`
