# Reduce Array Size to The Half

## 1. Problem Statement
[LeetCode 1338](https://leetcode.com/problems/reduce-array-size-to-the-half/) — Choose a smallest set of distinct values to remove so at least half the array’s elements are gone. Return set size.

- **Inputs:** `vector<int> arr` (even length).
- **Output:** Minimum number of distinct values to remove.
- **Edges:** One value fills array; all unique.

## 2. Intuition
Greedy: remove highest-frequency values first until ≥ n/2 elements are deleted.

## 3. Brute Force → Optimal
Try subsets — exponential. Count + sort frequencies.

## 4. Data Structure / Approach Justification
**Chosen:** frequency bag, sort counts descending, greedy consume.

Greedy-on-frequencies — not yet the full greedy-algorithms topic, but frequency drives the choice.

A general `unordered_map` also works and is the idiomatic tool once topic 6 formalizes hashmap patterns. Here we prefer a **fixed alphabet/value table** where constraints allow, so the skill is "count occurrences," not "design a hash table API." When values are sparse we may still use `unordered_map` as a **counting bag** — framed as frequency storage, not as the Two Sum / Group Anagrams pattern unit.

## 5. Logic Walkthrough
1. Count.
2. Sort counts desc.
3. Accumulate until ≥ n/2; return how many counts used.

## 6. Dry Run
[3×4, 5×3, 2×2, 7] → take 3s then 5s → 7≥5 → answer 2.

## 7. Time & Space Complexity
- **Time:** O(N + U log U)
- **Space:** O(U)

## 8. Trade-offs & Alternatives
Heap of counts also works (topic 22 flavor).

## 9. Common Mistakes / Edge Cases
Removing values until half of *distinct* count; off-by-one on `n/2`.

## 10. Interview Follow-ups / Variations
Exactly half; weighted removals.

## 11. Tags
`array`, `frequency`, `greedy`, `leetcode-1338`, `difficulty:medium`
