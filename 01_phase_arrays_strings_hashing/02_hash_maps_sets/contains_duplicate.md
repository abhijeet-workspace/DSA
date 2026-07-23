# Contains Duplicate

## 1. Problem Statement
Return `true` if any value appears at least twice in `nums`, else `false`.

- **Input:** `vector<int> nums`
- **Output:** bool
- **Valid answer:** true iff a duplicate exists
- **Edges:** empty; single element; all unique; all same

## 2. Intuition
A set remembers values already seen. A failed insert means the value appeared before.

## 3. Brute Force → Optimal
- **Brute:** for each `i`, scan `j > i` — O(N²).
- **Optimal:** `unordered_set` insert/find — O(N) average.

## 4. Data Structure / Approach Justification
`unordered_set<int>` — average O(1) membership.

| Alternative | Why it loses here |
|-------------|-------------------|
| Sort + adjacent compare | O(N log N); mutates or copies |
| Nested loops | O(N²) time |

## 5. Logic Walkthrough
1. Create empty `seen`.
2. For each `x`, try `insert`; if `.second == false`, return true.
3. If loop finishes, return false.

## 6. Dry Run
`nums = [1,2,3,1]`
- 1 → `{1}`
- 2 → `{1,2}`
- 3 → `{1,2,3}`
- 1 → already present → **true**

## 7. Time & Space Complexity
- **Time:** O(N) average
- **Space:** O(N)
- Why: one pass; set stores up to N distinct values.

## 8. Trade-offs & Alternatives
Hash set is fastest expected. Sort saves memory if in-place mutation is allowed (O(1) extra).

## 9. Common Mistakes / Edge Cases
Forgetting early return on failed insert; using `map` size vs array size incorrectly; empty input → false.

## 10. Interview Follow-ups / Variations
Return the duplicate value? Find all duplicates? First duplicate by index?

## 11. Tags
`hash-set`, `duplicate`, `leetcode-217`, `easy`
