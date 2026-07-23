# Asymptotic Analysis

## 1. Problem Statement
Demonstrate common asymptotic classes in C++ and relate them to Big-O / Ω / Θ notation.

- **Input:** sample arrays (unsorted and sorted); small set `{1,2,3}` for subsets; sizes `{1000,5000,10000,50000}` for timing
- **Output:** results for O(1)/O(log n)/O(n)/O(n log n)/O(n²)/O(2ⁿ) demos; linear vs quadratic timing ratios
- **Valid answer:** each helper matches its stated class; subset count is `2^|S|`
- **Edge cases:** binary search needs sorted input; exponential demos only for tiny n

## 2. Intuition
Asymptotics describe growth as n → ∞. Drop constants and lower-order terms so you can compare algorithms by shape (log vs linear vs quadratic), not by machine constants.

## 3. Brute Force → Optimal
- **Naive:** only wall-clock timing — machine-dependent and noisy.
- **This approach:** classify by counting loops/recursion structure, then optionally confirm with a small empirical check (linear sum vs nested duplicate scan).

## 4. Data Structure / Approach Justification
**Chosen:** `std::vector` demos plus in-place merge sort / reverse to show time *and* extra space separately.

| Alternative | Why it loses here |
|-------------|-------------------|
| Pure math notes only | No runnable intuition for class jumps |
| Only `std::sort` | Hides the T(n)=2T(n/2)+O(n) structure |
| Hash set for duplicates | Changes the lesson from O(n²) to O(n) |

Trade-off: educational demos prioritize clarity over production libraries.

## 5. Logic Walkthrough
1. `getFirst` — one index read → O(1).
2. `binarySearch` — halve range each step → O(log n).
3. `linearSum` — one pass → O(n).
4. `mergeSort` — two halves + O(n) merge → Θ(n log n).
5. `hasDuplicateBrute` — nested pairs → O(n²).
6. `generateSubsets` — include/exclude each element → O(2ⁿ) leaves.
7. `reverseInPlace` — swaps with O(1) extra space; contrast with copy reverse.
8. `benchmarkLinearVsQuadratic` — time O(n) vs O(n²) on growing n.

## 6. Dry Run
Array `{3,1,4,1,5,9,2,6,5,3,5}`:
- `getFirst` → `3`
- sorted → binary search `5` finds some valid index
- `linearSum` → `44`
- merge sort → `{1,1,2,3,3,4,5,5,5,6,9}`
- duplicates → `true`
- subsets of `{1,2,3}` → `8`

## 7. Time & Space Complexity
| Routine | Time | Extra space |
|---------|------|-------------|
| getFirst | O(1) | O(1) |
| binarySearch | O(log n) | O(1) |
| linearSum | O(n) | O(1) |
| mergeSort | Θ(n log n) | O(n) |
| hasDuplicateBrute | O(n²) | O(1) |
| generateSubsets | O(2ⁿ · n) to materialize | O(n) stack + output |
| reverseInPlace | O(n) | O(1) |

Why: loop nesting and divide depth dictate the class (section 4).

## 8. Trade-offs & Alternatives
- Big-O is an *upper bound notation*, not synonymous with “worst case.”
- Prefer Θ when you know a tight bound (e.g. merge sort).
- Space complexity usually means *extra* memory beyond the input.

## 9. Common Mistakes / Edge Cases
- Calling binary search on unsorted data
- Treating `O(2n)` as different from `O(n)`
- Counting input size as “space complexity”
- Running O(2ⁿ) / O(n!) for large n

## 10. Interview Follow-ups / Variations
- Difference between O, Ω, Θ on the same algorithm?
- Why comparison sorting is Ω(n log n) in the comparison model?
- How cache effects can make Θ(n) look “slower” than expected?

## 11. Tags
`asymptotic-analysis`, `big-o`, `complexity`, `merge-sort`, `binary-search`, `difficulty:easy`
