# Longest Common Subpath

## 1. Problem Statement
[LeetCode 1923](https://leetcode.com/problems/longest-common-subpath/) — longest common contiguous subpath among ≥2 paths (node id sequences).

- **Inputs:** `n` cities (unused in hash demo), `paths`.
- **Output:** length of longest common subpath.
- **Edges:** no common → 0; one path.

## 2. Intuition
Binary search length; rolling-hash set intersection across paths. Suffix structures on concatenated paths also work.

## 3. Brute Force → Optimal
- **Brute:** huge.
- **Hash+BS:** practical.
- **Generalized SA:** contest alternative.

## 4. Data Structure / Approach Justification
**Chosen:** BS + single-mod hash intersection (verify omitted for short demo; collisions rare on samples).

| Alternative | Note |
|-------------|------|
| SA of all paths with sentinels | Deterministic |
| Double hash | Safer |

**Pedagogy:** binary search + rolling hash (or SA) on paths; SA folder focus is string analogues.

## 5. Logic Walkthrough
BS mid; for each path insert window hashes; intersect sets.

## 6. Dry Run
Sample → length `2`.

## 7. Time & Space Complexity
Time **O(L log L)** with L total length. Space **O(L)**.

## 8. Trade-offs & Alternatives
Sibling of multi-string LCS via SA in this folder.

## 9. Common Mistakes / Edge Cases
Single hash collisions; empty intersection mishandled.

## 10. Interview Follow-ups / Variations
`longest_common_substring_k_strings`.

## 11. Tags
`leetcode-1923`, `rolling-hash`, `binary-search`, `difficulty:hard`
