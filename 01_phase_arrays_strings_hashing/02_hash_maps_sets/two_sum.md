# Two Sum

## Problem Statement
[LeetCode 1](https://leetcode.com/problems/two-sum/) — return indices of the two numbers that add up to `target`.

- **Inputs:** `vector<int> nums`, `int target`.
- **Output:** two distinct indices.
- **Valid answer:** exactly one solution; cannot use the same element twice.
- **Edges:** negatives; zeros; answer at ends.

## Intuition
For each value, check whether `target - value` was already seen; one pass with a hash map.

## Brute Force → Optimal
- **Brute:** all pairs — O(N²).
- **Optimal:** hash map value→index — O(N)/O(N).

## Data Structure / Approach Justification
**Chosen:** `unordered_map` of seen values.

- **vs sort + two pointers:** loses original indices unless you store pairs.
- **vs nested loops:** too slow for interview expectations.

## Logic Walkthrough
Scan left→right. If `need = target - nums[i]` is in the map, return `{map[need], i}`; else store `nums[i] → i`.

## Dry Run
`[2,7,11,15], target=9`: see 2; at 7 need=2 → indices `0,1`.

## Time & Space Complexity
Time **O(N)**. Space **O(N)**. Why: one hash lookup per element.

## Trade-offs & Alternatives
Sorted two-pointers works if returning values (not indices) is enough.

## Common Mistakes / Edge Cases
Using the same index twice; overwriting map too early before checking.

## Interview Follow-ups / Variations
Two Sum II (sorted); 3Sum; count of pairs.

## Tags
`array`, `hash-map`, `difficulty:easy`
