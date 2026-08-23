# Valid Triangle Number

## Problem Statement
[LeetCode 611](https://leetcode.com/problems/valid-triangle-number/) — count triplets `i<j<k` that can be side lengths of a triangle.

- **Inputs:** `vector<int> nums`.
- **Output:** `int` count.
- **Valid answer:** triplets with `a+b>c` (and the other inequalities follow after sorting).
- **Edges:** zeros; duplicates; all equal.

## Intuition
Sort. Fix the largest side `c`. Then count pairs with `a+b>c` using two pointers (binary-searchable per hi).

## Brute Force → Optimal
- **Brute:** triple loop — O(N³).
- **Optimal:** sort + two pointers — O(N²). Per-c binary search of the pair is O(N² log N).

## Data Structure / Approach Justification
**Chosen:** two pointers after sort — the linear partner of “BS as a tool”.

- **vs binary search for each hi:** correct but extra log
- **vs unsorted:** triangle inequality is messy

## Logic Walkthrough
For each c from the right, `lo/hi` on `[0,c)`. If `nums[lo]+nums[hi] > nums[c]`, add `hi-lo` and `--hi`.

## Dry Run
`[2,2,3,4]` → 3 valid triplets.

## Time & Space Complexity
Time **O(N²)**. Space **O(1)** extra. Why: c runs N times; inner two-pointer is O(N).

## Trade-offs & Alternatives
You can binary-search the smallest lo for each hi if asked to show the BS tool explicitly.

## Common Mistakes / Edge Cases
Forgetting zeros cannot form a triangle; overflow on a+b (use long long if needed).

## Interview Follow-ups / Variations
3Sum; two sum less than k.

## Tags
`two-pointers`, `binary-search`, `sorting`, `leetcode-611`, `difficulty:medium`
