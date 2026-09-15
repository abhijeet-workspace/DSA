# Largest Number

## 1. Problem Statement
[LeetCode 179](https://leetcode.com/problems/largest-number/) — rearrange a list of non-negative integers so their concatenation forms the largest possible number; return it as a string.

- **Inputs:** `vector<int> nums`.
- **Output:** string of the largest concatenation (no leading zeros except `"0"`).
- **Valid answer:** unique numeric string for a given multiset.
- **Edges:** all zeros; single element; numbers like `30` vs `3`.

## 2. Intuition
Numeric ascending/descending order fails (`3` before `30` → `330` > `303`). Compare pairs by concatenated order: `a` before `b` iff `a+b > b+a`.

## 3. Brute Force → Optimal
- **Brute:** try all permutations — O(N!).
- **Optimal:** convert to strings, sort with concat comparator, join — O(N log N · L) where L is digit length.

## 4. Data Structure / Approach Justification
**Chosen:** `vector<string>` + custom `std::sort` comparator.

| Alternative | Why we skip it here |
|-------------|---------------------|
| Heap of strings with same comparator | Same idea; sort is simpler |
| Digit DP / math tricks | Overkill for interview |

## 5. Logic Walkthrough
1. Map each int → decimal string.
2. Sort so `a` precedes `b` when `a+b > b+a`.
3. If the largest piece is `"0"`, return `"0"`.
4. Concatenate sorted pieces.

## 6. Dry Run
`[3,30,34,5,9]` → order `9,5,34,3,30` → `"9534330"`.

## 7. Time & Space Complexity
- **Time:** O(N log N · L) for string compares during sort.
- **Space:** O(N · L) for string copies / output.

## 8. Trade-offs & Alternatives
Comparator must be transitive for the domain (it is for this concat order). Watch leading-zero collapse.

## 9. Common Mistakes / Edge Cases
Sorting by integer value; forgetting all-zeros → `"0"`; unstable assumptions about equal prefixes; using `<` instead of concat compare.

## 10. Interview Follow-ups / Variations
Smallest number concatenation; prove comparator correctness; handle very large digit counts.

## 11. Tags
`sorting`, `custom-comparator`, `string`, `leetcode-179`, `difficulty:medium`
