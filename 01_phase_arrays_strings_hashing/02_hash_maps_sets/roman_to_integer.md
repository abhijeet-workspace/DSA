# Roman to Integer

## Problem Statement
[LeetCode 13](https://leetcode.com/problems/roman-to-integer/) — convert a valid Roman numeral string `s` to its integer value.

- **Inputs:** string `s` of symbols `I V X L C D M` (guaranteed valid).
- **Output:** `int` in `[1, 3999]`.
- **Valid answer:** additive values, with subtractive pairs `IV, IX, XL, XC, CD, CM`.
- **Edges:** all additive (`III`); mixed subtractive (`MCMXCIV`); single symbol.

## Intuition
Each symbol has a fixed value. If a smaller value appears immediately before a larger one, subtract it; otherwise add it.

## Brute Force → Optimal
- **Brute:** scan for two-char subtractive tokens first, else take one-char tokens — extra bookkeeping.
- **Optimal:** map each char; one left-to-right pass comparing `s[i]` with `s[i+1]` — O(N).

## Data Structure / Approach Justification
**Chosen:** `unordered_map<char,int>` of the seven symbols (hash-map topic).

| Alternative | Why it loses here |
|-------------|-------------------|
| Nested ifs / switch only | Same logic; harder to extend / read |
| Two-char lookup table | Correct but more states than needed |

## Logic Walkthrough
1. Map `I=1, V=5, X=10, L=50, C=100, D=500, M=1000`.
2. For each index `i`, let `cur = map[s[i]]`.
3. If `i+1` exists and `cur < map[s[i+1]]`, add `-cur`; else add `cur`.

## Dry Run
`MCMXCIV`: `M` add 1000; `C` before `M` subtract 100; `M` add 1000; `X` before `C` subtract 10; `C` add 100; `I` before `V` subtract 1; `V` add 5 → **1994**.

## Time & Space Complexity
Time **O(N)**. Space **O(1)** (seven keys). Why: one pass; fixed alphabet.

## Trade-offs & Alternatives
A 256-slot array indexed by `char` is faster and still O(1) space; map is clearer for interviews.

## Common Mistakes / Edge Cases
Adding every symbol then never subtracting; comparing with previous instead of next; assuming invalid input.

## Interview Follow-ups / Variations
Integer to Roman (12); validate a Roman string.

## Tags
`hash-map`, `string`, `math`, `leetcode-13`, `difficulty:easy`
