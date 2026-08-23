# Random Pick with Weight

## Problem Statement
[LeetCode 528](https://leetcode.com/problems/random-pick-with-weight/) — weights `w`; `pickIndex()` returns i with probability `w[i] / sum(w)`.

- **Inputs:** `vector<int> w` in the constructor.
- **Output:** `int` index.
- **Valid answer:** a weighted random index.
- **Edges:** single weight; highly skewed weights.

## Intuition
Map the number line of prefix sums. Sample `r` in `[1, total]` and binary-search the first prefix ≥ r.

## Brute Force → Optimal
- **Brute:** scan subtracting weights — O(N) per pick.
- **Optimal:** prefix + binary search — O(log N) per pick after O(N) build.

## Data Structure / Approach Justification
**Chosen:** prefix sums as a discrete CDF.

- **vs alias method:** O(1) pick, more build code
- **vs linear scan:** too slow for many picks

## Logic Walkthrough
`partial_sum`. `upper_bound`/`lower_bound` of r on the prefix array.

## Dry Run
`w=[1,3]`: prefixes `[1,4]`. r=1 → 0; r=2,3,4 → 1.

## Time & Space Complexity
Build **O(N)**. Pick **O(log N)**. Space **O(N)**. Why: one prefix array; log search.

## Trade-offs & Alternatives
Use `std::discrete_distribution` in production C++.

## Common Mistakes / Edge Cases
Sampling `0..total-1` against prefixes that start at w[0]; modulo bias (ignore in interviews).

## Interview Follow-ups / Variations
Random pick index; snapshot array.

## Tags
`binary-search`, `prefix-sum`, `design`, `leetcode-528`, `difficulty:medium`
