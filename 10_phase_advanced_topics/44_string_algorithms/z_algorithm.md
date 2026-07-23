# Z-Algorithm

## Problem Statement
Compute the Z-array of a string, and use it to find all occurrences of a pattern in a text in linear time.

- **Inputs:** string `s` for Z; or `pattern` + `text` for search via `pattern + "$" + text`.
- **Output:** `Z[i]` = length of longest prefix of `s` that is also a prefix of `s[i..]`; match start indices for search.
- **Valid answer:** `Z[0]` conventionally 0/unused; matches only where `Z[i] == |pattern|`.
- **Edges:** empty; all equal chars; no matches; sentinel must not appear in alphabet (or choose unused char).

## Intuition
Maintain the rightmost segment `[L,R]` that matches the prefix (“Z-box”). Positions inside it already know a lower bound from `Z[i-L]`, so you copy/min then only extend when needed.

## Brute Force → Optimal
- **Brute:** for each `i`, compare with prefix — O(N²).
- **Optimal:** Z-algorithm — O(N).

## Data Structure / Approach Justification
**Chosen:** single `vector<int> Z` plus box `[L,R]`; search concatenates with sentinel `$`.

- **vs KMP:** similar power; Z is often easier for listing matches / prefix properties.
- **vs Rabin–Karp:** deterministic linear without hash collisions.

## Logic Walkthrough
For `i=1..n-1`: if `i < R`, set `Z[i] = min(R-i, Z[i-L])`. Extend while chars match. If `i+Z[i] > R`, set `L=i`, `R=i+Z[i]`. For search, any `Z[i]==m` past the sentinel is a hit at `i-m-1`.

## Dry Run
`s="aabxaa"` → `Z[4]=2` (`"aa"`), `Z[5]=1`.
`pattern="aa"`, `text="aabxaa"` → matches at **0** and **4** (2 hits).

## Time & Space Complexity
Time **O(N)**; space **O(N)** for Z (and concat). Why: `R` advances at most N times across extensions (section 4).

## Trade-offs & Alternatives
Prefer Z for CP string tasks and occurrence listing. Prefer KMP when LPS/borders are the teaching target. Hashing for approximate / multi-pattern pipelines.

## Common Mistakes / Edge Cases
Missing sentinel between pattern and text; alphabet containing `$`; forgetting `Z[0]`; off-by-one when mapping concat index to text index.

## Interview Follow-ups / Variations
Count distinct substrings; string compression via borders; compare with KMP failure function duality.

## Tags
`string`, `z-algorithm`, `pattern-matching`, `prefix`, `difficulty:medium`
