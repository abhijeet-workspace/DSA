# Valid Anagram

## 1. Problem Statement
Return `true` if `t` is an anagram of `s` (same letters, same counts).

- **Input:** strings `s`, `t` (lowercase a-z assumed)
- **Output:** bool
- **Valid answer:** true iff character multisets match
- **Edges:** different lengths; empty; unicode (extend map)

## 2. Intuition
Anagrams share a frequency signature. Count chars in `s`, subtract while scanning `t`.

## 3. Brute Force → Optimal
- **Brute:** sort both strings and compare — O(N log N).
- **Optimal:** frequency array of size 26 — O(N).

## 4. Data Structure / Approach Justification
`array<int,26>` — fixed alphabet, O(1) space.

| Alternative | Why it loses here |
|-------------|-------------------|
| Sort both | Slower; unnecessary when alphabet is tiny |
| `unordered_map` | Needed for unicode; overhead for a-z |

## 5. Logic Walkthrough
1. Length mismatch → false.
2. Increment counts for `s`.
3. Decrement for `t`; if any count goes negative → false.
4. All zero → true.

## 6. Dry Run
`s=anagram`, `t=nagaram` — after count/subtract, all 26 counters are 0 → **true**.  
`s=rat`, `t=car` — mismatch → **false**.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) for 26 buckets
- Why: one pass each string; fixed alphabet.

## 8. Trade-offs & Alternatives
Fixed 26 array is fastest for lowercase English. Use map for unicode / case-folding.

## 9. Common Mistakes / Edge Cases
Skipping length check; assuming only letters; off-by-one on `c - 'a'`.

## 10. Interview Follow-ups / Variations
Unicode? Case sensitivity? Group Anagrams (LC 49)?

## 11. Tags
`frequency`, `string`, `leetcode-242`, `easy`
