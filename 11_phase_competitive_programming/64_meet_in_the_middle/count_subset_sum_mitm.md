# Count Subset Sum (MITM)

## 1. Problem Statement
Count the number of subsets that sum to `target` (N≈40 teaching scale).

- **Inputs:** array, target.
- **Output:** count of subsets (including empty if target 0).
- **Edges:** zeros; duplicate sums.

## 2. Intuition
Enum left/right sums; for each left, add multiplicity of `target-left` in right via map or sorted equal_range.

## 3. Brute Force → Optimal
- **Brute:** 2^N.
- **MITM:** 2^(N/2).

## 4. Data Structure / Approach Justification
**Chosen:** unordered_map frequencies on right sums.

| Alternative | Note |
|-------------|------|
| DP | If sums bounded |

## 5. Logic Walkthrough
1. Enum sumsL, sumsR.
2. Freq map R.
3. Accumulate map[target-s].

## 6. Dry Run
`[1,1,1]`, target 2 → **3**.

## 7. Time & Space Complexity
**O(2^(N/2))** expected with hashing.

## 8. Trade-offs & Alternatives
Overflow of counts for large N — use 64-bit.

## 9. Common Mistakes / Edge Cases
Double-counting empty; forgetting multiplicities.

## 10. Interview Follow-ups / Variations
Mod p; count with size constraint.

## 11. Tags
`meet-in-the-middle`, `subset-sum`, `counting`, `difficulty:hard`
