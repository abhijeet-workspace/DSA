# Find the Shortest Superstring

## Problem Statement
[LeetCode 943](https://leetcode.com/problems/find-the-shortest-superstring/) — shortest string containing each word as substring (TSP on overlaps).

- **Inputs:** `words`.
- **Output:** shortest superstring.
- **Valid answer:** any min-length superstring.
- **Edges:** n=1; no overlaps.

## Intuition
Overlap[i][j] = max suffix of i matching prefix of j; Held-Karp DP.

## Brute Force → Optimal
- **Brute:** permutations.
- **Optimal:** O(N^2*2^N) bitmask TSP.

## Data Structure / Approach Justification
**Chosen:** dp[mask][i] best string ending at i covering mask.

## Logic Walkthrough
Reconstruct parent or store strings (n small).

## Dry Run
words=[catg,ctaagt,gcta,ttca,atgcatc] -> length 16 sample.

## Time & Space Complexity
Time **O(N^2*2^N)**. Space **O(N*2^N)**. Why: TSP (section 4).

## Trade-offs & Alternatives
n<=12.

## Common Mistakes / Edge Cases
Wrong overlap computation.

## Interview Follow-ups / Variations
TSP; Shortest Path Visiting All Nodes.

## Tags
`bitmask-dp`, `tsp`, `leetcode-943`, `difficulty:hard`
