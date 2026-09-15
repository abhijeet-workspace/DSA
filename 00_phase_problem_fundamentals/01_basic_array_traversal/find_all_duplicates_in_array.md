# Find All Duplicates in an Array

## 1. Problem Statement
[LeetCode 442](https://leetcode.com/problems/find-all-duplicates-in-an-array/) — `nums` length `n` with values in `[1, n]`. Each appears once or twice. Return all values that appear twice. O(N) time and O(1) extra space (output excluded).

- **Inputs:** `vector<int>& nums`.
- **Output:** `vector<int>` of duplicates (any order).
- **Edges:** No duplicates; all pairs; `n = 1`.

## 2. Intuition
Values are valid indices (`v → v-1`). Negate the cell at that index to mean “seen.” A second visit to an already-negative cell means `v` is a duplicate.

## 3. Brute Force → Optimal
- **Brute / hash:** `unordered_set` or frequency map — O(N) time, O(N) space.
- **Sort:** adjacent equals — O(N log N).
- **Optimal under constraints:** index marking by negation — O(N) time, O(1) extra.

## 4. Data Structure / Approach Justification
**Chosen:** in-place sign marking at index `abs(x) - 1`.

| Alternative | Why we acknowledge but do not lead with it |
|-------------|-----------------------------------------------|
| `unordered_set` / frequency hash map | Clean and idiomatic — belongs to topic 6 once hashing is formal |
| Sort then scan | Simple; loses the O(N)/O(1) constraint |

A hashset solution also works and may be what you write first in an interview without the space constraint. We solve via **direct index marking** here on purpose: this topic builds index fluency before hashing (topic 6) and before cyclic-sort framing (topic 12).

## 5. Logic Walkthrough
1. For each value `x` in `nums`, let `v = abs(x)`, `idx = v - 1`.
2. If `nums[idx]` is already negative, `v` is a duplicate → push `v`.
3. Else set `nums[idx] = -nums[idx]`.
4. Return collected duplicates.

## 6. Dry Run
`[4,3,2,7,8,2,3,1]` — first `2` negates index 1; second `2` sees index 1 negative → record `2`. Same for `3`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1) extra (plus output)

## 8. Trade-offs & Alternatives
Sign marking mutates input — mention restoring signs if the caller needs the original array. This problem reappears conceptually in **Cyclic Sort (topic 12)** with a “place `v` at index `v-1`” framing; here we only use the array as a boolean mark store via signs.

## 9. Common Mistakes / Edge Cases
Forgetting `abs` after mutation; using `x` instead of `abs(x)` as the value; 0-based vs 1-based index off-by-one.

## 10. Interview Follow-ups / Variations
Find the single duplicate (LC 287); find all disappeared numbers (LC 448); cyclic-sort variants in topic 12.

## 11. Tags
`array`, `indexing`, `in-place`, `leetcode-442`, `difficulty:medium`
