# Random Pick with Blacklist (LC 710)

## 1. Problem Statement
Pick uniformly from `[0, n)` excluding a blacklist, in O(1) after preprocess.

- **Inputs:** `n`, blacklist array.
- **Output:** `pick()` values never in blacklist.
- **Valid answer:** [LC 710](https://leetcode.com/problems/random-pick-with-blacklist/).
- **Edges:** empty blacklist; blacklist near end; duplicates in list.
- **Link:** [LC 710](https://leetcode.com/problems/random-pick-with-blacklist/)

## 2. Intuition
Map blacklisted indices in the allowed prefix to white indices in the suffix.

## 3. Brute Force → Optimal
- **Brute:** rejection sampling.
- **Remap:** O(1) pick.

## 4. Data Structure / Approach Justification
**Chosen:** whitelist size `m=n-|black|`; remap blacks in `[0,m)` to whites in `[m,n)`.

| Alternative | Note |
|-------------|------|
| Store all whites | O(n) memory |
| Skip list of intervals | Heavier |

## 5. Logic Walkthrough
1. Put blacklist in set.
2. Collect white numbers ≥ m.
3. Map each black < m to a white.

## 6. Dry Run
n=4, black={1,2} → picks in {0,3}.

## 7. Time & Space Complexity
Preprocess **O(|B|)**, pick **O(1)**.

## 8. Trade-offs & Alternatives
Elegant hashing trick.

## 9. Common Mistakes / Edge Cases
Wrong m; remapping whites; RNG modulus.

## 10. Interview Follow-ups / Variations
Dynamic blacklist; weighted.

## 11. Tags
`randomized`, `hashmap`, `lc-710`, `difficulty:hard`
