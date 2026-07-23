# Lower / Upper Bound

## Problem Statement
Teaching file — first index with `nums[i] >= target` (lower) and first with `nums[i] > target` (upper); mirrors `std::lower_bound` / `std::upper_bound`.

- **Inputs:** sorted `vector<int> nums`, `int target`.
- **Output:** insertion-style indices in `[0, n]`.
- **Valid answer:** leftmost qualifying index (or `n` if none).
- **Edges:** empty; all equal; target below/above range; duplicates.

## Intuition
Half-open `[left, right)` keeps the candidate frontier: shrink `right` when mid still qualifies, else advance `left`.

## Brute Force → Optimal
- **Brute:** scan left-to-right — O(N).
- **Optimal:** binary search bounds — O(log N).

## Data Structure / Approach Justification
**Chosen:** custom `customLowerBound` / `customUpperBound` with exclusive `right = n`.

- **vs closed interval + return `low`:** same result; half-open matches STL mental model.
- **vs linear scan:** needed when bounds feed larger algorithms (counts, inserts).

## Logic Walkthrough
Lower: if `nums[mid] >= target`, `right = mid`; else `left = mid + 1`. Upper: if `nums[mid] > target`, `right = mid`; else `left = mid + 1`. Return `left`.

## Dry Run
`nums = [1,2,4,4,4,6,7]`, `target = 4`:
- lower settles at index `2`; upper at `5` → count of 4s is `ub - lb = 3`.

## Time & Space Complexity
Time **O(log N)**. Space **O(1)**. Why: one binary search each (section 4).

## Trade-offs & Alternatives
Prefer STL when available. Hand-roll when teaching or in languages without it.

## Common Mistakes / Edge Cases
Mixing `>=` vs `>` predicates; using inclusive right incorrectly; assuming target exists.

## Interview Follow-ups / Variations
Count of target = upper − lower; search insert position.

## Tags
`binary-search`, `lower-bound`, `upper-bound`, `difficulty:easy`
