# Relative Sort Array

## 1. Problem Statement
[LeetCode 1122](https://leetcode.com/problems/relative-sort-array/) — sort `arr1` so that values appearing in `arr2` come first in `arr2`'s order (preserving multiplicity from `arr1`). Values not in `arr2` follow in ascending order.

- **Inputs:** `vector<int> arr1`, `vector<int> arr2` (distinct elements).
- **Output:** rearranged `arr1`.
- **Valid answer:** relative order of `arr2` keys, then remaining sorted.
- **Edges:** `arr2` covers all of `arr1`; no overlap; duplicates in `arr1`.

## 2. Intuition
Assign each `arr2` value a rank index. Custom-compare: ranked keys by rank; unranked keys after all ranks, ordered by value.

## 3. Brute Force → Optimal
- **Brute:** for each `arr2` value, scan `arr1` and collect matches, then sort leftovers — O(|arr2|·N + N log N).
- **Optimal:** frequency / counting map or one custom sort with rank map — O(N log N) or O(N+K).

## 4. Data Structure / Approach Justification
**Chosen:** `unordered_map` rank + `std::sort` comparator (clear custom-order lesson).

| Alternative | Why we skip it here |
|-------------|---------------------|
| Counting array (values ≤ 1000) | Faster O(N+K); less general |
| Stable multi-pass collect | Fine interview answer; more code |

## 5. Logic Walkthrough
1. Map each `arr2[i]` → rank `i`.
2. Sort `arr1` with comparator: if both ranked, compare ranks; else push unranked after ranked; among unranked compare values.
3. Return sorted `arr1`.

## 6. Dry Run
`arr1=[2,3,1,3,2,4,6,7,9,2,19]`, `arr2=[2,1,4,3,9,6]` → `2,2,2,1,4,3,3,9,6,7,19`.

## 7. Time & Space Complexity
- **Time:** O(N log N) sort + O(M) rank build.
- **Space:** O(M) for rank map (sort may use O(log N)).

## 8. Trade-offs & Alternatives
Counting sort wins under small value bounds. Comparator approach generalizes to arbitrary custom orders.

## 9. Common Mistakes / Edge Cases
Treating `arr2` as unique requirement for `arr1` values; unstable placement of duplicates; sorting unranked before finishing `arr2` keys.

## 10. Interview Follow-ups / Variations
Counting-sort O(N+K); relative order without mutating; custom sort of strings by priority list.

## 11. Tags
`sorting`, `custom-comparator`, `hashmap`, `leetcode-1122`, `difficulty:easy`
