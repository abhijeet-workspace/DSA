# Search Insert Position

## Problem Statement
[LeetCode 35](https://leetcode.com/problems/search-insert-position/) — sorted distinct `nums`; return index of `target` or where it would be inserted to keep order.

- **Inputs:** ascending `vector<int> nums` (distinct), `int target`.
- **Output:** index in `[0, n]`.
- **Valid answer:** first index with `nums[i] >= target` (or `n`).
- **Edges:** insert at front; at end; exact hit; empty.

## Intuition
Classic BS that returns the final `low` when the loop ends — that is the insertion point.

## Brute Force → Optimal
- **Brute:** linear scan for first `>= target` — O(N).
- **Optimal:** binary search — O(log N).

## Data Structure / Approach Justification
**Chosen:** closed `[low, high]` loop; on miss return `low`.

- **vs `lower_bound`:** identical semantics; this form is interview-friendly.
- **vs linear:** required for large N.

## Logic Walkthrough
Compare mid to target. Equal → return mid. Mid smaller → `low = mid + 1`. Else `high = mid - 1`. After exit, `low` is the insert index.

## Dry Run
`nums = [1,3,5,6]`:
- target `5` → hit index `2`
- target `2` → loop ends with `low = 1`

## Time & Space Complexity
Time **O(log N)**. Space **O(1)**. Why: standard binary search (section 4).

## Trade-offs & Alternatives
Same as lower bound; prefer naming that matches the problem statement in interviews.

## Common Mistakes / Edge Cases
Returning `high` after exit; off-by-one when `target` > all elements.

## Interview Follow-ups / Variations
Duplicates → lower bound; Search Insert with capacity constraints.

## Tags
`binary-search`, `array`, `insertion`, `difficulty:easy`
