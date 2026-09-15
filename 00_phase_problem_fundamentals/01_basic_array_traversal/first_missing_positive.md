# First Missing Positive

## 1. Problem Statement
[LeetCode 41](https://leetcode.com/problems/first-missing-positive/) — Given an unsorted integer array, return the smallest missing **positive** integer. Aim for O(N) time and O(1) extra space.

- **Inputs:** `vector<int>& nums`.
- **Output:** Smallest missing positive (`≥ 1`).
- **Edges:** Empty-like tiny arrays; already `1..n`; all negatives; duplicates.

## 2. Intuition
The answer is in `1..n+1`. Use the array itself as buckets: value `v` in `[1,n]` belongs at index `v-1`. After placement, the first index whose value is not `i+1` reveals the missing positive.

## 3. Brute Force → Optimal
- **Brute:** sort / hash set of positives — O(N log N) or O(N) space.
- **Optimal:** index-bucket swaps, then linear scan — O(N) time, O(1) extra.

## 4. Data Structure / Approach Justification
**Chosen:** while-swap placement of each `nums[i]` into index `nums[i]-1` when in range.

| Alternative | Why we acknowledge but do not lead with it |
|-------------|-----------------------------------------------|
| `unordered_set` of all values then probe `1,2,3,...` | Clear; O(N) space — hashing is topic 6 |
| Boolean presence array sized `n+2` | O(N) space |

Hashing works and is often the first interview answer before the O(1)-space follow-up. We solve with **index-bucket placement** here because this topic is building index fluency. A two-pointer or hashset approach is not the pedagogical goal for topic 1.

## 5. Logic Walkthrough
1. For each `i`, while `nums[i]` is in `[1,n]` and not already at `nums[i]-1`, swap it into place.
2. Scan `i = 0..n-1`; if `nums[i] != i+1`, return `i+1`.
3. If all match, return `n+1`.

## 6. Dry Run
`[3,4,-1,1]` → after swaps roughly `[1,-1,3,4]` → index `1` holds `-1` ≠ `2` → answer `2`.

## 7. Time & Space Complexity
- **Time:** O(N) — each value swaps into place at most once amortized
- **Space:** O(1) extra

## 8. Trade-offs & Alternatives
This same problem reappears conceptually in **Cyclic Sort (topic 12)** with an explicit “cycle sort / place numbers at home indices” pattern lesson. Here we teach it as **index-bucket placement** only — recognize the connection later; do not treat topic 12 as an unrelated problem.

Sign-marking (like LC 442) can also encode presence but is messier with non-positive values mixed in; swap-to-home is the standard O(1)-space approach.

## 9. Common Mistakes / Edge Cases
Infinite swap when duplicates (`nums[i] == nums[nums[i]-1]` must stop); forgetting answer can be `n+1`; using 0-based value checks incorrectly.

## 10. Interview Follow-ups / Variations
Find all missing positives in range; LC 448 disappeared numbers; cyclic-sort family in topic 12.

## 11. Tags
`array`, `indexing`, `in-place`, `leetcode-41`, `difficulty:hard`
