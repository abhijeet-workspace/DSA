# Distinct Echo Substrings

## 1. Problem Statement
[LeetCode 1316](https://leetcode.com/problems/distinct-echo-substrings/) — count distinct substrings that equal some string repeated twice (`a+a`).

- **Inputs:** string `text`.
- **Output:** count of distinct echo substrings.
- **Valid answer:** set size of such substrings.
- **Edges:** all equal chars; no echoes.

## 2. Intuition
Echo of length `2k` means `s[i..i+k) == s[i+k..i+2k)`. Rolling hash compares halves in O(1); store hashes of full echo in a set.

## 3. Brute Force → Optimal
- **Brute:** all substrings compare — O(N³).
- **Optimal:** double rolling hash — O(N²).

## 4. Data Structure / Approach Justification
**Chosen:** prefix hashes + set of echo hashes.

- **vs Z-boxes:** possible but heavier.

## 5. Logic Walkthrough
For each i,k check half equality via hash; insert hash of `[i,i+2k)`.

## 6. Dry Run
`text="abcabcabc"` → **3** (`abcabc`, `bcabca`, `cabcab` — actually sample is 3).

## 7. Time & Space Complexity
Time **O(N²)**. Space **O(N²)** worst for set.

## 8. Trade-offs & Alternatives
Single hash risks collision; double hash safer.

## 9. Common Mistakes / Edge Cases
Counting occurrences not distinct; odd lengths.

## 10. Interview Follow-ups / Variations
Longest Duplicate Substring; Rabin–Karp.

## 11. Tags
`rolling-hash`, `string`, `leetcode-1316`, `difficulty:hard`
