# Ransom Note

## Problem Statement
[LeetCode 383](https://leetcode.com/problems/ransom-note/) — return `true` if `ransomNote` can be constructed from `magazine` letters (each letter used at most once).

- **Inputs:** strings `ransomNote`, `magazine` (lowercase).
- **Output:** bool.
- **Edges:** empty note; note longer than magazine; insufficient counts.

## Intuition
Count magazine frequencies; decrement while scanning the note. A negative count means shortage.

## Brute Force → Optimal
- **Brute:** for each note char, scan/remove from magazine — O(N·M).
- **Optimal:** 26-slot count array — O(N+M).

## Data Structure / Approach Justification
**Chosen:** `array<int,26>` like Valid Anagram (242).

| Alternative | Why it loses here |
|-------------|-------------------|
| Hash map | Same idea; heavier for a–z |
| Sorting both | O(N log N); overkill |

## Logic Walkthrough
1. Count magazine letters.
2. For each note letter, decrement; if `< 0`, return false.
3. Else true.

## Dry Run
`note=aa`, `mag=aab` → counts allow two `a` → **true**. `note=aa`, `mag=ab` → second `a` fails → **false**.

## Time & Space Complexity
Time **O(N+M)**. Space **O(1)** (26 slots).

## Trade-offs & Alternatives
Early exit if `note.size() > magazine.size()`.

## Common Mistakes / Edge Cases
Requiring anagram (equal lengths); uppercase assumptions.

## Interview Follow-ups / Variations
Valid Anagram (242); Find All Anagrams (438).

## Tags
`hash-map`, `counting`, `string`, `leetcode-383`, `difficulty:easy`
